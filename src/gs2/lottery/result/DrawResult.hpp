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

#ifndef GS2_LOTTERY_CONTROL_DRAWRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DRAWRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 抽選を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DrawResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選結果の景品リスト */
        optional<List<DrawnPrize>> items;
        /** 排出済みの景品情報 */
        optional<BoxItems> boxItems;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            boxItems(data.boxItems)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            boxItems(std::move(data.boxItems))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        DrawnPrize item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "boxItems") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->boxItems.emplace();
                    detail::json::JsonParser::parse(&this->boxItems->getModel(), jsonObject);
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
    DrawResult() :
        m_pData(nullptr)
    {}

    DrawResult(const DrawResult& drawResult) :
        Gs2Object(drawResult),
        m_pData(drawResult.m_pData != nullptr ? new Data(*drawResult.m_pData) : nullptr)
    {}

    DrawResult(DrawResult&& drawResult) :
        Gs2Object(std::move(drawResult)),
        m_pData(drawResult.m_pData)
    {
        drawResult.m_pData = nullptr;
    }

    ~DrawResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DrawResult& operator=(const DrawResult& drawResult)
    {
        Gs2Object::operator=(drawResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*drawResult.m_pData);

        return *this;
    }

    DrawResult& operator=(DrawResult&& drawResult)
    {
        Gs2Object::operator=(std::move(drawResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = drawResult.m_pData;
        drawResult.m_pData = nullptr;

        return *this;
    }

    const DrawResult* operator->() const
    {
        return this;
    }

    DrawResult* operator->()
    {
        return this;
    }
    /**
     * 抽選結果の景品リストを取得
     *
     * @return 抽選結果の景品リスト
     */
    const optional<List<DrawnPrize>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 抽選結果の景品リストを設定
     *
     * @param items 抽選結果の景品リスト
     */
    void setItems(const List<DrawnPrize>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * 排出済みの景品情報を取得
     *
     * @return 排出済みの景品情報
     */
    const optional<BoxItems>& getBoxItems() const
    {
        return ensureData().boxItems;
    }

    /**
     * 排出済みの景品情報を設定
     *
     * @param boxItems 排出済みの景品情報
     */
    void setBoxItems(const BoxItems& boxItems)
    {
        ensureData().boxItems.emplace(boxItems);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_DRAWRESULT_HPP_