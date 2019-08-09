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

#ifndef GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * Noneの一覧を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeItemModelsRequest : public Gs2BasicRequest, public Gs2Inventory
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            inventoryName(std::move(data.inventoryName))
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
    DescribeItemModelsRequest() :
        m_pData(nullptr)
    {}

    DescribeItemModelsRequest(const DescribeItemModelsRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeItemModelsRequest(DescribeItemModelsRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeItemModelsRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeItemModelsRequest& operator=(const DescribeItemModelsRequest& describeItemModelsRequest)
    {
        Gs2BasicRequest::operator=(describeItemModelsRequest);
        Gs2Inventory::operator=(describeItemModelsRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeItemModelsRequest.m_pData);

        return *this;
    }

    DescribeItemModelsRequest& operator=(DescribeItemModelsRequest&& describeItemModelsRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeItemModelsRequest));
        Gs2Inventory::operator=(std::move(describeItemModelsRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeItemModelsRequest.m_pData;
        describeItemModelsRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeItemModelsRequest* operator->() const
    {
        return this;
    }

    DescribeItemModelsRequest* operator->()
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
    DescribeItemModelsRequest& withNamespaceName(const Char* namespaceName)
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
    DescribeItemModelsRequest& withInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeItemModelsRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeItemModelsRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeItemModelsRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeItemModelsRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSREQUEST_HPP_