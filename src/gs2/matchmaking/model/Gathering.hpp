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

#ifndef GS2_MATCHMAKING_MODEL_GATHERING_HPP_
#define GS2_MATCHMAKING_MODEL_GATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AttributeRange.hpp"
#include "CapacityOfRole.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * ギャザリング
 *
 * @author Game Server Services, Inc.
 *
 */
class Gathering : public Gs2Object
{
    friend bool operator!=(const Gathering& lhs, const Gathering& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリング */
        optional<StringHolder> gatheringId;
        /** ギャザリング名 */
        optional<StringHolder> name;
        /** 募集条件 */
        optional<List<AttributeRange>> attributeRanges;
        /** 参加者 */
        optional<List<CapacityOfRole>> capacityOfRoles;
        /** 参加を許可するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
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

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "gatheringId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->gatheringId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "attributeRanges") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->attributeRanges.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AttributeRange item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->attributeRanges, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "capacityOfRoles") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->capacityOfRoles.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        CapacityOfRole item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->capacityOfRoles, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "allowUserIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->allowUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->allowUserIds, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
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
    Gathering() = default;
    Gathering(const Gathering& gathering) = default;
    Gathering(Gathering&& gathering) = default;
    ~Gathering() = default;

    Gathering& operator=(const Gathering& gathering) = default;
    Gathering& operator=(Gathering&& gathering) = default;

    Gathering deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Gathering);
    }

    const Gathering* operator->() const
    {
        return this;
    }

    Gathering* operator->()
    {
        return this;
    }
    /**
     * ギャザリングを取得
     *
     * @return ギャザリング
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングを設定
     *
     * @param gatheringId ギャザリング
     */
    void setGatheringId(StringHolder gatheringId)
    {
        ensureData().gatheringId.emplace(std::move(gatheringId));
    }

    /**
     * ギャザリングを設定
     *
     * @param gatheringId ギャザリング
     */
    Gathering& withGatheringId(StringHolder gatheringId)
    {
        setGatheringId(std::move(gatheringId));
        return *this;
    }

    /**
     * ギャザリング名を取得
     *
     * @return ギャザリング名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    Gathering& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 募集条件を取得
     *
     * @return 募集条件
     */
    const optional<List<AttributeRange>>& getAttributeRanges() const
    {
        return ensureData().attributeRanges;
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    void setAttributeRanges(List<AttributeRange> attributeRanges)
    {
        ensureData().attributeRanges.emplace(std::move(attributeRanges));
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    Gathering& withAttributeRanges(List<AttributeRange> attributeRanges)
    {
        setAttributeRanges(std::move(attributeRanges));
        return *this;
    }

    /**
     * 参加者を取得
     *
     * @return 参加者
     */
    const optional<List<CapacityOfRole>>& getCapacityOfRoles() const
    {
        return ensureData().capacityOfRoles;
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    void setCapacityOfRoles(List<CapacityOfRole> capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(std::move(capacityOfRoles));
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    Gathering& withCapacityOfRoles(List<CapacityOfRole> capacityOfRoles)
    {
        setCapacityOfRoles(std::move(capacityOfRoles));
        return *this;
    }

    /**
     * 参加を許可するユーザIDリストを取得
     *
     * @return 参加を許可するユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    Gathering& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        setAllowUserIds(std::move(allowUserIds));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    Gathering& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    Gathering& withCreatedAt(Int64 createdAt)
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
    Gathering& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Gathering& lhs, const Gathering& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->gatheringId != lhr.m_pData->gatheringId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->attributeRanges != lhr.m_pData->attributeRanges)
        {
            return true;
        }
        if (lhs.m_pData->capacityOfRoles != lhr.m_pData->capacityOfRoles)
        {
            return true;
        }
        if (lhs.m_pData->allowUserIds != lhr.m_pData->allowUserIds)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
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

inline bool operator==(const Gathering& lhs, const Gathering& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_GATHERING_HPP_