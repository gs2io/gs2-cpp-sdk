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

#ifndef GS2_MONEY_MODEL_WALLETDETAIL_HPP_
#define GS2_MONEY_MODEL_WALLETDETAIL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレットの詳細
 *
 * @author Game Server Services, Inc.
 *
 */
class WalletDetail : public Gs2Object
{
    friend bool operator!=(const WalletDetail& lhs, const WalletDetail& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレットの詳細 */
        optional<StringHolder> walletDetailId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** None */
        optional<Int32> slot;
        /** 単価 */
        optional<Float> price;
        /** 所持量 */
        optional<Int32> count;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            walletDetailId(data.walletDetailId),
            userId(data.userId),
            slot(data.slot),
            price(data.price),
            count(data.count),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            walletDetailId(std::move(data.walletDetailId)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            price(std::move(data.price)),
            count(std::move(data.count)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "walletDetailId") == 0) {
                if (jsonValue.IsString())
                {
                    this->walletDetailId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "slot") == 0) {
                if (jsonValue.IsInt())
                {
                    this->slot = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
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
    WalletDetail() :
        m_pData(nullptr)
    {}

    WalletDetail(const WalletDetail& walletDetail) :
        Gs2Object(walletDetail),
        m_pData(walletDetail.m_pData != nullptr ? new Data(*walletDetail.m_pData) : nullptr)
    {}

    WalletDetail(WalletDetail&& walletDetail) :
        Gs2Object(std::move(walletDetail)),
        m_pData(walletDetail.m_pData)
    {
        walletDetail.m_pData = nullptr;
    }

    ~WalletDetail()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WalletDetail& operator=(const WalletDetail& walletDetail)
    {
        Gs2Object::operator=(walletDetail);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*walletDetail.m_pData);

        return *this;
    }

    WalletDetail& operator=(WalletDetail&& walletDetail)
    {
        Gs2Object::operator=(std::move(walletDetail));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = walletDetail.m_pData;
        walletDetail.m_pData = nullptr;

        return *this;
    }

    const WalletDetail* operator->() const
    {
        return this;
    }

    WalletDetail* operator->()
    {
        return this;
    }
    /**
     * ウォレットの詳細を取得
     *
     * @return ウォレットの詳細
     */
    const optional<StringHolder>& getWalletDetailId() const
    {
        return ensureData().walletDetailId;
    }

    /**
     * ウォレットの詳細を設定
     *
     * @param walletDetailId ウォレットの詳細
     */
    void setWalletDetailId(const Char* walletDetailId)
    {
        ensureData().walletDetailId.emplace(walletDetailId);
    }

    /**
     * ウォレットの詳細を設定
     *
     * @param walletDetailId ウォレットの詳細
     */
    WalletDetail& withWalletDetailId(const Char* walletDetailId)
    {
        setWalletDetailId(walletDetailId);
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
    WalletDetail& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    WalletDetail& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    /**
     * 単価を取得
     *
     * @return 単価
     */
    const optional<Float>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    void setPrice(Float price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    WalletDetail& withPrice(Float price)
    {
        setPrice(price);
        return *this;
    }

    /**
     * 所持量を取得
     *
     * @return 所持量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持量を設定
     *
     * @param count 所持量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 所持量を設定
     *
     * @param count 所持量
     */
    WalletDetail& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    WalletDetail& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    WalletDetail& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WalletDetail& lhs, const WalletDetail& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->walletDetailId != lhr.m_pData->walletDetailId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->slot != lhr.m_pData->slot)
        {
            return true;
        }
        if (lhs.m_pData->price != lhr.m_pData->price)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const WalletDetail& lhs, const WalletDetail& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_WALLETDETAIL_HPP_