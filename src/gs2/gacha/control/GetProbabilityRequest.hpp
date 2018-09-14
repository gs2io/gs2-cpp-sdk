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

#ifndef GS2_GACHA_CONTROL_GETPROBABILITYREQUEST_HPP_
#define GS2_GACHA_CONTROL_GETPROBABILITYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GachaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class GetProbabilityRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "GetProbability";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前 */
        optional<StringHolder> gachaPoolName;
        /** ガチャの名前 */
        optional<StringHolder> gachaName;
        /** 何回目の抽選時の抽選確率を取得するか */
        optional<Int32> drawTime;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            gachaName(data.gachaName),
            drawTime(data.drawTime)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            gachaName(std::move(data.gachaName)),
            drawTime(std::move(data.drawTime))
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
    GetProbabilityRequest() :
        m_pData(nullptr)
    {}

    GetProbabilityRequest(const GetProbabilityRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetProbabilityRequest(GetProbabilityRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetProbabilityRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetProbabilityRequest& operator=(const GetProbabilityRequest& getProbabilityRequest)
    {
        Gs2BasicRequest::operator=(getProbabilityRequest);
        Gs2Gacha::operator=(getProbabilityRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getProbabilityRequest.m_pData);

        return *this;
    }

    GetProbabilityRequest& operator=(GetProbabilityRequest&& getProbabilityRequest)
    {
        Gs2BasicRequest::operator=(std::move(getProbabilityRequest));
        Gs2Gacha::operator=(std::move(getProbabilityRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getProbabilityRequest.m_pData;
        getProbabilityRequest.m_pData = nullptr;

        return *this;
    }

    const GetProbabilityRequest* operator->() const
    {
        return this;
    }

    GetProbabilityRequest* operator->()
    {
        return this;
    }

    /**
     * ガチャプールの名前を取得
     *
     * @return ガチャプールの名前
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプールの名前を設定
     *
     * @param gachaPoolName ガチャプールの名前
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャプールの名前を設定
     *
     * @param gachaPoolName ガチャプールの名前
     */
    GetProbabilityRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
        return *this;
    }

    /**
     * ガチャの名前を取得
     *
     * @return ガチャの名前
     */
    const optional<StringHolder>& getGachaName() const
    {
        return ensureData().gachaName;
    }

    /**
     * ガチャの名前を設定
     *
     * @param gachaName ガチャの名前
     */
    void setGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
    }

    /**
     * ガチャの名前を設定
     *
     * @param gachaName ガチャの名前
     */
    GetProbabilityRequest& withGachaName(const Char* gachaName)
    {
        ensureData().gachaName.emplace(gachaName);
        return *this;
    }

    /**
     * 何回目の抽選時の抽選確率を取得するかを取得
     *
     * @return 何回目の抽選時の抽選確率を取得するか
     */
    const optional<Int32>& getDrawTime() const
    {
        return ensureData().drawTime;
    }

    /**
     * 何回目の抽選時の抽選確率を取得するかを設定
     *
     * @param drawTime 何回目の抽選時の抽選確率を取得するか
     */
    void setDrawTime(Int32 drawTime)
    {
        ensureData().drawTime.emplace(drawTime);
    }

    /**
     * 何回目の抽選時の抽選確率を取得するかを設定
     *
     * @param drawTime 何回目の抽選時の抽選確率を取得するか
     */
    GetProbabilityRequest& withDrawTime(Int32 drawTime)
    {
        ensureData().drawTime.emplace(drawTime);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetProbabilityRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetProbabilityRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetProbabilityRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetProbabilityRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_GETPROBABILITYREQUEST_HPP_