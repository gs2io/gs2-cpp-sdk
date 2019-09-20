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

#ifndef GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/quest/Gs2QuestConst.hpp>
#include <gs2/quest/model/model.hpp>
#include <memory>

namespace gs2 { namespace quest
{

/**
 * クエストを分類するカテゴリーを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** クエスト開始したときに実行するスクリプト */
        optional<ScriptSetting> startQuestScript;
        /** クエストクリアしたときに実行するスクリプト */
        optional<ScriptSetting> completeQuestScript;
        /** クエスト失敗したときに実行するスクリプト */
        optional<ScriptSetting> failedQuestScript;
        /** 報酬付与処理をジョブとして追加するキューのネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {
            if (data.startQuestScript)
            {
                startQuestScript = data.startQuestScript->deepCopy();
            }
            if (data.completeQuestScript)
            {
                completeQuestScript = data.completeQuestScript->deepCopy();
            }
            if (data.failedQuestScript)
            {
                failedQuestScript = data.failedQuestScript->deepCopy();
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
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
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
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * クエスト開始したときに実行するスクリプトを取得
     *
     * @return クエスト開始したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getStartQuestScript() const
    {
        return ensureData().startQuestScript;
    }

    /**
     * クエスト開始したときに実行するスクリプトを設定
     *
     * @param startQuestScript クエスト開始したときに実行するスクリプト
     */
    void setStartQuestScript(ScriptSetting startQuestScript)
    {
        ensureData().startQuestScript.emplace(std::move(startQuestScript));
    }

    /**
     * クエスト開始したときに実行するスクリプトを設定
     *
     * @param startQuestScript クエスト開始したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withStartQuestScript(ScriptSetting startQuestScript)
    {
        ensureData().startQuestScript.emplace(std::move(startQuestScript));
        return *this;
    }

    /**
     * クエストクリアしたときに実行するスクリプトを取得
     *
     * @return クエストクリアしたときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCompleteQuestScript() const
    {
        return ensureData().completeQuestScript;
    }

    /**
     * クエストクリアしたときに実行するスクリプトを設定
     *
     * @param completeQuestScript クエストクリアしたときに実行するスクリプト
     */
    void setCompleteQuestScript(ScriptSetting completeQuestScript)
    {
        ensureData().completeQuestScript.emplace(std::move(completeQuestScript));
    }

    /**
     * クエストクリアしたときに実行するスクリプトを設定
     *
     * @param completeQuestScript クエストクリアしたときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCompleteQuestScript(ScriptSetting completeQuestScript)
    {
        ensureData().completeQuestScript.emplace(std::move(completeQuestScript));
        return *this;
    }

    /**
     * クエスト失敗したときに実行するスクリプトを取得
     *
     * @return クエスト失敗したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getFailedQuestScript() const
    {
        return ensureData().failedQuestScript;
    }

    /**
     * クエスト失敗したときに実行するスクリプトを設定
     *
     * @param failedQuestScript クエスト失敗したときに実行するスクリプト
     */
    void setFailedQuestScript(ScriptSetting failedQuestScript)
    {
        ensureData().failedQuestScript.emplace(std::move(failedQuestScript));
    }

    /**
     * クエスト失敗したときに実行するスクリプトを設定
     *
     * @param failedQuestScript クエスト失敗したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withFailedQuestScript(ScriptSetting failedQuestScript)
    {
        ensureData().failedQuestScript.emplace(std::move(failedQuestScript));
        return *this;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを取得
     *
     * @return 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    void setQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
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
    UpdateNamespaceRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_