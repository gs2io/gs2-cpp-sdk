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

#ifndef GS2_MATCHMAKING_MODEL_ATTRIBUTE_HPP_
#define GS2_MATCHMAKING_MODEL_ATTRIBUTE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * プレイヤーの属性値
 *
 * @author Game Server Services, Inc.
 *
 */
class Attribute : public Gs2Object
{
    friend bool operator!=(const Attribute& lhs, const Attribute& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 属性名 */
        optional<StringHolder> name;
        /** 属性値 */
        optional<Int32> value;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            value(data.value)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            value(std::move(data.value))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
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
    Attribute() :
        m_pData(nullptr)
    {}

    Attribute(const Attribute& attribute) :
        Gs2Object(attribute),
        m_pData(attribute.m_pData != nullptr ? new Data(*attribute.m_pData) : nullptr)
    {}

    Attribute(Attribute&& attribute) :
        Gs2Object(std::move(attribute)),
        m_pData(attribute.m_pData)
    {
        attribute.m_pData = nullptr;
    }

    ~Attribute()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Attribute& operator=(const Attribute& attribute)
    {
        Gs2Object::operator=(attribute);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*attribute.m_pData);

        return *this;
    }

    Attribute& operator=(Attribute&& attribute)
    {
        Gs2Object::operator=(std::move(attribute));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = attribute.m_pData;
        attribute.m_pData = nullptr;

        return *this;
    }

    const Attribute* operator->() const
    {
        return this;
    }

    Attribute* operator->()
    {
        return this;
    }
    /**
     * 属性名を取得
     *
     * @return 属性名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 属性名を設定
     *
     * @param name 属性名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 属性名を設定
     *
     * @param name 属性名
     */
    Attribute& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 属性値を取得
     *
     * @return 属性値
     */
    const optional<Int32>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 属性値を設定
     *
     * @param value 属性値
     */
    void setValue(Int32 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 属性値を設定
     *
     * @param value 属性値
     */
    Attribute& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Attribute& lhs, const Attribute& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Attribute& lhs, const Attribute& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_ATTRIBUTE_HPP_