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

#ifndef GS2_EZ_QUEST_MODEL_EZREWARD_HPP_
#define GS2_EZ_QUEST_MODEL_EZREWARD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace quest {

class Reward;

}

namespace ez { namespace quest {

class EzReward : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタンプシートで実行するアクションの種類 */
        StringHolder action;
        /** リクエストモデル */
        StringHolder request;
        /** 入手するリソースGRN */
        StringHolder itemId;
        /** 入手する数量 */
        Int32 value;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::quest::Reward& reward);
        Data(const gs2::optional<gs2::quest::Reward>& reward);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzReward() = default;
    EzReward(const EzReward& ezReward) = default;
    EzReward(EzReward&& ezReward) = default;
    ~EzReward() = default;

    EzReward(gs2::quest::Reward reward);
    EzReward(gs2::optional<gs2::quest::Reward> reward);

    EzReward& operator=(const EzReward& ezReward) = default;
    EzReward& operator=(EzReward&& ezReward) = default;

    EzReward deepCopy() const;

    gs2::quest::Reward ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getAction() const
    {
        return ensureData().action;
    }

    const StringHolder& getRequest() const
    {
        return ensureData().request;
    }

    const StringHolder& getItemId() const
    {
        return ensureData().itemId;
    }

    Int32 getValue() const
    {
        return ensureData().value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAction(StringHolder action)
    {
        ensureData().action = std::move(action);
    }

    void setRequest(StringHolder request)
    {
        ensureData().request = std::move(request);
    }

    void setItemId(StringHolder itemId)
    {
        ensureData().itemId = std::move(itemId);
    }

    void setValue(Int32 value)
    {
        ensureData().value = value;
    }

    EzReward& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    EzReward& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }

    EzReward& withItemId(StringHolder itemId)
    {
        setItemId(std::move(itemId));
        return *this;
    }

    EzReward& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZREWARD_HPP_