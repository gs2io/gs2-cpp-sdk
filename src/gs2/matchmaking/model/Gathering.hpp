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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AttributeRange.hpp"
#include "CapacityOfRole.hpp"
#include <memory>

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
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Gathering() = default;
    Gathering(const Gathering& gathering) = default;
    Gathering(Gathering&& gathering) = default;
    ~Gathering() = default;

    Gathering& operator=(const Gathering& gathering) = default;
    Gathering& operator=(Gathering&& gathering) = default;

    Gathering deepCopy() const;

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

bool operator!=(const Gathering& lhs, const Gathering& lhr);

inline bool operator==(const Gathering& lhs, const Gathering& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_GATHERING_HPP_