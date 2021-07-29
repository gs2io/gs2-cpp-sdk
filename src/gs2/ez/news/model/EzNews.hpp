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

#ifndef GS2_EZ_NEWS_MODEL_EZNEWS_HPP_
#define GS2_EZ_NEWS_MODEL_EZNEWS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace news {

class News;

}

namespace ez { namespace news {

class EzNews : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** セクション名 */
        StringHolder section;
        /** コンテンツ名 */
        StringHolder content;
        /** 記事見出し */
        StringHolder title;
        /** 配信期間を決定する GS2-Schedule のイベントID */
        StringHolder scheduleEventId;
        /** タイムスタンプ */
        Int64 timestamp;
        /** Front Matter */
        StringHolder frontMatter;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::news::News& news);
        Data(const gs2::optional<gs2::news::News>& news);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzNews() = default;
    EzNews(const EzNews& ezNews) = default;
    EzNews(EzNews&& ezNews) = default;
    ~EzNews() = default;

    EzNews(gs2::news::News news);
    EzNews(gs2::optional<gs2::news::News> news);

    EzNews& operator=(const EzNews& ezNews) = default;
    EzNews& operator=(EzNews&& ezNews) = default;

    EzNews deepCopy() const;

    gs2::news::News ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getSection() const
    {
        return ensureData().section;
    }

    const StringHolder& getContent() const
    {
        return ensureData().content;
    }

    const StringHolder& getTitle() const
    {
        return ensureData().title;
    }

    const StringHolder& getScheduleEventId() const
    {
        return ensureData().scheduleEventId;
    }

    Int64 getTimestamp() const
    {
        return ensureData().timestamp;
    }

    const StringHolder& getFrontMatter() const
    {
        return ensureData().frontMatter;
    }

    // ========================================
    //   Setters
    // ========================================

    void setSection(StringHolder section)
    {
        ensureData().section = std::move(section);
    }

    void setContent(StringHolder content)
    {
        ensureData().content = std::move(content);
    }

    void setTitle(StringHolder title)
    {
        ensureData().title = std::move(title);
    }

    void setScheduleEventId(StringHolder scheduleEventId)
    {
        ensureData().scheduleEventId = std::move(scheduleEventId);
    }

    void setTimestamp(Int64 timestamp)
    {
        ensureData().timestamp = timestamp;
    }

    void setFrontMatter(StringHolder frontMatter)
    {
        ensureData().frontMatter = std::move(frontMatter);
    }

    EzNews& withSection(StringHolder section)
    {
        setSection(std::move(section));
        return *this;
    }

    EzNews& withContent(StringHolder content)
    {
        setContent(std::move(content));
        return *this;
    }

    EzNews& withTitle(StringHolder title)
    {
        setTitle(std::move(title));
        return *this;
    }

    EzNews& withScheduleEventId(StringHolder scheduleEventId)
    {
        setScheduleEventId(std::move(scheduleEventId));
        return *this;
    }

    EzNews& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
        return *this;
    }

    EzNews& withFrontMatter(StringHolder frontMatter)
    {
        setFrontMatter(std::move(frontMatter));
        return *this;
    }
};

}}}

#endif //GS2_EZ_NEWS_EZNEWS_HPP_