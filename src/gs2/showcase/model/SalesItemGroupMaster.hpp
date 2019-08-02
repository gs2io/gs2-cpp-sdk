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

#ifndef GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 商品グループマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItemGroupMaster : public Gs2Object
{
    friend bool operator!=(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループマスター */
        optional<StringHolder> salesItemGroupId;
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品グループマスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 商品グループに含める商品リスト */
        optional<List<StringHolder>> salesItemNames;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            salesItemGroupId(data.salesItemGroupId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            salesItemNames(data.salesItemNames),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            salesItemGroupId(std::move(data.salesItemGroupId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            salesItemNames(std::move(data.salesItemNames)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "salesItemGroupId") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesItemGroupId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "salesItemNames") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->salesItemNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->salesItemNames, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
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
    SalesItemGroupMaster() :
        m_pData(nullptr)
    {}

    SalesItemGroupMaster(const SalesItemGroupMaster& salesItemGroupMaster) :
        Gs2Object(salesItemGroupMaster),
        m_pData(salesItemGroupMaster.m_pData != nullptr ? new Data(*salesItemGroupMaster.m_pData) : nullptr)
    {}

    SalesItemGroupMaster(SalesItemGroupMaster&& salesItemGroupMaster) :
        Gs2Object(std::move(salesItemGroupMaster)),
        m_pData(salesItemGroupMaster.m_pData)
    {
        salesItemGroupMaster.m_pData = nullptr;
    }

    ~SalesItemGroupMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SalesItemGroupMaster& operator=(const SalesItemGroupMaster& salesItemGroupMaster)
    {
        Gs2Object::operator=(salesItemGroupMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*salesItemGroupMaster.m_pData);

        return *this;
    }

    SalesItemGroupMaster& operator=(SalesItemGroupMaster&& salesItemGroupMaster)
    {
        Gs2Object::operator=(std::move(salesItemGroupMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = salesItemGroupMaster.m_pData;
        salesItemGroupMaster.m_pData = nullptr;

        return *this;
    }

    const SalesItemGroupMaster* operator->() const
    {
        return this;
    }

    SalesItemGroupMaster* operator->()
    {
        return this;
    }
    /**
     * 商品グループマスターを取得
     *
     * @return 商品グループマスター
     */
    const optional<StringHolder>& getSalesItemGroupId() const
    {
        return ensureData().salesItemGroupId;
    }

    /**
     * 商品グループマスターを設定
     *
     * @param salesItemGroupId 商品グループマスター
     */
    void setSalesItemGroupId(const Char* salesItemGroupId)
    {
        ensureData().salesItemGroupId.emplace(salesItemGroupId);
    }

    /**
     * 商品グループマスターを設定
     *
     * @param salesItemGroupId 商品グループマスター
     */
    SalesItemGroupMaster& withSalesItemGroupId(const Char* salesItemGroupId)
    {
        setSalesItemGroupId(salesItemGroupId);
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    SalesItemGroupMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 商品グループマスターの説明を取得
     *
     * @return 商品グループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 商品グループマスターの説明を設定
     *
     * @param description 商品グループマスターの説明
     */
    SalesItemGroupMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    SalesItemGroupMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 商品グループに含める商品リストを取得
     *
     * @return 商品グループに含める商品リスト
     */
    const optional<List<StringHolder>>& getSalesItemNames() const
    {
        return ensureData().salesItemNames;
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    void setSalesItemNames(const List<StringHolder>& salesItemNames)
    {
        ensureData().salesItemNames.emplace(salesItemNames);
    }

    /**
     * 商品グループに含める商品リストを設定
     *
     * @param salesItemNames 商品グループに含める商品リスト
     */
    SalesItemGroupMaster& withSalesItemNames(const List<StringHolder>& salesItemNames)
    {
        setSalesItemNames(salesItemNames);
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
    SalesItemGroupMaster& withCreatedAt(Int64 createdAt)
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
    SalesItemGroupMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->salesItemGroupId != lhr.m_pData->salesItemGroupId)
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
        if (lhs.m_pData->salesItemNames != lhr.m_pData->salesItemNames)
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

inline bool operator==(const SalesItemGroupMaster& lhs, const SalesItemGroupMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMGROUPMASTER_HPP_