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

#ifndef GS2_EZ_RANKING_EZLISTSUBSCRIBESRESULT_HPP_
#define GS2_EZ_RANKING_EZLISTSUBSCRIBESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/DescribeSubscribesByCategoryNameResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzListSubscribesResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 購読対象のリスト */
        List<EzSubscribeUser> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::DescribeSubscribesByCategoryNameResult& describeSubscribesByCategoryNameResult)
        {
            if (describeSubscribesByCategoryNameResult.getItems())
            {
                auto& list = *describeSubscribesByCategoryNameResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzSubscribeUser(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListSubscribesResult() = default;
    EzListSubscribesResult(const EzListSubscribesResult& result) = default;
    EzListSubscribesResult(EzListSubscribesResult&& result) = default;
    ~EzListSubscribesResult() = default;

    EzListSubscribesResult(gs2::ranking::DescribeSubscribesByCategoryNameResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListSubscribesResult& operator=(const EzListSubscribesResult& result) = default;
    EzListSubscribesResult& operator=(EzListSubscribesResult&& result) = default;

    EzListSubscribesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListSubscribesResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzSubscribeUser>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListSubscribesResult> AsyncEzListSubscribesResult;

}}}

#endif //GS2_EZ_RANKING_EZLISTSUBSCRIBESRESULT_HPP_