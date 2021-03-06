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

#ifndef GS2_FRIEND_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_FRIEND_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/Gs2FriendConst.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Friend
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
        /** フォローされたときに実行するスクリプト */
        optional<ScriptSetting> followScript;
        /** アンフォローされたときに実行するスクリプト */
        optional<ScriptSetting> unfollowScript;
        /** フレンドリクエストを発行したときに実行するスクリプト */
        optional<ScriptSetting> sendRequestScript;
        /** フレンドリクエストをキャンセルしたときに実行するスクリプト */
        optional<ScriptSetting> cancelRequestScript;
        /** フレンドリクエストを承諾したときに実行するスクリプト */
        optional<ScriptSetting> acceptRequestScript;
        /** フレンドリクエストを拒否したときに実行するスクリプト */
        optional<ScriptSetting> rejectRequestScript;
        /** フレンドを削除したときに実行するスクリプト */
        optional<ScriptSetting> deleteFriendScript;
        /** プロフィールを更新したときに実行するスクリプト */
        optional<ScriptSetting> updateProfileScript;
        /** フォローされたときのプッシュ通知 */
        optional<NotificationSetting> followNotification;
        /** フレンドリクエストが届いたときのプッシュ通知 */
        optional<NotificationSetting> receiveRequestNotification;
        /** フレンドリクエストが承認されたときのプッシュ通知 */
        optional<NotificationSetting> acceptRequestNotification;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description)
        {
            if (data.followScript)
            {
                followScript = data.followScript->deepCopy();
            }
            if (data.unfollowScript)
            {
                unfollowScript = data.unfollowScript->deepCopy();
            }
            if (data.sendRequestScript)
            {
                sendRequestScript = data.sendRequestScript->deepCopy();
            }
            if (data.cancelRequestScript)
            {
                cancelRequestScript = data.cancelRequestScript->deepCopy();
            }
            if (data.acceptRequestScript)
            {
                acceptRequestScript = data.acceptRequestScript->deepCopy();
            }
            if (data.rejectRequestScript)
            {
                rejectRequestScript = data.rejectRequestScript->deepCopy();
            }
            if (data.deleteFriendScript)
            {
                deleteFriendScript = data.deleteFriendScript->deepCopy();
            }
            if (data.updateProfileScript)
            {
                updateProfileScript = data.updateProfileScript->deepCopy();
            }
            if (data.followNotification)
            {
                followNotification = data.followNotification->deepCopy();
            }
            if (data.receiveRequestNotification)
            {
                receiveRequestNotification = data.receiveRequestNotification->deepCopy();
            }
            if (data.acceptRequestNotification)
            {
                acceptRequestNotification = data.acceptRequestNotification->deepCopy();
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
     * フォローされたときに実行するスクリプトを取得
     *
     * @return フォローされたときに実行するスクリプト
     */
    const optional<ScriptSetting>& getFollowScript() const
    {
        return ensureData().followScript;
    }

    /**
     * フォローされたときに実行するスクリプトを設定
     *
     * @param followScript フォローされたときに実行するスクリプト
     */
    void setFollowScript(ScriptSetting followScript)
    {
        ensureData().followScript.emplace(std::move(followScript));
    }

    /**
     * フォローされたときに実行するスクリプトを設定
     *
     * @param followScript フォローされたときに実行するスクリプト
     */
    UpdateNamespaceRequest& withFollowScript(ScriptSetting followScript)
    {
        ensureData().followScript.emplace(std::move(followScript));
        return *this;
    }

    /**
     * アンフォローされたときに実行するスクリプトを取得
     *
     * @return アンフォローされたときに実行するスクリプト
     */
    const optional<ScriptSetting>& getUnfollowScript() const
    {
        return ensureData().unfollowScript;
    }

    /**
     * アンフォローされたときに実行するスクリプトを設定
     *
     * @param unfollowScript アンフォローされたときに実行するスクリプト
     */
    void setUnfollowScript(ScriptSetting unfollowScript)
    {
        ensureData().unfollowScript.emplace(std::move(unfollowScript));
    }

    /**
     * アンフォローされたときに実行するスクリプトを設定
     *
     * @param unfollowScript アンフォローされたときに実行するスクリプト
     */
    UpdateNamespaceRequest& withUnfollowScript(ScriptSetting unfollowScript)
    {
        ensureData().unfollowScript.emplace(std::move(unfollowScript));
        return *this;
    }

    /**
     * フレンドリクエストを発行したときに実行するスクリプトを取得
     *
     * @return フレンドリクエストを発行したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getSendRequestScript() const
    {
        return ensureData().sendRequestScript;
    }

    /**
     * フレンドリクエストを発行したときに実行するスクリプトを設定
     *
     * @param sendRequestScript フレンドリクエストを発行したときに実行するスクリプト
     */
    void setSendRequestScript(ScriptSetting sendRequestScript)
    {
        ensureData().sendRequestScript.emplace(std::move(sendRequestScript));
    }

    /**
     * フレンドリクエストを発行したときに実行するスクリプトを設定
     *
     * @param sendRequestScript フレンドリクエストを発行したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withSendRequestScript(ScriptSetting sendRequestScript)
    {
        ensureData().sendRequestScript.emplace(std::move(sendRequestScript));
        return *this;
    }

    /**
     * フレンドリクエストをキャンセルしたときに実行するスクリプトを取得
     *
     * @return フレンドリクエストをキャンセルしたときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCancelRequestScript() const
    {
        return ensureData().cancelRequestScript;
    }

    /**
     * フレンドリクエストをキャンセルしたときに実行するスクリプトを設定
     *
     * @param cancelRequestScript フレンドリクエストをキャンセルしたときに実行するスクリプト
     */
    void setCancelRequestScript(ScriptSetting cancelRequestScript)
    {
        ensureData().cancelRequestScript.emplace(std::move(cancelRequestScript));
    }

    /**
     * フレンドリクエストをキャンセルしたときに実行するスクリプトを設定
     *
     * @param cancelRequestScript フレンドリクエストをキャンセルしたときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCancelRequestScript(ScriptSetting cancelRequestScript)
    {
        ensureData().cancelRequestScript.emplace(std::move(cancelRequestScript));
        return *this;
    }

    /**
     * フレンドリクエストを承諾したときに実行するスクリプトを取得
     *
     * @return フレンドリクエストを承諾したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getAcceptRequestScript() const
    {
        return ensureData().acceptRequestScript;
    }

    /**
     * フレンドリクエストを承諾したときに実行するスクリプトを設定
     *
     * @param acceptRequestScript フレンドリクエストを承諾したときに実行するスクリプト
     */
    void setAcceptRequestScript(ScriptSetting acceptRequestScript)
    {
        ensureData().acceptRequestScript.emplace(std::move(acceptRequestScript));
    }

    /**
     * フレンドリクエストを承諾したときに実行するスクリプトを設定
     *
     * @param acceptRequestScript フレンドリクエストを承諾したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withAcceptRequestScript(ScriptSetting acceptRequestScript)
    {
        ensureData().acceptRequestScript.emplace(std::move(acceptRequestScript));
        return *this;
    }

    /**
     * フレンドリクエストを拒否したときに実行するスクリプトを取得
     *
     * @return フレンドリクエストを拒否したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getRejectRequestScript() const
    {
        return ensureData().rejectRequestScript;
    }

    /**
     * フレンドリクエストを拒否したときに実行するスクリプトを設定
     *
     * @param rejectRequestScript フレンドリクエストを拒否したときに実行するスクリプト
     */
    void setRejectRequestScript(ScriptSetting rejectRequestScript)
    {
        ensureData().rejectRequestScript.emplace(std::move(rejectRequestScript));
    }

    /**
     * フレンドリクエストを拒否したときに実行するスクリプトを設定
     *
     * @param rejectRequestScript フレンドリクエストを拒否したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withRejectRequestScript(ScriptSetting rejectRequestScript)
    {
        ensureData().rejectRequestScript.emplace(std::move(rejectRequestScript));
        return *this;
    }

    /**
     * フレンドを削除したときに実行するスクリプトを取得
     *
     * @return フレンドを削除したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDeleteFriendScript() const
    {
        return ensureData().deleteFriendScript;
    }

    /**
     * フレンドを削除したときに実行するスクリプトを設定
     *
     * @param deleteFriendScript フレンドを削除したときに実行するスクリプト
     */
    void setDeleteFriendScript(ScriptSetting deleteFriendScript)
    {
        ensureData().deleteFriendScript.emplace(std::move(deleteFriendScript));
    }

    /**
     * フレンドを削除したときに実行するスクリプトを設定
     *
     * @param deleteFriendScript フレンドを削除したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withDeleteFriendScript(ScriptSetting deleteFriendScript)
    {
        ensureData().deleteFriendScript.emplace(std::move(deleteFriendScript));
        return *this;
    }

    /**
     * プロフィールを更新したときに実行するスクリプトを取得
     *
     * @return プロフィールを更新したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getUpdateProfileScript() const
    {
        return ensureData().updateProfileScript;
    }

    /**
     * プロフィールを更新したときに実行するスクリプトを設定
     *
     * @param updateProfileScript プロフィールを更新したときに実行するスクリプト
     */
    void setUpdateProfileScript(ScriptSetting updateProfileScript)
    {
        ensureData().updateProfileScript.emplace(std::move(updateProfileScript));
    }

    /**
     * プロフィールを更新したときに実行するスクリプトを設定
     *
     * @param updateProfileScript プロフィールを更新したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withUpdateProfileScript(ScriptSetting updateProfileScript)
    {
        ensureData().updateProfileScript.emplace(std::move(updateProfileScript));
        return *this;
    }

    /**
     * フォローされたときのプッシュ通知を取得
     *
     * @return フォローされたときのプッシュ通知
     */
    const optional<NotificationSetting>& getFollowNotification() const
    {
        return ensureData().followNotification;
    }

    /**
     * フォローされたときのプッシュ通知を設定
     *
     * @param followNotification フォローされたときのプッシュ通知
     */
    void setFollowNotification(NotificationSetting followNotification)
    {
        ensureData().followNotification.emplace(std::move(followNotification));
    }

    /**
     * フォローされたときのプッシュ通知を設定
     *
     * @param followNotification フォローされたときのプッシュ通知
     */
    UpdateNamespaceRequest& withFollowNotification(NotificationSetting followNotification)
    {
        ensureData().followNotification.emplace(std::move(followNotification));
        return *this;
    }

    /**
     * フレンドリクエストが届いたときのプッシュ通知を取得
     *
     * @return フレンドリクエストが届いたときのプッシュ通知
     */
    const optional<NotificationSetting>& getReceiveRequestNotification() const
    {
        return ensureData().receiveRequestNotification;
    }

    /**
     * フレンドリクエストが届いたときのプッシュ通知を設定
     *
     * @param receiveRequestNotification フレンドリクエストが届いたときのプッシュ通知
     */
    void setReceiveRequestNotification(NotificationSetting receiveRequestNotification)
    {
        ensureData().receiveRequestNotification.emplace(std::move(receiveRequestNotification));
    }

    /**
     * フレンドリクエストが届いたときのプッシュ通知を設定
     *
     * @param receiveRequestNotification フレンドリクエストが届いたときのプッシュ通知
     */
    UpdateNamespaceRequest& withReceiveRequestNotification(NotificationSetting receiveRequestNotification)
    {
        ensureData().receiveRequestNotification.emplace(std::move(receiveRequestNotification));
        return *this;
    }

    /**
     * フレンドリクエストが承認されたときのプッシュ通知を取得
     *
     * @return フレンドリクエストが承認されたときのプッシュ通知
     */
    const optional<NotificationSetting>& getAcceptRequestNotification() const
    {
        return ensureData().acceptRequestNotification;
    }

    /**
     * フレンドリクエストが承認されたときのプッシュ通知を設定
     *
     * @param acceptRequestNotification フレンドリクエストが承認されたときのプッシュ通知
     */
    void setAcceptRequestNotification(NotificationSetting acceptRequestNotification)
    {
        ensureData().acceptRequestNotification.emplace(std::move(acceptRequestNotification));
    }

    /**
     * フレンドリクエストが承認されたときのプッシュ通知を設定
     *
     * @param acceptRequestNotification フレンドリクエストが承認されたときのプッシュ通知
     */
    UpdateNamespaceRequest& withAcceptRequestNotification(NotificationSetting acceptRequestNotification)
    {
        ensureData().acceptRequestNotification.emplace(std::move(acceptRequestNotification));
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
    UpdateNamespaceRequest& withLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
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

#endif //GS2_FRIEND_CONTROL_UPDATENAMESPACEREQUEST_HPP_