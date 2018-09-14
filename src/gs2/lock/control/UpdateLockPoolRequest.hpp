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

#ifndef GS2_LOCK_CONTROL_UPDATELOCKPOOLREQUEST_HPP_
#define GS2_LOCK_CONTROL_UPDATELOCKPOOLREQUEST_HPP_

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
class UpdateLockPoolRequest : public Gs2BasicRequest, public Gs2Lock
{
public:
    constexpr static const Char* const FUNCTION = "UpdateLockPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロックプールの名前を指定します。 */
        optional<StringHolder> lockPoolName;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lockPoolName(data.lockPoolName),
            description(data.description),
            serviceClass(data.serviceClass)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lockPoolName(std::move(data.lockPoolName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass))
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
    UpdateLockPoolRequest() :
        m_pData(nullptr)
    {}

    UpdateLockPoolRequest(const UpdateLockPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Lock(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateLockPoolRequest(UpdateLockPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Lock(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateLockPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateLockPoolRequest& operator=(const UpdateLockPoolRequest& updateLockPoolRequest)
    {
        Gs2BasicRequest::operator=(updateLockPoolRequest);
        Gs2Lock::operator=(updateLockPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateLockPoolRequest.m_pData);

        return *this;
    }

    UpdateLockPoolRequest& operator=(UpdateLockPoolRequest&& updateLockPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateLockPoolRequest));
        Gs2Lock::operator=(std::move(updateLockPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateLockPoolRequest.m_pData;
        updateLockPoolRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateLockPoolRequest* operator->() const
    {
        return this;
    }

    UpdateLockPoolRequest* operator->()
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
    UpdateLockPoolRequest& withLockPoolName(const Char* lockPoolName)
    {
        ensureData().lockPoolName.emplace(lockPoolName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateLockPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    UpdateLockPoolRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateLockPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateLockPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateLockPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateLockPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LOCK_CONTROL_UPDATELOCKPOOLREQUEST_HPP_