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

#ifndef GS2_MISSION_MODEL_NAMESPACE_HPP_
#define GS2_MISSION_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "NotificationSetting.hpp"
#include "LogSetting.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace mission {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ミッションを達成したときに実行するスクリプト */
        optional<ScriptSetting> missionCompleteScript;
        /** カウンターを上昇したときに実行するスクリプト */
        optional<ScriptSetting> counterIncrementScript;
        /** 報酬を受け取ったときに実行するスクリプト */
        optional<ScriptSetting> receiveRewardsScript;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** ミッションのタスクを達成したときのプッシュ通知 */
        optional<NotificationSetting> completeNotification;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.missionCompleteScript)
            {
                missionCompleteScript = data.missionCompleteScript->deepCopy();
            }
            if (data.counterIncrementScript)
            {
                counterIncrementScript = data.counterIncrementScript->deepCopy();
            }
            if (data.receiveRewardsScript)
            {
                receiveRewardsScript = data.receiveRewardsScript->deepCopy();
            }
            if (data.completeNotification)
            {
                completeNotification = data.completeNotification->deepCopy();
            }
            if (data.logSetting)
            {
                logSetting = data.logSetting->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "missionCompleteScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->missionCompleteScript.emplace();
                    detail::json::JsonParser::parse(&this->missionCompleteScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "counterIncrementScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->counterIncrementScript.emplace();
                    detail::json::JsonParser::parse(&this->counterIncrementScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "receiveRewardsScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->receiveRewardsScript.emplace();
                    detail::json::JsonParser::parse(&this->receiveRewardsScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "queueNamespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->queueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "keyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->keyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeNotification") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->completeNotification.emplace();
                    detail::json::JsonParser::parse(&this->completeNotification->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "logSetting") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->logSetting.emplace();
                    detail::json::JsonParser::parse(&this->logSetting->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * ミッションを達成したときに実行するスクリプトを取得
     *
     * @return ミッションを達成したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getMissionCompleteScript() const
    {
        return ensureData().missionCompleteScript;
    }

    /**
     * ミッションを達成したときに実行するスクリプトを設定
     *
     * @param missionCompleteScript ミッションを達成したときに実行するスクリプト
     */
    void setMissionCompleteScript(ScriptSetting missionCompleteScript)
    {
        ensureData().missionCompleteScript.emplace(std::move(missionCompleteScript));
    }

    /**
     * ミッションを達成したときに実行するスクリプトを設定
     *
     * @param missionCompleteScript ミッションを達成したときに実行するスクリプト
     */
    Namespace& withMissionCompleteScript(ScriptSetting missionCompleteScript)
    {
        setMissionCompleteScript(std::move(missionCompleteScript));
        return *this;
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを取得
     *
     * @return カウンターを上昇したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCounterIncrementScript() const
    {
        return ensureData().counterIncrementScript;
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを設定
     *
     * @param counterIncrementScript カウンターを上昇したときに実行するスクリプト
     */
    void setCounterIncrementScript(ScriptSetting counterIncrementScript)
    {
        ensureData().counterIncrementScript.emplace(std::move(counterIncrementScript));
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを設定
     *
     * @param counterIncrementScript カウンターを上昇したときに実行するスクリプト
     */
    Namespace& withCounterIncrementScript(ScriptSetting counterIncrementScript)
    {
        setCounterIncrementScript(std::move(counterIncrementScript));
        return *this;
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを取得
     *
     * @return 報酬を受け取ったときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReceiveRewardsScript() const
    {
        return ensureData().receiveRewardsScript;
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを設定
     *
     * @param receiveRewardsScript 報酬を受け取ったときに実行するスクリプト
     */
    void setReceiveRewardsScript(ScriptSetting receiveRewardsScript)
    {
        ensureData().receiveRewardsScript.emplace(std::move(receiveRewardsScript));
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを設定
     *
     * @param receiveRewardsScript 報酬を受け取ったときに実行するスクリプト
     */
    Namespace& withReceiveRewardsScript(ScriptSetting receiveRewardsScript)
    {
        setReceiveRewardsScript(std::move(receiveRewardsScript));
        return *this;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを取得
     *
     * @return 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    void setQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    Namespace& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        setQueueNamespaceId(std::move(queueNamespaceId));
        return *this;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを取得
     *
     * @return 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    Namespace& withKeyId(StringHolder keyId)
    {
        setKeyId(std::move(keyId));
        return *this;
    }

    /**
     * ミッションのタスクを達成したときのプッシュ通知を取得
     *
     * @return ミッションのタスクを達成したときのプッシュ通知
     */
    const optional<NotificationSetting>& getCompleteNotification() const
    {
        return ensureData().completeNotification;
    }

    /**
     * ミッションのタスクを達成したときのプッシュ通知を設定
     *
     * @param completeNotification ミッションのタスクを達成したときのプッシュ通知
     */
    void setCompleteNotification(NotificationSetting completeNotification)
    {
        ensureData().completeNotification.emplace(std::move(completeNotification));
    }

    /**
     * ミッションのタスクを達成したときのプッシュ通知を設定
     *
     * @param completeNotification ミッションのタスクを達成したときのプッシュ通知
     */
    Namespace& withCompleteNotification(NotificationSetting completeNotification)
    {
        setCompleteNotification(std::move(completeNotification));
        return *this;
    }

    /**
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    Namespace& withLogSetting(LogSetting logSetting)
    {
        setLogSetting(std::move(logSetting));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->missionCompleteScript != lhr.m_pData->missionCompleteScript)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementScript != lhr.m_pData->counterIncrementScript)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsScript != lhr.m_pData->receiveRewardsScript)
        {
            return true;
        }
        if (lhs.m_pData->queueNamespaceId != lhr.m_pData->queueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->keyId != lhr.m_pData->keyId)
        {
            return true;
        }
        if (lhs.m_pData->completeNotification != lhr.m_pData->completeNotification)
        {
            return true;
        }
        if (lhs.m_pData->logSetting != lhr.m_pData->logSetting)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_NAMESPACE_HPP_