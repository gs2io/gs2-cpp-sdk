/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MATCHMAKING_MODEL_MATCHMAKING_HPP_
#define GS2_MATCHMAKING_MODEL_MATCHMAKING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * マッチメイキング
 *
 * @author Game Server Services, Inc.
 *
 */
class Matchmaking : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** マッチメイキングGRN */
        optional<StringHolder> matchmakingId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** マッチメイキング名 */
        optional<StringHolder> name;
        /** マッチメイキング方式 */
        optional<StringHolder> type;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** 最大プレイヤー数 */
        optional<Int32> maxPlayer;
        /** マッチメイキング完了時の通知先URL */
        optional<StringHolder> callback;
        /** マッチメイキング完了時に GS2-Realtime と自動的に連携する場合に指定するギャザリングプール名 */
        optional<StringHolder> gatheringPoolName;
        /** マッチメイキングの状態変化や完了通知を GS2-InGamePushNotification を使用して通知する場合に指定するゲーム名 */
        optional<StringHolder> notificationGameName;
        /** ギャザリング作成時 に実行されるGS2-Script */
        optional<StringHolder> createGatheringTriggerScript;
        /** ギャザリング作成完了時 に実行されるGS2-Script */
        optional<StringHolder> createGatheringDoneTriggerScript;
        /** ギャザリング参加時 に実行されるGS2-Script */
        optional<StringHolder> joinGatheringTriggerScript;
        /** ギャザリング参加完了時 に実行されるGS2-Script */
        optional<StringHolder> joinGatheringDoneTriggerScript;
        /** ギャザリング離脱時 に実行されるGS2-Script */
        optional<StringHolder> leaveGatheringTriggerScript;
        /** ギャザリング離脱完了時 に実行されるGS2-Script */
        optional<StringHolder> leaveGatheringDoneTriggerScript;
        /** ギャザリング解散時 に実行されるGS2-Script */
        optional<StringHolder> breakupGatheringTriggerScript;
        /** マッチメイキング成立時 に実行されるGS2-Script */
        optional<StringHolder> matchmakingCompleteTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            matchmakingId(data.matchmakingId),
            ownerId(data.ownerId),
            name(data.name),
            type(data.type),
            description(data.description),
            serviceClass(data.serviceClass),
            maxPlayer(data.maxPlayer),
            callback(data.callback),
            gatheringPoolName(data.gatheringPoolName),
            notificationGameName(data.notificationGameName),
            createGatheringTriggerScript(data.createGatheringTriggerScript),
            createGatheringDoneTriggerScript(data.createGatheringDoneTriggerScript),
            joinGatheringTriggerScript(data.joinGatheringTriggerScript),
            joinGatheringDoneTriggerScript(data.joinGatheringDoneTriggerScript),
            leaveGatheringTriggerScript(data.leaveGatheringTriggerScript),
            leaveGatheringDoneTriggerScript(data.leaveGatheringDoneTriggerScript),
            breakupGatheringTriggerScript(data.breakupGatheringTriggerScript),
            matchmakingCompleteTriggerScript(data.matchmakingCompleteTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            matchmakingId(std::move(data.matchmakingId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            type(std::move(data.type)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            maxPlayer(std::move(data.maxPlayer)),
            callback(std::move(data.callback)),
            gatheringPoolName(std::move(data.gatheringPoolName)),
            notificationGameName(std::move(data.notificationGameName)),
            createGatheringTriggerScript(std::move(data.createGatheringTriggerScript)),
            createGatheringDoneTriggerScript(std::move(data.createGatheringDoneTriggerScript)),
            joinGatheringTriggerScript(std::move(data.joinGatheringTriggerScript)),
            joinGatheringDoneTriggerScript(std::move(data.joinGatheringDoneTriggerScript)),
            leaveGatheringTriggerScript(std::move(data.leaveGatheringTriggerScript)),
            leaveGatheringDoneTriggerScript(std::move(data.leaveGatheringDoneTriggerScript)),
            breakupGatheringTriggerScript(std::move(data.breakupGatheringTriggerScript)),
            matchmakingCompleteTriggerScript(std::move(data.matchmakingCompleteTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "matchmakingId") == 0) {
                if (jsonValue.IsString())
                {
                    this->matchmakingId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "serviceClass") == 0) {
                if (jsonValue.IsString())
                {
                    this->serviceClass.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "maxPlayer") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxPlayer = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "callback") == 0) {
                if (jsonValue.IsString())
                {
                    this->callback.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "gatheringPoolName") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringPoolName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationGameName") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationGameName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createGatheringTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createGatheringTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createGatheringDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createGatheringDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "joinGatheringTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->joinGatheringTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "joinGatheringDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->joinGatheringDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "leaveGatheringTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->leaveGatheringTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "leaveGatheringDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->leaveGatheringDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "breakupGatheringTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->breakupGatheringTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "matchmakingCompleteTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->matchmakingCompleteTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    Matchmaking() :
        m_pData(nullptr)
    {}

    Matchmaking(const Matchmaking& matchmaking) :
        Gs2Object(matchmaking),
        m_pData(matchmaking.m_pData != nullptr ? new Data(*matchmaking.m_pData) : nullptr)
    {}

    Matchmaking(Matchmaking&& matchmaking) :
        Gs2Object(std::move(matchmaking)),
        m_pData(matchmaking.m_pData)
    {
        matchmaking.m_pData = nullptr;
    }

    ~Matchmaking()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Matchmaking& operator=(const Matchmaking& matchmaking)
    {
        Gs2Object::operator=(matchmaking);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*matchmaking.m_pData);

        return *this;
    }

    Matchmaking& operator=(Matchmaking&& matchmaking)
    {
        Gs2Object::operator=(std::move(matchmaking));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = matchmaking.m_pData;
        matchmaking.m_pData = nullptr;

        return *this;
    }

    const Matchmaking* operator->() const
    {
        return this;
    }

    Matchmaking* operator->()
    {
        return this;
    }


    /**
     * マッチメイキングGRNを取得
     *
     * @return マッチメイキングGRN
     */
    const optional<StringHolder>& getMatchmakingId() const
    {
        return ensureData().matchmakingId;
    }

    /**
     * マッチメイキングGRNを設定
     *
     * @param matchmakingId マッチメイキングGRN
     */
    void setMatchmakingId(const Char* matchmakingId)
    {
        ensureData().matchmakingId.emplace(matchmakingId);
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
     * マッチメイキング名を取得
     *
     * @return マッチメイキング名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * マッチメイキング名を設定
     *
     * @param name マッチメイキング名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * マッチメイキング方式を取得
     *
     * @return マッチメイキング方式
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * マッチメイキング方式を設定
     *
     * @param type マッチメイキング方式
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * 最大プレイヤー数を取得
     *
     * @return 最大プレイヤー数
     */
    const optional<Int32>& getMaxPlayer() const
    {
        return ensureData().maxPlayer;
    }

    /**
     * 最大プレイヤー数を設定
     *
     * @param maxPlayer 最大プレイヤー数
     */
    void setMaxPlayer(Int32 maxPlayer)
    {
        ensureData().maxPlayer.emplace(maxPlayer);
    }

    /**
     * マッチメイキング完了時の通知先URLを取得
     *
     * @return マッチメイキング完了時の通知先URL
     */
    const optional<StringHolder>& getCallback() const
    {
        return ensureData().callback;
    }

    /**
     * マッチメイキング完了時の通知先URLを設定
     *
     * @param callback マッチメイキング完了時の通知先URL
     */
    void setCallback(const Char* callback)
    {
        ensureData().callback.emplace(callback);
    }

    /**
     * マッチメイキング完了時に GS2-Realtime と自動的に連携する場合に指定するギャザリングプール名を取得
     *
     * @return マッチメイキング完了時に GS2-Realtime と自動的に連携する場合に指定するギャザリングプール名
     */
    const optional<StringHolder>& getGatheringPoolName() const
    {
        return ensureData().gatheringPoolName;
    }

    /**
     * マッチメイキング完了時に GS2-Realtime と自動的に連携する場合に指定するギャザリングプール名を設定
     *
     * @param gatheringPoolName マッチメイキング完了時に GS2-Realtime と自動的に連携する場合に指定するギャザリングプール名
     */
    void setGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
    }

    /**
     * マッチメイキングの状態変化や完了通知を GS2-InGamePushNotification を使用して通知する場合に指定するゲーム名を取得
     *
     * @return マッチメイキングの状態変化や完了通知を GS2-InGamePushNotification を使用して通知する場合に指定するゲーム名
     */
    const optional<StringHolder>& getNotificationGameName() const
    {
        return ensureData().notificationGameName;
    }

    /**
     * マッチメイキングの状態変化や完了通知を GS2-InGamePushNotification を使用して通知する場合に指定するゲーム名を設定
     *
     * @param notificationGameName マッチメイキングの状態変化や完了通知を GS2-InGamePushNotification を使用して通知する場合に指定するゲーム名
     */
    void setNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
    }

    /**
     * ギャザリング作成時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング作成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateGatheringTriggerScript() const
    {
        return ensureData().createGatheringTriggerScript;
    }

    /**
     * ギャザリング作成時 に実行されるGS2-Scriptを設定
     *
     * @param createGatheringTriggerScript ギャザリング作成時 に実行されるGS2-Script
     */
    void setCreateGatheringTriggerScript(const Char* createGatheringTriggerScript)
    {
        ensureData().createGatheringTriggerScript.emplace(createGatheringTriggerScript);
    }

    /**
     * ギャザリング作成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング作成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateGatheringDoneTriggerScript() const
    {
        return ensureData().createGatheringDoneTriggerScript;
    }

    /**
     * ギャザリング作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createGatheringDoneTriggerScript ギャザリング作成完了時 に実行されるGS2-Script
     */
    void setCreateGatheringDoneTriggerScript(const Char* createGatheringDoneTriggerScript)
    {
        ensureData().createGatheringDoneTriggerScript.emplace(createGatheringDoneTriggerScript);
    }

    /**
     * ギャザリング参加時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング参加時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getJoinGatheringTriggerScript() const
    {
        return ensureData().joinGatheringTriggerScript;
    }

    /**
     * ギャザリング参加時 に実行されるGS2-Scriptを設定
     *
     * @param joinGatheringTriggerScript ギャザリング参加時 に実行されるGS2-Script
     */
    void setJoinGatheringTriggerScript(const Char* joinGatheringTriggerScript)
    {
        ensureData().joinGatheringTriggerScript.emplace(joinGatheringTriggerScript);
    }

    /**
     * ギャザリング参加完了時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング参加完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getJoinGatheringDoneTriggerScript() const
    {
        return ensureData().joinGatheringDoneTriggerScript;
    }

    /**
     * ギャザリング参加完了時 に実行されるGS2-Scriptを設定
     *
     * @param joinGatheringDoneTriggerScript ギャザリング参加完了時 に実行されるGS2-Script
     */
    void setJoinGatheringDoneTriggerScript(const Char* joinGatheringDoneTriggerScript)
    {
        ensureData().joinGatheringDoneTriggerScript.emplace(joinGatheringDoneTriggerScript);
    }

    /**
     * ギャザリング離脱時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング離脱時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getLeaveGatheringTriggerScript() const
    {
        return ensureData().leaveGatheringTriggerScript;
    }

    /**
     * ギャザリング離脱時 に実行されるGS2-Scriptを設定
     *
     * @param leaveGatheringTriggerScript ギャザリング離脱時 に実行されるGS2-Script
     */
    void setLeaveGatheringTriggerScript(const Char* leaveGatheringTriggerScript)
    {
        ensureData().leaveGatheringTriggerScript.emplace(leaveGatheringTriggerScript);
    }

    /**
     * ギャザリング離脱完了時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング離脱完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getLeaveGatheringDoneTriggerScript() const
    {
        return ensureData().leaveGatheringDoneTriggerScript;
    }

    /**
     * ギャザリング離脱完了時 に実行されるGS2-Scriptを設定
     *
     * @param leaveGatheringDoneTriggerScript ギャザリング離脱完了時 に実行されるGS2-Script
     */
    void setLeaveGatheringDoneTriggerScript(const Char* leaveGatheringDoneTriggerScript)
    {
        ensureData().leaveGatheringDoneTriggerScript.emplace(leaveGatheringDoneTriggerScript);
    }

    /**
     * ギャザリング解散時 に実行されるGS2-Scriptを取得
     *
     * @return ギャザリング解散時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getBreakupGatheringTriggerScript() const
    {
        return ensureData().breakupGatheringTriggerScript;
    }

    /**
     * ギャザリング解散時 に実行されるGS2-Scriptを設定
     *
     * @param breakupGatheringTriggerScript ギャザリング解散時 に実行されるGS2-Script
     */
    void setBreakupGatheringTriggerScript(const Char* breakupGatheringTriggerScript)
    {
        ensureData().breakupGatheringTriggerScript.emplace(breakupGatheringTriggerScript);
    }

    /**
     * マッチメイキング成立時 に実行されるGS2-Scriptを取得
     *
     * @return マッチメイキング成立時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getMatchmakingCompleteTriggerScript() const
    {
        return ensureData().matchmakingCompleteTriggerScript;
    }

    /**
     * マッチメイキング成立時 に実行されるGS2-Scriptを設定
     *
     * @param matchmakingCompleteTriggerScript マッチメイキング成立時 に実行されるGS2-Script
     */
    void setMatchmakingCompleteTriggerScript(const Char* matchmakingCompleteTriggerScript)
    {
        ensureData().matchmakingCompleteTriggerScript.emplace(matchmakingCompleteTriggerScript);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MATCHMAKING_MODEL_MATCHMAKING_HPP_