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

#ifndef GS2_EXPERIENCE_MODEL_THRESHOLDMASTER_HPP_
#define GS2_EXPERIENCE_MODEL_THRESHOLDMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * ランクアップ閾値マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ThresholdMaster : public Gs2Object
{
    friend bool operator!=(const ThresholdMaster& lhs, const ThresholdMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ランクアップ閾値マスター */
        optional<StringHolder> thresholdId;
        /** ランクアップ閾値名 */
        optional<StringHolder> name;
        /** ランクアップ閾値マスターの説明 */
        optional<StringHolder> description;
        /** ランクアップ閾値のメタデータ */
        optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        optional<List<Int64>> values;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            thresholdId(data.thresholdId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            values(data.values),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            thresholdId(std::move(data.thresholdId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            values(std::move(data.values)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "thresholdId") == 0) {
                if (jsonValue.IsString())
                {
                    this->thresholdId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "values") == 0) {
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
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    ThresholdMaster() :
        m_pData(nullptr)
    {}

    ThresholdMaster(const ThresholdMaster& thresholdMaster) :
        Gs2Object(thresholdMaster),
        m_pData(thresholdMaster.m_pData != nullptr ? new Data(*thresholdMaster.m_pData) : nullptr)
    {}

    ThresholdMaster(ThresholdMaster&& thresholdMaster) :
        Gs2Object(std::move(thresholdMaster)),
        m_pData(thresholdMaster.m_pData)
    {
        thresholdMaster.m_pData = nullptr;
    }

    ~ThresholdMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ThresholdMaster& operator=(const ThresholdMaster& thresholdMaster)
    {
        Gs2Object::operator=(thresholdMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*thresholdMaster.m_pData);

        return *this;
    }

    ThresholdMaster& operator=(ThresholdMaster&& thresholdMaster)
    {
        Gs2Object::operator=(std::move(thresholdMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = thresholdMaster.m_pData;
        thresholdMaster.m_pData = nullptr;

        return *this;
    }

    const ThresholdMaster* operator->() const
    {
        return this;
    }

    ThresholdMaster* operator->()
    {
        return this;
    }
    /**
     * ランクアップ閾値マスターを取得
     *
     * @return ランクアップ閾値マスター
     */
    const optional<StringHolder>& getThresholdId() const
    {
        return ensureData().thresholdId;
    }

    /**
     * ランクアップ閾値マスターを設定
     *
     * @param thresholdId ランクアップ閾値マスター
     */
    void setThresholdId(const Char* thresholdId)
    {
        ensureData().thresholdId.emplace(thresholdId);
    }

    /**
     * ランクアップ閾値マスターを設定
     *
     * @param thresholdId ランクアップ閾値マスター
     */
    ThresholdMaster& withThresholdId(const Char* thresholdId)
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
    ThresholdMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ランクアップ閾値マスターの説明を取得
     *
     * @return ランクアップ閾値マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ランクアップ閾値マスターの説明を設定
     *
     * @param description ランクアップ閾値マスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ランクアップ閾値マスターの説明を設定
     *
     * @param description ランクアップ閾値マスターの説明
     */
    ThresholdMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    ThresholdMaster& withMetadata(const Char* metadata)
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
    ThresholdMaster& withValues(const List<Int64>& values)
    {
        setValues(values);
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
    ThresholdMaster& withCreatedAt(Int64 createdAt)
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
    ThresholdMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ThresholdMaster& lhs, const ThresholdMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
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

inline bool operator==(const ThresholdMaster& lhs, const ThresholdMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_THRESHOLDMASTER_HPP_