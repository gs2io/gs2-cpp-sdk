/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MONEY_CONTROL_DESCRIBERECEIPTBYUSERIDANDSLOTREQUEST_HPP_
#define GS2_MONEY_CONTROL_DESCRIBERECEIPTBYUSERIDANDSLOTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeReceiptByUserIdAndSlotRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "DescribeReceiptByUserIdAndSlot";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** データの取得開始日時(エポック秒) */
        optional<Int32> begin;
        /** データの取得終了日時(エポック秒) */
        optional<Int32> end;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int32> limit;

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
            limit(data.limit)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            begin(std::move(data.begin)),
            end(std::move(data.end)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit))
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
    DescribeReceiptByUserIdAndSlotRequest() :
        m_pData(nullptr)
    {}

    DescribeReceiptByUserIdAndSlotRequest(const DescribeReceiptByUserIdAndSlotRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeReceiptByUserIdAndSlotRequest(DescribeReceiptByUserIdAndSlotRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeReceiptByUserIdAndSlotRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeReceiptByUserIdAndSlotRequest& operator=(const DescribeReceiptByUserIdAndSlotRequest& describeReceiptByUserIdAndSlotRequest)
    {
        Gs2BasicRequest::operator=(describeReceiptByUserIdAndSlotRequest);
        Gs2Money::operator=(describeReceiptByUserIdAndSlotRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeReceiptByUserIdAndSlotRequest.m_pData);

        return *this;
    }

    DescribeReceiptByUserIdAndSlotRequest& operator=(DescribeReceiptByUserIdAndSlotRequest&& describeReceiptByUserIdAndSlotRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeReceiptByUserIdAndSlotRequest));
        Gs2Money::operator=(std::move(describeReceiptByUserIdAndSlotRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeReceiptByUserIdAndSlotRequest.m_pData;
        describeReceiptByUserIdAndSlotRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeReceiptByUserIdAndSlotRequest* operator->() const
    {
        return this;
    }

    DescribeReceiptByUserIdAndSlotRequest* operator->()
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
    DescribeReceiptByUserIdAndSlotRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    DescribeReceiptByUserIdAndSlotRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    DescribeReceiptByUserIdAndSlotRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * データの取得開始日時(エポック秒)を取得
     *
     * @return データの取得開始日時(エポック秒)
     */
    const optional<Int32>& getBegin() const
    {
        return ensureData().begin;
    }

    /**
     * データの取得開始日時(エポック秒)を設定
     *
     * @param begin データの取得開始日時(エポック秒)
     */
    void setBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
    }

    /**
     * データの取得開始日時(エポック秒)を設定
     *
     * @param begin データの取得開始日時(エポック秒)
     */
    DescribeReceiptByUserIdAndSlotRequest& withBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
        return *this;
    }

    /**
     * データの取得終了日時(エポック秒)を取得
     *
     * @return データの取得終了日時(エポック秒)
     */
    const optional<Int32>& getEnd() const
    {
        return ensureData().end;
    }

    /**
     * データの取得終了日時(エポック秒)を設定
     *
     * @param end データの取得終了日時(エポック秒)
     */
    void setEnd(Int32 end)
    {
        ensureData().end.emplace(end);
    }

    /**
     * データの取得終了日時(エポック秒)を設定
     *
     * @param end データの取得終了日時(エポック秒)
     */
    DescribeReceiptByUserIdAndSlotRequest& withEnd(Int32 end)
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
    DescribeReceiptByUserIdAndSlotRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeReceiptByUserIdAndSlotRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeReceiptByUserIdAndSlotRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeReceiptByUserIdAndSlotRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeReceiptByUserIdAndSlotRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeReceiptByUserIdAndSlotRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_DESCRIBERECEIPTBYUSERIDANDSLOTREQUEST_HPP_