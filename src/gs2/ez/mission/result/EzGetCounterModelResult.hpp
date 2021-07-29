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

#ifndef GS2_EZ_MISSION_EZGETCOUNTERMODELRESULT_HPP_
#define GS2_EZ_MISSION_EZGETCOUNTERMODELRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/GetCounterModelResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzGetCounterModelResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンターの種類 */
        EzCounterModel item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::mission::GetCounterModelResult& getCounterModelResult) :
            item(getCounterModelResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetCounterModelResult() = default;
    EzGetCounterModelResult(const EzGetCounterModelResult& result) = default;
    EzGetCounterModelResult(EzGetCounterModelResult&& result) = default;
    ~EzGetCounterModelResult() = default;

    EzGetCounterModelResult(gs2::mission::GetCounterModelResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetCounterModelResult& operator=(const EzGetCounterModelResult& result) = default;
    EzGetCounterModelResult& operator=(EzGetCounterModelResult&& result) = default;

    EzGetCounterModelResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetCounterModelResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzCounterModel& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetCounterModelResult> AsyncEzGetCounterModelResult;

}}}

#endif //GS2_EZ_MISSION_EZGETCOUNTERMODELRESULT_HPP_