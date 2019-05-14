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

namespace gs2 { namespace  {

/**
 * 暗号鍵
 *
 * @author Game Server Services, Inc.
 *
 */
class Key : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 暗号鍵名 */
        optional<StringHolder> name;
        /** 作成日時 */
        
        optional<Int64> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            keyId(data.keyId),
            ownerId(data.ownerId),
            name(data.name),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            keyId(std::move(data.keyId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            createAt(std::move(data.createAt))
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
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
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
     * 暗号鍵 のGRNを取得
     *
     * @return 暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 暗号鍵 のGRNを設定
     *
     * @param keyId 暗号鍵 のGRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
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
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_KEY_MODEL_KEY_HPP_