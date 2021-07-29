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

#ifndef GS2_EZ_CHAT_EZLISTSUBSCRIBEROOMSRESULT_HPP_
#define GS2_EZ_CHAT_EZLISTSUBSCRIBEROOMSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/chat/result/DescribeSubscribesResult.hpp>


namespace gs2 { namespace ez { namespace chat {

class EzListSubscribeRoomsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 購読のリスト */
        List<EzSubscribe> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            nextPageToken(data.nextPageToken)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::chat::DescribeSubscribesResult& describeSubscribesResult) :
            nextPageToken(describeSubscribesResult.getNextPageToken())
        {
            if (describeSubscribesResult.getItems())
            {
                auto& list = *describeSubscribesResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzSubscribe(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListSubscribeRoomsResult() = default;
    EzListSubscribeRoomsResult(const EzListSubscribeRoomsResult& result) = default;
    EzListSubscribeRoomsResult(EzListSubscribeRoomsResult&& result) = default;
    ~EzListSubscribeRoomsResult() = default;

    EzListSubscribeRoomsResult(gs2::chat::DescribeSubscribesResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListSubscribeRoomsResult& operator=(const EzListSubscribeRoomsResult& result) = default;
    EzListSubscribeRoomsResult& operator=(EzListSubscribeRoomsResult&& result) = default;

    EzListSubscribeRoomsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListSubscribeRoomsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzSubscribe>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzListSubscribeRoomsResult> AsyncEzListSubscribeRoomsResult;

}}}

#endif //GS2_EZ_CHAT_EZLISTSUBSCRIBEROOMSRESULT_HPP_