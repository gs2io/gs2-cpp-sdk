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

#ifndef GS2_LIMIT_MODEL_COUNTER_HPP_
#define GS2_LIMIT_MODEL_COUNTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace limit {

/**
 * カウンター
 *
 * @author Game Server Services, Inc.
 *
 */
class Counter : public Gs2Object
{
    friend bool operator!=(const Counter& lhs, const Counter& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンター */
        optional<StringHolder> counterId;
        /** 回数制限の種類の名前 */
        optional<StringHolder> limitName;
        /** カウンターの名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** カウント値 */
        optional<Int32> count;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            counterId(data.counterId),
            limitName(data.limitName),
            name(data.name),
            userId(data.userId),
            count(data.count),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            counterId(std::move(data.counterId)),
            limitName(std::move(data.limitName)),
            name(std::move(data.name)),
            userId(std::move(data.userId)),
            count(std::move(data.count)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "counterId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "limitName") == 0) {
                if (jsonValue.IsString())
                {
                    this->limitName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Counter() :
        m_pData(nullptr)
    {}

    Counter(const Counter& counter) :
        Gs2Object(counter),
        m_pData(counter.m_pData != nullptr ? new Data(*counter.m_pData) : nullptr)
    {}

    Counter(Counter&& counter) :
        Gs2Object(std::move(counter)),
        m_pData(counter.m_pData)
    {
        counter.m_pData = nullptr;
    }

    ~Counter()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Counter& operator=(const Counter& counter)
    {
        Gs2Object::operator=(counter);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*counter.m_pData);

        return *this;
    }

    Counter& operator=(Counter&& counter)
    {
        Gs2Object::operator=(std::move(counter));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = counter.m_pData;
        counter.m_pData = nullptr;

        return *this;
    }

    const Counter* operator->() const
    {
        return this;
    }

    Counter* operator->()
    {
        return this;
    }
    /**
     * カウンターを取得
     *
     * @return カウンター
     */
    const optional<StringHolder>& getCounterId() const
    {
        return ensureData().counterId;
    }

    /**
     * カウンターを設定
     *
     * @param counterId カウンター
     */
    void setCounterId(const Char* counterId)
    {
        ensureData().counterId.emplace(counterId);
    }

    /**
     * カウンターを設定
     *
     * @param counterId カウンター
     */
    Counter& withCounterId(const Char* counterId)
    {
        setCounterId(counterId);
        return *this;
    }

    /**
     * 回数制限の種類の名前を取得
     *
     * @return 回数制限の種類の名前
     */
    const optional<StringHolder>& getLimitName() const
    {
        return ensureData().limitName;
    }

    /**
     * 回数制限の種類の名前を設定
     *
     * @param limitName 回数制限の種類の名前
     */
    void setLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
    }

    /**
     * 回数制限の種類の名前を設定
     *
     * @param limitName 回数制限の種類の名前
     */
    Counter& withLimitName(const Char* limitName)
    {
        setLimitName(limitName);
        return *this;
    }

    /**
     * カウンターの名前を取得
     *
     * @return カウンターの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カウンターの名前を設定
     *
     * @param name カウンターの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カウンターの名前を設定
     *
     * @param name カウンターの名前
     */
    Counter& withName(const Char* name)
    {
        setName(name);
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
    Counter& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * カウント値を取得
     *
     * @return カウント値
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * カウント値を設定
     *
     * @param count カウント値
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * カウント値を設定
     *
     * @param count カウント値
     */
    Counter& withCount(Int32 count)
    {
        setCount(count);
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
    Counter& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Counter& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Counter& lhs, const Counter& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->counterId != lhr.m_pData->counterId)
        {
            return true;
        }
        if (lhs.m_pData->limitName != lhr.m_pData->limitName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Counter& lhs, const Counter& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LIMIT_MODEL_COUNTER_HPP_