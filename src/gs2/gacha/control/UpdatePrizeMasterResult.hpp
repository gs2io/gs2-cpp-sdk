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

#ifndef GS2_GACHA_CONTROL_UPDATEPRIZEMASTERRESULT_HPP_
#define GS2_GACHA_CONTROL_UPDATEPRIZEMASTERRESULT_HPP_

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
class UpdatePrizeMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品 */
        optional<PrizeMaster> item;

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
    UpdatePrizeMasterResult() :
        m_pData(nullptr)
    {}

    UpdatePrizeMasterResult(const UpdatePrizeMasterResult& updatePrizeMasterResult) :
        Gs2Object(updatePrizeMasterResult),
        m_pData(updatePrizeMasterResult.m_pData != nullptr ? new Data(*updatePrizeMasterResult.m_pData) : nullptr)
    {}

    UpdatePrizeMasterResult(UpdatePrizeMasterResult&& updatePrizeMasterResult) :
        Gs2Object(std::move(updatePrizeMasterResult)),
        m_pData(updatePrizeMasterResult.m_pData)
    {
        updatePrizeMasterResult.m_pData = nullptr;
    }

    ~UpdatePrizeMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdatePrizeMasterResult& operator=(const UpdatePrizeMasterResult& updatePrizeMasterResult)
    {
        Gs2Object::operator=(updatePrizeMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updatePrizeMasterResult.m_pData);

        return *this;
    }

    UpdatePrizeMasterResult& operator=(UpdatePrizeMasterResult&& updatePrizeMasterResult)
    {
        Gs2Object::operator=(std::move(updatePrizeMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updatePrizeMasterResult.m_pData;
        updatePrizeMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdatePrizeMasterResult* operator->() const
    {
        return this;
    }

    UpdatePrizeMasterResult* operator->()
    {
        return this;
    }


    /**
     * 景品を取得
     *
     * @return 景品
     */
    const optional<PrizeMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 景品を設定
     *
     * @param item 景品
     */
    void setItem(const PrizeMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_UPDATEPRIZEMASTERRESULT_HPP_