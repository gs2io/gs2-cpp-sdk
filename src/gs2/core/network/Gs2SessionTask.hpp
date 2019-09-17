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

class Gs2SessionTask : public Gs2Object, public detail::IntrusiveListItem<Gs2SessionTask>
{
    friend gs2::Gs2Session;

private:
    Gs2Session& m_Gs2Session;
    Gs2SessionTaskId m_Gs2SessionTaskId;

protected:
    Gs2Session& getGs2Session()
    {
        return m_Gs2Session;
    }

    const Gs2SessionTaskId& getGs2SessionTaskId() const
    {
        return m_Gs2SessionTaskId;
    }

    // レスポンスが直接セッションに届かない派生クラスでは、この関数でセッションにレスポンスの到着を伝える
    void onResponse(Gs2Response& gs2Response);

    const optional<StringHolder>& getProjectToken() const;

private:
    virtual void triggerUserCallback(Gs2Response& gs2Response) = 0;

    // Gs2Session::execute() から利用
    virtual void prepareImpl() = 0;     // ロックの内側から呼ばれるので m_Gs2Session のプライベートメンバに安全にアクセス可能
    virtual void executeImpl() = 0;     // ロックの外側から呼ばれるので直接コールバックを呼び出し可能

public:
    Gs2SessionTask(Gs2Session& gs2Session) :
        m_Gs2Session(gs2Session)
    {}

    virtual ~Gs2SessionTask() = default;

    void callback(Gs2Response& gs2Response);

    void execute();
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSIONTASK_HPP_
