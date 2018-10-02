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

#ifndef GS2_SHOWCASE_CONTROL_BUYITEMRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_BUYITEMRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/model/StampSheet.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class BuyItemResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品 */
        optional<Item> item;
        /**   */
        optional<StampSheet> stampSheet;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            stampSheet(data.stampSheet)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            stampSheet(std::move(data.stampSheet))
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
            else if (std::strcmp(name, "stampSheet") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->stampSheet.emplace();
                    detail::json::JsonParser::parse(&this->stampSheet->getModel(), jsonObject);
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
    BuyItemResult() :
        m_pData(nullptr)
    {}

    BuyItemResult(const BuyItemResult& buyItemResult) :
        Gs2Object(buyItemResult),
        m_pData(buyItemResult.m_pData != nullptr ? new Data(*buyItemResult.m_pData) : nullptr)
    {}

    BuyItemResult(BuyItemResult&& buyItemResult) :
        Gs2Object(std::move(buyItemResult)),
        m_pData(buyItemResult.m_pData)
    {
        buyItemResult.m_pData = nullptr;
    }

    ~BuyItemResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    BuyItemResult& operator=(const BuyItemResult& buyItemResult)
    {
        Gs2Object::operator=(buyItemResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*buyItemResult.m_pData);

        return *this;
    }

    BuyItemResult& operator=(BuyItemResult&& buyItemResult)
    {
        Gs2Object::operator=(std::move(buyItemResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = buyItemResult.m_pData;
        buyItemResult.m_pData = nullptr;

        return *this;
    }

    const BuyItemResult* operator->() const
    {
        return this;
    }

    BuyItemResult* operator->()
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

    /**
     *  を取得
     *
     * @return  
     */
    const optional<StampSheet>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     *  を設定
     *
     * @param stampSheet  
     */
    void setStampSheet(const StampSheet& stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_BUYITEMRESULT_HPP_