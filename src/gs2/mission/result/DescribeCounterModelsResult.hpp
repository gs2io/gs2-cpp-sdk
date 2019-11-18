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

#ifndef GS2_MISSION_CONTROL_DESCRIBECOUNTERMODELSRESULT_HPP_
#define GS2_MISSION_CONTROL_DESCRIBECOUNTERMODELSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * カウンターの種類の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeCounterModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターの種類のリスト */
        optional<List<CounterModel>> items;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        CounterModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeCounterModelsResult() = default;
    DescribeCounterModelsResult(const DescribeCounterModelsResult& describeCounterModelsResult) = default;
    DescribeCounterModelsResult(DescribeCounterModelsResult&& describeCounterModelsResult) = default;
    ~DescribeCounterModelsResult() = default;

    DescribeCounterModelsResult& operator=(const DescribeCounterModelsResult& describeCounterModelsResult) = default;
    DescribeCounterModelsResult& operator=(DescribeCounterModelsResult&& describeCounterModelsResult) = default;

    DescribeCounterModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeCounterModelsResult);
    }

    const DescribeCounterModelsResult* operator->() const
    {
        return this;
    }

    DescribeCounterModelsResult* operator->()
    {
        return this;
    }
    /**
     * カウンターの種類のリストを取得
     *
     * @return カウンターの種類のリスト
     */
    const optional<List<CounterModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * カウンターの種類のリストを設定
     *
     * @param items カウンターの種類のリスト
     */
    void setItems(List<CounterModel> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeCounterModelsResult> AsyncDescribeCounterModelsResult;

} }

#endif //GS2_MISSION_CONTROL_DESCRIBECOUNTERMODELSRESULT_HPP_