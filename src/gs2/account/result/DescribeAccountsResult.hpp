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

#ifndef GS2_ACCOUNT_CONTROL_DESCRIBEACCOUNTSRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_DESCRIBEACCOUNTSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/account/model/model.hpp>
#include <memory>

namespace gs2 { namespace account
{

/**
 * ゲームプレイヤーアカウントの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeAccountsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームプレイヤーアカウントのリスト */
        optional<List<Account>> items;
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
    DescribeAccountsResult() = default;
    DescribeAccountsResult(const DescribeAccountsResult& describeAccountsResult) = default;
    DescribeAccountsResult(DescribeAccountsResult&& describeAccountsResult) = default;
    ~DescribeAccountsResult() = default;

    DescribeAccountsResult& operator=(const DescribeAccountsResult& describeAccountsResult) = default;
    DescribeAccountsResult& operator=(DescribeAccountsResult&& describeAccountsResult) = default;

    DescribeAccountsResult deepCopy() const;

    const DescribeAccountsResult* operator->() const
    {
        return this;
    }

    DescribeAccountsResult* operator->()
    {
        return this;
    }
    /**
     * ゲームプレイヤーアカウントのリストを取得
     *
     * @return ゲームプレイヤーアカウントのリスト
     */
    const optional<List<Account>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ゲームプレイヤーアカウントのリストを設定
     *
     * @param items ゲームプレイヤーアカウントのリスト
     */
    void setItems(List<Account> items)
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

typedef AsyncResult<DescribeAccountsResult> AsyncDescribeAccountsResult;

} }

#endif //GS2_ACCOUNT_CONTROL_DESCRIBEACCOUNTSRESULT_HPP_