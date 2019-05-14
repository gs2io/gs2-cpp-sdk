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

#ifndef GS2_MONEY_CONTROL_DESCRIBERECEIPTSBYUSERIDANDSLOTREQUEST_HPP_
#define GS2_MONEY_CONTROL_DESCRIBERECEIPTSBYUSERIDANDSLOTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * レシートの一覧を取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeReceiptsByUserIdAndSlotRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            userId(data.userId),
            slot(data.slot),
            begin(data.begin),
            end(data.end),
            pageToken(data.pageToken),
            limit(data.limit),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            begin(std::move(data.begin)),
            end(std::move(data.end)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit)),
            duplicationAvoider(std::move(data.duplicationAvoider))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    DescribeReceiptsByUserIdAndSlotRequest() :
        m_pData(nullptr)
    {}

    DescribeReceiptsByUserIdAndSlotRequest(const DescribeReceiptsByUserIdAndSlotRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeReceiptsByUserIdAndSlotRequest(DescribeReceiptsByUserIdAndSlotRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeReceiptsByUserIdAndSlotRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeReceiptsByUserIdAndSlotRequest& operator=(const DescribeReceiptsByUserIdAndSlotRequest& describeReceiptsByUserIdAndSlotRequest)
    {
        Gs2BasicRequest::operator=(describeReceiptsByUserIdAndSlotRequest);
        Gs2Money::operator=(describeReceiptsByUserIdAndSlotRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeReceiptsByUserIdAndSlotRequest.m_pData);

        return *this;
    }

    DescribeReceiptsByUserIdAndSlotRequest& operator=(DescribeReceiptsByUserIdAndSlotRequest&& describeReceiptsByUserIdAndSlotRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeReceiptsByUserIdAndSlotRequest));
        Gs2Money::operator=(std::move(describeReceiptsByUserIdAndSlotRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeReceiptsByUserIdAndSlotRequest.m_pData;
        describeReceiptsByUserIdAndSlotRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeReceiptsByUserIdAndSlotRequest* operator->() const
    {
        return this;
    }

    DescribeReceiptsByUserIdAndSlotRequest* operator->()
    {
        return this;
    }
    /**
     * 課金通貨の名前を取得
     *
     * @return 課金通貨の名前
     */
    const optional<StringHolder>& getMoneyName() const
    {
        return ensureData().moneyName;
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    void setMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    DescribeReceiptsByUserIdAndSlotRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DescribeReceiptsByUserIdAndSlotRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    DescribeReceiptsByUserIdAndSlotRequest& withSlot(Int32 slot)
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
    DescribeReceiptsByUserIdAndSlotRequest& withBegin(Int64 begin)
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
    DescribeReceiptsByUserIdAndSlotRequest& withEnd(Int64 end)
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
    void setPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    DescribeReceiptsByUserIdAndSlotRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
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
    DescribeReceiptsByUserIdAndSlotRequest& withLimit(Int64 limit)
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    DescribeReceiptsByUserIdAndSlotRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeReceiptsByUserIdAndSlotRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    DescribeReceiptsByUserIdAndSlotRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    DescribeReceiptsByUserIdAndSlotRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeReceiptsByUserIdAndSlotRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_MONEY_CONTROL_DESCRIBERECEIPTSBYUSERIDANDSLOTREQUEST_HPP_