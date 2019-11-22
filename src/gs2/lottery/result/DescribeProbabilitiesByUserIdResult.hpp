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

#ifndef GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESBYUSERIDRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESBYUSERIDRESULT_HPP_

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
 * 排出確率を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeProbabilitiesByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品の当選確率リスト */
        optional<List<Probability>> items;

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
    DescribeProbabilitiesByUserIdResult() = default;
    DescribeProbabilitiesByUserIdResult(const DescribeProbabilitiesByUserIdResult& describeProbabilitiesByUserIdResult) = default;
    DescribeProbabilitiesByUserIdResult(DescribeProbabilitiesByUserIdResult&& describeProbabilitiesByUserIdResult) = default;
    ~DescribeProbabilitiesByUserIdResult() = default;

    DescribeProbabilitiesByUserIdResult& operator=(const DescribeProbabilitiesByUserIdResult& describeProbabilitiesByUserIdResult) = default;
    DescribeProbabilitiesByUserIdResult& operator=(DescribeProbabilitiesByUserIdResult&& describeProbabilitiesByUserIdResult) = default;

    DescribeProbabilitiesByUserIdResult deepCopy() const;

    const DescribeProbabilitiesByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeProbabilitiesByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 景品の当選確率リストを取得
     *
     * @return 景品の当選確率リスト
     */
    const optional<List<Probability>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 景品の当選確率リストを設定
     *
     * @param items 景品の当選確率リスト
     */
    void setItems(List<Probability> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeProbabilitiesByUserIdResult> AsyncDescribeProbabilitiesByUserIdResult;

} }

#endif //GS2_LOTTERY_CONTROL_DESCRIBEPROBABILITIESBYUSERIDRESULT_HPP_