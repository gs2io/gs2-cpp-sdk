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

#ifndef GS2_CHAT_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_CHAT_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/chat/Gs2ChatConst.hpp>
#include <gs2/chat/model/model.hpp>
#include <memory>

namespace gs2 { namespace chat
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            allowCreateRoom(data.allowCreateRoom)
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
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
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
    UpdateNamespaceRequest& withAllowCreateRoom(Bool allowCreateRoom)
    {
        ensureData().allowCreateRoom.emplace(allowCreateRoom);
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
    UpdateNamespaceRequest& withPostMessageScript(ScriptSetting postMessageScript)
    {
        ensureData().postMessageScript.emplace(std::move(postMessageScript));
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
    UpdateNamespaceRequest& withCreateRoomScript(ScriptSetting createRoomScript)
    {
        ensureData().createRoomScript.emplace(std::move(createRoomScript));
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
    UpdateNamespaceRequest& withDeleteRoomScript(ScriptSetting deleteRoomScript)
    {
        ensureData().deleteRoomScript.emplace(std::move(deleteRoomScript));
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
    UpdateNamespaceRequest& withSubscribeRoomScript(ScriptSetting subscribeRoomScript)
    {
        ensureData().subscribeRoomScript.emplace(std::move(subscribeRoomScript));
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
    UpdateNamespaceRequest& withUnsubscribeRoomScript(ScriptSetting unsubscribeRoomScript)
    {
        ensureData().unsubscribeRoomScript.emplace(std::move(unsubscribeRoomScript));
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
    UpdateNamespaceRequest& withPostNotification(NotificationSetting postNotification)
    {
        ensureData().postNotification.emplace(std::move(postNotification));
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

#endif //GS2_CHAT_CONTROL_UPDATENAMESPACEREQUEST_HPP_