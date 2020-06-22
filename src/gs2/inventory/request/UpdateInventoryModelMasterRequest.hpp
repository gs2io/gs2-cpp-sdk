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

#ifndef GS2_INVENTORY_CONTROL_UPDATEINVENTORYMODELMASTERREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_UPDATEINVENTORYMODELMASTERREQUEST_HPP_

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
 * インベントリモデルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateInventoryModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** インベントリの種類名 */
        optional<StringHolder> inventoryName;
        /** インベントリモデルマスターの説明 */
        optional<StringHolder> description;
        /** インベントリの種類のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリの初期サイズ */
        optional<Int32> initialCapacity;
        /** インベントリの最大サイズ */
        optional<Int32> maxCapacity;
        /** 参照元が登録されているアイテムセットは削除できなくする */
        optional<Bool> protectReferencedItem;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            description(data.description),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity),
            protectReferencedItem(data.protectReferencedItem)
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
    UpdateInventoryModelMasterRequest() = default;
    UpdateInventoryModelMasterRequest(const UpdateInventoryModelMasterRequest& updateInventoryModelMasterRequest) = default;
    UpdateInventoryModelMasterRequest(UpdateInventoryModelMasterRequest&& updateInventoryModelMasterRequest) = default;
    ~UpdateInventoryModelMasterRequest() GS2_OVERRIDE = default;

    UpdateInventoryModelMasterRequest& operator=(const UpdateInventoryModelMasterRequest& updateInventoryModelMasterRequest) = default;
    UpdateInventoryModelMasterRequest& operator=(UpdateInventoryModelMasterRequest&& updateInventoryModelMasterRequest) = default;

    UpdateInventoryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateInventoryModelMasterRequest);
    }

    const UpdateInventoryModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateInventoryModelMasterRequest* operator->()
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
    UpdateInventoryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * インベントリの種類名を取得
     *
     * @return インベントリの種類名
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryName インベントリの種類名
     */
    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryName インベントリの種類名
     */
    UpdateInventoryModelMasterRequest& withInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
        return *this;
    }

    /**
     * インベントリモデルマスターの説明を取得
     *
     * @return インベントリモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * インベントリモデルマスターの説明を設定
     *
     * @param description インベントリモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * インベントリモデルマスターの説明を設定
     *
     * @param description インベントリモデルマスターの説明
     */
    UpdateInventoryModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * インベントリの種類のメタデータを取得
     *
     * @return インベントリの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * インベントリの種類のメタデータを設定
     *
     * @param metadata インベントリの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * インベントリの種類のメタデータを設定
     *
     * @param metadata インベントリの種類のメタデータ
     */
    UpdateInventoryModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * インベントリの初期サイズを取得
     *
     * @return インベントリの初期サイズ
     */
    const optional<Int32>& getInitialCapacity() const
    {
        return ensureData().initialCapacity;
    }

    /**
     * インベントリの初期サイズを設定
     *
     * @param initialCapacity インベントリの初期サイズ
     */
    void setInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity.emplace(initialCapacity);
    }

    /**
     * インベントリの初期サイズを設定
     *
     * @param initialCapacity インベントリの初期サイズ
     */
    UpdateInventoryModelMasterRequest& withInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity.emplace(initialCapacity);
        return *this;
    }

    /**
     * インベントリの最大サイズを取得
     *
     * @return インベントリの最大サイズ
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * インベントリの最大サイズを設定
     *
     * @param maxCapacity インベントリの最大サイズ
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
    }

    /**
     * インベントリの最大サイズを設定
     *
     * @param maxCapacity インベントリの最大サイズ
     */
    UpdateInventoryModelMasterRequest& withMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
        return *this;
    }

    /**
     * 参照元が登録されているアイテムセットは削除できなくするを取得
     *
     * @return 参照元が登録されているアイテムセットは削除できなくする
     */
    const optional<Bool>& getProtectReferencedItem() const
    {
        return ensureData().protectReferencedItem;
    }

    /**
     * 参照元が登録されているアイテムセットは削除できなくするを設定
     *
     * @param protectReferencedItem 参照元が登録されているアイテムセットは削除できなくする
     */
    void setProtectReferencedItem(Bool protectReferencedItem)
    {
        ensureData().protectReferencedItem.emplace(protectReferencedItem);
    }

    /**
     * 参照元が登録されているアイテムセットは削除できなくするを設定
     *
     * @param protectReferencedItem 参照元が登録されているアイテムセットは削除できなくする
     */
    UpdateInventoryModelMasterRequest& withProtectReferencedItem(Bool protectReferencedItem)
    {
        ensureData().protectReferencedItem.emplace(protectReferencedItem);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateInventoryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateInventoryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_UPDATEINVENTORYMODELMASTERREQUEST_HPP_