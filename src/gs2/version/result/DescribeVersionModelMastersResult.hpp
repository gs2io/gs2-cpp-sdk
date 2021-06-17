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

#ifndef GS2_VERSION_CONTROL_DESCRIBEVERSIONMODELMASTERSRESULT_HPP_
#define GS2_VERSION_CONTROL_DESCRIBEVERSIONMODELMASTERSRESULT_HPP_

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
 * バージョンマスターの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeVersionModelMastersResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** バージョンマスターのリスト */
        optional<List<VersionModelMaster>> items;
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
                        VersionModelMaster item_;
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
    DescribeVersionModelMastersResult() = default;
    DescribeVersionModelMastersResult(const DescribeVersionModelMastersResult& describeVersionModelMastersResult) = default;
    DescribeVersionModelMastersResult(DescribeVersionModelMastersResult&& describeVersionModelMastersResult) = default;
    ~DescribeVersionModelMastersResult() = default;

    DescribeVersionModelMastersResult& operator=(const DescribeVersionModelMastersResult& describeVersionModelMastersResult) = default;
    DescribeVersionModelMastersResult& operator=(DescribeVersionModelMastersResult&& describeVersionModelMastersResult) = default;

    DescribeVersionModelMastersResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeVersionModelMastersResult);
    }

    const DescribeVersionModelMastersResult* operator->() const
    {
        return this;
    }

    DescribeVersionModelMastersResult* operator->()
    {
        return this;
    }
    /**
     * バージョンマスターのリストを取得
     *
     * @return バージョンマスターのリスト
     */
    const optional<List<VersionModelMaster>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * バージョンマスターのリストを設定
     *
     * @param items バージョンマスターのリスト
     */
    void setItems(List<VersionModelMaster> items)
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

typedef AsyncResult<DescribeVersionModelMastersResult> AsyncDescribeVersionModelMastersResult;

} }

#endif //GS2_VERSION_CONTROL_DESCRIBEVERSIONMODELMASTERSRESULT_HPP_