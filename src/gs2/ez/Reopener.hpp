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

#ifndef GS2_EZ_REOPENER_HPP_
#define GS2_EZ_REOPENER_HPP_

#include "../core/common.hpp"
#include "../core/network/Gs2Session.hpp"
#include <functional>

namespace gs2 {

class Gs2RestSession;

namespace ez {

class IReopener
{
public:
    virtual void reopen(gs2::Gs2RestSession& session, gs2::Gs2Session::OpenCallbackType callback) = 0;
};

}
}

#endif //GS2_EZ_REOPENER_HPP_
