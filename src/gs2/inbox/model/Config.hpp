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

#ifndef GS2_INBOX_MODEL_CONFIG_HPP_
#define GS2_INBOX_MODEL_CONFIG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace inbox {

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            key(data.key),
            value(data.value)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "key") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->key.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->value.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Config() = default;
    Config(const Config& config) = default;
    Config(Config&& config) = default;
    ~Config() = default;

    Config& operator=(const Config& config) = default;
    Config& operator=(Config&& config) = default;

    Config deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Config);
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
    void setKey(StringHolder key)
    {
        ensureData().key.emplace(std::move(key));
    }

    /**
     * 名前を設定
     *
     * @param key 名前
     */
    Config& withKey(StringHolder key)
    {
        setKey(std::move(key));
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
    void setValue(StringHolder value)
    {
        ensureData().value.emplace(std::move(value));
    }

    /**
     * 値を設定
     *
     * @param value 値
     */
    Config& withValue(StringHolder value)
    {
        setValue(std::move(value));
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
        if (!lhs.m_pData || !lhr.m_pData)
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

#endif //GS2_INBOX_MODEL_CONFIG_HPP_