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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Player.hpp"
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            roleName(data.roleName),
            roleAliases(data.roleAliases),
            capacity(data.capacity),
            participants(data.participants)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            roleName(std::move(data.roleName)),
            roleAliases(std::move(data.roleAliases)),
            capacity(std::move(data.capacity)),
            participants(std::move(data.participants))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "roleName") == 0) {
                if (jsonValue.IsString())
                {
                    this->roleName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "roleAliases") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->roleAliases.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->roleAliases, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name, "capacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->capacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "participants") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->participants.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Player item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->participants, std::move(item));
                    }
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    CapacityOfRole() :
        m_pData(nullptr)
    {}

    CapacityOfRole(const CapacityOfRole& capacityOfRole) :
        Gs2Object(capacityOfRole),
        m_pData(capacityOfRole.m_pData != nullptr ? new Data(*capacityOfRole.m_pData) : nullptr)
    {}

    CapacityOfRole(CapacityOfRole&& capacityOfRole) :
        Gs2Object(std::move(capacityOfRole)),
        m_pData(capacityOfRole.m_pData)
    {
        capacityOfRole.m_pData = nullptr;
    }

    ~CapacityOfRole()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CapacityOfRole& operator=(const CapacityOfRole& capacityOfRole)
    {
        Gs2Object::operator=(capacityOfRole);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*capacityOfRole.m_pData);

        return *this;
    }

    CapacityOfRole& operator=(CapacityOfRole&& capacityOfRole)
    {
        Gs2Object::operator=(std::move(capacityOfRole));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = capacityOfRole.m_pData;
        capacityOfRole.m_pData = nullptr;

        return *this;
    }

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
    void setRoleName(const Char* roleName)
    {
        ensureData().roleName.emplace(roleName);
    }

    /**
     * ロール名を設定
     *
     * @param roleName ロール名
     */
    CapacityOfRole& withRoleName(const Char* roleName)
    {
        setRoleName(roleName);
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
    void setRoleAliases(const List<StringHolder>& roleAliases)
    {
        ensureData().roleAliases.emplace(roleAliases);
    }

    /**
     * ロール名の別名リストを設定
     *
     * @param roleAliases ロール名の別名リスト
     */
    CapacityOfRole& withRoleAliases(const List<StringHolder>& roleAliases)
    {
        setRoleAliases(roleAliases);
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
    void setParticipants(const List<Player>& participants)
    {
        ensureData().participants.emplace(participants);
    }

    /**
     * 参加者のプレイヤー情報リストを設定
     *
     * @param participants 参加者のプレイヤー情報リスト
     */
    CapacityOfRole& withParticipants(const List<Player>& participants)
    {
        setParticipants(participants);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CapacityOfRole& lhs, const CapacityOfRole& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->roleName != lhr.m_pData->roleName)
        {
            return true;
        }
        if (lhs.m_pData->roleAliases != lhr.m_pData->roleAliases)
        {
            return true;
        }
        if (lhs.m_pData->capacity != lhr.m_pData->capacity)
        {
            return true;
        }
        if (lhs.m_pData->participants != lhr.m_pData->participants)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const CapacityOfRole& lhs, const CapacityOfRole& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_CAPACITYOFROLE_HPP_