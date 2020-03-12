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

#ifndef GS2_INBOX_CONTROL_RECEIVEGLOBALMESSAGERESULT_HPP_
#define GS2_INBOX_CONTROL_RECEIVEGLOBALMESSAGERESULT_HPP_

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
 * グローバルメッセージのうちまだ受け取っていないメッセージを受信 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ReceiveGlobalMessageResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 受信したメッセージ一覧 */
        optional<List<Message>> item;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
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
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->item.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Message item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->item += std::move(item);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ReceiveGlobalMessageResult() = default;
    ReceiveGlobalMessageResult(const ReceiveGlobalMessageResult& receiveGlobalMessageResult) = default;
    ReceiveGlobalMessageResult(ReceiveGlobalMessageResult&& receiveGlobalMessageResult) = default;
    ~ReceiveGlobalMessageResult() = default;

    ReceiveGlobalMessageResult& operator=(const ReceiveGlobalMessageResult& receiveGlobalMessageResult) = default;
    ReceiveGlobalMessageResult& operator=(ReceiveGlobalMessageResult&& receiveGlobalMessageResult) = default;

    ReceiveGlobalMessageResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ReceiveGlobalMessageResult);
    }

    const ReceiveGlobalMessageResult* operator->() const
    {
        return this;
    }

    ReceiveGlobalMessageResult* operator->()
    {
        return this;
    }
    /**
     * 受信したメッセージ一覧を取得
     *
     * @return 受信したメッセージ一覧
     */
    const optional<List<Message>>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 受信したメッセージ一覧を設定
     *
     * @param item 受信したメッセージ一覧
     */
    void setItem(List<Message> item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ReceiveGlobalMessageResult> AsyncReceiveGlobalMessageResult;

} }

#endif //GS2_INBOX_CONTROL_RECEIVEGLOBALMESSAGERESULT_HPP_