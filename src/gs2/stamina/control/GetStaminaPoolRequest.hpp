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

#ifndef GS2_STAMINA_CONTROL_GETSTAMINAPOOLREQUEST_HPP_
#define GS2_STAMINA_CONTROL_GETSTAMINAPOOLREQUEST_HPP_

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
class GetStaminaPoolRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "GetStaminaPool";

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
    GetStaminaPoolRequest() :
        m_pData(nullptr)
    {}

    GetStaminaPoolRequest(const GetStaminaPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetStaminaPoolRequest(GetStaminaPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetStaminaPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStaminaPoolRequest& operator=(const GetStaminaPoolRequest& getStaminaPoolRequest)
    {
        Gs2BasicRequest::operator=(getStaminaPoolRequest);
        Gs2Stamina::operator=(getStaminaPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStaminaPoolRequest.m_pData);

        return *this;
    }

    GetStaminaPoolRequest& operator=(GetStaminaPoolRequest&& getStaminaPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(getStaminaPoolRequest));
        Gs2Stamina::operator=(std::move(getStaminaPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStaminaPoolRequest.m_pData;
        getStaminaPoolRequest.m_pData = nullptr;

        return *this;
    }

    const GetStaminaPoolRequest* operator->() const
    {
        return this;
    }

    GetStaminaPoolRequest* operator->()
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
    GetStaminaPoolRequest& withStaminaPoolName(const Char* staminaPoolName)
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
    GetStaminaPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetStaminaPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetStaminaPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetStaminaPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_GETSTAMINAPOOLREQUEST_HPP_