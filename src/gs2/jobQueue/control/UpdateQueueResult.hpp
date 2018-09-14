/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_JOBQUEUE_CONTROL_UPDATEQUEUERESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_UPDATEQUEUERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateQueueResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** キュー */
        optional<Queue> item;

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

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
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
    UpdateQueueResult() :
        m_pData(nullptr)
    {}

    UpdateQueueResult(const UpdateQueueResult& updateQueueResult) :
        Gs2Object(updateQueueResult),
        m_pData(updateQueueResult.m_pData != nullptr ? new Data(*updateQueueResult.m_pData) : nullptr)
    {}

    UpdateQueueResult(UpdateQueueResult&& updateQueueResult) :
        Gs2Object(std::move(updateQueueResult)),
        m_pData(updateQueueResult.m_pData)
    {
        updateQueueResult.m_pData = nullptr;
    }

    ~UpdateQueueResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateQueueResult& operator=(const UpdateQueueResult& updateQueueResult)
    {
        Gs2Object::operator=(updateQueueResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateQueueResult.m_pData);

        return *this;
    }

    UpdateQueueResult& operator=(UpdateQueueResult&& updateQueueResult)
    {
        Gs2Object::operator=(std::move(updateQueueResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateQueueResult.m_pData;
        updateQueueResult.m_pData = nullptr;

        return *this;
    }

    const UpdateQueueResult* operator->() const
    {
        return this;
    }

    UpdateQueueResult* operator->()
    {
        return this;
    }


    /**
     * キューを取得
     *
     * @return キュー
     */
    const optional<Queue>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * キューを設定
     *
     * @param item キュー
     */
    void setItem(const Queue& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_JOBQUEUE_CONTROL_UPDATEQUEUERESULT_HPP_