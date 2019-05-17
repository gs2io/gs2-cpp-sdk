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

#ifndef GS2_CORE_MODEL_IGS2CREDENTIAL_HPP_
#define GS2_CORE_MODEL_IGS2CREDENTIAL_HPP_

#include "../Gs2Object.hpp"

GS2_START_OF_NAMESPACE

namespace detail {
class Gs2StandardHttpTaskBase;
}

class IGs2Credential : public Gs2Object
{
public:
    IGs2Credential() = default;
    virtual ~IGs2Credential() = default;

    virtual void authorizeAndExecute(detail::Gs2StandardHttpTaskBase& gs2StandardHttpTaskBase) = 0;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_IGS2CREDENTIAL_HPP_
