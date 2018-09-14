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

#ifndef GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASEITEMMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASEITEMMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeShowcaseItemMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列商品 */
        optional<List<ShowcaseItemMaster>> items;
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
                        ShowcaseItemMaster item;
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
    DescribeShowcaseItemMasterResult() :
        m_pData(nullptr)
    {}

    DescribeShowcaseItemMasterResult(const DescribeShowcaseItemMasterResult& describeShowcaseItemMasterResult) :
        Gs2Object(describeShowcaseItemMasterResult),
        m_pData(describeShowcaseItemMasterResult.m_pData != nullptr ? new Data(*describeShowcaseItemMasterResult.m_pData) : nullptr)
    {}

    DescribeShowcaseItemMasterResult(DescribeShowcaseItemMasterResult&& describeShowcaseItemMasterResult) :
        Gs2Object(std::move(describeShowcaseItemMasterResult)),
        m_pData(describeShowcaseItemMasterResult.m_pData)
    {
        describeShowcaseItemMasterResult.m_pData = nullptr;
    }

    ~DescribeShowcaseItemMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeShowcaseItemMasterResult& operator=(const DescribeShowcaseItemMasterResult& describeShowcaseItemMasterResult)
    {
        Gs2Object::operator=(describeShowcaseItemMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeShowcaseItemMasterResult.m_pData);

        return *this;
    }

    DescribeShowcaseItemMasterResult& operator=(DescribeShowcaseItemMasterResult&& describeShowcaseItemMasterResult)
    {
        Gs2Object::operator=(std::move(describeShowcaseItemMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeShowcaseItemMasterResult.m_pData;
        describeShowcaseItemMasterResult.m_pData = nullptr;

        return *this;
    }

    const DescribeShowcaseItemMasterResult* operator->() const
    {
        return this;
    }

    DescribeShowcaseItemMasterResult* operator->()
    {
        return this;
    }


    /**
     * 陳列商品を取得
     *
     * @return 陳列商品
     */
    const optional<List<ShowcaseItemMaster>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 陳列商品を設定
     *
     * @param items 陳列商品
     */
    void setItems(const List<ShowcaseItemMaster>& items)
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

#endif //GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASEITEMMASTERRESULT_HPP_