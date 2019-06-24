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

#include "Gs2WebSocketResponse.hpp"
#include "../json/JsonParser.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

namespace detail {

void Gs2WebSocketResponse::MetaInfoModel::set(const Char name[], const json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name, "requestId") == 0) {
        if (jsonValue.IsString())
        {
            m_Gs2WebSocketResponse.m_Gs2SessionTaskId.importFrom(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name, "status") == 0)
    {
        if (jsonValue.IsInt())
        {
            m_Gs2WebSocketResponse.m_StatusCode = jsonValue.GetInt();
        }
    }
}

void Gs2WebSocketResponse::ErrorBodyModel::set(const Char name[], const json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name, "body") == 0)
    {
        if (jsonValue.IsObject())
        {
            m_Gs2WebSocketResponse.importFrom(jsonValue, m_Gs2WebSocketResponse.m_StatusCode);
        }
    }
}

void Gs2WebSocketResponse::ResponseBodyModel::set(const Char name[], const json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name, "body") == 0)
    {
        if (jsonValue.IsObject())
        {
            m_ResponseModel.set(jsonValue);
        }
    }
}

Gs2WebSocketResponse::Gs2WebSocketResponse(const char message[]) :
    Gs2Response(message),
    m_StatusCode(0)
{
    MetaInfoModel metaInfoModel(*this);
    json::JsonParser::parse(&metaInfoModel, message);

    if (m_StatusCode != 200)    // 基底クラスの処理と重複するが、効率化のために事前判定する
    {
        ErrorBodyModel errorBodyModel(*this);
        json::JsonParser::parse(&errorBodyModel, message);
    }
}

void Gs2WebSocketResponse::exportTo(json::IModel& model)
{
    ResponseBodyModel responseBodyModel(*this, model);
    json::JsonParser::parse(&responseBodyModel, getMessage());
}

}

GS2_END_OF_NAMESPACE
