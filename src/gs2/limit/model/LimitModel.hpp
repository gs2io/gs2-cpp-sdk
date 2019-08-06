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

#ifndef GS2_LIMIT_MODEL_LIMITMODEL_HPP_
#define GS2_LIMIT_MODEL_LIMITMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace limit {

/**
 * 回数制限の種類
 *
 * @author Game Server Services, Inc.
 *
 */
class LimitModel : public Gs2Object
{
    friend bool operator!=(const LimitModel& lhs, const LimitModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 回数制限の種類 */
        optional<StringHolder> limitModelId;
        /** 回数制限の種類名 */
        optional<StringHolder> name;
        /** 回数制限の種類のメタデータ */
        optional<StringHolder> metadata;
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** リセットをする日にち */
        optional<Int32> resetDayOfMonth;
        /** リセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** リセット時刻 */
        optional<Int32> resetHour;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            limitModelId(data.limitModelId),
            name(data.name),
            metadata(data.metadata),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            limitModelId(std::move(data.limitModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "limitModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->limitModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "resetType") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resetDayOfMonth") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetDayOfMonth = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "resetDayOfWeek") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetDayOfWeek.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resetHour") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetHour = jsonValue.GetInt();
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
    LimitModel() :
        m_pData(nullptr)
    {}

    LimitModel(const LimitModel& limitModel) :
        Gs2Object(limitModel),
        m_pData(limitModel.m_pData != nullptr ? new Data(*limitModel.m_pData) : nullptr)
    {}

    LimitModel(LimitModel&& limitModel) :
        Gs2Object(std::move(limitModel)),
        m_pData(limitModel.m_pData)
    {
        limitModel.m_pData = nullptr;
    }

    ~LimitModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LimitModel& operator=(const LimitModel& limitModel)
    {
        Gs2Object::operator=(limitModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*limitModel.m_pData);

        return *this;
    }

    LimitModel& operator=(LimitModel&& limitModel)
    {
        Gs2Object::operator=(std::move(limitModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = limitModel.m_pData;
        limitModel.m_pData = nullptr;

        return *this;
    }

    const LimitModel* operator->() const
    {
        return this;
    }

    LimitModel* operator->()
    {
        return this;
    }
    /**
     * 回数制限の種類を取得
     *
     * @return 回数制限の種類
     */
    const optional<StringHolder>& getLimitModelId() const
    {
        return ensureData().limitModelId;
    }

    /**
     * 回数制限の種類を設定
     *
     * @param limitModelId 回数制限の種類
     */
    void setLimitModelId(const Char* limitModelId)
    {
        ensureData().limitModelId.emplace(limitModelId);
    }

    /**
     * 回数制限の種類を設定
     *
     * @param limitModelId 回数制限の種類
     */
    LimitModel& withLimitModelId(const Char* limitModelId)
    {
        setLimitModelId(limitModelId);
        return *this;
    }

    /**
     * 回数制限の種類名を取得
     *
     * @return 回数制限の種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param name 回数制限の種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param name 回数制限の種類名
     */
    LimitModel& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 回数制限の種類のメタデータを取得
     *
     * @return 回数制限の種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 回数制限の種類のメタデータを設定
     *
     * @param metadata 回数制限の種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 回数制限の種類のメタデータを設定
     *
     * @param metadata 回数制限の種類のメタデータ
     */
    LimitModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * リセットタイミングを取得
     *
     * @return リセットタイミング
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    LimitModel& withResetType(const Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    /**
     * リセットをする日にちを取得
     *
     * @return リセットをする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    LimitModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    /**
     * リセットする曜日を取得
     *
     * @return リセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    void setResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    LimitModel& withResetDayOfWeek(const Char* resetDayOfWeek)
    {
        setResetDayOfWeek(resetDayOfWeek);
        return *this;
    }

    /**
     * リセット時刻を取得
     *
     * @return リセット時刻
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    LimitModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LimitModel& lhs, const LimitModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->limitModelId != lhr.m_pData->limitModelId)
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
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfMonth != lhr.m_pData->resetDayOfMonth)
        {
            return true;
        }
        if (lhs.m_pData->resetDayOfWeek != lhr.m_pData->resetDayOfWeek)
        {
            return true;
        }
        if (lhs.m_pData->resetHour != lhr.m_pData->resetHour)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const LimitModel& lhs, const LimitModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LIMIT_MODEL_LIMITMODEL_HPP_