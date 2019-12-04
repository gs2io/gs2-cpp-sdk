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

#ifndef GS2_WATCH_MODEL_CUMULATIVE_HPP_
#define GS2_WATCH_MODEL_CUMULATIVE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * 累積値
 *
 * @author Game Server Services, Inc.
 *
 */
class Cumulative : public Gs2Object
{
    friend bool operator!=(const Cumulative& lhs, const Cumulative& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 累積値 */
        optional<StringHolder> cumulativeId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** リソースのGRN */
        optional<StringHolder> resourceGrn;
        /** 名前 */
        optional<StringHolder> name;
        /** 累積値 */
        optional<Int64> value;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            cumulativeId(data.cumulativeId),
            ownerId(data.ownerId),
            resourceGrn(data.resourceGrn),
            name(data.name),
            value(data.value),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "cumulativeId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->cumulativeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "resourceGrn") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->resourceGrn.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->value = jsonValue.GetInt64();
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
    Cumulative() = default;
    Cumulative(const Cumulative& cumulative) = default;
    Cumulative(Cumulative&& cumulative) = default;
    ~Cumulative() = default;

    Cumulative& operator=(const Cumulative& cumulative) = default;
    Cumulative& operator=(Cumulative&& cumulative) = default;

    Cumulative deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Cumulative);
    }

    const Cumulative* operator->() const
    {
        return this;
    }

    Cumulative* operator->()
    {
        return this;
    }
    /**
     * 累積値を取得
     *
     * @return 累積値
     */
    const optional<StringHolder>& getCumulativeId() const
    {
        return ensureData().cumulativeId;
    }

    /**
     * 累積値を設定
     *
     * @param cumulativeId 累積値
     */
    void setCumulativeId(StringHolder cumulativeId)
    {
        ensureData().cumulativeId.emplace(std::move(cumulativeId));
    }

    /**
     * 累積値を設定
     *
     * @param cumulativeId 累積値
     */
    Cumulative& withCumulativeId(StringHolder cumulativeId)
    {
        setCumulativeId(std::move(cumulativeId));
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
    Cumulative& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * リソースのGRNを取得
     *
     * @return リソースのGRN
     */
    const optional<StringHolder>& getResourceGrn() const
    {
        return ensureData().resourceGrn;
    }

    /**
     * リソースのGRNを設定
     *
     * @param resourceGrn リソースのGRN
     */
    void setResourceGrn(StringHolder resourceGrn)
    {
        ensureData().resourceGrn.emplace(std::move(resourceGrn));
    }

    /**
     * リソースのGRNを設定
     *
     * @param resourceGrn リソースのGRN
     */
    Cumulative& withResourceGrn(StringHolder resourceGrn)
    {
        setResourceGrn(std::move(resourceGrn));
        return *this;
    }

    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    Cumulative& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 累積値を取得
     *
     * @return 累積値
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 累積値を設定
     *
     * @param value 累積値
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 累積値を設定
     *
     * @param value 累積値
     */
    Cumulative& withValue(Int64 value)
    {
        setValue(value);
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
    Cumulative& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Cumulative& lhs, const Cumulative& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->cumulativeId != lhr.m_pData->cumulativeId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->resourceGrn != lhr.m_pData->resourceGrn)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
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

inline bool operator==(const Cumulative& lhs, const Cumulative& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_WATCH_MODEL_CUMULATIVE_HPP_