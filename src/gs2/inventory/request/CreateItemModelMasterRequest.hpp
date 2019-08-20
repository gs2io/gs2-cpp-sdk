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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** カテゴリー名 */
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            stackingLimit(data.stackingLimit),
            allowMultipleStacks(data.allowMultipleStacks),
            sortValue(data.sortValue)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            inventoryName(std::move(data.inventoryName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            stackingLimit(std::move(data.stackingLimit)),
            allowMultipleStacks(std::move(data.allowMultipleStacks)),
            sortValue(std::move(data.sortValue))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    CreateItemModelMasterRequest() :
        m_pData(nullptr)
    {}

    CreateItemModelMasterRequest(const CreateItemModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateItemModelMasterRequest(CreateItemModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateItemModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemModelMasterRequest& operator=(const CreateItemModelMasterRequest& createItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(createItemModelMasterRequest);
        Gs2Inventory::operator=(createItemModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemModelMasterRequest.m_pData);

        return *this;
    }

    CreateItemModelMasterRequest& operator=(CreateItemModelMasterRequest&& createItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createItemModelMasterRequest));
        Gs2Inventory::operator=(std::move(createItemModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemModelMasterRequest.m_pData;
        createItemModelMasterRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    CreateItemModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
    }

    /**
     * アイテムの種類名を設定
     *
     * @param inventoryName アイテムの種類名
     */
    CreateItemModelMasterRequest& withInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param name アイテムモデルの種類名
     */
    CreateItemModelMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * アイテムモデルマスターの説明を設定
     *
     * @param description アイテムモデルマスターの説明
     */
    CreateItemModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * アイテムモデルの種類のメタデータを設定
     *
     * @param metadata アイテムモデルの種類のメタデータ
     */
    CreateItemModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    CreateItemModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateItemModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateItemModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateItemModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERREQUEST_HPP_