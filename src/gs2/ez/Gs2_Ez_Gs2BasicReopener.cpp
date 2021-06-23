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

#include "Gs2BasicReopener.hpp"
#include "../core/network/Gs2WebSocketSession.hpp"
#include "../core/network/Gs2RestSession.hpp"

namespace gs2 { namespace ez {

void Gs2BasicReopener::reopen(gs2::Gs2Session::OpenCallbackType callback, gs2::Gs2WebSocketSession& gs2WebSocketSession, gs2::Gs2RestSession& gs2RestSession)
{
    gs2WebSocketSession.open(
        [callback, &gs2RestSession](Gs2Session::AsyncOpenResult r)
        {
            if (r.getError())
            {
                callback(r);
            }
            else
            {
                gs2RestSession.open(callback);
            }
        }
    );
}

}}
