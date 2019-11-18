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

#ifndef GS2_EZ_EZSTAMPSHEET_HPP_
#define GS2_EZ_EZSTAMPSHEET_HPP_

#include "../core/common.hpp"
#include "../core/AsyncResult.hpp"
#include "../core/model/StampSheet.hpp"
#include "EzStampTask.hpp"
#include "distributor/result/EzRunStampSheetResult.hpp"
#include <functional>

namespace gs2 { namespace ez {

class Client;

class EzStampSheet
{
public:
    typedef std::function<void(distributor::AsyncEzRunStampSheetResult)> EzRunStampSheetCallback;

private:
    StringHolder m_SignedStampSheetString;
    List<EzStampTask> m_StampTasks;

public:
    EzStampSheet(StringHolder signedStampSheetString);

    void execute(
        EzRunStampSheetCallback callback,
        StringHolder stackContext,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId
    );

    const List<EzStampTask>& getEzStampTasks() const
    {
        return m_StampTasks;
    };
};

}}

#endif //GS2_EZ_EZSTAMPSHEET_HPP_
