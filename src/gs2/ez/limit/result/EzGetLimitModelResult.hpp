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

#ifndef GS2_EZ_LIMIT_EZGETLIMITMODELRESULT_HPP_
#define GS2_EZ_LIMIT_EZGETLIMITMODELRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/limit/result/GetLimitModelResult.hpp>


namespace gs2 { namespace ez { namespace limit {

class EzGetLimitModelResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 回数制限の種類 */
        EzLimitModel item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::limit::GetLimitModelResult& getLimitModelResult) :
            item(*getLimitModelResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetLimitModelResult() = default;
    EzGetLimitModelResult(const EzGetLimitModelResult& result) = default;
    EzGetLimitModelResult(EzGetLimitModelResult&& result) = default;
    ~EzGetLimitModelResult() = default;

    EzGetLimitModelResult(gs2::limit::GetLimitModelResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetLimitModelResult& operator=(const EzGetLimitModelResult& result) = default;
    EzGetLimitModelResult& operator=(EzGetLimitModelResult&& result) = default;

    EzGetLimitModelResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetLimitModelResult);
    }

    static bool isConvertible(const gs2::limit::GetLimitModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzLimitModel& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetLimitModelResult> AsyncEzGetLimitModelResult;

}}}

#endif //GS2_EZ_LIMIT_EZGETLIMITMODELRESULT_HPP_