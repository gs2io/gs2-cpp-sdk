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

#ifndef GS2_QUEST_MODEL_CONFIG_HPP_
#define GS2_QUEST_MODEL_CONFIG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * 設定値
 *
 * @author Game Server Services, Inc.
 *
 */
class Config : public Gs2Object
{
    friend bool operator!=(const Config& lhs, const Config& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 名前 */
        optional<StringHolder> key;
        /** 値 */
        optional<StringHolder> value;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            key(data.key),
            value(data.value)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            key(std::move(data.key)),
            value(std::move(data.value))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "key") == 0) {
                if (jsonValue.IsString())
                {
                    this->key.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0) {
                if (jsonValue.IsString())
                {
                    this->value.emplace(jsonValue.GetString());
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
    Config() :
        m_pData(nullptr)
    {}

    Config(const Config& config) :
        Gs2Object(config),
        m_pData(config.m_pData != nullptr ? new Data(*config.m_pData) : nullptr)
    {}

    Config(Config&& config) :
        Gs2Object(std::move(config)),
        m_pData(config.m_pData)
    {
        config.m_pData = nullptr;
    }

    ~Config()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Config& operator=(const Config& config)
    {
        Gs2Object::operator=(config);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*config.m_pData);

        return *this;
    }

    Config& operator=(Config&& config)
    {
        Gs2Object::operator=(std::move(config));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = config.m_pData;
        config.m_pData = nullptr;

        return *this;
    }

    const Config* operator->() const
    {
        return this;
    }

    Config* operator->()
    {
        return this;
    }
    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getKey() const
    {
        return ensureData().key;
    }

    /**
     * 名前を設定
     *
     * @param key 名前
     */
    void setKey(const Char* key)
    {
        ensureData().key.emplace(key);
    }

    /**
     * 名前を設定
     *
     * @param key 名前
     */
    Config& withKey(const Char* key)
    {
        setKey(key);
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
    Config& withValue(const Char* value)
    {
        setValue(value);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Config& lhs, const Config& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->key != lhr.m_pData->key)
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

inline bool operator==(const Config& lhs, const Config& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_CONFIG_HPP_