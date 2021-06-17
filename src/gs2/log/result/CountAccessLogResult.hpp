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

#ifndef GS2_LOG_CONTROL_COUNTACCESSLOGRESULT_HPP_
#define GS2_LOG_CONTROL_COUNTACCESSLOGRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/log/model/model.hpp>
#include <memory>

namespace gs2 { namespace log
{

/**
 * アクセスログの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CountAccessLogResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アクセスログ集計のリスト */
        optional<List<AccessLogCount>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;
        /** クエリ結果の総件数 */
        optional<Int64> totalCount;
        /** 検索時にスキャンした総容量 */
        optional<Int64> scanSize;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            nextPageToken(data.nextPageToken),
            totalCount(data.totalCount),
            scanSize(data.scanSize)
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
                        AccessLogCount item_;
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
            else if (std::strcmp(name_, "totalCount") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->totalCount = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "scanSize") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->scanSize = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CountAccessLogResult() = default;
    CountAccessLogResult(const CountAccessLogResult& countAccessLogResult) = default;
    CountAccessLogResult(CountAccessLogResult&& countAccessLogResult) = default;
    ~CountAccessLogResult() = default;

    CountAccessLogResult& operator=(const CountAccessLogResult& countAccessLogResult) = default;
    CountAccessLogResult& operator=(CountAccessLogResult&& countAccessLogResult) = default;

    CountAccessLogResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CountAccessLogResult);
    }

    const CountAccessLogResult* operator->() const
    {
        return this;
    }

    CountAccessLogResult* operator->()
    {
        return this;
    }
    /**
     * アクセスログ集計のリストを取得
     *
     * @return アクセスログ集計のリスト
     */
    const optional<List<AccessLogCount>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * アクセスログ集計のリストを設定
     *
     * @param items アクセスログ集計のリスト
     */
    void setItems(List<AccessLogCount> items)
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

    /**
     * クエリ結果の総件数を取得
     *
     * @return クエリ結果の総件数
     */
    const optional<Int64>& getTotalCount() const
    {
        return ensureData().totalCount;
    }

    /**
     * クエリ結果の総件数を設定
     *
     * @param totalCount クエリ結果の総件数
     */
    void setTotalCount(Int64 totalCount)
    {
        ensureData().totalCount.emplace(totalCount);
    }

    /**
     * 検索時にスキャンした総容量を取得
     *
     * @return 検索時にスキャンした総容量
     */
    const optional<Int64>& getScanSize() const
    {
        return ensureData().scanSize;
    }

    /**
     * 検索時にスキャンした総容量を設定
     *
     * @param scanSize 検索時にスキャンした総容量
     */
    void setScanSize(Int64 scanSize)
    {
        ensureData().scanSize.emplace(scanSize);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CountAccessLogResult> AsyncCountAccessLogResult;

} }

#endif //GS2_LOG_CONTROL_COUNTACCESSLOGRESULT_HPP_