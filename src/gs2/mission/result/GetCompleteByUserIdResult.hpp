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

#ifndef GS2_MISSION_CONTROL_GETCOMPLETEBYUSERIDRESULT_HPP_
#define GS2_MISSION_CONTROL_GETCOMPLETEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * ユーザIDを指定して達成状況を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCompleteByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 達成状況 */
        optional<Complete> item;

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
    GetCompleteByUserIdResult() = default;
    GetCompleteByUserIdResult(const GetCompleteByUserIdResult& getCompleteByUserIdResult) = default;
    GetCompleteByUserIdResult(GetCompleteByUserIdResult&& getCompleteByUserIdResult) = default;
    ~GetCompleteByUserIdResult() = default;

    GetCompleteByUserIdResult& operator=(const GetCompleteByUserIdResult& getCompleteByUserIdResult) = default;
    GetCompleteByUserIdResult& operator=(GetCompleteByUserIdResult&& getCompleteByUserIdResult) = default;

    GetCompleteByUserIdResult deepCopy() const;

    const GetCompleteByUserIdResult* operator->() const
    {
        return this;
    }

    GetCompleteByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 達成状況を取得
     *
     * @return 達成状況
     */
    const optional<Complete>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 達成状況を設定
     *
     * @param item 達成状況
     */
    void setItem(Complete item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetCompleteByUserIdResult> AsyncGetCompleteByUserIdResult;

} }

#endif //GS2_MISSION_CONTROL_GETCOMPLETEBYUSERIDRESULT_HPP_