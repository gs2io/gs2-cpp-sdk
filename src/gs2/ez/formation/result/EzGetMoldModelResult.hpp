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

#ifndef GS2_EZ_FORMATION_EZGETMOLDMODELRESULT_HPP_
#define GS2_EZ_FORMATION_EZGETMOLDMODELRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/formation/result/GetMoldModelResult.hpp>


namespace gs2 { namespace ez { namespace formation {

class EzGetMoldModelResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの保存領域 */
        EzMoldModel item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::formation::GetMoldModelResult& getMoldModelResult) :
            item(getMoldModelResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetMoldModelResult() = default;
    EzGetMoldModelResult(const EzGetMoldModelResult& result) = default;
    EzGetMoldModelResult(EzGetMoldModelResult&& result) = default;
    ~EzGetMoldModelResult() = default;

    EzGetMoldModelResult(gs2::formation::GetMoldModelResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetMoldModelResult& operator=(const EzGetMoldModelResult& result) = default;
    EzGetMoldModelResult& operator=(EzGetMoldModelResult&& result) = default;

    EzGetMoldModelResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetMoldModelResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzMoldModel& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetMoldModelResult> AsyncEzGetMoldModelResult;

}}}

#endif //GS2_EZ_FORMATION_EZGETMOLDMODELRESULT_HPP_