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

#ifndef GS2_DICTIONARY_MODEL_ENTRY_HPP_
#define GS2_DICTIONARY_MODEL_ENTRY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace dictionary {

/**
 * エントリー
 *
 * @author Game Server Services, Inc.
 *
 */
class Entry : public Gs2Object
{
    friend bool operator!=(const Entry& lhs, const Entry& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** エントリー のGRN */
        optional<StringHolder> entryId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** エントリーの種類名 */
        optional<StringHolder> name;
        /** None */
        optional<Int64> acquiredAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            entryId(data.entryId),
            userId(data.userId),
            name(data.name),
            acquiredAt(data.acquiredAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "entryId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->entryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquiredAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->acquiredAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Entry() = default;
    Entry(const Entry& entry) = default;
    Entry(Entry&& entry) = default;
    ~Entry() = default;

    Entry& operator=(const Entry& entry) = default;
    Entry& operator=(Entry&& entry) = default;

    Entry deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Entry);
    }

    const Entry* operator->() const
    {
        return this;
    }

    Entry* operator->()
    {
        return this;
    }
    /**
     * エントリー のGRNを取得
     *
     * @return エントリー のGRN
     */
    const optional<StringHolder>& getEntryId() const
    {
        return ensureData().entryId;
    }

    /**
     * エントリー のGRNを設定
     *
     * @param entryId エントリー のGRN
     */
    void setEntryId(StringHolder entryId)
    {
        ensureData().entryId.emplace(std::move(entryId));
    }

    /**
     * エントリー のGRNを設定
     *
     * @param entryId エントリー のGRN
     */
    Entry& withEntryId(StringHolder entryId)
    {
        setEntryId(std::move(entryId));
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
    Entry& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * エントリーの種類名を取得
     *
     * @return エントリーの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * エントリーの種類名を設定
     *
     * @param name エントリーの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * エントリーの種類名を設定
     *
     * @param name エントリーの種類名
     */
    Entry& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int64>& getAcquiredAt() const
    {
        return ensureData().acquiredAt;
    }

    /**
     * Noneを設定
     *
     * @param acquiredAt None
     */
    void setAcquiredAt(Int64 acquiredAt)
    {
        ensureData().acquiredAt.emplace(acquiredAt);
    }

    /**
     * Noneを設定
     *
     * @param acquiredAt None
     */
    Entry& withAcquiredAt(Int64 acquiredAt)
    {
        setAcquiredAt(acquiredAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Entry& lhs, const Entry& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->entryId != lhr.m_pData->entryId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->acquiredAt != lhr.m_pData->acquiredAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Entry& lhs, const Entry& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DICTIONARY_MODEL_ENTRY_HPP_