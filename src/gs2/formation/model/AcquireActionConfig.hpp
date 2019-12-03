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

#ifndef GS2_FORMATION_MODEL_ACQUIREACTIONCONFIG_HPP_
#define GS2_FORMATION_MODEL_ACQUIREACTIONCONFIG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Config.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * 入手アクションコンフィグ
 *
 * @author Game Server Services, Inc.
 *
 */
class AcquireActionConfig : public Gs2Object
{
    friend bool operator!=(const AcquireActionConfig& lhs, const AcquireActionConfig& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スロット名 */
        optional<StringHolder> name;
        /** スタンプシートに使用するコンフィグ */
        optional<List<Config>> config;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name)
        {
            if (data.config)
            {
                config = data.config->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "config") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->config.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Config item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->config += std::move(item);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AcquireActionConfig() = default;
    AcquireActionConfig(const AcquireActionConfig& acquireActionConfig) = default;
    AcquireActionConfig(AcquireActionConfig&& acquireActionConfig) = default;
    ~AcquireActionConfig() = default;

    AcquireActionConfig& operator=(const AcquireActionConfig& acquireActionConfig) = default;
    AcquireActionConfig& operator=(AcquireActionConfig&& acquireActionConfig) = default;

    AcquireActionConfig deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcquireActionConfig);
    }

    const AcquireActionConfig* operator->() const
    {
        return this;
    }

    AcquireActionConfig* operator->()
    {
        return this;
    }
    /**
     * スロット名を取得
     *
     * @return スロット名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スロット名を設定
     *
     * @param name スロット名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スロット名を設定
     *
     * @param name スロット名
     */
    AcquireActionConfig& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * スタンプシートに使用するコンフィグを取得
     *
     * @return スタンプシートに使用するコンフィグ
     */
    const optional<List<Config>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * スタンプシートに使用するコンフィグを設定
     *
     * @param config スタンプシートに使用するコンフィグ
     */
    void setConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * スタンプシートに使用するコンフィグを設定
     *
     * @param config スタンプシートに使用するコンフィグ
     */
    AcquireActionConfig& withConfig(List<Config> config)
    {
        setConfig(std::move(config));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const AcquireActionConfig& lhs, const AcquireActionConfig& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->config != lhr.m_pData->config)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const AcquireActionConfig& lhs, const AcquireActionConfig& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_ACQUIREACTIONCONFIG_HPP_