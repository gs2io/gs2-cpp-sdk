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

#ifndef GS2_INBOX_CONTROL_GETMESSAGESBYUSERIDRESULT_HPP_
#define GS2_INBOX_CONTROL_GETMESSAGESBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * メッセージを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMessagesByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージのリスト */
        optional<List<Message>> items;
        /** Noneのリスト */
        optional<List<NotGetMessage>> notGetItems;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            notGetItems(data.notGetItems)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            notGetItems(std::move(data.notGetItems))
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
                        Message item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "notGetItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->notGetItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        NotGetMessage item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->notGetItems += std::move(item);
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
    GetMessagesByUserIdResult() :
        m_pData(nullptr)
    {}

    GetMessagesByUserIdResult(const GetMessagesByUserIdResult& getMessagesByUserIdResult) :
        Gs2Object(getMessagesByUserIdResult),
        m_pData(getMessagesByUserIdResult.m_pData != nullptr ? new Data(*getMessagesByUserIdResult.m_pData) : nullptr)
    {}

    GetMessagesByUserIdResult(GetMessagesByUserIdResult&& getMessagesByUserIdResult) :
        Gs2Object(std::move(getMessagesByUserIdResult)),
        m_pData(getMessagesByUserIdResult.m_pData)
    {
        getMessagesByUserIdResult.m_pData = nullptr;
    }

    ~GetMessagesByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMessagesByUserIdResult& operator=(const GetMessagesByUserIdResult& getMessagesByUserIdResult)
    {
        Gs2Object::operator=(getMessagesByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMessagesByUserIdResult.m_pData);

        return *this;
    }

    GetMessagesByUserIdResult& operator=(GetMessagesByUserIdResult&& getMessagesByUserIdResult)
    {
        Gs2Object::operator=(std::move(getMessagesByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMessagesByUserIdResult.m_pData;
        getMessagesByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetMessagesByUserIdResult* operator->() const
    {
        return this;
    }

    GetMessagesByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * メッセージのリストを取得
     *
     * @return メッセージのリスト
     */
    const optional<List<Message>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * メッセージのリストを設定
     *
     * @param items メッセージのリスト
     */
    void setItems(const List<Message>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * Noneのリストを取得
     *
     * @return Noneのリスト
     */
    const optional<List<NotGetMessage>>& getNotGetItems() const
    {
        return ensureData().notGetItems;
    }

    /**
     * Noneのリストを設定
     *
     * @param notGetItems Noneのリスト
     */
    void setNotGetItems(const List<NotGetMessage>& notGetItems)
    {
        ensureData().notGetItems.emplace(notGetItems);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_GETMESSAGESBYUSERIDRESULT_HPP_