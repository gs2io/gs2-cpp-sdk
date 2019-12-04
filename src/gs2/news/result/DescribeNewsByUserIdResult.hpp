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

#ifndef GS2_NEWS_CONTROL_DESCRIBENEWSBYUSERIDRESULT_HPP_
#define GS2_NEWS_CONTROL_DESCRIBENEWSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/news/model/model.hpp>
#include <memory>

namespace gs2 { namespace news
{

/**
 * ユーザIDを指定してお知らせ記事の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeNewsByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** お知らせ記事のリスト */
        optional<List<News>> items;
        /** お知らせ記事データのハッシュ値 */
        optional<StringHolder> contentHash;
        /** テンプレートデータのハッシュ値 */
        optional<StringHolder> templateHash;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            contentHash(data.contentHash),
            templateHash(data.templateHash)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        News item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "contentHash") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->contentHash.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "templateHash") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->templateHash.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeNewsByUserIdResult() = default;
    DescribeNewsByUserIdResult(const DescribeNewsByUserIdResult& describeNewsByUserIdResult) = default;
    DescribeNewsByUserIdResult(DescribeNewsByUserIdResult&& describeNewsByUserIdResult) = default;
    ~DescribeNewsByUserIdResult() = default;

    DescribeNewsByUserIdResult& operator=(const DescribeNewsByUserIdResult& describeNewsByUserIdResult) = default;
    DescribeNewsByUserIdResult& operator=(DescribeNewsByUserIdResult&& describeNewsByUserIdResult) = default;

    DescribeNewsByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeNewsByUserIdResult);
    }

    const DescribeNewsByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeNewsByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * お知らせ記事のリストを取得
     *
     * @return お知らせ記事のリスト
     */
    const optional<List<News>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * お知らせ記事のリストを設定
     *
     * @param items お知らせ記事のリスト
     */
    void setItems(List<News> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * お知らせ記事データのハッシュ値を取得
     *
     * @return お知らせ記事データのハッシュ値
     */
    const optional<StringHolder>& getContentHash() const
    {
        return ensureData().contentHash;
    }

    /**
     * お知らせ記事データのハッシュ値を設定
     *
     * @param contentHash お知らせ記事データのハッシュ値
     */
    void setContentHash(StringHolder contentHash)
    {
        ensureData().contentHash.emplace(std::move(contentHash));
    }

    /**
     * テンプレートデータのハッシュ値を取得
     *
     * @return テンプレートデータのハッシュ値
     */
    const optional<StringHolder>& getTemplateHash() const
    {
        return ensureData().templateHash;
    }

    /**
     * テンプレートデータのハッシュ値を設定
     *
     * @param templateHash テンプレートデータのハッシュ値
     */
    void setTemplateHash(StringHolder templateHash)
    {
        ensureData().templateHash.emplace(std::move(templateHash));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeNewsByUserIdResult> AsyncDescribeNewsByUserIdResult;

} }

#endif //GS2_NEWS_CONTROL_DESCRIBENEWSBYUSERIDRESULT_HPP_