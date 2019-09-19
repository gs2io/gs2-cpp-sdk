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

#ifndef GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace account
{

/**
 * ゲームプレイヤーアカウントの現在時刻に対する補正値を更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateTimeOffsetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したゲームプレイヤーアカウント */
        optional<Account> item;

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
    UpdateTimeOffsetResult() = default;
    UpdateTimeOffsetResult(const UpdateTimeOffsetResult& updateTimeOffsetResult) = default;
    UpdateTimeOffsetResult(UpdateTimeOffsetResult&& updateTimeOffsetResult) = default;
    ~UpdateTimeOffsetResult() = default;

    UpdateTimeOffsetResult& operator=(const UpdateTimeOffsetResult& updateTimeOffsetResult) = default;
    UpdateTimeOffsetResult& operator=(UpdateTimeOffsetResult&& updateTimeOffsetResult) = default;

    UpdateTimeOffsetResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateTimeOffsetResult);
    }

    const UpdateTimeOffsetResult* operator->() const
    {
        return this;
    }

    UpdateTimeOffsetResult* operator->()
    {
        return this;
    }
    /**
     * 更新したゲームプレイヤーアカウントを取得
     *
     * @return 更新したゲームプレイヤーアカウント
     */
    const optional<Account>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したゲームプレイヤーアカウントを設定
     *
     * @param item 更新したゲームプレイヤーアカウント
     */
    void setItem(Account item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateTimeOffsetResult> AsyncUpdateTimeOffsetResult;

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETRESULT_HPP_