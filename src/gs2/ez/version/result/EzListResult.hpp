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

#ifndef GS2_EZ_VERSION_EZLISTRESULT_HPP_
#define GS2_EZ_VERSION_EZLISTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/version/result/DescribeAcceptVersionsResult.hpp>


namespace gs2 { namespace ez { namespace version {

class EzListResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 承認したバージョンのリスト */
        List<EzAcceptVersion> items;
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

        Data(const gs2::version::DescribeAcceptVersionsResult& describeAcceptVersionsResult) :
            nextPageToken(describeAcceptVersionsResult.getNextPageToken())
        {
            {
                auto& list = *describeAcceptVersionsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzAcceptVersion(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListResult() = default;
    EzListResult(const EzListResult& result) = default;
    EzListResult(EzListResult&& result) = default;
    ~EzListResult() = default;

    EzListResult(gs2::version::DescribeAcceptVersionsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListResult& operator=(const EzListResult& result) = default;
    EzListResult& operator=(EzListResult&& result) = default;

    EzListResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListResult);
    }

    static bool isConvertible(const gs2::version::DescribeAcceptVersionsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzAcceptVersion>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzListResult> AsyncEzListResult;

}}}

#endif //GS2_EZ_VERSION_EZLISTRESULT_HPP_