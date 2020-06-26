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

#ifndef GS2_MATCHMAKING_MODEL_BALLOT_HPP_
#define GS2_MATCHMAKING_MODEL_BALLOT_HPP_

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
 * 投票用紙
 *
 * @author Game Server Services, Inc.
 *
 */
class Ballot : public Gs2Object
{
    friend bool operator!=(const Ballot& lhs, const Ballot& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** レーティング計算に使用するレーティング名 */
        optional<StringHolder> ratingName;
        /** 投票対象のギャザリング名 */
        optional<StringHolder> gatheringName;
        /** 参加人数 */
        optional<Int32> numberOfPlayer;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            ratingName(data.ratingName),
            gatheringName(data.gatheringName),
            numberOfPlayer(data.numberOfPlayer)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ratingName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ratingName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "gatheringName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->gatheringName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "numberOfPlayer") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->numberOfPlayer = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Ballot() = default;
    Ballot(const Ballot& ballot) = default;
    Ballot(Ballot&& ballot) = default;
    ~Ballot() = default;

    Ballot& operator=(const Ballot& ballot) = default;
    Ballot& operator=(Ballot&& ballot) = default;

    Ballot deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Ballot);
    }

    const Ballot* operator->() const
    {
        return this;
    }

    Ballot* operator->()
    {
        return this;
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
    Ballot& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * レーティング計算に使用するレーティング名を取得
     *
     * @return レーティング計算に使用するレーティング名
     */
    const optional<StringHolder>& getRatingName() const
    {
        return ensureData().ratingName;
    }

    /**
     * レーティング計算に使用するレーティング名を設定
     *
     * @param ratingName レーティング計算に使用するレーティング名
     */
    void setRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
    }

    /**
     * レーティング計算に使用するレーティング名を設定
     *
     * @param ratingName レーティング計算に使用するレーティング名
     */
    Ballot& withRatingName(StringHolder ratingName)
    {
        setRatingName(std::move(ratingName));
        return *this;
    }

    /**
     * 投票対象のギャザリング名を取得
     *
     * @return 投票対象のギャザリング名
     */
    const optional<StringHolder>& getGatheringName() const
    {
        return ensureData().gatheringName;
    }

    /**
     * 投票対象のギャザリング名を設定
     *
     * @param gatheringName 投票対象のギャザリング名
     */
    void setGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
    }

    /**
     * 投票対象のギャザリング名を設定
     *
     * @param gatheringName 投票対象のギャザリング名
     */
    Ballot& withGatheringName(StringHolder gatheringName)
    {
        setGatheringName(std::move(gatheringName));
        return *this;
    }

    /**
     * 参加人数を取得
     *
     * @return 参加人数
     */
    const optional<Int32>& getNumberOfPlayer() const
    {
        return ensureData().numberOfPlayer;
    }

    /**
     * 参加人数を設定
     *
     * @param numberOfPlayer 参加人数
     */
    void setNumberOfPlayer(Int32 numberOfPlayer)
    {
        ensureData().numberOfPlayer.emplace(numberOfPlayer);
    }

    /**
     * 参加人数を設定
     *
     * @param numberOfPlayer 参加人数
     */
    Ballot& withNumberOfPlayer(Int32 numberOfPlayer)
    {
        setNumberOfPlayer(numberOfPlayer);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Ballot& lhs, const Ballot& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->ratingName != lhr.m_pData->ratingName)
        {
            return true;
        }
        if (lhs.m_pData->gatheringName != lhr.m_pData->gatheringName)
        {
            return true;
        }
        if (lhs.m_pData->numberOfPlayer != lhr.m_pData->numberOfPlayer)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Ballot& lhs, const Ballot& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_BALLOT_HPP_