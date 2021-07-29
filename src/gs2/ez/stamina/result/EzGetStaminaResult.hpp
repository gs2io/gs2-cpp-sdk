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

#ifndef GS2_EZ_STAMINA_EZGETSTAMINARESULT_HPP_
#define GS2_EZ_STAMINA_EZGETSTAMINARESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/stamina/result/GetStaminaResult.hpp>


namespace gs2 { namespace ez { namespace stamina {

class EzGetStaminaResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタミナ */
        EzStamina item;
        /** スタミナモデル */
        EzStaminaModel staminaModel;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
            staminaModel = data.staminaModel.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::stamina::GetStaminaResult& getStaminaResult) :
            item(getStaminaResult.getItem()),
            staminaModel(getStaminaResult.getStaminaModel())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetStaminaResult() = default;
    EzGetStaminaResult(const EzGetStaminaResult& result) = default;
    EzGetStaminaResult(EzGetStaminaResult&& result) = default;
    ~EzGetStaminaResult() = default;

    EzGetStaminaResult(gs2::stamina::GetStaminaResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetStaminaResult& operator=(const EzGetStaminaResult& result) = default;
    EzGetStaminaResult& operator=(EzGetStaminaResult&& result) = default;

    EzGetStaminaResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetStaminaResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzStamina& getItem() const
    {
        return ensureData().item;
    }

    const EzStaminaModel& getStaminaModel() const
    {
        return ensureData().staminaModel;
    }
};

typedef gs2::AsyncResult<EzGetStaminaResult> AsyncEzGetStaminaResult;

}}}

#endif //GS2_EZ_STAMINA_EZGETSTAMINARESULT_HPP_