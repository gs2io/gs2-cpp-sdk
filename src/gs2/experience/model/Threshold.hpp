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
#include <gs2/core/external/optional/optional.hpp>
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
        /** ランクアップ閾値 のGRN */
        optional<StringHolder> thresholdId;
        /** ランクアップ閾値名 */
        optional<StringHolder> name;
        /** ランクアップ閾値のメタデータ */
        optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        optional<List<Int64>> values;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            thresholdId(data.thresholdId),
            name(data.name),
            metadata(data.metadata),
            values(data.values)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            thresholdId(std::move(data.thresholdId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            values(std::move(data.values))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "thresholdId") == 0) {
                if (jsonValue.IsString())
                {
                    this->thresholdId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "values") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->values.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            detail::addToList(*this->values, json->GetInt64());
                        }
                    }
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Threshold() :
        m_pData(nullptr)
    {}

    Threshold(const Threshold& threshold) :
        Gs2Object(threshold),
        m_pData(threshold.m_pData != nullptr ? new Data(*threshold.m_pData) : nullptr)
    {}

    Threshold(Threshold&& threshold) :
        Gs2Object(std::move(threshold)),
        m_pData(threshold.m_pData)
    {
        threshold.m_pData = nullptr;
    }

    ~Threshold()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Threshold& operator=(const Threshold& threshold)
    {
        Gs2Object::operator=(threshold);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*threshold.m_pData);

        return *this;
    }

    Threshold& operator=(Threshold&& threshold)
    {
        Gs2Object::operator=(std::move(threshold));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = threshold.m_pData;
        threshold.m_pData = nullptr;

        return *this;
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
     * ランクアップ閾値 のGRNを取得
     *
     * @return ランクアップ閾値 のGRN
     */
    const optional<StringHolder>& getThresholdId() const
    {
        return ensureData().thresholdId;
    }

    /**
     * ランクアップ閾値 のGRNを設定
     *
     * @param thresholdId ランクアップ閾値 のGRN
     */
    void setThresholdId(const Char* thresholdId)
    {
        ensureData().thresholdId.emplace(thresholdId);
    }

    /**
     * ランクアップ閾値 のGRNを設定
     *
     * @param thresholdId ランクアップ閾値 のGRN
     */
    Threshold& withThresholdId(const Char* thresholdId)
    {
        setThresholdId(thresholdId);
        return *this;
    }

    /**
     * ランクアップ閾値名を取得
     *
     * @return ランクアップ閾値名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param name ランクアップ閾値名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param name ランクアップ閾値名
     */
    Threshold& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * ランクアップ閾値のメタデータを設定
     *
     * @param metadata ランクアップ閾値のメタデータ
     */
    Threshold& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setValues(const List<Int64>& values)
    {
        ensureData().values.emplace(values);
    }

    /**
     * ランクアップ経験値閾値リストを設定
     *
     * @param values ランクアップ経験値閾値リスト
     */
    Threshold& withValues(const List<Int64>& values)
    {
        setValues(values);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Threshold& lhs, const Threshold& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->thresholdId != lhr.m_pData->thresholdId)
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
        if (lhs.m_pData->values != lhr.m_pData->values)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Threshold& lhs, const Threshold& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_THRESHOLD_HPP_