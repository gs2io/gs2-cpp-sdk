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

#ifndef GS2_EZ_QUEST_EZDELETEPROGRESSRESULT_HPP_
#define GS2_EZ_QUEST_EZDELETEPROGRESSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/DeleteProgressResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzDeleteProgressResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエスト挑戦 */
        EzProgress item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::DeleteProgressResult& deleteProgressResult) :
            item(*deleteProgressResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDeleteProgressResult() = default;
    EzDeleteProgressResult(const EzDeleteProgressResult& result) = default;
    EzDeleteProgressResult(EzDeleteProgressResult&& result) = default;
    ~EzDeleteProgressResult() = default;

    EzDeleteProgressResult(gs2::quest::DeleteProgressResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzDeleteProgressResult& operator=(const EzDeleteProgressResult& result) = default;
    EzDeleteProgressResult& operator=(EzDeleteProgressResult&& result) = default;

    EzDeleteProgressResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDeleteProgressResult);
    }

    static bool isConvertible(const gs2::quest::DeleteProgressResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzProgress& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzDeleteProgressResult> AsyncEzDeleteProgressResult;

}}}

#endif //GS2_EZ_QUEST_EZDELETEPROGRESSRESULT_HPP_