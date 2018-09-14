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

#ifndef GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLRESULT_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLRESULT_HPP_

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
class CreateItemPoolResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費型アイテムプール */
        optional<ItemPool> item;

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
    CreateItemPoolResult() :
        m_pData(nullptr)
    {}

    CreateItemPoolResult(const CreateItemPoolResult& createItemPoolResult) :
        Gs2Object(createItemPoolResult),
        m_pData(createItemPoolResult.m_pData != nullptr ? new Data(*createItemPoolResult.m_pData) : nullptr)
    {}

    CreateItemPoolResult(CreateItemPoolResult&& createItemPoolResult) :
        Gs2Object(std::move(createItemPoolResult)),
        m_pData(createItemPoolResult.m_pData)
    {
        createItemPoolResult.m_pData = nullptr;
    }

    ~CreateItemPoolResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemPoolResult& operator=(const CreateItemPoolResult& createItemPoolResult)
    {
        Gs2Object::operator=(createItemPoolResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemPoolResult.m_pData);

        return *this;
    }

    CreateItemPoolResult& operator=(CreateItemPoolResult&& createItemPoolResult)
    {
        Gs2Object::operator=(std::move(createItemPoolResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemPoolResult.m_pData;
        createItemPoolResult.m_pData = nullptr;

        return *this;
    }

    const CreateItemPoolResult* operator->() const
    {
        return this;
    }

    CreateItemPoolResult* operator->()
    {
        return this;
    }


    /**
     * 消費型アイテムプールを取得
     *
     * @return 消費型アイテムプール
     */
    const optional<ItemPool>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 消費型アイテムプールを設定
     *
     * @param item 消費型アイテムプール
     */
    void setItem(const ItemPool& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CONSUMABLEITEM_CONTROL_CREATEITEMPOOLRESULT_HPP_