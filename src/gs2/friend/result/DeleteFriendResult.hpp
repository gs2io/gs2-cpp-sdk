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

#ifndef GS2_FRIEND_CONTROL_DELETEFRIENDRESULT_HPP_
#define GS2_FRIEND_CONTROL_DELETEFRIENDRESULT_HPP_

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
 * フレンドを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteFriendResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** フレンドのユーザー */
        optional<FriendUser> item;

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
    DeleteFriendResult() = default;
    DeleteFriendResult(const DeleteFriendResult& deleteFriendResult) = default;
    DeleteFriendResult(DeleteFriendResult&& deleteFriendResult) = default;
    ~DeleteFriendResult() = default;

    DeleteFriendResult& operator=(const DeleteFriendResult& deleteFriendResult) = default;
    DeleteFriendResult& operator=(DeleteFriendResult&& deleteFriendResult) = default;

    DeleteFriendResult deepCopy() const;

    const DeleteFriendResult* operator->() const
    {
        return this;
    }

    DeleteFriendResult* operator->()
    {
        return this;
    }
    /**
     * フレンドのユーザーを取得
     *
     * @return フレンドのユーザー
     */
    const optional<FriendUser>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * フレンドのユーザーを設定
     *
     * @param item フレンドのユーザー
     */
    void setItem(FriendUser item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DeleteFriendResult> AsyncDeleteFriendResult;

} }

#endif //GS2_FRIEND_CONTROL_DELETEFRIENDRESULT_HPP_