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

#ifndef GS2_SHOWCASE_MODEL_SALESITEMMASTER_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEMMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 商品マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItemMaster : public Gs2Object
{
    friend bool operator!=(const SalesItemMaster& lhs, const SalesItemMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品マスター */
        optional<StringHolder> salesItemId;
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品マスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            salesItemId(data.salesItemId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "salesItemId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->salesItemId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "consumeActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->consumeActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ConsumeAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->consumeActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "acquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->acquireActions, std::move(item));
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
    SalesItemMaster() = default;
    SalesItemMaster(const SalesItemMaster& salesItemMaster) = default;
    SalesItemMaster(SalesItemMaster&& salesItemMaster) = default;
    ~SalesItemMaster() = default;

    SalesItemMaster& operator=(const SalesItemMaster& salesItemMaster) = default;
    SalesItemMaster& operator=(SalesItemMaster&& salesItemMaster) = default;

    SalesItemMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SalesItemMaster);
    }

    const SalesItemMaster* operator->() const
    {
        return this;
    }

    SalesItemMaster* operator->()
    {
        return this;
    }
    /**
     * 商品マスターを取得
     *
     * @return 商品マスター
     */
    const optional<StringHolder>& getSalesItemId() const
    {
        return ensureData().salesItemId;
    }

    /**
     * 商品マスターを設定
     *
     * @param salesItemId 商品マスター
     */
    void setSalesItemId(StringHolder salesItemId)
    {
        ensureData().salesItemId.emplace(std::move(salesItemId));
    }

    /**
     * 商品マスターを設定
     *
     * @param salesItemId 商品マスター
     */
    SalesItemMaster& withSalesItemId(StringHolder salesItemId)
    {
        setSalesItemId(std::move(salesItemId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 商品名を設定
     *
     * @param name 商品名
     */
    SalesItemMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 商品マスターの説明を取得
     *
     * @return 商品マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品マスターの説明を設定
     *
     * @param description 商品マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 商品マスターの説明を設定
     *
     * @param description 商品マスターの説明
     */
    SalesItemMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    SalesItemMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 消費アクションリストを取得
     *
     * @return 消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    SalesItemMaster& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    /**
     * 入手アクションリストを取得
     *
     * @return 入手アクションリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    SalesItemMaster& withAcquireActions(List<AcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
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
    SalesItemMaster& withCreatedAt(Int64 createdAt)
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
    SalesItemMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SalesItemMaster& lhs, const SalesItemMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->salesItemId != lhr.m_pData->salesItemId)
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
        if (lhs.m_pData->consumeActions != lhr.m_pData->consumeActions)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
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

inline bool operator==(const SalesItemMaster& lhs, const SalesItemMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMMASTER_HPP_