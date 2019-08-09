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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESALESITEMGROUPMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESALESITEMGROUPMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 商品グループマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateSalesItemGroupMasterRequest : public Gs2BasicRequest, public Gs2Showcase
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
        /** 商品グループマスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 商品グループに含める商品リスト */
        optional<List<StringHolder>> salesItemNames;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            salesItemGroupName(data.salesItemGroupName),
            description(data.description),
            metadata(data.metadata),
            salesItemNames(data.salesItemNames)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            salesItemGroupName(std::move(data.salesItemGroupName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            salesItemNames(std::move(data.salesItemNames))
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
    UpdateSalesItemGroupMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateSalesItemGroupMasterRequest(const UpdateSalesItemGroupMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateSalesItemGroupMasterRequest(UpdateSalesItemGroupMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateSalesItemGroupMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateSalesItemGroupMasterRequest& operator=(const UpdateSalesItemGroupMasterRequest& updateSalesItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(updateSalesItemGroupMasterRequest);
        Gs2Showcase::operator=(updateSalesItemGroupMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateSalesItemGroupMasterRequest.m_pData);

        return *this;
    }

    UpdateSalesItemGroupMasterRequest& operator=(UpdateSalesItemGroupMasterRequest&& updateSalesItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateSalesItemGroupMasterRequest));
        Gs2Showcase::operator=(std::move(updateSalesItemGroupMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateSalesItemGroupMasterRequest.m_pData;
        updateSalesItemGroupMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateSalesItemGroupMasterRequest* operator->() const
    {
        return this;
    }

    UpdateSalesItemGroupMasterRequest* operator->()
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
    UpdateSalesItemGroupMasterRequest& withNamespaceName(const Char* namespaceName)
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
    UpdateSalesItemGroupMasterRequest& withSalesItemGroupName(const Char* salesItemGroupName)
    {
        ensureData().salesItemGroupName.emplace(salesItemGroupName);
        return *this;
    }

    /**
     * 商品グループマスターの説明を取得
     *
     * @return 商品グループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    UpdateSalesItemGroupMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    UpdateSalesItemGroupMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * 商品グループに含める商品リストを取得
     *
     * @return 商品グループに含める商品リスト
     */
    const optional<List<StringHolder>>& getSalesItemNames() const
    {
        return ensureData().salesItemNames;
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    void setSalesItemNames(const List<StringHolder>& salesItemNames)
    {
        ensureData().salesItemNames.emplace(salesItemNames);
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    UpdateSalesItemGroupMasterRequest& withSalesItemNames(const List<StringHolder>& salesItemNames)
    {
        ensureData().salesItemNames.emplace(salesItemNames);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateSalesItemGroupMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateSalesItemGroupMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateSalesItemGroupMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateSalesItemGroupMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATESALESITEMGROUPMASTERREQUEST_HPP_