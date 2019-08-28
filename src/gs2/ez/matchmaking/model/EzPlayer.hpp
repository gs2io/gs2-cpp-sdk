

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
    /** ユーザーID */
    gs2::optional<StringHolder> m_UserId;
    /** 属性値のリスト */
    gs2::optional<List<EzAttribute>> m_Attributes;
    /** ロール名 */
    gs2::optional<StringHolder> m_RoleName;

public:
    EzPlayer() = default;

    EzPlayer(gs2::matchmaking::Player player) :
        m_UserId(player.getUserId()),
        m_RoleName(player.getRoleName())
    {
        m_Attributes.emplace();
        if (player.getAttributes())
        {
            for (int i = 0; i < player.getAttributes()->getCount(); ++i)
            {
                *m_Attributes += EzAttribute((*player.getAttributes())[i]);
            }
        }
    }

    gs2::matchmaking::Player ToModel() const
    {
        gs2::matchmaking::Player player;
        player.setUserId(*m_UserId);
        {
            gs2::List<gs2::matchmaking::Attribute> list;
            auto& attributes = *m_Attributes;
            for (int i = 0; i < attributes.getCount(); ++i)
            {
                list += attributes[i].ToModel();
            }
            player.setAttributes(list);
        }
        player.setRoleName(*m_RoleName);
        return player;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getUserId() const
    {
        return *m_UserId;
    }

    gs2::StringHolder& getUserId()
    {
        return *m_UserId;
    }

    const List<EzAttribute>& getAttributes() const
    {
        return *m_Attributes;
    }

    List<EzAttribute>& getAttributes()
    {
        return *m_Attributes;
    }

    const gs2::StringHolder& getRoleName() const
    {
        return *m_RoleName;
    }

    gs2::StringHolder& getRoleName()
    {
        return *m_RoleName;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(Char* userId)
    {
        m_UserId.emplace(userId);
    }

    void setAttributes(const List<EzAttribute>& attributes)
    {
        m_Attributes = attributes;
    }

    void setAttributes(List<EzAttribute>&& attributes)
    {
        m_Attributes = std::move(attributes);
    }

    void setRoleName(Char* roleName)
    {
        m_RoleName.emplace(roleName);
    }

    EzPlayer& withUserId(Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    EzPlayer& withAttributes(const List<EzAttribute>& attributes)
    {
        setAttributes(attributes);
        return *this;
    }

    EzPlayer& withAttributes(List<EzAttribute>&& attributes)
    {
        setAttributes(std::move(attributes));
        return *this;
    }

    EzPlayer& withRoleName(Char* roleName)
    {
        setRoleName(roleName);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZPLAYER_HPP_