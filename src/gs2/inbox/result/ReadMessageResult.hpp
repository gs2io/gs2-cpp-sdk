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

#ifndef GS2_INBOX_CONTROL_READMESSAGERESULT_HPP_
#define GS2_INBOX_CONTROL_READMESSAGERESULT_HPP_

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
 * メッセージを開封 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ReadMessageResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<Message> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    ReadMessageResult() :
        m_pData(nullptr)
    {}

    ReadMessageResult(const ReadMessageResult& readMessageResult) :
        Gs2Object(readMessageResult),
        m_pData(readMessageResult.m_pData != nullptr ? new Data(*readMessageResult.m_pData) : nullptr)
    {}

    ReadMessageResult(ReadMessageResult&& readMessageResult) :
        Gs2Object(std::move(readMessageResult)),
        m_pData(readMessageResult.m_pData)
    {
        readMessageResult.m_pData = nullptr;
    }

    ~ReadMessageResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ReadMessageResult& operator=(const ReadMessageResult& readMessageResult)
    {
        Gs2Object::operator=(readMessageResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*readMessageResult.m_pData);

        return *this;
    }

    ReadMessageResult& operator=(ReadMessageResult&& readMessageResult)
    {
        Gs2Object::operator=(std::move(readMessageResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = readMessageResult.m_pData;
        readMessageResult.m_pData = nullptr;

        return *this;
    }

    const ReadMessageResult* operator->() const
    {
        return this;
    }

    ReadMessageResult* operator->()
    {
        return this;
    }
    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<Message>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * メッセージを設定
     *
     * @param item メッセージ
     */
    void setItem(const Message& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_READMESSAGERESULT_HPP_