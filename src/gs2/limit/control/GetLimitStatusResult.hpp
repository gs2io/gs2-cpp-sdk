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

#ifndef GS2_LIMIT_CONTROL_GETLIMITSTATUSRESULT_HPP_
#define GS2_LIMIT_CONTROL_GETLIMITSTATUSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * @author Game Server Services, Inc.
 */
class GetLimitStatusResult : public Gs2Object
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
    GetLimitStatusResult() :
        m_pData(nullptr)
    {}

    GetLimitStatusResult(const GetLimitStatusResult& getLimitStatusResult) :
        Gs2Object(getLimitStatusResult),
        m_pData(getLimitStatusResult.m_pData != nullptr ? new Data(*getLimitStatusResult.m_pData) : nullptr)
    {}

    GetLimitStatusResult(GetLimitStatusResult&& getLimitStatusResult) :
        Gs2Object(std::move(getLimitStatusResult)),
        m_pData(getLimitStatusResult.m_pData)
    {
        getLimitStatusResult.m_pData = nullptr;
    }

    ~GetLimitStatusResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetLimitStatusResult& operator=(const GetLimitStatusResult& getLimitStatusResult)
    {
        Gs2Object::operator=(getLimitStatusResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getLimitStatusResult.m_pData);

        return *this;
    }

    GetLimitStatusResult& operator=(GetLimitStatusResult&& getLimitStatusResult)
    {
        Gs2Object::operator=(std::move(getLimitStatusResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getLimitStatusResult.m_pData;
        getLimitStatusResult.m_pData = nullptr;

        return *this;
    }

    const GetLimitStatusResult* operator->() const
    {
        return this;
    }

    GetLimitStatusResult* operator->()
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

#endif //GS2_LIMIT_CONTROL_GETLIMITSTATUSRESULT_HPP_