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

#ifndef GS2_LIMIT_CONTROL_UPDATELIMITMODELMASTERRESULT_HPP_
#define GS2_LIMIT_CONTROL_UPDATELIMITMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * 回数制限の種類マスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateLimitModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した回数制限の種類マスター */
        optional<LimitModelMaster> item;

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

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
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
    UpdateLimitModelMasterResult() :
        m_pData(nullptr)
    {}

    UpdateLimitModelMasterResult(const UpdateLimitModelMasterResult& updateLimitModelMasterResult) :
        Gs2Object(updateLimitModelMasterResult),
        m_pData(updateLimitModelMasterResult.m_pData != nullptr ? new Data(*updateLimitModelMasterResult.m_pData) : nullptr)
    {}

    UpdateLimitModelMasterResult(UpdateLimitModelMasterResult&& updateLimitModelMasterResult) :
        Gs2Object(std::move(updateLimitModelMasterResult)),
        m_pData(updateLimitModelMasterResult.m_pData)
    {
        updateLimitModelMasterResult.m_pData = nullptr;
    }

    ~UpdateLimitModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateLimitModelMasterResult& operator=(const UpdateLimitModelMasterResult& updateLimitModelMasterResult)
    {
        Gs2Object::operator=(updateLimitModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateLimitModelMasterResult.m_pData);

        return *this;
    }

    UpdateLimitModelMasterResult& operator=(UpdateLimitModelMasterResult&& updateLimitModelMasterResult)
    {
        Gs2Object::operator=(std::move(updateLimitModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateLimitModelMasterResult.m_pData;
        updateLimitModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateLimitModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateLimitModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した回数制限の種類マスターを取得
     *
     * @return 更新した回数制限の種類マスター
     */
    const optional<LimitModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した回数制限の種類マスターを設定
     *
     * @param item 更新した回数制限の種類マスター
     */
    void setItem(const LimitModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LIMIT_CONTROL_UPDATELIMITMODELMASTERRESULT_HPP_