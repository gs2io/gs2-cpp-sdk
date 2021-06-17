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

#ifndef GS2_EXCHANGE_CONTROL_DESCRIBEAWAITSBYUSERIDRESULT_HPP_
#define GS2_EXCHANGE_CONTROL_DESCRIBEAWAITSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * 交換待機の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeAwaitsByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換待機のリスト */
        optional<List<Await>> items;
        /** 次のページを取得するためのトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            nextPageToken(data.nextPageToken)
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
                        Await item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "nextPageToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->nextPageToken.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeAwaitsByUserIdResult() = default;
    DescribeAwaitsByUserIdResult(const DescribeAwaitsByUserIdResult& describeAwaitsByUserIdResult) = default;
    DescribeAwaitsByUserIdResult(DescribeAwaitsByUserIdResult&& describeAwaitsByUserIdResult) = default;
    ~DescribeAwaitsByUserIdResult() = default;

    DescribeAwaitsByUserIdResult& operator=(const DescribeAwaitsByUserIdResult& describeAwaitsByUserIdResult) = default;
    DescribeAwaitsByUserIdResult& operator=(DescribeAwaitsByUserIdResult&& describeAwaitsByUserIdResult) = default;

    DescribeAwaitsByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeAwaitsByUserIdResult);
    }

    const DescribeAwaitsByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeAwaitsByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 交換待機のリストを取得
     *
     * @return 交換待機のリスト
     */
    const optional<List<Await>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 交換待機のリストを設定
     *
     * @param items 交換待機のリスト
     */
    void setItems(List<Await> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * 次のページを取得するためのトークンを取得
     *
     * @return 次のページを取得するためのトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * 次のページを取得するためのトークンを設定
     *
     * @param nextPageToken 次のページを取得するためのトークン
     */
    void setNextPageToken(StringHolder nextPageToken)
    {
        ensureData().nextPageToken.emplace(std::move(nextPageToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeAwaitsByUserIdResult> AsyncDescribeAwaitsByUserIdResult;

} }

#endif //GS2_EXCHANGE_CONTROL_DESCRIBEAWAITSBYUSERIDRESULT_HPP_