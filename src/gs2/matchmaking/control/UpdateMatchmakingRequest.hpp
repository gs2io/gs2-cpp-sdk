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

#ifndef GS2_MATCHMAKING_CONTROL_UPDATEMATCHMAKINGREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_UPDATEMATCHMAKINGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace matchmaking
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateMatchmakingRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "UpdateMatchmaking";

private:
    class Data : public Gs2Object
    {
    public:
        /** マッチメイキングの名前を指定します。 */
        optional<StringHolder> matchmakingName;
        /** マッチメイキングの説明 */
        optional<StringHolder> description;
        /** マッチメイキングのサービスクラス */
        optional<StringHolder> serviceClass;
        /** GS2-Realtime のギャザリングプール名 */
        optional<StringHolder> gatheringPoolName;
        /** マッチメイキング完了コールバックURL */
        optional<StringHolder> callback;
        /** GS2-InGamePushNotification のゲーム名 */
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            matchmakingName(data.matchmakingName),
            description(data.description),
            serviceClass(data.serviceClass),
            gatheringPoolName(data.gatheringPoolName),
            callback(data.callback),
            notificationGameName(data.notificationGameName),
            createGatheringTriggerScript(data.createGatheringTriggerScript),
            createGatheringDoneTriggerScript(data.createGatheringDoneTriggerScript),
            joinGatheringTriggerScript(data.joinGatheringTriggerScript),
            joinGatheringDoneTriggerScript(data.joinGatheringDoneTriggerScript),
            leaveGatheringTriggerScript(data.leaveGatheringTriggerScript),
            leaveGatheringDoneTriggerScript(data.leaveGatheringDoneTriggerScript),
            breakupGatheringTriggerScript(data.breakupGatheringTriggerScript),
            matchmakingCompleteTriggerScript(data.matchmakingCompleteTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            matchmakingName(std::move(data.matchmakingName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            gatheringPoolName(std::move(data.gatheringPoolName)),
            callback(std::move(data.callback)),
            notificationGameName(std::move(data.notificationGameName)),
            createGatheringTriggerScript(std::move(data.createGatheringTriggerScript)),
            createGatheringDoneTriggerScript(std::move(data.createGatheringDoneTriggerScript)),
            joinGatheringTriggerScript(std::move(data.joinGatheringTriggerScript)),
            joinGatheringDoneTriggerScript(std::move(data.joinGatheringDoneTriggerScript)),
            leaveGatheringTriggerScript(std::move(data.leaveGatheringTriggerScript)),
            leaveGatheringDoneTriggerScript(std::move(data.leaveGatheringDoneTriggerScript)),
            breakupGatheringTriggerScript(std::move(data.breakupGatheringTriggerScript)),
            matchmakingCompleteTriggerScript(std::move(data.matchmakingCompleteTriggerScript))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    UpdateMatchmakingRequest() :
        m_pData(nullptr)
    {}

    UpdateMatchmakingRequest(const UpdateMatchmakingRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateMatchmakingRequest(UpdateMatchmakingRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateMatchmakingRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMatchmakingRequest& operator=(const UpdateMatchmakingRequest& updateMatchmakingRequest)
    {
        Gs2BasicRequest::operator=(updateMatchmakingRequest);
        Gs2Matchmaking::operator=(updateMatchmakingRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMatchmakingRequest.m_pData);

        return *this;
    }

    UpdateMatchmakingRequest& operator=(UpdateMatchmakingRequest&& updateMatchmakingRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateMatchmakingRequest));
        Gs2Matchmaking::operator=(std::move(updateMatchmakingRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMatchmakingRequest.m_pData;
        updateMatchmakingRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateMatchmakingRequest* operator->() const
    {
        return this;
    }

    UpdateMatchmakingRequest* operator->()
    {
        return this;
    }

    /**
     * マッチメイキングの名前を指定します。を取得
     *
     * @return マッチメイキングの名前を指定します。
     */
    const optional<StringHolder>& getMatchmakingName() const
    {
        return ensureData().matchmakingName;
    }

    /**
     * マッチメイキングの名前を指定します。を設定
     *
     * @param matchmakingName マッチメイキングの名前を指定します。
     */
    void setMatchmakingName(const Char* matchmakingName)
    {
        ensureData().matchmakingName.emplace(matchmakingName);
    }

    /**
     * マッチメイキングの名前を指定します。を設定
     *
     * @param matchmakingName マッチメイキングの名前を指定します。
     */
    UpdateMatchmakingRequest& withMatchmakingName(const Char* matchmakingName)
    {
        ensureData().matchmakingName.emplace(matchmakingName);
        return *this;
    }

    /**
     * マッチメイキングの説明を取得
     *
     * @return マッチメイキングの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * マッチメイキングの説明を設定
     *
     * @param description マッチメイキングの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * マッチメイキングの説明を設定
     *
     * @param description マッチメイキングの説明
     */
    UpdateMatchmakingRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * マッチメイキングのサービスクラスを取得
     *
     * @return マッチメイキングのサービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * マッチメイキングのサービスクラスを設定
     *
     * @param serviceClass マッチメイキングのサービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * マッチメイキングのサービスクラスを設定
     *
     * @param serviceClass マッチメイキングのサービスクラス
     */
    UpdateMatchmakingRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * GS2-Realtime のギャザリングプール名を取得
     *
     * @return GS2-Realtime のギャザリングプール名
     */
    const optional<StringHolder>& getGatheringPoolName() const
    {
        return ensureData().gatheringPoolName;
    }

    /**
     * GS2-Realtime のギャザリングプール名を設定
     *
     * @param gatheringPoolName GS2-Realtime のギャザリングプール名
     */
    void setGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
    }

    /**
     * GS2-Realtime のギャザリングプール名を設定
     *
     * @param gatheringPoolName GS2-Realtime のギャザリングプール名
     */
    UpdateMatchmakingRequest& withGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
        return *this;
    }

    /**
     * マッチメイキング完了コールバックURLを取得
     *
     * @return マッチメイキング完了コールバックURL
     */
    const optional<StringHolder>& getCallback() const
    {
        return ensureData().callback;
    }

    /**
     * マッチメイキング完了コールバックURLを設定
     *
     * @param callback マッチメイキング完了コールバックURL
     */
    void setCallback(const Char* callback)
    {
        ensureData().callback.emplace(callback);
    }

    /**
     * マッチメイキング完了コールバックURLを設定
     *
     * @param callback マッチメイキング完了コールバックURL
     */
    UpdateMatchmakingRequest& withCallback(const Char* callback)
    {
        ensureData().callback.emplace(callback);
        return *this;
    }

    /**
     * GS2-InGamePushNotification のゲーム名を取得
     *
     * @return GS2-InGamePushNotification のゲーム名
     */
    const optional<StringHolder>& getNotificationGameName() const
    {
        return ensureData().notificationGameName;
    }

    /**
     * GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName GS2-InGamePushNotification のゲーム名
     */
    void setNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
    }

    /**
     * GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName GS2-InGamePushNotification のゲーム名
     */
    UpdateMatchmakingRequest& withNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
        return *this;
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
     * ギャザリング作成時 に実行されるGS2-Scriptを設定
     *
     * @param createGatheringTriggerScript ギャザリング作成時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withCreateGatheringTriggerScript(const Char* createGatheringTriggerScript)
    {
        ensureData().createGatheringTriggerScript.emplace(createGatheringTriggerScript);
        return *this;
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
     * ギャザリング作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createGatheringDoneTriggerScript ギャザリング作成完了時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withCreateGatheringDoneTriggerScript(const Char* createGatheringDoneTriggerScript)
    {
        ensureData().createGatheringDoneTriggerScript.emplace(createGatheringDoneTriggerScript);
        return *this;
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
     * ギャザリング参加時 に実行されるGS2-Scriptを設定
     *
     * @param joinGatheringTriggerScript ギャザリング参加時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withJoinGatheringTriggerScript(const Char* joinGatheringTriggerScript)
    {
        ensureData().joinGatheringTriggerScript.emplace(joinGatheringTriggerScript);
        return *this;
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
     * ギャザリング参加完了時 に実行されるGS2-Scriptを設定
     *
     * @param joinGatheringDoneTriggerScript ギャザリング参加完了時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withJoinGatheringDoneTriggerScript(const Char* joinGatheringDoneTriggerScript)
    {
        ensureData().joinGatheringDoneTriggerScript.emplace(joinGatheringDoneTriggerScript);
        return *this;
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
     * ギャザリング離脱時 に実行されるGS2-Scriptを設定
     *
     * @param leaveGatheringTriggerScript ギャザリング離脱時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withLeaveGatheringTriggerScript(const Char* leaveGatheringTriggerScript)
    {
        ensureData().leaveGatheringTriggerScript.emplace(leaveGatheringTriggerScript);
        return *this;
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
     * ギャザリング離脱完了時 に実行されるGS2-Scriptを設定
     *
     * @param leaveGatheringDoneTriggerScript ギャザリング離脱完了時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withLeaveGatheringDoneTriggerScript(const Char* leaveGatheringDoneTriggerScript)
    {
        ensureData().leaveGatheringDoneTriggerScript.emplace(leaveGatheringDoneTriggerScript);
        return *this;
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
     * ギャザリング解散時 に実行されるGS2-Scriptを設定
     *
     * @param breakupGatheringTriggerScript ギャザリング解散時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withBreakupGatheringTriggerScript(const Char* breakupGatheringTriggerScript)
    {
        ensureData().breakupGatheringTriggerScript.emplace(breakupGatheringTriggerScript);
        return *this;
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
     * マッチメイキング成立時 に実行されるGS2-Scriptを設定
     *
     * @param matchmakingCompleteTriggerScript マッチメイキング成立時 に実行されるGS2-Script
     */
    UpdateMatchmakingRequest& withMatchmakingCompleteTriggerScript(const Char* matchmakingCompleteTriggerScript)
    {
        ensureData().matchmakingCompleteTriggerScript.emplace(matchmakingCompleteTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateMatchmakingRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateMatchmakingRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateMatchmakingRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateMatchmakingRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_UPDATEMATCHMAKINGREQUEST_HPP_