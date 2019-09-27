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

#ifndef GS2_STAMINA_MODEL_STAMINA_HPP_
#define GS2_STAMINA_MODEL_STAMINA_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナ
 *
 * @author Game Server Services, Inc.
 *
 */
class Stamina : public Gs2Object
{
    friend bool operator!=(const Stamina& lhs, const Stamina& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<StringHolder> staminaId;
        /** スタミナモデルの名前 */
        optional<StringHolder> staminaName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 最終更新時におけるスタミナ値 */
        optional<Int32> value;
        /** スタミナの最大値 */
        optional<Int32> maxValue;
        /** スタミナの回復間隔(分) */
        optional<Int32> recoverIntervalMinutes;
        /** スタミナの回復量 */
        optional<Int32> recoverValue;
        /** スタミナの最大値を超えて格納されているスタミナ値 */
        optional<Int32> overflowValue;
        /** 次回スタミナが回復する時間 */
        optional<Int64> nextRecoverAt;
        /** 作成日時 */
        optional<Int64> lastRecoveredAt;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            staminaId(data.staminaId),
            staminaName(data.staminaName),
            userId(data.userId),
            value(data.value),
            maxValue(data.maxValue),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            overflowValue(data.overflowValue),
            nextRecoverAt(data.nextRecoverAt),
            lastRecoveredAt(data.lastRecoveredAt),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "staminaId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->staminaId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "staminaName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->staminaName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->maxValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "recoverIntervalMinutes") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->recoverIntervalMinutes = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "recoverValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->recoverValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "overflowValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->overflowValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "nextRecoverAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->nextRecoverAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "lastRecoveredAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->lastRecoveredAt = jsonValue.GetInt64();
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
    Stamina() = default;
    Stamina(const Stamina& stamina) = default;
    Stamina(Stamina&& stamina) = default;
    ~Stamina() = default;

    Stamina& operator=(const Stamina& stamina) = default;
    Stamina& operator=(Stamina&& stamina) = default;

    Stamina deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Stamina);
    }

    const Stamina* operator->() const
    {
        return this;
    }

    Stamina* operator->()
    {
        return this;
    }
    /**
     * スタミナを取得
     *
     * @return スタミナ
     */
    const optional<StringHolder>& getStaminaId() const
    {
        return ensureData().staminaId;
    }

    /**
     * スタミナを設定
     *
     * @param staminaId スタミナ
     */
    void setStaminaId(StringHolder staminaId)
    {
        ensureData().staminaId.emplace(std::move(staminaId));
    }

    /**
     * スタミナを設定
     *
     * @param staminaId スタミナ
     */
    Stamina& withStaminaId(StringHolder staminaId)
    {
        setStaminaId(std::move(staminaId));
        return *this;
    }

    /**
     * スタミナモデルの名前を取得
     *
     * @return スタミナモデルの名前
     */
    const optional<StringHolder>& getStaminaName() const
    {
        return ensureData().staminaName;
    }

    /**
     * スタミナモデルの名前を設定
     *
     * @param staminaName スタミナモデルの名前
     */
    void setStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
    }

    /**
     * スタミナモデルの名前を設定
     *
     * @param staminaName スタミナモデルの名前
     */
    Stamina& withStaminaName(StringHolder staminaName)
    {
        setStaminaName(std::move(staminaName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Stamina& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 最終更新時におけるスタミナ値を取得
     *
     * @return 最終更新時におけるスタミナ値
     */
    const optional<Int32>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 最終更新時におけるスタミナ値を設定
     *
     * @param value 最終更新時におけるスタミナ値
     */
    void setValue(Int32 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 最終更新時におけるスタミナ値を設定
     *
     * @param value 最終更新時におけるスタミナ値
     */
    Stamina& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }

    /**
     * スタミナの最大値を取得
     *
     * @return スタミナの最大値
     */
    const optional<Int32>& getMaxValue() const
    {
        return ensureData().maxValue;
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    void setMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    Stamina& withMaxValue(Int32 maxValue)
    {
        setMaxValue(maxValue);
        return *this;
    }

    /**
     * スタミナの回復間隔(分)を取得
     *
     * @return スタミナの回復間隔(分)
     */
    const optional<Int32>& getRecoverIntervalMinutes() const
    {
        return ensureData().recoverIntervalMinutes;
    }

    /**
     * スタミナの回復間隔(分)を設定
     *
     * @param recoverIntervalMinutes スタミナの回復間隔(分)
     */
    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes.emplace(recoverIntervalMinutes);
    }

    /**
     * スタミナの回復間隔(分)を設定
     *
     * @param recoverIntervalMinutes スタミナの回復間隔(分)
     */
    Stamina& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        setRecoverIntervalMinutes(recoverIntervalMinutes);
        return *this;
    }

    /**
     * スタミナの回復量を取得
     *
     * @return スタミナの回復量
     */
    const optional<Int32>& getRecoverValue() const
    {
        return ensureData().recoverValue;
    }

    /**
     * スタミナの回復量を設定
     *
     * @param recoverValue スタミナの回復量
     */
    void setRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue.emplace(recoverValue);
    }

    /**
     * スタミナの回復量を設定
     *
     * @param recoverValue スタミナの回復量
     */
    Stamina& withRecoverValue(Int32 recoverValue)
    {
        setRecoverValue(recoverValue);
        return *this;
    }

    /**
     * スタミナの最大値を超えて格納されているスタミナ値を取得
     *
     * @return スタミナの最大値を超えて格納されているスタミナ値
     */
    const optional<Int32>& getOverflowValue() const
    {
        return ensureData().overflowValue;
    }

    /**
     * スタミナの最大値を超えて格納されているスタミナ値を設定
     *
     * @param overflowValue スタミナの最大値を超えて格納されているスタミナ値
     */
    void setOverflowValue(Int32 overflowValue)
    {
        ensureData().overflowValue.emplace(overflowValue);
    }

    /**
     * スタミナの最大値を超えて格納されているスタミナ値を設定
     *
     * @param overflowValue スタミナの最大値を超えて格納されているスタミナ値
     */
    Stamina& withOverflowValue(Int32 overflowValue)
    {
        setOverflowValue(overflowValue);
        return *this;
    }

    /**
     * 次回スタミナが回復する時間を取得
     *
     * @return 次回スタミナが回復する時間
     */
    const optional<Int64>& getNextRecoverAt() const
    {
        return ensureData().nextRecoverAt;
    }

    /**
     * 次回スタミナが回復する時間を設定
     *
     * @param nextRecoverAt 次回スタミナが回復する時間
     */
    void setNextRecoverAt(Int64 nextRecoverAt)
    {
        ensureData().nextRecoverAt.emplace(nextRecoverAt);
    }

    /**
     * 次回スタミナが回復する時間を設定
     *
     * @param nextRecoverAt 次回スタミナが回復する時間
     */
    Stamina& withNextRecoverAt(Int64 nextRecoverAt)
    {
        setNextRecoverAt(nextRecoverAt);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getLastRecoveredAt() const
    {
        return ensureData().lastRecoveredAt;
    }

    /**
     * 作成日時を設定
     *
     * @param lastRecoveredAt 作成日時
     */
    void setLastRecoveredAt(Int64 lastRecoveredAt)
    {
        ensureData().lastRecoveredAt.emplace(lastRecoveredAt);
    }

    /**
     * 作成日時を設定
     *
     * @param lastRecoveredAt 作成日時
     */
    Stamina& withLastRecoveredAt(Int64 lastRecoveredAt)
    {
        setLastRecoveredAt(lastRecoveredAt);
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
    Stamina& withCreatedAt(Int64 createdAt)
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
    Stamina& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Stamina& lhs, const Stamina& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->staminaId != lhr.m_pData->staminaId)
        {
            return true;
        }
        if (lhs.m_pData->staminaName != lhr.m_pData->staminaName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
        if (lhs.m_pData->maxValue != lhr.m_pData->maxValue)
        {
            return true;
        }
        if (lhs.m_pData->recoverIntervalMinutes != lhr.m_pData->recoverIntervalMinutes)
        {
            return true;
        }
        if (lhs.m_pData->recoverValue != lhr.m_pData->recoverValue)
        {
            return true;
        }
        if (lhs.m_pData->overflowValue != lhr.m_pData->overflowValue)
        {
            return true;
        }
        if (lhs.m_pData->nextRecoverAt != lhr.m_pData->nextRecoverAt)
        {
            return true;
        }
        if (lhs.m_pData->lastRecoveredAt != lhr.m_pData->lastRecoveredAt)
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

inline bool operator==(const Stamina& lhs, const Stamina& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_STAMINA_HPP_