

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエストモデルのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** クエストクリア時の報酬 */
        gs2::optional<List<EzAcquireAction>> completeAcquireActions;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            metadata(data.metadata)
        {
            if (data.completeAcquireActions)
            {
                completeAcquireActions = data.completeAcquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::Contents& contents) :
            metadata(contents.getMetadata())
        {
            completeAcquireActions.emplace();
            if (contents.getCompleteAcquireActions())
            {
                for (int i = 0; i < contents.getCompleteAcquireActions()->getCount(); ++i)
                {
                    *completeAcquireActions += EzAcquireAction((*contents.getCompleteAcquireActions())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzContents() = default;
    EzContents(const EzContents& ezContents) = default;
    EzContents(EzContents&& ezContents) = default;
    ~EzContents() = default;

    EzContents(gs2::quest::Contents contents) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(contents)
    {}

    EzContents& operator=(const EzContents& ezContents) = default;
    EzContents& operator=(EzContents&& ezContents) = default;

    EzContents deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzContents);
    }

    gs2::quest::Contents ToModel() const
    {
        gs2::quest::Contents contents;
        contents.setMetadata(getMetadata());
        {
            gs2::List<gs2::quest::AcquireAction> list;
            auto& completeAcquireActions = getCompleteAcquireActions();
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

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzAcquireAction>& getCompleteAcquireActions() const
    {
        return *ensureData().completeAcquireActions;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setCompleteAcquireActions(List<EzAcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions = std::move(completeAcquireActions);
    }

    EzContents& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzContents& withCompleteAcquireActions(List<EzAcquireAction> completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZCONTENTS_HPP_