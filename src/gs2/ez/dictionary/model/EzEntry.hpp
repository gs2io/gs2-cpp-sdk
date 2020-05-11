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

#ifndef GS2_EZ_DICTIONARY_MODEL_EZENTRY_HPP_
#define GS2_EZ_DICTIONARY_MODEL_EZENTRY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace dictionary {

class Entry;

}

namespace ez { namespace dictionary {

class EzEntry : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** エントリー のGRN */
        gs2::optional<StringHolder> entryId;
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** エントリーの種類名 */
        gs2::optional<StringHolder> name;
        /** None */
        gs2::optional<Int64> acquiredAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::dictionary::Entry& entry);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzEntry() = default;
    EzEntry(const EzEntry& ezEntry) = default;
    EzEntry(EzEntry&& ezEntry) = default;
    ~EzEntry() = default;

    EzEntry(gs2::dictionary::Entry entry);

    EzEntry& operator=(const EzEntry& ezEntry) = default;
    EzEntry& operator=(EzEntry&& ezEntry) = default;

    EzEntry deepCopy() const;

    gs2::dictionary::Entry ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getEntryId() const
    {
        return *ensureData().entryId;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int64 getAcquiredAt() const
    {
        return *ensureData().acquiredAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setEntryId(StringHolder entryId)
    {
        ensureData().entryId = std::move(entryId);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setAcquiredAt(Int64 acquiredAt)
    {
        ensureData().acquiredAt = acquiredAt;
    }

    EzEntry& withEntryId(StringHolder entryId)
    {
        setEntryId(std::move(entryId));
        return *this;
    }

    EzEntry& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzEntry& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzEntry& withAcquiredAt(Int64 acquiredAt)
    {
        setAcquiredAt(acquiredAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_DICTIONARY_EZENTRY_HPP_