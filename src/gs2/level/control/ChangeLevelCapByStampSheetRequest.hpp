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

#ifndef GS2_LEVEL_CONTROL_CHANGELEVELCAPBYSTAMPSHEETREQUEST_HPP_
#define GS2_LEVEL_CONTROL_CHANGELEVELCAPBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"

namespace gs2 { namespace level {

/**
 * @author Game Server Services, Inc.
 */
class ChangeLevelCapByStampSheetRequest : public Gs2UserRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "ChangeLevelCapByStampSheet";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタンプシート */
        optional<StringHolder> sheet;
        /** スタンプの暗号鍵 */
        optional<StringHolder> keyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            sheet(data.sheet),
            keyName(data.keyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
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
    ChangeLevelCapByStampSheetRequest() :
        m_pData(nullptr)
    {}

    ChangeLevelCapByStampSheetRequest(const ChangeLevelCapByStampSheetRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ChangeLevelCapByStampSheetRequest(ChangeLevelCapByStampSheetRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ChangeLevelCapByStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChangeLevelCapByStampSheetRequest& operator=(const ChangeLevelCapByStampSheetRequest& changeLevelCapByStampSheetRequest)
    {
        Gs2UserRequest::operator=(changeLevelCapByStampSheetRequest);
        Gs2Level::operator=(changeLevelCapByStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*changeLevelCapByStampSheetRequest.m_pData);

        return *this;
    }

    ChangeLevelCapByStampSheetRequest& operator=(ChangeLevelCapByStampSheetRequest&& changeLevelCapByStampSheetRequest)
    {
        Gs2UserRequest::operator=(std::move(changeLevelCapByStampSheetRequest));
        Gs2Level::operator=(std::move(changeLevelCapByStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = changeLevelCapByStampSheetRequest.m_pData;
        changeLevelCapByStampSheetRequest.m_pData = nullptr;

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
    ChangeLevelCapByStampSheetRequest& withSheet(const Char* sheet)
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
    ChangeLevelCapByStampSheetRequest& withKeyName(const Char* keyName)
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
    ChangeLevelCapByStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ChangeLevelCapByStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ChangeLevelCapByStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ChangeLevelCapByStampSheetRequest& withRequestId(const Char* gs2RequestId)
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
    ChangeLevelCapByStampSheetRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_LEVEL_CONTROL_CHANGELEVELCAPBYSTAMPSHEETREQUEST_HPP_