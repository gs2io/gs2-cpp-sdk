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

#ifndef GS2_MATCHMAKING_MODEL_LEAVENOTIFICATION_HPP_
#define GS2_MATCHMAKING_MODEL_LEAVENOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class LeaveNotification : public Gs2Object
{
    friend bool operator!=(const LeaveNotification& lhs, const LeaveNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ギャザリング名 */
        optional<StringHolder> gatheringName;
        /** ユーザーID */
        optional<StringHolder> leaveUserId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            gatheringName(data.gatheringName),
            leaveUserId(data.leaveUserId)
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
            else if (std::strcmp(name_, "gatheringName") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "leaveUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->leaveUserId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    LeaveNotification() = default;
    LeaveNotification(const LeaveNotification& leaveNotification) = default;
    LeaveNotification(LeaveNotification&& leaveNotification) = default;
    ~LeaveNotification() = default;

    LeaveNotification& operator=(const LeaveNotification& leaveNotification) = default;
    LeaveNotification& operator=(LeaveNotification&& leaveNotification) = default;

    LeaveNotification deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LeaveNotification);
    }

    const LeaveNotification* operator->() const
    {
        return this;
    }

    LeaveNotification* operator->()
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
    LeaveNotification& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(
            std::move(namespaceName)
        );
        return *this;
    }

    /**
     * ギャザリング名を取得
     *
     * @return ギャザリング名
     */
    const optional<StringHolder>& getGatheringName() const
    {
        return ensureData().gatheringName;
    }

    /**
     * ギャザリング名を設定
     *
     * @param gatheringName ギャザリング名
     */
    void setGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(
            std::move(gatheringName)
        );
    }

    /**
     * ギャザリング名を設定
     *
     * @param gatheringName ギャザリング名
     */
    LeaveNotification& withGatheringName(StringHolder gatheringName)
    {
        setGatheringName(
            std::move(gatheringName)
        );
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getLeaveUserId() const
    {
        return ensureData().leaveUserId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param leaveUserId ユーザーID
     */
    void setLeaveUserId(StringHolder leaveUserId)
    {
        ensureData().leaveUserId.emplace(
            std::move(leaveUserId)
        );
    }

    /**
     * ユーザーIDを設定
     *
     * @param leaveUserId ユーザーID
     */
    LeaveNotification& withLeaveUserId(StringHolder leaveUserId)
    {
        setLeaveUserId(
            std::move(leaveUserId)
        );
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LeaveNotification& lhs, const LeaveNotification& lhr)
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
        if (lhs.m_pData->gatheringName != lhr.m_pData->gatheringName)
        {
            return true;
        }
        if (lhs.m_pData->leaveUserId != lhr.m_pData->leaveUserId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const LeaveNotification& lhs, const LeaveNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_LEAVENOTIFICATION_HPP_