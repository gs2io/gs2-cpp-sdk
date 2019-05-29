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

#include "AbstractGs2Client.hpp"
#include "AsyncResult.hpp"
#include "control/Gs2BasicRequest.hpp"
#include "model/IGs2Credential.hpp"
#include "network/HttpTask.hpp"
#include "util/StringVariable.hpp"
#include <string>
#include <network/HttpRequest.h>

GS2_START_OF_NAMESPACE

AbstractGs2ClientBase::AbstractGs2ClientBase(IGs2Credential& credential) :
    m_Credential(credential),
    m_Region(Region::AP_NORTHEAST_1)
{
}

AbstractGs2ClientBase::AbstractGs2ClientBase(IGs2Credential& credential, const Region& region) :
    m_Credential(credential),
    m_Region(region)
{
}

AbstractGs2ClientBase::AbstractGs2ClientBase(IGs2Credential& credential, const Char region[]) :
    m_Credential(credential),
    m_Region(region)
{
}

void AbstractGs2ClientBase::setUrl(::cocos2d::network::HttpRequest& httpRequest, const Char url[]) const
{
    detail::StringVariable urlString(url);
    urlString.replace("{service}", getEndPoint());
    urlString.replace("{region}", m_Region.getName());

    httpRequest.setUrl(urlString.c_str());
}

GS2_END_OF_NAMESPACE
