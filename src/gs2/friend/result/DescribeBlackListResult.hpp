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

#ifndef GS2_FRIEND_CONTROL_DESCRIBEBLACKLISTRESULT_HPP_
#define GS2_FRIEND_CONTROL_DESCRIBEBLACKLISTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * ブラックリストを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeBlackListResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ブラックリストに登録されたユーザIDリスト */
        optional<List<StringHolder>> items;

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
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->items += std::move(stringHolder);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeBlackListResult() = default;
    DescribeBlackListResult(const DescribeBlackListResult& describeBlackListResult) = default;
    DescribeBlackListResult(DescribeBlackListResult&& describeBlackListResult) = default;
    ~DescribeBlackListResult() = default;

    DescribeBlackListResult& operator=(const DescribeBlackListResult& describeBlackListResult) = default;
    DescribeBlackListResult& operator=(DescribeBlackListResult&& describeBlackListResult) = default;

    DescribeBlackListResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeBlackListResult);
    }

    const DescribeBlackListResult* operator->() const
    {
        return this;
    }

    DescribeBlackListResult* operator->()
    {
        return this;
    }
    /**
     * ブラックリストに登録されたユーザIDリストを取得
     *
     * @return ブラックリストに登録されたユーザIDリスト
     */
    const optional<List<StringHolder>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ブラックリストに登録されたユーザIDリストを設定
     *
     * @param items ブラックリストに登録されたユーザIDリスト
     */
    void setItems(List<StringHolder> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeBlackListResult> AsyncDescribeBlackListResult;

} }

#endif //GS2_FRIEND_CONTROL_DESCRIBEBLACKLISTRESULT_HPP_