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

#ifndef GS2_EZ_INVENTORY_EZLISTINVENTORYMODELSRESULT_HPP_
#define GS2_EZ_INVENTORY_EZLISTINVENTORYMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/DescribeInventoryModelsResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzListInventoryModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリモデルのリスト */
        List<EzInventoryModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::DescribeInventoryModelsResult& describeInventoryModelsResult)
        {
            {
                auto& list = *describeInventoryModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzInventoryModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListInventoryModelsResult() = default;
    EzListInventoryModelsResult(const EzListInventoryModelsResult& result) = default;
    EzListInventoryModelsResult(EzListInventoryModelsResult&& result) = default;
    ~EzListInventoryModelsResult() = default;

    EzListInventoryModelsResult(gs2::inventory::DescribeInventoryModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListInventoryModelsResult& operator=(const EzListInventoryModelsResult& result) = default;
    EzListInventoryModelsResult& operator=(EzListInventoryModelsResult&& result) = default;

    EzListInventoryModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListInventoryModelsResult);
    }

    static bool isConvertible(const gs2::inventory::DescribeInventoryModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzInventoryModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListInventoryModelsResult> AsyncEzListInventoryModelsResult;

}}}

#endif //GS2_EZ_INVENTORY_EZLISTINVENTORYMODELSRESULT_HPP_