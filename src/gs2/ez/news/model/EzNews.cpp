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

#include "EzNews.hpp"
#include <gs2/news/model/News.hpp>


namespace gs2 { namespace ez { namespace news {

EzNews::Data::Data(const Data& data) :
    Gs2Object(data),
    section(data.section),
    content(data.content),
    title(data.title),
    scheduleEventId(data.scheduleEventId),
    timestamp(data.timestamp),
    frontMatter(data.frontMatter)
{
}

EzNews::Data::Data(const gs2::news::News& news) :
    section(news.getSection()),
    content(news.getContent()),
    title(news.getTitle()),
    scheduleEventId(news.getScheduleEventId()),
    timestamp(news.getTimestamp() ? *news.getTimestamp() : 0),
    frontMatter(news.getFrontMatter())
{
}

EzNews::EzNews(gs2::news::News news) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(news)
{
}

EzNews EzNews::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzNews);
}

gs2::news::News EzNews::ToModel() const
{
    gs2::news::News news;
    news.setSection(getSection());
    news.setContent(getContent());
    news.setTitle(getTitle());
    news.setScheduleEventId(getScheduleEventId());
    news.setTimestamp(getTimestamp());
    news.setFrontMatter(getFrontMatter());
    return news;
}

}}}