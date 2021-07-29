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

#ifndef GS2_EZ_QUEST_MODEL_EZCOMPLETEDQUESTLIST_HPP_
#define GS2_EZ_QUEST_MODEL_EZCOMPLETEDQUESTLIST_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace quest {

class CompletedQuestList;

}

namespace ez { namespace quest {

class EzCompletedQuestList : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエストグループ名 */
        StringHolder questGroupName;
        /** 攻略済みのクエスト名一覧のリスト */
        List<StringHolder> completeQuestNames;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::quest::CompletedQuestList& completedQuestList);
        Data(const gs2::optional<gs2::quest::CompletedQuestList>& completedQuestList);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCompletedQuestList() = default;
    EzCompletedQuestList(const EzCompletedQuestList& ezCompletedQuestList) = default;
    EzCompletedQuestList(EzCompletedQuestList&& ezCompletedQuestList) = default;
    ~EzCompletedQuestList() = default;

    EzCompletedQuestList(gs2::quest::CompletedQuestList completedQuestList);
    EzCompletedQuestList(gs2::optional<gs2::quest::CompletedQuestList> completedQuestList);

    EzCompletedQuestList& operator=(const EzCompletedQuestList& ezCompletedQuestList) = default;
    EzCompletedQuestList& operator=(EzCompletedQuestList&& ezCompletedQuestList) = default;

    EzCompletedQuestList deepCopy() const;

    gs2::quest::CompletedQuestList ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getQuestGroupName() const
    {
        return ensureData().questGroupName;
    }

    const List<StringHolder>& getCompleteQuestNames() const
    {
        return ensureData().completeQuestNames;
    }

    // ========================================
    //   Setters
    // ========================================

    void setQuestGroupName(StringHolder questGroupName)
    {
        ensureData().questGroupName = std::move(questGroupName);
    }

    void setCompleteQuestNames(List<StringHolder> completeQuestNames)
    {
        ensureData().completeQuestNames = std::move(completeQuestNames);
    }

    EzCompletedQuestList& withQuestGroupName(StringHolder questGroupName)
    {
        setQuestGroupName(std::move(questGroupName));
        return *this;
    }

    EzCompletedQuestList& withCompleteQuestNames(List<StringHolder> completeQuestNames)
    {
        setCompleteQuestNames(std::move(completeQuestNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZCOMPLETEDQUESTLIST_HPP_