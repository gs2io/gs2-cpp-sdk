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

#ifndef GS2_FORMATION_MODEL_MOLDMODELMASTER_HPP_
#define GS2_FORMATION_MODEL_MOLDMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * フォームの保存領域マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class MoldModelMaster : public Gs2Object
{
    friend bool operator!=(const MoldModelMaster& lhs, const MoldModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォームの保存領域マスター */
        optional<StringHolder> moldModelId;
        /** フォームの保存領域名 */
        optional<StringHolder> name;
        /** フォームの保存領域マスターの説明 */
        optional<StringHolder> description;
        /** フォームの保存領域のメタデータ */
        optional<StringHolder> metadata;
        /** フォームを保存できる初期キャパシティ */
        optional<Int32> initialMaxCapacity;
        /** フォームを保存できるキャパシティ */
        optional<Int32> maxCapacity;
        /** フォーム名 */
        optional<StringHolder> formModelName;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            moldModelId(data.moldModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            initialMaxCapacity(data.initialMaxCapacity),
            maxCapacity(data.maxCapacity),
            formModelName(data.formModelName),
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
            if (std::strcmp(name_, "moldModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->moldModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "initialMaxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->initialMaxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "formModelName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->formModelName.emplace(jsonValue.GetString());
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
    MoldModelMaster() = default;
    MoldModelMaster(const MoldModelMaster& moldModelMaster) = default;
    MoldModelMaster(MoldModelMaster&& moldModelMaster) = default;
    ~MoldModelMaster() = default;

    MoldModelMaster& operator=(const MoldModelMaster& moldModelMaster) = default;
    MoldModelMaster& operator=(MoldModelMaster&& moldModelMaster) = default;

    MoldModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(MoldModelMaster);
    }

    const MoldModelMaster* operator->() const
    {
        return this;
    }

    MoldModelMaster* operator->()
    {
        return this;
    }
    /**
     * フォームの保存領域マスターを取得
     *
     * @return フォームの保存領域マスター
     */
    const optional<StringHolder>& getMoldModelId() const
    {
        return ensureData().moldModelId;
    }

    /**
     * フォームの保存領域マスターを設定
     *
     * @param moldModelId フォームの保存領域マスター
     */
    void setMoldModelId(StringHolder moldModelId)
    {
        ensureData().moldModelId.emplace(std::move(moldModelId));
    }

    /**
     * フォームの保存領域マスターを設定
     *
     * @param moldModelId フォームの保存領域マスター
     */
    MoldModelMaster& withMoldModelId(StringHolder moldModelId)
    {
        setMoldModelId(std::move(moldModelId));
        return *this;
    }

    /**
     * フォームの保存領域名を取得
     *
     * @return フォームの保存領域名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    MoldModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * フォームの保存領域マスターの説明を取得
     *
     * @return フォームの保存領域マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * フォームの保存領域マスターの説明を設定
     *
     * @param description フォームの保存領域マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * フォームの保存領域マスターの説明を設定
     *
     * @param description フォームの保存領域マスターの説明
     */
    MoldModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * フォームの保存領域のメタデータを取得
     *
     * @return フォームの保存領域のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * フォームの保存領域のメタデータを設定
     *
     * @param metadata フォームの保存領域のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * フォームの保存領域のメタデータを設定
     *
     * @param metadata フォームの保存領域のメタデータ
     */
    MoldModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * フォームを保存できる初期キャパシティを取得
     *
     * @return フォームを保存できる初期キャパシティ
     */
    const optional<Int32>& getInitialMaxCapacity() const
    {
        return ensureData().initialMaxCapacity;
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    void setInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        ensureData().initialMaxCapacity.emplace(initialMaxCapacity);
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    MoldModelMaster& withInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        setInitialMaxCapacity(initialMaxCapacity);
        return *this;
    }

    /**
     * フォームを保存できるキャパシティを取得
     *
     * @return フォームを保存できるキャパシティ
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    MoldModelMaster& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }

    /**
     * フォーム名を取得
     *
     * @return フォーム名
     */
    const optional<StringHolder>& getFormModelName() const
    {
        return ensureData().formModelName;
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    void setFormModelName(StringHolder formModelName)
    {
        ensureData().formModelName.emplace(std::move(formModelName));
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    MoldModelMaster& withFormModelName(StringHolder formModelName)
    {
        setFormModelName(std::move(formModelName));
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
    MoldModelMaster& withCreatedAt(Int64 createdAt)
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
    MoldModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const MoldModelMaster& lhs, const MoldModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->moldModelId != lhr.m_pData->moldModelId)
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
        if (lhs.m_pData->initialMaxCapacity != lhr.m_pData->initialMaxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->formModelName != lhr.m_pData->formModelName)
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

inline bool operator==(const MoldModelMaster& lhs, const MoldModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_MOLDMODELMASTER_HPP_