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

#ifndef GS2_CORE_NETWORK_GS2RESTSESSION_HPP_
#define GS2_CORE_NETWORK_GS2RESTSESSION_HPP_

#include "Gs2Session.hpp"
#include "HttpTask.hpp"
#include <atomic>

GS2_START_OF_NAMESPACE

class Gs2RestSession : public Gs2Session
{
public:
    static const char EndpointHost[];

private:
    class Gs2LoginTask : public detail::Gs2HttpTask
    {
    private:
        Gs2RestSession& m_Gs2RestSession;

    private:
        void callback(detail::Gs2RestResponse& gs2RestResponse) GS2_OVERRIDE;

    public:
        explicit Gs2LoginTask(Gs2RestSession& gs2RestSession);
        ~Gs2LoginTask() GS2_OVERRIDE = default;
    };

private:
    std::atomic<bool> m_IsOpenCancelled;

public:
    explicit Gs2RestSession(const BasicGs2Credential& gs2Credential) :
        Gs2Session(gs2Credential),
        m_IsOpenCancelled(false)
    {}

    Gs2RestSession(const BasicGs2Credential& gs2Credential, const Region& region) :
        Gs2Session(gs2Credential, region),
        m_IsOpenCancelled(false)
    {}

    Gs2RestSession(const BasicGs2Credential& gs2Credential, const Char region[]) :
        Gs2Session(gs2Credential, region),
        m_IsOpenCancelled(false)
    {}

    ~Gs2RestSession() GS2_OVERRIDE = default;

private:
    bool openImpl() GS2_OVERRIDE;
    void cancelOpenImpl() GS2_OVERRIDE;
    bool closeImpl() GS2_OVERRIDE;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2RESTSESSION_HPP_
