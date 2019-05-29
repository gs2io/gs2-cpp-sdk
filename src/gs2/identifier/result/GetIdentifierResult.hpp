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

#ifndef GS2_IDENTIFIER_CONTROL_GETIDENTIFIERRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_GETIDENTIFIERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * GSIを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetIdentifierResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** GSI */
        optional<Identifier> item;

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
    GetIdentifierResult() :
        m_pData(nullptr)
    {}

    GetIdentifierResult(const GetIdentifierResult& getIdentifierResult) :
        Gs2Object(getIdentifierResult),
        m_pData(getIdentifierResult.m_pData != nullptr ? new Data(*getIdentifierResult.m_pData) : nullptr)
    {}

    GetIdentifierResult(GetIdentifierResult&& getIdentifierResult) :
        Gs2Object(std::move(getIdentifierResult)),
        m_pData(getIdentifierResult.m_pData)
    {
        getIdentifierResult.m_pData = nullptr;
    }

    ~GetIdentifierResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetIdentifierResult& operator=(const GetIdentifierResult& getIdentifierResult)
    {
        Gs2Object::operator=(getIdentifierResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getIdentifierResult.m_pData);

        return *this;
    }

    GetIdentifierResult& operator=(GetIdentifierResult&& getIdentifierResult)
    {
        Gs2Object::operator=(std::move(getIdentifierResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getIdentifierResult.m_pData;
        getIdentifierResult.m_pData = nullptr;

        return *this;
    }

    const GetIdentifierResult* operator->() const
    {
        return this;
    }

    GetIdentifierResult* operator->()
    {
        return this;
    }
    /**
     * GSIを取得
     *
     * @return GSI
     */
    const optional<Identifier>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * GSIを設定
     *
     * @param item GSI
     */
    void setItem(const Identifier& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_GETIDENTIFIERRESULT_HPP_