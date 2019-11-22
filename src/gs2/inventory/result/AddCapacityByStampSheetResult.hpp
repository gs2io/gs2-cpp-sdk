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

#ifndef GS2_INVENTORY_CONTROL_ADDCAPACITYBYSTAMPSHEETRESULT_HPP_
#define GS2_INVENTORY_CONTROL_ADDCAPACITYBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * スタンプシートでキャパシティサイズを加算 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AddCapacityByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** キャパシティ加算後のインベントリ */
        optional<Inventory> item;

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
    AddCapacityByStampSheetResult() = default;
    AddCapacityByStampSheetResult(const AddCapacityByStampSheetResult& addCapacityByStampSheetResult) = default;
    AddCapacityByStampSheetResult(AddCapacityByStampSheetResult&& addCapacityByStampSheetResult) = default;
    ~AddCapacityByStampSheetResult() = default;

    AddCapacityByStampSheetResult& operator=(const AddCapacityByStampSheetResult& addCapacityByStampSheetResult) = default;
    AddCapacityByStampSheetResult& operator=(AddCapacityByStampSheetResult&& addCapacityByStampSheetResult) = default;

    AddCapacityByStampSheetResult deepCopy() const;

    const AddCapacityByStampSheetResult* operator->() const
    {
        return this;
    }

    AddCapacityByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * キャパシティ加算後のインベントリを取得
     *
     * @return キャパシティ加算後のインベントリ
     */
    const optional<Inventory>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * キャパシティ加算後のインベントリを設定
     *
     * @param item キャパシティ加算後のインベントリ
     */
    void setItem(Inventory item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<AddCapacityByStampSheetResult> AsyncAddCapacityByStampSheetResult;

} }

#endif //GS2_INVENTORY_CONTROL_ADDCAPACITYBYSTAMPSHEETRESULT_HPP_