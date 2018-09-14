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

#ifndef GS2_SHOWCASE_CONTROL_DELETEITEMGROUPMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_DELETEITEMGROUPMASTERREQUEST_HPP_

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
class DeleteItemGroupMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "DeleteItemGroupMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 商品グループの名前 */
        optional<StringHolder> itemGroupName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            itemGroupName(data.itemGroupName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            itemGroupName(std::move(data.itemGroupName))
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
    DeleteItemGroupMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteItemGroupMasterRequest(const DeleteItemGroupMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteItemGroupMasterRequest(DeleteItemGroupMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteItemGroupMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteItemGroupMasterRequest& operator=(const DeleteItemGroupMasterRequest& deleteItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteItemGroupMasterRequest);
        Gs2Showcase::operator=(deleteItemGroupMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteItemGroupMasterRequest.m_pData);

        return *this;
    }

    DeleteItemGroupMasterRequest& operator=(DeleteItemGroupMasterRequest&& deleteItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteItemGroupMasterRequest));
        Gs2Showcase::operator=(std::move(deleteItemGroupMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteItemGroupMasterRequest.m_pData;
        deleteItemGroupMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteItemGroupMasterRequest* operator->() const
    {
        return this;
    }

    DeleteItemGroupMasterRequest* operator->()
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
    DeleteItemGroupMasterRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
        return *this;
    }

    /**
     * 商品グループの名前を取得
     *
     * @return 商品グループの名前
     */
    const optional<StringHolder>& getItemGroupName() const
    {
        return ensureData().itemGroupName;
    }

    /**
     * 商品グループの名前を設定
     *
     * @param itemGroupName 商品グループの名前
     */
    void setItemGroupName(const Char* itemGroupName)
    {
        ensureData().itemGroupName.emplace(itemGroupName);
    }

    /**
     * 商品グループの名前を設定
     *
     * @param itemGroupName 商品グループの名前
     */
    DeleteItemGroupMasterRequest& withItemGroupName(const Char* itemGroupName)
    {
        ensureData().itemGroupName.emplace(itemGroupName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteItemGroupMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteItemGroupMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteItemGroupMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteItemGroupMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SHOWCASE_CONTROL_DELETEITEMGROUPMASTERREQUEST_HPP_