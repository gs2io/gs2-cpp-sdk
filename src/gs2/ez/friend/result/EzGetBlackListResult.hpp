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

#ifndef GS2_EZ_FRIEND_EZGETBLACKLISTRESULT_HPP_
#define GS2_EZ_FRIEND_EZGETBLACKLISTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/friend/result/DescribeBlackListResult.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzGetBlackListResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ブラックリストに登録されたユーザIDリスト */
        List<StringHolder> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::DescribeBlackListResult& describeBlackListResult) :
            items(*describeBlackListResult.getItems())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetBlackListResult() = default;
    EzGetBlackListResult(const EzGetBlackListResult& result) = default;
    EzGetBlackListResult(EzGetBlackListResult&& result) = default;
    ~EzGetBlackListResult() = default;

    EzGetBlackListResult(gs2::friend_::DescribeBlackListResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetBlackListResult& operator=(const EzGetBlackListResult& result) = default;
    EzGetBlackListResult& operator=(EzGetBlackListResult&& result) = default;

    EzGetBlackListResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetBlackListResult);
    }

    static bool isConvertible(const gs2::friend_::DescribeBlackListResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<StringHolder>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzGetBlackListResult> AsyncEzGetBlackListResult;

}}}

#endif //GS2_EZ_FRIEND_EZGETBLACKLISTRESULT_HPP_