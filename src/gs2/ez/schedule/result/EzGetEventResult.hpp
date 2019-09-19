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

#ifndef GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_
#define GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/schedule/result/GetEventResult.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzGetEventResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** イベント */
        EzEvent item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::schedule::GetEventResult& getEventResult) :
            item(*getEventResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetEventResult() = default;
    EzGetEventResult(const EzGetEventResult& result) = default;
    EzGetEventResult(EzGetEventResult&& result) = default;
    ~EzGetEventResult() = default;

    EzGetEventResult(gs2::schedule::GetEventResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetEventResult& operator=(const EzGetEventResult& result) = default;
    EzGetEventResult& operator=(EzGetEventResult&& result) = default;

    EzGetEventResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetEventResult);
    }

    static bool isConvertible(const gs2::schedule::GetEventResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzEvent& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetEventResult> AsyncEzGetEventResult;

}}}

#endif //GS2_EZ_SCHEDULE_EZGETEVENTRESULT_HPP_