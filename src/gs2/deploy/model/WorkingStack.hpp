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

#ifndef GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_
#define GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * 実行中のスタック
 *
 * @author Game Server Services, Inc.
 *
 */
class WorkingStack : public Gs2Object
{
    friend bool operator!=(const WorkingStack& lhs, const WorkingStack& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 実行中のスタック */
        optional<StringHolder> stackId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 実行中のスタック名 */
        optional<StringHolder> name;
        /** 実行に対して割り振られる一意な ID */
        optional<StringHolder> workId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stackId(data.stackId),
            ownerId(data.ownerId),
            name(data.name),
            workId(data.workId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "stackId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stackId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "workId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->workId.emplace(jsonValue.GetString());
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
    WorkingStack() = default;
    WorkingStack(const WorkingStack& workingStack) = default;
    WorkingStack(WorkingStack&& workingStack) = default;
    ~WorkingStack() = default;

    WorkingStack& operator=(const WorkingStack& workingStack) = default;
    WorkingStack& operator=(WorkingStack&& workingStack) = default;

    WorkingStack deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WorkingStack);
    }

    const WorkingStack* operator->() const
    {
        return this;
    }

    WorkingStack* operator->()
    {
        return this;
    }
    /**
     * 実行中のスタックを取得
     *
     * @return 実行中のスタック
     */
    const optional<StringHolder>& getStackId() const
    {
        return ensureData().stackId;
    }

    /**
     * 実行中のスタックを設定
     *
     * @param stackId 実行中のスタック
     */
    void setStackId(StringHolder stackId)
    {
        ensureData().stackId.emplace(std::move(stackId));
    }

    /**
     * 実行中のスタックを設定
     *
     * @param stackId 実行中のスタック
     */
    WorkingStack& withStackId(StringHolder stackId)
    {
        setStackId(std::move(stackId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    WorkingStack& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * 実行中のスタック名を取得
     *
     * @return 実行中のスタック名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 実行中のスタック名を設定
     *
     * @param name 実行中のスタック名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 実行中のスタック名を設定
     *
     * @param name 実行中のスタック名
     */
    WorkingStack& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 実行に対して割り振られる一意な IDを取得
     *
     * @return 実行に対して割り振られる一意な ID
     */
    const optional<StringHolder>& getWorkId() const
    {
        return ensureData().workId;
    }

    /**
     * 実行に対して割り振られる一意な IDを設定
     *
     * @param workId 実行に対して割り振られる一意な ID
     */
    void setWorkId(StringHolder workId)
    {
        ensureData().workId.emplace(std::move(workId));
    }

    /**
     * 実行に対して割り振られる一意な IDを設定
     *
     * @param workId 実行に対して割り振られる一意な ID
     */
    WorkingStack& withWorkId(StringHolder workId)
    {
        setWorkId(std::move(workId));
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
    WorkingStack& withCreatedAt(Int64 createdAt)
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
    WorkingStack& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WorkingStack& lhs, const WorkingStack& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->stackId != lhr.m_pData->stackId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->workId != lhr.m_pData->workId)
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

inline bool operator==(const WorkingStack& lhs, const WorkingStack& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_