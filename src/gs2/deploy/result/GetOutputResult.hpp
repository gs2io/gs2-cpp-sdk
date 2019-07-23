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

#ifndef GS2_DEPLOY_CONTROL_GETOUTPUTRESULT_HPP_
#define GS2_DEPLOY_CONTROL_GETOUTPUTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * アウトプットを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetOutputResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アウトプット */
        optional<Output> item;

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
    GetOutputResult() :
        m_pData(nullptr)
    {}

    GetOutputResult(const GetOutputResult& getOutputResult) :
        Gs2Object(getOutputResult),
        m_pData(getOutputResult.m_pData != nullptr ? new Data(*getOutputResult.m_pData) : nullptr)
    {}

    GetOutputResult(GetOutputResult&& getOutputResult) :
        Gs2Object(std::move(getOutputResult)),
        m_pData(getOutputResult.m_pData)
    {
        getOutputResult.m_pData = nullptr;
    }

    ~GetOutputResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetOutputResult& operator=(const GetOutputResult& getOutputResult)
    {
        Gs2Object::operator=(getOutputResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getOutputResult.m_pData);

        return *this;
    }

    GetOutputResult& operator=(GetOutputResult&& getOutputResult)
    {
        Gs2Object::operator=(std::move(getOutputResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getOutputResult.m_pData;
        getOutputResult.m_pData = nullptr;

        return *this;
    }

    const GetOutputResult* operator->() const
    {
        return this;
    }

    GetOutputResult* operator->()
    {
        return this;
    }
    /**
     * アウトプットを取得
     *
     * @return アウトプット
     */
    const optional<Output>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * アウトプットを設定
     *
     * @param item アウトプット
     */
    void setItem(const Output& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETOUTPUTRESULT_HPP_