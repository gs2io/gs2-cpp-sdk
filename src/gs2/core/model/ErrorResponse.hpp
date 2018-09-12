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

#ifndef GS2_CORE_MODEL_ERRORRESPONSE_HPP_
#define GS2_CORE_MODEL_ERRORRESPONSE_HPP_

#include "../Gs2Object.hpp"
#include "../json/IModel.hpp"
#include "../util/StringHolder.hpp"
#include "../external/optional/optional.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class ErrorResponse : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        gs2::optional<StringHolder> message;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            message(data.message)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            message(std::move(data.message))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (strcmp(name, "message") == 0) {
                if (jsonValue.IsString())
                {
                    this->message.emplace(jsonValue.GetString());
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
    ErrorResponse() :
        m_pData(nullptr)
    {}

    ErrorResponse(const ErrorResponse& errorResponse) :
        Gs2Object(errorResponse),
        m_pData(errorResponse.m_pData != nullptr ? new Data(*errorResponse.m_pData) : nullptr)
    {
    }

    ErrorResponse(ErrorResponse&& errorResponse) :
        Gs2Object(std::move(errorResponse)),
        m_pData(errorResponse.m_pData)
    {
        errorResponse.m_pData = nullptr;
    }

    ~ErrorResponse()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ErrorResponse& operator=(const ErrorResponse& errorResponse)
    {
        Gs2Object::operator=(errorResponse);

        if (&errorResponse != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = new Data(*errorResponse.m_pData);
        }

        return *this;
    }

    ErrorResponse& operator=(ErrorResponse&& errorResponse)
    {
        Gs2Object::operator=(std::move(errorResponse));

        if (&errorResponse != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = errorResponse.m_pData;
            errorResponse.m_pData = nullptr;
        }

        return *this;
    }

    const ErrorResponse* operator->() const
    {
        return this;
    }

    ErrorResponse* operator->()
    {
        return this;
    }

    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_ERRORRESPONSE_HPP_
