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

#ifndef GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/showcase/model/model.hpp>
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * ユーザIDを指定して陳列棚を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetShowcaseByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚 */
        optional<Showcase> item;

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
    GetShowcaseByUserIdResult() = default;
    GetShowcaseByUserIdResult(const GetShowcaseByUserIdResult& getShowcaseByUserIdResult) = default;
    GetShowcaseByUserIdResult(GetShowcaseByUserIdResult&& getShowcaseByUserIdResult) = default;
    ~GetShowcaseByUserIdResult() = default;

    GetShowcaseByUserIdResult& operator=(const GetShowcaseByUserIdResult& getShowcaseByUserIdResult) = default;
    GetShowcaseByUserIdResult& operator=(GetShowcaseByUserIdResult&& getShowcaseByUserIdResult) = default;

    GetShowcaseByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetShowcaseByUserIdResult);
    }

    const GetShowcaseByUserIdResult* operator->() const
    {
        return this;
    }

    GetShowcaseByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 陳列棚を取得
     *
     * @return 陳列棚
     */
    const optional<Showcase>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 陳列棚を設定
     *
     * @param item 陳列棚
     */
    void setItem(Showcase item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetShowcaseByUserIdResult> AsyncGetShowcaseByUserIdResult;

} }

#endif //GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_