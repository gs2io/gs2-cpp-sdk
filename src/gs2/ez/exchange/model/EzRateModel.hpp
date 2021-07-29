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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzConsumeAction.hpp"
#include "EzAcquireAction.hpp"
#include <memory>


namespace gs2 {

namespace exchange {

class RateModel;

}

namespace ez { namespace exchange {

class EzRateModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換レートの種類名 */
        StringHolder name;
        /** 交換レートの種類のメタデータ */
        StringHolder metadata;
        /** 消費アクションリスト */
        List<EzConsumeAction> consumeActions;
        /** 入手アクションリスト */
        List<EzAcquireAction> acquireActions;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::exchange::RateModel& rateModel);
        Data(const gs2::optional<gs2::exchange::RateModel>& rateModel);
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

    EzRateModel(gs2::exchange::RateModel rateModel);
    EzRateModel(gs2::optional<gs2::exchange::RateModel> rateModel);

    EzRateModel& operator=(const EzRateModel& ezRateModel) = default;
    EzRateModel& operator=(EzRateModel&& ezRateModel) = default;

    EzRateModel deepCopy() const;

    gs2::exchange::RateModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    const List<EzAcquireAction>& getAcquireActions() const
    {
        return ensureData().acquireActions;
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