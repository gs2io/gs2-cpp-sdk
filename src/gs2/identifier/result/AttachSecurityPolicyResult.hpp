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

#ifndef GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYRESULT_HPP_

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
 * 割り当てられたセキュリティポリシーを新しくユーザーに割り当てます のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AttachSecurityPolicyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 新しくユーザーに割り当てたセキュリティポリシーのリスト */
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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        SecurityPolicy item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
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
    AttachSecurityPolicyResult() :
        m_pData(nullptr)
    {}

    AttachSecurityPolicyResult(const AttachSecurityPolicyResult& attachSecurityPolicyResult) :
        Gs2Object(attachSecurityPolicyResult),
        m_pData(attachSecurityPolicyResult.m_pData != nullptr ? new Data(*attachSecurityPolicyResult.m_pData) : nullptr)
    {}

    AttachSecurityPolicyResult(AttachSecurityPolicyResult&& attachSecurityPolicyResult) :
        Gs2Object(std::move(attachSecurityPolicyResult)),
        m_pData(attachSecurityPolicyResult.m_pData)
    {
        attachSecurityPolicyResult.m_pData = nullptr;
    }

    ~AttachSecurityPolicyResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AttachSecurityPolicyResult& operator=(const AttachSecurityPolicyResult& attachSecurityPolicyResult)
    {
        Gs2Object::operator=(attachSecurityPolicyResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*attachSecurityPolicyResult.m_pData);

        return *this;
    }

    AttachSecurityPolicyResult& operator=(AttachSecurityPolicyResult&& attachSecurityPolicyResult)
    {
        Gs2Object::operator=(std::move(attachSecurityPolicyResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = attachSecurityPolicyResult.m_pData;
        attachSecurityPolicyResult.m_pData = nullptr;

        return *this;
    }

    const AttachSecurityPolicyResult* operator->() const
    {
        return this;
    }

    AttachSecurityPolicyResult* operator->()
    {
        return this;
    }
    /**
     * 新しくユーザーに割り当てたセキュリティポリシーのリストを取得
     *
     * @return 新しくユーザーに割り当てたセキュリティポリシーのリスト
     */
    const optional<List<SecurityPolicy>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 新しくユーザーに割り当てたセキュリティポリシーのリストを設定
     *
     * @param items 新しくユーザーに割り当てたセキュリティポリシーのリスト
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

#endif //GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYRESULT_HPP_