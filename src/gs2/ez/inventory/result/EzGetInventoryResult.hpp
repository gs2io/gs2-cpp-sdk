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

#ifndef GS2_EZ_INVENTORY_EZGETINVENTORYRESULT_HPP_
#define GS2_EZ_INVENTORY_EZGETINVENTORYRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/GetInventoryResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzGetInventoryResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリ */
        EzInventory item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::GetInventoryResult& getInventoryResult) :
            item(*getInventoryResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetInventoryResult() = default;
    EzGetInventoryResult(const EzGetInventoryResult& result) = default;
    EzGetInventoryResult(EzGetInventoryResult&& result) = default;
    ~EzGetInventoryResult() = default;

    EzGetInventoryResult(gs2::inventory::GetInventoryResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetInventoryResult& operator=(const EzGetInventoryResult& result) = default;
    EzGetInventoryResult& operator=(EzGetInventoryResult&& result) = default;

    EzGetInventoryResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetInventoryResult);
    }

    static bool isConvertible(const gs2::inventory::GetInventoryResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzInventory& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetInventoryResult> AsyncEzGetInventoryResult;

}}}

#endif //GS2_EZ_INVENTORY_EZGETINVENTORYRESULT_HPP_