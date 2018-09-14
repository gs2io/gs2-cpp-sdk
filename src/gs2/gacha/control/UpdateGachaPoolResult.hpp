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

#ifndef GS2_GACHA_CONTROL_UPDATEGACHAPOOLRESULT_HPP_
#define GS2_GACHA_CONTROL_UPDATEGACHAPOOLRESULT_HPP_

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
class UpdateGachaPoolResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ガチャプール */
        optional<GachaPool> item;

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
    UpdateGachaPoolResult() :
        m_pData(nullptr)
    {}

    UpdateGachaPoolResult(const UpdateGachaPoolResult& updateGachaPoolResult) :
        Gs2Object(updateGachaPoolResult),
        m_pData(updateGachaPoolResult.m_pData != nullptr ? new Data(*updateGachaPoolResult.m_pData) : nullptr)
    {}

    UpdateGachaPoolResult(UpdateGachaPoolResult&& updateGachaPoolResult) :
        Gs2Object(std::move(updateGachaPoolResult)),
        m_pData(updateGachaPoolResult.m_pData)
    {
        updateGachaPoolResult.m_pData = nullptr;
    }

    ~UpdateGachaPoolResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGachaPoolResult& operator=(const UpdateGachaPoolResult& updateGachaPoolResult)
    {
        Gs2Object::operator=(updateGachaPoolResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGachaPoolResult.m_pData);

        return *this;
    }

    UpdateGachaPoolResult& operator=(UpdateGachaPoolResult&& updateGachaPoolResult)
    {
        Gs2Object::operator=(std::move(updateGachaPoolResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGachaPoolResult.m_pData;
        updateGachaPoolResult.m_pData = nullptr;

        return *this;
    }

    const UpdateGachaPoolResult* operator->() const
    {
        return this;
    }

    UpdateGachaPoolResult* operator->()
    {
        return this;
    }


    /**
     * ガチャプールを取得
     *
     * @return ガチャプール
     */
    const optional<GachaPool>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ガチャプールを設定
     *
     * @param item ガチャプール
     */
    void setItem(const GachaPool& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_UPDATEGACHAPOOLRESULT_HPP_