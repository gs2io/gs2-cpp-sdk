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
#include <gs2/core/external/optional/optional.hpp>
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            staminaId(data.staminaId),
            staminaName(data.staminaName),
            userId(data.userId),
            value(data.value),
            maxValue(data.maxValue),
            overflowValue(data.overflowValue),
            nextRecoverAt(data.nextRecoverAt),
            lastRecoveredAt(data.lastRecoveredAt),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            staminaId(std::move(data.staminaId)),
            staminaName(std::move(data.staminaName)),
            userId(std::move(data.userId)),
            value(std::move(data.value)),
            maxValue(std::move(data.maxValue)),
            overflowValue(std::move(data.overflowValue)),
            nextRecoverAt(std::move(data.nextRecoverAt)),
            lastRecoveredAt(std::move(data.lastRecoveredAt)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "staminaId") == 0) {
                if (jsonValue.IsString())
                {
                    this->staminaId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "staminaName") == 0) {
                if (jsonValue.IsString())
                {
                    this->staminaName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "maxValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "overflowValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->overflowValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "nextRecoverAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->nextRecoverAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "lastRecoveredAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->lastRecoveredAt = jsonValue.GetInt64();
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
    Stamina() :
        m_pData(nullptr)
    {}

    Stamina(const Stamina& stamina) :
        Gs2Object(stamina),
        m_pData(stamina.m_pData != nullptr ? new Data(*stamina.m_pData) : nullptr)
    {}

    Stamina(Stamina&& stamina) :
        Gs2Object(std::move(stamina)),
        m_pData(stamina.m_pData)
    {
        stamina.m_pData = nullptr;
    }

    ~Stamina()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Stamina& operator=(const Stamina& stamina)
    {
        Gs2Object::operator=(stamina);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*stamina.m_pData);

        return *this;
    }

    Stamina& operator=(Stamina&& stamina)
    {
        Gs2Object::operator=(std::move(stamina));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = stamina.m_pData;
        stamina.m_pData = nullptr;

        return *this;
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
    void setStaminaId(const Char* staminaId)
    {
        ensureData().staminaId.emplace(staminaId);
    }

    /**
     * スタミナを設定
     *
     * @param staminaId スタミナ
     */
    Stamina& withStaminaId(const Char* staminaId)
    {
        setStaminaId(staminaId);
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
    void setStaminaName(const Char* staminaName)
    {
        ensureData().staminaName.emplace(staminaName);
    }

    /**
     * スタミナモデルの名前を設定
     *
     * @param staminaName スタミナモデルの名前
     */
    Stamina& withStaminaName(const Char* staminaName)
    {
        setStaminaName(staminaName);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Stamina& withUserId(const Char* userId)
    {
        setUserId(userId);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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