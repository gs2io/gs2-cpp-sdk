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

#ifndef GS2_MONEY_CONTROL_WITHDRAWBYUSERIDREQUEST_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace money
{

/**
 * ユーザーIDを指定してウォレットから残高を消費します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawByUserIdRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペースの名前 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** 消費する課金通貨の数量 */
        optional<Int32> count;
        /** 有償課金通貨のみを対象とするか */
        optional<Bool> paidOnly;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            slot(data.slot),
            count(data.count),
            paidOnly(data.paidOnly),
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
    WithdrawByUserIdRequest() = default;
    WithdrawByUserIdRequest(const WithdrawByUserIdRequest& withdrawByUserIdRequest) = default;
    WithdrawByUserIdRequest(WithdrawByUserIdRequest&& withdrawByUserIdRequest) = default;
    ~WithdrawByUserIdRequest() GS2_OVERRIDE = default;

    WithdrawByUserIdRequest& operator=(const WithdrawByUserIdRequest& withdrawByUserIdRequest) = default;
    WithdrawByUserIdRequest& operator=(WithdrawByUserIdRequest&& withdrawByUserIdRequest) = default;

    WithdrawByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WithdrawByUserIdRequest);
    }

    const WithdrawByUserIdRequest* operator->() const
    {
        return this;
    }

    WithdrawByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペースの名前を取得
     *
     * @return ネームスペースの名前
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    WithdrawByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    WithdrawByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    WithdrawByUserIdRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * 消費する課金通貨の数量を取得
     *
     * @return 消費する課金通貨の数量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 消費する課金通貨の数量を設定
     *
     * @param count 消費する課金通貨の数量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 消費する課金通貨の数量を設定
     *
     * @param count 消費する課金通貨の数量
     */
    WithdrawByUserIdRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
        return *this;
    }

    /**
     * 有償課金通貨のみを対象とするかを取得
     *
     * @return 有償課金通貨のみを対象とするか
     */
    const optional<Bool>& getPaidOnly() const
    {
        return ensureData().paidOnly;
    }

    /**
     * 有償課金通貨のみを対象とするかを設定
     *
     * @param paidOnly 有償課金通貨のみを対象とするか
     */
    void setPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
    }

    /**
     * 有償課金通貨のみを対象とするかを設定
     *
     * @param paidOnly 有償課金通貨のみを対象とするか
     */
    WithdrawByUserIdRequest& withPaidOnly(Bool paidOnly)
    {
        ensureData().paidOnly.emplace(paidOnly);
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
    WithdrawByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    WithdrawByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WithdrawByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYUSERIDREQUEST_HPP_