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

#ifndef GS2_EZ_STAMINA_EZLISTSTAMINAMODELSRESULT_HPP_
#define GS2_EZ_STAMINA_EZLISTSTAMINAMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/stamina/result/DescribeStaminaModelsResult.hpp>


namespace gs2 { namespace ez { namespace stamina {

class EzListStaminaModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタミナモデルのリスト */
        List<EzStaminaModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::stamina::DescribeStaminaModelsResult& describeStaminaModelsResult)
        {
            if (describeStaminaModelsResult.getItems())
            {
                auto& list = *describeStaminaModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzStaminaModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListStaminaModelsResult() = default;
    EzListStaminaModelsResult(const EzListStaminaModelsResult& result) = default;
    EzListStaminaModelsResult(EzListStaminaModelsResult&& result) = default;
    ~EzListStaminaModelsResult() = default;

    EzListStaminaModelsResult(gs2::stamina::DescribeStaminaModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListStaminaModelsResult& operator=(const EzListStaminaModelsResult& result) = default;
    EzListStaminaModelsResult& operator=(EzListStaminaModelsResult&& result) = default;

    EzListStaminaModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListStaminaModelsResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzStaminaModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListStaminaModelsResult> AsyncEzListStaminaModelsResult;

}}}

#endif //GS2_EZ_STAMINA_EZLISTSTAMINAMODELSRESULT_HPP_