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

#ifndef GS2_CONSUMABLEITEM_CONTROL_DELETEINVENTORYBYUSERIDREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_DELETEINVENTORYBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ConsumableItemConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace consumableItem
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteInventoryByUserIdRequest : public Gs2BasicRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "DeleteInventoryByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** 消費型アイテムプールの名前 */
        optional<StringHolder> itemPoolName;
        /** 消費型アイテムの名前 */
        optional<StringHolder> itemName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** 有効期限 */
        optional<Int32> expireAt;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            itemPoolName(data.itemPoolName),
            itemName(data.itemName),
            userId(data.userId),
            expireAt(data.expireAt)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            itemPoolName(std::move(data.itemPoolName)),
            itemName(std::move(data.itemName)),
            userId(std::move(data.userId)),
            expireAt(std::move(data.expireAt))
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
    DeleteInventoryByUserIdRequest() :
        m_pData(nullptr)
    {}

    DeleteInventoryByUserIdRequest(const DeleteInventoryByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteInventoryByUserIdRequest(DeleteInventoryByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteInventoryByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteInventoryByUserIdRequest& operator=(const DeleteInventoryByUserIdRequest& deleteInventoryByUserIdRequest)
    {
        Gs2BasicRequest::operator=(deleteInventoryByUserIdRequest);
        Gs2ConsumableItem::operator=(deleteInventoryByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteInventoryByUserIdRequest.m_pData);

        return *this;
    }

    DeleteInventoryByUserIdRequest& operator=(DeleteInventoryByUserIdRequest&& deleteInventoryByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteInventoryByUserIdRequest));
        Gs2ConsumableItem::operator=(std::move(deleteInventoryByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteInventoryByUserIdRequest.m_pData;
        deleteInventoryByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteInventoryByUserIdRequest* operator->() const
    {
        return this;
    }

    DeleteInventoryByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * 消費型アイテムプールの名前を取得
     *
     * @return 消費型アイテムプールの名前
     */
    const optional<StringHolder>& getItemPoolName() const
    {
        return ensureData().itemPoolName;
    }

    /**
     * 消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 消費型アイテムプールの名前
     */
    void setItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
    }

    /**
     * 消費型アイテムプールの名前を設定
     *
     * @param itemPoolName 消費型アイテムプールの名前
     */
    DeleteInventoryByUserIdRequest& withItemPoolName(const Char* itemPoolName)
    {
        ensureData().itemPoolName.emplace(itemPoolName);
        return *this;
    }

    /**
     * 消費型アイテムの名前を取得
     *
     * @return 消費型アイテムの名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * 消費型アイテムの名前を設定
     *
     * @param itemName 消費型アイテムの名前
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * 消費型アイテムの名前を設定
     *
     * @param itemName 消費型アイテムの名前
     */
    DeleteInventoryByUserIdRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    DeleteInventoryByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int32>& getExpireAt() const
    {
        return ensureData().expireAt;
    }

    /**
     * 有効期限を設定
     *
     * @param expireAt 有効期限
     */
    void setExpireAt(Int32 expireAt)
    {
        ensureData().expireAt.emplace(expireAt);
    }

    /**
     * 有効期限を設定
     *
     * @param expireAt 有効期限
     */
    DeleteInventoryByUserIdRequest& withExpireAt(Int32 expireAt)
    {
        ensureData().expireAt.emplace(expireAt);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteInventoryByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteInventoryByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteInventoryByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteInventoryByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CONSUMABLEITEM_CONTROL_DELETEINVENTORYBYUSERIDREQUEST_HPP_