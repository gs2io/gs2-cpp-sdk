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

#ifndef GS2_GACHA_CONTROL_UPDATERARITYMASTERRESULT_HPP_
#define GS2_GACHA_CONTROL_UPDATERARITYMASTERRESULT_HPP_

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
class UpdateRarityMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品レアリティ */
        optional<RarityMaster> item;

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
    UpdateRarityMasterResult() :
        m_pData(nullptr)
    {}

    UpdateRarityMasterResult(const UpdateRarityMasterResult& updateRarityMasterResult) :
        Gs2Object(updateRarityMasterResult),
        m_pData(updateRarityMasterResult.m_pData != nullptr ? new Data(*updateRarityMasterResult.m_pData) : nullptr)
    {}

    UpdateRarityMasterResult(UpdateRarityMasterResult&& updateRarityMasterResult) :
        Gs2Object(std::move(updateRarityMasterResult)),
        m_pData(updateRarityMasterResult.m_pData)
    {
        updateRarityMasterResult.m_pData = nullptr;
    }

    ~UpdateRarityMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateRarityMasterResult& operator=(const UpdateRarityMasterResult& updateRarityMasterResult)
    {
        Gs2Object::operator=(updateRarityMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateRarityMasterResult.m_pData);

        return *this;
    }

    UpdateRarityMasterResult& operator=(UpdateRarityMasterResult&& updateRarityMasterResult)
    {
        Gs2Object::operator=(std::move(updateRarityMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateRarityMasterResult.m_pData;
        updateRarityMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateRarityMasterResult* operator->() const
    {
        return this;
    }

    UpdateRarityMasterResult* operator->()
    {
        return this;
    }


    /**
     * 景品レアリティを取得
     *
     * @return 景品レアリティ
     */
    const optional<RarityMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 景品レアリティを設定
     *
     * @param item 景品レアリティ
     */
    void setItem(const RarityMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_UPDATERARITYMASTERRESULT_HPP_