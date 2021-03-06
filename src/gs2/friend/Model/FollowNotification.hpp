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

#ifndef GS2_FRIEND_MODEL_FOLLOWNOTIFICATION_HPP_
#define GS2_FRIEND_MODEL_FOLLOWNOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace friend_ {

/**
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class FollowNotification : public Gs2Object
{
    friend bool operator!=(const FollowNotification& lhs, const FollowNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> fromUserId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            fromUserId(data.fromUserId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "fromUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->fromUserId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    FollowNotification() = default;
    FollowNotification(const FollowNotification& followNotification) = default;
    FollowNotification(FollowNotification&& followNotification) = default;
    ~FollowNotification() = default;

    FollowNotification& operator=(const FollowNotification& followNotification) = default;
    FollowNotification& operator=(FollowNotification&& followNotification) = default;

    FollowNotification deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(FollowNotification);
    }

    const FollowNotification* operator->() const
    {
        return this;
    }

    FollowNotification* operator->()
    {
        return this;
    }
    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(
            std::move(namespaceName)
        );
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    FollowNotification& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(
            std::move(namespaceName)
        );
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getFromUserId() const
    {
        return ensureData().fromUserId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param fromUserId ユーザーID
     */
    void setFromUserId(StringHolder fromUserId)
    {
        ensureData().fromUserId.emplace(
            std::move(fromUserId)
        );
    }

    /**
     * ユーザーIDを設定
     *
     * @param fromUserId ユーザーID
     */
    FollowNotification& withFromUserId(StringHolder fromUserId)
    {
        setFromUserId(
            std::move(fromUserId)
        );
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const FollowNotification& lhs, const FollowNotification& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData || lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->fromUserId != lhr.m_pData->fromUserId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const FollowNotification& lhs, const FollowNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_FOLLOWNOTIFICATION_HPP_