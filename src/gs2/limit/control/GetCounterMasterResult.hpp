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

#ifndef GS2_LIMIT_CONTROL_GETCOUNTERMASTERRESULT_HPP_
#define GS2_LIMIT_CONTROL_GETCOUNTERMASTERRESULT_HPP_

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
 * @author Game Server Services, Inc.
 */
class GetCounterMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターマスター */
        optional<CounterMaster> item;

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
    GetCounterMasterResult() :
        m_pData(nullptr)
    {}

    GetCounterMasterResult(const GetCounterMasterResult& getCounterMasterResult) :
        Gs2Object(getCounterMasterResult),
        m_pData(getCounterMasterResult.m_pData != nullptr ? new Data(*getCounterMasterResult.m_pData) : nullptr)
    {}

    GetCounterMasterResult(GetCounterMasterResult&& getCounterMasterResult) :
        Gs2Object(std::move(getCounterMasterResult)),
        m_pData(getCounterMasterResult.m_pData)
    {
        getCounterMasterResult.m_pData = nullptr;
    }

    ~GetCounterMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCounterMasterResult& operator=(const GetCounterMasterResult& getCounterMasterResult)
    {
        Gs2Object::operator=(getCounterMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCounterMasterResult.m_pData);

        return *this;
    }

    GetCounterMasterResult& operator=(GetCounterMasterResult&& getCounterMasterResult)
    {
        Gs2Object::operator=(std::move(getCounterMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCounterMasterResult.m_pData;
        getCounterMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCounterMasterResult* operator->() const
    {
        return this;
    }

    GetCounterMasterResult* operator->()
    {
        return this;
    }


    /**
     * カウンターマスターを取得
     *
     * @return カウンターマスター
     */
    const optional<CounterMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * カウンターマスターを設定
     *
     * @param item カウンターマスター
     */
    void setItem(const CounterMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LIMIT_CONTROL_GETCOUNTERMASTERRESULT_HPP_