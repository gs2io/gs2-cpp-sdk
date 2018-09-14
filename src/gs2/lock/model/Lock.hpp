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

#ifndef GS2_LOCK_MODEL_LOCK_HPP_
#define GS2_LOCK_MODEL_LOCK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace lock {

/**
 * ロック
 *
 * @author Game Server Services, Inc.
 *
 */
class Lock : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ロックプールGRN */
        optional<StringHolder> lockPoolId;
        /** オーナーID */
        optional<StringHolder> userId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** リソース名 */
        optional<StringHolder> resourceName;
        /** 有効期限 */
        optional<Int32> ttl;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            lockPoolId(data.lockPoolId),
            userId(data.userId),
            transactionId(data.transactionId),
            resourceName(data.resourceName),
            ttl(data.ttl)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            lockPoolId(std::move(data.lockPoolId)),
            userId(std::move(data.userId)),
            transactionId(std::move(data.transactionId)),
            resourceName(std::move(data.resourceName)),
            ttl(std::move(data.ttl))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "lockPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->lockPoolId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "transactionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ttl") == 0) {
                if (jsonValue.IsInt())
                {
                    this->ttl = jsonValue.GetInt();
                }
            }
        }
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
    Lock() :
        m_pData(nullptr)
    {}

    Lock(const Lock& lock) :
        Gs2Object(lock),
        m_pData(lock.m_pData != nullptr ? new Data(*lock.m_pData) : nullptr)
    {}

    Lock(Lock&& lock) :
        Gs2Object(std::move(lock)),
        m_pData(lock.m_pData)
    {
        lock.m_pData = nullptr;
    }

    ~Lock()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Lock& operator=(const Lock& lock)
    {
        Gs2Object::operator=(lock);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lock.m_pData);

        return *this;
    }

    Lock& operator=(Lock&& lock)
    {
        Gs2Object::operator=(std::move(lock));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lock.m_pData;
        lock.m_pData = nullptr;

        return *this;
    }

    const Lock* operator->() const
    {
        return this;
    }

    Lock* operator->()
    {
        return this;
    }


    /**
     * ロックプールGRNを取得
     *
     * @return ロックプールGRN
     */
    const optional<StringHolder>& getLockPoolId() const
    {
        return ensureData().lockPoolId;
    }

    /**
     * ロックプールGRNを設定
     *
     * @param lockPoolId ロックプールGRN
     */
    void setLockPoolId(const Char* lockPoolId)
    {
        ensureData().lockPoolId.emplace(lockPoolId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * オーナーIDを設定
     *
     * @param userId オーナーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
     * リソース名を取得
     *
     * @return リソース名
     */
    const optional<StringHolder>& getResourceName() const
    {
        return ensureData().resourceName;
    }

    /**
     * リソース名を設定
     *
     * @param resourceName リソース名
     */
    void setResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * 有効期限を設定
     *
     * @param ttl 有効期限
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOCK_MODEL_LOCK_HPP_