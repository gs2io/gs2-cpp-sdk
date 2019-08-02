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

#ifndef GS2_KEY_MODEL_KEY_HPP_
#define GS2_KEY_MODEL_KEY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace key {

/**
 * 暗号鍵
 *
 * @author Game Server Services, Inc.
 *
 */
class Key : public Gs2Object
{
    friend bool operator!=(const Key& lhs, const Key& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 暗号鍵 */
        optional<StringHolder> keyId;
        /** 暗号鍵名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 暗号鍵 */
        optional<StringHolder> secret;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            keyId(data.keyId),
            name(data.name),
            description(data.description),
            secret(data.secret),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            keyId(std::move(data.keyId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            secret(std::move(data.secret)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "keyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->keyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "secret") == 0) {
                if (jsonValue.IsString())
                {
                    this->secret.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Key() :
        m_pData(nullptr)
    {}

    Key(const Key& key) :
        Gs2Object(key),
        m_pData(key.m_pData != nullptr ? new Data(*key.m_pData) : nullptr)
    {}

    Key(Key&& key) :
        Gs2Object(std::move(key)),
        m_pData(key.m_pData)
    {
        key.m_pData = nullptr;
    }

    ~Key()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Key& operator=(const Key& key)
    {
        Gs2Object::operator=(key);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*key.m_pData);

        return *this;
    }

    Key& operator=(Key&& key)
    {
        Gs2Object::operator=(std::move(key));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = key.m_pData;
        key.m_pData = nullptr;

        return *this;
    }

    const Key* operator->() const
    {
        return this;
    }

    Key* operator->()
    {
        return this;
    }
    /**
     * 暗号鍵を取得
     *
     * @return 暗号鍵
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 暗号鍵を設定
     *
     * @param keyId 暗号鍵
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 暗号鍵を設定
     *
     * @param keyId 暗号鍵
     */
    Key& withKeyId(const Char* keyId)
    {
        setKeyId(keyId);
        return *this;
    }

    /**
     * 暗号鍵名を取得
     *
     * @return 暗号鍵名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 暗号鍵名を設定
     *
     * @param name 暗号鍵名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 暗号鍵名を設定
     *
     * @param name 暗号鍵名
     */
    Key& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    Key& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 暗号鍵を取得
     *
     * @return 暗号鍵
     */
    const optional<StringHolder>& getSecret() const
    {
        return ensureData().secret;
    }

    /**
     * 暗号鍵を設定
     *
     * @param secret 暗号鍵
     */
    void setSecret(const Char* secret)
    {
        ensureData().secret.emplace(secret);
    }

    /**
     * 暗号鍵を設定
     *
     * @param secret 暗号鍵
     */
    Key& withSecret(const Char* secret)
    {
        setSecret(secret);
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
    Key& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Key& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Key& lhs, const Key& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->keyId != lhr.m_pData->keyId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->secret != lhr.m_pData->secret)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Key& lhs, const Key& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_KEY_MODEL_KEY_HPP_