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

#ifndef GS2_QUEST_MODEL_NAMESPACE_HPP_
#define GS2_QUEST_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエストを分類するカテゴリー
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
        /** クエストを分類するカテゴリー */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** カテゴリ名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** クエスト開始時 に実行されるスクリプト のGRN */
        optional<StringHolder> startQuestTriggerScriptId;
        /** クエスト開始完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> startQuestDoneTriggerScriptId;
        /** クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> startQuestDoneTriggerQueueNamespaceId;
        /** クエストクリア時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeQuestTriggerScriptId;
        /** クエストクリア完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeQuestDoneTriggerScriptId;
        /** クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> completeQuestDoneTriggerQueueNamespaceId;
        /** クエスト失敗時 に実行されるスクリプト のGRN */
        optional<StringHolder> failedQuestTriggerScriptId;
        /** クエスト失敗完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> failedQuestDoneTriggerScriptId;
        /** クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> failedQuestDoneTriggerQueueNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューのネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
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
            startQuestTriggerScriptId(data.startQuestTriggerScriptId),
            startQuestDoneTriggerScriptId(data.startQuestDoneTriggerScriptId),
            startQuestDoneTriggerQueueNamespaceId(data.startQuestDoneTriggerQueueNamespaceId),
            completeQuestTriggerScriptId(data.completeQuestTriggerScriptId),
            completeQuestDoneTriggerScriptId(data.completeQuestDoneTriggerScriptId),
            completeQuestDoneTriggerQueueNamespaceId(data.completeQuestDoneTriggerQueueNamespaceId),
            failedQuestTriggerScriptId(data.failedQuestTriggerScriptId),
            failedQuestDoneTriggerScriptId(data.failedQuestDoneTriggerScriptId),
            failedQuestDoneTriggerQueueNamespaceId(data.failedQuestDoneTriggerQueueNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            startQuestTriggerScriptId(std::move(data.startQuestTriggerScriptId)),
            startQuestDoneTriggerScriptId(std::move(data.startQuestDoneTriggerScriptId)),
            startQuestDoneTriggerQueueNamespaceId(std::move(data.startQuestDoneTriggerQueueNamespaceId)),
            completeQuestTriggerScriptId(std::move(data.completeQuestTriggerScriptId)),
            completeQuestDoneTriggerScriptId(std::move(data.completeQuestDoneTriggerScriptId)),
            completeQuestDoneTriggerQueueNamespaceId(std::move(data.completeQuestDoneTriggerQueueNamespaceId)),
            failedQuestTriggerScriptId(std::move(data.failedQuestTriggerScriptId)),
            failedQuestDoneTriggerScriptId(std::move(data.failedQuestDoneTriggerScriptId)),
            failedQuestDoneTriggerQueueNamespaceId(std::move(data.failedQuestDoneTriggerQueueNamespaceId)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "startQuestTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->startQuestTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "startQuestDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->startQuestDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "startQuestDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->startQuestDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "completeQuestTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeQuestTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "completeQuestDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeQuestDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "completeQuestDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completeQuestDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "failedQuestTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->failedQuestTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "failedQuestDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->failedQuestDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "failedQuestDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->failedQuestDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "queueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->queueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "keyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->keyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
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
     * クエストを分類するカテゴリーを取得
     *
     * @return クエストを分類するカテゴリー
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * クエストを分類するカテゴリーを設定
     *
     * @param namespaceId クエストを分類するカテゴリー
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * クエストを分類するカテゴリーを設定
     *
     * @param namespaceId クエストを分類するカテゴリー
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
     * クエスト開始時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト開始時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getStartQuestTriggerScriptId() const
    {
        return ensureData().startQuestTriggerScriptId;
    }

    /**
     * クエスト開始時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestTriggerScriptId クエスト開始時 に実行されるスクリプト のGRN
     */
    void setStartQuestTriggerScriptId(const Char* startQuestTriggerScriptId)
    {
        ensureData().startQuestTriggerScriptId.emplace(startQuestTriggerScriptId);
    }

    /**
     * クエスト開始時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestTriggerScriptId クエスト開始時 に実行されるスクリプト のGRN
     */
    Namespace& withStartQuestTriggerScriptId(const Char* startQuestTriggerScriptId)
    {
        setStartQuestTriggerScriptId(startQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト開始完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getStartQuestDoneTriggerScriptId() const
    {
        return ensureData().startQuestDoneTriggerScriptId;
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestDoneTriggerScriptId クエスト開始完了時 に実行されるスクリプト のGRN
     */
    void setStartQuestDoneTriggerScriptId(const Char* startQuestDoneTriggerScriptId)
    {
        ensureData().startQuestDoneTriggerScriptId.emplace(startQuestDoneTriggerScriptId);
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestDoneTriggerScriptId クエスト開始完了時 に実行されるスクリプト のGRN
     */
    Namespace& withStartQuestDoneTriggerScriptId(const Char* startQuestDoneTriggerScriptId)
    {
        setStartQuestDoneTriggerScriptId(startQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getStartQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().startQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param startQuestDoneTriggerQueueNamespaceId クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setStartQuestDoneTriggerQueueNamespaceId(const Char* startQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().startQuestDoneTriggerQueueNamespaceId.emplace(startQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param startQuestDoneTriggerQueueNamespaceId クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    Namespace& withStartQuestDoneTriggerQueueNamespaceId(const Char* startQuestDoneTriggerQueueNamespaceId)
    {
        setStartQuestDoneTriggerQueueNamespaceId(startQuestDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを取得
     *
     * @return クエストクリア時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteQuestTriggerScriptId() const
    {
        return ensureData().completeQuestTriggerScriptId;
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestTriggerScriptId クエストクリア時 に実行されるスクリプト のGRN
     */
    void setCompleteQuestTriggerScriptId(const Char* completeQuestTriggerScriptId)
    {
        ensureData().completeQuestTriggerScriptId.emplace(completeQuestTriggerScriptId);
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestTriggerScriptId クエストクリア時 に実行されるスクリプト のGRN
     */
    Namespace& withCompleteQuestTriggerScriptId(const Char* completeQuestTriggerScriptId)
    {
        setCompleteQuestTriggerScriptId(completeQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエストクリア完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteQuestDoneTriggerScriptId() const
    {
        return ensureData().completeQuestDoneTriggerScriptId;
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestDoneTriggerScriptId クエストクリア完了時 に実行されるスクリプト のGRN
     */
    void setCompleteQuestDoneTriggerScriptId(const Char* completeQuestDoneTriggerScriptId)
    {
        ensureData().completeQuestDoneTriggerScriptId.emplace(completeQuestDoneTriggerScriptId);
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestDoneTriggerScriptId クエストクリア完了時 に実行されるスクリプト のGRN
     */
    Namespace& withCompleteQuestDoneTriggerScriptId(const Char* completeQuestDoneTriggerScriptId)
    {
        setCompleteQuestDoneTriggerScriptId(completeQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().completeQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param completeQuestDoneTriggerQueueNamespaceId クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setCompleteQuestDoneTriggerQueueNamespaceId(const Char* completeQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().completeQuestDoneTriggerQueueNamespaceId.emplace(completeQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param completeQuestDoneTriggerQueueNamespaceId クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    Namespace& withCompleteQuestDoneTriggerQueueNamespaceId(const Char* completeQuestDoneTriggerQueueNamespaceId)
    {
        setCompleteQuestDoneTriggerQueueNamespaceId(completeQuestDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト失敗時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getFailedQuestTriggerScriptId() const
    {
        return ensureData().failedQuestTriggerScriptId;
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestTriggerScriptId クエスト失敗時 に実行されるスクリプト のGRN
     */
    void setFailedQuestTriggerScriptId(const Char* failedQuestTriggerScriptId)
    {
        ensureData().failedQuestTriggerScriptId.emplace(failedQuestTriggerScriptId);
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestTriggerScriptId クエスト失敗時 に実行されるスクリプト のGRN
     */
    Namespace& withFailedQuestTriggerScriptId(const Char* failedQuestTriggerScriptId)
    {
        setFailedQuestTriggerScriptId(failedQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getFailedQuestDoneTriggerScriptId() const
    {
        return ensureData().failedQuestDoneTriggerScriptId;
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestDoneTriggerScriptId クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    void setFailedQuestDoneTriggerScriptId(const Char* failedQuestDoneTriggerScriptId)
    {
        ensureData().failedQuestDoneTriggerScriptId.emplace(failedQuestDoneTriggerScriptId);
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestDoneTriggerScriptId クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    Namespace& withFailedQuestDoneTriggerScriptId(const Char* failedQuestDoneTriggerScriptId)
    {
        setFailedQuestDoneTriggerScriptId(failedQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getFailedQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().failedQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param failedQuestDoneTriggerQueueNamespaceId クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setFailedQuestDoneTriggerQueueNamespaceId(const Char* failedQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().failedQuestDoneTriggerQueueNamespaceId.emplace(failedQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param failedQuestDoneTriggerQueueNamespaceId クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    Namespace& withFailedQuestDoneTriggerQueueNamespaceId(const Char* failedQuestDoneTriggerQueueNamespaceId)
    {
        setFailedQuestDoneTriggerQueueNamespaceId(failedQuestDoneTriggerQueueNamespaceId);
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
    Namespace& withQueueNamespaceId(const Char* queueNamespaceId)
    {
        setQueueNamespaceId(queueNamespaceId);
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
    Namespace& withKeyId(const Char* keyId)
    {
        setKeyId(keyId);
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

bool operator!=(const Namespace& lhs, const Namespace& lhr)
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
        if (lhs.m_pData->startQuestTriggerScriptId != lhr.m_pData->startQuestTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->startQuestDoneTriggerScriptId != lhr.m_pData->startQuestDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->startQuestDoneTriggerQueueNamespaceId != lhr.m_pData->startQuestDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestTriggerScriptId != lhr.m_pData->completeQuestTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestDoneTriggerScriptId != lhr.m_pData->completeQuestDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestDoneTriggerQueueNamespaceId != lhr.m_pData->completeQuestDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->failedQuestTriggerScriptId != lhr.m_pData->failedQuestTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->failedQuestDoneTriggerScriptId != lhr.m_pData->failedQuestDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->failedQuestDoneTriggerQueueNamespaceId != lhr.m_pData->failedQuestDoneTriggerQueueNamespaceId)
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

bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_NAMESPACE_HPP_