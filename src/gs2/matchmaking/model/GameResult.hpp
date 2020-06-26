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

#ifndef GS2_MATCHMAKING_MODEL_GAMERESULT_HPP_
#define GS2_MATCHMAKING_MODEL_GAMERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * 対戦結果
 *
 * @author Game Server Services, Inc.
 *
 */
class GameResult : public Gs2Object
{
    friend bool operator!=(const GameResult& lhs, const GameResult& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 順位 */
        optional<Int32> rank;
        /** ユーザーID */
        optional<StringHolder> userId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rank(data.rank),
            userId(data.userId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "rank") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->rank = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GameResult() = default;
    GameResult(const GameResult& gameResult) = default;
    GameResult(GameResult&& gameResult) = default;
    ~GameResult() = default;

    GameResult& operator=(const GameResult& gameResult) = default;
    GameResult& operator=(GameResult&& gameResult) = default;

    GameResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GameResult);
    }

    const GameResult* operator->() const
    {
        return this;
    }

    GameResult* operator->()
    {
        return this;
    }
    /**
     * 順位を取得
     *
     * @return 順位
     */
    const optional<Int32>& getRank() const
    {
        return ensureData().rank;
    }

    /**
     * 順位を設定
     *
     * @param rank 順位
     */
    void setRank(Int32 rank)
    {
        ensureData().rank.emplace(rank);
    }

    /**
     * 順位を設定
     *
     * @param rank 順位
     */
    GameResult& withRank(Int32 rank)
    {
        setRank(rank);
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
    GameResult& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const GameResult& lhs, const GameResult& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->rank != lhr.m_pData->rank)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const GameResult& lhs, const GameResult& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_GAMERESULT_HPP_