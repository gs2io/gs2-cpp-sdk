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

#ifndef GS2_LOTTERY_CONTROL_GETRAWBOXBYUSERIDRESULT_HPP_
#define GS2_LOTTERY_CONTROL_GETRAWBOXBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * ユーザIDを指定してボックスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetRawBoxByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ボックス */
        optional<Box> item;

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
    GetRawBoxByUserIdResult() = default;
    GetRawBoxByUserIdResult(const GetRawBoxByUserIdResult& getRawBoxByUserIdResult) = default;
    GetRawBoxByUserIdResult(GetRawBoxByUserIdResult&& getRawBoxByUserIdResult) = default;
    ~GetRawBoxByUserIdResult() = default;

    GetRawBoxByUserIdResult& operator=(const GetRawBoxByUserIdResult& getRawBoxByUserIdResult) = default;
    GetRawBoxByUserIdResult& operator=(GetRawBoxByUserIdResult&& getRawBoxByUserIdResult) = default;

    GetRawBoxByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetRawBoxByUserIdResult);
    }

    const GetRawBoxByUserIdResult* operator->() const
    {
        return this;
    }

    GetRawBoxByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * ボックスを取得
     *
     * @return ボックス
     */
    const optional<Box>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ボックスを設定
     *
     * @param item ボックス
     */
    void setItem(Box item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetRawBoxByUserIdResult> AsyncGetRawBoxByUserIdResult;

} }

#endif //GS2_LOTTERY_CONTROL_GETRAWBOXBYUSERIDRESULT_HPP_