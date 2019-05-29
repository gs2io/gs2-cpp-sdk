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

#ifndef GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERRESULT_HPP_
#define GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERRESULT_HPP_

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
 * スタミナモデルマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateStaminaModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したスタミナモデルマスター */
        optional<StaminaModelMaster> item;

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
    CreateStaminaModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateStaminaModelMasterResult(const CreateStaminaModelMasterResult& createStaminaModelMasterResult) :
        Gs2Object(createStaminaModelMasterResult),
        m_pData(createStaminaModelMasterResult.m_pData != nullptr ? new Data(*createStaminaModelMasterResult.m_pData) : nullptr)
    {}

    CreateStaminaModelMasterResult(CreateStaminaModelMasterResult&& createStaminaModelMasterResult) :
        Gs2Object(std::move(createStaminaModelMasterResult)),
        m_pData(createStaminaModelMasterResult.m_pData)
    {
        createStaminaModelMasterResult.m_pData = nullptr;
    }

    ~CreateStaminaModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateStaminaModelMasterResult& operator=(const CreateStaminaModelMasterResult& createStaminaModelMasterResult)
    {
        Gs2Object::operator=(createStaminaModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createStaminaModelMasterResult.m_pData);

        return *this;
    }

    CreateStaminaModelMasterResult& operator=(CreateStaminaModelMasterResult&& createStaminaModelMasterResult)
    {
        Gs2Object::operator=(std::move(createStaminaModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createStaminaModelMasterResult.m_pData;
        createStaminaModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateStaminaModelMasterResult* operator->() const
    {
        return this;
    }

    CreateStaminaModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したスタミナモデルマスターを取得
     *
     * @return 作成したスタミナモデルマスター
     */
    const optional<StaminaModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したスタミナモデルマスターを設定
     *
     * @param item 作成したスタミナモデルマスター
     */
    void setItem(const StaminaModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERRESULT_HPP_