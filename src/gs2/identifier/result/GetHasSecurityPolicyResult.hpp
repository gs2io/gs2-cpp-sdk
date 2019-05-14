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

#ifndef GS2_IDENTIFIER_CONTROL_GETHASSECURITYPOLICYRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_GETHASSECURITYPOLICYRESULT_HPP_

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
 * 割り当てられたセキュリティポリシーの一覧を取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetHasSecurityPolicyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** セキュリティポリシーのリスト */
        optional<List<SecurityPolicy>> items;

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
                        SecurityPolicy item;
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
    GetHasSecurityPolicyResult() :
        m_pData(nullptr)
    {}

    GetHasSecurityPolicyResult(const GetHasSecurityPolicyResult& getHasSecurityPolicyResult) :
        Gs2Object(getHasSecurityPolicyResult),
        m_pData(getHasSecurityPolicyResult.m_pData != nullptr ? new Data(*getHasSecurityPolicyResult.m_pData) : nullptr)
    {}

    GetHasSecurityPolicyResult(GetHasSecurityPolicyResult&& getHasSecurityPolicyResult) :
        Gs2Object(std::move(getHasSecurityPolicyResult)),
        m_pData(getHasSecurityPolicyResult.m_pData)
    {
        getHasSecurityPolicyResult.m_pData = nullptr;
    }

    ~GetHasSecurityPolicyResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetHasSecurityPolicyResult& operator=(const GetHasSecurityPolicyResult& getHasSecurityPolicyResult)
    {
        Gs2Object::operator=(getHasSecurityPolicyResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getHasSecurityPolicyResult.m_pData);

        return *this;
    }

    GetHasSecurityPolicyResult& operator=(GetHasSecurityPolicyResult&& getHasSecurityPolicyResult)
    {
        Gs2Object::operator=(std::move(getHasSecurityPolicyResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getHasSecurityPolicyResult.m_pData;
        getHasSecurityPolicyResult.m_pData = nullptr;

        return *this;
    }

    const GetHasSecurityPolicyResult* operator->() const
    {
        return this;
    }

    GetHasSecurityPolicyResult* operator->()
    {
        return this;
    }
    /**
     * セキュリティポリシーのリストを取得
     *
     * @return セキュリティポリシーのリスト
     */
    const optional<List<SecurityPolicy>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * セキュリティポリシーのリストを設定
     *
     * @param items セキュリティポリシーのリスト
     */
    void setItems(const List<SecurityPolicy>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_GETHASSECURITYPOLICYRESULT_HPP_