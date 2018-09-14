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

#ifndef GS2_SHOWCASE_CONTROL_UPDATEITEMGROUPMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATEITEMGROUPMASTERREQUEST_HPP_

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
class UpdateItemGroupMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "UpdateItemGroupMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 商品グループの名前 */
        optional<StringHolder> itemGroupName;
        /** 販売している商品名のリスト */
        optional<List<StringHolder>> itemNames;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            itemGroupName(data.itemGroupName),
            itemNames(data.itemNames)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            itemGroupName(std::move(data.itemGroupName)),
            itemNames(std::move(data.itemNames))
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
    UpdateItemGroupMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateItemGroupMasterRequest(const UpdateItemGroupMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateItemGroupMasterRequest(UpdateItemGroupMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateItemGroupMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateItemGroupMasterRequest& operator=(const UpdateItemGroupMasterRequest& updateItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(updateItemGroupMasterRequest);
        Gs2Showcase::operator=(updateItemGroupMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateItemGroupMasterRequest.m_pData);

        return *this;
    }

    UpdateItemGroupMasterRequest& operator=(UpdateItemGroupMasterRequest&& updateItemGroupMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateItemGroupMasterRequest));
        Gs2Showcase::operator=(std::move(updateItemGroupMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateItemGroupMasterRequest.m_pData;
        updateItemGroupMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateItemGroupMasterRequest* operator->() const
    {
        return this;
    }

    UpdateItemGroupMasterRequest* operator->()
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
    UpdateItemGroupMasterRequest& withShowcaseName(const Char* showcaseName)
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
    UpdateItemGroupMasterRequest& withItemGroupName(const Char* itemGroupName)
    {
        ensureData().itemGroupName.emplace(itemGroupName);
        return *this;
    }

    /**
     * 販売している商品名のリストを取得
     *
     * @return 販売している商品名のリスト
     */
    const optional<List<StringHolder>>& getItemNames() const
    {
        return ensureData().itemNames;
    }

    /**
     * 販売している商品名のリストを設定
     *
     * @param itemNames 販売している商品名のリスト
     */
    void setItemNames(const List<StringHolder>& itemNames)
    {
        ensureData().itemNames.emplace(itemNames);
    }

    /**
     * 販売している商品名のリストを設定
     *
     * @param itemNames 販売している商品名のリスト
     */
    UpdateItemGroupMasterRequest& withItemNames(const List<StringHolder>& itemNames)
    {
        ensureData().itemNames.emplace(itemNames);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateItemGroupMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateItemGroupMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateItemGroupMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateItemGroupMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SHOWCASE_CONTROL_UPDATEITEMGROUPMASTERREQUEST_HPP_