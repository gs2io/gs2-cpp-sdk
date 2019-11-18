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

#ifndef GS2_EZ_QUEST_EZENDRESULT_HPP_
#define GS2_EZ_QUEST_EZENDRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/quest/result/EndResult.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzEndResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエスト挑戦 */
        EzProgress item;
        /** 報酬付与処理の実行に使用するスタンプシート */
        StringHolder stampSheet;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            stampSheet(data.stampSheet)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::EndResult& endResult) :
            item(*endResult.getItem()),
            stampSheet(*endResult.getStampSheet())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzEndResult() = default;
    EzEndResult(const EzEndResult& result) = default;
    EzEndResult(EzEndResult&& result) = default;
    ~EzEndResult() = default;

    EzEndResult(gs2::quest::EndResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzEndResult& operator=(const EzEndResult& result) = default;
    EzEndResult& operator=(EzEndResult&& result) = default;

    EzEndResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEndResult);
    }

    static bool isConvertible(const gs2::quest::EndResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getStampSheet().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzProgress& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getStampSheet() const
    {
        return ensureData().stampSheet;
    }
};

typedef gs2::AsyncResult<EzEndResult> AsyncEzEndResult;

}}}

#endif //GS2_EZ_QUEST_EZENDRESULT_HPP_