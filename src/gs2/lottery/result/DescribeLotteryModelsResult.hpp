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

#ifndef GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_

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
 * 抽選の種類の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeLotteryModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選の種類のリスト */
        optional<List<LotteryModel>> items;

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
    DescribeLotteryModelsResult() = default;
    DescribeLotteryModelsResult(const DescribeLotteryModelsResult& describeLotteryModelsResult) = default;
    DescribeLotteryModelsResult(DescribeLotteryModelsResult&& describeLotteryModelsResult) = default;
    ~DescribeLotteryModelsResult() = default;

    DescribeLotteryModelsResult& operator=(const DescribeLotteryModelsResult& describeLotteryModelsResult) = default;
    DescribeLotteryModelsResult& operator=(DescribeLotteryModelsResult&& describeLotteryModelsResult) = default;

    DescribeLotteryModelsResult deepCopy() const;

    const DescribeLotteryModelsResult* operator->() const
    {
        return this;
    }

    DescribeLotteryModelsResult* operator->()
    {
        return this;
    }
    /**
     * 抽選の種類のリストを取得
     *
     * @return 抽選の種類のリスト
     */
    const optional<List<LotteryModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 抽選の種類のリストを設定
     *
     * @param items 抽選の種類のリスト
     */
    void setItems(List<LotteryModel> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeLotteryModelsResult> AsyncDescribeLotteryModelsResult;

} }

#endif //GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_