

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

#ifndef GS2_EZ_LOTTERY_MODEL_EZDRAWNPRIZE_HPP_
#define GS2_EZ_LOTTERY_MODEL_EZDRAWNPRIZE_HPP_

#include <gs2/lottery/model/DrawnPrize.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace lottery {

class EzDrawnPrize : public gs2::Gs2Object
{
private:
    /** 入手アクションのリスト */
    gs2::optional<List<EzAcquireAction>> m_AcquireActions;

public:
    EzDrawnPrize() = default;

    EzDrawnPrize(gs2::lottery::DrawnPrize drawnPrize)
    {
        m_AcquireActions.emplace();
        if (drawnPrize.getAcquireActions())
        {
            for (int i = 0; i < drawnPrize.getAcquireActions()->getCount(); ++i)
            {
                *m_AcquireActions += EzAcquireAction((*drawnPrize.getAcquireActions())[i]);
            }
        }
    }

    gs2::lottery::DrawnPrize ToModel() const
    {
        gs2::lottery::DrawnPrize drawnPrize;
        {
            gs2::List<gs2::lottery::AcquireAction> list;
            auto& acquireActions = *m_AcquireActions;
            for (int i = 0; i < acquireActions.getCount(); ++i)
            {
                list += acquireActions[i].ToModel();
            }
            drawnPrize.setAcquireActions(list);
        }
        return drawnPrize;
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

    EzDrawnPrize& withAcquireActions(const List<EzAcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
        return *this;
    }

    EzDrawnPrize& withAcquireActions(List<EzAcquireAction>&& acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZDRAWNPRIZE_HPP_