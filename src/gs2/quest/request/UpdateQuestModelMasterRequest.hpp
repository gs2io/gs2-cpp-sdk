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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            questGroupName(data.questGroupName),
            questName(data.questName),
            description(data.description),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId)
        {
            if (data.contents)
            {
                contents = data.contents->deepCopy();
            }
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.failedAcquireActions)
            {
                failedAcquireActions = data.failedAcquireActions->deepCopy();
            }
            if (data.premiseQuestNames)
            {
                premiseQuestNames = data.premiseQuestNames->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateQuestModelMasterRequest() = default;
    UpdateQuestModelMasterRequest(const UpdateQuestModelMasterRequest& updateQuestModelMasterRequest) = default;
    UpdateQuestModelMasterRequest(UpdateQuestModelMasterRequest&& updateQuestModelMasterRequest) = default;
    ~UpdateQuestModelMasterRequest() GS2_OVERRIDE = default;

    UpdateQuestModelMasterRequest& operator=(const UpdateQuestModelMasterRequest& updateQuestModelMasterRequest) = default;
    UpdateQuestModelMasterRequest& operator=(UpdateQuestModelMasterRequest&& updateQuestModelMasterRequest) = default;

    UpdateQuestModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateQuestModelMasterRequest);
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    UpdateQuestModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setQuestGroupName(StringHolder questGroupName)
    {
        ensureData().questGroupName.emplace(std::move(questGroupName));
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param questGroupName クエストグループモデル名
     */
    UpdateQuestModelMasterRequest& withQuestGroupName(StringHolder questGroupName)
    {
        ensureData().questGroupName.emplace(std::move(questGroupName));
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
    void setQuestName(StringHolder questName)
    {
        ensureData().questName.emplace(std::move(questName));
    }

    /**
     * クエスト名を設定
     *
     * @param questName クエスト名
     */
    UpdateQuestModelMasterRequest& withQuestName(StringHolder questName)
    {
        ensureData().questName.emplace(std::move(questName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * クエストモデルの説明を設定
     *
     * @param description クエストモデルの説明
     */
    UpdateQuestModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストのメタデータを設定
     *
     * @param metadata クエストのメタデータ
     */
    UpdateQuestModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    void setContents(List<Contents> contents)
    {
        ensureData().contents.emplace(std::move(contents));
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    UpdateQuestModelMasterRequest& withContents(List<Contents> contents)
    {
        ensureData().contents.emplace(std::move(contents));
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
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    UpdateQuestModelMasterRequest& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
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
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    UpdateQuestModelMasterRequest& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
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
    void setFailedAcquireActions(List<AcquireAction> failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(std::move(failedAcquireActions));
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    UpdateQuestModelMasterRequest& withFailedAcquireActions(List<AcquireAction> failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(std::move(failedAcquireActions));
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
    void setPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(std::move(premiseQuestNames));
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    UpdateQuestModelMasterRequest& withPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(std::move(premiseQuestNames));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateQuestModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateQuestModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_UPDATEQUESTMODELMASTERREQUEST_HPP_