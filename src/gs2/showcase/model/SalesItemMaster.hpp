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
#include <gs2/core/external/optional/optional.hpp>
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            salesItemId(data.salesItemId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            consumeActions(data.consumeActions),
            acquireActions(data.acquireActions),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            salesItemId(std::move(data.salesItemId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            consumeActions(std::move(data.consumeActions)),
            acquireActions(std::move(data.acquireActions)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "salesItemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesItemId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "consumeActions") == 0) {
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
            else if (std::strcmp(name, "acquireActions") == 0) {
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
    SalesItemMaster() :
        m_pData(nullptr)
    {}

    SalesItemMaster(const SalesItemMaster& salesItemMaster) :
        Gs2Object(salesItemMaster),
        m_pData(salesItemMaster.m_pData != nullptr ? new Data(*salesItemMaster.m_pData) : nullptr)
    {}

    SalesItemMaster(SalesItemMaster&& salesItemMaster) :
        Gs2Object(std::move(salesItemMaster)),
        m_pData(salesItemMaster.m_pData)
    {
        salesItemMaster.m_pData = nullptr;
    }

    ~SalesItemMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SalesItemMaster& operator=(const SalesItemMaster& salesItemMaster)
    {
        Gs2Object::operator=(salesItemMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*salesItemMaster.m_pData);

        return *this;
    }

    SalesItemMaster& operator=(SalesItemMaster&& salesItemMaster)
    {
        Gs2Object::operator=(std::move(salesItemMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = salesItemMaster.m_pData;
        salesItemMaster.m_pData = nullptr;

        return *this;
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
    void setSalesItemId(const Char* salesItemId)
    {
        ensureData().salesItemId.emplace(salesItemId);
    }

    /**
     * 商品マスターを設定
     *
     * @param salesItemId 商品マスター
     */
    SalesItemMaster& withSalesItemId(const Char* salesItemId)
    {
        setSalesItemId(salesItemId);
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
    SalesItemMaster& withName(const Char* name)
    {
        setName(name);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 商品マスターの説明を設定
     *
     * @param description 商品マスターの説明
     */
    SalesItemMaster& withDescription(const Char* description)
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
    SalesItemMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        ensureData().consumeActions.emplace(consumeActions);
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    SalesItemMaster& withConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        setConsumeActions(consumeActions);
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
    void setAcquireActions(const List<AcquireAction>& acquireActions)
    {
        ensureData().acquireActions.emplace(acquireActions);
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    SalesItemMaster& withAcquireActions(const List<AcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
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

bool operator!=(const SalesItemMaster& lhs, const SalesItemMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const SalesItemMaster& lhs, const SalesItemMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMMASTER_HPP_