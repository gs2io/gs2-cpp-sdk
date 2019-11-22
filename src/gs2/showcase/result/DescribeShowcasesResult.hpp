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

#ifndef GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_

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
 * 陳列棚の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeShowcasesResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚のリスト */
        optional<List<Showcase>> items;

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
    DescribeShowcasesResult() = default;
    DescribeShowcasesResult(const DescribeShowcasesResult& describeShowcasesResult) = default;
    DescribeShowcasesResult(DescribeShowcasesResult&& describeShowcasesResult) = default;
    ~DescribeShowcasesResult() = default;

    DescribeShowcasesResult& operator=(const DescribeShowcasesResult& describeShowcasesResult) = default;
    DescribeShowcasesResult& operator=(DescribeShowcasesResult&& describeShowcasesResult) = default;

    DescribeShowcasesResult deepCopy() const;

    const DescribeShowcasesResult* operator->() const
    {
        return this;
    }

    DescribeShowcasesResult* operator->()
    {
        return this;
    }
    /**
     * 陳列棚のリストを取得
     *
     * @return 陳列棚のリスト
     */
    const optional<List<Showcase>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 陳列棚のリストを設定
     *
     * @param items 陳列棚のリスト
     */
    void setItems(List<Showcase> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeShowcasesResult> AsyncDescribeShowcasesResult;

} }

#endif //GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_