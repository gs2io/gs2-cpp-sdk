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

#ifndef GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_
#define GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/mission/result/GetCompleteResult.hpp>


namespace gs2 { namespace ez { namespace mission {

class EzGetCompleteResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 達成状況 */
        EzComplete item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::mission::GetCompleteResult& getCompleteResult) :
            item(getCompleteResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetCompleteResult() = default;
    EzGetCompleteResult(const EzGetCompleteResult& result) = default;
    EzGetCompleteResult(EzGetCompleteResult&& result) = default;
    ~EzGetCompleteResult() = default;

    EzGetCompleteResult(gs2::mission::GetCompleteResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetCompleteResult& operator=(const EzGetCompleteResult& result) = default;
    EzGetCompleteResult& operator=(EzGetCompleteResult&& result) = default;

    EzGetCompleteResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetCompleteResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzComplete& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetCompleteResult> AsyncEzGetCompleteResult;

}}}

#endif //GS2_EZ_MISSION_EZGETCOMPLETERESULT_HPP_