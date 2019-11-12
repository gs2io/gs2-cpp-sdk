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

#ifndef GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_
#define GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_

#include "../core/common.hpp"
#include "../core/AsyncResult.hpp"
#include "EzStampSheet.hpp"
#include <functional>
#include <mutex>

namespace gs2 { namespace ez {

class Client;

class StampSheetStateMachine
{
public:
    typedef std::function<void(EzStampSheet, distributor::AsyncEzRunStampSheetResult)> EzStampSheetCallback;
    typedef std::function<void(EzStampTask, distributor::AsyncEzRunStampTaskResult)> EzStampTaskCallback;

private:
    EzStampSheet m_EzStampSheet;
    Client& m_Client;
    StringHolder m_DistributorNamespaceName;
    StringHolder m_StampSheetEncryptKeyId;

    EzStampSheetCallback m_EzStampSheetCallback;
    EzStampTaskCallback m_EzStampTaskCallback;

    enum class State {
        Idle,
        Running,
    } m_State;
    Int32 m_Step;
    StringHolder m_StackContext;
    distributor::AsyncEzRunStampSheetResult m_AsyncEzRunStampSheetResult;

    std::mutex m_Mutex;

private:
    void executeStep(Int32 step);

public:
    StampSheetStateMachine(
        StringHolder stampSheetString,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId,
        EzStampSheetCallback ezStampSheetCallback,
        EzStampTaskCallback ezStampTaskCallback = nullptr
    );

    StampSheetStateMachine(
        EzStampSheet ezStampSheet,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId,
        EzStampSheetCallback ezStampSheetCallback,
        EzStampTaskCallback ezStampTaskCallback = nullptr
    );

    void execute();
};

}}

#endif //GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_
