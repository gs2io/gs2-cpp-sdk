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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/inbox/model/model.hpp>
#include <memory>

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
        /** スタンプシート */
        optional<StringHolder> stampSheet;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "stampSheet") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ReadMessageResult() = default;
    ReadMessageResult(const ReadMessageResult& readMessageResult) = default;
    ReadMessageResult(ReadMessageResult&& readMessageResult) = default;
    ~ReadMessageResult() = default;

    ReadMessageResult& operator=(const ReadMessageResult& readMessageResult) = default;
    ReadMessageResult& operator=(ReadMessageResult&& readMessageResult) = default;

    ReadMessageResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ReadMessageResult);
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
    void setItem(Message item)
    {
        ensureData().item.emplace(std::move(item));
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
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ReadMessageResult> AsyncReadMessageResult;

} }

#endif //GS2_INBOX_CONTROL_READMESSAGERESULT_HPP_