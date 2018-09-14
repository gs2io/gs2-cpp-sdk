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
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** カウンター名 */
        optional<StringHolder> counterName;
        /** 現在のカウント値 */
        optional<Int32> count;
        /** カウントのリミット値 */
        optional<Int32> limit;
        /** 次回リセット日時(エポック秒) */
        optional<Int32> nextResetAt;
        /** 最後にカウンターを進めた時間(エポック秒) */
        optional<Int32> countAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            counterName(data.counterName),
            count(data.count),
            limit(data.limit),
            nextResetAt(data.nextResetAt),
            countAt(data.countAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            counterName(std::move(data.counterName)),
            count(std::move(data.count)),
            limit(std::move(data.limit)),
            nextResetAt(std::move(data.nextResetAt)),
            countAt(std::move(data.countAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "counterName") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "limit") == 0) {
                if (jsonValue.IsInt())
                {
                    this->limit = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "nextResetAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->nextResetAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "countAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->countAt = jsonValue.GetInt();
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
     * カウンター名を取得
     *
     * @return カウンター名
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * 現在のカウント値を取得
     *
     * @return 現在のカウント値
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 現在のカウント値を設定
     *
     * @param count 現在のカウント値
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * カウントのリミット値を取得
     *
     * @return カウントのリミット値
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * カウントのリミット値を設定
     *
     * @param limit カウントのリミット値
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * 次回リセット日時(エポック秒)を取得
     *
     * @return 次回リセット日時(エポック秒)
     */
    const optional<Int32>& getNextResetAt() const
    {
        return ensureData().nextResetAt;
    }

    /**
     * 次回リセット日時(エポック秒)を設定
     *
     * @param nextResetAt 次回リセット日時(エポック秒)
     */
    void setNextResetAt(Int32 nextResetAt)
    {
        ensureData().nextResetAt.emplace(nextResetAt);
    }

    /**
     * 最後にカウンターを進めた時間(エポック秒)を取得
     *
     * @return 最後にカウンターを進めた時間(エポック秒)
     */
    const optional<Int32>& getCountAt() const
    {
        return ensureData().countAt;
    }

    /**
     * 最後にカウンターを進めた時間(エポック秒)を設定
     *
     * @param countAt 最後にカウンターを進めた時間(エポック秒)
     */
    void setCountAt(Int32 countAt)
    {
        ensureData().countAt.emplace(countAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LIMIT_MODEL_COUNTER_HPP_