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

#ifndef GS2_LIMIT_MODEL_LIMITMODELMASTER_HPP_
#define GS2_LIMIT_MODEL_LIMITMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace limit {

/**
 * 回数制限の種類マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class LimitModelMaster : public Gs2Object
{
    friend bool operator!=(const LimitModelMaster& lhs, const LimitModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 回数制限の種類マスター */
        optional<StringHolder> limitModelId;
        /** 回数制限の種類名 */
        optional<StringHolder> name;
        /** 回数制限の種類マスターの説明 */
        optional<StringHolder> description;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            limitModelId(data.limitModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            limitModelId(std::move(data.limitModelId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "limitModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->limitModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetType") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetDayOfMonth") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetDayOfMonth = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "resetDayOfWeek") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetDayOfWeek.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetHour") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetHour = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    LimitModelMaster() :
        m_pData(nullptr)
    {}

    LimitModelMaster(const LimitModelMaster& limitModelMaster) :
        Gs2Object(limitModelMaster),
        m_pData(limitModelMaster.m_pData != nullptr ? new Data(*limitModelMaster.m_pData) : nullptr)
    {}

    LimitModelMaster(LimitModelMaster&& limitModelMaster) :
        Gs2Object(std::move(limitModelMaster)),
        m_pData(limitModelMaster.m_pData)
    {
        limitModelMaster.m_pData = nullptr;
    }

    ~LimitModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LimitModelMaster& operator=(const LimitModelMaster& limitModelMaster)
    {
        Gs2Object::operator=(limitModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*limitModelMaster.m_pData);

        return *this;
    }

    LimitModelMaster& operator=(LimitModelMaster&& limitModelMaster)
    {
        Gs2Object::operator=(std::move(limitModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = limitModelMaster.m_pData;
        limitModelMaster.m_pData = nullptr;

        return *this;
    }

    const LimitModelMaster* operator->() const
    {
        return this;
    }

    LimitModelMaster* operator->()
    {
        return this;
    }
    /**
     * 回数制限の種類マスターを取得
     *
     * @return 回数制限の種類マスター
     */
    const optional<StringHolder>& getLimitModelId() const
    {
        return ensureData().limitModelId;
    }

    /**
     * 回数制限の種類マスターを設定
     *
     * @param limitModelId 回数制限の種類マスター
     */
    void setLimitModelId(const Char* limitModelId)
    {
        ensureData().limitModelId.emplace(limitModelId);
    }

    /**
     * 回数制限の種類マスターを設定
     *
     * @param limitModelId 回数制限の種類マスター
     */
    LimitModelMaster& withLimitModelId(const Char* limitModelId)
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
    LimitModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 回数制限の種類マスターの説明を取得
     *
     * @return 回数制限の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 回数制限の種類マスターの説明を設定
     *
     * @param description 回数制限の種類マスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 回数制限の種類マスターの説明を設定
     *
     * @param description 回数制限の種類マスターの説明
     */
    LimitModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    LimitModelMaster& withMetadata(const Char* metadata)
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
    LimitModelMaster& withResetType(const Char* resetType)
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
    LimitModelMaster& withResetDayOfMonth(Int32 resetDayOfMonth)
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
    LimitModelMaster& withResetDayOfWeek(const Char* resetDayOfWeek)
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
    LimitModelMaster& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
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
    LimitModelMaster& withCreatedAt(Int64 createdAt)
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
    LimitModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LimitModelMaster& lhs, const LimitModelMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
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

inline bool operator==(const LimitModelMaster& lhs, const LimitModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LIMIT_MODEL_LIMITMODELMASTER_HPP_