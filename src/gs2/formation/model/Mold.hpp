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

#ifndef GS2_FORMATION_MODEL_MOLD_HPP_
#define GS2_FORMATION_MODEL_MOLD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * 保存したフォーム
 *
 * @author Game Server Services, Inc.
 *
 */
class Mold : public Gs2Object
{
    friend bool operator!=(const Mold& lhs, const Mold& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 保存したフォーム */
        optional<StringHolder> moldId;
        /** フォームの保存領域の名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 現在のキャパシティ */
        optional<Int32> capacity;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            moldId(data.moldId),
            name(data.name),
            userId(data.userId),
            capacity(data.capacity),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "moldId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->moldId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "capacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->capacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Mold() = default;
    Mold(const Mold& mold) = default;
    Mold(Mold&& mold) = default;
    ~Mold() = default;

    Mold& operator=(const Mold& mold) = default;
    Mold& operator=(Mold&& mold) = default;

    Mold deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Mold);
    }

    const Mold* operator->() const
    {
        return this;
    }

    Mold* operator->()
    {
        return this;
    }
    /**
     * 保存したフォームを取得
     *
     * @return 保存したフォーム
     */
    const optional<StringHolder>& getMoldId() const
    {
        return ensureData().moldId;
    }

    /**
     * 保存したフォームを設定
     *
     * @param moldId 保存したフォーム
     */
    void setMoldId(StringHolder moldId)
    {
        ensureData().moldId.emplace(std::move(moldId));
    }

    /**
     * 保存したフォームを設定
     *
     * @param moldId 保存したフォーム
     */
    Mold& withMoldId(StringHolder moldId)
    {
        setMoldId(std::move(moldId));
        return *this;
    }

    /**
     * フォームの保存領域の名前を取得
     *
     * @return フォームの保存領域の名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param name フォームの保存領域の名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * フォームの保存領域の名前を設定
     *
     * @param name フォームの保存領域の名前
     */
    Mold& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Mold& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 現在のキャパシティを取得
     *
     * @return 現在のキャパシティ
     */
    const optional<Int32>& getCapacity() const
    {
        return ensureData().capacity;
    }

    /**
     * 現在のキャパシティを設定
     *
     * @param capacity 現在のキャパシティ
     */
    void setCapacity(Int32 capacity)
    {
        ensureData().capacity.emplace(capacity);
    }

    /**
     * 現在のキャパシティを設定
     *
     * @param capacity 現在のキャパシティ
     */
    Mold& withCapacity(Int32 capacity)
    {
        setCapacity(capacity);
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
    Mold& withCreatedAt(Int64 createdAt)
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
    Mold& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Mold& lhs, const Mold& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->moldId != lhr.m_pData->moldId)
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
        if (lhs.m_pData->capacity != lhr.m_pData->capacity)
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

inline bool operator==(const Mold& lhs, const Mold& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_MOLD_HPP_