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

#ifndef GS2_EZ_FORMATION_EZGETFORMWITHSIGNATURERESULT_HPP_
#define GS2_EZ_FORMATION_EZGETFORMWITHSIGNATURERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/formation/result/GetFormWithSignatureResult.hpp>


namespace gs2 { namespace ez { namespace formation {

class EzGetFormWithSignatureResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォーム */
        EzForm item;
        /** 署名対象の値 */
        StringHolder body;
        /** 署名 */
        StringHolder signature;
        /** 保存したフォーム */
        EzMold mold;
        /** フォームの保存領域 */
        EzMoldModel moldModel;
        /** フォームモデル */
        EzFormModel formModel;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            body(data.body),
            signature(data.signature)
        {
            item = data.item.deepCopy();
            mold = data.mold.deepCopy();
            moldModel = data.moldModel.deepCopy();
            formModel = data.formModel.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::formation::GetFormWithSignatureResult& getFormWithSignatureResult) :
            item(getFormWithSignatureResult.getItem()),
            body(getFormWithSignatureResult.getBody() ? *getFormWithSignatureResult.getBody() : StringHolder()),
            signature(getFormWithSignatureResult.getSignature() ? *getFormWithSignatureResult.getSignature() : StringHolder()),
            mold(getFormWithSignatureResult.getMold()),
            moldModel(getFormWithSignatureResult.getMoldModel()),
            formModel(getFormWithSignatureResult.getFormModel())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetFormWithSignatureResult() = default;
    EzGetFormWithSignatureResult(const EzGetFormWithSignatureResult& result) = default;
    EzGetFormWithSignatureResult(EzGetFormWithSignatureResult&& result) = default;
    ~EzGetFormWithSignatureResult() = default;

    EzGetFormWithSignatureResult(gs2::formation::GetFormWithSignatureResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetFormWithSignatureResult& operator=(const EzGetFormWithSignatureResult& result) = default;
    EzGetFormWithSignatureResult& operator=(EzGetFormWithSignatureResult&& result) = default;

    EzGetFormWithSignatureResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetFormWithSignatureResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzForm& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getBody() const
    {
        return ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return ensureData().signature;
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

typedef gs2::AsyncResult<EzGetFormWithSignatureResult> AsyncEzGetFormWithSignatureResult;

}}}

#endif //GS2_EZ_FORMATION_EZGETFORMWITHSIGNATURERESULT_HPP_