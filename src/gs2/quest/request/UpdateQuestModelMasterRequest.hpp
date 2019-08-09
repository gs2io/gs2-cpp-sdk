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

#ifndef GS2_QUEST_CONTROL_UPDATEQUESTMODELMASTERREQUEST_HPP_
#define GS2_QUEST_CONTROL_UPDATEQUESTMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * クエストモデルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateQuestModelMasterRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** クエストグループモデル名 */
        optional<StringHolder> questGroupName;
        /** クエスト名 */
        optional<StringHolder> questName;
        /** クエストモデルの説明 */
        optional<StringHolder> description;
        /** クエストのメタデータ */
        optional<StringHolder> metadata;
        /** クエストの内容 */
        optional<List<Contents>> contents;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;
        /** クエストの参加料 */
        optional<List<ConsumeAction>> consumeActions;
        /** クエスト失敗時の報酬 */
        optional<List<AcquireAction>> failedAcquireActions;
        /** クエストに挑戦するためにクリアしておく必要のあるクエスト名 */
        optional<List<StringHolder>> premiseQuestNames;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            questGroupName(data.questGroupName),
            questName(data.questName),
            description(data.description),
            metadata(data.metadata),
            contents(data.contents),
            challengePeriodEventId(data.challengePeriodEventId),
            consumeActions(data.consumeActions),
            failedAcquireActions(data.failedAcquireActions),
            premiseQuestNames(data.premiseQuestNames)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            questGroupName(std::move(data.questGroupName)),
            questName(std::move(data.questName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            contents(std::move(data.contents)),
            challengePeriodEventId(std::move(data.challengePeriodEventId)),
            consumeActions(std::move(data.consumeActions)),
            failedAcquireActions(std::move(data.failedAcquireActions)),
            premiseQuestNames(std::move(data.premiseQuestNames))
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
    UpdateQuestModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateQuestModelMasterRequest(const UpdateQuestModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Quest(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateQuestModelMasterRequest(UpdateQuestModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Quest(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateQuestModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateQuestModelMasterRequest& operator=(const UpdateQuestModelMasterRequest& updateQuestModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateQuestModelMasterRequest);
        Gs2Quest::operator=(updateQuestModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateQuestModelMasterRequest.m_pData);

        return *this;
    }

    UpdateQuestModelMasterRequest& operator=(UpdateQuestModelMasterRequest&& updateQuestModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateQuestModelMasterRequest));
        Gs2Quest::operator=(std::move(updateQuestModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateQuestModelMasterRequest.m_pData;
        updateQuestModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateQuestModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateQuestModelMasterRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    UpdateQuestModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * クエストグループモデル名を取得
     *
     * @return クエストグループモデル名
     */
    const optional<StringHolder>& getQuestGroupName() const
    {
        return ensureData().questGroupName;
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param questGroupName クエストグループモデル名
     */
    void setQuestGroupName(const Char* questGroupName)
    {
        ensureData().questGroupName.emplace(questGroupName);
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param questGroupName クエストグループモデル名
     */
    UpdateQuestModelMasterRequest& withQuestGroupName(const Char* questGroupName)
    {
        ensureData().questGroupName.emplace(questGroupName);
        return *this;
    }

    /**
     * クエスト名を取得
     *
     * @return クエスト名
     */
    const optional<StringHolder>& getQuestName() const
    {
        return ensureData().questName;
    }

    /**
     * クエスト名を設定
     *
     * @param questName クエスト名
     */
    void setQuestName(const Char* questName)
    {
        ensureData().questName.emplace(questName);
    }

    /**
     * クエスト名を設定
     *
     * @param questName クエスト名
     */
    UpdateQuestModelMasterRequest& withQuestName(const Char* questName)
    {
        ensureData().questName.emplace(questName);
        return *this;
    }

    /**
     * クエストモデルの説明を取得
     *
     * @return クエストモデルの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * クエストモデルの説明を設定
     *
     * @param description クエストモデルの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * クエストモデルの説明を設定
     *
     * @param description クエストモデルの説明
     */
    UpdateQuestModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * クエストのメタデータを取得
     *
     * @return クエストのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストのメタデータを設定
     *
     * @param metadata クエストのメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * クエストのメタデータを設定
     *
     * @param metadata クエストのメタデータ
     */
    UpdateQuestModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * クエストの内容を取得
     *
     * @return クエストの内容
     */
    const optional<List<Contents>>& getContents() const
    {
        return ensureData().contents;
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    void setContents(const List<Contents>& contents)
    {
        ensureData().contents.emplace(contents);
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    UpdateQuestModelMasterRequest& withContents(const List<Contents>& contents)
    {
        ensureData().contents.emplace(contents);
        return *this;
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return 挑戦可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    UpdateQuestModelMasterRequest& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
        return *this;
    }

    /**
     * クエストの参加料を取得
     *
     * @return クエストの参加料
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    void setConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        ensureData().consumeActions.emplace(consumeActions);
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    UpdateQuestModelMasterRequest& withConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        ensureData().consumeActions.emplace(consumeActions);
        return *this;
    }

    /**
     * クエスト失敗時の報酬を取得
     *
     * @return クエスト失敗時の報酬
     */
    const optional<List<AcquireAction>>& getFailedAcquireActions() const
    {
        return ensureData().failedAcquireActions;
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    void setFailedAcquireActions(const List<AcquireAction>& failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(failedAcquireActions);
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    UpdateQuestModelMasterRequest& withFailedAcquireActions(const List<AcquireAction>& failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(failedAcquireActions);
        return *this;
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を取得
     *
     * @return クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    const optional<List<StringHolder>>& getPremiseQuestNames() const
    {
        return ensureData().premiseQuestNames;
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    void setPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(premiseQuestNames);
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    UpdateQuestModelMasterRequest& withPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(premiseQuestNames);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateQuestModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateQuestModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateQuestModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateQuestModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_UPDATEQUESTMODELMASTERREQUEST_HPP_