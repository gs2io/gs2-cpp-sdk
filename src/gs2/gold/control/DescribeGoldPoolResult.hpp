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

#ifndef GS2_GOLD_CONTROL_DESCRIBEGOLDPOOLRESULT_HPP_
#define GS2_GOLD_CONTROL_DESCRIBEGOLDPOOLRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gold
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeGoldPoolResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゴールドプール */
        optional<List<GoldPool>> items;
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
                        GoldPool item;
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
    DescribeGoldPoolResult() :
        m_pData(nullptr)
    {}

    DescribeGoldPoolResult(const DescribeGoldPoolResult& describeGoldPoolResult) :
        Gs2Object(describeGoldPoolResult),
        m_pData(describeGoldPoolResult.m_pData != nullptr ? new Data(*describeGoldPoolResult.m_pData) : nullptr)
    {}

    DescribeGoldPoolResult(DescribeGoldPoolResult&& describeGoldPoolResult) :
        Gs2Object(std::move(describeGoldPoolResult)),
        m_pData(describeGoldPoolResult.m_pData)
    {
        describeGoldPoolResult.m_pData = nullptr;
    }

    ~DescribeGoldPoolResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeGoldPoolResult& operator=(const DescribeGoldPoolResult& describeGoldPoolResult)
    {
        Gs2Object::operator=(describeGoldPoolResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeGoldPoolResult.m_pData);

        return *this;
    }

    DescribeGoldPoolResult& operator=(DescribeGoldPoolResult&& describeGoldPoolResult)
    {
        Gs2Object::operator=(std::move(describeGoldPoolResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeGoldPoolResult.m_pData;
        describeGoldPoolResult.m_pData = nullptr;

        return *this;
    }

    const DescribeGoldPoolResult* operator->() const
    {
        return this;
    }

    DescribeGoldPoolResult* operator->()
    {
        return this;
    }


    /**
     * ゴールドプールを取得
     *
     * @return ゴールドプール
     */
    const optional<List<GoldPool>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ゴールドプールを設定
     *
     * @param items ゴールドプール
     */
    void setItems(const List<GoldPool>& items)
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

#endif //GS2_GOLD_CONTROL_DESCRIBEGOLDPOOLRESULT_HPP_