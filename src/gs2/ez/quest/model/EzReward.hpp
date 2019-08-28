

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

#include <gs2/quest/model/Reward.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzReward : public gs2::Gs2Object
{
private:
    /** スタンプシートで実行するアクションの種類 */
    gs2::optional<StringHolder> m_Action;
    /** リクエストモデル */
    gs2::optional<StringHolder> m_Request;
    /** 入手するリソースGRN */
    gs2::optional<StringHolder> m_ItemId;
    /** 入手する数量 */
    gs2::optional<Int32> m_Value;

public:
    EzReward() = default;

    EzReward(gs2::quest::Reward reward) :
        m_Action(reward.getAction()),
        m_Request(reward.getRequest()),
        m_ItemId(reward.getItemId()),
        m_Value(reward.getValue() ? *reward.getValue() : 0)
    {
    }

    gs2::quest::Reward ToModel() const
    {
        gs2::quest::Reward reward;
        reward.setAction(*m_Action);
        reward.setRequest(*m_Request);
        reward.setItemId(*m_ItemId);
        reward.setValue(*m_Value);
        return reward;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getAction() const
    {
        return *m_Action;
    }

    gs2::StringHolder& getAction()
    {
        return *m_Action;
    }

    const gs2::StringHolder& getRequest() const
    {
        return *m_Request;
    }

    gs2::StringHolder& getRequest()
    {
        return *m_Request;
    }

    const gs2::StringHolder& getItemId() const
    {
        return *m_ItemId;
    }

    gs2::StringHolder& getItemId()
    {
        return *m_ItemId;
    }

    Int32 getValue() const
    {
        return *m_Value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setAction(Char* action)
    {
        m_Action.emplace(action);
    }

    void setRequest(Char* request)
    {
        m_Request.emplace(request);
    }

    void setItemId(Char* itemId)
    {
        m_ItemId.emplace(itemId);
    }

    void setValue(Int32 value)
    {
        m_Value = value;
    }

    EzReward& withAction(Char* action)
    {
        setAction(action);
        return *this;
    }

    EzReward& withRequest(Char* request)
    {
        setRequest(request);
        return *this;
    }

    EzReward& withItemId(Char* itemId)
    {
        setItemId(itemId);
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