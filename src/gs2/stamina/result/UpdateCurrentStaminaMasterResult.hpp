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

#ifndef GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERRESULT_HPP_
#define GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERRESULT_HPP_

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
 * 現在有効なスタミナマスターJSONを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentStaminaMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効なスタミナマスターJSON */
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
    UpdateCurrentStaminaMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentStaminaMasterResult(const UpdateCurrentStaminaMasterResult& updateCurrentStaminaMasterResult) :
        Gs2Object(updateCurrentStaminaMasterResult),
        m_pData(updateCurrentStaminaMasterResult.m_pData != nullptr ? new Data(*updateCurrentStaminaMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentStaminaMasterResult(UpdateCurrentStaminaMasterResult&& updateCurrentStaminaMasterResult) :
        Gs2Object(std::move(updateCurrentStaminaMasterResult)),
        m_pData(updateCurrentStaminaMasterResult.m_pData)
    {
        updateCurrentStaminaMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentStaminaMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentStaminaMasterResult& operator=(const UpdateCurrentStaminaMasterResult& updateCurrentStaminaMasterResult)
    {
        Gs2Object::operator=(updateCurrentStaminaMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentStaminaMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentStaminaMasterResult& operator=(UpdateCurrentStaminaMasterResult&& updateCurrentStaminaMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentStaminaMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentStaminaMasterResult.m_pData;
        updateCurrentStaminaMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentStaminaMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentStaminaMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効なスタミナマスターJSONを取得
     *
     * @return 更新した現在有効なスタミナマスターJSON
     */
    const optional<CurrentStaminaMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効なスタミナマスターJSONを設定
     *
     * @param item 更新した現在有効なスタミナマスターJSON
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

#endif //GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERRESULT_HPP_