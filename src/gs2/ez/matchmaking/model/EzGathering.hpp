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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZGATHERING_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZGATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzAttributeRange.hpp"
#include "EzCapacityOfRole.hpp"
#include <memory>


namespace gs2 {

namespace matchmaking {

class Gathering;

}

namespace ez { namespace matchmaking {

class EzGathering : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ギャザリング */
        gs2::optional<StringHolder> gatheringId;
        /** ギャザリング名 */
        gs2::optional<StringHolder> name;
        /** 募集条件 */
        gs2::optional<List<EzAttributeRange>> attributeRanges;
        /** 参加者 */
        gs2::optional<List<EzCapacityOfRole>> capacityOfRoles;
        /** 参加を許可するユーザIDリスト */
        gs2::optional<List<StringHolder>> allowUserIds;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** ギャザリングの有効期限 */
        gs2::optional<Int64> expiresAt;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;
        /** 最終更新日時 */
        gs2::optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::Gathering& gathering);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGathering() = default;
    EzGathering(const EzGathering& ezGathering) = default;
    EzGathering(EzGathering&& ezGathering) = default;
    ~EzGathering() = default;

    EzGathering(gs2::matchmaking::Gathering gathering);

    EzGathering& operator=(const EzGathering& ezGathering) = default;
    EzGathering& operator=(EzGathering&& ezGathering) = default;

    EzGathering deepCopy() const;

    gs2::matchmaking::Gathering ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getGatheringId() const
    {
        return *ensureData().gatheringId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const List<EzAttributeRange>& getAttributeRanges() const
    {
        return *ensureData().attributeRanges;
    }

    const List<EzCapacityOfRole>& getCapacityOfRoles() const
    {
        return *ensureData().capacityOfRoles;
    }

    const List<StringHolder>& getAllowUserIds() const
    {
        return *ensureData().allowUserIds;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Int64 getExpiresAt() const
    {
        return *ensureData().expiresAt;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    Int64 getUpdatedAt() const
    {
        return *ensureData().updatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setGatheringId(StringHolder gatheringId)
    {
        ensureData().gatheringId = std::move(gatheringId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setAttributeRanges(List<EzAttributeRange> attributeRanges)
    {
        ensureData().attributeRanges = std::move(attributeRanges);
    }

    void setCapacityOfRoles(List<EzCapacityOfRole> capacityOfRoles)
    {
        ensureData().capacityOfRoles = std::move(capacityOfRoles);
    }

    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds = std::move(allowUserIds);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt = expiresAt;
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt = updatedAt;
    }

    EzGathering& withGatheringId(StringHolder gatheringId)
    {
        setGatheringId(std::move(gatheringId));
        return *this;
    }

    EzGathering& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzGathering& withAttributeRanges(List<EzAttributeRange> attributeRanges)
    {
        setAttributeRanges(std::move(attributeRanges));
        return *this;
    }

    EzGathering& withCapacityOfRoles(List<EzCapacityOfRole> capacityOfRoles)
    {
        setCapacityOfRoles(std::move(capacityOfRoles));
        return *this;
    }

    EzGathering& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        setAllowUserIds(std::move(allowUserIds));
        return *this;
    }

    EzGathering& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzGathering& withExpiresAt(Int64 expiresAt)
    {
        setExpiresAt(expiresAt);
        return *this;
    }

    EzGathering& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzGathering& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZGATHERING_HPP_