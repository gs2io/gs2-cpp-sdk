

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

#ifndef GS2_EZ_QUEST_MODEL_EZCONTENTS_HPP_
#define GS2_EZ_QUEST_MODEL_EZCONTENTS_HPP_

#include <gs2/quest/model/Contents.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace quest {

class EzContents : public gs2::Gs2Object
{
private:
    /** クエストモデルのメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** クエストクリア時の報酬 */
    gs2::optional<List<EzAcquireAction>> m_CompleteAcquireActions;

public:
    EzContents() = default;

    EzContents(gs2::quest::Contents contents) :
        m_Metadata(contents.getMetadata())
    {
        m_CompleteAcquireActions.emplace();
        if (contents.getCompleteAcquireActions())
        {
            for (int i = 0; i < contents.getCompleteAcquireActions()->getCount(); ++i)
            {
                *m_CompleteAcquireActions += EzAcquireAction((*contents.getCompleteAcquireActions())[i]);
            }
        }
    }

    gs2::quest::Contents ToModel() const
    {
        gs2::quest::Contents contents;
        contents.setMetadata(*m_Metadata);
        {
            gs2::List<gs2::quest::AcquireAction> list;
            auto& completeAcquireActions = *m_CompleteAcquireActions;
            for (int i = 0; i < completeAcquireActions.getCount(); ++i)
            {
                list += completeAcquireActions[i].ToModel();
            }
            contents.setCompleteAcquireActions(list);
        }
        return contents;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const List<EzAcquireAction>& getCompleteAcquireActions() const
    {
        return *m_CompleteAcquireActions;
    }

    List<EzAcquireAction>& getCompleteAcquireActions()
    {
        return *m_CompleteAcquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setCompleteAcquireActions(const List<EzAcquireAction>& completeAcquireActions)
    {
        m_CompleteAcquireActions = completeAcquireActions;
    }

    void setCompleteAcquireActions(List<EzAcquireAction>&& completeAcquireActions)
    {
        m_CompleteAcquireActions = std::move(completeAcquireActions);
    }

    EzContents& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzContents& withCompleteAcquireActions(const List<EzAcquireAction>& completeAcquireActions)
    {
        setCompleteAcquireActions(completeAcquireActions);
        return *this;
    }

    EzContents& withCompleteAcquireActions(List<EzAcquireAction>&& completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZCONTENTS_HPP_