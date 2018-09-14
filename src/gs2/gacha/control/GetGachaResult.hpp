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

#ifndef GS2_GACHA_CONTROL_GETGACHARESULT_HPP_
#define GS2_GACHA_CONTROL_GETGACHARESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class GetGachaResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャ */
        optional<Gacha> item;

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
    GetGachaResult() :
        m_pData(nullptr)
    {}

    GetGachaResult(const GetGachaResult& getGachaResult) :
        Gs2Object(getGachaResult),
        m_pData(getGachaResult.m_pData != nullptr ? new Data(*getGachaResult.m_pData) : nullptr)
    {}

    GetGachaResult(GetGachaResult&& getGachaResult) :
        Gs2Object(std::move(getGachaResult)),
        m_pData(getGachaResult.m_pData)
    {
        getGachaResult.m_pData = nullptr;
    }

    ~GetGachaResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetGachaResult& operator=(const GetGachaResult& getGachaResult)
    {
        Gs2Object::operator=(getGachaResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getGachaResult.m_pData);

        return *this;
    }

    GetGachaResult& operator=(GetGachaResult&& getGachaResult)
    {
        Gs2Object::operator=(std::move(getGachaResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getGachaResult.m_pData;
        getGachaResult.m_pData = nullptr;

        return *this;
    }

    const GetGachaResult* operator->() const
    {
        return this;
    }

    GetGachaResult* operator->()
    {
        return this;
    }


    /**
     * ガチャを取得
     *
     * @return ガチャ
     */
    const optional<Gacha>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ガチャを設定
     *
     * @param item ガチャ
     */
    void setItem(const Gacha& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_GETGACHARESULT_HPP_