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

#ifndef GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/Gs2InventoryConst.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * アイテムモデルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateItemModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** アイテムの種類名 */
        optional<StringHolder> inventoryName;
        /** アイテムモデルの種類名 */
        optional<StringHolder> name;
        /** アイテムモデルマスターの説明 */
        optional<StringHolder> description;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** スタック可能な最大数量 */
        optional<Int64> stackingLimit;
        /** スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか */
        optional<Bool> allowMultipleStacks;
        /** 表示順番 */
        optional<Int32> sortValue;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            stackingLimit(data.stackingLimit),
            allowMultipleStacks(data.allowMultipleStacks),
            sortValue(data.sortValue)
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
    CreateItemModelMasterRequest() = default;
    CreateItemModelMasterRequest(const CreateItemModelMasterRequest& createItemModelMasterRequest) = default;
    CreateItemModelMasterRequest(CreateItemModelMasterRequest&& createItemModelMasterRequest) = default;
    ~CreateItemModelMasterRequest() GS2_OVERRIDE = default;

    CreateItemModelMasterRequest& operator=(const CreateItemModelMasterRequest& createItemModelMasterRequest) = default;
    CreateItemModelMasterRequest& operator=(CreateItemModelMasterRequest&& createItemModelMasterRequest) = default;

    CreateItemModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateItemModelMasterRequest);
    }

    const CreateItemModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateItemModelMasterRequest* operator->()
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
    CreateItemModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * アイテムの種類名を取得
     *
     * @return アイテムの種類名
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * アイテムの種類名を設定
     *
     * @param inventoryName アイテムの種類名
     */
    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
    }

    /**
     * アイテムの種類名を設定
     *
     * @param inventoryName アイテムの種類名
     */
    CreateItemModelMasterRequest& withInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
        return *this;
    }

    /**
     * アイテムモデルの種類名を取得
     *
     * @return アイテムモデルの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    CreateItemModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * アイテムモデルマスターの説明を取得
     *
     * @return アイテムモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * アイテムモデルマスターの説明を設定
     *
     * @param description アイテムモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * アイテムモデルマスターの説明を設定
     *
     * @param description アイテムモデルマスターの説明
     */
    CreateItemModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * アイテムモデルの種類のメタデータを取得
     *
     * @return アイテムモデルの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    CreateItemModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * スタック可能な最大数量を取得
     *
     * @return スタック可能な最大数量
     */
    const optional<Int64>& getStackingLimit() const
    {
        return ensureData().stackingLimit;
    }

    /**
     * スタック可能な最大数量を設定
     *
     * @param stackingLimit スタック可能な最大数量
     */
    void setStackingLimit(Int64 stackingLimit)
    {
        ensureData().stackingLimit.emplace(stackingLimit);
    }

    /**
     * スタック可能な最大数量を設定
     *
     * @param stackingLimit スタック可能な最大数量
     */
    CreateItemModelMasterRequest& withStackingLimit(Int64 stackingLimit)
    {
        ensureData().stackingLimit.emplace(stackingLimit);
        return *this;
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを取得
     *
     * @return スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    const optional<Bool>& getAllowMultipleStacks() const
    {
        return ensureData().allowMultipleStacks;
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを設定
     *
     * @param allowMultipleStacks スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    void setAllowMultipleStacks(Bool allowMultipleStacks)
    {
        ensureData().allowMultipleStacks.emplace(allowMultipleStacks);
    }

    /**
     * スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すかを設定
     *
     * @param allowMultipleStacks スタック可能な最大数量を超えた時複数枠にアイテムを保管することを許すか
     */
    CreateItemModelMasterRequest& withAllowMultipleStacks(Bool allowMultipleStacks)
    {
        ensureData().allowMultipleStacks.emplace(allowMultipleStacks);
        return *this;
    }

    /**
     * 表示順番を取得
     *
     * @return 表示順番
     */
    const optional<Int32>& getSortValue() const
    {
        return ensureData().sortValue;
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    void setSortValue(Int32 sortValue)
    {
        ensureData().sortValue.emplace(sortValue);
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    CreateItemModelMasterRequest& withSortValue(Int32 sortValue)
    {
        ensureData().sortValue.emplace(sortValue);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateItemModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateItemModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERREQUEST_HPP_