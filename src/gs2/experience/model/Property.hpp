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

#ifndef GS2_EXPERIENCE_MODEL_PROPERTY_HPP_
#define GS2_EXPERIENCE_MODEL_PROPERTY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * プロパティ
 *
 * @author Game Server Services, Inc.
 *
 */
class Property : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;
        /** プロパティID */
        optional<StringHolder> propertyId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            experienceModelName(data.experienceModelName),
            propertyId(data.propertyId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            experienceModelName(std::move(data.experienceModelName)),
            propertyId(std::move(data.propertyId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "experienceModelName") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "propertyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
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
    Property() :
        m_pData(nullptr)
    {}

    Property(const Property& property) :
        Gs2Object(property),
        m_pData(property.m_pData != nullptr ? new Data(*property.m_pData) : nullptr)
    {}

    Property(Property&& property) :
        Gs2Object(std::move(property)),
        m_pData(property.m_pData)
    {
        property.m_pData = nullptr;
    }

    ~Property()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Property& operator=(const Property& property)
    {
        Gs2Object::operator=(property);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*property.m_pData);

        return *this;
    }

    Property& operator=(Property&& property)
    {
        Gs2Object::operator=(std::move(property));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = property.m_pData;
        property.m_pData = nullptr;

        return *this;
    }

    const Property* operator->() const
    {
        return this;
    }

    Property* operator->()
    {
        return this;
    }
    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_EXPERIENCE_MODEL_PROPERTY_HPP_