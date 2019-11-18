

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

#ifndef GS2_EZ_EXCHANGE_MODEL_EZRATEMODEL_HPP_
#define GS2_EZ_EXCHANGE_MODEL_EZRATEMODEL_HPP_

#include <gs2/exchange/model/RateModel.hpp>
#include "EzConsumeAction.hpp"
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace exchange {

class EzRateModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換レートの種類名 */
        gs2::optional<StringHolder> name;
        /** 交換レートの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 消費アクションリスト */
        gs2::optional<List<EzConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        gs2::optional<List<EzAcquireAction>> acquireActions;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata)
        {
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::exchange::RateModel& rateModel) :
            name(rateModel.getName()),
            metadata(rateModel.getMetadata())
        {
            consumeActions.emplace();
            if (rateModel.getConsumeActions())
            {
                for (int i = 0; i < rateModel.getConsumeActions()->getCount(); ++i)
                {
                    *consumeActions += EzConsumeAction((*rateModel.getConsumeActions())[i]);
                }
            }
            acquireActions.emplace();
            if (rateModel.getAcquireActions())
            {
                for (int i = 0; i < rateModel.getAcquireActions()->getCount(); ++i)
                {
                    *acquireActions += EzAcquireAction((*rateModel.getAcquireActions())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRateModel() = default;
    EzRateModel(const EzRateModel& ezRateModel) = default;
    EzRateModel(EzRateModel&& ezRateModel) = default;
    ~EzRateModel() = default;

    EzRateModel(gs2::exchange::RateModel rateModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(rateModel)
    {}

    EzRateModel& operator=(const EzRateModel& ezRateModel) = default;
    EzRateModel& operator=(EzRateModel&& ezRateModel) = default;

    EzRateModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRateModel);
    }

    gs2::exchange::RateModel ToModel() const
    {
        gs2::exchange::RateModel rateModel;
        rateModel.setName(getName());
        rateModel.setMetadata(getMetadata());
        {
            gs2::List<gs2::exchange::ConsumeAction> list;
            auto& consumeActions = getConsumeActions();
            for (int i = 0; i < consumeActions.getCount(); ++i)
            {
                list += consumeActions[i].ToModel();
            }
            rateModel.setConsumeActions(list);
        }
        {
            gs2::List<gs2::exchange::AcquireAction> list;
            auto& acquireActions = getAcquireActions();
            for (int i = 0; i < acquireActions.getCount(); ++i)
            {
                list += acquireActions[i].ToModel();
            }
            rateModel.setAcquireActions(list);
        }
        return rateModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return *ensureData().consumeActions;
    }

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return *ensureData().acquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setConsumeActions(List<EzConsumeAction> consumeActions)
    {
        ensureData().consumeActions = std::move(consumeActions);
    }

    void setAcquireActions(List<EzAcquireAction> acquireActions)
    {
        ensureData().acquireActions = std::move(acquireActions);
    }

    EzRateModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRateModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzRateModel& withConsumeActions(List<EzConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    EzRateModel& withAcquireActions(List<EzAcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXCHANGE_EZRATEMODEL_HPP_