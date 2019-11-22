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

#ifndef GS2_FRIEND_CONTROL_REJECTREQUESTBYUSERIDRESULT_HPP_
#define GS2_FRIEND_CONTROL_REJECTREQUESTBYUSERIDRESULT_HPP_

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
 * ユーザーIDを指定してフレンドリクエストを拒否 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RejectRequestByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 拒否したフレンドリクエスト */
        optional<FriendRequest> item;

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
    RejectRequestByUserIdResult() = default;
    RejectRequestByUserIdResult(const RejectRequestByUserIdResult& rejectRequestByUserIdResult) = default;
    RejectRequestByUserIdResult(RejectRequestByUserIdResult&& rejectRequestByUserIdResult) = default;
    ~RejectRequestByUserIdResult() = default;

    RejectRequestByUserIdResult& operator=(const RejectRequestByUserIdResult& rejectRequestByUserIdResult) = default;
    RejectRequestByUserIdResult& operator=(RejectRequestByUserIdResult&& rejectRequestByUserIdResult) = default;

    RejectRequestByUserIdResult deepCopy() const;

    const RejectRequestByUserIdResult* operator->() const
    {
        return this;
    }

    RejectRequestByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 拒否したフレンドリクエストを取得
     *
     * @return 拒否したフレンドリクエスト
     */
    const optional<FriendRequest>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 拒否したフレンドリクエストを設定
     *
     * @param item 拒否したフレンドリクエスト
     */
    void setItem(FriendRequest item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RejectRequestByUserIdResult> AsyncRejectRequestByUserIdResult;

} }

#endif //GS2_FRIEND_CONTROL_REJECTREQUESTBYUSERIDRESULT_HPP_