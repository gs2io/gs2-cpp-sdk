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

#ifndef GS2_CONSUMABLEITEM_CONTROL_CONSUMEITEMBYUSERIDRESULT_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_CONSUMEITEMBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace consumableItem
{

/**
 * @author Game Server Services, Inc.
 */
class ConsumeItemByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 所持品 */
        optional<Inventory> item;

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
    ConsumeItemByUserIdResult() :
        m_pData(nullptr)
    {}

    ConsumeItemByUserIdResult(const ConsumeItemByUserIdResult& consumeItemByUserIdResult) :
        Gs2Object(consumeItemByUserIdResult),
        m_pData(consumeItemByUserIdResult.m_pData != nullptr ? new Data(*consumeItemByUserIdResult.m_pData) : nullptr)
    {}

    ConsumeItemByUserIdResult(ConsumeItemByUserIdResult&& consumeItemByUserIdResult) :
        Gs2Object(std::move(consumeItemByUserIdResult)),
        m_pData(consumeItemByUserIdResult.m_pData)
    {
        consumeItemByUserIdResult.m_pData = nullptr;
    }

    ~ConsumeItemByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeItemByUserIdResult& operator=(const ConsumeItemByUserIdResult& consumeItemByUserIdResult)
    {
        Gs2Object::operator=(consumeItemByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeItemByUserIdResult.m_pData);

        return *this;
    }

    ConsumeItemByUserIdResult& operator=(ConsumeItemByUserIdResult&& consumeItemByUserIdResult)
    {
        Gs2Object::operator=(std::move(consumeItemByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeItemByUserIdResult.m_pData;
        consumeItemByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const ConsumeItemByUserIdResult* operator->() const
    {
        return this;
    }

    ConsumeItemByUserIdResult* operator->()
    {
        return this;
    }


    /**
     * 所持品を取得
     *
     * @return 所持品
     */
    const optional<Inventory>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 所持品を設定
     *
     * @param item 所持品
     */
    void setItem(const Inventory& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CONSUMABLEITEM_CONTROL_CONSUMEITEMBYUSERIDRESULT_HPP_