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

#ifndef GS2_NEWS_MODEL_NEWS_HPP_
#define GS2_NEWS_MODEL_NEWS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace news {

/**
 * お知らせ記事
 *
 * @author Game Server Services, Inc.
 *
 */
class News : public Gs2Object
{
    friend bool operator!=(const News& lhs, const News& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** セクション名 */
        optional<StringHolder> section;
        /** コンテンツ名 */
        optional<StringHolder> content;
        /** 記事見出し */
        optional<StringHolder> title;
        /** 配信期間を決定する GS2-Schedule のイベントID */
        optional<StringHolder> scheduleEventId;
        /** タイムスタンプ */
        optional<Int64> timestamp;
        /** Front Matter */
        optional<StringHolder> frontMatter;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            section(data.section),
            content(data.content),
            title(data.title),
            scheduleEventId(data.scheduleEventId),
            timestamp(data.timestamp),
            frontMatter(data.frontMatter)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "section") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->section.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "content") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->content.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "title") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->title.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scheduleEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scheduleEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "timestamp") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->timestamp = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "frontMatter") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->frontMatter.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    News() = default;
    News(const News& news) = default;
    News(News&& news) = default;
    ~News() = default;

    News& operator=(const News& news) = default;
    News& operator=(News&& news) = default;

    News deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(News);
    }

    const News* operator->() const
    {
        return this;
    }

    News* operator->()
    {
        return this;
    }
    /**
     * セクション名を取得
     *
     * @return セクション名
     */
    const optional<StringHolder>& getSection() const
    {
        return ensureData().section;
    }

    /**
     * セクション名を設定
     *
     * @param section セクション名
     */
    void setSection(StringHolder section)
    {
        ensureData().section.emplace(std::move(section));
    }

    /**
     * セクション名を設定
     *
     * @param section セクション名
     */
    News& withSection(StringHolder section)
    {
        setSection(std::move(section));
        return *this;
    }

    /**
     * コンテンツ名を取得
     *
     * @return コンテンツ名
     */
    const optional<StringHolder>& getContent() const
    {
        return ensureData().content;
    }

    /**
     * コンテンツ名を設定
     *
     * @param content コンテンツ名
     */
    void setContent(StringHolder content)
    {
        ensureData().content.emplace(std::move(content));
    }

    /**
     * コンテンツ名を設定
     *
     * @param content コンテンツ名
     */
    News& withContent(StringHolder content)
    {
        setContent(std::move(content));
        return *this;
    }

    /**
     * 記事見出しを取得
     *
     * @return 記事見出し
     */
    const optional<StringHolder>& getTitle() const
    {
        return ensureData().title;
    }

    /**
     * 記事見出しを設定
     *
     * @param title 記事見出し
     */
    void setTitle(StringHolder title)
    {
        ensureData().title.emplace(std::move(title));
    }

    /**
     * 記事見出しを設定
     *
     * @param title 記事見出し
     */
    News& withTitle(StringHolder title)
    {
        setTitle(std::move(title));
        return *this;
    }

    /**
     * 配信期間を決定する GS2-Schedule のイベントIDを取得
     *
     * @return 配信期間を決定する GS2-Schedule のイベントID
     */
    const optional<StringHolder>& getScheduleEventId() const
    {
        return ensureData().scheduleEventId;
    }

    /**
     * 配信期間を決定する GS2-Schedule のイベントIDを設定
     *
     * @param scheduleEventId 配信期間を決定する GS2-Schedule のイベントID
     */
    void setScheduleEventId(StringHolder scheduleEventId)
    {
        ensureData().scheduleEventId.emplace(std::move(scheduleEventId));
    }

    /**
     * 配信期間を決定する GS2-Schedule のイベントIDを設定
     *
     * @param scheduleEventId 配信期間を決定する GS2-Schedule のイベントID
     */
    News& withScheduleEventId(StringHolder scheduleEventId)
    {
        setScheduleEventId(std::move(scheduleEventId));
        return *this;
    }

    /**
     * タイムスタンプを取得
     *
     * @return タイムスタンプ
     */
    const optional<Int64>& getTimestamp() const
    {
        return ensureData().timestamp;
    }

    /**
     * タイムスタンプを設定
     *
     * @param timestamp タイムスタンプ
     */
    void setTimestamp(Int64 timestamp)
    {
        ensureData().timestamp.emplace(timestamp);
    }

    /**
     * タイムスタンプを設定
     *
     * @param timestamp タイムスタンプ
     */
    News& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
        return *this;
    }

    /**
     * Front Matterを取得
     *
     * @return Front Matter
     */
    const optional<StringHolder>& getFrontMatter() const
    {
        return ensureData().frontMatter;
    }

    /**
     * Front Matterを設定
     *
     * @param frontMatter Front Matter
     */
    void setFrontMatter(StringHolder frontMatter)
    {
        ensureData().frontMatter.emplace(std::move(frontMatter));
    }

    /**
     * Front Matterを設定
     *
     * @param frontMatter Front Matter
     */
    News& withFrontMatter(StringHolder frontMatter)
    {
        setFrontMatter(std::move(frontMatter));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const News& lhs, const News& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->section != lhr.m_pData->section)
        {
            return true;
        }
        if (lhs.m_pData->content != lhr.m_pData->content)
        {
            return true;
        }
        if (lhs.m_pData->title != lhr.m_pData->title)
        {
            return true;
        }
        if (lhs.m_pData->scheduleEventId != lhr.m_pData->scheduleEventId)
        {
            return true;
        }
        if (lhs.m_pData->timestamp != lhr.m_pData->timestamp)
        {
            return true;
        }
        if (lhs.m_pData->frontMatter != lhr.m_pData->frontMatter)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const News& lhs, const News& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_NEWS_MODEL_NEWS_HPP_