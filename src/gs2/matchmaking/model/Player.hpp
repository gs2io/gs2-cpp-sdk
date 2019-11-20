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

#ifndef GS2_MATCHMAKING_MODEL_PLAYER_HPP_
#define GS2_MATCHMAKING_MODEL_PLAYER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Attribute.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * プレイヤー情報
 *
 * @author Game Server Services, Inc.
 *
 */
class Player : public Gs2Object
{
    friend bool operator!=(const Player& lhs, const Player& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 属性値のリスト */
        optional<List<Attribute>> attributes;
        /** ロール名 */
        optional<StringHolder> roleName;
        /** 参加を拒否するユーザIDリスト */
        optional<List<StringHolder>> denyUserIds;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            roleName(data.roleName)
        {
            if (data.attributes)
            {
                attributes = data.attributes->deepCopy();
            }
            if (data.denyUserIds)
            {
                denyUserIds = data.denyUserIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "attributes") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->attributes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Attribute item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->attributes += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "roleName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->roleName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "denyUserIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->denyUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->denyUserIds += std::move(stringHolder);
                        }
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Player() = default;
    Player(const Player& player) = default;
    Player(Player&& player) = default;
    ~Player() = default;

    Player& operator=(const Player& player) = default;
    Player& operator=(Player&& player) = default;

    Player deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Player);
    }

    const Player* operator->() const
    {
        return this;
    }

    Player* operator->()
    {
        return this;
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
    Player& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 属性値のリストを取得
     *
     * @return 属性値のリスト
     */
    const optional<List<Attribute>>& getAttributes() const
    {
        return ensureData().attributes;
    }

    /**
     * 属性値のリストを設定
     *
     * @param attributes 属性値のリスト
     */
    void setAttributes(List<Attribute> attributes)
    {
        ensureData().attributes.emplace(std::move(attributes));
    }

    /**
     * 属性値のリストを設定
     *
     * @param attributes 属性値のリスト
     */
    Player& withAttributes(List<Attribute> attributes)
    {
        setAttributes(std::move(attributes));
        return *this;
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
    Player& withRoleName(StringHolder roleName)
    {
        setRoleName(std::move(roleName));
        return *this;
    }

    /**
     * 参加を拒否するユーザIDリストを取得
     *
     * @return 参加を拒否するユーザIDリスト
     */
    const optional<List<StringHolder>>& getDenyUserIds() const
    {
        return ensureData().denyUserIds;
    }

    /**
     * 参加を拒否するユーザIDリストを設定
     *
     * @param denyUserIds 参加を拒否するユーザIDリスト
     */
    void setDenyUserIds(List<StringHolder> denyUserIds)
    {
        ensureData().denyUserIds.emplace(std::move(denyUserIds));
    }

    /**
     * 参加を拒否するユーザIDリストを設定
     *
     * @param denyUserIds 参加を拒否するユーザIDリスト
     */
    Player& withDenyUserIds(List<StringHolder> denyUserIds)
    {
        setDenyUserIds(std::move(denyUserIds));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Player& lhs, const Player& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->attributes != lhr.m_pData->attributes)
        {
            return true;
        }
        if (lhs.m_pData->roleName != lhr.m_pData->roleName)
        {
            return true;
        }
        if (lhs.m_pData->denyUserIds != lhr.m_pData->denyUserIds)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Player& lhs, const Player& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_PLAYER_HPP_