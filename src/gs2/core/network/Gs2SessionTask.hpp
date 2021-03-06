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
#include "../util/StringHolder.hpp"
#include "Gs2SessionTaskId.hpp"

GS2_START_OF_NAMESPACE

class Gs2Session;
class Gs2ClientException;

namespace detail {

class Gs2Response;

class Gs2Task : public Gs2Object, public detail::IntrusiveListItem<Gs2Task>
{
public:
    virtual ~Gs2Task() = default;

    virtual void triggerCallback() = 0;
};

class Gs2SessionTask : public Gs2Task
{
    friend gs2::Gs2Session;

private:
    Gs2SessionTaskId m_Gs2SessionTaskId;

protected:
    void onResponse(Gs2Session& gs2Session, Gs2Response& gs2Response);

    const Gs2SessionTaskId& getGs2SessionTaskId() const
    {
        return m_Gs2SessionTaskId;
    }

private:
    // Gs2Session::execute() から利用
    void prepare(Gs2Session& gs2Session, Gs2SessionTaskId gs2SessionTaskId);
    void execute(Gs2Session& gs2Session);

    virtual void prepareImpl(Gs2Session& gs2Session, const StringHolder& projectToken) = 0;   // ロックの内側から呼ばれるので m_Gs2Session のプライベートメンバに安全にアクセス可能
    virtual void executeImpl(Gs2Session& gs2Session) = 0;   // ロックの外側から呼ばれるので直接コールバックを呼び出し可能

public:
    Gs2SessionTask() = default;

    virtual ~Gs2SessionTask() = default;

    virtual void setResult(Gs2Response& gs2Response) = 0;
    virtual void setResult(Gs2ClientException gs2ClientException) = 0;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSIONTASK_HPP_
