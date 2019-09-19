

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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZPLAYER_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZPLAYER_HPP_

#include <gs2/matchmaking/model/Player.hpp>
#include "EzAttribute.hpp"


namespace gs2 { namespace ez { namespace matchmaking {

class EzPlayer : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 属性値のリスト */
        gs2::optional<List<EzAttribute>> attributes;
        /** ロール名 */
        gs2::optional<StringHolder> roleName;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            roleName(data.roleName)
        {
            if (data.attributes)
            {
                attributes = data.attributes->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::Player& player) :
            userId(player.getUserId()),
            roleName(player.getRoleName())
        {
            attributes.emplace();
            if (player.getAttributes())
            {
                for (int i = 0; i < player.getAttributes()->getCount(); ++i)
                {
                    *attributes += EzAttribute((*player.getAttributes())[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPlayer() = default;
    EzPlayer(const EzPlayer& ezPlayer) = default;
    EzPlayer(EzPlayer&& ezPlayer) = default;
    ~EzPlayer() = default;

    EzPlayer(gs2::matchmaking::Player player) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(player)
    {}

    EzPlayer& operator=(const EzPlayer& ezPlayer) = default;
    EzPlayer& operator=(EzPlayer&& ezPlayer) = default;

    EzPlayer deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPlayer);
    }

    gs2::matchmaking::Player ToModel() const
    {
        gs2::matchmaking::Player player;
        player.setUserId(getUserId());
        {
            gs2::List<gs2::matchmaking::Attribute> list;
            auto& attributes = getAttributes();
            for (int i = 0; i < attributes.getCount(); ++i)
            {
                list += attributes[i].ToModel();
            }
            player.setAttributes(list);
        }
        player.setRoleName(getRoleName());
        return player;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const List<EzAttribute>& getAttributes() const
    {
        return *ensureData().attributes;
    }

    const StringHolder& getRoleName() const
    {
        return *ensureData().roleName;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setAttributes(List<EzAttribute> attributes)
    {
        ensureData().attributes = std::move(attributes);
    }

    void setRoleName(StringHolder roleName)
    {
        ensureData().roleName = std::move(roleName);
    }

    EzPlayer& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzPlayer& withAttributes(List<EzAttribute> attributes)
    {
        setAttributes(std::move(attributes));
        return *this;
    }

    EzPlayer& withRoleName(StringHolder roleName)
    {
        setRoleName(std::move(roleName));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZPLAYER_HPP_