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

#ifndef GS2_EZ_INVENTORY_EZLISTITEMMODELSRESULT_HPP_
#define GS2_EZ_INVENTORY_EZLISTITEMMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/DescribeItemModelsResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzListItemModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** アイテムモデルのリスト */
        List<EzItemModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::DescribeItemModelsResult& describeItemModelsResult)
        {
            if (describeItemModelsResult.getItems())
            {
                auto& list = *describeItemModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzItemModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListItemModelsResult() = default;
    EzListItemModelsResult(const EzListItemModelsResult& result) = default;
    EzListItemModelsResult(EzListItemModelsResult&& result) = default;
    ~EzListItemModelsResult() = default;

    EzListItemModelsResult(gs2::inventory::DescribeItemModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListItemModelsResult& operator=(const EzListItemModelsResult& result) = default;
    EzListItemModelsResult& operator=(EzListItemModelsResult&& result) = default;

    EzListItemModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListItemModelsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzItemModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListItemModelsResult> AsyncEzListItemModelsResult;

}}}

#endif //GS2_EZ_INVENTORY_EZLISTITEMMODELSRESULT_HPP_