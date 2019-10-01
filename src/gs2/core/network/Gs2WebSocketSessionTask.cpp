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

#include "Gs2WebSocketSessionTask.hpp"
#include "Gs2WebSocketSession.hpp"
#include "../json/JsonWriter.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2WebSocketSessionTaskBase::prepareImpl(Gs2Session& gs2Session, const StringHolder& projectToken)
{
    detail::json::JsonWriter jsonWriter;

    jsonWriter.writeObjectStart();

    constructRequestImpl(jsonWriter);

    jsonWriter.writePropertyName("xGs2ClientId");
    jsonWriter.writeCharArray(gs2Session.getGs2Credential().getClientId());
    jsonWriter.writePropertyName("xGs2ProjectToken");
    jsonWriter.writeCharArray(projectToken);

    jsonWriter.writePropertyName("x_gs2");
    jsonWriter.writeObjectStart();
    jsonWriter.writePropertyName("service");
    jsonWriter.writeCharArray(getServiceName());
    jsonWriter.writePropertyName("component");
    jsonWriter.writeCharArray(getComponentName());
    jsonWriter.writePropertyName("function");
    jsonWriter.writeCharArray(getFunctionName());
    jsonWriter.writePropertyName("contentType");
    jsonWriter.writeCharArray("application/json");
    jsonWriter.writePropertyName("requestId");
    {
        char buffer[16];
        getGs2SessionTaskId().exportTo(buffer, sizeof(buffer));
        jsonWriter.writeCharArray(buffer);
    }
    jsonWriter.writeObjectEnd();

    jsonWriter.writeObjectEnd();

    static_cast<Gs2WebSocketSession&>(gs2Session).send(jsonWriter.toString());
}

void Gs2WebSocketSessionTaskBase::executeImpl(Gs2Session& gs2Session)
{
    GS2_NOT_USED(gs2Session);
}

}

GS2_END_OF_NAMESPACE
