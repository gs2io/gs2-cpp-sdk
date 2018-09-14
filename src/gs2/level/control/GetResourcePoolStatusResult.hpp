/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LEVEL_CONTROL_GETRESOURCEPOOLSTATUSRESULT_HPP_
#define GS2_LEVEL_CONTROL_GETRESOURCEPOOLSTATUSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class GetResourcePoolStatusResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータス */
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

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "status") == 0) {
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
    GetResourcePoolStatusResult() :
        m_pData(nullptr)
    {}

    GetResourcePoolStatusResult(const GetResourcePoolStatusResult& getResourcePoolStatusResult) :
        Gs2Object(getResourcePoolStatusResult),
        m_pData(getResourcePoolStatusResult.m_pData != nullptr ? new Data(*getResourcePoolStatusResult.m_pData) : nullptr)
    {}

    GetResourcePoolStatusResult(GetResourcePoolStatusResult&& getResourcePoolStatusResult) :
        Gs2Object(std::move(getResourcePoolStatusResult)),
        m_pData(getResourcePoolStatusResult.m_pData)
    {
        getResourcePoolStatusResult.m_pData = nullptr;
    }

    ~GetResourcePoolStatusResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetResourcePoolStatusResult& operator=(const GetResourcePoolStatusResult& getResourcePoolStatusResult)
    {
        Gs2Object::operator=(getResourcePoolStatusResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getResourcePoolStatusResult.m_pData);

        return *this;
    }

    GetResourcePoolStatusResult& operator=(GetResourcePoolStatusResult&& getResourcePoolStatusResult)
    {
        Gs2Object::operator=(std::move(getResourcePoolStatusResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getResourcePoolStatusResult.m_pData;
        getResourcePoolStatusResult.m_pData = nullptr;

        return *this;
    }

    const GetResourcePoolStatusResult* operator->() const
    {
        return this;
    }

    GetResourcePoolStatusResult* operator->()
    {
        return this;
    }


    /**
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * ステータスを設定
     *
     * @param status ステータス
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

} }

#endif //GS2_LEVEL_CONTROL_GETRESOURCEPOOLSTATUSRESULT_HPP_