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
#include <gs2/core/external/optional/optional.hpp>
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
        /** ミューテックス のGRN */
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
        optional<Int64> createAt;
        /** 作成日時 */
        optional<Int64> ttlAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            mutexId(data.mutexId),
            userId(data.userId),
            propertyId(data.propertyId),
            transactionId(data.transactionId),
            referenceCount(data.referenceCount),
            createAt(data.createAt),
            ttlAt(data.ttlAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            mutexId(std::move(data.mutexId)),
            userId(std::move(data.userId)),
            propertyId(std::move(data.propertyId)),
            transactionId(std::move(data.transactionId)),
            referenceCount(std::move(data.referenceCount)),
            createAt(std::move(data.createAt)),
            ttlAt(std::move(data.ttlAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "mutexId") == 0) {
                if (jsonValue.IsString())
                {
                    this->mutexId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "propertyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "transactionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "referenceCount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->referenceCount = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "ttlAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->ttlAt = jsonValue.GetInt64();
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
    Mutex() :
        m_pData(nullptr)
    {}

    Mutex(const Mutex& mutex) :
        Gs2Object(mutex),
        m_pData(mutex.m_pData != nullptr ? new Data(*mutex.m_pData) : nullptr)
    {}

    Mutex(Mutex&& mutex) :
        Gs2Object(std::move(mutex)),
        m_pData(mutex.m_pData)
    {
        mutex.m_pData = nullptr;
    }

    ~Mutex()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Mutex& operator=(const Mutex& mutex)
    {
        Gs2Object::operator=(mutex);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*mutex.m_pData);

        return *this;
    }

    Mutex& operator=(Mutex&& mutex)
    {
        Gs2Object::operator=(std::move(mutex));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = mutex.m_pData;
        mutex.m_pData = nullptr;

        return *this;
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
     * ミューテックス のGRNを取得
     *
     * @return ミューテックス のGRN
     */
    const optional<StringHolder>& getMutexId() const
    {
        return ensureData().mutexId;
    }

    /**
     * ミューテックス のGRNを設定
     *
     * @param mutexId ミューテックス のGRN
     */
    void setMutexId(const Char* mutexId)
    {
        ensureData().mutexId.emplace(mutexId);
    }

    /**
     * ミューテックス のGRNを設定
     *
     * @param mutexId ミューテックス のGRN
     */
    Mutex& withMutexId(const Char* mutexId)
    {
        setMutexId(mutexId);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Mutex& withUserId(const Char* userId)
    {
        setUserId(userId);
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
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    Mutex& withPropertyId(const Char* propertyId)
    {
        setPropertyId(propertyId);
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
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
    }

    /**
     * ロックを取得したトランザクションIDを設定
     *
     * @param transactionId ロックを取得したトランザクションID
     */
    Mutex& withTransactionId(const Char* transactionId)
    {
        setTransactionId(transactionId);
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
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Mutex& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getTtlAt() const
    {
        return ensureData().ttlAt;
    }

    /**
     * 作成日時を設定
     *
     * @param ttlAt 作成日時
     */
    void setTtlAt(Int64 ttlAt)
    {
        ensureData().ttlAt.emplace(ttlAt);
    }

    /**
     * 作成日時を設定
     *
     * @param ttlAt 作成日時
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

bool operator!=(const Mutex& lhs, const Mutex& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
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

bool operator==(const Mutex& lhs, const Mutex& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOCK_MODEL_MUTEX_HPP_