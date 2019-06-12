/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_CORE_NETWORK_GS2SESSIONTASK_HPP_
#define GS2_CORE_NETWORK_GS2SESSIONTASK_HPP_

#include "../Gs2Object.hpp"
#include "../util/IntrusiveList.hpp"

GS2_START_OF_NAMESPACE

// TODO
class Gs2RestSession;
typedef Gs2RestSession IGs2Session;
class Gs2ClientException;

namespace detail {

class Gs2SessionTask : public Gs2Object, public detail::IntrusiveListItem<Gs2SessionTask>
{
protected:
    IGs2Session& m_Gs2Session;

private:
    virtual void triggerUserCallback(const Char responseBody[], Gs2ClientException* pGs2ClientException) = 0;

public:
    Gs2SessionTask(IGs2Session& gs2Session) :
        m_Gs2Session(gs2Session)
    {}

    virtual ~Gs2SessionTask() = default;

    void callback(const Char responseBody[], Gs2ClientException* pGs2ClientException);

    virtual void execute() = 0;

    void sendBySession();
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSIONTASK_HPP_
