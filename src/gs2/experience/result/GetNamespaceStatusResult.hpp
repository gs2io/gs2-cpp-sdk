/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
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

#ifndef GS2_EXPERIENCE_CONTROL_GETNAMESPACESTATUSRESULT_HPP_
#define GS2_EXPERIENCE_CONTROL_GETNAMESPACESTATUSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ネームスペースを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetNamespaceStatusResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** None */
        optional<StringHolder> status;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            status(data.status)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            status(std::move(data.status))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "status") == 0) {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
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
    GetNamespaceStatusResult() :
        m_pData(nullptr)
    {}

    GetNamespaceStatusResult(const GetNamespaceStatusResult& getNamespaceStatusResult) :
        Gs2Object(getNamespaceStatusResult),
        m_pData(getNamespaceStatusResult.m_pData != nullptr ? new Data(*getNamespaceStatusResult.m_pData) : nullptr)
    {}

    GetNamespaceStatusResult(GetNamespaceStatusResult&& getNamespaceStatusResult) :
        Gs2Object(std::move(getNamespaceStatusResult)),
        m_pData(getNamespaceStatusResult.m_pData)
    {
        getNamespaceStatusResult.m_pData = nullptr;
    }

    ~GetNamespaceStatusResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetNamespaceStatusResult& operator=(const GetNamespaceStatusResult& getNamespaceStatusResult)
    {
        Gs2Object::operator=(getNamespaceStatusResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getNamespaceStatusResult.m_pData);

        return *this;
    }

    GetNamespaceStatusResult& operator=(GetNamespaceStatusResult&& getNamespaceStatusResult)
    {
        Gs2Object::operator=(std::move(getNamespaceStatusResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getNamespaceStatusResult.m_pData;
        getNamespaceStatusResult.m_pData = nullptr;

        return *this;
    }

    const GetNamespaceStatusResult* operator->() const
    {
        return this;
    }

    GetNamespaceStatusResult* operator->()
    {
        return this;
    }
    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * Noneを設定
     *
     * @param status None
     */
    void setStatus(const Char* status)
    {
        ensureData().status.emplace(status);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;

} }

#endif //GS2_EXPERIENCE_CONTROL_GETNAMESPACESTATUSRESULT_HPP_