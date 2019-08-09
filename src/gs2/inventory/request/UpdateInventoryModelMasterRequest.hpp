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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** カテゴリー名 */
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            description(data.description),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            inventoryName(std::move(data.inventoryName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            initialCapacity(std::move(data.initialCapacity)),
            maxCapacity(std::move(data.maxCapacity))
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
    UpdateInventoryModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateInventoryModelMasterRequest(const UpdateInventoryModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateInventoryModelMasterRequest(UpdateInventoryModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateInventoryModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateInventoryModelMasterRequest& operator=(const UpdateInventoryModelMasterRequest& updateInventoryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateInventoryModelMasterRequest);
        Gs2Inventory::operator=(updateInventoryModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateInventoryModelMasterRequest.m_pData);

        return *this;
    }

    UpdateInventoryModelMasterRequest& operator=(UpdateInventoryModelMasterRequest&& updateInventoryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateInventoryModelMasterRequest));
        Gs2Inventory::operator=(std::move(updateInventoryModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateInventoryModelMasterRequest.m_pData;
        updateInventoryModelMasterRequest.m_pData = nullptr;

        return *this;
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
    UpdateInventoryModelMasterRequest& withNamespaceName(const Char* namespaceName)
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
    UpdateInventoryModelMasterRequest& withInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * インベントリモデルマスターの説明を設定
     *
     * @param description インベントリモデルマスターの説明
     */
    UpdateInventoryModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * インベントリの種類のメタデータを設定
     *
     * @param metadata インベントリの種類のメタデータ
     */
    UpdateInventoryModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateInventoryModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateInventoryModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateInventoryModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateInventoryModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_UPDATEINVENTORYMODELMASTERREQUEST_HPP_