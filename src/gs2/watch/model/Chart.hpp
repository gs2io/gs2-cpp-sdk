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

#ifndef GS2_WATCH_MODEL_CHART_HPP_
#define GS2_WATCH_MODEL_CHART_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * チャート
 *
 * @author Game Server Services, Inc.
 *
 */
class Chart : public Gs2Object
{
    friend bool operator!=(const Chart& lhs, const Chart& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** Datadog のJSON 形式のグラフ定義 */
        optional<StringHolder> chartId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** Datadog から払い出された組み込みID */
        optional<StringHolder> embedId;
        /** Datadog から払い出された組み込み用HTML */
        optional<StringHolder> html;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            chartId(data.chartId),
            ownerId(data.ownerId),
            embedId(data.embedId),
            html(data.html)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "chartId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->chartId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "embedId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->embedId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "html") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->html.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Chart() = default;
    Chart(const Chart& chart) = default;
    Chart(Chart&& chart) = default;
    ~Chart() = default;

    Chart& operator=(const Chart& chart) = default;
    Chart& operator=(Chart&& chart) = default;

    Chart deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Chart);
    }

    const Chart* operator->() const
    {
        return this;
    }

    Chart* operator->()
    {
        return this;
    }
    /**
     * Datadog のJSON 形式のグラフ定義を取得
     *
     * @return Datadog のJSON 形式のグラフ定義
     */
    const optional<StringHolder>& getChartId() const
    {
        return ensureData().chartId;
    }

    /**
     * Datadog のJSON 形式のグラフ定義を設定
     *
     * @param chartId Datadog のJSON 形式のグラフ定義
     */
    void setChartId(StringHolder chartId)
    {
        ensureData().chartId.emplace(std::move(chartId));
    }

    /**
     * Datadog のJSON 形式のグラフ定義を設定
     *
     * @param chartId Datadog のJSON 形式のグラフ定義
     */
    Chart& withChartId(StringHolder chartId)
    {
        setChartId(std::move(chartId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Chart& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * Datadog から払い出された組み込みIDを取得
     *
     * @return Datadog から払い出された組み込みID
     */
    const optional<StringHolder>& getEmbedId() const
    {
        return ensureData().embedId;
    }

    /**
     * Datadog から払い出された組み込みIDを設定
     *
     * @param embedId Datadog から払い出された組み込みID
     */
    void setEmbedId(StringHolder embedId)
    {
        ensureData().embedId.emplace(std::move(embedId));
    }

    /**
     * Datadog から払い出された組み込みIDを設定
     *
     * @param embedId Datadog から払い出された組み込みID
     */
    Chart& withEmbedId(StringHolder embedId)
    {
        setEmbedId(std::move(embedId));
        return *this;
    }

    /**
     * Datadog から払い出された組み込み用HTMLを取得
     *
     * @return Datadog から払い出された組み込み用HTML
     */
    const optional<StringHolder>& getHtml() const
    {
        return ensureData().html;
    }

    /**
     * Datadog から払い出された組み込み用HTMLを設定
     *
     * @param html Datadog から払い出された組み込み用HTML
     */
    void setHtml(StringHolder html)
    {
        ensureData().html.emplace(std::move(html));
    }

    /**
     * Datadog から払い出された組み込み用HTMLを設定
     *
     * @param html Datadog から払い出された組み込み用HTML
     */
    Chart& withHtml(StringHolder html)
    {
        setHtml(std::move(html));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Chart& lhs, const Chart& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->chartId != lhr.m_pData->chartId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->embedId != lhr.m_pData->embedId)
        {
            return true;
        }
        if (lhs.m_pData->html != lhr.m_pData->html)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Chart& lhs, const Chart& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_WATCH_MODEL_CHART_HPP_