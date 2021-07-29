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

#ifndef GS2_EZ_SCHEDULE_EZLISTTRIGGERSRESULT_HPP_
#define GS2_EZ_SCHEDULE_EZLISTTRIGGERSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/schedule/result/DescribeTriggersResult.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzListTriggersResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** トリガーのリスト */
        List<EzTrigger> items;
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

        Data(const gs2::schedule::DescribeTriggersResult& describeTriggersResult) :
            nextPageToken(describeTriggersResult.getNextPageToken())
        {
            if (describeTriggersResult.getItems())
            {
                auto& list = *describeTriggersResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzTrigger(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListTriggersResult() = default;
    EzListTriggersResult(const EzListTriggersResult& result) = default;
    EzListTriggersResult(EzListTriggersResult&& result) = default;
    ~EzListTriggersResult() = default;

    EzListTriggersResult(gs2::schedule::DescribeTriggersResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListTriggersResult& operator=(const EzListTriggersResult& result) = default;
    EzListTriggersResult& operator=(EzListTriggersResult&& result) = default;

    EzListTriggersResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListTriggersResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzTrigger>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzListTriggersResult> AsyncEzListTriggersResult;

}}}

#endif //GS2_EZ_SCHEDULE_EZLISTTRIGGERSRESULT_HPP_