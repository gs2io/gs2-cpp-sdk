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

#ifndef GS2_RANKING_CONTROL_DESCRIBERANKINGSSBYUSERIDRESULT_HPP_
#define GS2_RANKING_CONTROL_DESCRIBERANKINGSSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * ユーザIDを指定してランキングを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeRankingssByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ランキングのリスト */
        optional<List<Ranking>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeRankingssByUserIdResult() = default;
    DescribeRankingssByUserIdResult(const DescribeRankingssByUserIdResult& describeRankingssByUserIdResult) = default;
    DescribeRankingssByUserIdResult(DescribeRankingssByUserIdResult&& describeRankingssByUserIdResult) = default;
    ~DescribeRankingssByUserIdResult() = default;

    DescribeRankingssByUserIdResult& operator=(const DescribeRankingssByUserIdResult& describeRankingssByUserIdResult) = default;
    DescribeRankingssByUserIdResult& operator=(DescribeRankingssByUserIdResult&& describeRankingssByUserIdResult) = default;

    DescribeRankingssByUserIdResult deepCopy() const;

    const DescribeRankingssByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeRankingssByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * ランキングのリストを取得
     *
     * @return ランキングのリスト
     */
    const optional<List<Ranking>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ランキングのリストを設定
     *
     * @param items ランキングのリスト
     */
    void setItems(List<Ranking> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * リストの続きを取得するためのページトークンを取得
     *
     * @return リストの続きを取得するためのページトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * リストの続きを取得するためのページトークンを設定
     *
     * @param nextPageToken リストの続きを取得するためのページトークン
     */
    void setNextPageToken(StringHolder nextPageToken)
    {
        ensureData().nextPageToken.emplace(std::move(nextPageToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeRankingssByUserIdResult> AsyncDescribeRankingssByUserIdResult;

} }

#endif //GS2_RANKING_CONTROL_DESCRIBERANKINGSSBYUSERIDRESULT_HPP_