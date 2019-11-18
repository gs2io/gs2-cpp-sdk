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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            value(data.value)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Attribute() = default;
    Attribute(const Attribute& attribute) = default;
    Attribute(Attribute&& attribute) = default;
    ~Attribute() = default;

    Attribute& operator=(const Attribute& attribute) = default;
    Attribute& operator=(Attribute&& attribute) = default;

    Attribute deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Attribute);
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 属性名を設定
     *
     * @param name 属性名
     */
    Attribute& withName(StringHolder name)
    {
        setName(std::move(name));
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

inline bool operator!=(const Attribute& lhs, const Attribute& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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

inline bool operator==(const Attribute& lhs, const Attribute& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_ATTRIBUTE_HPP_