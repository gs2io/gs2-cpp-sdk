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

#ifndef GS2_MONEY_MODEL_SCRIPTSETTING_HPP_
#define GS2_MONEY_MODEL_SCRIPTSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * スクリプト設定
 *
 * @author Game Server Services, Inc.
 *
 */
class ScriptSetting : public Gs2Object
{
    friend bool operator!=(const ScriptSetting& lhs, const ScriptSetting& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 実行前に使用する GS2-Script のスクリプト のGRN */
        optional<StringHolder> triggerScriptId;
        /** 完了時に使用する GS2-Script のスクリプト のGRN */
        optional<StringHolder> doneTriggerScriptId;
        /** 完了時に使用する GS2-JobQueue のネームスペース のGRN */
        optional<StringHolder> doneTriggerQueueNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            triggerScriptId(data.triggerScriptId),
            doneTriggerScriptId(data.doneTriggerScriptId),
            doneTriggerQueueNamespaceId(data.doneTriggerQueueNamespaceId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            triggerScriptId(std::move(data.triggerScriptId)),
            doneTriggerScriptId(std::move(data.doneTriggerScriptId)),
            doneTriggerQueueNamespaceId(std::move(data.doneTriggerQueueNamespaceId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "triggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->triggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->doneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    ScriptSetting() :
        m_pData(nullptr)
    {}

    ScriptSetting(const ScriptSetting& scriptSetting) :
        Gs2Object(scriptSetting),
        m_pData(scriptSetting.m_pData != nullptr ? new Data(*scriptSetting.m_pData) : nullptr)
    {}

    ScriptSetting(ScriptSetting&& scriptSetting) :
        Gs2Object(std::move(scriptSetting)),
        m_pData(scriptSetting.m_pData)
    {
        scriptSetting.m_pData = nullptr;
    }

    ~ScriptSetting()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ScriptSetting& operator=(const ScriptSetting& scriptSetting)
    {
        Gs2Object::operator=(scriptSetting);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*scriptSetting.m_pData);

        return *this;
    }

    ScriptSetting& operator=(ScriptSetting&& scriptSetting)
    {
        Gs2Object::operator=(std::move(scriptSetting));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = scriptSetting.m_pData;
        scriptSetting.m_pData = nullptr;

        return *this;
    }

    const ScriptSetting* operator->() const
    {
        return this;
    }

    ScriptSetting* operator->()
    {
        return this;
    }
    /**
     * 実行前に使用する GS2-Script のスクリプト のGRNを取得
     *
     * @return 実行前に使用する GS2-Script のスクリプト のGRN
     */
    const optional<StringHolder>& getTriggerScriptId() const
    {
        return ensureData().triggerScriptId;
    }

    /**
     * 実行前に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param triggerScriptId 実行前に使用する GS2-Script のスクリプト のGRN
     */
    void setTriggerScriptId(const Char* triggerScriptId)
    {
        ensureData().triggerScriptId.emplace(triggerScriptId);
    }

    /**
     * 実行前に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param triggerScriptId 実行前に使用する GS2-Script のスクリプト のGRN
     */
    ScriptSetting& withTriggerScriptId(const Char* triggerScriptId)
    {
        setTriggerScriptId(triggerScriptId);
        return *this;
    }

    /**
     * 完了時に使用する GS2-Script のスクリプト のGRNを取得
     *
     * @return 完了時に使用する GS2-Script のスクリプト のGRN
     */
    const optional<StringHolder>& getDoneTriggerScriptId() const
    {
        return ensureData().doneTriggerScriptId;
    }

    /**
     * 完了時に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param doneTriggerScriptId 完了時に使用する GS2-Script のスクリプト のGRN
     */
    void setDoneTriggerScriptId(const Char* doneTriggerScriptId)
    {
        ensureData().doneTriggerScriptId.emplace(doneTriggerScriptId);
    }

    /**
     * 完了時に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param doneTriggerScriptId 完了時に使用する GS2-Script のスクリプト のGRN
     */
    ScriptSetting& withDoneTriggerScriptId(const Char* doneTriggerScriptId)
    {
        setDoneTriggerScriptId(doneTriggerScriptId);
        return *this;
    }

    /**
     * 完了時に使用する GS2-JobQueue のネームスペース のGRNを取得
     *
     * @return 完了時に使用する GS2-JobQueue のネームスペース のGRN
     */
    const optional<StringHolder>& getDoneTriggerQueueNamespaceId() const
    {
        return ensureData().doneTriggerQueueNamespaceId;
    }

    /**
     * 完了時に使用する GS2-JobQueue のネームスペース のGRNを設定
     *
     * @param doneTriggerQueueNamespaceId 完了時に使用する GS2-JobQueue のネームスペース のGRN
     */
    void setDoneTriggerQueueNamespaceId(const Char* doneTriggerQueueNamespaceId)
    {
        ensureData().doneTriggerQueueNamespaceId.emplace(doneTriggerQueueNamespaceId);
    }

    /**
     * 完了時に使用する GS2-JobQueue のネームスペース のGRNを設定
     *
     * @param doneTriggerQueueNamespaceId 完了時に使用する GS2-JobQueue のネームスペース のGRN
     */
    ScriptSetting& withDoneTriggerQueueNamespaceId(const Char* doneTriggerQueueNamespaceId)
    {
        setDoneTriggerQueueNamespaceId(doneTriggerQueueNamespaceId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ScriptSetting& lhs, const ScriptSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->triggerScriptId != lhr.m_pData->triggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doneTriggerScriptId != lhr.m_pData->doneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doneTriggerQueueNamespaceId != lhr.m_pData->doneTriggerQueueNamespaceId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ScriptSetting& lhs, const ScriptSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_SCRIPTSETTING_HPP_