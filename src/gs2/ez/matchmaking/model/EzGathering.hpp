

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
    /** ギャザリング */
    gs2::optional<StringHolder> m_GatheringId;
    /** ギャザリング名 */
    gs2::optional<StringHolder> m_Name;
    /** 募集条件 */
    gs2::optional<List<EzAttributeRange>> m_AttributeRanges;
    /** 参加者 */
    gs2::optional<List<EzCapacityOfRole>> m_CapacityOfRoles;
    /** 参加を許可するユーザIDリスト */
    gs2::optional<List<StringHolder>> m_AllowUserIds;
    /** メタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 作成日時 */
    gs2::optional<Int64> m_CreatedAt;
    /** 最終更新日時 */
    gs2::optional<Int64> m_UpdatedAt;

public:
    EzGathering() = default;

    EzGathering(gs2::matchmaking::Gathering gathering) :
        m_GatheringId(gathering.getGatheringId()),
        m_Name(gathering.getName()),
        m_AllowUserIds(gathering.getAllowUserIds()),
        m_Metadata(gathering.getMetadata()),
        m_CreatedAt(gathering.getCreatedAt() ? *gathering.getCreatedAt() : 0),
        m_UpdatedAt(gathering.getUpdatedAt() ? *gathering.getUpdatedAt() : 0)
    {
        m_AttributeRanges.emplace();
        if (gathering.getAttributeRanges())
        {
            for (int i = 0; i < gathering.getAttributeRanges()->getCount(); ++i)
            {
                *m_AttributeRanges += EzAttributeRange((*gathering.getAttributeRanges())[i]);
            }
        }
        m_CapacityOfRoles.emplace();
        if (gathering.getCapacityOfRoles())
        {
            for (int i = 0; i < gathering.getCapacityOfRoles()->getCount(); ++i)
            {
                *m_CapacityOfRoles += EzCapacityOfRole((*gathering.getCapacityOfRoles())[i]);
            }
        }
    }

    gs2::matchmaking::Gathering ToModel() const
    {
        gs2::matchmaking::Gathering gathering;
        gathering.setGatheringId(*m_GatheringId);
        gathering.setName(*m_Name);
        {
            gs2::List<gs2::matchmaking::AttributeRange> list;
            auto& attributeRanges = *m_AttributeRanges;
            for (int i = 0; i < attributeRanges.getCount(); ++i)
            {
                list += attributeRanges[i].ToModel();
            }
            gathering.setAttributeRanges(list);
        }
        {
            gs2::List<gs2::matchmaking::CapacityOfRole> list;
            auto& capacityOfRoles = *m_CapacityOfRoles;
            for (int i = 0; i < capacityOfRoles.getCount(); ++i)
            {
                list += capacityOfRoles[i].ToModel();
            }
            gathering.setCapacityOfRoles(list);
        }
        gathering.setAllowUserIds(*m_AllowUserIds);
        gathering.setMetadata(*m_Metadata);
        gathering.setCreatedAt(*m_CreatedAt);
        gathering.setUpdatedAt(*m_UpdatedAt);
        return gathering;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getGatheringId() const
    {
        return *m_GatheringId;
    }

    gs2::StringHolder& getGatheringId()
    {
        return *m_GatheringId;
    }

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const List<EzAttributeRange>& getAttributeRanges() const
    {
        return *m_AttributeRanges;
    }

    List<EzAttributeRange>& getAttributeRanges()
    {
        return *m_AttributeRanges;
    }

    const List<EzCapacityOfRole>& getCapacityOfRoles() const
    {
        return *m_CapacityOfRoles;
    }

    List<EzCapacityOfRole>& getCapacityOfRoles()
    {
        return *m_CapacityOfRoles;
    }

    const List<StringHolder>& getAllowUserIds() const
    {
        return *m_AllowUserIds;
    }

    List<StringHolder>& getAllowUserIds()
    {
        return *m_AllowUserIds;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    Int64 getCreatedAt() const
    {
        return *m_CreatedAt;
    }

    Int64 getUpdatedAt() const
    {
        return *m_UpdatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setGatheringId(Char* gatheringId)
    {
        m_GatheringId.emplace(gatheringId);
    }

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setAttributeRanges(const List<EzAttributeRange>& attributeRanges)
    {
        m_AttributeRanges = attributeRanges;
    }

    void setAttributeRanges(List<EzAttributeRange>&& attributeRanges)
    {
        m_AttributeRanges = std::move(attributeRanges);
    }

    void setCapacityOfRoles(const List<EzCapacityOfRole>& capacityOfRoles)
    {
        m_CapacityOfRoles = capacityOfRoles;
    }

    void setCapacityOfRoles(List<EzCapacityOfRole>&& capacityOfRoles)
    {
        m_CapacityOfRoles = std::move(capacityOfRoles);
    }

    void setAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        m_AllowUserIds = allowUserIds;
    }

    void setAllowUserIds(List<StringHolder>&& allowUserIds)
    {
        m_AllowUserIds = std::move(allowUserIds);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setCreatedAt(Int64 createdAt)
    {
        m_CreatedAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        m_UpdatedAt = updatedAt;
    }

    EzGathering& withGatheringId(Char* gatheringId)
    {
        setGatheringId(gatheringId);
        return *this;
    }

    EzGathering& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzGathering& withAttributeRanges(const List<EzAttributeRange>& attributeRanges)
    {
        setAttributeRanges(attributeRanges);
        return *this;
    }

    EzGathering& withAttributeRanges(List<EzAttributeRange>&& attributeRanges)
    {
        setAttributeRanges(std::move(attributeRanges));
        return *this;
    }

    EzGathering& withCapacityOfRoles(const List<EzCapacityOfRole>& capacityOfRoles)
    {
        setCapacityOfRoles(capacityOfRoles);
        return *this;
    }

    EzGathering& withCapacityOfRoles(List<EzCapacityOfRole>&& capacityOfRoles)
    {
        setCapacityOfRoles(std::move(capacityOfRoles));
        return *this;
    }

    EzGathering& withAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        setAllowUserIds(allowUserIds);
        return *this;
    }

    EzGathering& withAllowUserIds(List<StringHolder>&& allowUserIds)
    {
        setAllowUserIds(std::move(allowUserIds));
        return *this;
    }

    EzGathering& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
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