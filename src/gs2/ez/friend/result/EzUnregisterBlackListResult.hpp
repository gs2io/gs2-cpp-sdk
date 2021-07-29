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

#ifndef GS2_EZ_FRIEND_EZUNREGISTERBLACKLISTRESULT_HPP_
#define GS2_EZ_FRIEND_EZUNREGISTERBLACKLISTRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/friend/result/UnregisterBlackListResult.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzUnregisterBlackListResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ブラックリスト */
        EzBlackList item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::UnregisterBlackListResult& unregisterBlackListResult) :
            item(unregisterBlackListResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzUnregisterBlackListResult() = default;
    EzUnregisterBlackListResult(const EzUnregisterBlackListResult& result) = default;
    EzUnregisterBlackListResult(EzUnregisterBlackListResult&& result) = default;
    ~EzUnregisterBlackListResult() = default;

    EzUnregisterBlackListResult(gs2::friend_::UnregisterBlackListResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzUnregisterBlackListResult& operator=(const EzUnregisterBlackListResult& result) = default;
    EzUnregisterBlackListResult& operator=(EzUnregisterBlackListResult&& result) = default;

    EzUnregisterBlackListResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzUnregisterBlackListResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzBlackList& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzUnregisterBlackListResult> AsyncEzUnregisterBlackListResult;

}}}

#endif //GS2_EZ_FRIEND_EZUNREGISTERBLACKLISTRESULT_HPP_