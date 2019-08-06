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

#ifndef GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_
#define GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include <cstring>

namespace gs2 { namespace matchmaking {

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
        /** ギャザリング新規作成時のアクション */
        optional<StringHolder> createGatheringTriggerType;
        /** ギャザリング新規作成時 にルームを作成するネームスペース のGRN */
        optional<StringHolder> createGatheringTriggerRealtimeNamespaceId;
        /** ギャザリング新規作成時 に実行されるスクリプト のGRN */
        optional<StringHolder> createGatheringTriggerScriptId;
        /** マッチメイキング完了時のアクション */
        optional<StringHolder> completeMatchmakingTriggerType;
        /** マッチメイキング完了時 にルームを作成するネームスペース のGRN */
        optional<StringHolder> completeMatchmakingTriggerRealtimeNamespaceId;
        /** マッチメイキング完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeMatchmakingTriggerScriptId;
        /** ギャザリングに新規プレイヤーが参加したときのプッシュ通知 */
        optional<NotificationSetting> joinNotification;
        /** ギャザリングからプレイヤーが離脱したときのプッシュ通知 */
        optional<NotificationSetting> leaveNotification;
        /** マッチメイキングが完了したときのプッシュ通知 */
        optional<NotificationSetting> completeNotification;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            createGatheringTriggerType(data.createGatheringTriggerType),
            createGatheringTriggerRealtimeNamespaceId(data.createGatheringTriggerRealtimeNamespaceId),
            createGatheringTriggerScriptId(data.createGatheringTriggerScriptId),
            completeMatchmakingTriggerType(data.completeMatchmakingTriggerType),
            completeMatchmakingTriggerRealtimeNamespaceId(data.completeMatchmakingTriggerRealtimeNamespaceId),
            completeMatchmakingTriggerScriptId(data.completeMatchmakingTriggerScriptId),
            joinNotification(data.joinNotification),
            leaveNotification(data.leaveNotification),
            completeNotification(data.completeNotification),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            createGatheringTriggerType(std::move(data.createGatheringTriggerType)),
            createGatheringTriggerRealtimeNamespaceId(std::move(data.createGatheringTriggerRealtimeNamespaceId)),
            createGatheringTriggerScriptId(std::move(data.createGatheringTriggerScriptId)),
            completeMatchmakingTriggerType(std::move(data.completeMatchmakingTriggerType)),
            completeMatchmakingTriggerRealtimeNamespaceId(std::move(data.completeMatchmakingTriggerRealtimeNamespaceId)),
            completeMatchmakingTriggerScriptId(std::move(data.completeMatchmakingTriggerScriptId)),
            joinNotification(std::move(data.joinNotification)),
            leaveNotification(std::move(data.leaveNotification)),
            completeNotification(std::move(data.completeNotification)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createGatheringTriggerType") == 0) {
                if (jsonValue.IsString())
                {
                    this->createGatheringTriggerType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createGatheringTriggerRealtimeNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createGatheringTriggerRealtimeNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createGatheringTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createGatheringTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeMatchmakingTriggerType") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeMatchmakingTriggerType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeMatchmakingTriggerRealtimeNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeMatchmakingTriggerRealtimeNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeMatchmakingTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeMatchmakingTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "joinNotification") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->joinNotification.emplace();
                    detail::json::JsonParser::parse(&this->joinNotification->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "leaveNotification") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->leaveNotification.emplace();
                    detail::json::JsonParser::parse(&this->leaveNotification->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "completeNotification") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->completeNotification.emplace();
                    detail::json::JsonParser::parse(&this->completeNotification->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
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
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
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
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * ギャザリング新規作成時のアクションを取得
     *
     * @return ギャザリング新規作成時のアクション
     */
    const optional<StringHolder>& getCreateGatheringTriggerType() const
    {
        return ensureData().createGatheringTriggerType;
    }

    /**
     * ギャザリング新規作成時のアクションを設定
     *
     * @param createGatheringTriggerType ギャザリング新規作成時のアクション
     */
    void setCreateGatheringTriggerType(const Char* createGatheringTriggerType)
    {
        ensureData().createGatheringTriggerType.emplace(createGatheringTriggerType);
    }

    /**
     * ギャザリング新規作成時のアクションを設定
     *
     * @param createGatheringTriggerType ギャザリング新規作成時のアクション
     */
    Namespace& withCreateGatheringTriggerType(const Char* createGatheringTriggerType)
    {
        setCreateGatheringTriggerType(createGatheringTriggerType);
        return *this;
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを取得
     *
     * @return ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    const optional<StringHolder>& getCreateGatheringTriggerRealtimeNamespaceId() const
    {
        return ensureData().createGatheringTriggerRealtimeNamespaceId;
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを設定
     *
     * @param createGatheringTriggerRealtimeNamespaceId ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    void setCreateGatheringTriggerRealtimeNamespaceId(const Char* createGatheringTriggerRealtimeNamespaceId)
    {
        ensureData().createGatheringTriggerRealtimeNamespaceId.emplace(createGatheringTriggerRealtimeNamespaceId);
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを設定
     *
     * @param createGatheringTriggerRealtimeNamespaceId ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    Namespace& withCreateGatheringTriggerRealtimeNamespaceId(const Char* createGatheringTriggerRealtimeNamespaceId)
    {
        setCreateGatheringTriggerRealtimeNamespaceId(createGatheringTriggerRealtimeNamespaceId);
        return *this;
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを取得
     *
     * @return ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateGatheringTriggerScriptId() const
    {
        return ensureData().createGatheringTriggerScriptId;
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createGatheringTriggerScriptId ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    void setCreateGatheringTriggerScriptId(const Char* createGatheringTriggerScriptId)
    {
        ensureData().createGatheringTriggerScriptId.emplace(createGatheringTriggerScriptId);
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createGatheringTriggerScriptId ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    Namespace& withCreateGatheringTriggerScriptId(const Char* createGatheringTriggerScriptId)
    {
        setCreateGatheringTriggerScriptId(createGatheringTriggerScriptId);
        return *this;
    }

    /**
     * マッチメイキング完了時のアクションを取得
     *
     * @return マッチメイキング完了時のアクション
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerType() const
    {
        return ensureData().completeMatchmakingTriggerType;
    }

    /**
     * マッチメイキング完了時のアクションを設定
     *
     * @param completeMatchmakingTriggerType マッチメイキング完了時のアクション
     */
    void setCompleteMatchmakingTriggerType(const Char* completeMatchmakingTriggerType)
    {
        ensureData().completeMatchmakingTriggerType.emplace(completeMatchmakingTriggerType);
    }

    /**
     * マッチメイキング完了時のアクションを設定
     *
     * @param completeMatchmakingTriggerType マッチメイキング完了時のアクション
     */
    Namespace& withCompleteMatchmakingTriggerType(const Char* completeMatchmakingTriggerType)
    {
        setCompleteMatchmakingTriggerType(completeMatchmakingTriggerType);
        return *this;
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを取得
     *
     * @return マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerRealtimeNamespaceId() const
    {
        return ensureData().completeMatchmakingTriggerRealtimeNamespaceId;
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを設定
     *
     * @param completeMatchmakingTriggerRealtimeNamespaceId マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    void setCompleteMatchmakingTriggerRealtimeNamespaceId(const Char* completeMatchmakingTriggerRealtimeNamespaceId)
    {
        ensureData().completeMatchmakingTriggerRealtimeNamespaceId.emplace(completeMatchmakingTriggerRealtimeNamespaceId);
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを設定
     *
     * @param completeMatchmakingTriggerRealtimeNamespaceId マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    Namespace& withCompleteMatchmakingTriggerRealtimeNamespaceId(const Char* completeMatchmakingTriggerRealtimeNamespaceId)
    {
        setCompleteMatchmakingTriggerRealtimeNamespaceId(completeMatchmakingTriggerRealtimeNamespaceId);
        return *this;
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを取得
     *
     * @return マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerScriptId() const
    {
        return ensureData().completeMatchmakingTriggerScriptId;
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeMatchmakingTriggerScriptId マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    void setCompleteMatchmakingTriggerScriptId(const Char* completeMatchmakingTriggerScriptId)
    {
        ensureData().completeMatchmakingTriggerScriptId.emplace(completeMatchmakingTriggerScriptId);
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeMatchmakingTriggerScriptId マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    Namespace& withCompleteMatchmakingTriggerScriptId(const Char* completeMatchmakingTriggerScriptId)
    {
        setCompleteMatchmakingTriggerScriptId(completeMatchmakingTriggerScriptId);
        return *this;
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を取得
     *
     * @return ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    const optional<NotificationSetting>& getJoinNotification() const
    {
        return ensureData().joinNotification;
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を設定
     *
     * @param joinNotification ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    void setJoinNotification(const NotificationSetting& joinNotification)
    {
        ensureData().joinNotification.emplace(joinNotification);
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を設定
     *
     * @param joinNotification ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    Namespace& withJoinNotification(const NotificationSetting& joinNotification)
    {
        setJoinNotification(joinNotification);
        return *this;
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を取得
     *
     * @return ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    const optional<NotificationSetting>& getLeaveNotification() const
    {
        return ensureData().leaveNotification;
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を設定
     *
     * @param leaveNotification ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    void setLeaveNotification(const NotificationSetting& leaveNotification)
    {
        ensureData().leaveNotification.emplace(leaveNotification);
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を設定
     *
     * @param leaveNotification ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    Namespace& withLeaveNotification(const NotificationSetting& leaveNotification)
    {
        setLeaveNotification(leaveNotification);
        return *this;
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を取得
     *
     * @return マッチメイキングが完了したときのプッシュ通知
     */
    const optional<NotificationSetting>& getCompleteNotification() const
    {
        return ensureData().completeNotification;
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を設定
     *
     * @param completeNotification マッチメイキングが完了したときのプッシュ通知
     */
    void setCompleteNotification(const NotificationSetting& completeNotification)
    {
        ensureData().completeNotification.emplace(completeNotification);
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を設定
     *
     * @param completeNotification マッチメイキングが完了したときのプッシュ通知
     */
    Namespace& withCompleteNotification(const NotificationSetting& completeNotification)
    {
        setCompleteNotification(completeNotification);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->createGatheringTriggerType != lhr.m_pData->createGatheringTriggerType)
        {
            return true;
        }
        if (lhs.m_pData->createGatheringTriggerRealtimeNamespaceId != lhr.m_pData->createGatheringTriggerRealtimeNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createGatheringTriggerScriptId != lhr.m_pData->createGatheringTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerType != lhr.m_pData->completeMatchmakingTriggerType)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerRealtimeNamespaceId != lhr.m_pData->completeMatchmakingTriggerRealtimeNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->completeMatchmakingTriggerScriptId != lhr.m_pData->completeMatchmakingTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->joinNotification != lhr.m_pData->joinNotification)
        {
            return true;
        }
        if (lhs.m_pData->leaveNotification != lhr.m_pData->leaveNotification)
        {
            return true;
        }
        if (lhs.m_pData->completeNotification != lhr.m_pData->completeNotification)
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

#endif //GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_