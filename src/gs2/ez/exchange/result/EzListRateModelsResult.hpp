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

#ifndef GS2_EZ_EXCHANGE_EZLISTRATEMODELSRESULT_HPP_
#define GS2_EZ_EXCHANGE_EZLISTRATEMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/exchange/result/DescribeRateModelsResult.hpp>


namespace gs2 { namespace ez { namespace exchange {

class EzListRateModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換レートモデルのリスト */
        List<EzRateModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::exchange::DescribeRateModelsResult& describeRateModelsResult)
        {
            {
                auto& list = *describeRateModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzRateModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListRateModelsResult() = default;
    EzListRateModelsResult(const EzListRateModelsResult& result) = default;
    EzListRateModelsResult(EzListRateModelsResult&& result) = default;
    ~EzListRateModelsResult() = default;

    EzListRateModelsResult(gs2::exchange::DescribeRateModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListRateModelsResult& operator=(const EzListRateModelsResult& result) = default;
    EzListRateModelsResult& operator=(EzListRateModelsResult&& result) = default;

    EzListRateModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListRateModelsResult);
    }

    static bool isConvertible(const gs2::exchange::DescribeRateModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzRateModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListRateModelsResult> AsyncEzListRateModelsResult;

}}}

#endif //GS2_EZ_EXCHANGE_EZLISTRATEMODELSRESULT_HPP_