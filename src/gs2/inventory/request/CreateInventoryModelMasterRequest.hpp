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

#ifndef GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERREQUEST_HPP_

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
 * インベントリモデルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateInventoryModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** インベントリの種類名 */
        optional<StringHolder> name;
        /** インベントリモデルマスターの説明 */
        optional<StringHolder> description;
        /** インベントリの種類のメタデータ */
        optional<StringHolder> metadata;
        /** インベントリの初期サイズ */
        optional<Int32> initialCapacity;
        /** インベントリの最大サイズ */
        optional<Int32> maxCapacity;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity)
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
    CreateInventoryModelMasterRequest() = default;
    CreateInventoryModelMasterRequest(const CreateInventoryModelMasterRequest& createInventoryModelMasterRequest) = default;
    CreateInventoryModelMasterRequest(CreateInventoryModelMasterRequest&& createInventoryModelMasterRequest) = default;
    ~CreateInventoryModelMasterRequest() GS2_OVERRIDE = default;

    CreateInventoryModelMasterRequest& operator=(const CreateInventoryModelMasterRequest& createInventoryModelMasterRequest) = default;
    CreateInventoryModelMasterRequest& operator=(CreateInventoryModelMasterRequest&& createInventoryModelMasterRequest) = default;

    CreateInventoryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateInventoryModelMasterRequest);
    }

    const CreateInventoryModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateInventoryModelMasterRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    CreateInventoryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * インベントリの種類名を取得
     *
     * @return インベントリの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * インベントリの種類名を設定
     *
     * @param name インベントリの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * インベントリの種類名を設定
     *
     * @param name インベントリの種類名
     */
    CreateInventoryModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateInventoryModelMasterRequest& withDescription(StringHolder description)
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
    CreateInventoryModelMasterRequest& withMetadata(StringHolder metadata)
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
    CreateInventoryModelMasterRequest& withInitialCapacity(Int32 initialCapacity)
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
    CreateInventoryModelMasterRequest& withMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateInventoryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateInventoryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERREQUEST_HPP_