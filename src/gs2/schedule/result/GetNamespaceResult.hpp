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

#ifndef GS2_SCHEDULE_CONTROL_GETNAMESPACERESULT_HPP_
#define GS2_SCHEDULE_CONTROL_GETNAMESPACERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * ネームスペースを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetNamespaceResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<Namespace> item;

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
    GetNamespaceResult() :
        m_pData(nullptr)
    {}

    GetNamespaceResult(const GetNamespaceResult& getNamespaceResult) :
        Gs2Object(getNamespaceResult),
        m_pData(getNamespaceResult.m_pData != nullptr ? new Data(*getNamespaceResult.m_pData) : nullptr)
    {}

    GetNamespaceResult(GetNamespaceResult&& getNamespaceResult) :
        Gs2Object(std::move(getNamespaceResult)),
        m_pData(getNamespaceResult.m_pData)
    {
        getNamespaceResult.m_pData = nullptr;
    }

    ~GetNamespaceResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetNamespaceResult& operator=(const GetNamespaceResult& getNamespaceResult)
    {
        Gs2Object::operator=(getNamespaceResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getNamespaceResult.m_pData);

        return *this;
    }

    GetNamespaceResult& operator=(GetNamespaceResult&& getNamespaceResult)
    {
        Gs2Object::operator=(std::move(getNamespaceResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getNamespaceResult.m_pData;
        getNamespaceResult.m_pData = nullptr;

        return *this;
    }

    const GetNamespaceResult* operator->() const
    {
        return this;
    }

    GetNamespaceResult* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<Namespace>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ネームスペースを設定
     *
     * @param item ネームスペース
     */
    void setItem(const Namespace& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_GETNAMESPACERESULT_HPP_