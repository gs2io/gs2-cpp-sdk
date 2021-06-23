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

#include "Gs2RestResponse.hpp"
#include "../json/JsonParser.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2RestResponse::Model::set(const detail::json::JsonConstValue& jsonValue)
{
    m_Gs2RestResponse.importFrom(jsonValue, m_StatusCode);
}

Gs2RestResponse::Gs2RestResponse(const char message[], Int32 statusCode)
    : Gs2Response(message)
{
    Model model(*this, statusCode);
    json::JsonParser::parse(&model, message);
}

void Gs2RestResponse::exportTo(json::IModel& model)
{
    json::JsonParser::parse(&model, getMessage());
}

}

GS2_END_OF_NAMESPACE
