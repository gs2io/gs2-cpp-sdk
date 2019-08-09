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

#ifndef GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * アイテムをインベントリに追加 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AcquireItemSetByUserIdRequest : public Gs2BasicRequest, public Gs2Inventory
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
        /** アイテムマスターの名前 */
        optional<StringHolder> itemName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 入手する量 */
        optional<Int64> acquireCount;
        /** 有効期限 */
        optional<Int64> expiresAt;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            itemName(data.itemName),
            userId(data.userId),
            acquireCount(data.acquireCount),
            expiresAt(data.expiresAt),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            inventoryName(std::move(data.inventoryName)),
            itemName(std::move(data.itemName)),
            userId(std::move(data.userId)),
            acquireCount(std::move(data.acquireCount)),
            expiresAt(std::move(data.expiresAt)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    AcquireItemSetByUserIdRequest() :
        m_pData(nullptr)
    {}

    AcquireItemSetByUserIdRequest(const AcquireItemSetByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AcquireItemSetByUserIdRequest(AcquireItemSetByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AcquireItemSetByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AcquireItemSetByUserIdRequest& operator=(const AcquireItemSetByUserIdRequest& acquireItemSetByUserIdRequest)
    {
        Gs2BasicRequest::operator=(acquireItemSetByUserIdRequest);
        Gs2Inventory::operator=(acquireItemSetByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*acquireItemSetByUserIdRequest.m_pData);

        return *this;
    }

    AcquireItemSetByUserIdRequest& operator=(AcquireItemSetByUserIdRequest&& acquireItemSetByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(acquireItemSetByUserIdRequest));
        Gs2Inventory::operator=(std::move(acquireItemSetByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = acquireItemSetByUserIdRequest.m_pData;
        acquireItemSetByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const AcquireItemSetByUserIdRequest* operator->() const
    {
        return this;
    }

    AcquireItemSetByUserIdRequest* operator->()
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
    AcquireItemSetByUserIdRequest& withNamespaceName(const Char* namespaceName)
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
    AcquireItemSetByUserIdRequest& withInventoryName(const Char* inventoryName)
    {
        ensureData().inventoryName.emplace(inventoryName);
        return *this;
    }

    /**
     * アイテムマスターの名前を取得
     *
     * @return アイテムマスターの名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    void setItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    AcquireItemSetByUserIdRequest& withItemName(const Char* itemName)
    {
        ensureData().itemName.emplace(itemName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    AcquireItemSetByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 入手する量を取得
     *
     * @return 入手する量
     */
    const optional<Int64>& getAcquireCount() const
    {
        return ensureData().acquireCount;
    }

    /**
     * 入手する量を設定
     *
     * @param acquireCount 入手する量
     */
    void setAcquireCount(Int64 acquireCount)
    {
        ensureData().acquireCount.emplace(acquireCount);
    }

    /**
     * 入手する量を設定
     *
     * @param acquireCount 入手する量
     */
    AcquireItemSetByUserIdRequest& withAcquireCount(Int64 acquireCount)
    {
        ensureData().acquireCount.emplace(acquireCount);
        return *this;
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * 有効期限を設定
     *
     * @param expiresAt 有効期限
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }

    /**
     * 有効期限を設定
     *
     * @param expiresAt 有効期限
     */
    AcquireItemSetByUserIdRequest& withExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    AcquireItemSetByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AcquireItemSetByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AcquireItemSetByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AcquireItemSetByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AcquireItemSetByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_ACQUIREITEMSETBYUSERIDREQUEST_HPP_