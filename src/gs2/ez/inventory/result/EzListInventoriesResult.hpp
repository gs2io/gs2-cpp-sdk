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

#ifndef GS2_EZ_INVENTORY_EZLISTINVENTORIESRESULT_HPP_
#define GS2_EZ_INVENTORY_EZLISTINVENTORIESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/inventory/result/DescribeInventoriesResult.hpp>


namespace gs2 { namespace ez { namespace inventory {

class EzListInventoriesResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** インベントリのリスト */
        List<EzInventory> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            nextPageToken(data.nextPageToken)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::inventory::DescribeInventoriesResult& describeInventoriesResult) :
            nextPageToken(describeInventoriesResult.getNextPageToken())
        {
            {
                auto& list = *describeInventoriesResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzInventory(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListInventoriesResult() = default;
    EzListInventoriesResult(const EzListInventoriesResult& result) = default;
    EzListInventoriesResult(EzListInventoriesResult&& result) = default;
    ~EzListInventoriesResult() = default;

    EzListInventoriesResult(gs2::inventory::DescribeInventoriesResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListInventoriesResult& operator=(const EzListInventoriesResult& result) = default;
    EzListInventoriesResult& operator=(EzListInventoriesResult&& result) = default;

    EzListInventoriesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListInventoriesResult);
    }

    static bool isConvertible(const gs2::inventory::DescribeInventoriesResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzInventory>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzListInventoriesResult> AsyncEzListInventoriesResult;

}}}

#endif //GS2_EZ_INVENTORY_EZLISTINVENTORIESRESULT_HPP_