/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LOCK_MODEL_MUTEX_HPP_
#define GS2_LOCK_MODEL_MUTEX_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace lock {

/**
 * ミューテックス
 *
 * @author Game Server Services, Inc.
 *
 */
class Mutex : public Gs2Object
{
    friend bool operator!=(const Mutex& lhs, const Mutex& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミューテックス */
        optional<StringHolder> mutexId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** ロックを取得したトランザクションID */
        optional<StringHolder> transactionId;
        /** 参照回数 */
        optional<Int32> referenceCount;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** ロックの有効期限 */
        optional<Int64> ttlAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            mutexId(data.mutexId),
            userId(data.userId),
            propertyId(data.propertyId),
            transactionId(data.transactionId),
            referenceCount(data.referenceCount),
            createdAt(data.createdAt),
            ttlAt(data.ttlAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "mutexId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->mutexId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "propertyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "transactionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "referenceCount") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->referenceCount = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "ttlAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->ttlAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Mutex() = default;
    Mutex(const Mutex& mutex) = default;
    Mutex(Mutex&& mutex) = default;
    ~Mutex() = default;

    Mutex& operator=(const Mutex& mutex) = default;
    Mutex& operator=(Mutex&& mutex) = default;

    Mutex deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Mutex);
    }

    const Mutex* operator->() const
    {
        return this;
    }

    Mutex* operator->()
    {
        return this;
    }
    /**
     * ミューテックスを取得
     *
     * @return ミューテックス
     */
    const optional<StringHolder>& getMutexId() const
    {
        return ensureData().mutexId;
    }

    /**
     * ミューテックスを設定
     *
     * @param mutexId ミューテックス
     */
    void setMutexId(StringHolder mutexId)
    {
        ensureData().mutexId.emplace(std::move(mutexId));
    }

    /**
     * ミューテックスを設定
     *
     * @param mutexId ミューテックス
     */
    Mutex& withMutexId(StringHolder mutexId)
    {
        setMutexId(std::move(mutexId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Mutex& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    Mutex& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }

    /**
     * ロックを取得したトランザクションIDを取得
     *
     * @return ロックを取得したトランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * ロックを取得したトランザクションIDを設定
     *
     * @param transactionId ロックを取得したトランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * ロックを取得したトランザクションIDを設定
     *
     * @param transactionId ロックを取得したトランザクションID
     */
    Mutex& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    /**
     * 参照回数を取得
     *
     * @return 参照回数
     */
    const optional<Int32>& getReferenceCount() const
    {
        return ensureData().referenceCount;
    }

    /**
     * 参照回数を設定
     *
     * @param referenceCount 参照回数
     */
    void setReferenceCount(Int32 referenceCount)
    {
        ensureData().referenceCount.emplace(referenceCount);
    }

    /**
     * 参照回数を設定
     *
     * @param referenceCount 参照回数
     */
    Mutex& withReferenceCount(Int32 referenceCount)
    {
        setReferenceCount(referenceCount);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Mutex& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * ロックの有効期限を取得
     *
     * @return ロックの有効期限
     */
    const optional<Int64>& getTtlAt() const
    {
        return ensureData().ttlAt;
    }

    /**
     * ロックの有効期限を設定
     *
     * @param ttlAt ロックの有効期限
     */
    void setTtlAt(Int64 ttlAt)
    {
        ensureData().ttlAt.emplace(ttlAt);
    }

    /**
     * ロックの有効期限を設定
     *
     * @param ttlAt ロックの有効期限
     */
    Mutex& withTtlAt(Int64 ttlAt)
    {
        setTtlAt(ttlAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Mutex& lhs, const Mutex& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->mutexId != lhr.m_pData->mutexId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->propertyId != lhr.m_pData->propertyId)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->referenceCount != lhr.m_pData->referenceCount)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->ttlAt != lhr.m_pData->ttlAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Mutex& lhs, const Mutex& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOCK_MODEL_MUTEX_HPP_