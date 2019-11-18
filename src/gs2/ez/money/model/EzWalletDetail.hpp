

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

#ifndef GS2_EZ_MONEY_MODEL_EZWALLETDETAIL_HPP_
#define GS2_EZ_MONEY_MODEL_EZWALLETDETAIL_HPP_

#include <gs2/money/model/Wallet.hpp>


namespace gs2 { namespace ez { namespace money {

class EzWalletDetail : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロット番号 */
        gs2::optional<Int32> slot;
        /** 有償課金通貨所持量 */
        gs2::optional<Int32> paid;
        /** 無償課金通貨所持量 */
        gs2::optional<Int32> free;
        /** 最終更新日時 */
        gs2::optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            slot(data.slot),
            paid(data.paid),
            free(data.free),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::money::Wallet& wallet) :
            slot(wallet.getSlot() ? *wallet.getSlot() : 0),
            paid(wallet.getPaid() ? *wallet.getPaid() : 0),
            free(wallet.getFree() ? *wallet.getFree() : 0),
            updatedAt(wallet.getUpdatedAt() ? *wallet.getUpdatedAt() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzWalletDetail() = default;
    EzWalletDetail(const EzWalletDetail& ezWalletDetail) = default;
    EzWalletDetail(EzWalletDetail&& ezWalletDetail) = default;
    ~EzWalletDetail() = default;

    EzWalletDetail(gs2::money::Wallet wallet) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(wallet)
    {}

    EzWalletDetail& operator=(const EzWalletDetail& ezWalletDetail) = default;
    EzWalletDetail& operator=(EzWalletDetail&& ezWalletDetail) = default;

    EzWalletDetail deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzWalletDetail);
    }

    gs2::money::Wallet ToModel() const
    {
        gs2::money::Wallet wallet;
        wallet.setSlot(getSlot());
        wallet.setPaid(getPaid());
        wallet.setFree(getFree());
        wallet.setUpdatedAt(getUpdatedAt());
        return wallet;
    }

    // ========================================
    //   Getters
    // ========================================

    Int32 getSlot() const
    {
        return *ensureData().slot;
    }

    Int32 getPaid() const
    {
        return *ensureData().paid;
    }

    Int32 getFree() const
    {
        return *ensureData().free;
    }

    Int64 getUpdatedAt() const
    {
        return *ensureData().updatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setSlot(Int32 slot)
    {
        ensureData().slot = slot;
    }

    void setPaid(Int32 paid)
    {
        ensureData().paid = paid;
    }

    void setFree(Int32 free)
    {
        ensureData().free = free;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt = updatedAt;
    }

    EzWalletDetail& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    EzWalletDetail& withPaid(Int32 paid)
    {
        setPaid(paid);
        return *this;
    }

    EzWalletDetail& withFree(Int32 free)
    {
        setFree(free);
        return *this;
    }

    EzWalletDetail& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MONEY_EZWALLETDETAIL_HPP_