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

#ifndef GS2_LOCK_CONTROL_LOCKBYUSERIDREQUEST_HPP_
#define GS2_LOCK_CONTROL_LOCKBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LockConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace lock
{

/**
 * ユーザIDを指定してミューテックスを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class LockByUserIdRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ロックを取得するトランザクションID */
        optional<StringHolder> transactionId;
        /** ロックを取得する期限（秒） */
        optional<Int64> ttl;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            propertyId(data.propertyId),
            userId(data.userId),
            transactionId(data.transactionId),
            ttl(data.ttl),
            duplicationAvoider(data.duplicationAvoider)
        {
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
    LockByUserIdRequest() = default;
    LockByUserIdRequest(const LockByUserIdRequest& lockByUserIdRequest) = default;
    LockByUserIdRequest(LockByUserIdRequest&& lockByUserIdRequest) = default;
    ~LockByUserIdRequest() GS2_OVERRIDE = default;

    LockByUserIdRequest& operator=(const LockByUserIdRequest& lockByUserIdRequest) = default;
    LockByUserIdRequest& operator=(LockByUserIdRequest&& lockByUserIdRequest) = default;

    LockByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LockByUserIdRequest);
    }

    const LockByUserIdRequest* operator->() const
    {
        return this;
    }

    LockByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    LockByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    LockByUserIdRequest& withPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
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
    LockByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * ロックを取得するトランザクションIDを取得
     *
     * @return ロックを取得するトランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * ロックを取得するトランザクションIDを設定
     *
     * @param transactionId ロックを取得するトランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * ロックを取得するトランザクションIDを設定
     *
     * @param transactionId ロックを取得するトランザクションID
     */
    LockByUserIdRequest& withTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
        return *this;
    }

    /**
     * ロックを取得する期限（秒）を取得
     *
     * @return ロックを取得する期限（秒）
     */
    const optional<Int64>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * ロックを取得する期限（秒）を設定
     *
     * @param ttl ロックを取得する期限（秒）
     */
    void setTtl(Int64 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * ロックを取得する期限（秒）を設定
     *
     * @param ttl ロックを取得する期限（秒）
     */
    LockByUserIdRequest& withTtl(Int64 ttl)
    {
        ensureData().ttl.emplace(ttl);
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
    LockByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    LockByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LockByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOCK_CONTROL_LOCKBYUSERIDREQUEST_HPP_