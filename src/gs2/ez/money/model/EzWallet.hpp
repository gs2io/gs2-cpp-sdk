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

#ifndef GS2_EZ_MONEY_MODEL_EZWALLET_HPP_
#define GS2_EZ_MONEY_MODEL_EZWALLET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace money {

class Wallet;

}

namespace ez { namespace money {

class EzWallet : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロット番号 */
        Int32 slot;
        /** 有償課金通貨所持量 */
        Int32 paid;
        /** 無償課金通貨所持量 */
        Int32 free;
        /** 最終更新日時 */
        Int64 updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::money::Wallet& wallet);
        Data(const gs2::optional<gs2::money::Wallet>& wallet);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzWallet() = default;
    EzWallet(const EzWallet& ezWallet) = default;
    EzWallet(EzWallet&& ezWallet) = default;
    ~EzWallet() = default;

    EzWallet(gs2::money::Wallet wallet);
    EzWallet(gs2::optional<gs2::money::Wallet> wallet);

    EzWallet& operator=(const EzWallet& ezWallet) = default;
    EzWallet& operator=(EzWallet&& ezWallet) = default;

    EzWallet deepCopy() const;

    gs2::money::Wallet ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    Int32 getSlot() const
    {
        return ensureData().slot;
    }

    Int32 getPaid() const
    {
        return ensureData().paid;
    }

    Int32 getFree() const
    {
        return ensureData().free;
    }

    Int64 getUpdatedAt() const
    {
        return ensureData().updatedAt;
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

    EzWallet& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    EzWallet& withPaid(Int32 paid)
    {
        setPaid(paid);
        return *this;
    }

    EzWallet& withFree(Int32 free)
    {
        setFree(free);
        return *this;
    }

    EzWallet& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MONEY_EZWALLET_HPP_