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

#ifndef GS2_CORE_NETWORK_GS2RESPONSE_HPP_
#define GS2_CORE_NETWORK_GS2RESPONSE_HPP_

#include "../Gs2Object.hpp"
#include "../external/optional/optional.hpp"
#include "../exception/Gs2ClientException.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

namespace json {
    class IModel;
}

class Gs2Response : public Gs2Object
{
private:
    const char* m_Message;
    optional<Gs2ClientException> m_Gs2ClientException;

protected:
    const char* getMessage() const
    {
        return m_Message;
    }

    bool importFrom(const json::JsonConstValue& jsonConstValue, Int32 statusCode);

public:
    Gs2Response(const char message[]) :
        m_Message(message)
    {}

    virtual ~Gs2Response() = default;

    optional<Gs2ClientException>& getGs2ClientException()
    {
        return m_Gs2ClientException;
    }

    virtual void exportTo(json::IModel& model) = 0;
};

class Gs2ClientErrorResponse : public Gs2Response
{
public:
    Gs2ClientErrorResponse() :
        Gs2Response("")
    {}

    ~Gs2ClientErrorResponse() GS2_OVERRIDE = default;

    void exportTo(json::IModel& model) GS2_OVERRIDE {}
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2RESPONSE_HPP_
