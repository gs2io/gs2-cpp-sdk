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

#ifndef GS2_DEPLOY_MODEL_OUTPUT_HPP_
#define GS2_DEPLOY_MODEL_OUTPUT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * アウトプット
 *
 * @author Game Server Services, Inc.
 *
 */
class Output : public Gs2Object
{
    friend bool operator!=(const Output& lhs, const Output& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** アウトプット */
        optional<StringHolder> outputId;
        /** アウトプット名 */
        optional<StringHolder> name;
        /** 値 */
        optional<StringHolder> value;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            outputId(data.outputId),
            name(data.name),
            value(data.value),
            createdAt(data.createdAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            outputId(std::move(data.outputId)),
            name(std::move(data.name)),
            value(std::move(data.value)),
            createdAt(std::move(data.createdAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "outputId") == 0) {
                if (jsonValue.IsString())
                {
                    this->outputId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsString())
                {
                    this->value.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
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
    Output() :
        m_pData(nullptr)
    {}

    Output(const Output& output) :
        Gs2Object(output),
        m_pData(output.m_pData != nullptr ? new Data(*output.m_pData) : nullptr)
    {}

    Output(Output&& output) :
        Gs2Object(std::move(output)),
        m_pData(output.m_pData)
    {
        output.m_pData = nullptr;
    }

    ~Output()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Output& operator=(const Output& output)
    {
        Gs2Object::operator=(output);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*output.m_pData);

        return *this;
    }

    Output& operator=(Output&& output)
    {
        Gs2Object::operator=(std::move(output));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = output.m_pData;
        output.m_pData = nullptr;

        return *this;
    }

    const Output* operator->() const
    {
        return this;
    }

    Output* operator->()
    {
        return this;
    }
    /**
     * アウトプットを取得
     *
     * @return アウトプット
     */
    const optional<StringHolder>& getOutputId() const
    {
        return ensureData().outputId;
    }

    /**
     * アウトプットを設定
     *
     * @param outputId アウトプット
     */
    void setOutputId(const Char* outputId)
    {
        ensureData().outputId.emplace(outputId);
    }

    /**
     * アウトプットを設定
     *
     * @param outputId アウトプット
     */
    Output& withOutputId(const Char* outputId)
    {
        setOutputId(outputId);
        return *this;
    }

    /**
     * アウトプット名を取得
     *
     * @return アウトプット名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * アウトプット名を設定
     *
     * @param name アウトプット名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * アウトプット名を設定
     *
     * @param name アウトプット名
     */
    Output& withName(const Char* name)
    {
        setName(name);
        return *this;
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
     * 値を設定
     *
     * @param value 値
     */
    Output& withValue(const Char* value)
    {
        setValue(value);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Output& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Output& lhs, const Output& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->outputId != lhr.m_pData->outputId)
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
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Output& lhs, const Output& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_OUTPUT_HPP_