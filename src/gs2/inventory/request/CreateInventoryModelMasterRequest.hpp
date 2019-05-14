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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * インベントリマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateInventoryModelMasterRequest : public Gs2BasicRequest, public Gs2Inventory
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
        optional<StringHolder> name;
        /** インベントリマスターの説明 */
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
            categoryName(data.categoryName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            initialCapacity(data.initialCapacity),
            maxCapacity(data.maxCapacity)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            categoryName(std::move(data.categoryName)),
            name(std::move(data.name)),
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
    CreateInventoryModelMasterRequest() :
        m_pData(nullptr)
    {}

    CreateInventoryModelMasterRequest(const CreateInventoryModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateInventoryModelMasterRequest(CreateInventoryModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateInventoryModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateInventoryModelMasterRequest& operator=(const CreateInventoryModelMasterRequest& createInventoryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(createInventoryModelMasterRequest);
        Gs2Inventory::operator=(createInventoryModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createInventoryModelMasterRequest.m_pData);

        return *this;
    }

    CreateInventoryModelMasterRequest& operator=(CreateInventoryModelMasterRequest&& createInventoryModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createInventoryModelMasterRequest));
        Gs2Inventory::operator=(std::move(createInventoryModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createInventoryModelMasterRequest.m_pData;
        createInventoryModelMasterRequest.m_pData = nullptr;

        return *this;
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
    CreateInventoryModelMasterRequest& withCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * インベントリの種類名を設定
     *
     * @param name インベントリの種類名
     */
    CreateInventoryModelMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * インベントリマスターの説明を取得
     *
     * @return インベントリマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * インベントリマスターの説明を設定
     *
     * @param description インベントリマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * インベントリマスターの説明を設定
     *
     * @param description インベントリマスターの説明
     */
    CreateInventoryModelMasterRequest& withDescription(const Char* description)
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
    CreateInventoryModelMasterRequest& withMetadata(const Char* metadata)
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
    CreateInventoryModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateInventoryModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateInventoryModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateInventoryModelMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERREQUEST_HPP_