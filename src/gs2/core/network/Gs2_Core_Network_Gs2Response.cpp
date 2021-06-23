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

#include "Gs2Response.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

namespace {

class ErrorResponse : public detail::json::IModel
{
private:
    Gs2ClientException& m_Gs2ClientException;

public:
    void set(const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE
    {
        IModel::set(jsonValue);
    }

    void set(const Char name[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE
    {
        if (strcmp(name, "message") == 0 && jsonValue.IsString())
        {
            detail::json::JsonParser::parse(&m_Gs2ClientException->getModel(), jsonValue.GetString());
        }
    }

    ErrorResponse(Gs2ClientException& gs2ClientException) :
        m_Gs2ClientException(gs2ClientException)
    {}

    ~ErrorResponse() = default;
};

}

bool Gs2Response::importFrom(const json::JsonConstValue& jsonConstValue, Int32 statusCode)
{
    if (statusCode == 200)
    {
        return false;
    }
    else
    {
        m_Gs2ClientException.emplace();

        Gs2ClientException::Type type;
        switch(statusCode) {
            case -1: type = Gs2ClientException::NoInternetConnectionException; break;
            case 400: type = Gs2ClientException::BadRequestException; break;
            case 401: type = Gs2ClientException::UnauthorizedException; break;
            case 402: type = Gs2ClientException::QuotaLimitExceededException; break;
            case 404: type = Gs2ClientException::NotFoundException; break;
            case 409: type = Gs2ClientException::ConflictException; break;
            case 500: type = Gs2ClientException::InternalServerErrorException; break;
            case 502: type = Gs2ClientException::BadGatewayException; break;
            case 503: type = Gs2ClientException::ServiceUnavailableException; break;
            case 504: type = Gs2ClientException::RequestTimeoutException; break;
            default: type = Gs2ClientException::UnknownException; break;
        }
        m_Gs2ClientException->setType(type);

        ErrorResponse errorResponse(*m_Gs2ClientException);
        errorResponse.set(jsonConstValue);

        return true;
    }
}

}

GS2_END_OF_NAMESPACE
