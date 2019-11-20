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

#ifndef GS2_MISSION_MODEL_COMPLETE_HPP_
#define GS2_MISSION_MODEL_COMPLETE_HPP_

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
 * 達成状況
 *
 * @author Game Server Services, Inc.
 *
 */
class Complete : public Gs2Object
{
    friend bool operator!=(const Complete& lhs, const Complete& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 達成状況 */
        optional<StringHolder> completeId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ミッショングループ名 */
        optional<StringHolder> missionGroupName;
        /** 達成済みのタスク名リスト */
        optional<List<StringHolder>> completedMissionTaskNames;
        /** 報酬の受け取り済みのタスク名リスト */
        optional<List<StringHolder>> receivedMissionTaskNames;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            completeId(data.completeId),
            userId(data.userId),
            missionGroupName(data.missionGroupName),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.completedMissionTaskNames)
            {
                completedMissionTaskNames = data.completedMissionTaskNames->deepCopy();
            }
            if (data.receivedMissionTaskNames)
            {
                receivedMissionTaskNames = data.receivedMissionTaskNames->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "completeId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->completeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "missionGroupName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->missionGroupName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completedMissionTaskNames") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->completedMissionTaskNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->completedMissionTaskNames += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "receivedMissionTaskNames") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->receivedMissionTaskNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->receivedMissionTaskNames += std::move(stringHolder);
                        }
                    }
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
    Complete() = default;
    Complete(const Complete& complete) = default;
    Complete(Complete&& complete) = default;
    ~Complete() = default;

    Complete& operator=(const Complete& complete) = default;
    Complete& operator=(Complete&& complete) = default;

    Complete deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Complete);
    }

    const Complete* operator->() const
    {
        return this;
    }

    Complete* operator->()
    {
        return this;
    }
    /**
     * 達成状況を取得
     *
     * @return 達成状況
     */
    const optional<StringHolder>& getCompleteId() const
    {
        return ensureData().completeId;
    }

    /**
     * 達成状況を設定
     *
     * @param completeId 達成状況
     */
    void setCompleteId(StringHolder completeId)
    {
        ensureData().completeId.emplace(std::move(completeId));
    }

    /**
     * 達成状況を設定
     *
     * @param completeId 達成状況
     */
    Complete& withCompleteId(StringHolder completeId)
    {
        setCompleteId(std::move(completeId));
        return *this;
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
    Complete& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * ミッショングループ名を取得
     *
     * @return ミッショングループ名
     */
    const optional<StringHolder>& getMissionGroupName() const
    {
        return ensureData().missionGroupName;
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    void setMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName.emplace(std::move(missionGroupName));
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    Complete& withMissionGroupName(StringHolder missionGroupName)
    {
        setMissionGroupName(std::move(missionGroupName));
        return *this;
    }

    /**
     * 達成済みのタスク名リストを取得
     *
     * @return 達成済みのタスク名リスト
     */
    const optional<List<StringHolder>>& getCompletedMissionTaskNames() const
    {
        return ensureData().completedMissionTaskNames;
    }

    /**
     * 達成済みのタスク名リストを設定
     *
     * @param completedMissionTaskNames 達成済みのタスク名リスト
     */
    void setCompletedMissionTaskNames(List<StringHolder> completedMissionTaskNames)
    {
        ensureData().completedMissionTaskNames.emplace(std::move(completedMissionTaskNames));
    }

    /**
     * 達成済みのタスク名リストを設定
     *
     * @param completedMissionTaskNames 達成済みのタスク名リスト
     */
    Complete& withCompletedMissionTaskNames(List<StringHolder> completedMissionTaskNames)
    {
        setCompletedMissionTaskNames(std::move(completedMissionTaskNames));
        return *this;
    }

    /**
     * 報酬の受け取り済みのタスク名リストを取得
     *
     * @return 報酬の受け取り済みのタスク名リスト
     */
    const optional<List<StringHolder>>& getReceivedMissionTaskNames() const
    {
        return ensureData().receivedMissionTaskNames;
    }

    /**
     * 報酬の受け取り済みのタスク名リストを設定
     *
     * @param receivedMissionTaskNames 報酬の受け取り済みのタスク名リスト
     */
    void setReceivedMissionTaskNames(List<StringHolder> receivedMissionTaskNames)
    {
        ensureData().receivedMissionTaskNames.emplace(std::move(receivedMissionTaskNames));
    }

    /**
     * 報酬の受け取り済みのタスク名リストを設定
     *
     * @param receivedMissionTaskNames 報酬の受け取り済みのタスク名リスト
     */
    Complete& withReceivedMissionTaskNames(List<StringHolder> receivedMissionTaskNames)
    {
        setReceivedMissionTaskNames(std::move(receivedMissionTaskNames));
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
    Complete& withCreatedAt(Int64 createdAt)
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
    Complete& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Complete& lhs, const Complete& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->completeId != lhr.m_pData->completeId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->missionGroupName != lhr.m_pData->missionGroupName)
        {
            return true;
        }
        if (lhs.m_pData->completedMissionTaskNames != lhr.m_pData->completedMissionTaskNames)
        {
            return true;
        }
        if (lhs.m_pData->receivedMissionTaskNames != lhr.m_pData->receivedMissionTaskNames)
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

inline bool operator==(const Complete& lhs, const Complete& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_COMPLETE_HPP_