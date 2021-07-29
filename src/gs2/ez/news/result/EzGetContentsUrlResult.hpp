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

#ifndef GS2_EZ_NEWS_EZGETCONTENTSURLRESULT_HPP_
#define GS2_EZ_NEWS_EZGETCONTENTSURLRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/news/result/WantGrantResult.hpp>


namespace gs2 { namespace ez { namespace news {

class EzGetContentsUrlResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** お知らせコンテンツにアクセスするために設定の必要なクッキー のリスト */
        List<EzSetCookieRequestEntry> items;
        /** お知らせコンテンツにアクセスするためのURL */
        StringHolder browserUrl;
        /** ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要 */
        StringHolder zipUrl;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            browserUrl(data.browserUrl),
            zipUrl(data.zipUrl)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::news::WantGrantResult& wantGrantResult) :
            browserUrl(wantGrantResult.getBrowserUrl() ? *wantGrantResult.getBrowserUrl() : StringHolder()),
            zipUrl(wantGrantResult.getZipUrl() ? *wantGrantResult.getZipUrl() : StringHolder())
        {
            if (wantGrantResult.getItems())
            {
                auto& list = *wantGrantResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzSetCookieRequestEntry(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetContentsUrlResult() = default;
    EzGetContentsUrlResult(const EzGetContentsUrlResult& result) = default;
    EzGetContentsUrlResult(EzGetContentsUrlResult&& result) = default;
    ~EzGetContentsUrlResult() = default;

    EzGetContentsUrlResult(gs2::news::WantGrantResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetContentsUrlResult& operator=(const EzGetContentsUrlResult& result) = default;
    EzGetContentsUrlResult& operator=(EzGetContentsUrlResult&& result) = default;

    EzGetContentsUrlResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetContentsUrlResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzSetCookieRequestEntry>& getItems() const
    {
        return ensureData().items;
    }

    const StringHolder& getBrowserUrl() const
    {
        return ensureData().browserUrl;
    }

    const StringHolder& getZipUrl() const
    {
        return ensureData().zipUrl;
    }
};

typedef gs2::AsyncResult<EzGetContentsUrlResult> AsyncEzGetContentsUrlResult;

}}}

#endif //GS2_EZ_NEWS_EZGETCONTENTSURLRESULT_HPP_