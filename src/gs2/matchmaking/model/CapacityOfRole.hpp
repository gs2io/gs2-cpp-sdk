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

#ifndef GS2_MATCHMAKING_MODEL_CAPACITYOFROLE_HPP_
#define GS2_MATCHMAKING_MODEL_CAPACITYOFROLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Player.hpp"
#include <memory>

namespace gs2 { namespace matchmaking {

/**
 * ロールごとのキャパシティ
 *
 * @author Game Server Services, Inc.
 *
 */
class CapacityOfRole : public Gs2Object
{
    friend bool operator!=(const CapacityOfRole& lhs, const CapacityOfRole& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ロール名 */
        optional<StringHolder> roleName;
        /** ロール名の別名リスト */
        optional<List<StringHolder>> roleAliases;
        /** 募集人数 */
        optional<Int32> capacity;
        /** 参加者のプレイヤー情報リスト */
        optional<List<Player>> participants;

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
    CapacityOfRole() = default;
    CapacityOfRole(const CapacityOfRole& capacityOfRole) = default;
    CapacityOfRole(CapacityOfRole&& capacityOfRole) = default;
    ~CapacityOfRole() = default;

    CapacityOfRole& operator=(const CapacityOfRole& capacityOfRole) = default;
    CapacityOfRole& operator=(CapacityOfRole&& capacityOfRole) = default;

    CapacityOfRole deepCopy() const;

    const CapacityOfRole* operator->() const
    {
        return this;
    }

    CapacityOfRole* operator->()
    {
        return this;
    }
    /**
     * ロール名を取得
     *
     * @return ロール名
     */
    const optional<StringHolder>& getRoleName() const
    {
        return ensureData().roleName;
    }

    /**
     * ロール名を設定
     *
     * @param roleName ロール名
     */
    void setRoleName(StringHolder roleName)
    {
        ensureData().roleName.emplace(std::move(roleName));
    }

    /**
     * ロール名を設定
     *
     * @param roleName ロール名
     */
    CapacityOfRole& withRoleName(StringHolder roleName)
    {
        setRoleName(std::move(roleName));
        return *this;
    }

    /**
     * ロール名の別名リストを取得
     *
     * @return ロール名の別名リスト
     */
    const optional<List<StringHolder>>& getRoleAliases() const
    {
        return ensureData().roleAliases;
    }

    /**
     * ロール名の別名リストを設定
     *
     * @param roleAliases ロール名の別名リスト
     */
    void setRoleAliases(List<StringHolder> roleAliases)
    {
        ensureData().roleAliases.emplace(std::move(roleAliases));
    }

    /**
     * ロール名の別名リストを設定
     *
     * @param roleAliases ロール名の別名リスト
     */
    CapacityOfRole& withRoleAliases(List<StringHolder> roleAliases)
    {
        setRoleAliases(std::move(roleAliases));
        return *this;
    }

    /**
     * 募集人数を取得
     *
     * @return 募集人数
     */
    const optional<Int32>& getCapacity() const
    {
        return ensureData().capacity;
    }

    /**
     * 募集人数を設定
     *
     * @param capacity 募集人数
     */
    void setCapacity(Int32 capacity)
    {
        ensureData().capacity.emplace(capacity);
    }

    /**
     * 募集人数を設定
     *
     * @param capacity 募集人数
     */
    CapacityOfRole& withCapacity(Int32 capacity)
    {
        setCapacity(capacity);
        return *this;
    }

    /**
     * 参加者のプレイヤー情報リストを取得
     *
     * @return 参加者のプレイヤー情報リスト
     */
    const optional<List<Player>>& getParticipants() const
    {
        return ensureData().participants;
    }

    /**
     * 参加者のプレイヤー情報リストを設定
     *
     * @param participants 参加者のプレイヤー情報リスト
     */
    void setParticipants(List<Player> participants)
    {
        ensureData().participants.emplace(std::move(participants));
    }

    /**
     * 参加者のプレイヤー情報リストを設定
     *
     * @param participants 参加者のプレイヤー情報リスト
     */
    CapacityOfRole& withParticipants(List<Player> participants)
    {
        setParticipants(std::move(participants));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CapacityOfRole& lhs, const CapacityOfRole& lhr);

inline bool operator==(const CapacityOfRole& lhs, const CapacityOfRole& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_CAPACITYOFROLE_HPP_