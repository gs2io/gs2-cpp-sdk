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

#ifndef GS2_FRIEND_CONTROL_DESCRIBESENDREQUESTSRESULT_HPP_
#define GS2_FRIEND_CONTROL_DESCRIBESENDREQUESTSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * 送信したフレンドリクエストの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeSendRequestsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** フレンドリクエストのリスト */
        optional<List<FriendRequest>> items;

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
    DescribeSendRequestsResult() = default;
    DescribeSendRequestsResult(const DescribeSendRequestsResult& describeSendRequestsResult) = default;
    DescribeSendRequestsResult(DescribeSendRequestsResult&& describeSendRequestsResult) = default;
    ~DescribeSendRequestsResult() = default;

    DescribeSendRequestsResult& operator=(const DescribeSendRequestsResult& describeSendRequestsResult) = default;
    DescribeSendRequestsResult& operator=(DescribeSendRequestsResult&& describeSendRequestsResult) = default;

    DescribeSendRequestsResult deepCopy() const;

    const DescribeSendRequestsResult* operator->() const
    {
        return this;
    }

    DescribeSendRequestsResult* operator->()
    {
        return this;
    }
    /**
     * フレンドリクエストのリストを取得
     *
     * @return フレンドリクエストのリスト
     */
    const optional<List<FriendRequest>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * フレンドリクエストのリストを設定
     *
     * @param items フレンドリクエストのリスト
     */
    void setItems(List<FriendRequest> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeSendRequestsResult> AsyncDescribeSendRequestsResult;

} }

#endif //GS2_FRIEND_CONTROL_DESCRIBESENDREQUESTSRESULT_HPP_