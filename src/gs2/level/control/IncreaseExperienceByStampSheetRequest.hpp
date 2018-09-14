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

#ifndef GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYSTAMPSHEETREQUEST_HPP_
#define GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"

namespace gs2 { namespace level {

/**
 * @author Game Server Services, Inc.
 */
class IncreaseExperienceByStampSheetRequest : public Gs2UserRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "IncreaseExperienceByStampSheet";

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
    IncreaseExperienceByStampSheetRequest() :
        m_pData(nullptr)
    {}

    IncreaseExperienceByStampSheetRequest(const IncreaseExperienceByStampSheetRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    IncreaseExperienceByStampSheetRequest(IncreaseExperienceByStampSheetRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~IncreaseExperienceByStampSheetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IncreaseExperienceByStampSheetRequest& operator=(const IncreaseExperienceByStampSheetRequest& increaseExperienceByStampSheetRequest)
    {
        Gs2UserRequest::operator=(increaseExperienceByStampSheetRequest);
        Gs2Level::operator=(increaseExperienceByStampSheetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*increaseExperienceByStampSheetRequest.m_pData);

        return *this;
    }

    IncreaseExperienceByStampSheetRequest& operator=(IncreaseExperienceByStampSheetRequest&& increaseExperienceByStampSheetRequest)
    {
        Gs2UserRequest::operator=(std::move(increaseExperienceByStampSheetRequest));
        Gs2Level::operator=(std::move(increaseExperienceByStampSheetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = increaseExperienceByStampSheetRequest.m_pData;
        increaseExperienceByStampSheetRequest.m_pData = nullptr;

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
    IncreaseExperienceByStampSheetRequest& withSheet(const Char* sheet)
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
    IncreaseExperienceByStampSheetRequest& withKeyName(const Char* keyName)
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
    IncreaseExperienceByStampSheetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    IncreaseExperienceByStampSheetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    IncreaseExperienceByStampSheetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IncreaseExperienceByStampSheetRequest& withRequestId(const Char* gs2RequestId)
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
    IncreaseExperienceByStampSheetRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYSTAMPSHEETREQUEST_HPP_