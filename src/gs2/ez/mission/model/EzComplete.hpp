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

#ifndef GS2_EZ_MISSION_MODEL_EZCOMPLETE_HPP_
#define GS2_EZ_MISSION_MODEL_EZCOMPLETE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace mission {

class Complete;

}

namespace ez { namespace mission {

class EzComplete : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ミッショングループ名 */
        StringHolder missionGroupName;
        /** 達成済みのタスク名リスト */
        List<StringHolder> completedMissionTaskNames;
        /** 報酬の受け取り済みのタスク名リスト */
        List<StringHolder> receivedMissionTaskNames;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::Complete& complete);
        Data(const gs2::optional<gs2::mission::Complete>& complete);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzComplete() = default;
    EzComplete(const EzComplete& ezComplete) = default;
    EzComplete(EzComplete&& ezComplete) = default;
    ~EzComplete() = default;

    EzComplete(gs2::mission::Complete complete);
    EzComplete(gs2::optional<gs2::mission::Complete> complete);

    EzComplete& operator=(const EzComplete& ezComplete) = default;
    EzComplete& operator=(EzComplete&& ezComplete) = default;

    EzComplete deepCopy() const;

    gs2::mission::Complete ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMissionGroupName() const
    {
        return ensureData().missionGroupName;
    }

    const List<StringHolder>& getCompletedMissionTaskNames() const
    {
        return ensureData().completedMissionTaskNames;
    }

    const List<StringHolder>& getReceivedMissionTaskNames() const
    {
        return ensureData().receivedMissionTaskNames;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName = std::move(missionGroupName);
    }

    void setCompletedMissionTaskNames(List<StringHolder> completedMissionTaskNames)
    {
        ensureData().completedMissionTaskNames = std::move(completedMissionTaskNames);
    }

    void setReceivedMissionTaskNames(List<StringHolder> receivedMissionTaskNames)
    {
        ensureData().receivedMissionTaskNames = std::move(receivedMissionTaskNames);
    }

    EzComplete& withMissionGroupName(StringHolder missionGroupName)
    {
        setMissionGroupName(std::move(missionGroupName));
        return *this;
    }

    EzComplete& withCompletedMissionTaskNames(List<StringHolder> completedMissionTaskNames)
    {
        setCompletedMissionTaskNames(std::move(completedMissionTaskNames));
        return *this;
    }

    EzComplete& withReceivedMissionTaskNames(List<StringHolder> receivedMissionTaskNames)
    {
        setReceivedMissionTaskNames(std::move(receivedMissionTaskNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOMPLETE_HPP_