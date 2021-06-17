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

#ifndef GS2_NEWS_CONTROL_WANTGRANTRESULT_HPP_
#define GS2_NEWS_CONTROL_WANTGRANTRESULT_HPP_

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
 * お知らせ記事に加算 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WantGrantResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** お知らせコンテンツにアクセスするために設定の必要なクッキー のリスト */
        optional<List<SetCookieRequestEntry>> items;
        /** お知らせコンテンツにアクセスするためのURL */
        optional<StringHolder> browserUrl;
        /** ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要 */
        optional<StringHolder> zipUrl;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            browserUrl(data.browserUrl),
            zipUrl(data.zipUrl)
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
                        SetCookieRequestEntry item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "browserUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->browserUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "zipUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->zipUrl.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WantGrantResult() = default;
    WantGrantResult(const WantGrantResult& wantGrantResult) = default;
    WantGrantResult(WantGrantResult&& wantGrantResult) = default;
    ~WantGrantResult() = default;

    WantGrantResult& operator=(const WantGrantResult& wantGrantResult) = default;
    WantGrantResult& operator=(WantGrantResult&& wantGrantResult) = default;

    WantGrantResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WantGrantResult);
    }

    const WantGrantResult* operator->() const
    {
        return this;
    }

    WantGrantResult* operator->()
    {
        return this;
    }
    /**
     * お知らせコンテンツにアクセスするために設定の必要なクッキー のリストを取得
     *
     * @return お知らせコンテンツにアクセスするために設定の必要なクッキー のリスト
     */
    const optional<List<SetCookieRequestEntry>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * お知らせコンテンツにアクセスするために設定の必要なクッキー のリストを設定
     *
     * @param items お知らせコンテンツにアクセスするために設定の必要なクッキー のリスト
     */
    void setItems(List<SetCookieRequestEntry> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * お知らせコンテンツにアクセスするためのURLを取得
     *
     * @return お知らせコンテンツにアクセスするためのURL
     */
    const optional<StringHolder>& getBrowserUrl() const
    {
        return ensureData().browserUrl;
    }

    /**
     * お知らせコンテンツにアクセスするためのURLを設定
     *
     * @param browserUrl お知らせコンテンツにアクセスするためのURL
     */
    void setBrowserUrl(StringHolder browserUrl)
    {
        ensureData().browserUrl.emplace(std::move(browserUrl));
    }

    /**
     * ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要を取得
     *
     * @return ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要
     */
    const optional<StringHolder>& getZipUrl() const
    {
        return ensureData().zipUrl;
    }

    /**
     * ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要を設定
     *
     * @param zipUrl ZIP形式のお知らせコンテンツにアクセスするためのURL Cookieの設定は不要
     */
    void setZipUrl(StringHolder zipUrl)
    {
        ensureData().zipUrl.emplace(std::move(zipUrl));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<WantGrantResult> AsyncWantGrantResult;

} }

#endif //GS2_NEWS_CONTROL_WANTGRANTRESULT_HPP_