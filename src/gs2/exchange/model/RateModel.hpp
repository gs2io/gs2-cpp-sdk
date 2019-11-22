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

#ifndef GS2_EXCHANGE_MODEL_RATEMODEL_HPP_
#define GS2_EXCHANGE_MODEL_RATEMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <memory>

namespace gs2 { namespace exchange {

/**
 * 交換レートモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class RateModel : public Gs2Object
{
    friend bool operator!=(const RateModel& lhs, const RateModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換レートマスター */
        optional<StringHolder> rateModelId;
        /** 交換レートの種類名 */
        optional<StringHolder> name;
        /** 交換レートの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RateModel() = default;
    RateModel(const RateModel& rateModel) = default;
    RateModel(RateModel&& rateModel) = default;
    ~RateModel() = default;

    RateModel& operator=(const RateModel& rateModel) = default;
    RateModel& operator=(RateModel&& rateModel) = default;

    RateModel deepCopy() const;

    const RateModel* operator->() const
    {
        return this;
    }

    RateModel* operator->()
    {
        return this;
    }
    /**
     * 交換レートマスターを取得
     *
     * @return 交換レートマスター
     */
    const optional<StringHolder>& getRateModelId() const
    {
        return ensureData().rateModelId;
    }

    /**
     * 交換レートマスターを設定
     *
     * @param rateModelId 交換レートマスター
     */
    void setRateModelId(StringHolder rateModelId)
    {
        ensureData().rateModelId.emplace(std::move(rateModelId));
    }

    /**
     * 交換レートマスターを設定
     *
     * @param rateModelId 交換レートマスター
     */
    RateModel& withRateModelId(StringHolder rateModelId)
    {
        setRateModelId(std::move(rateModelId));
        return *this;
    }

    /**
     * 交換レートの種類名を取得
     *
     * @return 交換レートの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 交換レートの種類名を設定
     *
     * @param name 交換レートの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 交換レートの種類名を設定
     *
     * @param name 交換レートの種類名
     */
    RateModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 交換レートの種類のメタデータを取得
     *
     * @return 交換レートの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 交換レートの種類のメタデータを設定
     *
     * @param metadata 交換レートの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 交換レートの種類のメタデータを設定
     *
     * @param metadata 交換レートの種類のメタデータ
     */
    RateModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 消費アクションリストを取得
     *
     * @return 消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    RateModel& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    /**
     * 入手アクションリストを取得
     *
     * @return 入手アクションリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    RateModel& withAcquireActions(List<AcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const RateModel& lhs, const RateModel& lhr);

inline bool operator==(const RateModel& lhs, const RateModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXCHANGE_MODEL_RATEMODEL_HPP_