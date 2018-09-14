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

#ifndef GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"

namespace gs2 { namespace stamina {

/**
 * @author Game Server Services, Inc.
 */
class ChangeStaminaByStampSheetRequest : public Gs2UserRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "ChangeStaminaByStampSheet";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタンプシート */
        optional<StringHolder> sheet;
        /** スタンプの暗号鍵 */
        optional<StringHolder> keyName;
        /** スタミナの最大値 */
        optional<Int32> maxValue;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            sheet(data.sheet),
            keyName(data.keyName),
            maxValue(data.maxValue)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            sheet(std::move(data.sheet)),
            keyName(std::move(data.keyName)),
            maxValue(std::move(data.maxValue))
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
    ChangeStaminaByStampSheetRequest() :
        m_pData(nullptr)
    {}

    ChangeStaminaByStampSheetRequest(const ChangeStaminaByStampSheetRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChangeStaminaByStampSheetRequest(ChangeStaminaByStampSheetRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChangeStaminaByStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChangeStaminaByStampSheetRequest& operator=(const ChangeStaminaByStampSheetRequest& changeStaminaByStampSheetRequest)
    {
        Gs2UserRequest::operator=(changeStaminaByStampSheetRequest);
        Gs2Stamina::operator=(changeStaminaByStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*changeStaminaByStampSheetRequest.m_pData);

        return *this;
    }

    ChangeStaminaByStampSheetRequest& operator=(ChangeStaminaByStampSheetRequest&& changeStaminaByStampSheetRequest)
    {
        Gs2UserRequest::operator=(std::move(changeStaminaByStampSheetRequest));
        Gs2Stamina::operator=(std::move(changeStaminaByStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = changeStaminaByStampSheetRequest.m_pData;
        changeStaminaByStampSheetRequest.m_pData = nullptr;

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
    ChangeStaminaByStampSheetRequest& withSheet(const Char* sheet)
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
    ChangeStaminaByStampSheetRequest& withKeyName(const Char* keyName)
    {
        ensureData().keyName.emplace(keyName);
        return *this;
    }

    /**
     * スタミナの最大値を取得
     *
     * @return スタミナの最大値
     */
    const optional<Int32>& getMaxValue() const
    {
        return ensureData().maxValue;
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    void setMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    ChangeStaminaByStampSheetRequest& withMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    ChangeStaminaByStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChangeStaminaByStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChangeStaminaByStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChangeStaminaByStampSheetRequest& withRequestId(const Char* gs2RequestId)
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
    ChangeStaminaByStampSheetRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETREQUEST_HPP_