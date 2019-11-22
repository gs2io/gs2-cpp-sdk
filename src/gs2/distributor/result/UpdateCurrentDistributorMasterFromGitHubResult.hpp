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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERFROMGITHUBRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERFROMGITHUBRESULT_HPP_

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
 * 現在有効な配信設定を更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentDistributorMasterFromGitHubResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な配信設定 */
        optional<CurrentDistributorMaster> item;

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
    UpdateCurrentDistributorMasterFromGitHubResult() = default;
    UpdateCurrentDistributorMasterFromGitHubResult(const UpdateCurrentDistributorMasterFromGitHubResult& updateCurrentDistributorMasterFromGitHubResult) = default;
    UpdateCurrentDistributorMasterFromGitHubResult(UpdateCurrentDistributorMasterFromGitHubResult&& updateCurrentDistributorMasterFromGitHubResult) = default;
    ~UpdateCurrentDistributorMasterFromGitHubResult() = default;

    UpdateCurrentDistributorMasterFromGitHubResult& operator=(const UpdateCurrentDistributorMasterFromGitHubResult& updateCurrentDistributorMasterFromGitHubResult) = default;
    UpdateCurrentDistributorMasterFromGitHubResult& operator=(UpdateCurrentDistributorMasterFromGitHubResult&& updateCurrentDistributorMasterFromGitHubResult) = default;

    UpdateCurrentDistributorMasterFromGitHubResult deepCopy() const;

    const UpdateCurrentDistributorMasterFromGitHubResult* operator->() const
    {
        return this;
    }

    UpdateCurrentDistributorMasterFromGitHubResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な配信設定を取得
     *
     * @return 更新した現在有効な配信設定
     */
    const optional<CurrentDistributorMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な配信設定を設定
     *
     * @param item 更新した現在有効な配信設定
     */
    void setItem(CurrentDistributorMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateCurrentDistributorMasterFromGitHubResult> AsyncUpdateCurrentDistributorMasterFromGitHubResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERFROMGITHUBRESULT_HPP_