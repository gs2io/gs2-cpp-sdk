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

#ifndef GS2_EZ_ENHANCE_EZGETPROGRESSRESULT_HPP_
#define GS2_EZ_ENHANCE_EZGETPROGRESSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/enhance/result/GetProgressResult.hpp>


namespace gs2 { namespace ez { namespace enhance {

class EzGetProgressResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化実行 */
        EzProgress item;
        /** 強化レートモデル */
        EzRateModel rateModel;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
            rateModel = data.rateModel.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::enhance::GetProgressResult& getProgressResult) :
            item(getProgressResult.getItem()),
            rateModel(getProgressResult.getRateModel())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetProgressResult() = default;
    EzGetProgressResult(const EzGetProgressResult& result) = default;
    EzGetProgressResult(EzGetProgressResult&& result) = default;
    ~EzGetProgressResult() = default;

    EzGetProgressResult(gs2::enhance::GetProgressResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetProgressResult& operator=(const EzGetProgressResult& result) = default;
    EzGetProgressResult& operator=(EzGetProgressResult&& result) = default;

    EzGetProgressResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetProgressResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzProgress& getItem() const
    {
        return ensureData().item;
    }

    const EzRateModel& getRateModel() const
    {
        return ensureData().rateModel;
    }
};

typedef gs2::AsyncResult<EzGetProgressResult> AsyncEzGetProgressResult;

}}}

#endif //GS2_EZ_ENHANCE_EZGETPROGRESSRESULT_HPP_