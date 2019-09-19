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

#ifndef GS2_QUEST_CONTROL_CREATEQUESTGROUPMODELMASTERREQUEST_HPP_
#define GS2_QUEST_CONTROL_CREATEQUESTGROUPMODELMASTERREQUEST_HPP_

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
 * クエストグループマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateQuestGroupModelMasterRequest : public Gs2BasicRequest, public Gs2Quest
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
        optional<StringHolder> name;
        /** クエストグループマスターの説明 */
        optional<StringHolder> description;
        /** クエストグループのメタデータ */
        optional<StringHolder> metadata;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId)
        {
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
    CreateQuestGroupModelMasterRequest() = default;
    CreateQuestGroupModelMasterRequest(const CreateQuestGroupModelMasterRequest& createQuestGroupModelMasterRequest) = default;
    CreateQuestGroupModelMasterRequest(CreateQuestGroupModelMasterRequest&& createQuestGroupModelMasterRequest) = default;
    ~CreateQuestGroupModelMasterRequest() GS2_OVERRIDE = default;

    CreateQuestGroupModelMasterRequest& operator=(const CreateQuestGroupModelMasterRequest& createQuestGroupModelMasterRequest) = default;
    CreateQuestGroupModelMasterRequest& operator=(CreateQuestGroupModelMasterRequest&& createQuestGroupModelMasterRequest) = default;

    CreateQuestGroupModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateQuestGroupModelMasterRequest);
    }

    const CreateQuestGroupModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateQuestGroupModelMasterRequest* operator->()
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
    CreateQuestGroupModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * クエストグループモデル名を取得
     *
     * @return クエストグループモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param name クエストグループモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param name クエストグループモデル名
     */
    CreateQuestGroupModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * クエストグループマスターの説明を取得
     *
     * @return クエストグループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * クエストグループマスターの説明を設定
     *
     * @param description クエストグループマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * クエストグループマスターの説明を設定
     *
     * @param description クエストグループマスターの説明
     */
    CreateQuestGroupModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * クエストグループのメタデータを取得
     *
     * @return クエストグループのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストグループのメタデータを設定
     *
     * @param metadata クエストグループのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストグループのメタデータを設定
     *
     * @param metadata クエストグループのメタデータ
     */
    CreateQuestGroupModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    CreateQuestGroupModelMasterRequest& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateQuestGroupModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateQuestGroupModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_CREATEQUESTGROUPMODELMASTERREQUEST_HPP_