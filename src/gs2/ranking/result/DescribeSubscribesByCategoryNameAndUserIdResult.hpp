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

#ifndef GS2_RANKING_CONTROL_DESCRIBESUBSCRIBESBYCATEGORYNAMEANDUSERIDRESULT_HPP_
#define GS2_RANKING_CONTROL_DESCRIBESUBSCRIBESBYCATEGORYNAMEANDUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * ユーザIDを指定して購読しているユーザIDの一覧取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeSubscribesByCategoryNameAndUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 購読対象のリスト */
        optional<List<SubscribeUser>> items;

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
                        SubscribeUser item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeSubscribesByCategoryNameAndUserIdResult() = default;
    DescribeSubscribesByCategoryNameAndUserIdResult(const DescribeSubscribesByCategoryNameAndUserIdResult& describeSubscribesByCategoryNameAndUserIdResult) = default;
    DescribeSubscribesByCategoryNameAndUserIdResult(DescribeSubscribesByCategoryNameAndUserIdResult&& describeSubscribesByCategoryNameAndUserIdResult) = default;
    ~DescribeSubscribesByCategoryNameAndUserIdResult() = default;

    DescribeSubscribesByCategoryNameAndUserIdResult& operator=(const DescribeSubscribesByCategoryNameAndUserIdResult& describeSubscribesByCategoryNameAndUserIdResult) = default;
    DescribeSubscribesByCategoryNameAndUserIdResult& operator=(DescribeSubscribesByCategoryNameAndUserIdResult&& describeSubscribesByCategoryNameAndUserIdResult) = default;

    DescribeSubscribesByCategoryNameAndUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeSubscribesByCategoryNameAndUserIdResult);
    }

    const DescribeSubscribesByCategoryNameAndUserIdResult* operator->() const
    {
        return this;
    }

    DescribeSubscribesByCategoryNameAndUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 購読対象のリストを取得
     *
     * @return 購読対象のリスト
     */
    const optional<List<SubscribeUser>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 購読対象のリストを設定
     *
     * @param items 購読対象のリスト
     */
    void setItems(List<SubscribeUser> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeSubscribesByCategoryNameAndUserIdResult> AsyncDescribeSubscribesByCategoryNameAndUserIdResult;

} }

#endif //GS2_RANKING_CONTROL_DESCRIBESUBSCRIBESBYCATEGORYNAMEANDUSERIDRESULT_HPP_