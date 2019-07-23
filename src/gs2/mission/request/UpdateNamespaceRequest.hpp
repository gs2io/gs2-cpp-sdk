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

#ifndef GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MissionConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace mission
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ミッション達成時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteTriggerScriptId;
        /** ミッション達成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteDoneTriggerScriptId;
        /** ミッション達成完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> missionCompleteDoneTriggerQueueNamespaceId;
        /** カウンター上昇時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementTriggerScriptId;
        /** カウンター上昇完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementDoneTriggerScriptId;
        /** カウンター上昇完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> counterIncrementDoneTriggerQueueNamespaceId;
        /** 報酬受け取り時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsTriggerScriptId;
        /** 報酬受け取り完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerScriptId;
        /** 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerQueueNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            missionCompleteTriggerScriptId(data.missionCompleteTriggerScriptId),
            missionCompleteDoneTriggerScriptId(data.missionCompleteDoneTriggerScriptId),
            missionCompleteDoneTriggerQueueNamespaceId(data.missionCompleteDoneTriggerQueueNamespaceId),
            counterIncrementTriggerScriptId(data.counterIncrementTriggerScriptId),
            counterIncrementDoneTriggerScriptId(data.counterIncrementDoneTriggerScriptId),
            counterIncrementDoneTriggerQueueNamespaceId(data.counterIncrementDoneTriggerQueueNamespaceId),
            receiveRewardsTriggerScriptId(data.receiveRewardsTriggerScriptId),
            receiveRewardsDoneTriggerScriptId(data.receiveRewardsDoneTriggerScriptId),
            receiveRewardsDoneTriggerQueueNamespaceId(data.receiveRewardsDoneTriggerQueueNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            missionCompleteTriggerScriptId(std::move(data.missionCompleteTriggerScriptId)),
            missionCompleteDoneTriggerScriptId(std::move(data.missionCompleteDoneTriggerScriptId)),
            missionCompleteDoneTriggerQueueNamespaceId(std::move(data.missionCompleteDoneTriggerQueueNamespaceId)),
            counterIncrementTriggerScriptId(std::move(data.counterIncrementTriggerScriptId)),
            counterIncrementDoneTriggerScriptId(std::move(data.counterIncrementDoneTriggerScriptId)),
            counterIncrementDoneTriggerQueueNamespaceId(std::move(data.counterIncrementDoneTriggerQueueNamespaceId)),
            receiveRewardsTriggerScriptId(std::move(data.receiveRewardsTriggerScriptId)),
            receiveRewardsDoneTriggerScriptId(std::move(data.receiveRewardsDoneTriggerScriptId)),
            receiveRewardsDoneTriggerQueueNamespaceId(std::move(data.receiveRewardsDoneTriggerQueueNamespaceId)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId))
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
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Mission(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Mission(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Mission::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Mission::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
    {
        return this;
    }
    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    UpdateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteTriggerScriptId() const
    {
        return ensureData().missionCompleteTriggerScriptId;
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteTriggerScriptId(const Char* missionCompleteTriggerScriptId)
    {
        ensureData().missionCompleteTriggerScriptId.emplace(missionCompleteTriggerScriptId);
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteTriggerScriptId(const Char* missionCompleteTriggerScriptId)
    {
        ensureData().missionCompleteTriggerScriptId.emplace(missionCompleteTriggerScriptId);
        return *this;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerScriptId() const
    {
        return ensureData().missionCompleteDoneTriggerScriptId;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteDoneTriggerScriptId(const Char* missionCompleteDoneTriggerScriptId)
    {
        ensureData().missionCompleteDoneTriggerScriptId.emplace(missionCompleteDoneTriggerScriptId);
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteDoneTriggerScriptId(const Char* missionCompleteDoneTriggerScriptId)
    {
        ensureData().missionCompleteDoneTriggerScriptId.emplace(missionCompleteDoneTriggerScriptId);
        return *this;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerQueueNamespaceId() const
    {
        return ensureData().missionCompleteDoneTriggerQueueNamespaceId;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    void setMissionCompleteDoneTriggerQueueNamespaceId(const Char* missionCompleteDoneTriggerQueueNamespaceId)
    {
        ensureData().missionCompleteDoneTriggerQueueNamespaceId.emplace(missionCompleteDoneTriggerQueueNamespaceId);
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteDoneTriggerQueueNamespaceId(const Char* missionCompleteDoneTriggerQueueNamespaceId)
    {
        ensureData().missionCompleteDoneTriggerQueueNamespaceId.emplace(missionCompleteDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementTriggerScriptId() const
    {
        return ensureData().counterIncrementTriggerScriptId;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementTriggerScriptId(const Char* counterIncrementTriggerScriptId)
    {
        ensureData().counterIncrementTriggerScriptId.emplace(counterIncrementTriggerScriptId);
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementTriggerScriptId(const Char* counterIncrementTriggerScriptId)
    {
        ensureData().counterIncrementTriggerScriptId.emplace(counterIncrementTriggerScriptId);
        return *this;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerScriptId() const
    {
        return ensureData().counterIncrementDoneTriggerScriptId;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementDoneTriggerScriptId(const Char* counterIncrementDoneTriggerScriptId)
    {
        ensureData().counterIncrementDoneTriggerScriptId.emplace(counterIncrementDoneTriggerScriptId);
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementDoneTriggerScriptId(const Char* counterIncrementDoneTriggerScriptId)
    {
        ensureData().counterIncrementDoneTriggerScriptId.emplace(counterIncrementDoneTriggerScriptId);
        return *this;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerQueueNamespaceId() const
    {
        return ensureData().counterIncrementDoneTriggerQueueNamespaceId;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    void setCounterIncrementDoneTriggerQueueNamespaceId(const Char* counterIncrementDoneTriggerQueueNamespaceId)
    {
        ensureData().counterIncrementDoneTriggerQueueNamespaceId.emplace(counterIncrementDoneTriggerQueueNamespaceId);
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementDoneTriggerQueueNamespaceId(const Char* counterIncrementDoneTriggerQueueNamespaceId)
    {
        ensureData().counterIncrementDoneTriggerQueueNamespaceId.emplace(counterIncrementDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsTriggerScriptId() const
    {
        return ensureData().receiveRewardsTriggerScriptId;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsTriggerScriptId(const Char* receiveRewardsTriggerScriptId)
    {
        ensureData().receiveRewardsTriggerScriptId.emplace(receiveRewardsTriggerScriptId);
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsTriggerScriptId(const Char* receiveRewardsTriggerScriptId)
    {
        ensureData().receiveRewardsTriggerScriptId.emplace(receiveRewardsTriggerScriptId);
        return *this;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerScriptId() const
    {
        return ensureData().receiveRewardsDoneTriggerScriptId;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsDoneTriggerScriptId(const Char* receiveRewardsDoneTriggerScriptId)
    {
        ensureData().receiveRewardsDoneTriggerScriptId.emplace(receiveRewardsDoneTriggerScriptId);
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsDoneTriggerScriptId(const Char* receiveRewardsDoneTriggerScriptId)
    {
        ensureData().receiveRewardsDoneTriggerScriptId.emplace(receiveRewardsDoneTriggerScriptId);
        return *this;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerQueueNamespaceId() const
    {
        return ensureData().receiveRewardsDoneTriggerQueueNamespaceId;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReceiveRewardsDoneTriggerQueueNamespaceId(const Char* receiveRewardsDoneTriggerQueueNamespaceId)
    {
        ensureData().receiveRewardsDoneTriggerQueueNamespaceId.emplace(receiveRewardsDoneTriggerQueueNamespaceId);
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsDoneTriggerQueueNamespaceId(const Char* receiveRewardsDoneTriggerQueueNamespaceId)
    {
        ensureData().receiveRewardsDoneTriggerQueueNamespaceId.emplace(receiveRewardsDoneTriggerQueueNamespaceId);
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
    void setQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    UpdateNamespaceRequest& withQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
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
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    UpdateNamespaceRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_