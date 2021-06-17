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

#ifndef GS2_MATCHMAKING_MODEL_RATINGMODEL_HPP_
#define GS2_MATCHMAKING_MODEL_RATINGMODEL_HPP_

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
 * レーティングモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class RatingModel : public Gs2Object
{
    friend bool operator!=(const RatingModel& lhs, const RatingModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** レーティングモデル */
        optional<StringHolder> ratingModelId;
        /** レーティングの種類名 */
        optional<StringHolder> name;
        /** レーティングの種類のメタデータ */
        optional<StringHolder> metadata;
        /** レート値の変動の大きさ */
        optional<Int32> volatility;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ratingModelId(data.ratingModelId),
            name(data.name),
            metadata(data.metadata),
            volatility(data.volatility)
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
            else if (std::strcmp(name_, "volatility") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->volatility = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RatingModel() = default;
    RatingModel(const RatingModel& ratingModel) = default;
    RatingModel(RatingModel&& ratingModel) = default;
    ~RatingModel() = default;

    RatingModel& operator=(const RatingModel& ratingModel) = default;
    RatingModel& operator=(RatingModel&& ratingModel) = default;

    RatingModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RatingModel);
    }

    const RatingModel* operator->() const
    {
        return this;
    }

    RatingModel* operator->()
    {
        return this;
    }
    /**
     * レーティングモデルを取得
     *
     * @return レーティングモデル
     */
    const optional<StringHolder>& getRatingModelId() const
    {
        return ensureData().ratingModelId;
    }

    /**
     * レーティングモデルを設定
     *
     * @param ratingModelId レーティングモデル
     */
    void setRatingModelId(StringHolder ratingModelId)
    {
        ensureData().ratingModelId.emplace(std::move(ratingModelId));
    }

    /**
     * レーティングモデルを設定
     *
     * @param ratingModelId レーティングモデル
     */
    RatingModel& withRatingModelId(StringHolder ratingModelId)
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
    RatingModel& withName(StringHolder name)
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
    RatingModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    RatingModel& withVolatility(Int32 volatility)
    {
        setVolatility(volatility);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RatingModel& lhs, const RatingModel& lhr)
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
        if (lhs.m_pData->volatility != lhr.m_pData->volatility)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const RatingModel& lhs, const RatingModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_RATINGMODEL_HPP_