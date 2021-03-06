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

#ifndef GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_
#define GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inbox/Gs2InboxConst.hpp>
#include <gs2/inbox/model/model.hpp>
#include <memory>

namespace gs2 { namespace inbox
{

/**
 * メッセージを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendMessageByUserIdRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** メッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** 開封時に実行する入手アクション */
        optional<List<AcquireAction>> readAcquireActions;
        /** メッセージの有効期限 */
        optional<Int64> expiresAt;
        /** メッセージの有効期限までの差分 */
        optional<TimeSpan> expiresTimeSpan;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            metadata(data.metadata),
            expiresAt(data.expiresAt),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.readAcquireActions)
            {
                readAcquireActions = data.readAcquireActions->deepCopy();
            }
            if (data.expiresTimeSpan)
            {
                expiresTimeSpan = data.expiresTimeSpan->deepCopy();
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
    SendMessageByUserIdRequest() = default;
    SendMessageByUserIdRequest(const SendMessageByUserIdRequest& sendMessageByUserIdRequest) = default;
    SendMessageByUserIdRequest(SendMessageByUserIdRequest&& sendMessageByUserIdRequest) = default;
    ~SendMessageByUserIdRequest() GS2_OVERRIDE = default;

    SendMessageByUserIdRequest& operator=(const SendMessageByUserIdRequest& sendMessageByUserIdRequest) = default;
    SendMessageByUserIdRequest& operator=(SendMessageByUserIdRequest&& sendMessageByUserIdRequest) = default;

    SendMessageByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SendMessageByUserIdRequest);
    }

    const SendMessageByUserIdRequest* operator->() const
    {
        return this;
    }

    SendMessageByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * プレゼントボックス名を取得
     *
     * @return プレゼントボックス名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    SendMessageByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    SendMessageByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * メッセージの内容に相当するメタデータを取得
     *
     * @return メッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    SendMessageByUserIdRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 開封時に実行する入手アクションを取得
     *
     * @return 開封時に実行する入手アクション
     */
    const optional<List<AcquireAction>>& getReadAcquireActions() const
    {
        return ensureData().readAcquireActions;
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    void setReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    SendMessageByUserIdRequest& withReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
        return *this;
    }

    /**
     * メッセージの有効期限を取得
     *
     * @return メッセージの有効期限
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * メッセージの有効期限を設定
     *
     * @param expiresAt メッセージの有効期限
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }

    /**
     * メッセージの有効期限を設定
     *
     * @param expiresAt メッセージの有効期限
     */
    SendMessageByUserIdRequest& withExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
        return *this;
    }

    /**
     * メッセージの有効期限までの差分を取得
     *
     * @return メッセージの有効期限までの差分
     */
    const optional<TimeSpan>& getExpiresTimeSpan() const
    {
        return ensureData().expiresTimeSpan;
    }

    /**
     * メッセージの有効期限までの差分を設定
     *
     * @param expiresTimeSpan メッセージの有効期限までの差分
     */
    void setExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        ensureData().expiresTimeSpan.emplace(std::move(expiresTimeSpan));
    }

    /**
     * メッセージの有効期限までの差分を設定
     *
     * @param expiresTimeSpan メッセージの有効期限までの差分
     */
    SendMessageByUserIdRequest& withExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        ensureData().expiresTimeSpan.emplace(std::move(expiresTimeSpan));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    SendMessageByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SendMessageByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMessageByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_