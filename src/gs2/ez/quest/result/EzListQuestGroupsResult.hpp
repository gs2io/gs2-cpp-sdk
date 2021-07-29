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

#ifndef GS2_EZ_QUEST_EZLISTQUESTGROUPSRESULT_HPP_
#define GS2_EZ_QUEST_EZLISTQUESTGROUPSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/DescribeQuestGroupModelsResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzListQuestGroupsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエストグループのリスト */
        List<EzQuestGroupModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::DescribeQuestGroupModelsResult& describeQuestGroupModelsResult)
        {
            if (describeQuestGroupModelsResult.getItems())
            {
                auto& list = *describeQuestGroupModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzQuestGroupModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListQuestGroupsResult() = default;
    EzListQuestGroupsResult(const EzListQuestGroupsResult& result) = default;
    EzListQuestGroupsResult(EzListQuestGroupsResult&& result) = default;
    ~EzListQuestGroupsResult() = default;

    EzListQuestGroupsResult(gs2::quest::DescribeQuestGroupModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListQuestGroupsResult& operator=(const EzListQuestGroupsResult& result) = default;
    EzListQuestGroupsResult& operator=(EzListQuestGroupsResult&& result) = default;

    EzListQuestGroupsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListQuestGroupsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzQuestGroupModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListQuestGroupsResult> AsyncEzListQuestGroupsResult;

}}}

#endif //GS2_EZ_QUEST_EZLISTQUESTGROUPSRESULT_HPP_