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
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
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
            startQuestScript(data.startQuestScript),
            completeQuestScript(data.completeQuestScript),
            failedQuestScript(data.failedQuestScript),
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
            startQuestScript(std::move(data.startQuestScript)),
            completeQuestScript(std::move(data.completeQuestScript)),
            failedQuestScript(std::move(data.failedQuestScript)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId)),
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
            else if (std::strcmp(name_, "startQuestScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->startQuestScript.emplace();
                    detail::json::JsonParser::parse(&this->startQuestScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "completeQuestScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->completeQuestScript.emplace();
                    detail::json::JsonParser::parse(&this->completeQuestScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "failedQuestScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->failedQuestScript.emplace();
                    detail::json::JsonParser::parse(&this->failedQuestScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "queueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->queueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "keyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->keyId.emplace(jsonValue.GetString());
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
    Namespace& withStartQuestScript(const ScriptSetting& startQuestScript)
    {
        setStartQuestScript(startQuestScript);
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
    Namespace& withCompleteQuestScript(const ScriptSetting& completeQuestScript)
    {
        setCompleteQuestScript(completeQuestScript);
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
    Namespace& withFailedQuestScript(const ScriptSetting& failedQuestScript)
    {
        setFailedQuestScript(failedQuestScript);
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
        if (lhs.m_pData->startQuestScript != lhr.m_pData->startQuestScript)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestScript != lhr.m_pData->completeQuestScript)
        {
            return true;
        }
        if (lhs.m_pData->failedQuestScript != lhr.m_pData->failedQuestScript)
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

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_NAMESPACE_HPP_