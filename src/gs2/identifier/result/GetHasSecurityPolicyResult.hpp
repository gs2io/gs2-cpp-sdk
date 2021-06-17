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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/identifier/model/model.hpp>
#include <memory>

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
                        SecurityPolicy item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetHasSecurityPolicyResult() = default;
    GetHasSecurityPolicyResult(const GetHasSecurityPolicyResult& getHasSecurityPolicyResult) = default;
    GetHasSecurityPolicyResult(GetHasSecurityPolicyResult&& getHasSecurityPolicyResult) = default;
    ~GetHasSecurityPolicyResult() = default;

    GetHasSecurityPolicyResult& operator=(const GetHasSecurityPolicyResult& getHasSecurityPolicyResult) = default;
    GetHasSecurityPolicyResult& operator=(GetHasSecurityPolicyResult&& getHasSecurityPolicyResult) = default;

    GetHasSecurityPolicyResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetHasSecurityPolicyResult);
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
    void setItems(List<SecurityPolicy> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetHasSecurityPolicyResult> AsyncGetHasSecurityPolicyResult;

} }

#endif //GS2_IDENTIFIER_CONTROL_GETHASSECURITYPOLICYRESULT_HPP_