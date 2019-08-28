

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
    /** スロット番号 */
    gs2::optional<Int32> m_Slot;
    /** 有償課金通貨所持量 */
    gs2::optional<Int32> m_Paid;
    /** 無償課金通貨所持量 */
    gs2::optional<Int32> m_Free;
    /** 最終更新日時 */
    gs2::optional<Int64> m_UpdatedAt;

public:
    EzWalletDetail() = default;

    EzWalletDetail(gs2::money::Wallet wallet) :
        m_Slot(wallet.getSlot() ? *wallet.getSlot() : 0),
        m_Paid(wallet.getPaid() ? *wallet.getPaid() : 0),
        m_Free(wallet.getFree() ? *wallet.getFree() : 0),
        m_UpdatedAt(wallet.getUpdatedAt() ? *wallet.getUpdatedAt() : 0)
    {
    }

    gs2::money::Wallet ToModel() const
    {
        gs2::money::Wallet wallet;
        wallet.setSlot(*m_Slot);
        wallet.setPaid(*m_Paid);
        wallet.setFree(*m_Free);
        wallet.setUpdatedAt(*m_UpdatedAt);
        return wallet;
    }

    // ========================================
    //   Getters
    // ========================================

    Int32 getSlot() const
    {
        return *m_Slot;
    }

    Int32 getPaid() const
    {
        return *m_Paid;
    }

    Int32 getFree() const
    {
        return *m_Free;
    }

    Int64 getUpdatedAt() const
    {
        return *m_UpdatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setSlot(Int32 slot)
    {
        m_Slot = slot;
    }

    void setPaid(Int32 paid)
    {
        m_Paid = paid;
    }

    void setFree(Int32 free)
    {
        m_Free = free;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        m_UpdatedAt = updatedAt;
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