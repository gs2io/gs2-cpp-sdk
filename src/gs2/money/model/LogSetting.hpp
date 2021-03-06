/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_MONEY_MODEL_LOGSETTING_HPP_
#define GS2_MONEY_MODEL_LOGSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ロギング通知設定
 *
 * @author Game Server Services, Inc.
 *
 */
class LogSetting : public Gs2Object
{
    friend bool operator!=(const LogSetting& lhs, const LogSetting& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ログの記録に使用する GS2-Log のネームスペース のGRN */
        optional<StringHolder> loggingNamespaceId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            loggingNamespaceId(data.loggingNamespaceId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "loggingNamespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->loggingNamespaceId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    LogSetting() = default;
    LogSetting(const LogSetting& logSetting) = default;
    LogSetting(LogSetting&& logSetting) = default;
    ~LogSetting() = default;

    LogSetting& operator=(const LogSetting& logSetting) = default;
    LogSetting& operator=(LogSetting&& logSetting) = default;

    LogSetting deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LogSetting);
    }

    const LogSetting* operator->() const
    {
        return this;
    }

    LogSetting* operator->()
    {
        return this;
    }
    /**
     * ログの記録に使用する GS2-Log のネームスペース のGRNを取得
     *
     * @return ログの記録に使用する GS2-Log のネームスペース のGRN
     */
    const optional<StringHolder>& getLoggingNamespaceId() const
    {
        return ensureData().loggingNamespaceId;
    }

    /**
     * ログの記録に使用する GS2-Log のネームスペース のGRNを設定
     *
     * @param loggingNamespaceId ログの記録に使用する GS2-Log のネームスペース のGRN
     */
    void setLoggingNamespaceId(StringHolder loggingNamespaceId)
    {
        ensureData().loggingNamespaceId.emplace(std::move(loggingNamespaceId));
    }

    /**
     * ログの記録に使用する GS2-Log のネームスペース のGRNを設定
     *
     * @param loggingNamespaceId ログの記録に使用する GS2-Log のネームスペース のGRN
     */
    LogSetting& withLoggingNamespaceId(StringHolder loggingNamespaceId)
    {
        setLoggingNamespaceId(std::move(loggingNamespaceId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LogSetting& lhs, const LogSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->loggingNamespaceId != lhr.m_pData->loggingNamespaceId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const LogSetting& lhs, const LogSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_LOGSETTING_HPP_