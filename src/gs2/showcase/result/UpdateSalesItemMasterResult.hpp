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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/showcase/model/model.hpp>
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 商品マスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateSalesItemMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した商品マスター */
        optional<SalesItemMaster> item;

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
    UpdateSalesItemMasterResult() = default;
    UpdateSalesItemMasterResult(const UpdateSalesItemMasterResult& updateSalesItemMasterResult) = default;
    UpdateSalesItemMasterResult(UpdateSalesItemMasterResult&& updateSalesItemMasterResult) = default;
    ~UpdateSalesItemMasterResult() = default;

    UpdateSalesItemMasterResult& operator=(const UpdateSalesItemMasterResult& updateSalesItemMasterResult) = default;
    UpdateSalesItemMasterResult& operator=(UpdateSalesItemMasterResult&& updateSalesItemMasterResult) = default;

    UpdateSalesItemMasterResult deepCopy() const;

    const UpdateSalesItemMasterResult* operator->() const
    {
        return this;
    }

    UpdateSalesItemMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した商品マスターを取得
     *
     * @return 更新した商品マスター
     */
    const optional<SalesItemMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した商品マスターを設定
     *
     * @param item 更新した商品マスター
     */
    void setItem(SalesItemMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateSalesItemMasterResult> AsyncUpdateSalesItemMasterResult;

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_