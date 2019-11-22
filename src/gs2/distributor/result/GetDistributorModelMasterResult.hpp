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

#ifndef GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORMODELMASTERRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/distributor/model/model.hpp>
#include <memory>

namespace gs2 { namespace distributor
{

/**
 * 配信設定マスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetDistributorModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 配信設定マスター */
        optional<DistributorModelMaster> item;

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
    GetDistributorModelMasterResult() = default;
    GetDistributorModelMasterResult(const GetDistributorModelMasterResult& getDistributorModelMasterResult) = default;
    GetDistributorModelMasterResult(GetDistributorModelMasterResult&& getDistributorModelMasterResult) = default;
    ~GetDistributorModelMasterResult() = default;

    GetDistributorModelMasterResult& operator=(const GetDistributorModelMasterResult& getDistributorModelMasterResult) = default;
    GetDistributorModelMasterResult& operator=(GetDistributorModelMasterResult&& getDistributorModelMasterResult) = default;

    GetDistributorModelMasterResult deepCopy() const;

    const GetDistributorModelMasterResult* operator->() const
    {
        return this;
    }

    GetDistributorModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 配信設定マスターを取得
     *
     * @return 配信設定マスター
     */
    const optional<DistributorModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 配信設定マスターを設定
     *
     * @param item 配信設定マスター
     */
    void setItem(DistributorModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetDistributorModelMasterResult> AsyncGetDistributorModelMasterResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORMODELMASTERRESULT_HPP_