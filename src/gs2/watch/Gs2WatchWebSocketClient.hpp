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

#ifndef GS2_WATCH_GS2WATCHWEBSOCKETCLIENT_HPP_
#define GS2_WATCH_GS2WATCHWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/GetChartRequest.hpp"
#include "request/GetCumulativeRequest.hpp"
#include "request/DescribeBillingActivitiesRequest.hpp"
#include "request/GetBillingActivityRequest.hpp"
#include "result/GetChartResult.hpp"
#include "result/GetCumulativeResult.hpp"
#include "result/DescribeBillingActivitiesResult.hpp"
#include "result/GetBillingActivityResult.hpp"
#include <cstring>

namespace gs2 { namespace watch {

/**
 * GS2 Watch API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2WatchWebSocketClient : public AbstractGs2ClientBase
{
private:

    class GetChartTask : public detail::Gs2WebSocketSessionTask<GetChartResult>
    {
    private:
        GetChartRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "chart";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getChart";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getMetrics())
            {
                jsonWriter.writePropertyName("metrics");
                jsonWriter.writeCharArray(*m_Request.getMetrics());
            }
            if (m_Request.getGrn())
            {
                jsonWriter.writePropertyName("grn");
                jsonWriter.writeCharArray(*m_Request.getGrn());
            }
            if (m_Request.getQueries())
            {
                jsonWriter.writePropertyName("queries");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getQueries();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getBy())
            {
                jsonWriter.writePropertyName("by");
                jsonWriter.writeCharArray(*m_Request.getBy());
            }
            if (m_Request.getTimeframe())
            {
                jsonWriter.writePropertyName("timeframe");
                jsonWriter.writeCharArray(*m_Request.getTimeframe());
            }
            if (m_Request.getSize())
            {
                jsonWriter.writePropertyName("size");
                jsonWriter.writeCharArray(*m_Request.getSize());
            }
            if (m_Request.getFormat())
            {
                jsonWriter.writePropertyName("format");
                jsonWriter.writeCharArray(*m_Request.getFormat());
            }
            if (m_Request.getAggregator())
            {
                jsonWriter.writePropertyName("aggregator");
                jsonWriter.writeCharArray(*m_Request.getAggregator());
            }
            if (m_Request.getStyle())
            {
                jsonWriter.writePropertyName("style");
                jsonWriter.writeCharArray(*m_Request.getStyle());
            }
            if (m_Request.getTitle())
            {
                jsonWriter.writePropertyName("title");
                jsonWriter.writeCharArray(*m_Request.getTitle());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetChartTask(
            GetChartRequest request,
            Gs2WebSocketSessionTask<GetChartResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetChartResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetChartTask() GS2_OVERRIDE = default;
    };

    class GetCumulativeTask : public detail::Gs2WebSocketSessionTask<GetCumulativeResult>
    {
    private:
        GetCumulativeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "cumulative";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getCumulative";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getResourceGrn())
            {
                jsonWriter.writePropertyName("resourceGrn");
                jsonWriter.writeCharArray(*m_Request.getResourceGrn());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetCumulativeTask(
            GetCumulativeRequest request,
            Gs2WebSocketSessionTask<GetCumulativeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetCumulativeResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCumulativeTask() GS2_OVERRIDE = default;
    };

    class DescribeBillingActivitiesTask : public detail::Gs2WebSocketSessionTask<DescribeBillingActivitiesResult>
    {
    private:
        DescribeBillingActivitiesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingActivity";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeBillingActivities";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getYear())
            {
                jsonWriter.writePropertyName("year");
                jsonWriter.writeInt32(*m_Request.getYear());
            }
            if (m_Request.getMonth())
            {
                jsonWriter.writePropertyName("month");
                jsonWriter.writeInt32(*m_Request.getMonth());
            }
            if (m_Request.getService())
            {
                jsonWriter.writePropertyName("service");
                jsonWriter.writeCharArray(*m_Request.getService());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeBillingActivitiesTask(
            DescribeBillingActivitiesRequest request,
            Gs2WebSocketSessionTask<DescribeBillingActivitiesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeBillingActivitiesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBillingActivitiesTask() GS2_OVERRIDE = default;
    };

    class GetBillingActivityTask : public detail::Gs2WebSocketSessionTask<GetBillingActivityResult>
    {
    private:
        GetBillingActivityRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "billingActivity";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getBillingActivity";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getYear())
            {
                jsonWriter.writePropertyName("year");
                jsonWriter.writeInt32(*m_Request.getYear());
            }
            if (m_Request.getMonth())
            {
                jsonWriter.writePropertyName("month");
                jsonWriter.writeInt32(*m_Request.getMonth());
            }
            if (m_Request.getService())
            {
                jsonWriter.writePropertyName("service");
                jsonWriter.writeCharArray(*m_Request.getService());
            }
            if (m_Request.getActivityType())
            {
                jsonWriter.writePropertyName("activityType");
                jsonWriter.writeCharArray(*m_Request.getActivityType());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetBillingActivityTask(
            GetBillingActivityRequest request,
            Gs2WebSocketSessionTask<GetBillingActivityResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetBillingActivityResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBillingActivityTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Chart& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getChartId())
        {
            jsonWriter.writePropertyName("chartId");
            jsonWriter.writeCharArray(*obj.getChartId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getEmbedId())
        {
            jsonWriter.writePropertyName("embedId");
            jsonWriter.writeCharArray(*obj.getEmbedId());
        }
        if (obj.getHtml())
        {
            jsonWriter.writePropertyName("html");
            jsonWriter.writeCharArray(*obj.getHtml());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Cumulative& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCumulativeId())
        {
            jsonWriter.writePropertyName("cumulativeId");
            jsonWriter.writeCharArray(*obj.getCumulativeId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResourceGrn())
        {
            jsonWriter.writePropertyName("resourceGrn");
            jsonWriter.writeCharArray(*obj.getResourceGrn());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeInt64(*obj.getValue());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const BillingActivity& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBillingActivityId())
        {
            jsonWriter.writePropertyName("billingActivityId");
            jsonWriter.writeCharArray(*obj.getBillingActivityId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getYear())
        {
            jsonWriter.writePropertyName("year");
            jsonWriter.writeInt32(*obj.getYear());
        }
        if (obj.getMonth())
        {
            jsonWriter.writePropertyName("month");
            jsonWriter.writeInt32(*obj.getMonth());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getActivityType())
        {
            jsonWriter.writePropertyName("activityType");
            jsonWriter.writeCharArray(*obj.getActivityType());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeInt64(*obj.getValue());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2WatchWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * チャートを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getChart(GetChartRequest request, std::function<void(AsyncGetChartResult)> callback)
    {
        GetChartTask& task = *new GetChartTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 累積値を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCumulative(GetCumulativeRequest request, std::function<void(AsyncGetCumulativeResult)> callback)
    {
        GetCumulativeTask& task = *new GetCumulativeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 請求にまつわるアクティビティの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBillingActivities(DescribeBillingActivitiesRequest request, std::function<void(AsyncDescribeBillingActivitiesResult)> callback)
    {
        DescribeBillingActivitiesTask& task = *new DescribeBillingActivitiesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 請求にまつわるアクティビティを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBillingActivity(GetBillingActivityRequest request, std::function<void(AsyncGetBillingActivityResult)> callback)
    {
        GetBillingActivityTask& task = *new GetBillingActivityTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_WATCH_GS2WATCHWEBSOCKETCLIENT_HPP_