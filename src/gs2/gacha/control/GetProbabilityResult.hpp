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

#ifndef GS2_GACHA_CONTROL_GETPROBABILITYRESULT_HPP_
#define GS2_GACHA_CONTROL_GETPROBABILITYRESULT_HPP_

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
class GetProbabilityResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レアリティ毎の排出率 */
        optional<List<Probability>> items;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Probability item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
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
    GetProbabilityResult() :
        m_pData(nullptr)
    {}

    GetProbabilityResult(const GetProbabilityResult& getProbabilityResult) :
        Gs2Object(getProbabilityResult),
        m_pData(getProbabilityResult.m_pData != nullptr ? new Data(*getProbabilityResult.m_pData) : nullptr)
    {}

    GetProbabilityResult(GetProbabilityResult&& getProbabilityResult) :
        Gs2Object(std::move(getProbabilityResult)),
        m_pData(getProbabilityResult.m_pData)
    {
        getProbabilityResult.m_pData = nullptr;
    }

    ~GetProbabilityResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetProbabilityResult& operator=(const GetProbabilityResult& getProbabilityResult)
    {
        Gs2Object::operator=(getProbabilityResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getProbabilityResult.m_pData);

        return *this;
    }

    GetProbabilityResult& operator=(GetProbabilityResult&& getProbabilityResult)
    {
        Gs2Object::operator=(std::move(getProbabilityResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getProbabilityResult.m_pData;
        getProbabilityResult.m_pData = nullptr;

        return *this;
    }

    const GetProbabilityResult* operator->() const
    {
        return this;
    }

    GetProbabilityResult* operator->()
    {
        return this;
    }


    /**
     * レアリティ毎の排出率を取得
     *
     * @return レアリティ毎の排出率
     */
    const optional<List<Probability>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * レアリティ毎の排出率を設定
     *
     * @param items レアリティ毎の排出率
     */
    void setItems(const List<Probability>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_CONTROL_GETPROBABILITYRESULT_HPP_