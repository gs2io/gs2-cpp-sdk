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

#ifndef GS2_WATCH_GS2WATCHRESTCLIENT_HPP_
#define GS2_WATCH_GS2WATCHRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
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
class Gs2WatchRestClient : public AbstractGs2ClientBase
{
private:

    class GetChartTask : public detail::Gs2RestSessionTask<GetChartResult>
    {
    private:
        GetChartRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/chart/{metrics}";
            {
                auto& value = m_Request.getMetrics();
                url.replace("{metrics}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetChartTask(
            GetChartRequest request,
            Gs2RestSessionTask<GetChartResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetChartResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetChartTask() GS2_OVERRIDE = default;
    };

    class GetCumulativeTask : public detail::Gs2RestSessionTask<GetCumulativeResult>
    {
    private:
        GetCumulativeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/cumulative/{name}";
            {
                auto& value = m_Request.getName();
                url.replace("{name}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getResourceGrn())
            {
                jsonWriter.writePropertyName("resourceGrn");
                jsonWriter.writeCharArray(*m_Request.getResourceGrn());
            }
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetCumulativeTask(
            GetCumulativeRequest request,
            Gs2RestSessionTask<GetCumulativeResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCumulativeResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCumulativeTask() GS2_OVERRIDE = default;
    };

    class DescribeBillingActivitiesTask : public detail::Gs2RestSessionTask<DescribeBillingActivitiesResult>
    {
    private:
        DescribeBillingActivitiesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/billingActivity/{year}/{month}";
            {
                auto& value = m_Request.getYear();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{year}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{year}", "null");
                }
            }
            {
                auto& value = m_Request.getMonth();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{month}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{month}", "null");
                }
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getPageToken())
            {
                url += joint;
                url += "pageToken=";
                url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getLimit())
            {
                url += joint;
                url += "limit=";
                url += detail::StringVariable(*m_Request.getLimit()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeBillingActivitiesTask(
            DescribeBillingActivitiesRequest request,
            Gs2RestSessionTask<DescribeBillingActivitiesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeBillingActivitiesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBillingActivitiesTask() GS2_OVERRIDE = default;
    };

    class GetBillingActivityTask : public detail::Gs2RestSessionTask<GetBillingActivityResult>
    {
    private:
        GetBillingActivityRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "watch";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/billingActivity/{year}/{month}/{service}/{activityType}";
            {
                auto& value = m_Request.getYear();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{year}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{year}", "null");
                }
            }
            {
                auto& value = m_Request.getMonth();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{month}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{month}", "null");
                }
            }
            {
                auto& value = m_Request.getService();
                url.replace("{service}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getActivityType();
                url.replace("{activityType}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            jsonWriter.writeObjectEnd();
            {
                gs2HttpTask.setBody(jsonWriter.toString());
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        GetBillingActivityTask(
            GetBillingActivityRequest request,
            Gs2RestSessionTask<GetBillingActivityResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetBillingActivityResult>(callback),
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
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2WatchRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_WATCH_GS2WATCHRESTCLIENT_HPP_