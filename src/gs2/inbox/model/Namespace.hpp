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
        /** メッセージ受信時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveMessageTriggerScriptId;
        /** メッセージ受信完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveMessageDoneTriggerScriptId;
        /** メッセージ受信完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> receiveMessageDoneTriggerNamespaceId;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageDoneTriggerScriptId;
        /** メッセージ開封完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> readMessageDoneTriggerNamespaceId;
        /** メッセージ削除時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageTriggerScriptId;
        /** メッセージ削除完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageDoneTriggerScriptId;
        /** メッセージ削除完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> deleteMessageDoneTriggerNamespaceId;
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
            receiveMessageTriggerScriptId(data.receiveMessageTriggerScriptId),
            receiveMessageDoneTriggerScriptId(data.receiveMessageDoneTriggerScriptId),
            receiveMessageDoneTriggerNamespaceId(data.receiveMessageDoneTriggerNamespaceId),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageDoneTriggerScriptId(data.readMessageDoneTriggerScriptId),
            readMessageDoneTriggerNamespaceId(data.readMessageDoneTriggerNamespaceId),
            deleteMessageTriggerScriptId(data.deleteMessageTriggerScriptId),
            deleteMessageDoneTriggerScriptId(data.deleteMessageDoneTriggerScriptId),
            deleteMessageDoneTriggerNamespaceId(data.deleteMessageDoneTriggerNamespaceId),
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
            receiveMessageTriggerScriptId(std::move(data.receiveMessageTriggerScriptId)),
            receiveMessageDoneTriggerScriptId(std::move(data.receiveMessageDoneTriggerScriptId)),
            receiveMessageDoneTriggerNamespaceId(std::move(data.receiveMessageDoneTriggerNamespaceId)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageDoneTriggerScriptId(std::move(data.readMessageDoneTriggerScriptId)),
            readMessageDoneTriggerNamespaceId(std::move(data.readMessageDoneTriggerNamespaceId)),
            deleteMessageTriggerScriptId(std::move(data.deleteMessageTriggerScriptId)),
            deleteMessageDoneTriggerScriptId(std::move(data.deleteMessageDoneTriggerScriptId)),
            deleteMessageDoneTriggerNamespaceId(std::move(data.deleteMessageDoneTriggerNamespaceId)),
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
            else if (std::strcmp(name, "isAutomaticDeletingEnabled") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isAutomaticDeletingEnabled = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "receiveMessageTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveMessageDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveMessageDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageDoneTriggerNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageDoneTriggerNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteMessageTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteMessageDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteMessageDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageDoneTriggerNamespaceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "receiveNotification") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->receiveNotification.emplace();
                    detail::json::JsonParser::parse(&this->receiveNotification->getModel(), jsonObject);
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
     * メッセージ受信時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ受信時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveMessageTriggerScriptId() const
    {
        return ensureData().receiveMessageTriggerScriptId;
    }

    /**
     * メッセージ受信時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageTriggerScriptId メッセージ受信時 に実行されるスクリプト のGRN
     */
    void setReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
    {
        ensureData().receiveMessageTriggerScriptId.emplace(receiveMessageTriggerScriptId);
    }

    /**
     * メッセージ受信時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageTriggerScriptId メッセージ受信時 に実行されるスクリプト のGRN
     */
    Namespace& withReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
    {
        setReceiveMessageTriggerScriptId(receiveMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerScriptId() const
    {
        return ensureData().receiveMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageDoneTriggerScriptId メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    void setReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
    {
        ensureData().receiveMessageDoneTriggerScriptId.emplace(receiveMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageDoneTriggerScriptId メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    Namespace& withReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
    {
        setReceiveMessageDoneTriggerScriptId(receiveMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerNamespaceId() const
    {
        return ensureData().receiveMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveMessageDoneTriggerNamespaceId メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReceiveMessageDoneTriggerNamespaceId(const Char* receiveMessageDoneTriggerNamespaceId)
    {
        ensureData().receiveMessageDoneTriggerNamespaceId.emplace(receiveMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveMessageDoneTriggerNamespaceId メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withReceiveMessageDoneTriggerNamespaceId(const Char* receiveMessageDoneTriggerNamespaceId)
    {
        setReceiveMessageDoneTriggerNamespaceId(receiveMessageDoneTriggerNamespaceId);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageTriggerScriptId() const
    {
        return ensureData().readMessageTriggerScriptId;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    void setReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    Namespace& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        setReadMessageTriggerScriptId(readMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageDoneTriggerScriptId() const
    {
        return ensureData().readMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageDoneTriggerScriptId メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    void setReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
    {
        ensureData().readMessageDoneTriggerScriptId.emplace(readMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageDoneTriggerScriptId メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    Namespace& withReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
    {
        setReadMessageDoneTriggerScriptId(readMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReadMessageDoneTriggerNamespaceId() const
    {
        return ensureData().readMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param readMessageDoneTriggerNamespaceId メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReadMessageDoneTriggerNamespaceId(const Char* readMessageDoneTriggerNamespaceId)
    {
        ensureData().readMessageDoneTriggerNamespaceId.emplace(readMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param readMessageDoneTriggerNamespaceId メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withReadMessageDoneTriggerNamespaceId(const Char* readMessageDoneTriggerNamespaceId)
    {
        setReadMessageDoneTriggerNamespaceId(readMessageDoneTriggerNamespaceId);
        return *this;
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ削除時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDeleteMessageTriggerScriptId() const
    {
        return ensureData().deleteMessageTriggerScriptId;
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageTriggerScriptId メッセージ削除時 に実行されるスクリプト のGRN
     */
    void setDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
    {
        ensureData().deleteMessageTriggerScriptId.emplace(deleteMessageTriggerScriptId);
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageTriggerScriptId メッセージ削除時 に実行されるスクリプト のGRN
     */
    Namespace& withDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
    {
        setDeleteMessageTriggerScriptId(deleteMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerScriptId() const
    {
        return ensureData().deleteMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageDoneTriggerScriptId メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    void setDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
    {
        ensureData().deleteMessageDoneTriggerScriptId.emplace(deleteMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageDoneTriggerScriptId メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    Namespace& withDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
    {
        setDeleteMessageDoneTriggerScriptId(deleteMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerNamespaceId() const
    {
        return ensureData().deleteMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param deleteMessageDoneTriggerNamespaceId メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    void setDeleteMessageDoneTriggerNamespaceId(const Char* deleteMessageDoneTriggerNamespaceId)
    {
        ensureData().deleteMessageDoneTriggerNamespaceId.emplace(deleteMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param deleteMessageDoneTriggerNamespaceId メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withDeleteMessageDoneTriggerNamespaceId(const Char* deleteMessageDoneTriggerNamespaceId)
    {
        setDeleteMessageDoneTriggerNamespaceId(deleteMessageDoneTriggerNamespaceId);
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
        if (lhs.m_pData->receiveMessageTriggerScriptId != lhr.m_pData->receiveMessageTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveMessageDoneTriggerScriptId != lhr.m_pData->receiveMessageDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveMessageDoneTriggerNamespaceId != lhr.m_pData->receiveMessageDoneTriggerNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->readMessageTriggerScriptId != lhr.m_pData->readMessageTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->readMessageDoneTriggerScriptId != lhr.m_pData->readMessageDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->readMessageDoneTriggerNamespaceId != lhr.m_pData->readMessageDoneTriggerNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->deleteMessageTriggerScriptId != lhr.m_pData->deleteMessageTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->deleteMessageDoneTriggerScriptId != lhr.m_pData->deleteMessageDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->deleteMessageDoneTriggerNamespaceId != lhr.m_pData->deleteMessageDoneTriggerNamespaceId)
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