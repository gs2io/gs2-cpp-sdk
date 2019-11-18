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

#ifndef GS2_EZ_RANKING_EZUNSUBSCRIBERESULT_HPP_
#define GS2_EZ_RANKING_EZUNSUBSCRIBERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/UnsubscribeResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzUnsubscribeResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 解除した購読対象 */
        EzSubscribeUser item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::UnsubscribeResult& unsubscribeResult) :
            item(*unsubscribeResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzUnsubscribeResult() = default;
    EzUnsubscribeResult(const EzUnsubscribeResult& result) = default;
    EzUnsubscribeResult(EzUnsubscribeResult&& result) = default;
    ~EzUnsubscribeResult() = default;

    EzUnsubscribeResult(gs2::ranking::UnsubscribeResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzUnsubscribeResult& operator=(const EzUnsubscribeResult& result) = default;
    EzUnsubscribeResult& operator=(EzUnsubscribeResult&& result) = default;

    EzUnsubscribeResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzUnsubscribeResult);
    }

    static bool isConvertible(const gs2::ranking::UnsubscribeResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzSubscribeUser& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzUnsubscribeResult> AsyncEzUnsubscribeResult;

}}}

#endif //GS2_EZ_RANKING_EZUNSUBSCRIBERESULT_HPP_