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

#ifndef GS2_INBOX_CONTROL_READMESSAGEBYUSERIDRESULT_HPP_
#define GS2_INBOX_CONTROL_READMESSAGEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * ユーザーIDを指定してメッセージを開封 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ReadMessageByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<Message> item;
        /** スタンプシート */
        optional<StringHolder> stampSheet;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            stampSheet(data.stampSheet)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            stampSheet(std::move(data.stampSheet))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "stampSheet") == 0) {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
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
    ReadMessageByUserIdResult() :
        m_pData(nullptr)
    {}

    ReadMessageByUserIdResult(const ReadMessageByUserIdResult& readMessageByUserIdResult) :
        Gs2Object(readMessageByUserIdResult),
        m_pData(readMessageByUserIdResult.m_pData != nullptr ? new Data(*readMessageByUserIdResult.m_pData) : nullptr)
    {}

    ReadMessageByUserIdResult(ReadMessageByUserIdResult&& readMessageByUserIdResult) :
        Gs2Object(std::move(readMessageByUserIdResult)),
        m_pData(readMessageByUserIdResult.m_pData)
    {
        readMessageByUserIdResult.m_pData = nullptr;
    }

    ~ReadMessageByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ReadMessageByUserIdResult& operator=(const ReadMessageByUserIdResult& readMessageByUserIdResult)
    {
        Gs2Object::operator=(readMessageByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*readMessageByUserIdResult.m_pData);

        return *this;
    }

    ReadMessageByUserIdResult& operator=(ReadMessageByUserIdResult&& readMessageByUserIdResult)
    {
        Gs2Object::operator=(std::move(readMessageByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = readMessageByUserIdResult.m_pData;
        readMessageByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const ReadMessageByUserIdResult* operator->() const
    {
        return this;
    }

    ReadMessageByUserIdResult* operator->()
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

    /**
     * スタンプシートを取得
     *
     * @return スタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ReadMessageByUserIdResult> AsyncReadMessageByUserIdResult;

} }

#endif //GS2_INBOX_CONTROL_READMESSAGEBYUSERIDRESULT_HPP_