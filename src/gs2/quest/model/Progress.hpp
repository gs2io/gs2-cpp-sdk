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

#ifndef GS2_QUEST_MODEL_PROGRESS_HPP_
#define GS2_QUEST_MODEL_PROGRESS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Reward.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエスト挑戦
 *
 * @author Game Server Services, Inc.
 *
 */
class Progress : public Gs2Object
{
    friend bool operator!=(const Progress& lhs, const Progress& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト挑戦 */
        optional<StringHolder> progressId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** クエストモデル */
        optional<StringHolder> questModelId;
        /** 乱数シード */
        optional<Int64> randomSeed;
        /** クエストで得られる報酬の上限 */
        optional<List<Reward>> rewards;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            progressId(data.progressId),
            userId(data.userId),
            transactionId(data.transactionId),
            questModelId(data.questModelId),
            randomSeed(data.randomSeed),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.rewards)
            {
                rewards = data.rewards->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "progressId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->progressId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "transactionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "questModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->questModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "randomSeed") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->randomSeed = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "rewards") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->rewards.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Reward item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->rewards += std::move(item);
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
    Progress() = default;
    Progress(const Progress& progress) = default;
    Progress(Progress&& progress) = default;
    ~Progress() = default;

    Progress& operator=(const Progress& progress) = default;
    Progress& operator=(Progress&& progress) = default;

    Progress deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Progress);
    }

    const Progress* operator->() const
    {
        return this;
    }

    Progress* operator->()
    {
        return this;
    }
    /**
     * クエスト挑戦を取得
     *
     * @return クエスト挑戦
     */
    const optional<StringHolder>& getProgressId() const
    {
        return ensureData().progressId;
    }

    /**
     * クエスト挑戦を設定
     *
     * @param progressId クエスト挑戦
     */
    void setProgressId(StringHolder progressId)
    {
        ensureData().progressId.emplace(std::move(progressId));
    }

    /**
     * クエスト挑戦を設定
     *
     * @param progressId クエスト挑戦
     */
    Progress& withProgressId(StringHolder progressId)
    {
        setProgressId(std::move(progressId));
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
    Progress& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    Progress& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    /**
     * クエストモデルを取得
     *
     * @return クエストモデル
     */
    const optional<StringHolder>& getQuestModelId() const
    {
        return ensureData().questModelId;
    }

    /**
     * クエストモデルを設定
     *
     * @param questModelId クエストモデル
     */
    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId.emplace(std::move(questModelId));
    }

    /**
     * クエストモデルを設定
     *
     * @param questModelId クエストモデル
     */
    Progress& withQuestModelId(StringHolder questModelId)
    {
        setQuestModelId(std::move(questModelId));
        return *this;
    }

    /**
     * 乱数シードを取得
     *
     * @return 乱数シード
     */
    const optional<Int64>& getRandomSeed() const
    {
        return ensureData().randomSeed;
    }

    /**
     * 乱数シードを設定
     *
     * @param randomSeed 乱数シード
     */
    void setRandomSeed(Int64 randomSeed)
    {
        ensureData().randomSeed.emplace(randomSeed);
    }

    /**
     * 乱数シードを設定
     *
     * @param randomSeed 乱数シード
     */
    Progress& withRandomSeed(Int64 randomSeed)
    {
        setRandomSeed(randomSeed);
        return *this;
    }

    /**
     * クエストで得られる報酬の上限を取得
     *
     * @return クエストで得られる報酬の上限
     */
    const optional<List<Reward>>& getRewards() const
    {
        return ensureData().rewards;
    }

    /**
     * クエストで得られる報酬の上限を設定
     *
     * @param rewards クエストで得られる報酬の上限
     */
    void setRewards(List<Reward> rewards)
    {
        ensureData().rewards.emplace(std::move(rewards));
    }

    /**
     * クエストで得られる報酬の上限を設定
     *
     * @param rewards クエストで得られる報酬の上限
     */
    Progress& withRewards(List<Reward> rewards)
    {
        setRewards(std::move(rewards));
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
    Progress& withCreatedAt(Int64 createdAt)
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
    Progress& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Progress& lhs, const Progress& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->progressId != lhr.m_pData->progressId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->questModelId != lhr.m_pData->questModelId)
        {
            return true;
        }
        if (lhs.m_pData->randomSeed != lhr.m_pData->randomSeed)
        {
            return true;
        }
        if (lhs.m_pData->rewards != lhr.m_pData->rewards)
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

inline bool operator==(const Progress& lhs, const Progress& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_PROGRESS_HPP_