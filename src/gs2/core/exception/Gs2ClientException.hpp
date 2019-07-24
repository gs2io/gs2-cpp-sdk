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

#ifndef GS2_CORE_EXCEPTION_GS2CLIENTEXCEPTION_HPP_
#define GS2_CORE_EXCEPTION_GS2CLIENTEXCEPTION_HPP_

#include "../Gs2Object.hpp"
#include "../json/IModel.hpp"
#include "../json/JsonParser.hpp"
#include "../util/List.hpp"
#include "../model/RequestError.hpp"

GS2_START_OF_NAMESPACE

class Gs2ClientException : public Gs2Object
{
public:
    enum Type {
        UnknownException,

        SessionNotOpenException,
        NoInternetConnectionException,

        BadRequestException,
        UnauthorizedException,
        QuotaLimitExceededException,
        NotFoundException,
        ConflictException,
        InternalServerErrorException,
        BadGatewayException,
        ServiceUnavailableException,
        RequestTimeoutException,
    };

private:
    class Data : public detail::json::IModel
    {
    public:
        optional<Type> type;
        List<RequestError> errors;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            type(data.type),
            errors(data.errors)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            type(std::move(data.type)),
            errors(std::move(data.errors))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (jsonValue.IsArray())
            {
                const auto& array = jsonValue.GetArray();
                for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                    RequestError item;
                    detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                    detail::addToList(errors, std::move(item));
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Gs2ClientException() :
        m_pData(nullptr)
    {}

    Gs2ClientException(const Gs2ClientException& gs2ClientException) :
        Gs2Object(gs2ClientException),
        m_pData(gs2ClientException.m_pData != nullptr ? new Data(*gs2ClientException.m_pData) : nullptr)
    {
    }

    Gs2ClientException(Gs2ClientException&& gs2ClientException) :
        Gs2Object(std::move(gs2ClientException)),
        m_pData(gs2ClientException.m_pData)
    {
        gs2ClientException.m_pData = nullptr;
    }

    ~Gs2ClientException()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gs2ClientException& operator=(const Gs2ClientException& gs2ClientException)
    {
        Gs2Object::operator=(gs2ClientException);

        if (&gs2ClientException != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = new Data(*gs2ClientException.m_pData);
        }

        return *this;
    }

    Gs2ClientException& operator=(Gs2ClientException&& gs2ClientException)
    {
        Gs2Object::operator=(std::move(gs2ClientException));

        if (&gs2ClientException != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = gs2ClientException.m_pData;
            gs2ClientException.m_pData = nullptr;
        }

        return *this;
    }

    const Gs2ClientException* operator->() const
    {
        return this;
    }

    Gs2ClientException* operator->()
    {
        return this;
    }

    const optional<Type>& getType() const
    {
        return ensureData().type;
    }

    void setType(Type type)
    {
        ensureData().type = type;
    }

    Gs2ClientException& withType(Type type)
    {
        setType(type);
        return *this;
    }

    const List<RequestError>& getErrors() const
    {
        return ensureData().errors;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_EXCEPTION_GS2CLIENTEXCEPTION_HPP_
