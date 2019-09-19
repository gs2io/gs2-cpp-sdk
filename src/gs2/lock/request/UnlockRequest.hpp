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

#ifndef GS2_LOCK_CONTROL_UNLOCKREQUEST_HPP_
#define GS2_LOCK_CONTROL_UNLOCKREQUEST_HPP_

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
 * ミューテックスを解放 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UnlockRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** ロックを取得したトランザクションID */
        optional<StringHolder> transactionId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            propertyId(data.propertyId),
            transactionId(data.transactionId),
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
    UnlockRequest() = default;
    UnlockRequest(const UnlockRequest& unlockRequest) = default;
    UnlockRequest(UnlockRequest&& unlockRequest) = default;
    ~UnlockRequest() GS2_OVERRIDE = default;

    UnlockRequest& operator=(const UnlockRequest& unlockRequest) = default;
    UnlockRequest& operator=(UnlockRequest&& unlockRequest) = default;

    UnlockRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UnlockRequest);
    }

    const UnlockRequest* operator->() const
    {
        return this;
    }

    UnlockRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    UnlockRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    UnlockRequest& withNamespaceName(StringHolder namespaceName)
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
    UnlockRequest& withPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
        return *this;
    }

    /**
     * ロックを取得したトランザクションIDを取得
     *
     * @return ロックを取得したトランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * ロックを取得したトランザクションIDを設定
     *
     * @param transactionId ロックを取得したトランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * ロックを取得したトランザクションIDを設定
     *
     * @param transactionId ロックを取得したトランザクションID
     */
    UnlockRequest& withTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
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
    UnlockRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    UnlockRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UnlockRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOCK_CONTROL_UNLOCKREQUEST_HPP_