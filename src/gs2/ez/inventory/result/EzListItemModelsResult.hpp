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
    /** アイテムモデルのリスト */
    List<EzItemModel> m_Items;

public:
    EzListItemModelsResult(const gs2::inventory::DescribeItemModelsResult& result)
    {
        {
            auto& list = *result.getItems();
            for (int i = 0; i < list.getCount(); ++i)
            {
                m_Items += EzItemModel(list[i]);
            }
        }
    }

    static bool isConvertible(const gs2::inventory::DescribeItemModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzItemModel>& getItems() const
    {
        return m_Items;
    }

    List<EzItemModel>& getItems()
    {
        return m_Items;
    }
};

typedef gs2::AsyncResult<EzListItemModelsResult> AsyncEzListItemModelsResult;

}}}

#endif //GS2_EZ_INVENTORY_EZLISTITEMMODELSRESULT_HPP_