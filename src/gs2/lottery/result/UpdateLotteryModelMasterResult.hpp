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

#ifndef GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERRESULT_HPP_
#define GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * 抽選の種類マスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateLotteryModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した抽選の種類マスター */
        optional<LotteryModelMaster> item;

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
    UpdateLotteryModelMasterResult() = default;
    UpdateLotteryModelMasterResult(const UpdateLotteryModelMasterResult& updateLotteryModelMasterResult) = default;
    UpdateLotteryModelMasterResult(UpdateLotteryModelMasterResult&& updateLotteryModelMasterResult) = default;
    ~UpdateLotteryModelMasterResult() = default;

    UpdateLotteryModelMasterResult& operator=(const UpdateLotteryModelMasterResult& updateLotteryModelMasterResult) = default;
    UpdateLotteryModelMasterResult& operator=(UpdateLotteryModelMasterResult&& updateLotteryModelMasterResult) = default;

    UpdateLotteryModelMasterResult deepCopy() const;

    const UpdateLotteryModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateLotteryModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した抽選の種類マスターを取得
     *
     * @return 更新した抽選の種類マスター
     */
    const optional<LotteryModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した抽選の種類マスターを設定
     *
     * @param item 更新した抽選の種類マスター
     */
    void setItem(LotteryModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateLotteryModelMasterResult> AsyncUpdateLotteryModelMasterResult;

} }

#endif //GS2_LOTTERY_CONTROL_UPDATELOTTERYMODELMASTERRESULT_HPP_