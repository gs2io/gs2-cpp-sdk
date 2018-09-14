/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
 * 受信ボックス
 *
 * @author Game Server Services, Inc.
 *
 */
class Inbox : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 受信ボックスGRN */
        optional<StringHolder> inboxId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 受信ボックス名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** 開封時自動削除 */
        optional<Bool> autoDelete;
        /** メッセージの開封通知先URL */
        optional<StringHolder> cooperationUrl;
        /** メッセージ受信時 に実行されるGS2-Script */
        optional<StringHolder> receiveMessageTriggerScript;
        /** メッセージ受信完了時 に実行されるGS2-Script */
        optional<StringHolder> receiveMessageDoneTriggerScript;
        /** メッセージ開封時 に実行されるGS2-Script */
        optional<StringHolder> readMessageTriggerScript;
        /** メッセージ開封完了時 に実行されるGS2-Script */
        optional<StringHolder> readMessageDoneTriggerScript;
        /** メッセージ削除時 に実行されるGS2-Script */
        optional<StringHolder> deleteMessageTriggerScript;
        /** メッセージ削除完了時 に実行されるGS2-Script */
        optional<StringHolder> deleteMessageDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            inboxId(data.inboxId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            autoDelete(data.autoDelete),
            cooperationUrl(data.cooperationUrl),
            receiveMessageTriggerScript(data.receiveMessageTriggerScript),
            receiveMessageDoneTriggerScript(data.receiveMessageDoneTriggerScript),
            readMessageTriggerScript(data.readMessageTriggerScript),
            readMessageDoneTriggerScript(data.readMessageDoneTriggerScript),
            deleteMessageTriggerScript(data.deleteMessageTriggerScript),
            deleteMessageDoneTriggerScript(data.deleteMessageDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            inboxId(std::move(data.inboxId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            autoDelete(std::move(data.autoDelete)),
            cooperationUrl(std::move(data.cooperationUrl)),
            receiveMessageTriggerScript(std::move(data.receiveMessageTriggerScript)),
            receiveMessageDoneTriggerScript(std::move(data.receiveMessageDoneTriggerScript)),
            readMessageTriggerScript(std::move(data.readMessageTriggerScript)),
            readMessageDoneTriggerScript(std::move(data.readMessageDoneTriggerScript)),
            deleteMessageTriggerScript(std::move(data.deleteMessageTriggerScript)),
            deleteMessageDoneTriggerScript(std::move(data.deleteMessageDoneTriggerScript)),
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
            else if (std::strcmp(name, "serviceClass") == 0) {
                if (jsonValue.IsString())
                {
                    this->serviceClass.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "autoDelete") == 0) {
                if (jsonValue.IsBool())
                {
                    this->autoDelete = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "cooperationUrl") == 0) {
                if (jsonValue.IsString())
                {
                    this->cooperationUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveMessageTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveMessageDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveMessageDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteMessageTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "deleteMessageDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->deleteMessageDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
     * 受信ボックスGRNを取得
     *
     * @return 受信ボックスGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * 受信ボックスGRNを設定
     *
     * @param inboxId 受信ボックスGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
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
     * 受信ボックス名を取得
     *
     * @return 受信ボックス名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 受信ボックス名を設定
     *
     * @param name 受信ボックス名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
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
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * 開封時自動削除を取得
     *
     * @return 開封時自動削除
     */
    const optional<Bool>& getAutoDelete() const
    {
        return ensureData().autoDelete;
    }

    /**
     * 開封時自動削除を設定
     *
     * @param autoDelete 開封時自動削除
     */
    void setAutoDelete(Bool autoDelete)
    {
        ensureData().autoDelete.emplace(autoDelete);
    }

    /**
     * メッセージの開封通知先URLを取得
     *
     * @return メッセージの開封通知先URL
     */
    const optional<StringHolder>& getCooperationUrl() const
    {
        return ensureData().cooperationUrl;
    }

    /**
     * メッセージの開封通知先URLを設定
     *
     * @param cooperationUrl メッセージの開封通知先URL
     */
    void setCooperationUrl(const Char* cooperationUrl)
    {
        ensureData().cooperationUrl.emplace(cooperationUrl);
    }

    /**
     * メッセージ受信時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ受信時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReceiveMessageTriggerScript() const
    {
        return ensureData().receiveMessageTriggerScript;
    }

    /**
     * メッセージ受信時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageTriggerScript メッセージ受信時 に実行されるGS2-Script
     */
    void setReceiveMessageTriggerScript(const Char* receiveMessageTriggerScript)
    {
        ensureData().receiveMessageTriggerScript.emplace(receiveMessageTriggerScript);
    }

    /**
     * メッセージ受信完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ受信完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerScript() const
    {
        return ensureData().receiveMessageDoneTriggerScript;
    }

    /**
     * メッセージ受信完了時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageDoneTriggerScript メッセージ受信完了時 に実行されるGS2-Script
     */
    void setReceiveMessageDoneTriggerScript(const Char* receiveMessageDoneTriggerScript)
    {
        ensureData().receiveMessageDoneTriggerScript.emplace(receiveMessageDoneTriggerScript);
    }

    /**
     * メッセージ開封時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ開封時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReadMessageTriggerScript() const
    {
        return ensureData().readMessageTriggerScript;
    }

    /**
     * メッセージ開封時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageTriggerScript メッセージ開封時 に実行されるGS2-Script
     */
    void setReadMessageTriggerScript(const Char* readMessageTriggerScript)
    {
        ensureData().readMessageTriggerScript.emplace(readMessageTriggerScript);
    }

    /**
     * メッセージ開封完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ開封完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReadMessageDoneTriggerScript() const
    {
        return ensureData().readMessageDoneTriggerScript;
    }

    /**
     * メッセージ開封完了時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageDoneTriggerScript メッセージ開封完了時 に実行されるGS2-Script
     */
    void setReadMessageDoneTriggerScript(const Char* readMessageDoneTriggerScript)
    {
        ensureData().readMessageDoneTriggerScript.emplace(readMessageDoneTriggerScript);
    }

    /**
     * メッセージ削除時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ削除時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteMessageTriggerScript() const
    {
        return ensureData().deleteMessageTriggerScript;
    }

    /**
     * メッセージ削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageTriggerScript メッセージ削除時 に実行されるGS2-Script
     */
    void setDeleteMessageTriggerScript(const Char* deleteMessageTriggerScript)
    {
        ensureData().deleteMessageTriggerScript.emplace(deleteMessageTriggerScript);
    }

    /**
     * メッセージ削除完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ削除完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerScript() const
    {
        return ensureData().deleteMessageDoneTriggerScript;
    }

    /**
     * メッセージ削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageDoneTriggerScript メッセージ削除完了時 に実行されるGS2-Script
     */
    void setDeleteMessageDoneTriggerScript(const Char* deleteMessageDoneTriggerScript)
    {
        ensureData().deleteMessageDoneTriggerScript.emplace(deleteMessageDoneTriggerScript);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_MODEL_INBOX_HPP_