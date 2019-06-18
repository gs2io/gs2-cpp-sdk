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
        
        Data()
        {}
        
        Data(const Data& data) :
            Gs2Object(data),
            result(data.result),
            error(data.error)
        {}
        
        Data(Data&& data) :
            Gs2Object(std::move(data)),
            result(std::move(data.result)),
            error(std::move(data.error))
        {}
        
        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    AsyncResult() :
        m_pData(nullptr)
    {}

    AsyncResult(T& result, optional<Gs2ClientException>& error) :
        m_pData(nullptr)
    {
        ensureData().result.emplace(std::move(result));
        ensureData().error = std::move(error);
    }

    AsyncResult(const AsyncResult& asyncResult) :
        Gs2Object(asyncResult),
        m_pData(asyncResult.m_pData != nullptr ? new Data(*asyncResult.m_pData) : nullptr)
    {}

    AsyncResult(AsyncResult&& asyncResult) :
        Gs2Object(std::move(asyncResult)),
        m_pData(asyncResult.m_pData)
    {
        asyncResult.m_pData = nullptr;
    }

    ~AsyncResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AsyncResult& operator=(const AsyncResult& asyncResult)
    {
        Gs2Object::operator=(asyncResult);

        if (&asyncResult != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = new Data(*asyncResult.m_pData);
        }

        return *this;
    }

    AsyncResult& operator=(AsyncResult&& asyncResult)
    {
        Gs2Object::operator=(std::move(asyncResult));

        if (&asyncResult != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = asyncResult.m_pData;
            asyncResult.m_pData = nullptr;
        }

        return *this;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            error(data.error)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            error(std::move(data.error))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    AsyncResult() :
        m_pData(nullptr)
    {}

    AsyncResult(optional<Gs2ClientException>& error) :
        m_pData(nullptr)
    {
        ensureData().error = std::move(error);
    }

    AsyncResult(Gs2ClientException& error) :
        m_pData(nullptr)
    {
        ensureData().error = std::move(error);
    }

    AsyncResult(const AsyncResult& asyncResult) :
        Gs2Object(asyncResult),
        m_pData(asyncResult.m_pData != nullptr ? new Data(*asyncResult.m_pData) : nullptr)
    {}

    AsyncResult(AsyncResult&& asyncResult) :
        Gs2Object(std::move(asyncResult)),
        m_pData(asyncResult.m_pData)
    {
        asyncResult.m_pData = nullptr;
    }

    ~AsyncResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AsyncResult& operator=(const AsyncResult& asyncResult)
    {
        Gs2Object::operator=(asyncResult);

        if (&asyncResult != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = asyncResult.m_pData != nullptr ? new Data(*asyncResult.m_pData) : nullptr;
        }

        return *this;
    }

    AsyncResult& operator=(AsyncResult&& asyncResult)
    {
        Gs2Object::operator=(std::move(asyncResult));

        if (&asyncResult != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = asyncResult.m_pData;
            asyncResult.m_pData = nullptr;
        }

        return *this;
    }

    const optional<Gs2ClientException>& getError() const
    {
        return ensureData().error;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_ASYNCRESULT_HPP_
