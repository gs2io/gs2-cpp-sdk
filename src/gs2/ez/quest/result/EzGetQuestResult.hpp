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

#ifndef GS2_EZ_QUEST_EZGETQUESTRESULT_HPP_
#define GS2_EZ_QUEST_EZGETQUESTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/GetQuestModelResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzGetQuestResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** None */
        EzQuestModel item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::GetQuestModelResult& getQuestModelResult) :
            item(*getQuestModelResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetQuestResult() = default;
    EzGetQuestResult(const EzGetQuestResult& result) = default;
    EzGetQuestResult(EzGetQuestResult&& result) = default;
    ~EzGetQuestResult() = default;

    EzGetQuestResult(gs2::quest::GetQuestModelResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetQuestResult& operator=(const EzGetQuestResult& result) = default;
    EzGetQuestResult& operator=(EzGetQuestResult&& result) = default;

    EzGetQuestResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetQuestResult);
    }

    static bool isConvertible(const gs2::quest::GetQuestModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzQuestModel& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetQuestResult> AsyncEzGetQuestResult;

}}}

#endif //GS2_EZ_QUEST_EZGETQUESTRESULT_HPP_