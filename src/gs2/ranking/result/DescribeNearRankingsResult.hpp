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

#ifndef GS2_RANKING_CONTROL_DESCRIBENEARRANKINGSRESULT_HPP_
#define GS2_RANKING_CONTROL_DESCRIBENEARRANKINGSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * 指定したスコア付近のランキングを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeNearRankingsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ランキングのリスト */
        optional<List<Ranking>> items;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Ranking item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeNearRankingsResult() = default;
    DescribeNearRankingsResult(const DescribeNearRankingsResult& describeNearRankingsResult) = default;
    DescribeNearRankingsResult(DescribeNearRankingsResult&& describeNearRankingsResult) = default;
    ~DescribeNearRankingsResult() = default;

    DescribeNearRankingsResult& operator=(const DescribeNearRankingsResult& describeNearRankingsResult) = default;
    DescribeNearRankingsResult& operator=(DescribeNearRankingsResult&& describeNearRankingsResult) = default;

    DescribeNearRankingsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeNearRankingsResult);
    }

    const DescribeNearRankingsResult* operator->() const
    {
        return this;
    }

    DescribeNearRankingsResult* operator->()
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeNearRankingsResult> AsyncDescribeNearRankingsResult;

} }

#endif //GS2_RANKING_CONTROL_DESCRIBENEARRANKINGSRESULT_HPP_