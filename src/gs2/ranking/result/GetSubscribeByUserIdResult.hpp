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

#ifndef GS2_RANKING_CONTROL_GETSUBSCRIBEBYUSERIDRESULT_HPP_
#define GS2_RANKING_CONTROL_GETSUBSCRIBEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * ユーザIDを指定して購読を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetSubscribeByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 購読対象 */
        optional<SubscribeUser> item;

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
    GetSubscribeByUserIdResult() = default;
    GetSubscribeByUserIdResult(const GetSubscribeByUserIdResult& getSubscribeByUserIdResult) = default;
    GetSubscribeByUserIdResult(GetSubscribeByUserIdResult&& getSubscribeByUserIdResult) = default;
    ~GetSubscribeByUserIdResult() = default;

    GetSubscribeByUserIdResult& operator=(const GetSubscribeByUserIdResult& getSubscribeByUserIdResult) = default;
    GetSubscribeByUserIdResult& operator=(GetSubscribeByUserIdResult&& getSubscribeByUserIdResult) = default;

    GetSubscribeByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetSubscribeByUserIdResult);
    }

    const GetSubscribeByUserIdResult* operator->() const
    {
        return this;
    }

    GetSubscribeByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 購読対象を取得
     *
     * @return 購読対象
     */
    const optional<SubscribeUser>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 購読対象を設定
     *
     * @param item 購読対象
     */
    void setItem(SubscribeUser item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetSubscribeByUserIdResult> AsyncGetSubscribeByUserIdResult;

} }

#endif //GS2_RANKING_CONTROL_GETSUBSCRIBEBYUSERIDRESULT_HPP_