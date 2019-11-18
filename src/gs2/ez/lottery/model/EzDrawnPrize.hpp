

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 入手アクションのリスト */
        gs2::optional<List<EzAcquireAction>> acquireActions;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::lottery::DrawnPrize& drawnPrize)
        {
            acquireActions.emplace();
            if (drawnPrize.getAcquireActions())
            {
                for (int i = 0; i < drawnPrize.getAcquireActions()->getCount(); ++i)
                {
                    *acquireActions += EzAcquireAction((*drawnPrize.getAcquireActions())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDrawnPrize() = default;
    EzDrawnPrize(const EzDrawnPrize& ezDrawnPrize) = default;
    EzDrawnPrize(EzDrawnPrize&& ezDrawnPrize) = default;
    ~EzDrawnPrize() = default;

    EzDrawnPrize(gs2::lottery::DrawnPrize drawnPrize) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(drawnPrize)
    {}

    EzDrawnPrize& operator=(const EzDrawnPrize& ezDrawnPrize) = default;
    EzDrawnPrize& operator=(EzDrawnPrize&& ezDrawnPrize) = default;

    EzDrawnPrize deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDrawnPrize);
    }

    gs2::lottery::DrawnPrize ToModel() const
    {
        gs2::lottery::DrawnPrize drawnPrize;
        {
            gs2::List<gs2::lottery::AcquireAction> list;
            auto& acquireActions = getAcquireActions();
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
        return *ensureData().acquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAcquireActions(List<EzAcquireAction> acquireActions)
    {
        ensureData().acquireActions = std::move(acquireActions);
    }

    EzDrawnPrize& withAcquireActions(List<EzAcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOTTERY_EZDRAWNPRIZE_HPP_