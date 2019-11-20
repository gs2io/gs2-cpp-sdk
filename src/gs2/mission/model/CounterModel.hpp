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

#ifndef GS2_MISSION_MODEL_COUNTERMODEL_HPP_
#define GS2_MISSION_MODEL_COUNTERMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "CounterScopeModel.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace mission {

/**
 * カウンターの種類
 *
 * @author Game Server Services, Inc.
 *
 */
class CounterModel : public Gs2Object
{
    friend bool operator!=(const CounterModel& lhs, const CounterModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターの種類 */
        optional<StringHolder> counterId;
        /** カウンター名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** カウンターのリセットタイミング */
        optional<List<CounterScopeModel>> scopes;
        /** カウントアップ可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            counterId(data.counterId),
            name(data.name),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId)
        {
            if (data.scopes)
            {
                scopes = data.scopes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "counterId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->counterId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scopes") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->scopes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        CounterScopeModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->scopes += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "challengePeriodEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CounterModel() = default;
    CounterModel(const CounterModel& counterModel) = default;
    CounterModel(CounterModel&& counterModel) = default;
    ~CounterModel() = default;

    CounterModel& operator=(const CounterModel& counterModel) = default;
    CounterModel& operator=(CounterModel&& counterModel) = default;

    CounterModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CounterModel);
    }

    const CounterModel* operator->() const
    {
        return this;
    }

    CounterModel* operator->()
    {
        return this;
    }
    /**
     * カウンターの種類を取得
     *
     * @return カウンターの種類
     */
    const optional<StringHolder>& getCounterId() const
    {
        return ensureData().counterId;
    }

    /**
     * カウンターの種類を設定
     *
     * @param counterId カウンターの種類
     */
    void setCounterId(StringHolder counterId)
    {
        ensureData().counterId.emplace(std::move(counterId));
    }

    /**
     * カウンターの種類を設定
     *
     * @param counterId カウンターの種類
     */
    CounterModel& withCounterId(StringHolder counterId)
    {
        setCounterId(std::move(counterId));
        return *this;
    }

    /**
     * カウンター名を取得
     *
     * @return カウンター名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カウンター名を設定
     *
     * @param name カウンター名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * カウンター名を設定
     *
     * @param name カウンター名
     */
    CounterModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    CounterModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * カウンターのリセットタイミングを取得
     *
     * @return カウンターのリセットタイミング
     */
    const optional<List<CounterScopeModel>>& getScopes() const
    {
        return ensureData().scopes;
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    void setScopes(List<CounterScopeModel> scopes)
    {
        ensureData().scopes.emplace(std::move(scopes));
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    CounterModel& withScopes(List<CounterScopeModel> scopes)
    {
        setScopes(std::move(scopes));
        return *this;
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    CounterModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CounterModel& lhs, const CounterModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->counterId != lhr.m_pData->counterId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->scopes != lhr.m_pData->scopes)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const CounterModel& lhs, const CounterModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_COUNTERMODEL_HPP_