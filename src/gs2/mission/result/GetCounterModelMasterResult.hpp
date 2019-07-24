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

#ifndef GS2_MISSION_CONTROL_GETCOUNTERMODELMASTERRESULT_HPP_
#define GS2_MISSION_CONTROL_GETCOUNTERMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace mission
{

/**
 * カウンターの種類マスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCounterModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターの種類マスター */
        optional<CounterModelMaster> item;

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
    GetCounterModelMasterResult() :
        m_pData(nullptr)
    {}

    GetCounterModelMasterResult(const GetCounterModelMasterResult& getCounterModelMasterResult) :
        Gs2Object(getCounterModelMasterResult),
        m_pData(getCounterModelMasterResult.m_pData != nullptr ? new Data(*getCounterModelMasterResult.m_pData) : nullptr)
    {}

    GetCounterModelMasterResult(GetCounterModelMasterResult&& getCounterModelMasterResult) :
        Gs2Object(std::move(getCounterModelMasterResult)),
        m_pData(getCounterModelMasterResult.m_pData)
    {
        getCounterModelMasterResult.m_pData = nullptr;
    }

    ~GetCounterModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCounterModelMasterResult& operator=(const GetCounterModelMasterResult& getCounterModelMasterResult)
    {
        Gs2Object::operator=(getCounterModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCounterModelMasterResult.m_pData);

        return *this;
    }

    GetCounterModelMasterResult& operator=(GetCounterModelMasterResult&& getCounterModelMasterResult)
    {
        Gs2Object::operator=(std::move(getCounterModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCounterModelMasterResult.m_pData;
        getCounterModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCounterModelMasterResult* operator->() const
    {
        return this;
    }

    GetCounterModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * カウンターの種類マスターを取得
     *
     * @return カウンターの種類マスター
     */
    const optional<CounterModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * カウンターの種類マスターを設定
     *
     * @param item カウンターの種類マスター
     */
    void setItem(const CounterModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_GETCOUNTERMODELMASTERRESULT_HPP_