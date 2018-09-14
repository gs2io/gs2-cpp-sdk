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

#ifndef GS2_CONSUMABLEITEM_CONTROL_ACQUISITIONITEMREQUEST_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_ACQUISITIONITEMREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ConsumableItemConst.hpp"

namespace gs2 { namespace consumableItem {

/**
 * @author Game Server Services, Inc.
 */
class AcquisitionItemRequest : public Gs2UserRequest, public Gs2ConsumableItem
{
public:
    constexpr static const Char* const FUNCTION = "AcquisitionItem";

private:
    class Data : public Gs2Object
    {
    public:
        /** 消費型アイテムプールの名前 */
        optional<StringHolder> itemPoolName;
        /** 消費型アイテムの名前 */
        optional<StringHolder> itemName;
        /** 入手数量 */
        optional<Int32> count;
        /** 有効期限(エポック秒) */
        optional<Int32> expireAt;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            itemPoolName(data.itemPoolName),
            itemName(data.itemName),
            count(data.count),
            expireAt(data.expireAt)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            itemPoolName(std::move(data.itemPoolName)),
            itemName(std::move(data.itemName)),
            count(std::move(data.count)),
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
    AcquisitionItemRequest() :
        m_pData(nullptr)
    {}

    AcquisitionItemRequest(const AcquisitionItemRequest& obj) :
        Gs2UserRequest(obj),
        Gs2ConsumableItem(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AcquisitionItemRequest(AcquisitionItemRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2ConsumableItem(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AcquisitionItemRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AcquisitionItemRequest& operator=(const AcquisitionItemRequest& acquisitionItemRequest)
    {
        Gs2UserRequest::operator=(acquisitionItemRequest);
        Gs2ConsumableItem::operator=(acquisitionItemRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*acquisitionItemRequest.m_pData);

        return *this;
    }

    AcquisitionItemRequest& operator=(AcquisitionItemRequest&& acquisitionItemRequest)
    {
        Gs2UserRequest::operator=(std::move(acquisitionItemRequest));
        Gs2ConsumableItem::operator=(std::move(acquisitionItemRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = acquisitionItemRequest.m_pData;
        acquisitionItemRequest.m_pData = nullptr;

        return *this;
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
    AcquisitionItemRequest& withItemPoolName(const Char* itemPoolName)
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
    AcquisitionItemRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * 入手数量を取得
     *
     * @return 入手数量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 入手数量を設定
     *
     * @param count 入手数量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 入手数量を設定
     *
     * @param count 入手数量
     */
    AcquisitionItemRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
        return *this;
    }

    /**
     * 有効期限(エポック秒)を取得
     *
     * @return 有効期限(エポック秒)
     */
    const optional<Int32>& getExpireAt() const
    {
        return ensureData().expireAt;
    }

    /**
     * 有効期限(エポック秒)を設定
     *
     * @param expireAt 有効期限(エポック秒)
     */
    void setExpireAt(Int32 expireAt)
    {
        ensureData().expireAt.emplace(expireAt);
    }

    /**
     * 有効期限(エポック秒)を設定
     *
     * @param expireAt 有効期限(エポック秒)
     */
    AcquisitionItemRequest& withExpireAt(Int32 expireAt)
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
    AcquisitionItemRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AcquisitionItemRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AcquisitionItemRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AcquisitionItemRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    AcquisitionItemRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_CONSUMABLEITEM_CONTROL_ACQUISITIONITEMREQUEST_HPP_