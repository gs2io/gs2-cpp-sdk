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

#ifndef GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 商品グループマスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteSalesItemGroupMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 商品名 */
        optional<StringHolder> salesItemGroupName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            salesItemGroupName(data.salesItemGroupName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            salesItemGroupName(std::move(data.salesItemGroupName))
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
    DeleteSalesItemGroupMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteSalesItemGroupMasterRequest(const DeleteSalesItemGroupMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteSalesItemGroupMasterRequest(DeleteSalesItemGroupMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteSalesItemGroupMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteSalesItemGroupMasterRequest& operator=(const DeleteSalesItemGroupMasterRequest& deleteSalesItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteSalesItemGroupMasterRequest);
        Gs2Showcase::operator=(deleteSalesItemGroupMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteSalesItemGroupMasterRequest.m_pData);

        return *this;
    }

    DeleteSalesItemGroupMasterRequest& operator=(DeleteSalesItemGroupMasterRequest&& deleteSalesItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteSalesItemGroupMasterRequest));
        Gs2Showcase::operator=(std::move(deleteSalesItemGroupMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteSalesItemGroupMasterRequest.m_pData;
        deleteSalesItemGroupMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteSalesItemGroupMasterRequest* operator->() const
    {
        return this;
    }

    DeleteSalesItemGroupMasterRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DeleteSalesItemGroupMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getSalesItemGroupName() const
    {
        return ensureData().salesItemGroupName;
    }

    /**
     * 商品名を設定
     *
     * @param salesItemGroupName 商品名
     */
    void setSalesItemGroupName(const Char* salesItemGroupName)
    {
        ensureData().salesItemGroupName.emplace(salesItemGroupName);
    }

    /**
     * 商品名を設定
     *
     * @param salesItemGroupName 商品名
     */
    DeleteSalesItemGroupMasterRequest& withSalesItemGroupName(const Char* salesItemGroupName)
    {
        ensureData().salesItemGroupName.emplace(salesItemGroupName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteSalesItemGroupMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteSalesItemGroupMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteSalesItemGroupMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteSalesItemGroupMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERREQUEST_HPP_