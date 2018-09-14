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

#ifndef GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"

namespace gs2 { namespace stamina {

/**
 * @author Game Server Services, Inc.
 */
class ConsumeStaminaRequest : public Gs2UserRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "ConsumeStamina";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナプールの名前を指定します。 */
        optional<StringHolder> staminaPoolName;
        /** スタミナの増減量 */
        optional<Int32> variation;
        /** スタミナの最大値 */
        optional<Int32> maxValue;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            staminaPoolName(data.staminaPoolName),
            variation(data.variation),
            maxValue(data.maxValue)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            staminaPoolName(std::move(data.staminaPoolName)),
            variation(std::move(data.variation)),
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
    ConsumeStaminaRequest() :
        m_pData(nullptr)
    {}

    ConsumeStaminaRequest(const ConsumeStaminaRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ConsumeStaminaRequest(ConsumeStaminaRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ConsumeStaminaRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeStaminaRequest& operator=(const ConsumeStaminaRequest& consumeStaminaRequest)
    {
        Gs2UserRequest::operator=(consumeStaminaRequest);
        Gs2Stamina::operator=(consumeStaminaRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeStaminaRequest.m_pData);

        return *this;
    }

    ConsumeStaminaRequest& operator=(ConsumeStaminaRequest&& consumeStaminaRequest)
    {
        Gs2UserRequest::operator=(std::move(consumeStaminaRequest));
        Gs2Stamina::operator=(std::move(consumeStaminaRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeStaminaRequest.m_pData;
        consumeStaminaRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * スタミナプールの名前を指定します。を取得
     *
     * @return スタミナプールの名前を指定します。
     */
    const optional<StringHolder>& getStaminaPoolName() const
    {
        return ensureData().staminaPoolName;
    }

    /**
     * スタミナプールの名前を指定します。を設定
     *
     * @param staminaPoolName スタミナプールの名前を指定します。
     */
    void setStaminaPoolName(const Char* staminaPoolName)
    {
        ensureData().staminaPoolName.emplace(staminaPoolName);
    }

    /**
     * スタミナプールの名前を指定します。を設定
     *
     * @param staminaPoolName スタミナプールの名前を指定します。
     */
    ConsumeStaminaRequest& withStaminaPoolName(const Char* staminaPoolName)
    {
        ensureData().staminaPoolName.emplace(staminaPoolName);
        return *this;
    }

    /**
     * スタミナの増減量を取得
     *
     * @return スタミナの増減量
     */
    const optional<Int32>& getVariation() const
    {
        return ensureData().variation;
    }

    /**
     * スタミナの増減量を設定
     *
     * @param variation スタミナの増減量
     */
    void setVariation(Int32 variation)
    {
        ensureData().variation.emplace(variation);
    }

    /**
     * スタミナの増減量を設定
     *
     * @param variation スタミナの増減量
     */
    ConsumeStaminaRequest& withVariation(Int32 variation)
    {
        ensureData().variation.emplace(variation);
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
    ConsumeStaminaRequest& withMaxValue(Int32 maxValue)
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
    ConsumeStaminaRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ConsumeStaminaRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ConsumeStaminaRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ConsumeStaminaRequest& withRequestId(const Char* gs2RequestId)
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
    ConsumeStaminaRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_