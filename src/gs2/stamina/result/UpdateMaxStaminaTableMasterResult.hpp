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

#ifndef GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERRESULT_HPP_
#define GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERRESULT_HPP_

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
 * スタミナ最大値テーブルを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMaxStaminaTableMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したスタミナ最大値テーブル */
        optional<MaxStaminaTableMaster> item;

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
    UpdateMaxStaminaTableMasterResult() :
        m_pData(nullptr)
    {}

    UpdateMaxStaminaTableMasterResult(const UpdateMaxStaminaTableMasterResult& updateMaxStaminaTableMasterResult) :
        Gs2Object(updateMaxStaminaTableMasterResult),
        m_pData(updateMaxStaminaTableMasterResult.m_pData != nullptr ? new Data(*updateMaxStaminaTableMasterResult.m_pData) : nullptr)
    {}

    UpdateMaxStaminaTableMasterResult(UpdateMaxStaminaTableMasterResult&& updateMaxStaminaTableMasterResult) :
        Gs2Object(std::move(updateMaxStaminaTableMasterResult)),
        m_pData(updateMaxStaminaTableMasterResult.m_pData)
    {
        updateMaxStaminaTableMasterResult.m_pData = nullptr;
    }

    ~UpdateMaxStaminaTableMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMaxStaminaTableMasterResult& operator=(const UpdateMaxStaminaTableMasterResult& updateMaxStaminaTableMasterResult)
    {
        Gs2Object::operator=(updateMaxStaminaTableMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMaxStaminaTableMasterResult.m_pData);

        return *this;
    }

    UpdateMaxStaminaTableMasterResult& operator=(UpdateMaxStaminaTableMasterResult&& updateMaxStaminaTableMasterResult)
    {
        Gs2Object::operator=(std::move(updateMaxStaminaTableMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMaxStaminaTableMasterResult.m_pData;
        updateMaxStaminaTableMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateMaxStaminaTableMasterResult* operator->() const
    {
        return this;
    }

    UpdateMaxStaminaTableMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新したスタミナ最大値テーブルを取得
     *
     * @return 更新したスタミナ最大値テーブル
     */
    const optional<MaxStaminaTableMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したスタミナ最大値テーブルを設定
     *
     * @param item 更新したスタミナ最大値テーブル
     */
    void setItem(const MaxStaminaTableMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERRESULT_HPP_