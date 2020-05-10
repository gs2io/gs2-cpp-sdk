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

#ifndef GS2_DICTIONARY_MODEL_ENTRYMODELMASTER_HPP_
#define GS2_DICTIONARY_MODEL_ENTRYMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace dictionary {

/**
 * エントリーモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class EntryModelMaster : public Gs2Object
{
    friend bool operator!=(const EntryModelMaster& lhs, const EntryModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** エントリーモデルマスター */
        optional<StringHolder> entryModelId;
        /** エントリーモデル名 */
        optional<StringHolder> name;
        /** エントリーモデルマスターの説明 */
        optional<StringHolder> description;
        /** エントリーモデルのメタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            entryModelId(data.entryModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
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
            if (std::strcmp(name_, "entryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->entryModelId.emplace(jsonValue.GetString());
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
    EntryModelMaster() = default;
    EntryModelMaster(const EntryModelMaster& entryModelMaster) = default;
    EntryModelMaster(EntryModelMaster&& entryModelMaster) = default;
    ~EntryModelMaster() = default;

    EntryModelMaster& operator=(const EntryModelMaster& entryModelMaster) = default;
    EntryModelMaster& operator=(EntryModelMaster&& entryModelMaster) = default;

    EntryModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EntryModelMaster);
    }

    const EntryModelMaster* operator->() const
    {
        return this;
    }

    EntryModelMaster* operator->()
    {
        return this;
    }
    /**
     * エントリーモデルマスターを取得
     *
     * @return エントリーモデルマスター
     */
    const optional<StringHolder>& getEntryModelId() const
    {
        return ensureData().entryModelId;
    }

    /**
     * エントリーモデルマスターを設定
     *
     * @param entryModelId エントリーモデルマスター
     */
    void setEntryModelId(StringHolder entryModelId)
    {
        ensureData().entryModelId.emplace(std::move(entryModelId));
    }

    /**
     * エントリーモデルマスターを設定
     *
     * @param entryModelId エントリーモデルマスター
     */
    EntryModelMaster& withEntryModelId(StringHolder entryModelId)
    {
        setEntryModelId(std::move(entryModelId));
        return *this;
    }

    /**
     * エントリーモデル名を取得
     *
     * @return エントリーモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * エントリーモデル名を設定
     *
     * @param name エントリーモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * エントリーモデル名を設定
     *
     * @param name エントリーモデル名
     */
    EntryModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * エントリーモデルマスターの説明を取得
     *
     * @return エントリーモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * エントリーモデルマスターの説明を設定
     *
     * @param description エントリーモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * エントリーモデルマスターの説明を設定
     *
     * @param description エントリーモデルマスターの説明
     */
    EntryModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * エントリーモデルのメタデータを取得
     *
     * @return エントリーモデルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * エントリーモデルのメタデータを設定
     *
     * @param metadata エントリーモデルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * エントリーモデルのメタデータを設定
     *
     * @param metadata エントリーモデルのメタデータ
     */
    EntryModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    EntryModelMaster& withCreatedAt(Int64 createdAt)
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
    EntryModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const EntryModelMaster& lhs, const EntryModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->entryModelId != lhr.m_pData->entryModelId)
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

inline bool operator==(const EntryModelMaster& lhs, const EntryModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DICTIONARY_MODEL_ENTRYMODELMASTER_HPP_