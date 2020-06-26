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

#ifndef GS2_MATCHMAKING_MODEL_RATINGMODELMASTER_HPP_
#define GS2_MATCHMAKING_MODEL_RATINGMODELMASTER_HPP_

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
 * レーティングモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class RatingModelMaster : public Gs2Object
{
    friend bool operator!=(const RatingModelMaster& lhs, const RatingModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** レーティングモデルマスター */
        optional<StringHolder> ratingModelId;
        /** レーティングの種類名 */
        optional<StringHolder> name;
        /** レーティングの種類のメタデータ */
        optional<StringHolder> metadata;
        /** レーティングモデルマスターの説明 */
        optional<StringHolder> description;
        /** レート値の変動の大きさ */
        optional<Int32> volatility;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ratingModelId(data.ratingModelId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            volatility(data.volatility),
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
            if (std::strcmp(name_, "ratingModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ratingModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "volatility") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->volatility = jsonValue.GetInt();
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
    RatingModelMaster() = default;
    RatingModelMaster(const RatingModelMaster& ratingModelMaster) = default;
    RatingModelMaster(RatingModelMaster&& ratingModelMaster) = default;
    ~RatingModelMaster() = default;

    RatingModelMaster& operator=(const RatingModelMaster& ratingModelMaster) = default;
    RatingModelMaster& operator=(RatingModelMaster&& ratingModelMaster) = default;

    RatingModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RatingModelMaster);
    }

    const RatingModelMaster* operator->() const
    {
        return this;
    }

    RatingModelMaster* operator->()
    {
        return this;
    }
    /**
     * レーティングモデルマスターを取得
     *
     * @return レーティングモデルマスター
     */
    const optional<StringHolder>& getRatingModelId() const
    {
        return ensureData().ratingModelId;
    }

    /**
     * レーティングモデルマスターを設定
     *
     * @param ratingModelId レーティングモデルマスター
     */
    void setRatingModelId(StringHolder ratingModelId)
    {
        ensureData().ratingModelId.emplace(std::move(ratingModelId));
    }

    /**
     * レーティングモデルマスターを設定
     *
     * @param ratingModelId レーティングモデルマスター
     */
    RatingModelMaster& withRatingModelId(StringHolder ratingModelId)
    {
        setRatingModelId(std::move(ratingModelId));
        return *this;
    }

    /**
     * レーティングの種類名を取得
     *
     * @return レーティングの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * レーティングの種類名を設定
     *
     * @param name レーティングの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * レーティングの種類名を設定
     *
     * @param name レーティングの種類名
     */
    RatingModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * レーティングの種類のメタデータを取得
     *
     * @return レーティングの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * レーティングの種類のメタデータを設定
     *
     * @param metadata レーティングの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * レーティングの種類のメタデータを設定
     *
     * @param metadata レーティングの種類のメタデータ
     */
    RatingModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * レーティングモデルマスターの説明を取得
     *
     * @return レーティングモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * レーティングモデルマスターの説明を設定
     *
     * @param description レーティングモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * レーティングモデルマスターの説明を設定
     *
     * @param description レーティングモデルマスターの説明
     */
    RatingModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * レート値の変動の大きさを取得
     *
     * @return レート値の変動の大きさ
     */
    const optional<Int32>& getVolatility() const
    {
        return ensureData().volatility;
    }

    /**
     * レート値の変動の大きさを設定
     *
     * @param volatility レート値の変動の大きさ
     */
    void setVolatility(Int32 volatility)
    {
        ensureData().volatility.emplace(volatility);
    }

    /**
     * レート値の変動の大きさを設定
     *
     * @param volatility レート値の変動の大きさ
     */
    RatingModelMaster& withVolatility(Int32 volatility)
    {
        setVolatility(volatility);
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
    RatingModelMaster& withCreatedAt(Int64 createdAt)
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
    RatingModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RatingModelMaster& lhs, const RatingModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->ratingModelId != lhr.m_pData->ratingModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->volatility != lhr.m_pData->volatility)
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

inline bool operator==(const RatingModelMaster& lhs, const RatingModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_RATINGMODELMASTER_HPP_