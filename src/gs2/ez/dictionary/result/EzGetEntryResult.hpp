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

#ifndef GS2_EZ_DICTIONARY_EZGETENTRYRESULT_HPP_
#define GS2_EZ_DICTIONARY_EZGETENTRYRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/dictionary/result/GetEntryResult.hpp>


namespace gs2 { namespace ez { namespace dictionary {

class EzGetEntryResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** エントリー */
        EzEntry item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::dictionary::GetEntryResult& getEntryResult) :
            item(*getEntryResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetEntryResult() = default;
    EzGetEntryResult(const EzGetEntryResult& result) = default;
    EzGetEntryResult(EzGetEntryResult&& result) = default;
    ~EzGetEntryResult() = default;

    EzGetEntryResult(gs2::dictionary::GetEntryResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetEntryResult& operator=(const EzGetEntryResult& result) = default;
    EzGetEntryResult& operator=(EzGetEntryResult&& result) = default;

    EzGetEntryResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetEntryResult);
    }

    static bool isConvertible(const gs2::dictionary::GetEntryResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzEntry& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetEntryResult> AsyncEzGetEntryResult;

}}}

#endif //GS2_EZ_DICTIONARY_EZGETENTRYRESULT_HPP_