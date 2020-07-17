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

#ifndef GS2_EXCHANGE_MODEL_AWAIT_HPP_
#define GS2_EXCHANGE_MODEL_AWAIT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace exchange {

/**
 * 交換待機
 *
 * @author Game Server Services, Inc.
 *
 */
class Await : public Gs2Object
{
    friend bool operator!=(const Await& lhs, const Await& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換待機 */
        optional<StringHolder> awaitId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 交換レート名 */
        optional<StringHolder> rateName;
        /** 交換待機の名前 */
        optional<StringHolder> name;
        /** 交換数 */
        optional<Int32> count;
        /** 作成日時 */
        optional<Int64> exchangedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            awaitId(data.awaitId),
            userId(data.userId),
            rateName(data.rateName),
            name(data.name),
            count(data.count),
            exchangedAt(data.exchangedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "awaitId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->awaitId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "rateName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->rateName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "count") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "exchangedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->exchangedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Await() = default;
    Await(const Await& await_) = default;
    Await(Await&& await_) = default;
    ~Await() = default;

    Await& operator=(const Await& await_) = default;
    Await& operator=(Await&& await_) = default;

    Await deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Await);
    }

    const Await* operator->() const
    {
        return this;
    }

    Await* operator->()
    {
        return this;
    }
    /**
     * 交換待機を取得
     *
     * @return 交換待機
     */
    const optional<StringHolder>& getAwaitId() const
    {
        return ensureData().awaitId;
    }

    /**
     * 交換待機を設定
     *
     * @param awaitId 交換待機
     */
    void setAwaitId(StringHolder awaitId)
    {
        ensureData().awaitId.emplace(std::move(awaitId));
    }

    /**
     * 交換待機を設定
     *
     * @param awaitId 交換待機
     */
    Await& withAwaitId(StringHolder awaitId)
    {
        setAwaitId(std::move(awaitId));
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
    Await& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 交換レート名を取得
     *
     * @return 交換レート名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * 交換レート名を設定
     *
     * @param rateName 交換レート名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * 交換レート名を設定
     *
     * @param rateName 交換レート名
     */
    Await& withRateName(StringHolder rateName)
    {
        setRateName(std::move(rateName));
        return *this;
    }

    /**
     * 交換待機の名前を取得
     *
     * @return 交換待機の名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 交換待機の名前を設定
     *
     * @param name 交換待機の名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 交換待機の名前を設定
     *
     * @param name 交換待機の名前
     */
    Await& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 交換数を取得
     *
     * @return 交換数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 交換数を設定
     *
     * @param count 交換数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 交換数を設定
     *
     * @param count 交換数
     */
    Await& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getExchangedAt() const
    {
        return ensureData().exchangedAt;
    }

    /**
     * 作成日時を設定
     *
     * @param exchangedAt 作成日時
     */
    void setExchangedAt(Int64 exchangedAt)
    {
        ensureData().exchangedAt.emplace(exchangedAt);
    }

    /**
     * 作成日時を設定
     *
     * @param exchangedAt 作成日時
     */
    Await& withExchangedAt(Int64 exchangedAt)
    {
        setExchangedAt(exchangedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Await& lhs, const Await& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->awaitId != lhr.m_pData->awaitId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->rateName != lhr.m_pData->rateName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->exchangedAt != lhr.m_pData->exchangedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Await& lhs, const Await& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXCHANGE_MODEL_AWAIT_HPP_