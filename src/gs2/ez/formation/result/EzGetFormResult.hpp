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

#ifndef GS2_EZ_FORMATION_EZGETFORMRESULT_HPP_
#define GS2_EZ_FORMATION_EZGETFORMRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/formation/result/GetFormResult.hpp>


namespace gs2 { namespace ez { namespace formation {

class EzGetFormResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォーム */
        EzForm item;
        /** 保存したフォーム */
        EzMold mold;
        /** フォームの保存領域 */
        EzMoldModel moldModel;
        /** フォームモデル */
        EzFormModel formModel;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
            mold = data.mold.deepCopy();
            moldModel = data.moldModel.deepCopy();
            formModel = data.formModel.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::formation::GetFormResult& getFormResult) :
            item(getFormResult.getItem()),
            mold(getFormResult.getMold()),
            moldModel(getFormResult.getMoldModel()),
            formModel(getFormResult.getFormModel())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetFormResult() = default;
    EzGetFormResult(const EzGetFormResult& result) = default;
    EzGetFormResult(EzGetFormResult&& result) = default;
    ~EzGetFormResult() = default;

    EzGetFormResult(gs2::formation::GetFormResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetFormResult& operator=(const EzGetFormResult& result) = default;
    EzGetFormResult& operator=(EzGetFormResult&& result) = default;

    EzGetFormResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetFormResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzForm& getItem() const
    {
        return ensureData().item;
    }

    const EzMold& getMold() const
    {
        return ensureData().mold;
    }

    const EzMoldModel& getMoldModel() const
    {
        return ensureData().moldModel;
    }

    const EzFormModel& getFormModel() const
    {
        return ensureData().formModel;
    }
};

typedef gs2::AsyncResult<EzGetFormResult> AsyncEzGetFormResult;

}}}

#endif //GS2_EZ_FORMATION_EZGETFORMRESULT_HPP_