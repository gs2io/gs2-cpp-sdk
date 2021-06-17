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

#ifndef GS2_DICTIONARY_MODEL_ENTRYMODEL_HPP_
#define GS2_DICTIONARY_MODEL_ENTRYMODEL_HPP_

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
 * エントリーモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class EntryModel : public Gs2Object
{
    friend bool operator!=(const EntryModel& lhs, const EntryModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** エントリーモデルマスター */
        optional<StringHolder> entryModelId;
        /** エントリーの種類名 */
        optional<StringHolder> name;
        /** エントリーの種類のメタデータ */
        optional<StringHolder> metadata;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            entryModelId(data.entryModelId),
            name(data.name),
            metadata(data.metadata)
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
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EntryModel() = default;
    EntryModel(const EntryModel& entryModel) = default;
    EntryModel(EntryModel&& entryModel) = default;
    ~EntryModel() = default;

    EntryModel& operator=(const EntryModel& entryModel) = default;
    EntryModel& operator=(EntryModel&& entryModel) = default;

    EntryModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EntryModel);
    }

    const EntryModel* operator->() const
    {
        return this;
    }

    EntryModel* operator->()
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
    EntryModel& withEntryModelId(StringHolder entryModelId)
    {
        setEntryModelId(std::move(entryModelId));
        return *this;
    }

    /**
     * エントリーの種類名を取得
     *
     * @return エントリーの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * エントリーの種類名を設定
     *
     * @param name エントリーの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * エントリーの種類名を設定
     *
     * @param name エントリーの種類名
     */
    EntryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * エントリーの種類のメタデータを取得
     *
     * @return エントリーの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * エントリーの種類のメタデータを設定
     *
     * @param metadata エントリーの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * エントリーの種類のメタデータを設定
     *
     * @param metadata エントリーの種類のメタデータ
     */
    EntryModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const EntryModel& lhs, const EntryModel& lhr)
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
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const EntryModel& lhs, const EntryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DICTIONARY_MODEL_ENTRYMODEL_HPP_