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

#ifndef GS2_EZ_SHOWCASE_EZGETSHOWCASERESULT_HPP_
#define GS2_EZ_SHOWCASE_EZGETSHOWCASERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/showcase/result/GetShowcaseResult.hpp>


namespace gs2 { namespace ez { namespace showcase {

class EzGetShowcaseResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 陳列棚 */
        EzShowcase item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::showcase::GetShowcaseResult& getShowcaseResult) :
            item(*getShowcaseResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetShowcaseResult() = default;
    EzGetShowcaseResult(const EzGetShowcaseResult& result) = default;
    EzGetShowcaseResult(EzGetShowcaseResult&& result) = default;
    ~EzGetShowcaseResult() = default;

    EzGetShowcaseResult(gs2::showcase::GetShowcaseResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetShowcaseResult& operator=(const EzGetShowcaseResult& result) = default;
    EzGetShowcaseResult& operator=(EzGetShowcaseResult&& result) = default;

    EzGetShowcaseResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetShowcaseResult);
    }

    static bool isConvertible(const gs2::showcase::GetShowcaseResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzShowcase& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetShowcaseResult> AsyncEzGetShowcaseResult;

}}}

#endif //GS2_EZ_SHOWCASE_EZGETSHOWCASERESULT_HPP_