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

#ifndef GS2_INBOX_CONTROL_READMESSAGESRESULT_HPP_
#define GS2_INBOX_CONTROL_READMESSAGESRESULT_HPP_

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
 * @author Game Server Services, Inc.
 */
class ReadMessagesResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<List<Message>> items;
        /** 開封通知のレスポンス内容 */
        optional<StringHolder> cooperationResponse;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            cooperationResponse(data.cooperationResponse)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            cooperationResponse(std::move(data.cooperationResponse))
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
                        Message item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "cooperationResponse") == 0) {
                if (jsonValue.IsString())
                {
                    this->cooperationResponse.emplace(jsonValue.GetString());
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
    ReadMessagesResult() :
        m_pData(nullptr)
    {}

    ReadMessagesResult(const ReadMessagesResult& readMessagesResult) :
        Gs2Object(readMessagesResult),
        m_pData(readMessagesResult.m_pData != nullptr ? new Data(*readMessagesResult.m_pData) : nullptr)
    {}

    ReadMessagesResult(ReadMessagesResult&& readMessagesResult) :
        Gs2Object(std::move(readMessagesResult)),
        m_pData(readMessagesResult.m_pData)
    {
        readMessagesResult.m_pData = nullptr;
    }

    ~ReadMessagesResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ReadMessagesResult& operator=(const ReadMessagesResult& readMessagesResult)
    {
        Gs2Object::operator=(readMessagesResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*readMessagesResult.m_pData);

        return *this;
    }

    ReadMessagesResult& operator=(ReadMessagesResult&& readMessagesResult)
    {
        Gs2Object::operator=(std::move(readMessagesResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = readMessagesResult.m_pData;
        readMessagesResult.m_pData = nullptr;

        return *this;
    }

    const ReadMessagesResult* operator->() const
    {
        return this;
    }

    ReadMessagesResult* operator->()
    {
        return this;
    }


    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<List<Message>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * メッセージを設定
     *
     * @param items メッセージ
     */
    void setItems(const List<Message>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * 開封通知のレスポンス内容を取得
     *
     * @return 開封通知のレスポンス内容
     */
    const optional<StringHolder>& getCooperationResponse() const
    {
        return ensureData().cooperationResponse;
    }

    /**
     * 開封通知のレスポンス内容を設定
     *
     * @param cooperationResponse 開封通知のレスポンス内容
     */
    void setCooperationResponse(const Char* cooperationResponse)
    {
        ensureData().cooperationResponse.emplace(cooperationResponse);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_READMESSAGESRESULT_HPP_