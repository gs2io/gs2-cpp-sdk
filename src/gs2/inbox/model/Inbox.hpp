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

#ifndef GS2_INBOX_MODEL_INBOX_HPP_
#define GS2_INBOX_MODEL_INBOX_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * プレゼントボックス
 *
 * @author Game Server Services, Inc.
 *
 */
class Inbox : public Gs2Object
{
    friend bool operator!=(const Inbox& lhs, const Inbox& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** プレゼントボックス のGRN */
        optional<StringHolder> inboxId;
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
        /** メッセージ受信完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> receiveMessageDoneTriggerQueueId;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageDoneTriggerScriptId;
        /** メッセージ開封完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> readMessageDoneTriggerQueueId;
        /** メッセージ削除時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageTriggerScriptId;
        /** メッセージ削除完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageDoneTriggerScriptId;
        /** メッセージ削除完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> deleteMessageDoneTriggerQueueId;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inboxId(data.inboxId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            isAutomaticDeletingEnabled(data.isAutomaticDeletingEnabled),
            receiveMessageTriggerScriptId(data.receiveMessageTriggerScriptId),
            receiveMessageDoneTriggerScriptId(data.receiveMessageDoneTriggerScriptId),
            receiveMessageDoneTriggerQueueId(data.receiveMessageDoneTriggerQueueId),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageDoneTriggerScriptId(data.readMessageDoneTriggerScriptId),
            readMessageDoneTriggerQueueId(data.readMessageDoneTriggerQueueId),
            deleteMessageTriggerScriptId(data.deleteMessageTriggerScriptId),
            deleteMessageDoneTriggerScriptId(data.deleteMessageDoneTriggerScriptId),
            deleteMessageDoneTriggerQueueId(data.deleteMessageDoneTriggerQueueId),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inboxId(std::move(data.inboxId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            isAutomaticDeletingEnabled(std::move(data.isAutomaticDeletingEnabled)),
            receiveMessageTriggerScriptId(std::move(data.receiveMessageTriggerScriptId)),
            receiveMessageDoneTriggerScriptId(std::move(data.receiveMessageDoneTriggerScriptId)),
            receiveMessageDoneTriggerQueueId(std::move(data.receiveMessageDoneTriggerQueueId)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageDoneTriggerScriptId(std::move(data.readMessageDoneTriggerScriptId)),
            readMessageDoneTriggerQueueId(std::move(data.readMessageDoneTriggerQueueId)),
            deleteMessageTriggerScriptId(std::move(data.deleteMessageTriggerScriptId)),
            deleteMessageDoneTriggerScriptId(std::move(data.deleteMessageDoneTriggerScriptId)),
            deleteMessageDoneTriggerQueueId(std::move(data.deleteMessageDoneTriggerQueueId)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "inboxId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "receiveMessageDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageDoneTriggerQueueId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "readMessageDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageDoneTriggerQueueId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "deleteMessageDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
    Inbox() :
        m_pData(nullptr)
    {}

    Inbox(const Inbox& inbox) :
        Gs2Object(inbox),
        m_pData(inbox.m_pData != nullptr ? new Data(*inbox.m_pData) : nullptr)
    {}

    Inbox(Inbox&& inbox) :
        Gs2Object(std::move(inbox)),
        m_pData(inbox.m_pData)
    {
        inbox.m_pData = nullptr;
    }

    ~Inbox()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Inbox& operator=(const Inbox& inbox)
    {
        Gs2Object::operator=(inbox);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*inbox.m_pData);

        return *this;
    }

    Inbox& operator=(Inbox&& inbox)
    {
        Gs2Object::operator=(std::move(inbox));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = inbox.m_pData;
        inbox.m_pData = nullptr;

        return *this;
    }

    const Inbox* operator->() const
    {
        return this;
    }

    Inbox* operator->()
    {
        return this;
    }
    /**
     * プレゼントボックス のGRNを取得
     *
     * @return プレゼントボックス のGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * プレゼントボックス のGRNを設定
     *
     * @param inboxId プレゼントボックス のGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
    }

    /**
     * プレゼントボックス のGRNを設定
     *
     * @param inboxId プレゼントボックス のGRN
     */
    Inbox& withInboxId(const Char* inboxId)
    {
        setInboxId(inboxId);
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
    Inbox& withOwnerId(const Char* ownerId)
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
    Inbox& withName(const Char* name)
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
    Inbox& withDescription(const Char* description)
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
    Inbox& withIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
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
    Inbox& withReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
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
    Inbox& withReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
    {
        setReceiveMessageDoneTriggerScriptId(receiveMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return メッセージ受信完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerQueueId() const
    {
        return ensureData().receiveMessageDoneTriggerQueueId;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param receiveMessageDoneTriggerQueueId メッセージ受信完了時 にジョブが登録されるキュー のGRN
     */
    void setReceiveMessageDoneTriggerQueueId(const Char* receiveMessageDoneTriggerQueueId)
    {
        ensureData().receiveMessageDoneTriggerQueueId.emplace(receiveMessageDoneTriggerQueueId);
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param receiveMessageDoneTriggerQueueId メッセージ受信完了時 にジョブが登録されるキュー のGRN
     */
    Inbox& withReceiveMessageDoneTriggerQueueId(const Char* receiveMessageDoneTriggerQueueId)
    {
        setReceiveMessageDoneTriggerQueueId(receiveMessageDoneTriggerQueueId);
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
    Inbox& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
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
    Inbox& withReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
    {
        setReadMessageDoneTriggerScriptId(readMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return メッセージ開封完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getReadMessageDoneTriggerQueueId() const
    {
        return ensureData().readMessageDoneTriggerQueueId;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param readMessageDoneTriggerQueueId メッセージ開封完了時 にジョブが登録されるキュー のGRN
     */
    void setReadMessageDoneTriggerQueueId(const Char* readMessageDoneTriggerQueueId)
    {
        ensureData().readMessageDoneTriggerQueueId.emplace(readMessageDoneTriggerQueueId);
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param readMessageDoneTriggerQueueId メッセージ開封完了時 にジョブが登録されるキュー のGRN
     */
    Inbox& withReadMessageDoneTriggerQueueId(const Char* readMessageDoneTriggerQueueId)
    {
        setReadMessageDoneTriggerQueueId(readMessageDoneTriggerQueueId);
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
    Inbox& withDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
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
    Inbox& withDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
    {
        setDeleteMessageDoneTriggerScriptId(deleteMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return メッセージ削除完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerQueueId() const
    {
        return ensureData().deleteMessageDoneTriggerQueueId;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param deleteMessageDoneTriggerQueueId メッセージ削除完了時 にジョブが登録されるキュー のGRN
     */
    void setDeleteMessageDoneTriggerQueueId(const Char* deleteMessageDoneTriggerQueueId)
    {
        ensureData().deleteMessageDoneTriggerQueueId.emplace(deleteMessageDoneTriggerQueueId);
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param deleteMessageDoneTriggerQueueId メッセージ削除完了時 にジョブが登録されるキュー のGRN
     */
    Inbox& withDeleteMessageDoneTriggerQueueId(const Char* deleteMessageDoneTriggerQueueId)
    {
        setDeleteMessageDoneTriggerQueueId(deleteMessageDoneTriggerQueueId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Inbox& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    Inbox& withUpdateAt(Int64 updateAt)
    {
        setUpdateAt(updateAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Inbox& lhs, const Inbox& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->inboxId != lhr.m_pData->inboxId)
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
        if (lhs.m_pData->receiveMessageDoneTriggerQueueId != lhr.m_pData->receiveMessageDoneTriggerQueueId)
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
        if (lhs.m_pData->readMessageDoneTriggerQueueId != lhr.m_pData->readMessageDoneTriggerQueueId)
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
        if (lhs.m_pData->deleteMessageDoneTriggerQueueId != lhr.m_pData->deleteMessageDoneTriggerQueueId)
        {
            return true;
        }
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->updateAt != lhr.m_pData->updateAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Inbox& lhs, const Inbox& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_INBOX_HPP_