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

#ifndef GS2_INVENTORY_CONTROL_VERIFYREFERENCEOFBYUSERIDREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_VERIFYREFERENCEOFBYUSERIDREQUEST_HPP_

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
 * 参照元に関する検証 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class VerifyReferenceOfByUserIdRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** インベントリの名前 */
        optional<StringHolder> inventoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アイテムマスターの名前 */
        optional<StringHolder> itemName;
        /** アイテムセットを識別する名前 */
        optional<StringHolder> itemSetName;
        /** この所持品の参照元 */
        optional<StringHolder> referenceOf;
        /** 検証の種類 */
        optional<StringHolder> verifyType;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            inventoryName(data.inventoryName),
            userId(data.userId),
            itemName(data.itemName),
            itemSetName(data.itemSetName),
            referenceOf(data.referenceOf),
            verifyType(data.verifyType),
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
    VerifyReferenceOfByUserIdRequest() = default;
    VerifyReferenceOfByUserIdRequest(const VerifyReferenceOfByUserIdRequest& verifyReferenceOfByUserIdRequest) = default;
    VerifyReferenceOfByUserIdRequest(VerifyReferenceOfByUserIdRequest&& verifyReferenceOfByUserIdRequest) = default;
    ~VerifyReferenceOfByUserIdRequest() GS2_OVERRIDE = default;

    VerifyReferenceOfByUserIdRequest& operator=(const VerifyReferenceOfByUserIdRequest& verifyReferenceOfByUserIdRequest) = default;
    VerifyReferenceOfByUserIdRequest& operator=(VerifyReferenceOfByUserIdRequest&& verifyReferenceOfByUserIdRequest) = default;

    VerifyReferenceOfByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(VerifyReferenceOfByUserIdRequest);
    }

    const VerifyReferenceOfByUserIdRequest* operator->() const
    {
        return this;
    }

    VerifyReferenceOfByUserIdRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    VerifyReferenceOfByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    VerifyReferenceOfByUserIdRequest& withInventoryName(StringHolder inventoryName)
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
    VerifyReferenceOfByUserIdRequest& withUserId(StringHolder userId)
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
    VerifyReferenceOfByUserIdRequest& withItemName(StringHolder itemName)
    {
        ensureData().itemName.emplace(std::move(itemName));
        return *this;
    }

    /**
     * アイテムセットを識別する名前を取得
     *
     * @return アイテムセットを識別する名前
     */
    const optional<StringHolder>& getItemSetName() const
    {
        return ensureData().itemSetName;
    }

    /**
     * アイテムセットを識別する名前を設定
     *
     * @param itemSetName アイテムセットを識別する名前
     */
    void setItemSetName(StringHolder itemSetName)
    {
        ensureData().itemSetName.emplace(std::move(itemSetName));
    }

    /**
     * アイテムセットを識別する名前を設定
     *
     * @param itemSetName アイテムセットを識別する名前
     */
    VerifyReferenceOfByUserIdRequest& withItemSetName(StringHolder itemSetName)
    {
        ensureData().itemSetName.emplace(std::move(itemSetName));
        return *this;
    }

    /**
     * この所持品の参照元を取得
     *
     * @return この所持品の参照元
     */
    const optional<StringHolder>& getReferenceOf() const
    {
        return ensureData().referenceOf;
    }

    /**
     * この所持品の参照元を設定
     *
     * @param referenceOf この所持品の参照元
     */
    void setReferenceOf(StringHolder referenceOf)
    {
        ensureData().referenceOf.emplace(std::move(referenceOf));
    }

    /**
     * この所持品の参照元を設定
     *
     * @param referenceOf この所持品の参照元
     */
    VerifyReferenceOfByUserIdRequest& withReferenceOf(StringHolder referenceOf)
    {
        ensureData().referenceOf.emplace(std::move(referenceOf));
        return *this;
    }

    /**
     * 検証の種類を取得
     *
     * @return 検証の種類
     */
    const optional<StringHolder>& getVerifyType() const
    {
        return ensureData().verifyType;
    }

    /**
     * 検証の種類を設定
     *
     * @param verifyType 検証の種類
     */
    void setVerifyType(StringHolder verifyType)
    {
        ensureData().verifyType.emplace(std::move(verifyType));
    }

    /**
     * 検証の種類を設定
     *
     * @param verifyType 検証の種類
     */
    VerifyReferenceOfByUserIdRequest& withVerifyType(StringHolder verifyType)
    {
        ensureData().verifyType.emplace(std::move(verifyType));
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
    VerifyReferenceOfByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    VerifyReferenceOfByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VerifyReferenceOfByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_VERIFYREFERENCEOFBYUSERIDREQUEST_HPP_