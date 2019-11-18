

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

#include <gs2/matchmaking/model/Gathering.hpp>
#include "EzAttributeRange.hpp"
#include "EzCapacityOfRole.hpp"


namespace gs2 { namespace ez { namespace matchmaking {

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
        /** 作成日時 */
        gs2::optional<Int64> createdAt;
        /** 最終更新日時 */
        gs2::optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            gatheringId(data.gatheringId),
            name(data.name),
            metadata(data.metadata),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.attributeRanges)
            {
                attributeRanges = data.attributeRanges->deepCopy();
            }
            if (data.capacityOfRoles)
            {
                capacityOfRoles = data.capacityOfRoles->deepCopy();
            }
            if (data.allowUserIds)
            {
                allowUserIds = data.allowUserIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::Gathering& gathering) :
            gatheringId(gathering.getGatheringId()),
            name(gathering.getName()),
            allowUserIds(gathering.getAllowUserIds()),
            metadata(gathering.getMetadata()),
            createdAt(gathering.getCreatedAt() ? *gathering.getCreatedAt() : 0),
            updatedAt(gathering.getUpdatedAt() ? *gathering.getUpdatedAt() : 0)
        {
            attributeRanges.emplace();
            if (gathering.getAttributeRanges())
            {
                for (int i = 0; i < gathering.getAttributeRanges()->getCount(); ++i)
                {
                    *attributeRanges += EzAttributeRange((*gathering.getAttributeRanges())[i]);
                }
            }
            capacityOfRoles.emplace();
            if (gathering.getCapacityOfRoles())
            {
                for (int i = 0; i < gathering.getCapacityOfRoles()->getCount(); ++i)
                {
                    *capacityOfRoles += EzCapacityOfRole((*gathering.getCapacityOfRoles())[i]);
                }
            }
        }

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

    EzGathering(gs2::matchmaking::Gathering gathering) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(gathering)
    {}

    EzGathering& operator=(const EzGathering& ezGathering) = default;
    EzGathering& operator=(EzGathering&& ezGathering) = default;

    EzGathering deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGathering);
    }

    gs2::matchmaking::Gathering ToModel() const
    {
        gs2::matchmaking::Gathering gathering;
        gathering.setGatheringId(getGatheringId());
        gathering.setName(getName());
        {
            gs2::List<gs2::matchmaking::AttributeRange> list;
            auto& attributeRanges = getAttributeRanges();
            for (int i = 0; i < attributeRanges.getCount(); ++i)
            {
                list += attributeRanges[i].ToModel();
            }
            gathering.setAttributeRanges(list);
        }
        {
            gs2::List<gs2::matchmaking::CapacityOfRole> list;
            auto& capacityOfRoles = getCapacityOfRoles();
            for (int i = 0; i < capacityOfRoles.getCount(); ++i)
            {
                list += capacityOfRoles[i].ToModel();
            }
            gathering.setCapacityOfRoles(list);
        }
        gathering.setAllowUserIds(getAllowUserIds());
        gathering.setMetadata(getMetadata());
        gathering.setCreatedAt(getCreatedAt());
        gathering.setUpdatedAt(getUpdatedAt());
        return gathering;
    }

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