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

#ifndef GS2_MATCHMAKING_MODEL_ATTRIBUTERANGE_HPP_
#define GS2_MATCHMAKING_MODEL_ATTRIBUTERANGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * ギャザリング参加可能な属性値の範囲
 *
 * @author Game Server Services, Inc.
 *
 */
class AttributeRange : public Gs2Object
{
    friend bool operator!=(const AttributeRange& lhs, const AttributeRange& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 属性名 */
        optional<StringHolder> name;
        /** ギャザリング参加可能な属性値の最小値 */
        optional<Int32> min;
        /** ギャザリング参加可能な属性値の最大値 */
        optional<Int32> max;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            min(data.min),
            max(data.max)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            min(std::move(data.min)),
            max(std::move(data.max))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "min") == 0) {
                if (jsonValue.IsInt())
                {
                    this->min = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "max") == 0) {
                if (jsonValue.IsInt())
                {
                    this->max = jsonValue.GetInt();
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
    AttributeRange() :
        m_pData(nullptr)
    {}

    AttributeRange(const AttributeRange& attributeRange) :
        Gs2Object(attributeRange),
        m_pData(attributeRange.m_pData != nullptr ? new Data(*attributeRange.m_pData) : nullptr)
    {}

    AttributeRange(AttributeRange&& attributeRange) :
        Gs2Object(std::move(attributeRange)),
        m_pData(attributeRange.m_pData)
    {
        attributeRange.m_pData = nullptr;
    }

    ~AttributeRange()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AttributeRange& operator=(const AttributeRange& attributeRange)
    {
        Gs2Object::operator=(attributeRange);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*attributeRange.m_pData);

        return *this;
    }

    AttributeRange& operator=(AttributeRange&& attributeRange)
    {
        Gs2Object::operator=(std::move(attributeRange));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = attributeRange.m_pData;
        attributeRange.m_pData = nullptr;

        return *this;
    }

    const AttributeRange* operator->() const
    {
        return this;
    }

    AttributeRange* operator->()
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
    AttributeRange& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ギャザリング参加可能な属性値の最小値を取得
     *
     * @return ギャザリング参加可能な属性値の最小値
     */
    const optional<Int32>& getMin() const
    {
        return ensureData().min;
    }

    /**
     * ギャザリング参加可能な属性値の最小値を設定
     *
     * @param min ギャザリング参加可能な属性値の最小値
     */
    void setMin(Int32 min)
    {
        ensureData().min.emplace(min);
    }

    /**
     * ギャザリング参加可能な属性値の最小値を設定
     *
     * @param min ギャザリング参加可能な属性値の最小値
     */
    AttributeRange& withMin(Int32 min)
    {
        setMin(min);
        return *this;
    }

    /**
     * ギャザリング参加可能な属性値の最大値を取得
     *
     * @return ギャザリング参加可能な属性値の最大値
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * ギャザリング参加可能な属性値の最大値を設定
     *
     * @param max ギャザリング参加可能な属性値の最大値
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
    }

    /**
     * ギャザリング参加可能な属性値の最大値を設定
     *
     * @param max ギャザリング参加可能な属性値の最大値
     */
    AttributeRange& withMax(Int32 max)
    {
        setMax(max);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const AttributeRange& lhs, const AttributeRange& lhr)
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
        if (lhs.m_pData->min != lhr.m_pData->min)
        {
            return true;
        }
        if (lhs.m_pData->max != lhr.m_pData->max)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const AttributeRange& lhs, const AttributeRange& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_ATTRIBUTERANGE_HPP_