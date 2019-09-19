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

#ifndef GS2_DEPLOY_CONTROL_DESCRIBERESOURCESRESULT_HPP_
#define GS2_DEPLOY_CONTROL_DESCRIBERESOURCESRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace deploy
{

/**
 * 作成されたのリソースの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeResourcesResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成されたのリソースのリスト */
        optional<List<Resource>> items;
        /** リストの続きを取得するためのページトークン */
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
                        Resource item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
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
    DescribeResourcesResult() = default;
    DescribeResourcesResult(const DescribeResourcesResult& describeResourcesResult) = default;
    DescribeResourcesResult(DescribeResourcesResult&& describeResourcesResult) = default;
    ~DescribeResourcesResult() = default;

    DescribeResourcesResult& operator=(const DescribeResourcesResult& describeResourcesResult) = default;
    DescribeResourcesResult& operator=(DescribeResourcesResult&& describeResourcesResult) = default;

    DescribeResourcesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeResourcesResult);
    }

    const DescribeResourcesResult* operator->() const
    {
        return this;
    }

    DescribeResourcesResult* operator->()
    {
        return this;
    }
    /**
     * 作成されたのリソースのリストを取得
     *
     * @return 作成されたのリソースのリスト
     */
    const optional<List<Resource>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 作成されたのリソースのリストを設定
     *
     * @param items 作成されたのリソースのリスト
     */
    void setItems(List<Resource> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * リストの続きを取得するためのページトークンを取得
     *
     * @return リストの続きを取得するためのページトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * リストの続きを取得するためのページトークンを設定
     *
     * @param nextPageToken リストの続きを取得するためのページトークン
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

typedef AsyncResult<DescribeResourcesResult> AsyncDescribeResourcesResult;

} }

#endif //GS2_DEPLOY_CONTROL_DESCRIBERESOURCESRESULT_HPP_