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

#ifndef GS2_INVENTORY_GS2INVENTORYPRIVATERESTCLIENT_HPP_
#define GS2_INVENTORY_GS2INVENTORYPRIVATERESTCLIENT_HPP_

#include <gs2/inventory/Gs2InventoryRestClient.hpp>
#include "request/DescribeNamespacesByOwnerIdRequest.hpp"
#include "result/DescribeNamespacesByOwnerIdResult.hpp"

namespace gs2 { namespace inventory {

/**
 * GS2 Inventory API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InventoryPrivateRestClient : public Gs2InventoryRestClient
{
private:

    class DescribeNamespacesByOwnerIdTask : public detail::Gs2RestSessionTask<DescribeNamespacesByOwnerIdResult>
    {
    private:
        DescribeNamespacesByOwnerIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/system/{ownerId}/namespace";
            {
                auto& value = m_Request.getOwnerId();
                url.replace("{ownerId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeNamespacesByOwnerIdTask(
            DescribeNamespacesByOwnerIdRequest request,
            Gs2RestSessionTask<DescribeNamespacesByOwnerIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeNamespacesByOwnerIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesByOwnerIdTask() GS2_OVERRIDE = default;
    };


public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2InventoryPrivateRestClient(Gs2RestSession& gs2RestSession) :
        Gs2InventoryRestClient(gs2RestSession)
    {
    }

	/**
	 * オーナーIDを指定してネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespacesByOwnerId(DescribeNamespacesByOwnerIdRequest request, std::function<void(AsyncDescribeNamespacesByOwnerIdResult)> callback)
    {
        DescribeNamespacesByOwnerIdTask& task = *new DescribeNamespacesByOwnerIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYPRIVATERESTCLIENT_HPP_