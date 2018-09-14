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

#ifndef GS2_GACHA_CONTROL_DOGACHAREQUEST_HPP_
#define GS2_GACHA_CONTROL_DOGACHAREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GachaConst.hpp"

namespace gs2 { namespace gacha {

/**
 * @author Game Server Services, Inc.
 */
class DoGachaRequest : public Gs2UserRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "DoGacha";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** ガチャの名前を指定します。 */
        optional<StringHolder> gachaName;
        /** コンテキストデータ */
        optional<StringHolder> context;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            gachaName(data.gachaName),
            context(data.context)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            gachaName(std::move(data.gachaName)),
            context(std::move(data.context))
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
    DoGachaRequest() :
        m_pData(nullptr)
    {}

    DoGachaRequest(const DoGachaRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DoGachaRequest(DoGachaRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DoGachaRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DoGachaRequest& operator=(const DoGachaRequest& doGachaRequest)
    {
        Gs2UserRequest::operator=(doGachaRequest);
        Gs2Gacha::operator=(doGachaRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*doGachaRequest.m_pData);

        return *this;
    }

    DoGachaRequest& operator=(DoGachaRequest&& doGachaRequest)
    {
        Gs2UserRequest::operator=(std::move(doGachaRequest));
        Gs2Gacha::operator=(std::move(doGachaRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = doGachaRequest.m_pData;
        doGachaRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * ガチャプールの名前を指定します。を取得
     *
     * @return ガチャプールの名前を指定します。
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    DoGachaRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * ガチャの名前を指定します。を取得
     *
     * @return ガチャの名前を指定します。
     */
    const optional<StringHolder>& getGachaName() const
    {
        return ensureData().gachaName;
    }

    /**
     * ガチャの名前を指定します。を設定
     *
     * @param gachaName ガチャの名前を指定します。
     */
    void setGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
    }

    /**
     * ガチャの名前を指定します。を設定
     *
     * @param gachaName ガチャの名前を指定します。
     */
    DoGachaRequest& withGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
        return *this;
    }

    /**
     * コンテキストデータを取得
     *
     * @return コンテキストデータ
     */
    const optional<StringHolder>& getContext() const
    {
        return ensureData().context;
    }

    /**
     * コンテキストデータを設定
     *
     * @param context コンテキストデータ
     */
    void setContext(const Char* context)
    {
        ensureData().context.emplace(context);
    }

    /**
     * コンテキストデータを設定
     *
     * @param context コンテキストデータ
     */
    DoGachaRequest& withContext(const Char* context)
    {
        ensureData().context.emplace(context);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DoGachaRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DoGachaRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DoGachaRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DoGachaRequest& withRequestId(const Char* gs2RequestId)
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
    DoGachaRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_GACHA_CONTROL_DOGACHAREQUEST_HPP_