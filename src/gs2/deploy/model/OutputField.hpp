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

#ifndef GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_
#define GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * Output に記録するフィールド
 *
 * @author Game Server Services, Inc.
 *
 */
class OutputField : public Gs2Object
{
    friend bool operator!=(const OutputField& lhs, const OutputField& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 名前 */
        optional<StringHolder> name;
        /** フィールド名 */
        optional<StringHolder> fieldName;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            fieldName(data.fieldName)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            fieldName(std::move(data.fieldName))
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
            else if (std::strcmp(name_, "fieldName") == 0) {
                if (jsonValue.IsString())
                {
                    this->fieldName.emplace(jsonValue.GetString());
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
    OutputField() :
        m_pData(nullptr)
    {}

    OutputField(const OutputField& outputField) :
        Gs2Object(outputField),
        m_pData(outputField.m_pData != nullptr ? new Data(*outputField.m_pData) : nullptr)
    {}

    OutputField(OutputField&& outputField) :
        Gs2Object(std::move(outputField)),
        m_pData(outputField.m_pData)
    {
        outputField.m_pData = nullptr;
    }

    ~OutputField()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    OutputField& operator=(const OutputField& outputField)
    {
        Gs2Object::operator=(outputField);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*outputField.m_pData);

        return *this;
    }

    OutputField& operator=(OutputField&& outputField)
    {
        Gs2Object::operator=(std::move(outputField));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = outputField.m_pData;
        outputField.m_pData = nullptr;

        return *this;
    }

    const OutputField* operator->() const
    {
        return this;
    }

    OutputField* operator->()
    {
        return this;
    }
    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    OutputField& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * フィールド名を取得
     *
     * @return フィールド名
     */
    const optional<StringHolder>& getFieldName() const
    {
        return ensureData().fieldName;
    }

    /**
     * フィールド名を設定
     *
     * @param fieldName フィールド名
     */
    void setFieldName(const Char* fieldName)
    {
        ensureData().fieldName.emplace(fieldName);
    }

    /**
     * フィールド名を設定
     *
     * @param fieldName フィールド名
     */
    OutputField& withFieldName(const Char* fieldName)
    {
        setFieldName(fieldName);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const OutputField& lhs, const OutputField& lhr)
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
        if (lhs.m_pData->fieldName != lhr.m_pData->fieldName)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const OutputField& lhs, const OutputField& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_