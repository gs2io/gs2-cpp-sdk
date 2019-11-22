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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

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

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Key() = default;
    Key(const Key& key) = default;
    Key(Key&& key) = default;
    ~Key() = default;

    Key& operator=(const Key& key) = default;
    Key& operator=(Key&& key) = default;

    Key deepCopy() const;

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
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 暗号鍵を設定
     *
     * @param keyId 暗号鍵
     */
    Key& withKeyId(StringHolder keyId)
    {
        setKeyId(std::move(keyId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 暗号鍵名を設定
     *
     * @param name 暗号鍵名
     */
    Key& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    Key& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    void setSecret(StringHolder secret)
    {
        ensureData().secret.emplace(std::move(secret));
    }

    /**
     * 暗号鍵を設定
     *
     * @param secret 暗号鍵
     */
    Key& withSecret(StringHolder secret)
    {
        setSecret(std::move(secret));
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

bool operator!=(const Key& lhs, const Key& lhr);

inline bool operator==(const Key& lhs, const Key& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_KEY_MODEL_KEY_HPP_