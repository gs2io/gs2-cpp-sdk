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
#include <gs2/core/external/optional/optional.hpp>
#include "CounterScopeModel.hpp"
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            counterId(data.counterId),
            name(data.name),
            metadata(data.metadata),
            scopes(data.scopes),
            challengePeriodEventId(data.challengePeriodEventId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            counterId(std::move(data.counterId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            scopes(std::move(data.scopes)),
            challengePeriodEventId(std::move(data.challengePeriodEventId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "counterId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scopes") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->scopes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        CounterScopeModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->scopes, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "challengePeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    CounterModel() :
        m_pData(nullptr)
    {}

    CounterModel(const CounterModel& counterModel) :
        Gs2Object(counterModel),
        m_pData(counterModel.m_pData != nullptr ? new Data(*counterModel.m_pData) : nullptr)
    {}

    CounterModel(CounterModel&& counterModel) :
        Gs2Object(std::move(counterModel)),
        m_pData(counterModel.m_pData)
    {
        counterModel.m_pData = nullptr;
    }

    ~CounterModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CounterModel& operator=(const CounterModel& counterModel)
    {
        Gs2Object::operator=(counterModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*counterModel.m_pData);

        return *this;
    }

    CounterModel& operator=(CounterModel&& counterModel)
    {
        Gs2Object::operator=(std::move(counterModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = counterModel.m_pData;
        counterModel.m_pData = nullptr;

        return *this;
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
    void setCounterId(const Char* counterId)
    {
        ensureData().counterId.emplace(counterId);
    }

    /**
     * カウンターの種類を設定
     *
     * @param counterId カウンターの種類
     */
    CounterModel& withCounterId(const Char* counterId)
    {
        setCounterId(counterId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カウンター名を設定
     *
     * @param name カウンター名
     */
    CounterModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    CounterModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setScopes(const List<CounterScopeModel>& scopes)
    {
        ensureData().scopes.emplace(scopes);
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    CounterModel& withScopes(const List<CounterScopeModel>& scopes)
    {
        setScopes(scopes);
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
    void setChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    CounterModel& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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