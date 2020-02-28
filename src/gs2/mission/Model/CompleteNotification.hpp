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

#ifndef GS2_MISSION_MODEL_COMPLETENOTIFICATION_HPP_
#define GS2_MISSION_MODEL_COMPLETENOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace mission {

/**
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class CompleteNotification : public Gs2Object
{
    friend bool operator!=(const CompleteNotification& lhs, const CompleteNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** グループ名 */
        optional<StringHolder> groupName;
        /** タスク名 */
        optional<StringHolder> taskName;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            groupName(data.groupName),
            taskName(data.taskName)
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
            else if (std::strcmp(name_, "groupName") == 0) {
                if (jsonValue.IsString())
                {
                    this->groupName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "taskName") == 0) {
                if (jsonValue.IsString())
                {
                    this->taskName.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CompleteNotification() = default;
    CompleteNotification(const CompleteNotification& completeNotification) = default;
    CompleteNotification(CompleteNotification&& completeNotification) = default;
    ~CompleteNotification() = default;

    CompleteNotification& operator=(const CompleteNotification& completeNotification) = default;
    CompleteNotification& operator=(CompleteNotification&& completeNotification) = default;

    CompleteNotification deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CompleteNotification);
    }

    const CompleteNotification* operator->() const
    {
        return this;
    }

    CompleteNotification* operator->()
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
    CompleteNotification& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(
            std::move(namespaceName)
        );
        return *this;
    }

    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    void setGroupName(StringHolder groupName)
    {
        ensureData().groupName.emplace(
            std::move(groupName)
        );
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    CompleteNotification& withGroupName(StringHolder groupName)
    {
        setGroupName(
            std::move(groupName)
        );
        return *this;
    }

    /**
     * タスク名を取得
     *
     * @return タスク名
     */
    const optional<StringHolder>& getTaskName() const
    {
        return ensureData().taskName;
    }

    /**
     * タスク名を設定
     *
     * @param taskName タスク名
     */
    void setTaskName(StringHolder taskName)
    {
        ensureData().taskName.emplace(
            std::move(taskName)
        );
    }

    /**
     * タスク名を設定
     *
     * @param taskName タスク名
     */
    CompleteNotification& withTaskName(StringHolder taskName)
    {
        setTaskName(
            std::move(taskName)
        );
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CompleteNotification& lhs, const CompleteNotification& lhr)
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
        if (lhs.m_pData->groupName != lhr.m_pData->groupName)
        {
            return true;
        }
        if (lhs.m_pData->taskName != lhr.m_pData->taskName)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const CompleteNotification& lhs, const CompleteNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_COMPLETENOTIFICATION_HPP_