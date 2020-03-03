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

#ifndef GS2_QUEST_MODEL_SCRIPTSETTING_HPP_
#define GS2_QUEST_MODEL_SCRIPTSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace quest {

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
        /** 完了通知の通知先 */
        optional<StringHolder> doneTriggerTargetType;
        /** 完了時に使用する GS2-Script のスクリプト のGRN */
        optional<StringHolder> doneTriggerScriptId;
        /** 完了時に使用する GS2-JobQueue のネームスペース のGRN */
        optional<StringHolder> doneTriggerQueueNamespaceId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            triggerScriptId(data.triggerScriptId),
            doneTriggerTargetType(data.doneTriggerTargetType),
            doneTriggerScriptId(data.doneTriggerScriptId),
            doneTriggerQueueNamespaceId(data.doneTriggerQueueNamespaceId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "triggerScriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->triggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doneTriggerTargetType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->doneTriggerTargetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doneTriggerScriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->doneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "doneTriggerQueueNamespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->doneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ScriptSetting() = default;
    ScriptSetting(const ScriptSetting& scriptSetting) = default;
    ScriptSetting(ScriptSetting&& scriptSetting) = default;
    ~ScriptSetting() = default;

    ScriptSetting& operator=(const ScriptSetting& scriptSetting) = default;
    ScriptSetting& operator=(ScriptSetting&& scriptSetting) = default;

    ScriptSetting deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ScriptSetting);
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
    void setTriggerScriptId(StringHolder triggerScriptId)
    {
        ensureData().triggerScriptId.emplace(std::move(triggerScriptId));
    }

    /**
     * 実行前に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param triggerScriptId 実行前に使用する GS2-Script のスクリプト のGRN
     */
    ScriptSetting& withTriggerScriptId(StringHolder triggerScriptId)
    {
        setTriggerScriptId(std::move(triggerScriptId));
        return *this;
    }

    /**
     * 完了通知の通知先を取得
     *
     * @return 完了通知の通知先
     */
    const optional<StringHolder>& getDoneTriggerTargetType() const
    {
        return ensureData().doneTriggerTargetType;
    }

    /**
     * 完了通知の通知先を設定
     *
     * @param doneTriggerTargetType 完了通知の通知先
     */
    void setDoneTriggerTargetType(StringHolder doneTriggerTargetType)
    {
        ensureData().doneTriggerTargetType.emplace(std::move(doneTriggerTargetType));
    }

    /**
     * 完了通知の通知先を設定
     *
     * @param doneTriggerTargetType 完了通知の通知先
     */
    ScriptSetting& withDoneTriggerTargetType(StringHolder doneTriggerTargetType)
    {
        setDoneTriggerTargetType(std::move(doneTriggerTargetType));
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
    void setDoneTriggerScriptId(StringHolder doneTriggerScriptId)
    {
        ensureData().doneTriggerScriptId.emplace(std::move(doneTriggerScriptId));
    }

    /**
     * 完了時に使用する GS2-Script のスクリプト のGRNを設定
     *
     * @param doneTriggerScriptId 完了時に使用する GS2-Script のスクリプト のGRN
     */
    ScriptSetting& withDoneTriggerScriptId(StringHolder doneTriggerScriptId)
    {
        setDoneTriggerScriptId(std::move(doneTriggerScriptId));
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
    void setDoneTriggerQueueNamespaceId(StringHolder doneTriggerQueueNamespaceId)
    {
        ensureData().doneTriggerQueueNamespaceId.emplace(std::move(doneTriggerQueueNamespaceId));
    }

    /**
     * 完了時に使用する GS2-JobQueue のネームスペース のGRNを設定
     *
     * @param doneTriggerQueueNamespaceId 完了時に使用する GS2-JobQueue のネームスペース のGRN
     */
    ScriptSetting& withDoneTriggerQueueNamespaceId(StringHolder doneTriggerQueueNamespaceId)
    {
        setDoneTriggerQueueNamespaceId(std::move(doneTriggerQueueNamespaceId));
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
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->triggerScriptId != lhr.m_pData->triggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->doneTriggerTargetType != lhr.m_pData->doneTriggerTargetType)
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

#endif //GS2_QUEST_MODEL_SCRIPTSETTING_HPP_