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

#ifndef GS2_CORE_NETWORK_GS2RESTRESPONSE_HPP_
#define GS2_CORE_NETWORK_GS2RESTRESPONSE_HPP_

#include "Gs2Response.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2RestResponse : public Gs2Response
{
private:
    class Model : public json::IModel
    {
    private:
        Gs2RestResponse& m_Gs2RestResponse;
        Int32 m_StatusCode;

    public:
        void set(const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;

    public:
        Model(Gs2RestResponse& gs2RestResponse, Int32 statusCode) :
            m_Gs2RestResponse(gs2RestResponse),
            m_StatusCode(statusCode)
        {}

        ~Model() = default;
    };

public:
    Gs2RestResponse(const char message[], Int32 statusCode);

    ~Gs2RestResponse() GS2_OVERRIDE = default;

    void exportTo(json::IModel& model) GS2_OVERRIDE;
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2RESTRESPONSE_HPP_
