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
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    DeleteTriggerResult() :
        m_pData(nullptr)
    {}

    DeleteTriggerResult(const DeleteTriggerResult& deleteTriggerResult) :
        Gs2Object(deleteTriggerResult),
        m_pData(deleteTriggerResult.m_pData != nullptr ? new Data(*deleteTriggerResult.m_pData) : nullptr)
    {}

    DeleteTriggerResult(DeleteTriggerResult&& deleteTriggerResult) :
        Gs2Object(std::move(deleteTriggerResult)),
        m_pData(deleteTriggerResult.m_pData)
    {
        deleteTriggerResult.m_pData = nullptr;
    }

    ~DeleteTriggerResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTriggerResult& operator=(const DeleteTriggerResult& deleteTriggerResult)
    {
        Gs2Object::operator=(deleteTriggerResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTriggerResult.m_pData);

        return *this;
    }

    DeleteTriggerResult& operator=(DeleteTriggerResult&& deleteTriggerResult)
    {
        Gs2Object::operator=(std::move(deleteTriggerResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTriggerResult.m_pData;
        deleteTriggerResult.m_pData = nullptr;

        return *this;
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
    void setItem(const Trigger& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_DELETETRIGGERRESULT_HPP_