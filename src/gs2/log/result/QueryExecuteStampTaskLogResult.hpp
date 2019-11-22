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

#ifndef GS2_LOG_CONTROL_QUERYEXECUTESTAMPTASKLOGRESULT_HPP_
#define GS2_LOG_CONTROL_QUERYEXECUTESTAMPTASKLOGRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/log/model/model.hpp>
#include <memory>

namespace gs2 { namespace log
{

/**
 * スタンプタスク実行ログの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class QueryExecuteStampTaskLogResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプタスク実行ログのリスト */
        optional<List<ExecuteStampTaskLog>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;
        /** クエリ結果の総件数 */
        optional<Int64> totalCount;
        /** 検索時にスキャンした総容量 */
        optional<Int64> scanSize;

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
    QueryExecuteStampTaskLogResult() = default;
    QueryExecuteStampTaskLogResult(const QueryExecuteStampTaskLogResult& queryExecuteStampTaskLogResult) = default;
    QueryExecuteStampTaskLogResult(QueryExecuteStampTaskLogResult&& queryExecuteStampTaskLogResult) = default;
    ~QueryExecuteStampTaskLogResult() = default;

    QueryExecuteStampTaskLogResult& operator=(const QueryExecuteStampTaskLogResult& queryExecuteStampTaskLogResult) = default;
    QueryExecuteStampTaskLogResult& operator=(QueryExecuteStampTaskLogResult&& queryExecuteStampTaskLogResult) = default;

    QueryExecuteStampTaskLogResult deepCopy() const;

    const QueryExecuteStampTaskLogResult* operator->() const
    {
        return this;
    }

    QueryExecuteStampTaskLogResult* operator->()
    {
        return this;
    }
    /**
     * スタンプタスク実行ログのリストを取得
     *
     * @return スタンプタスク実行ログのリスト
     */
    const optional<List<ExecuteStampTaskLog>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * スタンプタスク実行ログのリストを設定
     *
     * @param items スタンプタスク実行ログのリスト
     */
    void setItems(List<ExecuteStampTaskLog> items)
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

typedef AsyncResult<QueryExecuteStampTaskLogResult> AsyncQueryExecuteStampTaskLogResult;

} }

#endif //GS2_LOG_CONTROL_QUERYEXECUTESTAMPTASKLOGRESULT_HPP_