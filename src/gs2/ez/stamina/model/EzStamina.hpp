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

#ifndef GS2_EZ_STAMINA_MODEL_EZSTAMINA_HPP_
#define GS2_EZ_STAMINA_MODEL_EZSTAMINA_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace stamina {

class Stamina;

}

namespace ez { namespace stamina {

class EzStamina : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタミナモデルの名前 */
        gs2::optional<StringHolder> staminaName;
        /** 最終更新時におけるスタミナ値 */
        gs2::optional<Int32> value;
        /** スタミナの最大値 */
        gs2::optional<Int32> maxValue;
        /** スタミナの回復間隔(分) */
        gs2::optional<Int32> recoverIntervalMinutes;
        /** スタミナの回復量 */
        gs2::optional<Int32> recoverValue;
        /** 次回スタミナが回復する時間 */
        gs2::optional<Int64> nextRecoverAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::stamina::Stamina& stamina);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzStamina() = default;
    EzStamina(const EzStamina& ezStamina) = default;
    EzStamina(EzStamina&& ezStamina) = default;
    ~EzStamina() = default;

    EzStamina(gs2::stamina::Stamina stamina);

    EzStamina& operator=(const EzStamina& ezStamina) = default;
    EzStamina& operator=(EzStamina&& ezStamina) = default;

    EzStamina deepCopy() const;

    gs2::stamina::Stamina ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getStaminaName() const
    {
        return *ensureData().staminaName;
    }

    Int32 getValue() const
    {
        return *ensureData().value;
    }

    Int32 getMaxValue() const
    {
        return *ensureData().maxValue;
    }

    Int32 getRecoverIntervalMinutes() const
    {
        return *ensureData().recoverIntervalMinutes;
    }

    Int32 getRecoverValue() const
    {
        return *ensureData().recoverValue;
    }

    Int64 getNextRecoverAt() const
    {
        return *ensureData().nextRecoverAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName = std::move(staminaName);
    }

    void setValue(Int32 value)
    {
        ensureData().value = value;
    }

    void setMaxValue(Int32 maxValue)
    {
        ensureData().maxValue = maxValue;
    }

    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes = recoverIntervalMinutes;
    }

    void setRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue = recoverValue;
    }

    void setNextRecoverAt(Int64 nextRecoverAt)
    {
        ensureData().nextRecoverAt = nextRecoverAt;
    }

    EzStamina& withStaminaName(StringHolder staminaName)
    {
        setStaminaName(std::move(staminaName));
        return *this;
    }

    EzStamina& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }

    EzStamina& withMaxValue(Int32 maxValue)
    {
        setMaxValue(maxValue);
        return *this;
    }

    EzStamina& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        setRecoverIntervalMinutes(recoverIntervalMinutes);
        return *this;
    }

    EzStamina& withRecoverValue(Int32 recoverValue)
    {
        setRecoverValue(recoverValue);
        return *this;
    }

    EzStamina& withNextRecoverAt(Int64 nextRecoverAt)
    {
        setNextRecoverAt(nextRecoverAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZSTAMINA_HPP_