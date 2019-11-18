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

#ifndef GS2_MONEY_MODEL_WALLET_HPP_
#define GS2_MONEY_MODEL_WALLET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレット
 *
 * @author Game Server Services, Inc.
 *
 */
class Wallet : public Gs2Object
{
    friend bool operator!=(const Wallet& lhs, const Wallet& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレット */
        optional<StringHolder> walletId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** 有償課金通貨所持量 */
        optional<Int32> paid;
        /** 無償課金通貨所持量 */
        optional<Int32> free;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            walletId(data.walletId),
            userId(data.userId),
            slot(data.slot),
            paid(data.paid),
            free(data.free),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "walletId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->walletId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "slot") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->slot = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "paid") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->paid = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "free") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->free = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Wallet() = default;
    Wallet(const Wallet& wallet) = default;
    Wallet(Wallet&& wallet) = default;
    ~Wallet() = default;

    Wallet& operator=(const Wallet& wallet) = default;
    Wallet& operator=(Wallet&& wallet) = default;

    Wallet deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Wallet);
    }

    const Wallet* operator->() const
    {
        return this;
    }

    Wallet* operator->()
    {
        return this;
    }
    /**
     * ウォレットを取得
     *
     * @return ウォレット
     */
    const optional<StringHolder>& getWalletId() const
    {
        return ensureData().walletId;
    }

    /**
     * ウォレットを設定
     *
     * @param walletId ウォレット
     */
    void setWalletId(StringHolder walletId)
    {
        ensureData().walletId.emplace(std::move(walletId));
    }

    /**
     * ウォレットを設定
     *
     * @param walletId ウォレット
     */
    Wallet& withWalletId(StringHolder walletId)
    {
        setWalletId(std::move(walletId));
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
    Wallet& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    Wallet& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    /**
     * 有償課金通貨所持量を取得
     *
     * @return 有償課金通貨所持量
     */
    const optional<Int32>& getPaid() const
    {
        return ensureData().paid;
    }

    /**
     * 有償課金通貨所持量を設定
     *
     * @param paid 有償課金通貨所持量
     */
    void setPaid(Int32 paid)
    {
        ensureData().paid.emplace(paid);
    }

    /**
     * 有償課金通貨所持量を設定
     *
     * @param paid 有償課金通貨所持量
     */
    Wallet& withPaid(Int32 paid)
    {
        setPaid(paid);
        return *this;
    }

    /**
     * 無償課金通貨所持量を取得
     *
     * @return 無償課金通貨所持量
     */
    const optional<Int32>& getFree() const
    {
        return ensureData().free;
    }

    /**
     * 無償課金通貨所持量を設定
     *
     * @param free 無償課金通貨所持量
     */
    void setFree(Int32 free)
    {
        ensureData().free.emplace(free);
    }

    /**
     * 無償課金通貨所持量を設定
     *
     * @param free 無償課金通貨所持量
     */
    Wallet& withFree(Int32 free)
    {
        setFree(free);
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
    Wallet& withCreatedAt(Int64 createdAt)
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
    Wallet& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Wallet& lhs, const Wallet& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->walletId != lhr.m_pData->walletId)
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
        if (lhs.m_pData->paid != lhr.m_pData->paid)
        {
            return true;
        }
        if (lhs.m_pData->free != lhr.m_pData->free)
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

inline bool operator==(const Wallet& lhs, const Wallet& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_WALLET_HPP_