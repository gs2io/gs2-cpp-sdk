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

#ifndef GS2_MATCHMAKING_MODEL_VOTE_HPP_
#define GS2_MATCHMAKING_MODEL_VOTE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "WrittenBallot.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * 投票状況
 *
 * @author Game Server Services, Inc.
 *
 */
class Vote : public Gs2Object
{
    friend bool operator!=(const Vote& lhs, const Vote& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 投票状況 */
        optional<StringHolder> voteId;
        /** レーティング名 */
        optional<StringHolder> ratingName;
        /** レーティング名 */
        optional<StringHolder> gatheringName;
        /** 投票用紙のリスト */
        optional<List<WrittenBallot>> writtenBallots;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            voteId(data.voteId),
            ratingName(data.ratingName),
            gatheringName(data.gatheringName),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.writtenBallots)
            {
                writtenBallots = data.writtenBallots->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "voteId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->voteId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "writtenBallots") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->writtenBallots.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        WrittenBallot item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->writtenBallots += std::move(item);
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
    Vote() = default;
    Vote(const Vote& vote) = default;
    Vote(Vote&& vote) = default;
    ~Vote() = default;

    Vote& operator=(const Vote& vote) = default;
    Vote& operator=(Vote&& vote) = default;

    Vote deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Vote);
    }

    const Vote* operator->() const
    {
        return this;
    }

    Vote* operator->()
    {
        return this;
    }
    /**
     * 投票状況を取得
     *
     * @return 投票状況
     */
    const optional<StringHolder>& getVoteId() const
    {
        return ensureData().voteId;
    }

    /**
     * 投票状況を設定
     *
     * @param voteId 投票状況
     */
    void setVoteId(StringHolder voteId)
    {
        ensureData().voteId.emplace(std::move(voteId));
    }

    /**
     * 投票状況を設定
     *
     * @param voteId 投票状況
     */
    Vote& withVoteId(StringHolder voteId)
    {
        setVoteId(std::move(voteId));
        return *this;
    }

    /**
     * レーティング名を取得
     *
     * @return レーティング名
     */
    const optional<StringHolder>& getRatingName() const
    {
        return ensureData().ratingName;
    }

    /**
     * レーティング名を設定
     *
     * @param ratingName レーティング名
     */
    void setRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
    }

    /**
     * レーティング名を設定
     *
     * @param ratingName レーティング名
     */
    Vote& withRatingName(StringHolder ratingName)
    {
        setRatingName(std::move(ratingName));
        return *this;
    }

    /**
     * レーティング名を取得
     *
     * @return レーティング名
     */
    const optional<StringHolder>& getGatheringName() const
    {
        return ensureData().gatheringName;
    }

    /**
     * レーティング名を設定
     *
     * @param gatheringName レーティング名
     */
    void setGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
    }

    /**
     * レーティング名を設定
     *
     * @param gatheringName レーティング名
     */
    Vote& withGatheringName(StringHolder gatheringName)
    {
        setGatheringName(std::move(gatheringName));
        return *this;
    }

    /**
     * 投票用紙のリストを取得
     *
     * @return 投票用紙のリスト
     */
    const optional<List<WrittenBallot>>& getWrittenBallots() const
    {
        return ensureData().writtenBallots;
    }

    /**
     * 投票用紙のリストを設定
     *
     * @param writtenBallots 投票用紙のリスト
     */
    void setWrittenBallots(List<WrittenBallot> writtenBallots)
    {
        ensureData().writtenBallots.emplace(std::move(writtenBallots));
    }

    /**
     * 投票用紙のリストを設定
     *
     * @param writtenBallots 投票用紙のリスト
     */
    Vote& withWrittenBallots(List<WrittenBallot> writtenBallots)
    {
        setWrittenBallots(std::move(writtenBallots));
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
    Vote& withCreatedAt(Int64 createdAt)
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
    Vote& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Vote& lhs, const Vote& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->voteId != lhr.m_pData->voteId)
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
        if (lhs.m_pData->writtenBallots != lhr.m_pData->writtenBallots)
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

inline bool operator==(const Vote& lhs, const Vote& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_VOTE_HPP_