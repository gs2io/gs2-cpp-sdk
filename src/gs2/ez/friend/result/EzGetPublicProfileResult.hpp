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

#ifndef GS2_EZ_FRIEND_EZGETPUBLICPROFILERESULT_HPP_
#define GS2_EZ_FRIEND_EZGETPUBLICPROFILERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/friend/result/GetPublicProfileResult.hpp>


namespace gs2 { namespace ez { namespace friend_ {

class EzGetPublicProfileResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 公開プロフィール */
        EzPublicProfile item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::friend_::GetPublicProfileResult& getPublicProfileResult) :
            item(getPublicProfileResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetPublicProfileResult() = default;
    EzGetPublicProfileResult(const EzGetPublicProfileResult& result) = default;
    EzGetPublicProfileResult(EzGetPublicProfileResult&& result) = default;
    ~EzGetPublicProfileResult() = default;

    EzGetPublicProfileResult(gs2::friend_::GetPublicProfileResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetPublicProfileResult& operator=(const EzGetPublicProfileResult& result) = default;
    EzGetPublicProfileResult& operator=(EzGetPublicProfileResult&& result) = default;

    EzGetPublicProfileResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetPublicProfileResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const EzPublicProfile& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzGetPublicProfileResult> AsyncEzGetPublicProfileResult;

}}}

#endif //GS2_EZ_FRIEND_EZGETPUBLICPROFILERESULT_HPP_