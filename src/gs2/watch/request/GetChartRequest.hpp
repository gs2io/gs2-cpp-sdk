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

#ifndef GS2_WATCH_CONTROL_GETCHARTREQUEST_HPP_
#define GS2_WATCH_CONTROL_GETCHARTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/watch/Gs2WatchConst.hpp>
#include <gs2/watch/model/model.hpp>
#include <memory>

namespace gs2 { namespace watch
{

/**
 * チャートを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetChartRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** 指標 */
        optional<StringHolder> metrics;
        /** リソースのGRN */
        optional<StringHolder> grn;
        /** クエリリスト */
        optional<List<StringHolder>> queries;
        /** グルーピング対象 */
        optional<StringHolder> by;
        /** データの取得期間 */
        optional<StringHolder> timeframe;
        /** グラフのサイズ */
        optional<StringHolder> size;
        /** フォーマット */
        optional<StringHolder> format;
        /** 集計方針 */
        optional<StringHolder> aggregator;
        /** スタイル */
        optional<StringHolder> style;
        /** タイトル */
        optional<StringHolder> title;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            metrics(data.metrics),
            grn(data.grn),
            by(data.by),
            timeframe(data.timeframe),
            size(data.size),
            format(data.format),
            aggregator(data.aggregator),
            style(data.style),
            title(data.title)
        {
            if (data.queries)
            {
                queries = data.queries->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetChartRequest() = default;
    GetChartRequest(const GetChartRequest& getChartRequest) = default;
    GetChartRequest(GetChartRequest&& getChartRequest) = default;
    ~GetChartRequest() GS2_OVERRIDE = default;

    GetChartRequest& operator=(const GetChartRequest& getChartRequest) = default;
    GetChartRequest& operator=(GetChartRequest&& getChartRequest) = default;

    GetChartRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetChartRequest);
    }

    const GetChartRequest* operator->() const
    {
        return this;
    }

    GetChartRequest* operator->()
    {
        return this;
    }

    /**
     * 指標を取得
     *
     * @return 指標
     */
    const optional<StringHolder>& getMetrics() const
    {
        return ensureData().metrics;
    }

    /**
     * 指標を設定
     *
     * @param metrics 指標
     */
    void setMetrics(StringHolder metrics)
    {
        ensureData().metrics.emplace(std::move(metrics));
    }

    /**
     * 指標を設定
     *
     * @param metrics 指標
     */
    GetChartRequest& withMetrics(StringHolder metrics)
    {
        ensureData().metrics.emplace(std::move(metrics));
        return *this;
    }

    /**
     * リソースのGRNを取得
     *
     * @return リソースのGRN
     */
    const optional<StringHolder>& getGrn() const
    {
        return ensureData().grn;
    }

    /**
     * リソースのGRNを設定
     *
     * @param grn リソースのGRN
     */
    void setGrn(StringHolder grn)
    {
        ensureData().grn.emplace(std::move(grn));
    }

    /**
     * リソースのGRNを設定
     *
     * @param grn リソースのGRN
     */
    GetChartRequest& withGrn(StringHolder grn)
    {
        ensureData().grn.emplace(std::move(grn));
        return *this;
    }

    /**
     * クエリリストを取得
     *
     * @return クエリリスト
     */
    const optional<List<StringHolder>>& getQueries() const
    {
        return ensureData().queries;
    }

    /**
     * クエリリストを設定
     *
     * @param queries クエリリスト
     */
    void setQueries(List<StringHolder> queries)
    {
        ensureData().queries.emplace(std::move(queries));
    }

    /**
     * クエリリストを設定
     *
     * @param queries クエリリスト
     */
    GetChartRequest& withQueries(List<StringHolder> queries)
    {
        ensureData().queries.emplace(std::move(queries));
        return *this;
    }

    /**
     * グルーピング対象を取得
     *
     * @return グルーピング対象
     */
    const optional<StringHolder>& getBy() const
    {
        return ensureData().by;
    }

    /**
     * グルーピング対象を設定
     *
     * @param by グルーピング対象
     */
    void setBy(StringHolder by)
    {
        ensureData().by.emplace(std::move(by));
    }

    /**
     * グルーピング対象を設定
     *
     * @param by グルーピング対象
     */
    GetChartRequest& withBy(StringHolder by)
    {
        ensureData().by.emplace(std::move(by));
        return *this;
    }

    /**
     * データの取得期間を取得
     *
     * @return データの取得期間
     */
    const optional<StringHolder>& getTimeframe() const
    {
        return ensureData().timeframe;
    }

    /**
     * データの取得期間を設定
     *
     * @param timeframe データの取得期間
     */
    void setTimeframe(StringHolder timeframe)
    {
        ensureData().timeframe.emplace(std::move(timeframe));
    }

    /**
     * データの取得期間を設定
     *
     * @param timeframe データの取得期間
     */
    GetChartRequest& withTimeframe(StringHolder timeframe)
    {
        ensureData().timeframe.emplace(std::move(timeframe));
        return *this;
    }

    /**
     * グラフのサイズを取得
     *
     * @return グラフのサイズ
     */
    const optional<StringHolder>& getSize() const
    {
        return ensureData().size;
    }

    /**
     * グラフのサイズを設定
     *
     * @param size グラフのサイズ
     */
    void setSize(StringHolder size)
    {
        ensureData().size.emplace(std::move(size));
    }

    /**
     * グラフのサイズを設定
     *
     * @param size グラフのサイズ
     */
    GetChartRequest& withSize(StringHolder size)
    {
        ensureData().size.emplace(std::move(size));
        return *this;
    }

    /**
     * フォーマットを取得
     *
     * @return フォーマット
     */
    const optional<StringHolder>& getFormat() const
    {
        return ensureData().format;
    }

    /**
     * フォーマットを設定
     *
     * @param format フォーマット
     */
    void setFormat(StringHolder format)
    {
        ensureData().format.emplace(std::move(format));
    }

    /**
     * フォーマットを設定
     *
     * @param format フォーマット
     */
    GetChartRequest& withFormat(StringHolder format)
    {
        ensureData().format.emplace(std::move(format));
        return *this;
    }

    /**
     * 集計方針を取得
     *
     * @return 集計方針
     */
    const optional<StringHolder>& getAggregator() const
    {
        return ensureData().aggregator;
    }

    /**
     * 集計方針を設定
     *
     * @param aggregator 集計方針
     */
    void setAggregator(StringHolder aggregator)
    {
        ensureData().aggregator.emplace(std::move(aggregator));
    }

    /**
     * 集計方針を設定
     *
     * @param aggregator 集計方針
     */
    GetChartRequest& withAggregator(StringHolder aggregator)
    {
        ensureData().aggregator.emplace(std::move(aggregator));
        return *this;
    }

    /**
     * スタイルを取得
     *
     * @return スタイル
     */
    const optional<StringHolder>& getStyle() const
    {
        return ensureData().style;
    }

    /**
     * スタイルを設定
     *
     * @param style スタイル
     */
    void setStyle(StringHolder style)
    {
        ensureData().style.emplace(std::move(style));
    }

    /**
     * スタイルを設定
     *
     * @param style スタイル
     */
    GetChartRequest& withStyle(StringHolder style)
    {
        ensureData().style.emplace(std::move(style));
        return *this;
    }

    /**
     * タイトルを取得
     *
     * @return タイトル
     */
    const optional<StringHolder>& getTitle() const
    {
        return ensureData().title;
    }

    /**
     * タイトルを設定
     *
     * @param title タイトル
     */
    void setTitle(StringHolder title)
    {
        ensureData().title.emplace(std::move(title));
    }

    /**
     * タイトルを設定
     *
     * @param title タイトル
     */
    GetChartRequest& withTitle(StringHolder title)
    {
        ensureData().title.emplace(std::move(title));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetChartRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetChartRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_WATCH_CONTROL_GETCHARTREQUEST_HPP_