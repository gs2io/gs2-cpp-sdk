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

#ifndef GS2_QUEST_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_QUEST_CONTROL_CREATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * クエストを分類するカテゴリーを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> name;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            startQuestScript(data.startQuestScript),
            completeQuestScript(data.completeQuestScript),
            failedQuestScript(data.failedQuestScript),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            startQuestScript(std::move(data.startQuestScript)),
            completeQuestScript(std::move(data.completeQuestScript)),
            failedQuestScript(std::move(data.failedQuestScript)),
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
    CreateNamespaceRequest() :
        m_pData(nullptr)
    {}

    CreateNamespaceRequest(const CreateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Quest(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateNamespaceRequest(CreateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Quest(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(createNamespaceRequest);
        Gs2Quest::operator=(createNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNamespaceRequest.m_pData);

        return *this;
    }

    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(createNamespaceRequest));
        Gs2Quest::operator=(std::move(createNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNamespaceRequest.m_pData;
        createNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    CreateNamespaceRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setStartQuestScript(const ScriptSetting& startQuestScript)
    {
        ensureData().startQuestScript.emplace(startQuestScript);
    }

    /**
     * クエスト開始したときに実行するスクリプトを設定
     *
     * @param startQuestScript クエスト開始したときに実行するスクリプト
     */
    CreateNamespaceRequest& withStartQuestScript(const ScriptSetting& startQuestScript)
    {
        ensureData().startQuestScript.emplace(startQuestScript);
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
    void setCompleteQuestScript(const ScriptSetting& completeQuestScript)
    {
        ensureData().completeQuestScript.emplace(completeQuestScript);
    }

    /**
     * クエストクリアしたときに実行するスクリプトを設定
     *
     * @param completeQuestScript クエストクリアしたときに実行するスクリプト
     */
    CreateNamespaceRequest& withCompleteQuestScript(const ScriptSetting& completeQuestScript)
    {
        ensureData().completeQuestScript.emplace(completeQuestScript);
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
    void setFailedQuestScript(const ScriptSetting& failedQuestScript)
    {
        ensureData().failedQuestScript.emplace(failedQuestScript);
    }

    /**
     * クエスト失敗したときに実行するスクリプトを設定
     *
     * @param failedQuestScript クエスト失敗したときに実行するスクリプト
     */
    CreateNamespaceRequest& withFailedQuestScript(const ScriptSetting& failedQuestScript)
    {
        ensureData().failedQuestScript.emplace(failedQuestScript);
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
    void setQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    CreateNamespaceRequest& withQueueNamespaceId(const Char* queueNamespaceId)
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
    CreateNamespaceRequest& withKeyId(const Char* keyId)
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
    CreateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_CREATENAMESPACEREQUEST_HPP_