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

#ifndef GS2_MONEY_CONTROL_CREATEITEMRESULT_HPP_
#define GS2_MONEY_CONTROL_CREATEITEMRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * @author Game Server Services, Inc.
 */
class CreateItemResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品 */
        optional<Item> item;

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
    CreateItemResult() :
        m_pData(nullptr)
    {}

    CreateItemResult(const CreateItemResult& createItemResult) :
        Gs2Object(createItemResult),
        m_pData(createItemResult.m_pData != nullptr ? new Data(*createItemResult.m_pData) : nullptr)
    {}

    CreateItemResult(CreateItemResult&& createItemResult) :
        Gs2Object(std::move(createItemResult)),
        m_pData(createItemResult.m_pData)
    {
        createItemResult.m_pData = nullptr;
    }

    ~CreateItemResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemResult& operator=(const CreateItemResult& createItemResult)
    {
        Gs2Object::operator=(createItemResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemResult.m_pData);

        return *this;
    }

    CreateItemResult& operator=(CreateItemResult&& createItemResult)
    {
        Gs2Object::operator=(std::move(createItemResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemResult.m_pData;
        createItemResult.m_pData = nullptr;

        return *this;
    }

    const CreateItemResult* operator->() const
    {
        return this;
    }

    CreateItemResult* operator->()
    {
        return this;
    }


    /**
     * 商品を取得
     *
     * @return 商品
     */
    const optional<Item>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 商品を設定
     *
     * @param item 商品
     */
    void setItem(const Item& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_CONTROL_CREATEITEMRESULT_HPP_