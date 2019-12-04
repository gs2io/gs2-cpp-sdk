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

#ifndef GS2_EZ_FORMATION_EZLISTMOLDMODELSRESULT_HPP_
#define GS2_EZ_FORMATION_EZLISTMOLDMODELSRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/formation/result/DescribeMoldModelsResult.hpp>


namespace gs2 { namespace ez { namespace formation {

class EzListMoldModelsResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの保存領域のリスト */
        List<EzMoldModel> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::formation::DescribeMoldModelsResult& describeMoldModelsResult)
        {
            {
                auto& list = *describeMoldModelsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzMoldModel(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListMoldModelsResult() = default;
    EzListMoldModelsResult(const EzListMoldModelsResult& result) = default;
    EzListMoldModelsResult(EzListMoldModelsResult&& result) = default;
    ~EzListMoldModelsResult() = default;

    EzListMoldModelsResult(gs2::formation::DescribeMoldModelsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListMoldModelsResult& operator=(const EzListMoldModelsResult& result) = default;
    EzListMoldModelsResult& operator=(EzListMoldModelsResult&& result) = default;

    EzListMoldModelsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListMoldModelsResult);
    }

    static bool isConvertible(const gs2::formation::DescribeMoldModelsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzMoldModel>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzListMoldModelsResult> AsyncEzListMoldModelsResult;

}}}

#endif //GS2_EZ_FORMATION_EZLISTMOLDMODELSRESULT_HPP_