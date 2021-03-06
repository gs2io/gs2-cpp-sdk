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

#ifndef GS2_CHAT_MODEL_NAMESPACE_HPP_
#define GS2_CHAT_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "NotificationSetting.hpp"
#include "LogSetting.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace chat {

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
        /** ネームスペース名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ゲームプレイヤーによるルームの作成を許可するか */
        optional<Bool> allowCreateRoom;
        /** メッセージを投稿したときに実行するスクリプト */
        optional<ScriptSetting> postMessageScript;
        /** ルームを作成したときに実行するスクリプト */
        optional<ScriptSetting> createRoomScript;
        /** ルームを削除したときに実行するスクリプト */
        optional<ScriptSetting> deleteRoomScript;
        /** ルームを購読したときに実行するスクリプト */
        optional<ScriptSetting> subscribeRoomScript;
        /** ルームの購読を解除したときに実行するスクリプト */
        optional<ScriptSetting> unsubscribeRoomScript;
        /** 購読しているルームに新しい投稿がきたときのプッシュ通知 */
        optional<NotificationSetting> postNotification;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            allowCreateRoom(data.allowCreateRoom),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.postMessageScript)
            {
                postMessageScript = data.postMessageScript->deepCopy();
            }
            if (data.createRoomScript)
            {
                createRoomScript = data.createRoomScript->deepCopy();
            }
            if (data.deleteRoomScript)
            {
                deleteRoomScript = data.deleteRoomScript->deepCopy();
            }
            if (data.subscribeRoomScript)
            {
                subscribeRoomScript = data.subscribeRoomScript->deepCopy();
            }
            if (data.unsubscribeRoomScript)
            {
                unsubscribeRoomScript = data.unsubscribeRoomScript->deepCopy();
            }
            if (data.postNotification)
            {
                postNotification = data.postNotification->deepCopy();
            }
            if (data.logSetting)
            {
                logSetting = data.logSetting->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "allowCreateRoom") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->allowCreateRoom = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "postMessageScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->postMessageScript.emplace();
                    detail::json::JsonParser::parse(&this->postMessageScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createRoomScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->createRoomScript.emplace();
                    detail::json::JsonParser::parse(&this->createRoomScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "deleteRoomScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->deleteRoomScript.emplace();
                    detail::json::JsonParser::parse(&this->deleteRoomScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "subscribeRoomScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->subscribeRoomScript.emplace();
                    detail::json::JsonParser::parse(&this->subscribeRoomScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "unsubscribeRoomScript") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->unsubscribeRoomScript.emplace();
                    detail::json::JsonParser::parse(&this->unsubscribeRoomScript->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "postNotification") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->postNotification.emplace();
                    detail::json::JsonParser::parse(&this->postNotification->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "logSetting") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->logSetting.emplace();
                    detail::json::JsonParser::parse(&this->logSetting->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
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
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * ゲームプレイヤーによるルームの作成を許可するかを取得
     *
     * @return ゲームプレイヤーによるルームの作成を許可するか
     */
    const optional<Bool>& getAllowCreateRoom() const
    {
        return ensureData().allowCreateRoom;
    }

    /**
     * ゲームプレイヤーによるルームの作成を許可するかを設定
     *
     * @param allowCreateRoom ゲームプレイヤーによるルームの作成を許可するか
     */
    void setAllowCreateRoom(Bool allowCreateRoom)
    {
        ensureData().allowCreateRoom.emplace(allowCreateRoom);
    }

    /**
     * ゲームプレイヤーによるルームの作成を許可するかを設定
     *
     * @param allowCreateRoom ゲームプレイヤーによるルームの作成を許可するか
     */
    Namespace& withAllowCreateRoom(Bool allowCreateRoom)
    {
        setAllowCreateRoom(allowCreateRoom);
        return *this;
    }

    /**
     * メッセージを投稿したときに実行するスクリプトを取得
     *
     * @return メッセージを投稿したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getPostMessageScript() const
    {
        return ensureData().postMessageScript;
    }

    /**
     * メッセージを投稿したときに実行するスクリプトを設定
     *
     * @param postMessageScript メッセージを投稿したときに実行するスクリプト
     */
    void setPostMessageScript(ScriptSetting postMessageScript)
    {
        ensureData().postMessageScript.emplace(std::move(postMessageScript));
    }

    /**
     * メッセージを投稿したときに実行するスクリプトを設定
     *
     * @param postMessageScript メッセージを投稿したときに実行するスクリプト
     */
    Namespace& withPostMessageScript(ScriptSetting postMessageScript)
    {
        setPostMessageScript(std::move(postMessageScript));
        return *this;
    }

    /**
     * ルームを作成したときに実行するスクリプトを取得
     *
     * @return ルームを作成したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCreateRoomScript() const
    {
        return ensureData().createRoomScript;
    }

    /**
     * ルームを作成したときに実行するスクリプトを設定
     *
     * @param createRoomScript ルームを作成したときに実行するスクリプト
     */
    void setCreateRoomScript(ScriptSetting createRoomScript)
    {
        ensureData().createRoomScript.emplace(std::move(createRoomScript));
    }

    /**
     * ルームを作成したときに実行するスクリプトを設定
     *
     * @param createRoomScript ルームを作成したときに実行するスクリプト
     */
    Namespace& withCreateRoomScript(ScriptSetting createRoomScript)
    {
        setCreateRoomScript(std::move(createRoomScript));
        return *this;
    }

    /**
     * ルームを削除したときに実行するスクリプトを取得
     *
     * @return ルームを削除したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDeleteRoomScript() const
    {
        return ensureData().deleteRoomScript;
    }

    /**
     * ルームを削除したときに実行するスクリプトを設定
     *
     * @param deleteRoomScript ルームを削除したときに実行するスクリプト
     */
    void setDeleteRoomScript(ScriptSetting deleteRoomScript)
    {
        ensureData().deleteRoomScript.emplace(std::move(deleteRoomScript));
    }

    /**
     * ルームを削除したときに実行するスクリプトを設定
     *
     * @param deleteRoomScript ルームを削除したときに実行するスクリプト
     */
    Namespace& withDeleteRoomScript(ScriptSetting deleteRoomScript)
    {
        setDeleteRoomScript(std::move(deleteRoomScript));
        return *this;
    }

    /**
     * ルームを購読したときに実行するスクリプトを取得
     *
     * @return ルームを購読したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getSubscribeRoomScript() const
    {
        return ensureData().subscribeRoomScript;
    }

    /**
     * ルームを購読したときに実行するスクリプトを設定
     *
     * @param subscribeRoomScript ルームを購読したときに実行するスクリプト
     */
    void setSubscribeRoomScript(ScriptSetting subscribeRoomScript)
    {
        ensureData().subscribeRoomScript.emplace(std::move(subscribeRoomScript));
    }

    /**
     * ルームを購読したときに実行するスクリプトを設定
     *
     * @param subscribeRoomScript ルームを購読したときに実行するスクリプト
     */
    Namespace& withSubscribeRoomScript(ScriptSetting subscribeRoomScript)
    {
        setSubscribeRoomScript(std::move(subscribeRoomScript));
        return *this;
    }

    /**
     * ルームの購読を解除したときに実行するスクリプトを取得
     *
     * @return ルームの購読を解除したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getUnsubscribeRoomScript() const
    {
        return ensureData().unsubscribeRoomScript;
    }

    /**
     * ルームの購読を解除したときに実行するスクリプトを設定
     *
     * @param unsubscribeRoomScript ルームの購読を解除したときに実行するスクリプト
     */
    void setUnsubscribeRoomScript(ScriptSetting unsubscribeRoomScript)
    {
        ensureData().unsubscribeRoomScript.emplace(std::move(unsubscribeRoomScript));
    }

    /**
     * ルームの購読を解除したときに実行するスクリプトを設定
     *
     * @param unsubscribeRoomScript ルームの購読を解除したときに実行するスクリプト
     */
    Namespace& withUnsubscribeRoomScript(ScriptSetting unsubscribeRoomScript)
    {
        setUnsubscribeRoomScript(std::move(unsubscribeRoomScript));
        return *this;
    }

    /**
     * 購読しているルームに新しい投稿がきたときのプッシュ通知を取得
     *
     * @return 購読しているルームに新しい投稿がきたときのプッシュ通知
     */
    const optional<NotificationSetting>& getPostNotification() const
    {
        return ensureData().postNotification;
    }

    /**
     * 購読しているルームに新しい投稿がきたときのプッシュ通知を設定
     *
     * @param postNotification 購読しているルームに新しい投稿がきたときのプッシュ通知
     */
    void setPostNotification(NotificationSetting postNotification)
    {
        ensureData().postNotification.emplace(std::move(postNotification));
    }

    /**
     * 購読しているルームに新しい投稿がきたときのプッシュ通知を設定
     *
     * @param postNotification 購読しているルームに新しい投稿がきたときのプッシュ通知
     */
    Namespace& withPostNotification(NotificationSetting postNotification)
    {
        setPostNotification(std::move(postNotification));
        return *this;
    }

    /**
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    Namespace& withLogSetting(LogSetting logSetting)
    {
        setLogSetting(std::move(logSetting));
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
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->allowCreateRoom != lhr.m_pData->allowCreateRoom)
        {
            return true;
        }
        if (lhs.m_pData->postMessageScript != lhr.m_pData->postMessageScript)
        {
            return true;
        }
        if (lhs.m_pData->createRoomScript != lhr.m_pData->createRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->deleteRoomScript != lhr.m_pData->deleteRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->subscribeRoomScript != lhr.m_pData->subscribeRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->unsubscribeRoomScript != lhr.m_pData->unsubscribeRoomScript)
        {
            return true;
        }
        if (lhs.m_pData->postNotification != lhr.m_pData->postNotification)
        {
            return true;
        }
        if (lhs.m_pData->logSetting != lhr.m_pData->logSetting)
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

#endif //GS2_CHAT_MODEL_NAMESPACE_HPP_