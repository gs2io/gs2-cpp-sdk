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

#ifndef GS2_EZ_EXCHANGE_EZGETAWAITRESULT_HPP_
#define GS2_EZ_EXCHANGE_EZGETAWAITRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/exchange/result/GetAwaitResult.hpp>


namespace gs2 { namespace ez { namespace exchange {

class EzGetAwaitResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 交換待機 */
        EzAwait item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::exchange::GetAwaitResult& getAwaitResult) :
            item(getAwaitResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetAwaitResult() = default;
    EzGetAwaitResult(const EzGetAwaitResult& result) = default;
    EzGetAwaitResult(EzGetAwaitResult&& result) = default;
    ~EzGetAwaitResult() = default;

    EzGetAwaitResult(gs2::exchange::GetAwaitResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetAwaitResult& operator=(const EzGetAwaitResult& result) = default;
    EzGetAwaitResult& operator=(EzGetAwaitResult&& result) = default;

    EzGetAwaitResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetAwaitResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzAwait& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetAwaitResult> AsyncEzGetAwaitResult;

}}}

#endif //GS2_EZ_EXCHANGE_EZGETAWAITRESULT_HPP_