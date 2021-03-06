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

#ifndef GS2_EZ_FORMATION_EZGETMOLDRESULT_HPP_
#define GS2_EZ_FORMATION_EZGETMOLDRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/formation/result/GetMoldResult.hpp>


namespace gs2 { namespace ez { namespace formation {

class EzGetMoldResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 保存したフォーム */
        EzMold item;
        /** フォームの保存領域 */
        EzMoldModel moldModel;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
            moldModel = data.moldModel.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::formation::GetMoldResult& getMoldResult) :
            item(*getMoldResult.getItem()),
            moldModel(*getMoldResult.getMoldModel())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetMoldResult() = default;
    EzGetMoldResult(const EzGetMoldResult& result) = default;
    EzGetMoldResult(EzGetMoldResult&& result) = default;
    ~EzGetMoldResult() = default;

    EzGetMoldResult(gs2::formation::GetMoldResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetMoldResult& operator=(const EzGetMoldResult& result) = default;
    EzGetMoldResult& operator=(EzGetMoldResult&& result) = default;

    EzGetMoldResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetMoldResult);
    }

    static bool isConvertible(const gs2::formation::GetMoldResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getMoldModel().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzMold& getItem() const
    {
        return ensureData().item;
    }

    const EzMoldModel& getMoldModel() const
    {
        return ensureData().moldModel;
    }
};

typedef gs2::AsyncResult<EzGetMoldResult> AsyncEzGetMoldResult;

}}}

#endif //GS2_EZ_FORMATION_EZGETMOLDRESULT_HPP_