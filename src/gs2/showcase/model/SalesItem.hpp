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

#ifndef GS2_SHOWCASE_MODEL_SALESITEM_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEM_HPP_

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
 * 商品
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItem : public Gs2Object
{
    friend bool operator!=(const SalesItem& lhs, const SalesItem& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品名 */
        optional<StringHolder> name;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            metadata(data.metadata),
            consumeActions(data.consumeActions),
            acquireActions(data.acquireActions)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            consumeActions(std::move(data.consumeActions)),
            acquireActions(std::move(data.acquireActions))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
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
    SalesItem() :
        m_pData(nullptr)
    {}

    SalesItem(const SalesItem& salesItem) :
        Gs2Object(salesItem),
        m_pData(salesItem.m_pData != nullptr ? new Data(*salesItem.m_pData) : nullptr)
    {}

    SalesItem(SalesItem&& salesItem) :
        Gs2Object(std::move(salesItem)),
        m_pData(salesItem.m_pData)
    {
        salesItem.m_pData = nullptr;
    }

    ~SalesItem()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SalesItem& operator=(const SalesItem& salesItem)
    {
        Gs2Object::operator=(salesItem);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*salesItem.m_pData);

        return *this;
    }

    SalesItem& operator=(SalesItem&& salesItem)
    {
        Gs2Object::operator=(std::move(salesItem));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = salesItem.m_pData;
        salesItem.m_pData = nullptr;

        return *this;
    }

    const SalesItem* operator->() const
    {
        return this;
    }

    SalesItem* operator->()
    {
        return this;
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
    SalesItem& withName(const Char* name)
    {
        setName(name);
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
    SalesItem& withMetadata(const Char* metadata)
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
    SalesItem& withConsumeActions(const List<ConsumeAction>& consumeActions)
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
    SalesItem& withAcquireActions(const List<AcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SalesItem& lhs, const SalesItem& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->consumeActions != lhr.m_pData->consumeActions)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SalesItem& lhs, const SalesItem& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEM_HPP_