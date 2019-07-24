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

#ifndef GS2_STAMINA_CONTROL_GETCURRENTSTAMINAMASTERRESULT_HPP_
#define GS2_STAMINA_CONTROL_GETCURRENTSTAMINAMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * 現在有効な現在有効なスタミナマスターを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCurrentStaminaMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在有効な現在有効なスタミナマスター */
        optional<CurrentStaminaMaster> item;

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
    GetCurrentStaminaMasterResult() :
        m_pData(nullptr)
    {}

    GetCurrentStaminaMasterResult(const GetCurrentStaminaMasterResult& getCurrentStaminaMasterResult) :
        Gs2Object(getCurrentStaminaMasterResult),
        m_pData(getCurrentStaminaMasterResult.m_pData != nullptr ? new Data(*getCurrentStaminaMasterResult.m_pData) : nullptr)
    {}

    GetCurrentStaminaMasterResult(GetCurrentStaminaMasterResult&& getCurrentStaminaMasterResult) :
        Gs2Object(std::move(getCurrentStaminaMasterResult)),
        m_pData(getCurrentStaminaMasterResult.m_pData)
    {
        getCurrentStaminaMasterResult.m_pData = nullptr;
    }

    ~GetCurrentStaminaMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCurrentStaminaMasterResult& operator=(const GetCurrentStaminaMasterResult& getCurrentStaminaMasterResult)
    {
        Gs2Object::operator=(getCurrentStaminaMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCurrentStaminaMasterResult.m_pData);

        return *this;
    }

    GetCurrentStaminaMasterResult& operator=(GetCurrentStaminaMasterResult&& getCurrentStaminaMasterResult)
    {
        Gs2Object::operator=(std::move(getCurrentStaminaMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCurrentStaminaMasterResult.m_pData;
        getCurrentStaminaMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCurrentStaminaMasterResult* operator->() const
    {
        return this;
    }

    GetCurrentStaminaMasterResult* operator->()
    {
        return this;
    }
    /**
     * 現在有効な現在有効なスタミナマスターを取得
     *
     * @return 現在有効な現在有効なスタミナマスター
     */
    const optional<CurrentStaminaMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在有効な現在有効なスタミナマスターを設定
     *
     * @param item 現在有効な現在有効なスタミナマスター
     */
    void setItem(const CurrentStaminaMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_GETCURRENTSTAMINAMASTERRESULT_HPP_