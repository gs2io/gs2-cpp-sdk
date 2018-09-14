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

#ifndef GS2_LOCK_CONTROL_GETLOCKPOOLREQUEST_HPP_
#define GS2_LOCK_CONTROL_GETLOCKPOOLREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LockConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace lock
{

/**
 * @author Game Server Services, Inc.
 */
class GetLockPoolRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "GetLockPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロックプールの名前を指定します。 */
        optional<StringHolder> lockPoolName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lockPoolName(data.lockPoolName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lockPoolName(std::move(data.lockPoolName))
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
    GetLockPoolRequest() :
        m_pData(nullptr)
    {}

    GetLockPoolRequest(const GetLockPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lock(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetLockPoolRequest(GetLockPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lock(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetLockPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetLockPoolRequest& operator=(const GetLockPoolRequest& getLockPoolRequest)
    {
        Gs2BasicRequest::operator=(getLockPoolRequest);
        Gs2Lock::operator=(getLockPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getLockPoolRequest.m_pData);

        return *this;
    }

    GetLockPoolRequest& operator=(GetLockPoolRequest&& getLockPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(getLockPoolRequest));
        Gs2Lock::operator=(std::move(getLockPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getLockPoolRequest.m_pData;
        getLockPoolRequest.m_pData = nullptr;

        return *this;
    }

    const GetLockPoolRequest* operator->() const
    {
        return this;
    }

    GetLockPoolRequest* operator->()
    {
        return this;
    }

    /**
     * ロックプールの名前を指定します。を取得
     *
     * @return ロックプールの名前を指定します。
     */
    const optional<StringHolder>& getLockPoolName() const
    {
        return ensureData().lockPoolName;
    }

    /**
     * ロックプールの名前を指定します。を設定
     *
     * @param lockPoolName ロックプールの名前を指定します。
     */
    void setLockPoolName(const Char* lockPoolName)
    {
        ensureData().lockPoolName.emplace(lockPoolName);
    }

    /**
     * ロックプールの名前を指定します。を設定
     *
     * @param lockPoolName ロックプールの名前を指定します。
     */
    GetLockPoolRequest& withLockPoolName(const Char* lockPoolName)
    {
        ensureData().lockPoolName.emplace(lockPoolName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetLockPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetLockPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetLockPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetLockPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOCK_CONTROL_GETLOCKPOOLREQUEST_HPP_