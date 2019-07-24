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

#ifndef GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 陳列棚を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class BuyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品 */
        optional<SalesItem> item;
        /** 購入処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "stampSheet") == 0) {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
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
    BuyResult() :
        m_pData(nullptr)
    {}

    BuyResult(const BuyResult& buyResult) :
        Gs2Object(buyResult),
        m_pData(buyResult.m_pData != nullptr ? new Data(*buyResult.m_pData) : nullptr)
    {}

    BuyResult(BuyResult&& buyResult) :
        Gs2Object(std::move(buyResult)),
        m_pData(buyResult.m_pData)
    {
        buyResult.m_pData = nullptr;
    }

    ~BuyResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    BuyResult& operator=(const BuyResult& buyResult)
    {
        Gs2Object::operator=(buyResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*buyResult.m_pData);

        return *this;
    }

    BuyResult& operator=(BuyResult&& buyResult)
    {
        Gs2Object::operator=(std::move(buyResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = buyResult.m_pData;
        buyResult.m_pData = nullptr;

        return *this;
    }

    const BuyResult* operator->() const
    {
        return this;
    }

    BuyResult* operator->()
    {
        return this;
    }
    /**
     * 商品を取得
     *
     * @return 商品
     */
    const optional<SalesItem>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 商品を設定
     *
     * @param item 商品
     */
    void setItem(const SalesItem& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 購入処理の実行に使用するスタンプシートを取得
     *
     * @return 購入処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 購入処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 購入処理の実行に使用するスタンプシート
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_