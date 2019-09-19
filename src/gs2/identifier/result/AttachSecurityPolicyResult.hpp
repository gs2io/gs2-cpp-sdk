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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"
#include <memory>

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
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

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AttachSecurityPolicyResult() = default;
    AttachSecurityPolicyResult(const AttachSecurityPolicyResult& attachSecurityPolicyResult) = default;
    AttachSecurityPolicyResult(AttachSecurityPolicyResult&& attachSecurityPolicyResult) = default;
    ~AttachSecurityPolicyResult() = default;

    AttachSecurityPolicyResult& operator=(const AttachSecurityPolicyResult& attachSecurityPolicyResult) = default;
    AttachSecurityPolicyResult& operator=(AttachSecurityPolicyResult&& attachSecurityPolicyResult) = default;

    AttachSecurityPolicyResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AttachSecurityPolicyResult);
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
    void setItems(List<SecurityPolicy> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<AttachSecurityPolicyResult> AsyncAttachSecurityPolicyResult;

} }

#endif //GS2_IDENTIFIER_CONTROL_ATTACHSECURITYPOLICYRESULT_HPP_