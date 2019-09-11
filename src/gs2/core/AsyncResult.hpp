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

#ifndef GS2_CORE_ASYNCRESULT_HPP_
#define GS2_CORE_ASYNCRESULT_HPP_

#include "Gs2Object.hpp"
#include "exception/Gs2ClientException.hpp"
#include "external/optional/optional.hpp"

GS2_START_OF_NAMESPACE

template<class T>
class AsyncResult : public Gs2Object
{
private:
    class Data : public Gs2Object
    {
    public:
        optional<T> result;
        optional<Gs2ClientException> error;
        
        Data() = default;
        
        Data(const Data& data) :
            Gs2Object(data)
        {
            if (data.result)
            {
                result = data.result->deepCopy();
            }
            if (data.error)
            {
                error = data.error->deepCopy();
            }
        }
        
        Data(Data&& data) = default;
        
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AsyncResult() = default;
    AsyncResult(const AsyncResult& asyncResult) = default;
    AsyncResult(AsyncResult&& asyncResult) = default;
    ~AsyncResult() = default;

    AsyncResult(T&& result, optional<Gs2ClientException>&& error)
    {
        ensureData().result.emplace(std::move(result));
        ensureData().error = std::move(error);
    }

    AsyncResult(T&& result)
    {
        ensureData().result.emplace(std::move(result));
    }

    AsyncResult(Gs2ClientException&& error)
    {
        ensureData().error = std::move(error);
    }

    AsyncResult& operator=(const AsyncResult& asyncResult) = default;
    AsyncResult& operator=(AsyncResult&& asyncResult) = default;

    AsyncResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AsyncResult);
    }

    const optional<T>& getResult() const
    {
        return ensureData().result;
    }

    const optional<Gs2ClientException>& getError() const
    {
        return ensureData().error;
    }
};

template<>
class AsyncResult<void> : public Gs2Object
{
private:
    class Data : public Gs2Object
    {
    public:
        optional<Gs2ClientException> error;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            if (data.error)
            {
                error = data.error->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AsyncResult() = default;
    AsyncResult(const AsyncResult& asyncResult) = default;
    AsyncResult(AsyncResult&& asyncResult) = default;
    ~AsyncResult() = default;

    AsyncResult(optional<Gs2ClientException>&& error)
    {
        ensureData().error = std::move(error);
    }

    AsyncResult(Gs2ClientException&& error)
    {
        ensureData().error = std::move(error);
    }

    AsyncResult& operator=(const AsyncResult& asyncResult) = default;
    AsyncResult& operator=(AsyncResult&& asyncResult) = default;

    AsyncResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AsyncResult);
    }

    const optional<Gs2ClientException>& getError() const
    {
        return ensureData().error;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_ASYNCRESULT_HPP_
