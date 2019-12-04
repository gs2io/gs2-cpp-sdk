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

#ifndef GS2_FORMATION_MODEL_FORMMODELMASTER_HPP_
#define GS2_FORMATION_MODEL_FORMMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "SlotModel.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * フォームマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class FormModelMaster : public Gs2Object
{
    friend bool operator!=(const FormModelMaster& lhs, const FormModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォームマスター */
        optional<StringHolder> formModelId;
        /** フォーム名 */
        optional<StringHolder> name;
        /** フォームマスターの説明 */
        optional<StringHolder> description;
        /** フォームのメタデータ */
        optional<StringHolder> metadata;
        /** スロットリスト */
        optional<List<SlotModel>> slots;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            formModelId(data.formModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.slots)
            {
                slots = data.slots->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "formModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->formModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "slots") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->slots.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        SlotModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->slots += std::move(item);
                    }
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
    FormModelMaster() = default;
    FormModelMaster(const FormModelMaster& formModelMaster) = default;
    FormModelMaster(FormModelMaster&& formModelMaster) = default;
    ~FormModelMaster() = default;

    FormModelMaster& operator=(const FormModelMaster& formModelMaster) = default;
    FormModelMaster& operator=(FormModelMaster&& formModelMaster) = default;

    FormModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(FormModelMaster);
    }

    const FormModelMaster* operator->() const
    {
        return this;
    }

    FormModelMaster* operator->()
    {
        return this;
    }
    /**
     * フォームマスターを取得
     *
     * @return フォームマスター
     */
    const optional<StringHolder>& getFormModelId() const
    {
        return ensureData().formModelId;
    }

    /**
     * フォームマスターを設定
     *
     * @param formModelId フォームマスター
     */
    void setFormModelId(StringHolder formModelId)
    {
        ensureData().formModelId.emplace(std::move(formModelId));
    }

    /**
     * フォームマスターを設定
     *
     * @param formModelId フォームマスター
     */
    FormModelMaster& withFormModelId(StringHolder formModelId)
    {
        setFormModelId(std::move(formModelId));
        return *this;
    }

    /**
     * フォーム名を取得
     *
     * @return フォーム名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * フォーム名を設定
     *
     * @param name フォーム名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * フォーム名を設定
     *
     * @param name フォーム名
     */
    FormModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * フォームマスターの説明を取得
     *
     * @return フォームマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * フォームマスターの説明を設定
     *
     * @param description フォームマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * フォームマスターの説明を設定
     *
     * @param description フォームマスターの説明
     */
    FormModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * フォームのメタデータを取得
     *
     * @return フォームのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * フォームのメタデータを設定
     *
     * @param metadata フォームのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * フォームのメタデータを設定
     *
     * @param metadata フォームのメタデータ
     */
    FormModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * スロットリストを取得
     *
     * @return スロットリスト
     */
    const optional<List<SlotModel>>& getSlots() const
    {
        return ensureData().slots;
    }

    /**
     * スロットリストを設定
     *
     * @param slots スロットリスト
     */
    void setSlots(List<SlotModel> slots)
    {
        ensureData().slots.emplace(std::move(slots));
    }

    /**
     * スロットリストを設定
     *
     * @param slots スロットリスト
     */
    FormModelMaster& withSlots(List<SlotModel> slots)
    {
        setSlots(std::move(slots));
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
    FormModelMaster& withCreatedAt(Int64 createdAt)
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
    FormModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const FormModelMaster& lhs, const FormModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->formModelId != lhr.m_pData->formModelId)
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
        if (lhs.m_pData->slots != lhr.m_pData->slots)
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

inline bool operator==(const FormModelMaster& lhs, const FormModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_FORMMODELMASTER_HPP_