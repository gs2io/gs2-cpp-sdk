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

#ifndef GS2_CHAT_CONTROL_SEARCHLOGBYROOMRESULT_HPP_
#define GS2_CHAT_CONTROL_SEARCHLOGBYROOMRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class SearchLogByRoomResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージログ */
        optional<List<MessageLog>> items;
        /** 次のページを読み込むためのトークン */
        optional<StringHolder> nextPageToken;
        /** 検索時にスキャンしたログデータサイズ */
        optional<Int64> scanSize;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            nextPageToken(data.nextPageToken),
            scanSize(data.scanSize)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            nextPageToken(std::move(data.nextPageToken)),
            scanSize(std::move(data.scanSize))
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
                        MessageLog item;
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
            else if (std::strcmp(name, "scanSize") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->scanSize = jsonValue.GetInt64();
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
    SearchLogByRoomResult() :
        m_pData(nullptr)
    {}

    SearchLogByRoomResult(const SearchLogByRoomResult& searchLogByRoomResult) :
        Gs2Object(searchLogByRoomResult),
        m_pData(searchLogByRoomResult.m_pData != nullptr ? new Data(*searchLogByRoomResult.m_pData) : nullptr)
    {}

    SearchLogByRoomResult(SearchLogByRoomResult&& searchLogByRoomResult) :
        Gs2Object(std::move(searchLogByRoomResult)),
        m_pData(searchLogByRoomResult.m_pData)
    {
        searchLogByRoomResult.m_pData = nullptr;
    }

    ~SearchLogByRoomResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SearchLogByRoomResult& operator=(const SearchLogByRoomResult& searchLogByRoomResult)
    {
        Gs2Object::operator=(searchLogByRoomResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*searchLogByRoomResult.m_pData);

        return *this;
    }

    SearchLogByRoomResult& operator=(SearchLogByRoomResult&& searchLogByRoomResult)
    {
        Gs2Object::operator=(std::move(searchLogByRoomResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = searchLogByRoomResult.m_pData;
        searchLogByRoomResult.m_pData = nullptr;

        return *this;
    }

    const SearchLogByRoomResult* operator->() const
    {
        return this;
    }

    SearchLogByRoomResult* operator->()
    {
        return this;
    }


    /**
     * メッセージログを取得
     *
     * @return メッセージログ
     */
    const optional<List<MessageLog>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * メッセージログを設定
     *
     * @param items メッセージログ
     */
    void setItems(const List<MessageLog>& items)
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

    /**
     * 検索時にスキャンしたログデータサイズを取得
     *
     * @return 検索時にスキャンしたログデータサイズ
     */
    const optional<Int64>& getScanSize() const
    {
        return ensureData().scanSize;
    }

    /**
     * 検索時にスキャンしたログデータサイズを設定
     *
     * @param scanSize 検索時にスキャンしたログデータサイズ
     */
    void setScanSize(Int64 scanSize)
    {
        ensureData().scanSize.emplace(scanSize);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_CONTROL_SEARCHLOGBYROOMRESULT_HPP_