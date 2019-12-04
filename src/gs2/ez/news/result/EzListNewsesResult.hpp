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

#ifndef GS2_EZ_NEWS_EZLISTNEWSESRESULT_HPP_
#define GS2_EZ_NEWS_EZLISTNEWSESRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/news/result/DescribeNewsResult.hpp>


namespace gs2 { namespace ez { namespace news {

class EzListNewsesResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** お知らせ記事のリスト */
        List<EzNews> items;
        /** お知らせ記事データのハッシュ値 */
        StringHolder contentHash;
        /** テンプレートデータのハッシュ値 */
        StringHolder templateHash;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            contentHash(data.contentHash),
            templateHash(data.templateHash)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::news::DescribeNewsResult& describeNewsResult) :
            contentHash(*describeNewsResult.getContentHash()),
            templateHash(*describeNewsResult.getTemplateHash())
        {
            {
                auto& list = *describeNewsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzNews(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzListNewsesResult() = default;
    EzListNewsesResult(const EzListNewsesResult& result) = default;
    EzListNewsesResult(EzListNewsesResult&& result) = default;
    ~EzListNewsesResult() = default;

    EzListNewsesResult(gs2::news::DescribeNewsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzListNewsesResult& operator=(const EzListNewsesResult& result) = default;
    EzListNewsesResult& operator=(EzListNewsesResult&& result) = default;

    EzListNewsesResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzListNewsesResult);
    }

    static bool isConvertible(const gs2::news::DescribeNewsResult& result)
    {
        return
            result.getItems().has_value() &&
            result.getContentHash().has_value() &&
            result.getTemplateHash().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzNews>& getItems() const
    {
        return ensureData().items;
    }

    const StringHolder& getContentHash() const
    {
        return ensureData().contentHash;
    }

    const StringHolder& getTemplateHash() const
    {
        return ensureData().templateHash;
    }
};

typedef gs2::AsyncResult<EzListNewsesResult> AsyncEzListNewsesResult;

}}}

#endif //GS2_EZ_NEWS_EZLISTNEWSESRESULT_HPP_