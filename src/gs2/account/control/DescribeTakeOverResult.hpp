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

#ifndef GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeTakeOverResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 引き継ぎ情報 */
        optional<List<TakeOver>> items;
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
                        TakeOver item;
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
    DescribeTakeOverResult() :
        m_pData(nullptr)
    {}

    DescribeTakeOverResult(const DescribeTakeOverResult& describeTakeOverResult) :
        Gs2Object(describeTakeOverResult),
        m_pData(describeTakeOverResult.m_pData != nullptr ? new Data(*describeTakeOverResult.m_pData) : nullptr)
    {}

    DescribeTakeOverResult(DescribeTakeOverResult&& describeTakeOverResult) :
        Gs2Object(std::move(describeTakeOverResult)),
        m_pData(describeTakeOverResult.m_pData)
    {
        describeTakeOverResult.m_pData = nullptr;
    }

    ~DescribeTakeOverResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeTakeOverResult& operator=(const DescribeTakeOverResult& describeTakeOverResult)
    {
        Gs2Object::operator=(describeTakeOverResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeTakeOverResult.m_pData);

        return *this;
    }

    DescribeTakeOverResult& operator=(DescribeTakeOverResult&& describeTakeOverResult)
    {
        Gs2Object::operator=(std::move(describeTakeOverResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeTakeOverResult.m_pData;
        describeTakeOverResult.m_pData = nullptr;

        return *this;
    }

    const DescribeTakeOverResult* operator->() const
    {
        return this;
    }

    DescribeTakeOverResult* operator->()
    {
        return this;
    }


    /**
     * 引き継ぎ情報を取得
     *
     * @return 引き継ぎ情報
     */
    const optional<List<TakeOver>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 引き継ぎ情報を設定
     *
     * @param items 引き継ぎ情報
     */
    void setItems(const List<TakeOver>& items)
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

#endif //GS2_ACCOUNT_CONTROL_DESCRIBETAKEOVERRESULT_HPP_