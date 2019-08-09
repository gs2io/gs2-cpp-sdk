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

#ifndef GS2_INVENTORY_CONTROL_UPDATEITEMMODELMASTERREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_UPDATEITEMMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * アイテムモデルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateItemModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** インベントリの種類名 */
        optional<StringHolder> inventoryName;
        /** アイテムモデルの種類名 */
        optional<StringHolder> itemName;
        /** アイテムモデルマスターの説明 */
        optional<StringHolder> description;
        /** アイテムモデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所有可能な最大数量 */
        optional<Int64> maxCount;
        /** 表示順番 */
        optional<Int32> sortValue;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            itemName(data.itemName),
            description(data.description),
            metadata(data.metadata),
            maxCount(data.maxCount),
            sortValue(data.sortValue)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            inventoryName(std::move(data.inventoryName)),
            itemName(std::move(data.itemName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            maxCount(std::move(data.maxCount)),
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
    UpdateItemModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateItemModelMasterRequest(const UpdateItemModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateItemModelMasterRequest(UpdateItemModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateItemModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateItemModelMasterRequest& operator=(const UpdateItemModelMasterRequest& updateItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateItemModelMasterRequest);
        Gs2Inventory::operator=(updateItemModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateItemModelMasterRequest.m_pData);

        return *this;
    }

    UpdateItemModelMasterRequest& operator=(UpdateItemModelMasterRequest&& updateItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateItemModelMasterRequest));
        Gs2Inventory::operator=(std::move(updateItemModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateItemModelMasterRequest.m_pData;
        updateItemModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateItemModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateItemModelMasterRequest* operator->()
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
    UpdateItemModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryName インベントリの種類名
     */
    UpdateItemModelMasterRequest& withInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
        return *this;
    }

    /**
     * アイテムモデルの種類名を取得
     *
     * @return アイテムモデルの種類名
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param itemName アイテムモデルの種類名
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param itemName アイテムモデルの種類名
     */
    UpdateItemModelMasterRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
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
    UpdateItemModelMasterRequest& withDescription(const Char* description)
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
    UpdateItemModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * 所有可能な最大数量を取得
     *
     * @return 所有可能な最大数量
     */
    const optional<Int64>& getMaxCount() const
    {
        return ensureData().maxCount;
    }

    /**
     * 所有可能な最大数量を設定
     *
     * @param maxCount 所有可能な最大数量
     */
    void setMaxCount(Int64 maxCount)
    {
        ensureData().maxCount.emplace(maxCount);
    }

    /**
     * 所有可能な最大数量を設定
     *
     * @param maxCount 所有可能な最大数量
     */
    UpdateItemModelMasterRequest& withMaxCount(Int64 maxCount)
    {
        ensureData().maxCount.emplace(maxCount);
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
    UpdateItemModelMasterRequest& withSortValue(Int32 sortValue)
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
    UpdateItemModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateItemModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateItemModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateItemModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_UPDATEITEMMODELMASTERREQUEST_HPP_