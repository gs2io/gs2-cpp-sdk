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

#ifndef GS2_MONEY_CONTROL_DEPOSITWITHRECEIPTBYSTAMPSHEETREQUEST_HPP_
#define GS2_MONEY_CONTROL_DEPOSITWITHRECEIPTBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * スタンプシートを使用してウォレットの概要に残高を加算します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DepositWithReceiptByStampSheetRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名検証に使用する 暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** レシート */
        optional<StringHolder> receipt;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet),
            keyId(data.keyId),
            receipt(data.receipt),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stampSheet(std::move(data.stampSheet)),
            keyId(std::move(data.keyId)),
            receipt(std::move(data.receipt)),
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
    DepositWithReceiptByStampSheetRequest() :
        m_pData(nullptr)
    {}

    DepositWithReceiptByStampSheetRequest(const DepositWithReceiptByStampSheetRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DepositWithReceiptByStampSheetRequest(DepositWithReceiptByStampSheetRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DepositWithReceiptByStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DepositWithReceiptByStampSheetRequest& operator=(const DepositWithReceiptByStampSheetRequest& depositWithReceiptByStampSheetRequest)
    {
        Gs2BasicRequest::operator=(depositWithReceiptByStampSheetRequest);
        Gs2Money::operator=(depositWithReceiptByStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*depositWithReceiptByStampSheetRequest.m_pData);

        return *this;
    }

    DepositWithReceiptByStampSheetRequest& operator=(DepositWithReceiptByStampSheetRequest&& depositWithReceiptByStampSheetRequest)
    {
        Gs2BasicRequest::operator=(std::move(depositWithReceiptByStampSheetRequest));
        Gs2Money::operator=(std::move(depositWithReceiptByStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = depositWithReceiptByStampSheetRequest.m_pData;
        depositWithReceiptByStampSheetRequest.m_pData = nullptr;

        return *this;
    }

    const DepositWithReceiptByStampSheetRequest* operator->() const
    {
        return this;
    }

    DepositWithReceiptByStampSheetRequest* operator->()
    {
        return this;
    }
    /**
     * スタンプシートを取得
     *
     * @return スタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    DepositWithReceiptByStampSheetRequest& withStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
        return *this;
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを取得
     *
     * @return スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    DepositWithReceiptByStampSheetRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
        return *this;
    }

    /**
     * レシートを取得
     *
     * @return レシート
     */
    const optional<StringHolder>& getReceipt() const
    {
        return ensureData().receipt;
    }

    /**
     * レシートを設定
     *
     * @param receipt レシート
     */
    void setReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
    }

    /**
     * レシートを設定
     *
     * @param receipt レシート
     */
    DepositWithReceiptByStampSheetRequest& withReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
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
    DepositWithReceiptByStampSheetRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    DepositWithReceiptByStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DepositWithReceiptByStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DepositWithReceiptByStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DepositWithReceiptByStampSheetRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MONEY_CONTROL_DEPOSITWITHRECEIPTBYSTAMPSHEETREQUEST_HPP_