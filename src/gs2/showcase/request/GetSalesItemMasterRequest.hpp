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

#ifndef GS2_SHOWCASE_CONTROL_GETSALESITEMMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_GETSALESITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/showcase/Gs2ShowcaseConst.hpp>
#include <gs2/showcase/model/model.hpp>
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 商品マスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetSalesItemMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 商品名 */
        optional<StringHolder> salesItemName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            salesItemName(data.salesItemName)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetSalesItemMasterRequest() = default;
    GetSalesItemMasterRequest(const GetSalesItemMasterRequest& getSalesItemMasterRequest) = default;
    GetSalesItemMasterRequest(GetSalesItemMasterRequest&& getSalesItemMasterRequest) = default;
    ~GetSalesItemMasterRequest() GS2_OVERRIDE = default;

    GetSalesItemMasterRequest& operator=(const GetSalesItemMasterRequest& getSalesItemMasterRequest) = default;
    GetSalesItemMasterRequest& operator=(GetSalesItemMasterRequest&& getSalesItemMasterRequest) = default;

    GetSalesItemMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetSalesItemMasterRequest);
    }

    const GetSalesItemMasterRequest* operator->() const
    {
        return this;
    }

    GetSalesItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    GetSalesItemMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getSalesItemName() const
    {
        return ensureData().salesItemName;
    }

    /**
     * 商品名を設定
     *
     * @param salesItemName 商品名
     */
    void setSalesItemName(StringHolder salesItemName)
    {
        ensureData().salesItemName.emplace(std::move(salesItemName));
    }

    /**
     * 商品名を設定
     *
     * @param salesItemName 商品名
     */
    GetSalesItemMasterRequest& withSalesItemName(StringHolder salesItemName)
    {
        ensureData().salesItemName.emplace(std::move(salesItemName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetSalesItemMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetSalesItemMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_GETSALESITEMMASTERREQUEST_HPP_