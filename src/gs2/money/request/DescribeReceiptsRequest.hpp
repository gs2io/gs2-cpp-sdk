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

#ifndef GS2_MONEY_CONTROL_DESCRIBERECEIPTSREQUEST_HPP_
#define GS2_MONEY_CONTROL_DESCRIBERECEIPTSREQUEST_HPP_

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
 * レシートの一覧を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeReceiptsRequest : public Gs2BasicRequest, public Gs2Money
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
        /** None */
        optional<Int32> slot;
        /** None */
        optional<Int64> begin;
        /** None */
        optional<Int64> end;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int64> limit;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            slot(data.slot),
            begin(data.begin),
            end(data.end),
            pageToken(data.pageToken),
            limit(data.limit),
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
    DescribeReceiptsRequest() = default;
    DescribeReceiptsRequest(const DescribeReceiptsRequest& describeReceiptsRequest) = default;
    DescribeReceiptsRequest(DescribeReceiptsRequest&& describeReceiptsRequest) = default;
    ~DescribeReceiptsRequest() GS2_OVERRIDE = default;

    DescribeReceiptsRequest& operator=(const DescribeReceiptsRequest& describeReceiptsRequest) = default;
    DescribeReceiptsRequest& operator=(DescribeReceiptsRequest&& describeReceiptsRequest) = default;

    DescribeReceiptsRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeReceiptsRequest);
    }

    const DescribeReceiptsRequest* operator->() const
    {
        return this;
    }

    DescribeReceiptsRequest* operator->()
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
    DescribeReceiptsRequest& withNamespaceName(StringHolder namespaceName)
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
    DescribeReceiptsRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    DescribeReceiptsRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int64>& getBegin() const
    {
        return ensureData().begin;
    }

    /**
     * Noneを設定
     *
     * @param begin None
     */
    void setBegin(Int64 begin)
    {
        ensureData().begin.emplace(begin);
    }

    /**
     * Noneを設定
     *
     * @param begin None
     */
    DescribeReceiptsRequest& withBegin(Int64 begin)
    {
        ensureData().begin.emplace(begin);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int64>& getEnd() const
    {
        return ensureData().end;
    }

    /**
     * Noneを設定
     *
     * @param end None
     */
    void setEnd(Int64 end)
    {
        ensureData().end.emplace(end);
    }

    /**
     * Noneを設定
     *
     * @param end None
     */
    DescribeReceiptsRequest& withEnd(Int64 end)
    {
        ensureData().end.emplace(end);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(StringHolder pageToken)
    {
        ensureData().pageToken.emplace(std::move(pageToken));
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    DescribeReceiptsRequest& withPageToken(StringHolder pageToken)
    {
        ensureData().pageToken.emplace(std::move(pageToken));
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int64>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int64 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeReceiptsRequest& withLimit(Int64 limit)
    {
        ensureData().limit.emplace(limit);
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
    DescribeReceiptsRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    DescribeReceiptsRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeReceiptsRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_DESCRIBERECEIPTSREQUEST_HPP_