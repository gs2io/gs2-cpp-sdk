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

#ifndef GS2_LOCK_CONTROL_GETLOCKPOOLSTATUSREQUEST_HPP_
#define GS2_LOCK_CONTROL_GETLOCKPOOLSTATUSREQUEST_HPP_

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
class GetLockPoolStatusRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "GetLockPoolStatus";

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
    GetLockPoolStatusRequest() :
        m_pData(nullptr)
    {}

    GetLockPoolStatusRequest(const GetLockPoolStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lock(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetLockPoolStatusRequest(GetLockPoolStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lock(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetLockPoolStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetLockPoolStatusRequest& operator=(const GetLockPoolStatusRequest& getLockPoolStatusRequest)
    {
        Gs2BasicRequest::operator=(getLockPoolStatusRequest);
        Gs2Lock::operator=(getLockPoolStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getLockPoolStatusRequest.m_pData);

        return *this;
    }

    GetLockPoolStatusRequest& operator=(GetLockPoolStatusRequest&& getLockPoolStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getLockPoolStatusRequest));
        Gs2Lock::operator=(std::move(getLockPoolStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getLockPoolStatusRequest.m_pData;
        getLockPoolStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetLockPoolStatusRequest* operator->() const
    {
        return this;
    }

    GetLockPoolStatusRequest* operator->()
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
    GetLockPoolStatusRequest& withLockPoolName(const Char* lockPoolName)
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
    GetLockPoolStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetLockPoolStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetLockPoolStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetLockPoolStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOCK_CONTROL_GETLOCKPOOLSTATUSREQUEST_HPP_