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

#ifndef GS2_MATCHMAKING_MODEL_WRITTENBALLOT_HPP_
#define GS2_MATCHMAKING_MODEL_WRITTENBALLOT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Ballot.hpp"
#include "GameResult.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * 投票結果
 *
 * @author Game Server Services, Inc.
 *
 */
class WrittenBallot : public Gs2Object
{
    friend bool operator!=(const WrittenBallot& lhs, const WrittenBallot& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 投票用紙 */
        optional<Ballot> ballot;
        /** 投票内容。対戦結果のリスト */
        optional<List<GameResult>> gameResults;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.ballot)
            {
                ballot = data.ballot->deepCopy();
            }
            if (data.gameResults)
            {
                gameResults = data.gameResults->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "ballot") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->ballot.emplace();
                    detail::json::JsonParser::parse(&this->ballot->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "gameResults") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->gameResults.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        GameResult item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->gameResults += std::move(item);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WrittenBallot() = default;
    WrittenBallot(const WrittenBallot& writtenBallot) = default;
    WrittenBallot(WrittenBallot&& writtenBallot) = default;
    ~WrittenBallot() = default;

    WrittenBallot& operator=(const WrittenBallot& writtenBallot) = default;
    WrittenBallot& operator=(WrittenBallot&& writtenBallot) = default;

    WrittenBallot deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WrittenBallot);
    }

    const WrittenBallot* operator->() const
    {
        return this;
    }

    WrittenBallot* operator->()
    {
        return this;
    }
    /**
     * 投票用紙を取得
     *
     * @return 投票用紙
     */
    const optional<Ballot>& getBallot() const
    {
        return ensureData().ballot;
    }

    /**
     * 投票用紙を設定
     *
     * @param ballot 投票用紙
     */
    void setBallot(Ballot ballot)
    {
        ensureData().ballot.emplace(std::move(ballot));
    }

    /**
     * 投票用紙を設定
     *
     * @param ballot 投票用紙
     */
    WrittenBallot& withBallot(Ballot ballot)
    {
        setBallot(std::move(ballot));
        return *this;
    }

    /**
     * 投票内容。対戦結果のリストを取得
     *
     * @return 投票内容。対戦結果のリスト
     */
    const optional<List<GameResult>>& getGameResults() const
    {
        return ensureData().gameResults;
    }

    /**
     * 投票内容。対戦結果のリストを設定
     *
     * @param gameResults 投票内容。対戦結果のリスト
     */
    void setGameResults(List<GameResult> gameResults)
    {
        ensureData().gameResults.emplace(std::move(gameResults));
    }

    /**
     * 投票内容。対戦結果のリストを設定
     *
     * @param gameResults 投票内容。対戦結果のリスト
     */
    WrittenBallot& withGameResults(List<GameResult> gameResults)
    {
        setGameResults(std::move(gameResults));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WrittenBallot& lhs, const WrittenBallot& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->ballot != lhr.m_pData->ballot)
        {
            return true;
        }
        if (lhs.m_pData->gameResults != lhr.m_pData->gameResults)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const WrittenBallot& lhs, const WrittenBallot& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_WRITTENBALLOT_HPP_