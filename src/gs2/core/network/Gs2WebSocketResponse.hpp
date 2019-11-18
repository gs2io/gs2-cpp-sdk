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

#ifndef GS2_CORE_NETWORK_GS2WEBSOCKETRESPONSE_HPP_
#define GS2_CORE_NETWORK_GS2WEBSOCKETRESPONSE_HPP_

#include "Gs2Response.hpp"
#include "Gs2SessionTaskId.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2WebSocketResponse : public Gs2Response
{
private:
    class Model : public json::IModel
    {
    protected:
        Gs2WebSocketResponse& m_Gs2WebSocketResponse;

    public:
        Model(Gs2WebSocketResponse& gs2WebSocketResponse) :
            m_Gs2WebSocketResponse(gs2WebSocketResponse)
        {}

        ~Model() = default;
    };

    class MetaInfoModel : public Model
    {
    public:
        void set(const Char name[], const json::JsonConstValue& jsonValue) GS2_OVERRIDE;

    public:
        MetaInfoModel(Gs2WebSocketResponse& gs2WebSocketResponse) :
            Model(gs2WebSocketResponse)
        {}

        ~MetaInfoModel() = default;
    };

    class ErrorBodyModel : public Model
    {
    public:
        void set(const Char name[], const json::JsonConstValue& jsonValue) GS2_OVERRIDE;

    public:
        ErrorBodyModel(Gs2WebSocketResponse& gs2WebSocketResponse) :
            Model(gs2WebSocketResponse)
        {}

        ~ErrorBodyModel() = default;
    };

    class ResponseBodyModel : public Model
    {
    private:
        json::IModel& m_ResponseModel;

    public:
        void set(const Char name[], const json::JsonConstValue& jsonValue) GS2_OVERRIDE;

    public:
        ResponseBodyModel(Gs2WebSocketResponse& gs2WebSocketResponse, json::IModel& responseModel) :
            Model(gs2WebSocketResponse),
            m_ResponseModel(responseModel)
        {}

        ~ResponseBodyModel() = default;
    };

private:
    Int32 m_StatusCode;
    Gs2SessionTaskId m_Gs2SessionTaskId;

public:
    Gs2WebSocketResponse(const char message[]);

    ~Gs2WebSocketResponse() GS2_OVERRIDE = default;

    void exportTo(json::IModel& model) GS2_OVERRIDE;

    Gs2SessionTaskId& getGs2SessionTaskId()
    {
        return m_Gs2SessionTaskId;
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2WEBSOCKETRESPONSE_HPP_
