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

#ifndef GS2_KEY_CONTROL_DESCRIBEKEYSRESULT_HPP_
#define GS2_KEY_CONTROL_DESCRIBEKEYSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * 暗号鍵の一覧を取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeKeysResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 暗号鍵のリスト */
        optional<List<Key>> items;
        /** リストの続きを取得するためのページトークン */
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

        virtual ~Data() = default;

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
                        Key item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
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
    DescribeKeysResult() :
        m_pData(nullptr)
    {}

    DescribeKeysResult(const DescribeKeysResult& describeKeysResult) :
        Gs2Object(describeKeysResult),
        m_pData(describeKeysResult.m_pData != nullptr ? new Data(*describeKeysResult.m_pData) : nullptr)
    {}

    DescribeKeysResult(DescribeKeysResult&& describeKeysResult) :
        Gs2Object(std::move(describeKeysResult)),
        m_pData(describeKeysResult.m_pData)
    {
        describeKeysResult.m_pData = nullptr;
    }

    ~DescribeKeysResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeKeysResult& operator=(const DescribeKeysResult& describeKeysResult)
    {
        Gs2Object::operator=(describeKeysResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeKeysResult.m_pData);

        return *this;
    }

    DescribeKeysResult& operator=(DescribeKeysResult&& describeKeysResult)
    {
        Gs2Object::operator=(std::move(describeKeysResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeKeysResult.m_pData;
        describeKeysResult.m_pData = nullptr;

        return *this;
    }

    const DescribeKeysResult* operator->() const
    {
        return this;
    }

    DescribeKeysResult* operator->()
    {
        return this;
    }
    /**
     * 暗号鍵のリストを取得
     *
     * @return 暗号鍵のリスト
     */
    const optional<List<Key>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 暗号鍵のリストを設定
     *
     * @param items 暗号鍵のリスト
     */
    void setItems(const List<Key>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * リストの続きを取得するためのページトークンを取得
     *
     * @return リストの続きを取得するためのページトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * リストの続きを取得するためのページトークンを設定
     *
     * @param nextPageToken リストの続きを取得するためのページトークン
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

#endif //GS2_KEY_CONTROL_DESCRIBEKEYSRESULT_HPP_