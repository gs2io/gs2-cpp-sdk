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

#ifndef GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inventory/Gs2InventoryConst.hpp>
#include <gs2/inventory/model/model.hpp>
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * 有効期限ごとのアイテム所持数量を削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteItemSetByUserIdRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** インベントリの名前 */
        optional<StringHolder> inventoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アイテムマスターの名前 */
        optional<StringHolder> itemName;
        /** 有効期限 */
        optional<Int64> expiresAt;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            userId(data.userId),
            itemName(data.itemName),
            expiresAt(data.expiresAt),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    DeleteItemSetByUserIdRequest() = default;
    DeleteItemSetByUserIdRequest(const DeleteItemSetByUserIdRequest& deleteItemSetByUserIdRequest) = default;
    DeleteItemSetByUserIdRequest(DeleteItemSetByUserIdRequest&& deleteItemSetByUserIdRequest) = default;
    ~DeleteItemSetByUserIdRequest() GS2_OVERRIDE = default;

    DeleteItemSetByUserIdRequest& operator=(const DeleteItemSetByUserIdRequest& deleteItemSetByUserIdRequest) = default;
    DeleteItemSetByUserIdRequest& operator=(DeleteItemSetByUserIdRequest&& deleteItemSetByUserIdRequest) = default;

    DeleteItemSetByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteItemSetByUserIdRequest);
    }

    const DeleteItemSetByUserIdRequest* operator->() const
    {
        return this;
    }

    DeleteItemSetByUserIdRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    DeleteItemSetByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * インベントリの名前を取得
     *
     * @return インベントリの名前
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    DeleteItemSetByUserIdRequest& withInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DeleteItemSetByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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
    void setItemName(StringHolder itemName)
    {
        ensureData().itemName.emplace(std::move(itemName));
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    DeleteItemSetByUserIdRequest& withItemName(StringHolder itemName)
    {
        ensureData().itemName.emplace(std::move(itemName));
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
    DeleteItemSetByUserIdRequest& withExpiresAt(Int64 expiresAt)
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    DeleteItemSetByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteItemSetByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteItemSetByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_DELETEITEMSETBYUSERIDREQUEST_HPP_