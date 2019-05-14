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

#ifndef GS2_INVENTORY_CONTROL_GETITEMMODELMASTERREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_GETITEMMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * アイテムマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetItemModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** インベントリの種類名 */
        optional<StringHolder> inventoryModelName;
        /** アイテムモデルの種類名 */
        optional<StringHolder> itemModelName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            categoryName(data.categoryName),
            inventoryModelName(data.inventoryModelName),
            itemModelName(data.itemModelName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            categoryName(std::move(data.categoryName)),
            inventoryModelName(std::move(data.inventoryModelName)),
            itemModelName(std::move(data.itemModelName))
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
    GetItemModelMasterRequest() :
        m_pData(nullptr)
    {}

    GetItemModelMasterRequest(const GetItemModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetItemModelMasterRequest(GetItemModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetItemModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetItemModelMasterRequest& operator=(const GetItemModelMasterRequest& getItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(getItemModelMasterRequest);
        Gs2Inventory::operator=(getItemModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getItemModelMasterRequest.m_pData);

        return *this;
    }

    GetItemModelMasterRequest& operator=(GetItemModelMasterRequest&& getItemModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(getItemModelMasterRequest));
        Gs2Inventory::operator=(std::move(getItemModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getItemModelMasterRequest.m_pData;
        getItemModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const GetItemModelMasterRequest* operator->() const
    {
        return this;
    }

    GetItemModelMasterRequest* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    GetItemModelMasterRequest& withCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
        return *this;
    }

    /**
     * インベントリの種類名を取得
     *
     * @return インベントリの種類名
     */
    const optional<StringHolder>& getInventoryModelName() const
    {
        return ensureData().inventoryModelName;
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryModelName インベントリの種類名
     */
    void setInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
    }

    /**
     * インベントリの種類名を設定
     *
     * @param inventoryModelName インベントリの種類名
     */
    GetItemModelMasterRequest& withInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
        return *this;
    }

    /**
     * アイテムモデルの種類名を取得
     *
     * @return アイテムモデルの種類名
     */
    const optional<StringHolder>& getItemModelName() const
    {
        return ensureData().itemModelName;
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param itemModelName アイテムモデルの種類名
     */
    void setItemModelName(const Char* itemModelName)
    {
        ensureData().itemModelName.emplace(itemModelName);
    }

    /**
     * アイテムモデルの種類名を設定
     *
     * @param itemModelName アイテムモデルの種類名
     */
    GetItemModelMasterRequest& withItemModelName(const Char* itemModelName)
    {
        ensureData().itemModelName.emplace(itemModelName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetItemModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetItemModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetItemModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetItemModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_GETITEMMODELMASTERREQUEST_HPP_