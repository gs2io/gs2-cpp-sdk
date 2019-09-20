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

#ifndef GS2_SCHEDULE_CONTROL_DELETETRIGGERRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_DELETETRIGGERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/schedule/model/model.hpp>
#include <memory>

namespace gs2 { namespace schedule
{

/**
 * トリガーを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteTriggerResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** トリガー */
        optional<Trigger> item;

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
    DeleteTriggerResult() = default;
    DeleteTriggerResult(const DeleteTriggerResult& deleteTriggerResult) = default;
    DeleteTriggerResult(DeleteTriggerResult&& deleteTriggerResult) = default;
    ~DeleteTriggerResult() = default;

    DeleteTriggerResult& operator=(const DeleteTriggerResult& deleteTriggerResult) = default;
    DeleteTriggerResult& operator=(DeleteTriggerResult&& deleteTriggerResult) = default;

    DeleteTriggerResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteTriggerResult);
    }

    const DeleteTriggerResult* operator->() const
    {
        return this;
    }

    DeleteTriggerResult* operator->()
    {
        return this;
    }
    /**
     * トリガーを取得
     *
     * @return トリガー
     */
    const optional<Trigger>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * トリガーを設定
     *
     * @param item トリガー
     */
    void setItem(Trigger item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DeleteTriggerResult> AsyncDeleteTriggerResult;

} }

#endif //GS2_SCHEDULE_CONTROL_DELETETRIGGERRESULT_HPP_