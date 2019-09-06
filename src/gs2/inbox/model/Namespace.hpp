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

#ifndef GS2_INBOX_MODEL_NAMESPACE_HPP_
#define GS2_INBOX_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "NotificationSetting.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * ネームスペース
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
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** プレゼントボックス名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 開封したメッセージを自動的に削除するか */
        optional<Bool> isAutomaticDeletingEnabled;
        /** メッセージ受信したときに実行するスクリプト */
        optional<ScriptSetting> receiveMessageScript;
        /** メッセージ開封したときに実行するスクリプト */
        optional<ScriptSetting> readMessageScript;
        /** メッセージ削除したときに実行するスクリプト */
        optional<ScriptSetting> deleteMessageScript;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** メッセージを受信したときのプッシュ通知 */
        optional<NotificationSetting> receiveNotification;
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
            isAutomaticDeletingEnabled(data.isAutomaticDeletingEnabled),
            receiveMessageScript(data.receiveMessageScript),
            readMessageScript(data.readMessageScript),
            deleteMessageScript(data.deleteMessageScript),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            receiveNotification(data.receiveNotification),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            isAutomaticDeletingEnabled(std::move(data.isAutomaticDeletingEnabled)),
            receiveMessageScript(std::move(data.receiveMessageScript)),
            readMessageScript(std::move(data.readMessageScript)),
            deleteMessageScript(std::move(data.deleteMessageScript)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId)),
            receiveNotification(std::move(data.receiveNotification)),
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
            else if (std::strcmp(name_, "isAutomaticDeletingEnabled") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isAutomaticDeletingEnabled = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "receiveMessageScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->receiveMessageScript.emplace();
                    detail::json::JsonParser::parse(&this->receiveMessageScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "readMessageScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->readMessageScript.emplace();
                    detail::json::JsonParser::parse(&this->readMessageScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "deleteMessageScript") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->deleteMessageScript.emplace();
                    detail::json::JsonParser::parse(&this->deleteMessageScript->getModel(), jsonObject);
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
            else if (std::strcmp(name_, "receiveNotification") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->receiveNotification.emplace();
                    detail::json::JsonParser::parse(&this->receiveNotification->getModel(), jsonObject);
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
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
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
     * プレゼントボックス名を取得
     *
     * @return プレゼントボックス名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param name プレゼントボックス名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param name プレゼントボックス名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
        return *this;
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
     * 説明文を設定
     *
     * @param description 説明文
     */
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 開封したメッセージを自動的に削除するかを取得
     *
     * @return 開封したメッセージを自動的に削除するか
     */
    const optional<Bool>& getIsAutomaticDeletingEnabled() const
    {
        return ensureData().isAutomaticDeletingEnabled;
    }

    /**
     * 開封したメッセージを自動的に削除するかを設定
     *
     * @param isAutomaticDeletingEnabled 開封したメッセージを自動的に削除するか
     */
    void setIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
    {
        ensureData().isAutomaticDeletingEnabled.emplace(isAutomaticDeletingEnabled);
    }

    /**
     * 開封したメッセージを自動的に削除するかを設定
     *
     * @param isAutomaticDeletingEnabled 開封したメッセージを自動的に削除するか
     */
    Namespace& withIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
    {
        setIsAutomaticDeletingEnabled(isAutomaticDeletingEnabled);
        return *this;
    }

    /**
     * メッセージ受信したときに実行するスクリプトを取得
     *
     * @return メッセージ受信したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReceiveMessageScript() const
    {
        return ensureData().receiveMessageScript;
    }

    /**
     * メッセージ受信したときに実行するスクリプトを設定
     *
     * @param receiveMessageScript メッセージ受信したときに実行するスクリプト
     */
    void setReceiveMessageScript(const ScriptSetting& receiveMessageScript)
    {
        ensureData().receiveMessageScript.emplace(receiveMessageScript);
    }

    /**
     * メッセージ受信したときに実行するスクリプトを設定
     *
     * @param receiveMessageScript メッセージ受信したときに実行するスクリプト
     */
    Namespace& withReceiveMessageScript(const ScriptSetting& receiveMessageScript)
    {
        setReceiveMessageScript(receiveMessageScript);
        return *this;
    }

    /**
     * メッセージ開封したときに実行するスクリプトを取得
     *
     * @return メッセージ開封したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReadMessageScript() const
    {
        return ensureData().readMessageScript;
    }

    /**
     * メッセージ開封したときに実行するスクリプトを設定
     *
     * @param readMessageScript メッセージ開封したときに実行するスクリプト
     */
    void setReadMessageScript(const ScriptSetting& readMessageScript)
    {
        ensureData().readMessageScript.emplace(readMessageScript);
    }

    /**
     * メッセージ開封したときに実行するスクリプトを設定
     *
     * @param readMessageScript メッセージ開封したときに実行するスクリプト
     */
    Namespace& withReadMessageScript(const ScriptSetting& readMessageScript)
    {
        setReadMessageScript(readMessageScript);
        return *this;
    }

    /**
     * メッセージ削除したときに実行するスクリプトを取得
     *
     * @return メッセージ削除したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDeleteMessageScript() const
    {
        return ensureData().deleteMessageScript;
    }

    /**
     * メッセージ削除したときに実行するスクリプトを設定
     *
     * @param deleteMessageScript メッセージ削除したときに実行するスクリプト
     */
    void setDeleteMessageScript(const ScriptSetting& deleteMessageScript)
    {
        ensureData().deleteMessageScript.emplace(deleteMessageScript);
    }

    /**
     * メッセージ削除したときに実行するスクリプトを設定
     *
     * @param deleteMessageScript メッセージ削除したときに実行するスクリプト
     */
    Namespace& withDeleteMessageScript(const ScriptSetting& deleteMessageScript)
    {
        setDeleteMessageScript(deleteMessageScript);
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
     * メッセージを受信したときのプッシュ通知を取得
     *
     * @return メッセージを受信したときのプッシュ通知
     */
    const optional<NotificationSetting>& getReceiveNotification() const
    {
        return ensureData().receiveNotification;
    }

    /**
     * メッセージを受信したときのプッシュ通知を設定
     *
     * @param receiveNotification メッセージを受信したときのプッシュ通知
     */
    void setReceiveNotification(const NotificationSetting& receiveNotification)
    {
        ensureData().receiveNotification.emplace(receiveNotification);
    }

    /**
     * メッセージを受信したときのプッシュ通知を設定
     *
     * @param receiveNotification メッセージを受信したときのプッシュ通知
     */
    Namespace& withReceiveNotification(const NotificationSetting& receiveNotification)
    {
        setReceiveNotification(receiveNotification);
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
        if (lhs.m_pData->isAutomaticDeletingEnabled != lhr.m_pData->isAutomaticDeletingEnabled)
        {
            return true;
        }
        if (lhs.m_pData->receiveMessageScript != lhr.m_pData->receiveMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->readMessageScript != lhr.m_pData->readMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->deleteMessageScript != lhr.m_pData->deleteMessageScript)
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
        if (lhs.m_pData->receiveNotification != lhr.m_pData->receiveNotification)
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

#endif //GS2_INBOX_MODEL_NAMESPACE_HPP_