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

#ifndef GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERRESULT_HPP_

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
 * @author Game Server Services, Inc.
 */
class CreateShowcaseItemMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品 */
        optional<ShowcaseItemMaster> item;

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
    CreateShowcaseItemMasterResult() :
        m_pData(nullptr)
    {}

    CreateShowcaseItemMasterResult(const CreateShowcaseItemMasterResult& createShowcaseItemMasterResult) :
        Gs2Object(createShowcaseItemMasterResult),
        m_pData(createShowcaseItemMasterResult.m_pData != nullptr ? new Data(*createShowcaseItemMasterResult.m_pData) : nullptr)
    {}

    CreateShowcaseItemMasterResult(CreateShowcaseItemMasterResult&& createShowcaseItemMasterResult) :
        Gs2Object(std::move(createShowcaseItemMasterResult)),
        m_pData(createShowcaseItemMasterResult.m_pData)
    {
        createShowcaseItemMasterResult.m_pData = nullptr;
    }

    ~CreateShowcaseItemMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateShowcaseItemMasterResult& operator=(const CreateShowcaseItemMasterResult& createShowcaseItemMasterResult)
    {
        Gs2Object::operator=(createShowcaseItemMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createShowcaseItemMasterResult.m_pData);

        return *this;
    }

    CreateShowcaseItemMasterResult& operator=(CreateShowcaseItemMasterResult&& createShowcaseItemMasterResult)
    {
        Gs2Object::operator=(std::move(createShowcaseItemMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createShowcaseItemMasterResult.m_pData;
        createShowcaseItemMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateShowcaseItemMasterResult* operator->() const
    {
        return this;
    }

    CreateShowcaseItemMasterResult* operator->()
    {
        return this;
    }


    /**
     * 陳列商品を取得
     *
     * @return 陳列商品
     */
    const optional<ShowcaseItemMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 陳列商品を設定
     *
     * @param item 陳列商品
     */
    void setItem(const ShowcaseItemMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_CREATESHOWCASEITEMMASTERRESULT_HPP_