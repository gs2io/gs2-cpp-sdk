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

#ifndef GS2_INVENTORY_CONTROL_ADDCAPACITYBYUSERIDREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_ADDCAPACITYBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * キャパシティサイズを加算 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AddCapacityByUserIdRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** インベントリモデル名 */
        optional<StringHolder> inventoryModelName;
        /** 現在のインベントリの最大キャパシティ */
        optional<Int32> addCapacityValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            categoryName(data.categoryName),
            userId(data.userId),
            inventoryModelName(data.inventoryModelName),
            addCapacityValue(data.addCapacityValue),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            categoryName(std::move(data.categoryName)),
            userId(std::move(data.userId)),
            inventoryModelName(std::move(data.inventoryModelName)),
            addCapacityValue(std::move(data.addCapacityValue)),
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
    AddCapacityByUserIdRequest() :
        m_pData(nullptr)
    {}

    AddCapacityByUserIdRequest(const AddCapacityByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AddCapacityByUserIdRequest(AddCapacityByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AddCapacityByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AddCapacityByUserIdRequest& operator=(const AddCapacityByUserIdRequest& addCapacityByUserIdRequest)
    {
        Gs2BasicRequest::operator=(addCapacityByUserIdRequest);
        Gs2Inventory::operator=(addCapacityByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*addCapacityByUserIdRequest.m_pData);

        return *this;
    }

    AddCapacityByUserIdRequest& operator=(AddCapacityByUserIdRequest&& addCapacityByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(addCapacityByUserIdRequest));
        Gs2Inventory::operator=(std::move(addCapacityByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = addCapacityByUserIdRequest.m_pData;
        addCapacityByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const AddCapacityByUserIdRequest* operator->() const
    {
        return this;
    }

    AddCapacityByUserIdRequest* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    AddCapacityByUserIdRequest& withCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
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
    AddCapacityByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * インベントリモデル名を取得
     *
     * @return インベントリモデル名
     */
    const optional<StringHolder>& getInventoryModelName() const
    {
        return ensureData().inventoryModelName;
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryModelName インベントリモデル名
     */
    void setInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
    }

    /**
     * インベントリモデル名を設定
     *
     * @param inventoryModelName インベントリモデル名
     */
    AddCapacityByUserIdRequest& withInventoryModelName(const Char* inventoryModelName)
    {
        ensureData().inventoryModelName.emplace(inventoryModelName);
        return *this;
    }

    /**
     * 現在のインベントリの最大キャパシティを取得
     *
     * @return 現在のインベントリの最大キャパシティ
     */
    const optional<Int32>& getAddCapacityValue() const
    {
        return ensureData().addCapacityValue;
    }

    /**
     * 現在のインベントリの最大キャパシティを設定
     *
     * @param addCapacityValue 現在のインベントリの最大キャパシティ
     */
    void setAddCapacityValue(Int32 addCapacityValue)
    {
        ensureData().addCapacityValue.emplace(addCapacityValue);
    }

    /**
     * 現在のインベントリの最大キャパシティを設定
     *
     * @param addCapacityValue 現在のインベントリの最大キャパシティ
     */
    AddCapacityByUserIdRequest& withAddCapacityValue(Int32 addCapacityValue)
    {
        ensureData().addCapacityValue.emplace(addCapacityValue);
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
    AddCapacityByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    AddCapacityByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AddCapacityByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AddCapacityByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AddCapacityByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INVENTORY_CONTROL_ADDCAPACITYBYUSERIDREQUEST_HPP_