/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SHOWCASE_CONTROL_DELETESHOWCASEITEMMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_DELETESHOWCASEITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteShowcaseItemMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "DeleteShowcaseItemMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 商品の種類 */
        optional<StringHolder> category;
        /** 商品/商品グループ名 */
        optional<StringHolder> resourceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            category(data.category),
            resourceId(data.resourceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            category(std::move(data.category)),
            resourceId(std::move(data.resourceId))
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
    DeleteShowcaseItemMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteShowcaseItemMasterRequest(const DeleteShowcaseItemMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteShowcaseItemMasterRequest(DeleteShowcaseItemMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteShowcaseItemMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteShowcaseItemMasterRequest& operator=(const DeleteShowcaseItemMasterRequest& deleteShowcaseItemMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteShowcaseItemMasterRequest);
        Gs2Showcase::operator=(deleteShowcaseItemMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteShowcaseItemMasterRequest.m_pData);

        return *this;
    }

    DeleteShowcaseItemMasterRequest& operator=(DeleteShowcaseItemMasterRequest&& deleteShowcaseItemMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteShowcaseItemMasterRequest));
        Gs2Showcase::operator=(std::move(deleteShowcaseItemMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteShowcaseItemMasterRequest.m_pData;
        deleteShowcaseItemMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteShowcaseItemMasterRequest* operator->() const
    {
        return this;
    }

    DeleteShowcaseItemMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ショーケースの名前を取得
     *
     * @return ショーケースの名前
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    DeleteShowcaseItemMasterRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
        return *this;
    }

    /**
     * 商品の種類を取得
     *
     * @return 商品の種類
     */
    const optional<StringHolder>& getCategory() const
    {
        return ensureData().category;
    }

    /**
     * 商品の種類を設定
     *
     * @param category 商品の種類
     */
    void setCategory(const Char* category)
    {
        ensureData().category.emplace(category);
    }

    /**
     * 商品の種類を設定
     *
     * @param category 商品の種類
     */
    DeleteShowcaseItemMasterRequest& withCategory(const Char* category)
    {
        ensureData().category.emplace(category);
        return *this;
    }

    /**
     * 商品/商品グループ名を取得
     *
     * @return 商品/商品グループ名
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * 商品/商品グループ名を設定
     *
     * @param resourceId 商品/商品グループ名
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * 商品/商品グループ名を設定
     *
     * @param resourceId 商品/商品グループ名
     */
    DeleteShowcaseItemMasterRequest& withResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteShowcaseItemMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteShowcaseItemMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteShowcaseItemMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteShowcaseItemMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SHOWCASE_CONTROL_DELETESHOWCASEITEMMASTERREQUEST_HPP_