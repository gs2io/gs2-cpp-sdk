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

#ifndef GS2_EZ_EXCHANGE_EZLISTAWAITSRESULT_HPP_
#define GS2_EZ_EXCHANGE_EZLISTAWAITSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/exchange/result/DescribeAwaitsResult.hpp>


namespace gs2 { namespace ez { namespace exchange {

class EzListAwaitsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換待機のリスト */
        List<EzAwait> items;
        /** 次のページを取得するためのトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            nextPageToken(data.nextPageToken)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::exchange::DescribeAwaitsResult& describeAwaitsResult) :
            nextPageToken(describeAwaitsResult.getNextPageToken())
        {
            if (describeAwaitsResult.getItems())
            {
                auto& list = *describeAwaitsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzAwait(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListAwaitsResult() = default;
    EzListAwaitsResult(const EzListAwaitsResult& result) = default;
    EzListAwaitsResult(EzListAwaitsResult&& result) = default;
    ~EzListAwaitsResult() = default;

    EzListAwaitsResult(gs2::exchange::DescribeAwaitsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListAwaitsResult& operator=(const EzListAwaitsResult& result) = default;
    EzListAwaitsResult& operator=(EzListAwaitsResult&& result) = default;

    EzListAwaitsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListAwaitsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzAwait>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzListAwaitsResult> AsyncEzListAwaitsResult;

}}}

#endif //GS2_EZ_EXCHANGE_EZLISTAWAITSRESULT_HPP_