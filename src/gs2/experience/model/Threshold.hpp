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

#ifndef GS2_EXPERIENCE_MODEL_THRESHOLD_HPP_
#define GS2_EXPERIENCE_MODEL_THRESHOLD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * ランクアップ閾値
 *
 * @author Game Server Services, Inc.
 *
 */
class Threshold : public Gs2Object
{
    friend bool operator!=(const Threshold& lhs, const Threshold& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** しきい値ID */
        optional<StringHolder> thresholdId;
        /** ランクアップ閾値のメタデータ */
        optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        optional<List<Int64>> values;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            thresholdId(data.thresholdId),
            metadata(data.metadata)
        {
            if (data.values)
            {
                values = data.values->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "thresholdId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->thresholdId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "values") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->values.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            *this->values += json->GetInt64();
                        }
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Threshold() = default;
    Threshold(const Threshold& threshold) = default;
    Threshold(Threshold&& threshold) = default;
    ~Threshold() = default;

    Threshold& operator=(const Threshold& threshold) = default;
    Threshold& operator=(Threshold&& threshold) = default;

    Threshold deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Threshold);
    }

    const Threshold* operator->() const
    {
        return this;
    }

    Threshold* operator->()
    {
        return this;
    }
    /**
     * しきい値IDを取得
     *
     * @return しきい値ID
     */
    const optional<StringHolder>& getThresholdId() const
    {
        return ensureData().thresholdId;
    }

    /**
     * しきい値IDを設定
     *
     * @param thresholdId しきい値ID
     */
    void setThresholdId(StringHolder thresholdId)
    {
        ensureData().thresholdId.emplace(std::move(thresholdId));
    }

    /**
     * しきい値IDを設定
     *
     * @param thresholdId しきい値ID
     */
    Threshold& withThresholdId(StringHolder thresholdId)
    {
        setThresholdId(std::move(thresholdId));
        return *this;
    }

    /**
     * ランクアップ閾値のメタデータを取得
     *
     * @return ランクアップ閾値のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * ランクアップ閾値のメタデータを設定
     *
     * @param metadata ランクアップ閾値のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * ランクアップ閾値のメタデータを設定
     *
     * @param metadata ランクアップ閾値のメタデータ
     */
    Threshold& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * ランクアップ経験値閾値リストを取得
     *
     * @return ランクアップ経験値閾値リスト
     */
    const optional<List<Int64>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランクアップ経験値閾値リストを設定
     *
     * @param values ランクアップ経験値閾値リスト
     */
    void setValues(List<Int64> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランクアップ経験値閾値リストを設定
     *
     * @param values ランクアップ経験値閾値リスト
     */
    Threshold& withValues(List<Int64> values)
    {
        setValues(std::move(values));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Threshold& lhs, const Threshold& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->thresholdId != lhr.m_pData->thresholdId)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->values != lhr.m_pData->values)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Threshold& lhs, const Threshold& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_THRESHOLD_HPP_