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

#ifndef GS2_EZ_GS2BASICREOPENER_HPP_
#define GS2_EZ_GS2BASICREOPENER_HPP_

#include "Reopener.hpp"
#include "../core/Gs2Object.hpp"

namespace gs2 { namespace ez {

class Gs2BasicReopener : public IReopener, public gs2::Gs2Object
{
public:
    ~Gs2BasicReopener() GS2_OVERRIDE = default;

    void reopen(gs2::Gs2Session::OpenCallbackType callback, gs2::Gs2WebSocketSession& gs2Session) GS2_OVERRIDE;
};

}}

#endif //GS2_EZ_GS2BASICREOPENER_HPP_
