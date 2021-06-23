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

#include "EzStamina.hpp"
#include <gs2/stamina/model/Stamina.hpp>


namespace gs2 { namespace ez { namespace stamina {

EzStamina::Data::Data(const Data& data) :
    Gs2Object(data),
    staminaName(data.staminaName),
    value(data.value),
    maxValue(data.maxValue),
    recoverIntervalMinutes(data.recoverIntervalMinutes),
    recoverValue(data.recoverValue),
    nextRecoverAt(data.nextRecoverAt)
{
}

EzStamina::Data::Data(const gs2::stamina::Stamina& stamina) :
    staminaName(stamina.getStaminaName()),
    value(stamina.getValue() ? *stamina.getValue() : 0),
    maxValue(stamina.getMaxValue() ? *stamina.getMaxValue() : 0),
    recoverIntervalMinutes(stamina.getRecoverIntervalMinutes() ? *stamina.getRecoverIntervalMinutes() : 0),
    recoverValue(stamina.getRecoverValue() ? *stamina.getRecoverValue() : 0),
    nextRecoverAt(stamina.getNextRecoverAt() ? *stamina.getNextRecoverAt() : 0)
{
}

EzStamina::EzStamina(gs2::stamina::Stamina stamina) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(stamina)
{
}

EzStamina EzStamina::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStamina);
}

gs2::stamina::Stamina EzStamina::ToModel() const
{
    gs2::stamina::Stamina stamina;
    stamina.setStaminaName(getStaminaName());
    stamina.setValue(getValue());
    stamina.setMaxValue(getMaxValue());
    stamina.setRecoverIntervalMinutes(getRecoverIntervalMinutes());
    stamina.setRecoverValue(getRecoverValue());
    stamina.setNextRecoverAt(getNextRecoverAt());
    return stamina;
}

}}}