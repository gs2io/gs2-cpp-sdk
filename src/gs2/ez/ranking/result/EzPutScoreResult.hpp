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

#ifndef GS2_EZ_RANKING_EZPUTSCORERESULT_HPP_
#define GS2_EZ_RANKING_EZPUTSCORERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/PutScoreResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzPutScoreResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 登録したスコア */
        EzScore item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::PutScoreResult& putScoreResult) :
            item(putScoreResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzPutScoreResult() = default;
    EzPutScoreResult(const EzPutScoreResult& result) = default;
    EzPutScoreResult(EzPutScoreResult&& result) = default;
    ~EzPutScoreResult() = default;

    EzPutScoreResult(gs2::ranking::PutScoreResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzPutScoreResult& operator=(const EzPutScoreResult& result) = default;
    EzPutScoreResult& operator=(EzPutScoreResult&& result) = default;

    EzPutScoreResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzPutScoreResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzScore& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzPutScoreResult> AsyncEzPutScoreResult;

}}}

#endif //GS2_EZ_RANKING_EZPUTSCORERESULT_HPP_