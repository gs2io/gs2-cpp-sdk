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

#ifndef GS2_VARIABLE_CONTROL_GETVARIABLERESULT_HPP_
#define GS2_VARIABLE_CONTROL_GETVARIABLERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace variable
{

/**
 * @author Game Server Services, Inc.
 */
class GetVariableResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 値 */
        optional<StringHolder> value;
        /** 有効期限(エポック秒) */
        optional<Int32> expire;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            value(data.value),
            expire(data.expire)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            value(std::move(data.value)),
            expire(std::move(data.expire))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsString())
                {
                    this->value.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "expire") == 0) {
                if (jsonValue.IsInt())
                {
                    this->expire = jsonValue.GetInt();
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
    GetVariableResult() :
        m_pData(nullptr)
    {}

    GetVariableResult(const GetVariableResult& getVariableResult) :
        Gs2Object(getVariableResult),
        m_pData(getVariableResult.m_pData != nullptr ? new Data(*getVariableResult.m_pData) : nullptr)
    {}

    GetVariableResult(GetVariableResult&& getVariableResult) :
        Gs2Object(std::move(getVariableResult)),
        m_pData(getVariableResult.m_pData)
    {
        getVariableResult.m_pData = nullptr;
    }

    ~GetVariableResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetVariableResult& operator=(const GetVariableResult& getVariableResult)
    {
        Gs2Object::operator=(getVariableResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getVariableResult.m_pData);

        return *this;
    }

    GetVariableResult& operator=(GetVariableResult&& getVariableResult)
    {
        Gs2Object::operator=(std::move(getVariableResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getVariableResult.m_pData;
        getVariableResult.m_pData = nullptr;

        return *this;
    }

    const GetVariableResult* operator->() const
    {
        return this;
    }

    GetVariableResult* operator->()
    {
        return this;
    }


    /**
     * 値を取得
     *
     * @return 値
     */
    const optional<StringHolder>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 値を設定
     *
     * @param value 値
     */
    void setValue(const Char* value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 有効期限(エポック秒)を取得
     *
     * @return 有効期限(エポック秒)
     */
    const optional<Int32>& getExpire() const
    {
        return ensureData().expire;
    }

    /**
     * 有効期限(エポック秒)を設定
     *
     * @param expire 有効期限(エポック秒)
     */
    void setExpire(Int32 expire)
    {
        ensureData().expire.emplace(expire);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_VARIABLE_CONTROL_GETVARIABLERESULT_HPP_