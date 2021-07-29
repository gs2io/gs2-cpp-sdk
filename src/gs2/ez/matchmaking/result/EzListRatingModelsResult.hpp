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

#ifndef GS2_EZ_MATCHMAKING_EZLISTRATINGMODELSRESULT_HPP_
#define GS2_EZ_MATCHMAKING_EZLISTRATINGMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/matchmaking/result/DescribeRatingModelsResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzListRatingModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** レーティングモデルのリスト */
        List<EzRatingModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::DescribeRatingModelsResult& describeRatingModelsResult)
        {
            if (describeRatingModelsResult.getItems())
            {
                auto& list = *describeRatingModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzRatingModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListRatingModelsResult() = default;
    EzListRatingModelsResult(const EzListRatingModelsResult& result) = default;
    EzListRatingModelsResult(EzListRatingModelsResult&& result) = default;
    ~EzListRatingModelsResult() = default;

    EzListRatingModelsResult(gs2::matchmaking::DescribeRatingModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListRatingModelsResult& operator=(const EzListRatingModelsResult& result) = default;
    EzListRatingModelsResult& operator=(EzListRatingModelsResult&& result) = default;

    EzListRatingModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListRatingModelsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzRatingModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListRatingModelsResult> AsyncEzListRatingModelsResult;

}}}

#endif //GS2_EZ_MATCHMAKING_EZLISTRATINGMODELSRESULT_HPP_