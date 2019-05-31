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
 * ランクアップ閾値
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
        /** ランクアップ閾値 のGRN */
        optional<StringHolder> thresholdId;
        /** ランクアップ閾値名 */
        optional<StringHolder> name;
        /** ランクアップ閾値の説明 */
        optional<StringHolder> description;
        /** ランクアップ閾値のメタデータ */
        optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        optional<List<Int64>> values;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            thresholdId(data.thresholdId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            values(data.values),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            thresholdId(std::move(data.thresholdId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            values(std::move(data.values)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * ランクアップ閾値の説明を取得
     *
     * @return ランクアップ閾値の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ランクアップ閾値の説明を設定
     *
     * @param description ランクアップ閾値の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ランクアップ閾値の説明を設定
     *
     * @param description ランクアップ閾値の説明
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
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    ThresholdMaster& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    ThresholdMaster& withUpdateAt(Int64 updateAt)
    {
        setUpdateAt(updateAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ThresholdMaster& lhs, const ThresholdMaster& lhr)
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
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->updateAt != lhr.m_pData->updateAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const ThresholdMaster& lhs, const ThresholdMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_THRESHOLDMASTER_HPP_