/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_CONSUMABLEITEM_CONTROL_DESCRIBEITEMMASTERRESULT_HPP_
#define GS2_CONSUMABLEITEM_CONTROL_DESCRIBEITEMMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace consumableItem
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeItemMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費型アイテム */
        optional<List<ItemMaster>> items;
        /** 次のページを読み込むためのトークン */
        optional<StringHolder> nextPageToken;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            nextPageToken(data.nextPageToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            nextPageToken(std::move(data.nextPageToken))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemMaster item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "nextPageToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->nextPageToken.emplace(jsonValue.GetString());
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
    DescribeItemMasterResult() :
        m_pData(nullptr)
    {}

    DescribeItemMasterResult(const DescribeItemMasterResult& describeItemMasterResult) :
        Gs2Object(describeItemMasterResult),
        m_pData(describeItemMasterResult.m_pData != nullptr ? new Data(*describeItemMasterResult.m_pData) : nullptr)
    {}

    DescribeItemMasterResult(DescribeItemMasterResult&& describeItemMasterResult) :
        Gs2Object(std::move(describeItemMasterResult)),
        m_pData(describeItemMasterResult.m_pData)
    {
        describeItemMasterResult.m_pData = nullptr;
    }

    ~DescribeItemMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeItemMasterResult& operator=(const DescribeItemMasterResult& describeItemMasterResult)
    {
        Gs2Object::operator=(describeItemMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeItemMasterResult.m_pData);

        return *this;
    }

    DescribeItemMasterResult& operator=(DescribeItemMasterResult&& describeItemMasterResult)
    {
        Gs2Object::operator=(std::move(describeItemMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeItemMasterResult.m_pData;
        describeItemMasterResult.m_pData = nullptr;

        return *this;
    }

    const DescribeItemMasterResult* operator->() const
    {
        return this;
    }

    DescribeItemMasterResult* operator->()
    {
        return this;
    }


    /**
     * 消費型アイテムを取得
     *
     * @return 消費型アイテム
     */
    const optional<List<ItemMaster>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 消費型アイテムを設定
     *
     * @param items 消費型アイテム
     */
    void setItems(const List<ItemMaster>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * 次のページを読み込むためのトークンを取得
     *
     * @return 次のページを読み込むためのトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * 次のページを読み込むためのトークンを設定
     *
     * @param nextPageToken 次のページを読み込むためのトークン
     */
    void setNextPageToken(const Char* nextPageToken)
    {
        ensureData().nextPageToken.emplace(nextPageToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CONSUMABLEITEM_CONTROL_DESCRIBEITEMMASTERRESULT_HPP_