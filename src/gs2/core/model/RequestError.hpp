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

#ifndef GS2_CORE_MODEL_REQUESTERROR_HPP_
#define GS2_CORE_MODEL_REQUESTERROR_HPP_

#include "../Gs2Object.hpp"
#include "../json/IModel.hpp"
#include "../util/StringHolder.hpp"
#include "../util/StandardAllocator.hpp"
#include "../external/optional/optional.hpp"
#include <memory>

GS2_START_OF_NAMESPACE

class RequestError : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        gs2::optional<StringHolder> component;
        gs2::optional<StringHolder> message;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            component(data.component),
            message(data.message)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            component(std::move(data.component)),
            message(std::move(data.message))
        {}

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (strcmp(name, "component") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->component.emplace(jsonValue.GetString());
                }
            }
            else if (strcmp(name, "message") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->message.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RequestError() = default;
    RequestError(const RequestError& requestError) = default;
    RequestError(RequestError&& requestError) = default;
    ~RequestError() = default;

    RequestError& operator=(const RequestError& requestError) = default;
    RequestError& operator=(RequestError&& requestError) = default;

    RequestError deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RequestError);
    }

    const RequestError* operator->() const
    {
        return this;
    }

    RequestError* operator->()
    {
        return this;
    }

    const optional<StringHolder>& getComponent() const
    {
        return ensureData().component;
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

GS2_END_OF_NAMESPACE


#endif //GS2_CORE_MODEL_REQUESTERROR_HPP_
