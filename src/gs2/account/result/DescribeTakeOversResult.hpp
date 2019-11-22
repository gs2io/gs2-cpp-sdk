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

#ifndef GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERSRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERSRESULT_HPP_

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
 * 引き継ぎ設定の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeTakeOversResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 引き継ぎ設定のリスト */
        optional<List<TakeOver>> items;
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
    DescribeTakeOversResult() = default;
    DescribeTakeOversResult(const DescribeTakeOversResult& describeTakeOversResult) = default;
    DescribeTakeOversResult(DescribeTakeOversResult&& describeTakeOversResult) = default;
    ~DescribeTakeOversResult() = default;

    DescribeTakeOversResult& operator=(const DescribeTakeOversResult& describeTakeOversResult) = default;
    DescribeTakeOversResult& operator=(DescribeTakeOversResult&& describeTakeOversResult) = default;

    DescribeTakeOversResult deepCopy() const;

    const DescribeTakeOversResult* operator->() const
    {
        return this;
    }

    DescribeTakeOversResult* operator->()
    {
        return this;
    }
    /**
     * 引き継ぎ設定のリストを取得
     *
     * @return 引き継ぎ設定のリスト
     */
    const optional<List<TakeOver>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 引き継ぎ設定のリストを設定
     *
     * @param items 引き継ぎ設定のリスト
     */
    void setItems(List<TakeOver> items)
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

typedef AsyncResult<DescribeTakeOversResult> AsyncDescribeTakeOversResult;

} }

#endif //GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERSRESULT_HPP_