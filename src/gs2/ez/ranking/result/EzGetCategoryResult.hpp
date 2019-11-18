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

#ifndef GS2_EZ_RANKING_EZGETCATEGORYRESULT_HPP_
#define GS2_EZ_RANKING_EZGETCATEGORYRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/GetCategoryModelResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzGetCategoryResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カテゴリ */
        EzCategoryModel item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::GetCategoryModelResult& getCategoryModelResult) :
            item(*getCategoryModelResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetCategoryResult() = default;
    EzGetCategoryResult(const EzGetCategoryResult& result) = default;
    EzGetCategoryResult(EzGetCategoryResult&& result) = default;
    ~EzGetCategoryResult() = default;

    EzGetCategoryResult(gs2::ranking::GetCategoryModelResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetCategoryResult& operator=(const EzGetCategoryResult& result) = default;
    EzGetCategoryResult& operator=(EzGetCategoryResult&& result) = default;

    EzGetCategoryResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetCategoryResult);
    }

    static bool isConvertible(const gs2::ranking::GetCategoryModelResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzCategoryModel& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetCategoryResult> AsyncEzGetCategoryResult;

}}}

#endif //GS2_EZ_RANKING_EZGETCATEGORYRESULT_HPP_