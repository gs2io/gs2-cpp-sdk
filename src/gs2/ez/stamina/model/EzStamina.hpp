

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
    /** スタミナモデルの名前 */
    gs2::optional<StringHolder> m_StaminaName;
    /** 最終更新時におけるスタミナ値 */
    gs2::optional<Int32> m_Value;
    /** スタミナの最大値 */
    gs2::optional<Int32> m_MaxValue;
    /** 次回スタミナが回復する時間 */
    gs2::optional<Int64> m_NextRecoverAt;

public:
    EzStamina() = default;

    EzStamina(gs2::stamina::Stamina stamina) :
        m_StaminaName(stamina.getStaminaName()),
        m_Value(stamina.getValue() ? *stamina.getValue() : 0),
        m_MaxValue(stamina.getMaxValue() ? *stamina.getMaxValue() : 0),
        m_NextRecoverAt(stamina.getNextRecoverAt() ? *stamina.getNextRecoverAt() : 0)
    {
    }

    gs2::stamina::Stamina ToModel() const
    {
        gs2::stamina::Stamina stamina;
        stamina.setStaminaName(*m_StaminaName);
        stamina.setValue(*m_Value);
        stamina.setMaxValue(*m_MaxValue);
        stamina.setNextRecoverAt(*m_NextRecoverAt);
        return stamina;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getStaminaName() const
    {
        return *m_StaminaName;
    }

    gs2::StringHolder& getStaminaName()
    {
        return *m_StaminaName;
    }

    Int32 getValue() const
    {
        return *m_Value;
    }

    Int32 getMaxValue() const
    {
        return *m_MaxValue;
    }

    Int64 getNextRecoverAt() const
    {
        return *m_NextRecoverAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setStaminaName(Char* staminaName)
    {
        m_StaminaName.emplace(staminaName);
    }

    void setValue(Int32 value)
    {
        m_Value = value;
    }

    void setMaxValue(Int32 maxValue)
    {
        m_MaxValue = maxValue;
    }

    void setNextRecoverAt(Int64 nextRecoverAt)
    {
        m_NextRecoverAt = nextRecoverAt;
    }

    EzStamina& withStaminaName(Char* staminaName)
    {
        setStaminaName(staminaName);
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