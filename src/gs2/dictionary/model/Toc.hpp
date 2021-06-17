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

#ifndef GS2_DICTIONARY_MODEL_TOC_HPP_
#define GS2_DICTIONARY_MODEL_TOC_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Entry.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace dictionary {

/**
 * 見出し
 *
 * @author Game Server Services, Inc.
 *
 */
class Toc : public Gs2Object
{
    friend bool operator!=(const Toc& lhs, const Toc& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 見出し */
        optional<StringHolder> tocId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** インデックス */
        optional<Int32> index;
        /** エントリーのリスト */
        optional<List<Entry>> entries;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            tocId(data.tocId),
            userId(data.userId),
            index(data.index),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.entries)
            {
                entries = data.entries->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "tocId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->tocId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "index") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->index = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "entries") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->entries.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Entry item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->entries += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Toc() = default;
    Toc(const Toc& toc) = default;
    Toc(Toc&& toc) = default;
    ~Toc() = default;

    Toc& operator=(const Toc& toc) = default;
    Toc& operator=(Toc&& toc) = default;

    Toc deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Toc);
    }

    const Toc* operator->() const
    {
        return this;
    }

    Toc* operator->()
    {
        return this;
    }
    /**
     * 見出しを取得
     *
     * @return 見出し
     */
    const optional<StringHolder>& getTocId() const
    {
        return ensureData().tocId;
    }

    /**
     * 見出しを設定
     *
     * @param tocId 見出し
     */
    void setTocId(StringHolder tocId)
    {
        ensureData().tocId.emplace(std::move(tocId));
    }

    /**
     * 見出しを設定
     *
     * @param tocId 見出し
     */
    Toc& withTocId(StringHolder tocId)
    {
        setTocId(std::move(tocId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Toc& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * インデックスを取得
     *
     * @return インデックス
     */
    const optional<Int32>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * インデックスを設定
     *
     * @param index インデックス
     */
    void setIndex(Int32 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * インデックスを設定
     *
     * @param index インデックス
     */
    Toc& withIndex(Int32 index)
    {
        setIndex(index);
        return *this;
    }

    /**
     * エントリーのリストを取得
     *
     * @return エントリーのリスト
     */
    const optional<List<Entry>>& getEntries() const
    {
        return ensureData().entries;
    }

    /**
     * エントリーのリストを設定
     *
     * @param entries エントリーのリスト
     */
    void setEntries(List<Entry> entries)
    {
        ensureData().entries.emplace(std::move(entries));
    }

    /**
     * エントリーのリストを設定
     *
     * @param entries エントリーのリスト
     */
    Toc& withEntries(List<Entry> entries)
    {
        setEntries(std::move(entries));
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
    Toc& withCreatedAt(Int64 createdAt)
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
    Toc& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Toc& lhs, const Toc& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->tocId != lhr.m_pData->tocId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->index != lhr.m_pData->index)
        {
            return true;
        }
        if (lhs.m_pData->entries != lhr.m_pData->entries)
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

inline bool operator==(const Toc& lhs, const Toc& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DICTIONARY_MODEL_TOC_HPP_