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

#ifndef GS2_SHOWCASE_CONTROL_CREATESALESITEMGROUPMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_CREATESALESITEMGROUPMASTERREQUEST_HPP_

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
 * 商品グループマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateSalesItemGroupMasterRequest : public Gs2BasicRequest, public Gs2Showcase
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
        optional<StringHolder> name;
        /** 商品グループマスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 商品グループに含める商品リスト */
        optional<List<StringHolder>> salesItemNames;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata)
        {
            if (data.salesItemNames)
            {
                salesItemNames = data.salesItemNames->deepCopy();
            }
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
    CreateSalesItemGroupMasterRequest() = default;
    CreateSalesItemGroupMasterRequest(const CreateSalesItemGroupMasterRequest& createSalesItemGroupMasterRequest) = default;
    CreateSalesItemGroupMasterRequest(CreateSalesItemGroupMasterRequest&& createSalesItemGroupMasterRequest) = default;
    ~CreateSalesItemGroupMasterRequest() GS2_OVERRIDE = default;

    CreateSalesItemGroupMasterRequest& operator=(const CreateSalesItemGroupMasterRequest& createSalesItemGroupMasterRequest) = default;
    CreateSalesItemGroupMasterRequest& operator=(CreateSalesItemGroupMasterRequest&& createSalesItemGroupMasterRequest) = default;

    CreateSalesItemGroupMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateSalesItemGroupMasterRequest);
    }

    const CreateSalesItemGroupMasterRequest* operator->() const
    {
        return this;
    }

    CreateSalesItemGroupMasterRequest* operator->()
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
    CreateSalesItemGroupMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    CreateSalesItemGroupMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 商品グループマスターの説明を取得
     *
     * @return 商品グループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    CreateSalesItemGroupMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    CreateSalesItemGroupMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 商品グループに含める商品リストを取得
     *
     * @return 商品グループに含める商品リスト
     */
    const optional<List<StringHolder>>& getSalesItemNames() const
    {
        return ensureData().salesItemNames;
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    void setSalesItemNames(List<StringHolder> salesItemNames)
    {
        ensureData().salesItemNames.emplace(std::move(salesItemNames));
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    CreateSalesItemGroupMasterRequest& withSalesItemNames(List<StringHolder> salesItemNames)
    {
        ensureData().salesItemNames.emplace(std::move(salesItemNames));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateSalesItemGroupMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateSalesItemGroupMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_CREATESALESITEMGROUPMASTERREQUEST_HPP_