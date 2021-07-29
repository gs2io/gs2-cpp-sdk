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

#ifndef GS2_EZ_FRIEND_EZDESCRIBERECEIVEREQUESTSRESULT_HPP_
#define GS2_EZ_FRIEND_EZDESCRIBERECEIVEREQUESTSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/friend/result/DescribeReceiveRequestsResult.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzDescribeReceiveRequestsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フレンドリクエストのリスト */
        List<EzFriendRequest> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::DescribeReceiveRequestsResult& describeReceiveRequestsResult)
        {
            if (describeReceiveRequestsResult.getItems())
            {
                auto& list = *describeReceiveRequestsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzFriendRequest(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDescribeReceiveRequestsResult() = default;
    EzDescribeReceiveRequestsResult(const EzDescribeReceiveRequestsResult& result) = default;
    EzDescribeReceiveRequestsResult(EzDescribeReceiveRequestsResult&& result) = default;
    ~EzDescribeReceiveRequestsResult() = default;

    EzDescribeReceiveRequestsResult(gs2::friend_::DescribeReceiveRequestsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzDescribeReceiveRequestsResult& operator=(const EzDescribeReceiveRequestsResult& result) = default;
    EzDescribeReceiveRequestsResult& operator=(EzDescribeReceiveRequestsResult&& result) = default;

    EzDescribeReceiveRequestsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDescribeReceiveRequestsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzFriendRequest>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzDescribeReceiveRequestsResult> AsyncEzDescribeReceiveRequestsResult;

}}}

#endif //GS2_EZ_FRIEND_EZDESCRIBERECEIVEREQUESTSRESULT_HPP_