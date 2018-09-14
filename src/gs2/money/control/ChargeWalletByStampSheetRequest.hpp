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

#ifndef GS2_MONEY_CONTROL_CHARGEWALLETBYSTAMPSHEETREQUEST_HPP_
#define GS2_MONEY_CONTROL_CHARGEWALLETBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"

namespace gs2 { namespace money {

/**
 * @author Game Server Services, Inc.
 */
class ChargeWalletByStampSheetRequest : public Gs2UserRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "ChargeWalletByStampSheet";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得するウォレットのスロット番号 */
        optional<Int32> slot;
        /** スタンプシート */
        optional<StringHolder> sheet;
        /** スタンプの暗号鍵 */
        optional<StringHolder> keyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            slot(data.slot),
            sheet(data.sheet),
            keyName(data.keyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            slot(std::move(data.slot)),
            sheet(std::move(data.sheet)),
            keyName(std::move(data.keyName))
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
    ChargeWalletByStampSheetRequest() :
        m_pData(nullptr)
    {}

    ChargeWalletByStampSheetRequest(const ChargeWalletByStampSheetRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChargeWalletByStampSheetRequest(ChargeWalletByStampSheetRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChargeWalletByStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChargeWalletByStampSheetRequest& operator=(const ChargeWalletByStampSheetRequest& chargeWalletByStampSheetRequest)
    {
        Gs2UserRequest::operator=(chargeWalletByStampSheetRequest);
        Gs2Money::operator=(chargeWalletByStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*chargeWalletByStampSheetRequest.m_pData);

        return *this;
    }

    ChargeWalletByStampSheetRequest& operator=(ChargeWalletByStampSheetRequest&& chargeWalletByStampSheetRequest)
    {
        Gs2UserRequest::operator=(std::move(chargeWalletByStampSheetRequest));
        Gs2Money::operator=(std::move(chargeWalletByStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = chargeWalletByStampSheetRequest.m_pData;
        chargeWalletByStampSheetRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * 取得するウォレットのスロット番号を取得
     *
     * @return 取得するウォレットのスロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * 取得するウォレットのスロット番号を設定
     *
     * @param slot 取得するウォレットのスロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * 取得するウォレットのスロット番号を設定
     *
     * @param slot 取得するウォレットのスロット番号
     */
    ChargeWalletByStampSheetRequest& withSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
        return *this;
    }

    /**
     * スタンプシートを取得
     *
     * @return スタンプシート
     */
    const optional<StringHolder>& getSheet() const
    {
        return ensureData().sheet;
    }

    /**
     * スタンプシートを設定
     *
     * @param sheet スタンプシート
     */
    void setSheet(const Char* sheet)
    {
        ensureData().sheet.emplace(sheet);
    }

    /**
     * スタンプシートを設定
     *
     * @param sheet スタンプシート
     */
    ChargeWalletByStampSheetRequest& withSheet(const Char* sheet)
    {
        ensureData().sheet.emplace(sheet);
        return *this;
    }

    /**
     * スタンプの暗号鍵を取得
     *
     * @return スタンプの暗号鍵
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * スタンプの暗号鍵を設定
     *
     * @param keyName スタンプの暗号鍵
     */
    void setKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
    }

    /**
     * スタンプの暗号鍵を設定
     *
     * @param keyName スタンプの暗号鍵
     */
    ChargeWalletByStampSheetRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    ChargeWalletByStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChargeWalletByStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChargeWalletByStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChargeWalletByStampSheetRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    ChargeWalletByStampSheetRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_MONEY_CONTROL_CHARGEWALLETBYSTAMPSHEETREQUEST_HPP_