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

#ifndef GS2_VERSION_CONTROL_DESCRIBEACCEPTVERSIONSBYUSERIDRESULT_HPP_
#define GS2_VERSION_CONTROL_DESCRIBEACCEPTVERSIONSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/version/model/model.hpp>
#include <memory>

namespace gs2 { namespace version
{

/**
 * 承認したバージョンの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeAcceptVersionsByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 承認したバージョンのリスト */
        optional<List<AcceptVersion>> items;
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
                        AcceptVersion item;
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
    DescribeAcceptVersionsByUserIdResult() = default;
    DescribeAcceptVersionsByUserIdResult(const DescribeAcceptVersionsByUserIdResult& describeAcceptVersionsByUserIdResult) = default;
    DescribeAcceptVersionsByUserIdResult(DescribeAcceptVersionsByUserIdResult&& describeAcceptVersionsByUserIdResult) = default;
    ~DescribeAcceptVersionsByUserIdResult() = default;

    DescribeAcceptVersionsByUserIdResult& operator=(const DescribeAcceptVersionsByUserIdResult& describeAcceptVersionsByUserIdResult) = default;
    DescribeAcceptVersionsByUserIdResult& operator=(DescribeAcceptVersionsByUserIdResult&& describeAcceptVersionsByUserIdResult) = default;

    DescribeAcceptVersionsByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeAcceptVersionsByUserIdResult);
    }

    const DescribeAcceptVersionsByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeAcceptVersionsByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 承認したバージョンのリストを取得
     *
     * @return 承認したバージョンのリスト
     */
    const optional<List<AcceptVersion>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 承認したバージョンのリストを設定
     *
     * @param items 承認したバージョンのリスト
     */
    void setItems(List<AcceptVersion> items)
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

typedef AsyncResult<DescribeAcceptVersionsByUserIdResult> AsyncDescribeAcceptVersionsByUserIdResult;

} }

#endif //GS2_VERSION_CONTROL_DESCRIBEACCEPTVERSIONSBYUSERIDRESULT_HPP_