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

#ifndef GS2_LOCK_CONTROL_LOCKBYUSERREQUEST_HPP_
#define GS2_LOCK_CONTROL_LOCKBYUSERREQUEST_HPP_

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
class LockByUserRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "LockByUser";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロックプールの名前を指定します。 */
        optional<StringHolder> lockPoolName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** ロック解除するリソースの名前 */
        optional<StringHolder> resourceName;
        /** ロックの有効期間(秒) */
        optional<Int32> ttl;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lockPoolName(data.lockPoolName),
            userId(data.userId),
            transactionId(data.transactionId),
            resourceName(data.resourceName),
            ttl(data.ttl)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lockPoolName(std::move(data.lockPoolName)),
            userId(std::move(data.userId)),
            transactionId(std::move(data.transactionId)),
            resourceName(std::move(data.resourceName)),
            ttl(std::move(data.ttl))
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
    LockByUserRequest() :
        m_pData(nullptr)
    {}

    LockByUserRequest(const LockByUserRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lock(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    LockByUserRequest(LockByUserRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lock(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~LockByUserRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LockByUserRequest& operator=(const LockByUserRequest& lockByUserRequest)
    {
        Gs2BasicRequest::operator=(lockByUserRequest);
        Gs2Lock::operator=(lockByUserRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lockByUserRequest.m_pData);

        return *this;
    }

    LockByUserRequest& operator=(LockByUserRequest&& lockByUserRequest)
    {
        Gs2BasicRequest::operator=(std::move(lockByUserRequest));
        Gs2Lock::operator=(std::move(lockByUserRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lockByUserRequest.m_pData;
        lockByUserRequest.m_pData = nullptr;

        return *this;
    }

    const LockByUserRequest* operator->() const
    {
        return this;
    }

    LockByUserRequest* operator->()
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
    LockByUserRequest& withLockPoolName(const Char* lockPoolName)
    {
        ensureData().lockPoolName.emplace(lockPoolName);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    LockByUserRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    LockByUserRequest& withTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
        return *this;
    }

    /**
     * ロック解除するリソースの名前を取得
     *
     * @return ロック解除するリソースの名前
     */
    const optional<StringHolder>& getResourceName() const
    {
        return ensureData().resourceName;
    }

    /**
     * ロック解除するリソースの名前を設定
     *
     * @param resourceName ロック解除するリソースの名前
     */
    void setResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
    }

    /**
     * ロック解除するリソースの名前を設定
     *
     * @param resourceName ロック解除するリソースの名前
     */
    LockByUserRequest& withResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
        return *this;
    }

    /**
     * ロックの有効期間(秒)を取得
     *
     * @return ロックの有効期間(秒)
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * ロックの有効期間(秒)を設定
     *
     * @param ttl ロックの有効期間(秒)
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * ロックの有効期間(秒)を設定
     *
     * @param ttl ロックの有効期間(秒)
     */
    LockByUserRequest& withTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LockByUserRequest& withGs2ClientId(const Char* gs2ClientId)
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
    LockByUserRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    LockByUserRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LockByUserRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOCK_CONTROL_LOCKBYUSERREQUEST_HPP_