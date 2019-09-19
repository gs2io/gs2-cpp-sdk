

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

#include <gs2/stamina/model/Stamina.hpp>


namespace gs2 { namespace ez { namespace stamina {

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
        /** 次回スタミナが回復する時間 */
        gs2::optional<Int64> nextRecoverAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            staminaName(data.staminaName),
            value(data.value),
            maxValue(data.maxValue),
            nextRecoverAt(data.nextRecoverAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::stamina::Stamina& stamina) :
            staminaName(stamina.getStaminaName()),
            value(stamina.getValue() ? *stamina.getValue() : 0),
            maxValue(stamina.getMaxValue() ? *stamina.getMaxValue() : 0),
            nextRecoverAt(stamina.getNextRecoverAt() ? *stamina.getNextRecoverAt() : 0)
        {
        }

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

    EzStamina(gs2::stamina::Stamina stamina) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(stamina)
    {}

    EzStamina& operator=(const EzStamina& ezStamina) = default;
    EzStamina& operator=(EzStamina&& ezStamina) = default;

    EzStamina deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStamina);
    }

    gs2::stamina::Stamina ToModel() const
    {
        gs2::stamina::Stamina stamina;
        stamina.setStaminaName(getStaminaName());
        stamina.setValue(getValue());
        stamina.setMaxValue(getMaxValue());
        stamina.setNextRecoverAt(getNextRecoverAt());
        return stamina;
    }

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

    EzStamina& withNextRecoverAt(Int64 nextRecoverAt)
    {
        setNextRecoverAt(nextRecoverAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZSTAMINA_HPP_