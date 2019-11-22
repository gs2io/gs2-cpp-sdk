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

#ifndef GS2_QUEST_CONTROL_DESCRIBECOMPLETEDQUESTLISTSRESULT_HPP_
#define GS2_QUEST_CONTROL_DESCRIBECOMPLETEDQUESTLISTSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/quest/model/model.hpp>
#include <memory>

namespace gs2 { namespace quest
{

/**
 * クエスト進行の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeCompletedQuestListsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト進行のリスト */
        optional<List<CompletedQuestList>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

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
    DescribeCompletedQuestListsResult() = default;
    DescribeCompletedQuestListsResult(const DescribeCompletedQuestListsResult& describeCompletedQuestListsResult) = default;
    DescribeCompletedQuestListsResult(DescribeCompletedQuestListsResult&& describeCompletedQuestListsResult) = default;
    ~DescribeCompletedQuestListsResult() = default;

    DescribeCompletedQuestListsResult& operator=(const DescribeCompletedQuestListsResult& describeCompletedQuestListsResult) = default;
    DescribeCompletedQuestListsResult& operator=(DescribeCompletedQuestListsResult&& describeCompletedQuestListsResult) = default;

    DescribeCompletedQuestListsResult deepCopy() const;

    const DescribeCompletedQuestListsResult* operator->() const
    {
        return this;
    }

    DescribeCompletedQuestListsResult* operator->()
    {
        return this;
    }
    /**
     * クエスト進行のリストを取得
     *
     * @return クエスト進行のリスト
     */
    const optional<List<CompletedQuestList>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * クエスト進行のリストを設定
     *
     * @param items クエスト進行のリスト
     */
    void setItems(List<CompletedQuestList> items)
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

typedef AsyncResult<DescribeCompletedQuestListsResult> AsyncDescribeCompletedQuestListsResult;

} }

#endif //GS2_QUEST_CONTROL_DESCRIBECOMPLETEDQUESTLISTSRESULT_HPP_