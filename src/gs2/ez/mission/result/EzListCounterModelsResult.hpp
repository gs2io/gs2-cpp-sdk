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

#ifndef GS2_EZ_MISSION_EZLISTCOUNTERMODELSRESULT_HPP_
#define GS2_EZ_MISSION_EZLISTCOUNTERMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/DescribeCounterModelsResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzListCounterModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンターの種類のリスト */
        List<EzCounterModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::mission::DescribeCounterModelsResult& describeCounterModelsResult)
        {
            {
                auto& list = *describeCounterModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzCounterModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListCounterModelsResult() = default;
    EzListCounterModelsResult(const EzListCounterModelsResult& result) = default;
    EzListCounterModelsResult(EzListCounterModelsResult&& result) = default;
    ~EzListCounterModelsResult() = default;

    EzListCounterModelsResult(gs2::mission::DescribeCounterModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListCounterModelsResult& operator=(const EzListCounterModelsResult& result) = default;
    EzListCounterModelsResult& operator=(EzListCounterModelsResult&& result) = default;

    EzListCounterModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListCounterModelsResult);
    }

    static bool isConvertible(const gs2::mission::DescribeCounterModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzCounterModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListCounterModelsResult> AsyncEzListCounterModelsResult;

}}}

#endif //GS2_EZ_MISSION_EZLISTCOUNTERMODELSRESULT_HPP_