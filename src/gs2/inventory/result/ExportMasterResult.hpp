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

#ifndef GS2_INVENTORY_CONTROL_EXPORTMASTERRESULT_HPP_
#define GS2_INVENTORY_CONTROL_EXPORTMASTERRESULT_HPP_

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
 * 現在有効な所持品マスターのマスターデータをエクスポートします のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ExportMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在有効な所持品マスター */
        optional<CurrentItemModelMaster> item;

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
    ExportMasterResult() = default;
    ExportMasterResult(const ExportMasterResult& exportMasterResult) = default;
    ExportMasterResult(ExportMasterResult&& exportMasterResult) = default;
    ~ExportMasterResult() = default;

    ExportMasterResult& operator=(const ExportMasterResult& exportMasterResult) = default;
    ExportMasterResult& operator=(ExportMasterResult&& exportMasterResult) = default;

    ExportMasterResult deepCopy() const;

    const ExportMasterResult* operator->() const
    {
        return this;
    }

    ExportMasterResult* operator->()
    {
        return this;
    }
    /**
     * 現在有効な所持品マスターを取得
     *
     * @return 現在有効な所持品マスター
     */
    const optional<CurrentItemModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在有効な所持品マスターを設定
     *
     * @param item 現在有効な所持品マスター
     */
    void setItem(CurrentItemModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;

} }

#endif //GS2_INVENTORY_CONTROL_EXPORTMASTERRESULT_HPP_