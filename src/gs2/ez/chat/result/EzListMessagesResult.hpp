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

#ifndef GS2_EZ_CHAT_EZLISTMESSAGESRESULT_HPP_
#define GS2_EZ_CHAT_EZLISTMESSAGESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/chat/result/DescribeMessagesResult.hpp>


namespace gs2 { namespace ez { namespace chat {

class EzListMessagesResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** メッセージのリスト */
        List<EzMessage> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::chat::DescribeMessagesResult& describeMessagesResult)
        {
            {
                auto& list = *describeMessagesResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzMessage(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListMessagesResult() = default;
    EzListMessagesResult(const EzListMessagesResult& result) = default;
    EzListMessagesResult(EzListMessagesResult&& result) = default;
    ~EzListMessagesResult() = default;

    EzListMessagesResult(gs2::chat::DescribeMessagesResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListMessagesResult& operator=(const EzListMessagesResult& result) = default;
    EzListMessagesResult& operator=(EzListMessagesResult&& result) = default;

    EzListMessagesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListMessagesResult);
    }

    static bool isConvertible(const gs2::chat::DescribeMessagesResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzMessage>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListMessagesResult> AsyncEzListMessagesResult;

}}}

#endif //GS2_EZ_CHAT_EZLISTMESSAGESRESULT_HPP_