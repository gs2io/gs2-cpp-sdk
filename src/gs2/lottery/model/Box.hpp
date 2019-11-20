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

#ifndef GS2_LOTTERY_MODEL_BOX_HPP_
#define GS2_LOTTERY_MODEL_BOX_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * ボックス
 *
 * @author Game Server Services, Inc.
 *
 */
class Box : public Gs2Object
{
    friend bool operator!=(const Box& lhs, const Box& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ボックス */
        optional<StringHolder> boxId;
        /** 排出確率テーブル名 */
        optional<StringHolder> prizeTableName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 排出済み景品のインデックスのリスト */
        optional<List<Int32>> drawnIndexes;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            boxId(data.boxId),
            prizeTableName(data.prizeTableName),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.drawnIndexes)
            {
                drawnIndexes = data.drawnIndexes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "boxId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->boxId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "drawnIndexes") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->drawnIndexes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt())
                        {
                            *this->drawnIndexes += json->GetInt();
                        }
                    }
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
    Box() = default;
    Box(const Box& box) = default;
    Box(Box&& box) = default;
    ~Box() = default;

    Box& operator=(const Box& box) = default;
    Box& operator=(Box&& box) = default;

    Box deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Box);
    }

    const Box* operator->() const
    {
        return this;
    }

    Box* operator->()
    {
        return this;
    }
    /**
     * ボックスを取得
     *
     * @return ボックス
     */
    const optional<StringHolder>& getBoxId() const
    {
        return ensureData().boxId;
    }

    /**
     * ボックスを設定
     *
     * @param boxId ボックス
     */
    void setBoxId(StringHolder boxId)
    {
        ensureData().boxId.emplace(std::move(boxId));
    }

    /**
     * ボックスを設定
     *
     * @param boxId ボックス
     */
    Box& withBoxId(StringHolder boxId)
    {
        setBoxId(std::move(boxId));
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    Box& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
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
    Box& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 排出済み景品のインデックスのリストを取得
     *
     * @return 排出済み景品のインデックスのリスト
     */
    const optional<List<Int32>>& getDrawnIndexes() const
    {
        return ensureData().drawnIndexes;
    }

    /**
     * 排出済み景品のインデックスのリストを設定
     *
     * @param drawnIndexes 排出済み景品のインデックスのリスト
     */
    void setDrawnIndexes(List<Int32> drawnIndexes)
    {
        ensureData().drawnIndexes.emplace(std::move(drawnIndexes));
    }

    /**
     * 排出済み景品のインデックスのリストを設定
     *
     * @param drawnIndexes 排出済み景品のインデックスのリスト
     */
    Box& withDrawnIndexes(List<Int32> drawnIndexes)
    {
        setDrawnIndexes(std::move(drawnIndexes));
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
    Box& withCreatedAt(Int64 createdAt)
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
    Box& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Box& lhs, const Box& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->boxId != lhr.m_pData->boxId)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->drawnIndexes != lhr.m_pData->drawnIndexes)
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

inline bool operator==(const Box& lhs, const Box& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_BOX_HPP_