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

#ifndef GS2_EZ_LOTTERY_MODEL_EZBOXITEM_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZBOXITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzAcquireAction.hpp"
#include <memory>


namespace gs2 {

namespace lottery {

class BoxItem;

}

namespace ez { namespace lottery {

class EzBoxItem : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 入手アクションのリスト */
        List<EzAcquireAction> acquireActions;
        /** 残り数量 */
        Int32 remaining;
        /** 初期数量 */
        Int32 initial;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::lottery::BoxItem& boxItem);
        Data(const gs2::optional<gs2::lottery::BoxItem>& boxItem);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzBoxItem() = default;
    EzBoxItem(const EzBoxItem& ezBoxItem) = default;
    EzBoxItem(EzBoxItem&& ezBoxItem) = default;
    ~EzBoxItem() = default;

    EzBoxItem(gs2::lottery::BoxItem boxItem);
    EzBoxItem(gs2::optional<gs2::lottery::BoxItem> boxItem);

    EzBoxItem& operator=(const EzBoxItem& ezBoxItem) = default;
    EzBoxItem& operator=(EzBoxItem&& ezBoxItem) = default;

    EzBoxItem deepCopy() const;

    gs2::lottery::BoxItem ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    Int32 getRemaining() const
    {
        return ensureData().remaining;
    }

    Int32 getInitial() const
    {
        return ensureData().initial;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAcquireActions(List<EzAcquireAction> acquireActions)
    {
        ensureData().acquireActions = std::move(acquireActions);
    }

    void setRemaining(Int32 remaining)
    {
        ensureData().remaining = remaining;
    }

    void setInitial(Int32 initial)
    {
        ensureData().initial = initial;
    }

    EzBoxItem& withAcquireActions(List<EzAcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }

    EzBoxItem& withRemaining(Int32 remaining)
    {
        setRemaining(remaining);
        return *this;
    }

    EzBoxItem& withInitial(Int32 initial)
    {
        setInitial(initial);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZBOXITEM_HPP_