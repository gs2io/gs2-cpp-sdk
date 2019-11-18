

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

#ifndef GS2_EZ_QUEST_MODEL_EZCONSUMEACTION_HPP_
#define GS2_EZ_QUEST_MODEL_EZCONSUMEACTION_HPP_

#include <gs2/quest/model/ConsumeAction.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzConsumeAction : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタンプタスクで実行するアクションの種類 */
        gs2::optional<StringHolder> action;
        /** 消費リクエストのJSON */
        gs2::optional<StringHolder> request;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            action(data.action),
            request(data.request)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::ConsumeAction& consumeAction) :
            action(consumeAction.getAction()),
            request(consumeAction.getRequest())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzConsumeAction() = default;
    EzConsumeAction(const EzConsumeAction& ezConsumeAction) = default;
    EzConsumeAction(EzConsumeAction&& ezConsumeAction) = default;
    ~EzConsumeAction() = default;

    EzConsumeAction(gs2::quest::ConsumeAction consumeAction) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(consumeAction)
    {}

    EzConsumeAction& operator=(const EzConsumeAction& ezConsumeAction) = default;
    EzConsumeAction& operator=(EzConsumeAction&& ezConsumeAction) = default;

    EzConsumeAction deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzConsumeAction);
    }

    gs2::quest::ConsumeAction ToModel() const
    {
        gs2::quest::ConsumeAction consumeAction;
        consumeAction.setAction(getAction());
        consumeAction.setRequest(getRequest());
        return consumeAction;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getAction() const
    {
        return *ensureData().action;
    }

    const StringHolder& getRequest() const
    {
        return *ensureData().request;
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

    EzConsumeAction& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    EzConsumeAction& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZCONSUMEACTION_HPP_