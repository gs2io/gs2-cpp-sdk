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

#ifndef GS2_FRIEND_CONTROL_UNFOLLOWRESULT_HPP_
#define GS2_FRIEND_CONTROL_UNFOLLOWRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * アンフォロー のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UnfollowResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アンフォローしたユーザ */
        optional<FollowUser> item;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    UnfollowResult() = default;
    UnfollowResult(const UnfollowResult& unfollowResult) = default;
    UnfollowResult(UnfollowResult&& unfollowResult) = default;
    ~UnfollowResult() = default;

    UnfollowResult& operator=(const UnfollowResult& unfollowResult) = default;
    UnfollowResult& operator=(UnfollowResult&& unfollowResult) = default;

    UnfollowResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UnfollowResult);
    }

    const UnfollowResult* operator->() const
    {
        return this;
    }

    UnfollowResult* operator->()
    {
        return this;
    }
    /**
     * アンフォローしたユーザを取得
     *
     * @return アンフォローしたユーザ
     */
    const optional<FollowUser>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * アンフォローしたユーザを設定
     *
     * @param item アンフォローしたユーザ
     */
    void setItem(FollowUser item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UnfollowResult> AsyncUnfollowResult;

} }

#endif //GS2_FRIEND_CONTROL_UNFOLLOWRESULT_HPP_