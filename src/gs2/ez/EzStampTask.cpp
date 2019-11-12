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

#include "EzStampTask.hpp"
#include "../core/model/SignedStampTask.hpp"
#include "../core/json/JsonParser.hpp"
#include "Client.hpp"

namespace gs2 { namespace ez {

EzStampTask::EzStampTask(StringHolder stampSheetString) :
    m_StampTaskString(stampSheetString)
{
}

void EzStampTask::execute(
    EzRunStampTaskCallback callback,
    StringHolder stackContext,
    Client& client,
    StringHolder distributorNamespaceName,
    StringHolder stampSheetEncryptKeyId
)
{
    client.distributor.runStampTask(
        std::move(callback),
        std::move(distributorNamespaceName),
        m_StampTaskString,
        std::move(stampSheetEncryptKeyId),
        std::move(stackContext)
    );
}

}}
