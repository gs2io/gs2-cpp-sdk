

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

#ifndef GS2_EZ_INBOX_MODEL_EZACQUIREACTION_HPP_
#define GS2_EZ_INBOX_MODEL_EZACQUIREACTION_HPP_

#include <gs2/inbox/model/AcquireAction.hpp>


namespace gs2 { namespace ez { namespace inbox {

class EzAcquireAction : public gs2::Gs2Object
{
private:
    /** スタンプシートで実行するアクションの種類 */
    gs2::optional<StringHolder> m_Action;
    /** 入手リクエストのJSON */
    gs2::optional<StringHolder> m_Request;

public:
    EzAcquireAction() = default;

    EzAcquireAction(gs2::inbox::AcquireAction acquireAction) :
        m_Action(acquireAction.getAction()),
        m_Request(acquireAction.getRequest())
    {
    }

    gs2::inbox::AcquireAction ToModel() const
    {
        gs2::inbox::AcquireAction acquireAction;
        acquireAction.setAction(*m_Action);
        acquireAction.setRequest(*m_Request);
        return acquireAction;
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

    EzAcquireAction& withAction(Char* action)
    {
        setAction(action);
        return *this;
    }

    EzAcquireAction& withRequest(Char* request)
    {
        setRequest(request);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INBOX_EZACQUIREACTION_HPP_