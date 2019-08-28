

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

#include <gs2/lottery/model/BoxItem.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace lottery {

class EzBoxItem : public gs2::Gs2Object
{
private:
    /** 入手アクションのリスト */
    gs2::optional<List<EzAcquireAction>> m_AcquireActions;
    /** 残り数量 */
    gs2::optional<Int32> m_Remaining;
    /** 初期数量 */
    gs2::optional<Int32> m_Initial;

public:
    EzBoxItem() = default;

    EzBoxItem(gs2::lottery::BoxItem boxItem) :
        m_Remaining(boxItem.getRemaining() ? *boxItem.getRemaining() : 0),
        m_Initial(boxItem.getInitial() ? *boxItem.getInitial() : 0)
    {
        m_AcquireActions.emplace();
        if (boxItem.getAcquireActions())
        {
            for (int i = 0; i < boxItem.getAcquireActions()->getCount(); ++i)
            {
                *m_AcquireActions += EzAcquireAction((*boxItem.getAcquireActions())[i]);
            }
        }
    }

    gs2::lottery::BoxItem ToModel() const
    {
        gs2::lottery::BoxItem boxItem;
        {
            gs2::List<gs2::lottery::AcquireAction> list;
            auto& acquireActions = *m_AcquireActions;
            for (int i = 0; i < acquireActions.getCount(); ++i)
            {
                list += acquireActions[i].ToModel();
            }
            boxItem.setAcquireActions(list);
        }
        boxItem.setRemaining(*m_Remaining);
        boxItem.setInitial(*m_Initial);
        return boxItem;
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return *m_AcquireActions;
    }

    List<EzAcquireAction>& getAcquireActions()
    {
        return *m_AcquireActions;
    }

    Int32 getRemaining() const
    {
        return *m_Remaining;
    }

    Int32 getInitial() const
    {
        return *m_Initial;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAcquireActions(const List<EzAcquireAction>& acquireActions)
    {
        m_AcquireActions = acquireActions;
    }

    void setAcquireActions(List<EzAcquireAction>&& acquireActions)
    {
        m_AcquireActions = std::move(acquireActions);
    }

    void setRemaining(Int32 remaining)
    {
        m_Remaining = remaining;
    }

    void setInitial(Int32 initial)
    {
        m_Initial = initial;
    }

    EzBoxItem& withAcquireActions(const List<EzAcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
        return *this;
    }

    EzBoxItem& withAcquireActions(List<EzAcquireAction>&& acquireActions)
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