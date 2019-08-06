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

#ifndef GS2_MISSION_CONTROL_GETCOUNTERMODELRESULT_HPP_
#define GS2_MISSION_CONTROL_GETCOUNTERMODELRESULT_HPP_

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
 * カウンターの種類を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCounterModelResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターの種類 */
        optional<CounterModel> item;

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
    GetCounterModelResult() :
        m_pData(nullptr)
    {}

    GetCounterModelResult(const GetCounterModelResult& getCounterModelResult) :
        Gs2Object(getCounterModelResult),
        m_pData(getCounterModelResult.m_pData != nullptr ? new Data(*getCounterModelResult.m_pData) : nullptr)
    {}

    GetCounterModelResult(GetCounterModelResult&& getCounterModelResult) :
        Gs2Object(std::move(getCounterModelResult)),
        m_pData(getCounterModelResult.m_pData)
    {
        getCounterModelResult.m_pData = nullptr;
    }

    ~GetCounterModelResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCounterModelResult& operator=(const GetCounterModelResult& getCounterModelResult)
    {
        Gs2Object::operator=(getCounterModelResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCounterModelResult.m_pData);

        return *this;
    }

    GetCounterModelResult& operator=(GetCounterModelResult&& getCounterModelResult)
    {
        Gs2Object::operator=(std::move(getCounterModelResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCounterModelResult.m_pData;
        getCounterModelResult.m_pData = nullptr;

        return *this;
    }

    const GetCounterModelResult* operator->() const
    {
        return this;
    }

    GetCounterModelResult* operator->()
    {
        return this;
    }
    /**
     * カウンターの種類を取得
     *
     * @return カウンターの種類
     */
    const optional<CounterModel>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * カウンターの種類を設定
     *
     * @param item カウンターの種類
     */
    void setItem(const CounterModel& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_GETCOUNTERMODELRESULT_HPP_