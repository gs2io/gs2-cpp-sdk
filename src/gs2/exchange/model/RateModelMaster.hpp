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

#ifndef GS2_EXCHANGE_MODEL_RATEMODELMASTER_HPP_
#define GS2_EXCHANGE_MODEL_RATEMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ConsumeAction.hpp"
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace exchange {

/**
 * 交換レートマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class RateModelMaster : public Gs2Object
{
    friend bool operator!=(const RateModelMaster& lhs, const RateModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換レートマスター */
        optional<StringHolder> rateModelId;
        /** 交換レート名 */
        optional<StringHolder> name;
        /** 交換レートマスターの説明 */
        optional<StringHolder> description;
        /** 交換レートのメタデータ */
        optional<StringHolder> metadata;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;
        /** 交換の種類 */
        optional<StringHolder> timingType;
        /** 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分） */
        optional<Int32> lockTime;
        /** スキップをすることができるか */
        optional<Bool> enableSkip;
        /** 時短消費アクションリスト */
        optional<List<ConsumeAction>> skipConsumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rateModelId(data.rateModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            timingType(data.timingType),
            lockTime(data.lockTime),
            enableSkip(data.enableSkip),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.skipConsumeActions)
            {
                skipConsumeActions = data.skipConsumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "rateModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->rateModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "consumeActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->consumeActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ConsumeAction item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->consumeActions += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "timingType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->timingType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "lockTime") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->lockTime = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "enableSkip") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->enableSkip = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "skipConsumeActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->skipConsumeActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ConsumeAction item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->skipConsumeActions += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "acquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->acquireActions += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RateModelMaster() = default;
    RateModelMaster(const RateModelMaster& rateModelMaster) = default;
    RateModelMaster(RateModelMaster&& rateModelMaster) = default;
    ~RateModelMaster() = default;

    RateModelMaster& operator=(const RateModelMaster& rateModelMaster) = default;
    RateModelMaster& operator=(RateModelMaster&& rateModelMaster) = default;

    RateModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RateModelMaster);
    }

    const RateModelMaster* operator->() const
    {
        return this;
    }

    RateModelMaster* operator->()
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
    RateModelMaster& withRateModelId(StringHolder rateModelId)
    {
        setRateModelId(std::move(rateModelId));
        return *this;
    }

    /**
     * 交換レート名を取得
     *
     * @return 交換レート名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 交換レート名を設定
     *
     * @param name 交換レート名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 交換レート名を設定
     *
     * @param name 交換レート名
     */
    RateModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 交換レートマスターの説明を取得
     *
     * @return 交換レートマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 交換レートマスターの説明を設定
     *
     * @param description 交換レートマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 交換レートマスターの説明を設定
     *
     * @param description 交換レートマスターの説明
     */
    RateModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * 交換レートのメタデータを取得
     *
     * @return 交換レートのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 交換レートのメタデータを設定
     *
     * @param metadata 交換レートのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 交換レートのメタデータを設定
     *
     * @param metadata 交換レートのメタデータ
     */
    RateModelMaster& withMetadata(StringHolder metadata)
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
    RateModelMaster& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    /**
     * 交換の種類を取得
     *
     * @return 交換の種類
     */
    const optional<StringHolder>& getTimingType() const
    {
        return ensureData().timingType;
    }

    /**
     * 交換の種類を設定
     *
     * @param timingType 交換の種類
     */
    void setTimingType(StringHolder timingType)
    {
        ensureData().timingType.emplace(std::move(timingType));
    }

    /**
     * 交換の種類を設定
     *
     * @param timingType 交換の種類
     */
    RateModelMaster& withTimingType(StringHolder timingType)
    {
        setTimingType(std::move(timingType));
        return *this;
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を取得
     *
     * @return 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    const optional<Int32>& getLockTime() const
    {
        return ensureData().lockTime;
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を設定
     *
     * @param lockTime 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    void setLockTime(Int32 lockTime)
    {
        ensureData().lockTime.emplace(lockTime);
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を設定
     *
     * @param lockTime 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    RateModelMaster& withLockTime(Int32 lockTime)
    {
        setLockTime(lockTime);
        return *this;
    }

    /**
     * スキップをすることができるかを取得
     *
     * @return スキップをすることができるか
     */
    const optional<Bool>& getEnableSkip() const
    {
        return ensureData().enableSkip;
    }

    /**
     * スキップをすることができるかを設定
     *
     * @param enableSkip スキップをすることができるか
     */
    void setEnableSkip(Bool enableSkip)
    {
        ensureData().enableSkip.emplace(enableSkip);
    }

    /**
     * スキップをすることができるかを設定
     *
     * @param enableSkip スキップをすることができるか
     */
    RateModelMaster& withEnableSkip(Bool enableSkip)
    {
        setEnableSkip(enableSkip);
        return *this;
    }

    /**
     * 時短消費アクションリストを取得
     *
     * @return 時短消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getSkipConsumeActions() const
    {
        return ensureData().skipConsumeActions;
    }

    /**
     * 時短消費アクションリストを設定
     *
     * @param skipConsumeActions 時短消費アクションリスト
     */
    void setSkipConsumeActions(List<ConsumeAction> skipConsumeActions)
    {
        ensureData().skipConsumeActions.emplace(std::move(skipConsumeActions));
    }

    /**
     * 時短消費アクションリストを設定
     *
     * @param skipConsumeActions 時短消費アクションリスト
     */
    RateModelMaster& withSkipConsumeActions(List<ConsumeAction> skipConsumeActions)
    {
        setSkipConsumeActions(std::move(skipConsumeActions));
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
    RateModelMaster& withAcquireActions(List<AcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    RateModelMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    RateModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RateModelMaster& lhs, const RateModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->rateModelId != lhr.m_pData->rateModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->consumeActions != lhr.m_pData->consumeActions)
        {
            return true;
        }
        if (lhs.m_pData->timingType != lhr.m_pData->timingType)
        {
            return true;
        }
        if (lhs.m_pData->lockTime != lhr.m_pData->lockTime)
        {
            return true;
        }
        if (lhs.m_pData->enableSkip != lhr.m_pData->enableSkip)
        {
            return true;
        }
        if (lhs.m_pData->skipConsumeActions != lhr.m_pData->skipConsumeActions)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const RateModelMaster& lhs, const RateModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXCHANGE_MODEL_RATEMODELMASTER_HPP_