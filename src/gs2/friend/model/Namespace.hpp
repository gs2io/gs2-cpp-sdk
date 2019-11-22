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

#ifndef GS2_FRIEND_MODEL_NAMESPACE_HPP_
#define GS2_FRIEND_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include "LogSetting.hpp"
#include <memory>

namespace gs2 { namespace friend_ {

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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const;

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
    Namespace& withFollowScript(ScriptSetting followScript)
    {
        setFollowScript(std::move(followScript));
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
    Namespace& withUnfollowScript(ScriptSetting unfollowScript)
    {
        setUnfollowScript(std::move(unfollowScript));
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
    Namespace& withSendRequestScript(ScriptSetting sendRequestScript)
    {
        setSendRequestScript(std::move(sendRequestScript));
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
    Namespace& withCancelRequestScript(ScriptSetting cancelRequestScript)
    {
        setCancelRequestScript(std::move(cancelRequestScript));
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
    Namespace& withAcceptRequestScript(ScriptSetting acceptRequestScript)
    {
        setAcceptRequestScript(std::move(acceptRequestScript));
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
    Namespace& withRejectRequestScript(ScriptSetting rejectRequestScript)
    {
        setRejectRequestScript(std::move(rejectRequestScript));
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
    Namespace& withDeleteFriendScript(ScriptSetting deleteFriendScript)
    {
        setDeleteFriendScript(std::move(deleteFriendScript));
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
    Namespace& withUpdateProfileScript(ScriptSetting updateProfileScript)
    {
        setUpdateProfileScript(std::move(updateProfileScript));
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
    Namespace& withFollowNotification(NotificationSetting followNotification)
    {
        setFollowNotification(std::move(followNotification));
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
    Namespace& withReceiveRequestNotification(NotificationSetting receiveRequestNotification)
    {
        setReceiveRequestNotification(std::move(receiveRequestNotification));
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
    Namespace& withAcceptRequestNotification(NotificationSetting acceptRequestNotification)
    {
        setAcceptRequestNotification(std::move(acceptRequestNotification));
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

bool operator!=(const Namespace& lhs, const Namespace& lhr);

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_NAMESPACE_HPP_