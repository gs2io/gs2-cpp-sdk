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

#ifndef GS2_STAMINA_CONTROL_GETSTAMINAPOOLSTATUSREQUEST_HPP_
#define GS2_STAMINA_CONTROL_GETSTAMINAPOOLSTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * @author Game Server Services, Inc.
 */
class GetStaminaPoolStatusRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "GetStaminaPoolStatus";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナプールの名前を指定します。 */
        optional<StringHolder> staminaPoolName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            staminaPoolName(data.staminaPoolName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            staminaPoolName(std::move(data.staminaPoolName))
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
    GetStaminaPoolStatusRequest() :
        m_pData(nullptr)
    {}

    GetStaminaPoolStatusRequest(const GetStaminaPoolStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetStaminaPoolStatusRequest(GetStaminaPoolStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetStaminaPoolStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStaminaPoolStatusRequest& operator=(const GetStaminaPoolStatusRequest& getStaminaPoolStatusRequest)
    {
        Gs2BasicRequest::operator=(getStaminaPoolStatusRequest);
        Gs2Stamina::operator=(getStaminaPoolStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStaminaPoolStatusRequest.m_pData);

        return *this;
    }

    GetStaminaPoolStatusRequest& operator=(GetStaminaPoolStatusRequest&& getStaminaPoolStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getStaminaPoolStatusRequest));
        Gs2Stamina::operator=(std::move(getStaminaPoolStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStaminaPoolStatusRequest.m_pData;
        getStaminaPoolStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetStaminaPoolStatusRequest* operator->() const
    {
        return this;
    }

    GetStaminaPoolStatusRequest* operator->()
    {
        return this;
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
    GetStaminaPoolStatusRequest& withStaminaPoolName(const Char* staminaPoolName)
    {
        ensureData().staminaPoolName.emplace(staminaPoolName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetStaminaPoolStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetStaminaPoolStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetStaminaPoolStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetStaminaPoolStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_GETSTAMINAPOOLSTATUSREQUEST_HPP_