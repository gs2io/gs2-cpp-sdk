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

#ifndef GS2_EZ_EZSTAMPTASK_HPP_
#define GS2_EZ_EZSTAMPTASK_HPP_

#include "../core/common.hpp"
#include "../core/AsyncResult.hpp"
#include "../core/model/StampTask.hpp"
#include "EzStampTask.hpp"
#include "distributor/result/EzRunStampTaskResult.hpp"
#include <functional>

namespace gs2 { namespace ez {

class Client;

class EzStampTask
{
public:
    typedef std::function<void(distributor::AsyncEzRunStampTaskResult)> EzRunStampTaskCallback;

private:
    StringHolder m_StampTaskString;

public:
    EzStampTask(StringHolder stampTaskString);

    void execute(
        EzRunStampTaskCallback callback,
        StringHolder stackContext,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId
    );
};

}}

#endif //GS2_EZ_EZSTAMPTASK_HPP_
