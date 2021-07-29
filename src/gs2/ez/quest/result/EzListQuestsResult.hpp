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

#ifndef GS2_EZ_QUEST_EZLISTQUESTSRESULT_HPP_
#define GS2_EZ_QUEST_EZLISTQUESTSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/DescribeQuestModelsResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzListQuestsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** Noneのリスト */
        List<EzQuestModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::DescribeQuestModelsResult& describeQuestModelsResult)
        {
            if (describeQuestModelsResult.getItems())
            {
                auto& list = *describeQuestModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzQuestModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListQuestsResult() = default;
    EzListQuestsResult(const EzListQuestsResult& result) = default;
    EzListQuestsResult(EzListQuestsResult&& result) = default;
    ~EzListQuestsResult() = default;

    EzListQuestsResult(gs2::quest::DescribeQuestModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListQuestsResult& operator=(const EzListQuestsResult& result) = default;
    EzListQuestsResult& operator=(EzListQuestsResult&& result) = default;

    EzListQuestsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListQuestsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzQuestModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListQuestsResult> AsyncEzListQuestsResult;

}}}

#endif //GS2_EZ_QUEST_EZLISTQUESTSRESULT_HPP_