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

#ifndef GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_
#define GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeProfilesRequest.hpp"
#include "request/GetProfileRequest.hpp"
#include "request/GetProfileByUserIdRequest.hpp"
#include "request/UpdateProfileRequest.hpp"
#include "request/UpdateProfileByUserIdRequest.hpp"
#include "request/DeleteProfileByUserIdRequest.hpp"
#include "request/GetPublicProfileRequest.hpp"
#include "request/DescribeFollowsRequest.hpp"
#include "request/DescribeFollowsByUserIdRequest.hpp"
#include "request/GetFollowRequest.hpp"
#include "request/GetFollowByUserIdRequest.hpp"
#include "request/FollowRequest.hpp"
#include "request/FollowByUserIdRequest.hpp"
#include "request/UnfollowRequest.hpp"
#include "request/UnfollowByUserIdRequest.hpp"
#include "request/DescribeFriendsRequest.hpp"
#include "request/DescribeFriendsByUserIdRequest.hpp"
#include "request/GetFriendRequest.hpp"
#include "request/GetFriendByUserIdRequest.hpp"
#include "request/DeleteFriendRequest.hpp"
#include "request/DeleteFriendByUserIdRequest.hpp"
#include "request/DescribeSendRequestsRequest.hpp"
#include "request/DescribeSendRequestsByUserIdRequest.hpp"
#include "request/GetSendRequestRequest.hpp"
#include "request/GetSendRequestByUserIdRequest.hpp"
#include "request/SendRequestRequest.hpp"
#include "request/SendRequestByUserIdRequest.hpp"
#include "request/DeleteRequestRequest.hpp"
#include "request/DeleteRequestByUserIdRequest.hpp"
#include "request/DescribeReceiveRequestsRequest.hpp"
#include "request/DescribeReceiveRequestsByUserIdRequest.hpp"
#include "request/GetReceiveRequestRequest.hpp"
#include "request/GetReceiveRequestByUserIdRequest.hpp"
#include "request/AcceptRequestRequest.hpp"
#include "request/AcceptRequestByUserIdRequest.hpp"
#include "request/RejectRequestRequest.hpp"
#include "request/RejectRequestByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeProfilesResult.hpp"
#include "result/GetProfileResult.hpp"
#include "result/GetProfileByUserIdResult.hpp"
#include "result/UpdateProfileResult.hpp"
#include "result/UpdateProfileByUserIdResult.hpp"
#include "result/DeleteProfileByUserIdResult.hpp"
#include "result/GetPublicProfileResult.hpp"
#include "result/DescribeFollowsResult.hpp"
#include "result/DescribeFollowsByUserIdResult.hpp"
#include "result/GetFollowResult.hpp"
#include "result/GetFollowByUserIdResult.hpp"
#include "result/FollowResult.hpp"
#include "result/FollowByUserIdResult.hpp"
#include "result/UnfollowResult.hpp"
#include "result/UnfollowByUserIdResult.hpp"
#include "result/DescribeFriendsResult.hpp"
#include "result/DescribeFriendsByUserIdResult.hpp"
#include "result/GetFriendResult.hpp"
#include "result/GetFriendByUserIdResult.hpp"
#include "result/DeleteFriendResult.hpp"
#include "result/DeleteFriendByUserIdResult.hpp"
#include "result/DescribeSendRequestsResult.hpp"
#include "result/DescribeSendRequestsByUserIdResult.hpp"
#include "result/GetSendRequestResult.hpp"
#include "result/GetSendRequestByUserIdResult.hpp"
#include "result/SendRequestResult.hpp"
#include "result/SendRequestByUserIdResult.hpp"
#include "result/DeleteRequestResult.hpp"
#include "result/DeleteRequestByUserIdResult.hpp"
#include "result/DescribeReceiveRequestsResult.hpp"
#include "result/DescribeReceiveRequestsByUserIdResult.hpp"
#include "result/GetReceiveRequestResult.hpp"
#include "result/GetReceiveRequestByUserIdResult.hpp"
#include "result/AcceptRequestResult.hpp"
#include "result/AcceptRequestByUserIdResult.hpp"
#include "result/RejectRequestResult.hpp"
#include "result/RejectRequestByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace friend_ {

/**
 * GS2 Friend API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2FriendRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";

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
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2RestSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2RestSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getFollowScript())
            {
                jsonWriter.writePropertyName("followScript");
                write(jsonWriter, *m_Request.getFollowScript());
            }
            if (m_Request.getUnfollowScript())
            {
                jsonWriter.writePropertyName("unfollowScript");
                write(jsonWriter, *m_Request.getUnfollowScript());
            }
            if (m_Request.getSendRequestScript())
            {
                jsonWriter.writePropertyName("sendRequestScript");
                write(jsonWriter, *m_Request.getSendRequestScript());
            }
            if (m_Request.getCancelRequestScript())
            {
                jsonWriter.writePropertyName("cancelRequestScript");
                write(jsonWriter, *m_Request.getCancelRequestScript());
            }
            if (m_Request.getAcceptRequestScript())
            {
                jsonWriter.writePropertyName("acceptRequestScript");
                write(jsonWriter, *m_Request.getAcceptRequestScript());
            }
            if (m_Request.getRejectRequestScript())
            {
                jsonWriter.writePropertyName("rejectRequestScript");
                write(jsonWriter, *m_Request.getRejectRequestScript());
            }
            if (m_Request.getDeleteFriendScript())
            {
                jsonWriter.writePropertyName("deleteFriendScript");
                write(jsonWriter, *m_Request.getDeleteFriendScript());
            }
            if (m_Request.getUpdateProfileScript())
            {
                jsonWriter.writePropertyName("updateProfileScript");
                write(jsonWriter, *m_Request.getUpdateProfileScript());
            }
            if (m_Request.getFollowNotification())
            {
                jsonWriter.writePropertyName("followNotification");
                write(jsonWriter, *m_Request.getFollowNotification());
            }
            if (m_Request.getReceiveRequestNotification())
            {
                jsonWriter.writePropertyName("receiveRequestNotification");
                write(jsonWriter, *m_Request.getReceiveRequestNotification());
            }
            if (m_Request.getAcceptRequestNotification())
            {
                jsonWriter.writePropertyName("acceptRequestNotification");
                write(jsonWriter, *m_Request.getAcceptRequestNotification());
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
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2RestSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2RestSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/status";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2RestSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2RestSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2RestSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2RestSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getFollowScript())
            {
                jsonWriter.writePropertyName("followScript");
                write(jsonWriter, *m_Request.getFollowScript());
            }
            if (m_Request.getUnfollowScript())
            {
                jsonWriter.writePropertyName("unfollowScript");
                write(jsonWriter, *m_Request.getUnfollowScript());
            }
            if (m_Request.getSendRequestScript())
            {
                jsonWriter.writePropertyName("sendRequestScript");
                write(jsonWriter, *m_Request.getSendRequestScript());
            }
            if (m_Request.getCancelRequestScript())
            {
                jsonWriter.writePropertyName("cancelRequestScript");
                write(jsonWriter, *m_Request.getCancelRequestScript());
            }
            if (m_Request.getAcceptRequestScript())
            {
                jsonWriter.writePropertyName("acceptRequestScript");
                write(jsonWriter, *m_Request.getAcceptRequestScript());
            }
            if (m_Request.getRejectRequestScript())
            {
                jsonWriter.writePropertyName("rejectRequestScript");
                write(jsonWriter, *m_Request.getRejectRequestScript());
            }
            if (m_Request.getDeleteFriendScript())
            {
                jsonWriter.writePropertyName("deleteFriendScript");
                write(jsonWriter, *m_Request.getDeleteFriendScript());
            }
            if (m_Request.getUpdateProfileScript())
            {
                jsonWriter.writePropertyName("updateProfileScript");
                write(jsonWriter, *m_Request.getUpdateProfileScript());
            }
            if (m_Request.getFollowNotification())
            {
                jsonWriter.writePropertyName("followNotification");
                write(jsonWriter, *m_Request.getFollowNotification());
            }
            if (m_Request.getReceiveRequestNotification())
            {
                jsonWriter.writePropertyName("receiveRequestNotification");
                write(jsonWriter, *m_Request.getReceiveRequestNotification());
            }
            if (m_Request.getAcceptRequestNotification())
            {
                jsonWriter.writePropertyName("acceptRequestNotification");
                write(jsonWriter, *m_Request.getAcceptRequestNotification());
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

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2RestSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2RestSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeProfilesTask : public detail::Gs2RestSessionTask<DescribeProfilesResult>
    {
    private:
        DescribeProfilesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeProfilesTask(
            DescribeProfilesRequest request,
            Gs2RestSessionTask<DescribeProfilesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeProfilesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProfilesTask() GS2_OVERRIDE = default;
    };

    class GetProfileTask : public detail::Gs2RestSessionTask<GetProfileResult>
    {
    private:
        GetProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetProfileTask(
            GetProfileRequest request,
            Gs2RestSessionTask<GetProfileResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProfileTask() GS2_OVERRIDE = default;
    };

    class GetProfileByUserIdTask : public detail::Gs2RestSessionTask<GetProfileByUserIdResult>
    {
    private:
        GetProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetProfileByUserIdTask(
            GetProfileByUserIdRequest request,
            Gs2RestSessionTask<GetProfileByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProfileByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateProfileTask : public detail::Gs2RestSessionTask<UpdateProfileResult>
    {
    private:
        UpdateProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getPublicProfile())
            {
                jsonWriter.writePropertyName("publicProfile");
                jsonWriter.writeCharArray(*m_Request.getPublicProfile());
            }
            if (m_Request.getFollowerProfile())
            {
                jsonWriter.writePropertyName("followerProfile");
                jsonWriter.writeCharArray(*m_Request.getFollowerProfile());
            }
            if (m_Request.getFriendProfile())
            {
                jsonWriter.writePropertyName("friendProfile");
                jsonWriter.writeCharArray(*m_Request.getFriendProfile());
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateProfileTask(
            UpdateProfileRequest request,
            Gs2RestSessionTask<UpdateProfileResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProfileTask() GS2_OVERRIDE = default;
    };

    class UpdateProfileByUserIdTask : public detail::Gs2RestSessionTask<UpdateProfileByUserIdResult>
    {
    private:
        UpdateProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getPublicProfile())
            {
                jsonWriter.writePropertyName("publicProfile");
                jsonWriter.writeCharArray(*m_Request.getPublicProfile());
            }
            if (m_Request.getFollowerProfile())
            {
                jsonWriter.writePropertyName("followerProfile");
                jsonWriter.writeCharArray(*m_Request.getFollowerProfile());
            }
            if (m_Request.getFriendProfile())
            {
                jsonWriter.writePropertyName("friendProfile");
                jsonWriter.writeCharArray(*m_Request.getFriendProfile());
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateProfileByUserIdTask(
            UpdateProfileByUserIdRequest request,
            Gs2RestSessionTask<UpdateProfileByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateProfileByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteProfileByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/profile";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteProfileByUserIdTask(
            DeleteProfileByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetPublicProfileTask : public detail::Gs2RestSessionTask<GetPublicProfileResult>
    {
    private:
        GetPublicProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/profile/public";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetPublicProfileTask(
            GetPublicProfileRequest request,
            Gs2RestSessionTask<GetPublicProfileResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetPublicProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetPublicProfileTask() GS2_OVERRIDE = default;
    };

    class DescribeFollowsTask : public detail::Gs2RestSessionTask<DescribeFollowsResult>
    {
    private:
        DescribeFollowsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/follow";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeFollowsTask(
            DescribeFollowsRequest request,
            Gs2RestSessionTask<DescribeFollowsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFollowsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFollowsTask() GS2_OVERRIDE = default;
    };

    class DescribeFollowsByUserIdTask : public detail::Gs2RestSessionTask<DescribeFollowsByUserIdResult>
    {
    private:
        DescribeFollowsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/follow";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeFollowsByUserIdTask(
            DescribeFollowsByUserIdRequest request,
            Gs2RestSessionTask<DescribeFollowsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFollowsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFollowsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFollowTask : public detail::Gs2RestSessionTask<GetFollowResult>
    {
    private:
        GetFollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetFollowTask(
            GetFollowRequest request,
            Gs2RestSessionTask<GetFollowResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFollowTask() GS2_OVERRIDE = default;
    };

    class GetFollowByUserIdTask : public detail::Gs2RestSessionTask<GetFollowByUserIdResult>
    {
    private:
        GetFollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetFollowByUserIdTask(
            GetFollowByUserIdRequest request,
            Gs2RestSessionTask<GetFollowByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class FollowTask : public detail::Gs2RestSessionTask<FollowResult>
    {
    private:
        FollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        FollowTask(
            FollowRequest request,
            Gs2RestSessionTask<FollowResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<FollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~FollowTask() GS2_OVERRIDE = default;
    };

    class FollowByUserIdTask : public detail::Gs2RestSessionTask<FollowByUserIdResult>
    {
    private:
        FollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        FollowByUserIdTask(
            FollowByUserIdRequest request,
            Gs2RestSessionTask<FollowByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<FollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~FollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class UnfollowTask : public detail::Gs2RestSessionTask<UnfollowResult>
    {
    private:
        UnfollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        UnfollowTask(
            UnfollowRequest request,
            Gs2RestSessionTask<UnfollowResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UnfollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnfollowTask() GS2_OVERRIDE = default;
    };

    class UnfollowByUserIdTask : public detail::Gs2RestSessionTask<UnfollowByUserIdResult>
    {
    private:
        UnfollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/follow/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        UnfollowByUserIdTask(
            UnfollowByUserIdRequest request,
            Gs2RestSessionTask<UnfollowByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UnfollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnfollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeFriendsTask : public detail::Gs2RestSessionTask<DescribeFriendsResult>
    {
    private:
        DescribeFriendsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/friend";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeFriendsTask(
            DescribeFriendsRequest request,
            Gs2RestSessionTask<DescribeFriendsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFriendsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFriendsTask() GS2_OVERRIDE = default;
    };

    class DescribeFriendsByUserIdTask : public detail::Gs2RestSessionTask<DescribeFriendsByUserIdResult>
    {
    private:
        DescribeFriendsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/friend";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeFriendsByUserIdTask(
            DescribeFriendsByUserIdRequest request,
            Gs2RestSessionTask<DescribeFriendsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFriendsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFriendsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFriendTask : public detail::Gs2RestSessionTask<GetFriendResult>
    {
    private:
        GetFriendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/friend/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetFriendTask(
            GetFriendRequest request,
            Gs2RestSessionTask<GetFriendResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFriendResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFriendTask() GS2_OVERRIDE = default;
    };

    class GetFriendByUserIdTask : public detail::Gs2RestSessionTask<GetFriendByUserIdResult>
    {
    private:
        GetFriendByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/friend/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getWithProfile())
            {
                url += joint;
                url += "withProfile=";
                url += detail::StringVariable(*m_Request.getWithProfile()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetFriendByUserIdTask(
            GetFriendByUserIdRequest request,
            Gs2RestSessionTask<GetFriendByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFriendByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFriendByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteFriendTask : public detail::Gs2RestSessionTask<DeleteFriendResult>
    {
    private:
        DeleteFriendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/friend/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteFriendTask(
            DeleteFriendRequest request,
            Gs2RestSessionTask<DeleteFriendResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFriendResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFriendTask() GS2_OVERRIDE = default;
    };

    class DeleteFriendByUserIdTask : public detail::Gs2RestSessionTask<DeleteFriendByUserIdResult>
    {
    private:
        DeleteFriendByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/friend/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteFriendByUserIdTask(
            DeleteFriendByUserIdRequest request,
            Gs2RestSessionTask<DeleteFriendByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFriendByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFriendByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeSendRequestsTask : public detail::Gs2RestSessionTask<DescribeSendRequestsResult>
    {
    private:
        DescribeSendRequestsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/sendBox";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeSendRequestsTask(
            DescribeSendRequestsRequest request,
            Gs2RestSessionTask<DescribeSendRequestsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeSendRequestsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSendRequestsTask() GS2_OVERRIDE = default;
    };

    class DescribeSendRequestsByUserIdTask : public detail::Gs2RestSessionTask<DescribeSendRequestsByUserIdResult>
    {
    private:
        DescribeSendRequestsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/sendBox";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeSendRequestsByUserIdTask(
            DescribeSendRequestsByUserIdRequest request,
            Gs2RestSessionTask<DescribeSendRequestsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeSendRequestsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSendRequestsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetSendRequestTask : public detail::Gs2RestSessionTask<GetSendRequestResult>
    {
    private:
        GetSendRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetSendRequestTask(
            GetSendRequestRequest request,
            Gs2RestSessionTask<GetSendRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetSendRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSendRequestTask() GS2_OVERRIDE = default;
    };

    class GetSendRequestByUserIdTask : public detail::Gs2RestSessionTask<GetSendRequestByUserIdResult>
    {
    private:
        GetSendRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetSendRequestByUserIdTask(
            GetSendRequestByUserIdRequest request,
            Gs2RestSessionTask<GetSendRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetSendRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSendRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendRequestTask : public detail::Gs2RestSessionTask<SendRequestResult>
    {
    private:
        SendRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        SendRequestTask(
            SendRequestRequest request,
            Gs2RestSessionTask<SendRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SendRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendRequestTask() GS2_OVERRIDE = default;
    };

    class SendRequestByUserIdTask : public detail::Gs2RestSessionTask<SendRequestByUserIdResult>
    {
    private:
        SendRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        SendRequestByUserIdTask(
            SendRequestByUserIdRequest request,
            Gs2RestSessionTask<SendRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SendRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteRequestTask : public detail::Gs2RestSessionTask<DeleteRequestResult>
    {
    private:
        DeleteRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteRequestTask(
            DeleteRequestRequest request,
            Gs2RestSessionTask<DeleteRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRequestTask() GS2_OVERRIDE = default;
    };

    class DeleteRequestByUserIdTask : public detail::Gs2RestSessionTask<DeleteRequestByUserIdResult>
    {
    private:
        DeleteRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/sendBox/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteRequestByUserIdTask(
            DeleteRequestByUserIdRequest request,
            Gs2RestSessionTask<DeleteRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiveRequestsTask : public detail::Gs2RestSessionTask<DescribeReceiveRequestsResult>
    {
    private:
        DescribeReceiveRequestsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/inbox";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeReceiveRequestsTask(
            DescribeReceiveRequestsRequest request,
            Gs2RestSessionTask<DescribeReceiveRequestsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeReceiveRequestsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiveRequestsTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiveRequestsByUserIdTask : public detail::Gs2RestSessionTask<DescribeReceiveRequestsByUserIdResult>
    {
    private:
        DescribeReceiveRequestsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/inbox";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeReceiveRequestsByUserIdTask(
            DescribeReceiveRequestsByUserIdRequest request,
            Gs2RestSessionTask<DescribeReceiveRequestsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeReceiveRequestsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiveRequestsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetReceiveRequestTask : public detail::Gs2RestSessionTask<GetReceiveRequestResult>
    {
    private:
        GetReceiveRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetReceiveRequestTask(
            GetReceiveRequestRequest request,
            Gs2RestSessionTask<GetReceiveRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetReceiveRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceiveRequestTask() GS2_OVERRIDE = default;
    };

    class GetReceiveRequestByUserIdTask : public detail::Gs2RestSessionTask<GetReceiveRequestByUserIdResult>
    {
    private:
        GetReceiveRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        GetReceiveRequestByUserIdTask(
            GetReceiveRequestByUserIdRequest request,
            Gs2RestSessionTask<GetReceiveRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetReceiveRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceiveRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcceptRequestTask : public detail::Gs2RestSessionTask<AcceptRequestResult>
    {
    private:
        AcceptRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        AcceptRequestTask(
            AcceptRequestRequest request,
            Gs2RestSessionTask<AcceptRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcceptRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptRequestTask() GS2_OVERRIDE = default;
    };

    class AcceptRequestByUserIdTask : public detail::Gs2RestSessionTask<AcceptRequestByUserIdResult>
    {
    private:
        AcceptRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        AcceptRequestByUserIdTask(
            AcceptRequestByUserIdRequest request,
            Gs2RestSessionTask<AcceptRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcceptRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class RejectRequestTask : public detail::Gs2RestSessionTask<RejectRequestResult>
    {
    private:
        RejectRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        RejectRequestTask(
            RejectRequestRequest request,
            Gs2RestSessionTask<RejectRequestResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RejectRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~RejectRequestTask() GS2_OVERRIDE = default;
    };

    class RejectRequestByUserIdTask : public detail::Gs2RestSessionTask<RejectRequestByUserIdResult>
    {
    private:
        RejectRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/inbox/{fromUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFromUserId();
                url.replace("{fromUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            {
                gs2HttpTask.setBody("[]");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        RejectRequestByUserIdTask(
            RejectRequestByUserIdRequest request,
            Gs2RestSessionTask<RejectRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RejectRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~RejectRequestByUserIdTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getNamespaceId())
        {
            jsonWriter.writePropertyName("namespaceId");
            jsonWriter.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getFollowScript())
        {
            jsonWriter.writePropertyName("followScript");
            write(jsonWriter, *obj.getFollowScript());
        }
        if (obj.getUnfollowScript())
        {
            jsonWriter.writePropertyName("unfollowScript");
            write(jsonWriter, *obj.getUnfollowScript());
        }
        if (obj.getSendRequestScript())
        {
            jsonWriter.writePropertyName("sendRequestScript");
            write(jsonWriter, *obj.getSendRequestScript());
        }
        if (obj.getCancelRequestScript())
        {
            jsonWriter.writePropertyName("cancelRequestScript");
            write(jsonWriter, *obj.getCancelRequestScript());
        }
        if (obj.getAcceptRequestScript())
        {
            jsonWriter.writePropertyName("acceptRequestScript");
            write(jsonWriter, *obj.getAcceptRequestScript());
        }
        if (obj.getRejectRequestScript())
        {
            jsonWriter.writePropertyName("rejectRequestScript");
            write(jsonWriter, *obj.getRejectRequestScript());
        }
        if (obj.getDeleteFriendScript())
        {
            jsonWriter.writePropertyName("deleteFriendScript");
            write(jsonWriter, *obj.getDeleteFriendScript());
        }
        if (obj.getUpdateProfileScript())
        {
            jsonWriter.writePropertyName("updateProfileScript");
            write(jsonWriter, *obj.getUpdateProfileScript());
        }
        if (obj.getFollowNotification())
        {
            jsonWriter.writePropertyName("followNotification");
            write(jsonWriter, *obj.getFollowNotification());
        }
        if (obj.getReceiveRequestNotification())
        {
            jsonWriter.writePropertyName("receiveRequestNotification");
            write(jsonWriter, *obj.getReceiveRequestNotification());
        }
        if (obj.getAcceptRequestNotification())
        {
            jsonWriter.writePropertyName("acceptRequestNotification");
            write(jsonWriter, *obj.getAcceptRequestNotification());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Profile& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getProfileId())
        {
            jsonWriter.writePropertyName("profileId");
            jsonWriter.writeCharArray(*obj.getProfileId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getPublicProfile())
        {
            jsonWriter.writePropertyName("publicProfile");
            jsonWriter.writeCharArray(*obj.getPublicProfile());
        }
        if (obj.getFollowerProfile())
        {
            jsonWriter.writePropertyName("followerProfile");
            jsonWriter.writeCharArray(*obj.getFollowerProfile());
        }
        if (obj.getFriendProfile())
        {
            jsonWriter.writePropertyName("friendProfile");
            jsonWriter.writeCharArray(*obj.getFriendProfile());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Follow& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFollowId())
        {
            jsonWriter.writePropertyName("followId");
            jsonWriter.writeCharArray(*obj.getFollowId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserIds())
        {
            jsonWriter.writePropertyName("targetUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getTargetUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Friend& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFriendId())
        {
            jsonWriter.writePropertyName("friendId");
            jsonWriter.writeCharArray(*obj.getFriendId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserIds())
        {
            jsonWriter.writePropertyName("targetUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getTargetUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SendBox& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSendBoxId())
        {
            jsonWriter.writePropertyName("sendBoxId");
            jsonWriter.writeCharArray(*obj.getSendBoxId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserIds())
        {
            jsonWriter.writePropertyName("targetUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getTargetUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Inbox& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getInboxId())
        {
            jsonWriter.writePropertyName("inboxId");
            jsonWriter.writeCharArray(*obj.getInboxId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getFromUserIds())
        {
            jsonWriter.writePropertyName("fromUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getFromUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRegion())
        {
            jsonWriter.writePropertyName("region");
            jsonWriter.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            jsonWriter.writePropertyName("responseCacheId");
            jsonWriter.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            jsonWriter.writePropertyName("requestHash");
            jsonWriter.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const FollowUser& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getPublicProfile())
        {
            jsonWriter.writePropertyName("publicProfile");
            jsonWriter.writeCharArray(*obj.getPublicProfile());
        }
        if (obj.getFollowerProfile())
        {
            jsonWriter.writePropertyName("followerProfile");
            jsonWriter.writeCharArray(*obj.getFollowerProfile());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const FriendUser& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getPublicProfile())
        {
            jsonWriter.writePropertyName("publicProfile");
            jsonWriter.writeCharArray(*obj.getPublicProfile());
        }
        if (obj.getFriendProfile())
        {
            jsonWriter.writePropertyName("friendProfile");
            jsonWriter.writeCharArray(*obj.getFriendProfile());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const FriendRequest& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserId())
        {
            jsonWriter.writePropertyName("targetUserId");
            jsonWriter.writeCharArray(*obj.getTargetUserId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const PublicProfile& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getPublicProfile())
        {
            jsonWriter.writePropertyName("publicProfile");
            jsonWriter.writeCharArray(*obj.getPublicProfile());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerScriptId())
        {
            jsonWriter.writePropertyName("doneTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            jsonWriter.writePropertyName("doneTriggerQueueNamespaceId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            jsonWriter.writePropertyName("gatewayNamespaceId");
            jsonWriter.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobileNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            jsonWriter.writePropertyName("sound");
            jsonWriter.writeCharArray(*obj.getSound());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2FriendRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
    {
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してプロフィールの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProfiles(DescribeProfilesRequest request, std::function<void(AsyncDescribeProfilesResult)> callback)
    {
        DescribeProfilesTask& task = *new DescribeProfilesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * プロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProfile(GetProfileRequest request, std::function<void(AsyncGetProfileResult)> callback)
    {
        GetProfileTask& task = *new GetProfileTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してプロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProfileByUserId(GetProfileByUserIdRequest request, std::function<void(AsyncGetProfileByUserIdResult)> callback)
    {
        GetProfileByUserIdTask& task = *new GetProfileByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * プロフィールを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProfile(UpdateProfileRequest request, std::function<void(AsyncUpdateProfileResult)> callback)
    {
        UpdateProfileTask& task = *new UpdateProfileTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してプロフィールを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProfileByUserId(UpdateProfileByUserIdRequest request, std::function<void(AsyncUpdateProfileByUserIdResult)> callback)
    {
        UpdateProfileByUserIdTask& task = *new UpdateProfileByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * プロフィールを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProfileByUserId(DeleteProfileByUserIdRequest request, std::function<void(AsyncDeleteProfileByUserIdResult)> callback)
    {
        DeleteProfileByUserIdTask& task = *new DeleteProfileByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 公開プロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPublicProfile(GetPublicProfileRequest request, std::function<void(AsyncGetPublicProfileResult)> callback)
    {
        GetPublicProfileTask& task = *new GetPublicProfileTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォローの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFollows(DescribeFollowsRequest request, std::function<void(AsyncDescribeFollowsResult)> callback)
    {
        DescribeFollowsTask& task = *new DescribeFollowsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフォローの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFollowsByUserId(DescribeFollowsByUserIdRequest request, std::function<void(AsyncDescribeFollowsByUserIdResult)> callback)
    {
        DescribeFollowsByUserIdTask& task = *new DescribeFollowsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォローを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFollow(GetFollowRequest request, std::function<void(AsyncGetFollowResult)> callback)
    {
        GetFollowTask& task = *new GetFollowTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフォローを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFollowByUserId(GetFollowByUserIdRequest request, std::function<void(AsyncGetFollowByUserIdResult)> callback)
    {
        GetFollowByUserIdTask& task = *new GetFollowByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void follow(FollowRequest request, std::function<void(AsyncFollowResult)> callback)
    {
        FollowTask& task = *new FollowTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void followByUserId(FollowByUserIdRequest request, std::function<void(AsyncFollowByUserIdResult)> callback)
    {
        FollowByUserIdTask& task = *new FollowByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * アンフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unfollow(UnfollowRequest request, std::function<void(AsyncUnfollowResult)> callback)
    {
        UnfollowTask& task = *new UnfollowTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してアンフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unfollowByUserId(UnfollowByUserIdRequest request, std::function<void(AsyncUnfollowByUserIdResult)> callback)
    {
        UnfollowByUserIdTask& task = *new UnfollowByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFriends(DescribeFriendsRequest request, std::function<void(AsyncDescribeFriendsResult)> callback)
    {
        DescribeFriendsTask& task = *new DescribeFriendsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFriendsByUserId(DescribeFriendsByUserIdRequest request, std::function<void(AsyncDescribeFriendsByUserIdResult)> callback)
    {
        DescribeFriendsByUserIdTask& task = *new DescribeFriendsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFriend(GetFriendRequest request, std::function<void(AsyncGetFriendResult)> callback)
    {
        GetFriendTask& task = *new GetFriendTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFriendByUserId(GetFriendByUserIdRequest request, std::function<void(AsyncGetFriendByUserIdResult)> callback)
    {
        GetFriendByUserIdTask& task = *new GetFriendByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFriend(DeleteFriendRequest request, std::function<void(AsyncDeleteFriendResult)> callback)
    {
        DeleteFriendTask& task = *new DeleteFriendTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFriendByUserId(DeleteFriendByUserIdRequest request, std::function<void(AsyncDeleteFriendByUserIdResult)> callback)
    {
        DeleteFriendByUserIdTask& task = *new DeleteFriendByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 送信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSendRequests(DescribeSendRequestsRequest request, std::function<void(AsyncDescribeSendRequestsResult)> callback)
    {
        DescribeSendRequestsTask& task = *new DescribeSendRequestsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して送信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSendRequestsByUserId(DescribeSendRequestsByUserIdRequest request, std::function<void(AsyncDescribeSendRequestsByUserIdResult)> callback)
    {
        DescribeSendRequestsByUserIdTask& task = *new DescribeSendRequestsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 送信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSendRequest(GetSendRequestRequest request, std::function<void(AsyncGetSendRequestResult)> callback)
    {
        GetSendRequestTask& task = *new GetSendRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して送信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSendRequestByUserId(GetSendRequestByUserIdRequest request, std::function<void(AsyncGetSendRequestByUserIdResult)> callback)
    {
        GetSendRequestByUserIdTask& task = *new GetSendRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドリクエストを送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendRequest(SendRequestRequest request, std::function<void(AsyncSendRequestResult)> callback)
    {
        SendRequestTask& task = *new SendRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドリクエストを送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendRequestByUserId(SendRequestByUserIdRequest request, std::function<void(AsyncSendRequestByUserIdResult)> callback)
    {
        SendRequestByUserIdTask& task = *new SendRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドリクエストを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRequest(DeleteRequestRequest request, std::function<void(AsyncDeleteRequestResult)> callback)
    {
        DeleteRequestTask& task = *new DeleteRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドリクエストを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRequestByUserId(DeleteRequestByUserIdRequest request, std::function<void(AsyncDeleteRequestByUserIdResult)> callback)
    {
        DeleteRequestByUserIdTask& task = *new DeleteRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 受信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiveRequests(DescribeReceiveRequestsRequest request, std::function<void(AsyncDescribeReceiveRequestsResult)> callback)
    {
        DescribeReceiveRequestsTask& task = *new DescribeReceiveRequestsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiveRequestsByUserId(DescribeReceiveRequestsByUserIdRequest request, std::function<void(AsyncDescribeReceiveRequestsByUserIdResult)> callback)
    {
        DescribeReceiveRequestsByUserIdTask& task = *new DescribeReceiveRequestsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 受信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceiveRequest(GetReceiveRequestRequest request, std::function<void(AsyncGetReceiveRequestResult)> callback)
    {
        GetReceiveRequestTask& task = *new GetReceiveRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceiveRequestByUserId(GetReceiveRequestByUserIdRequest request, std::function<void(AsyncGetReceiveRequestByUserIdResult)> callback)
    {
        GetReceiveRequestByUserIdTask& task = *new GetReceiveRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドリクエストを承諾<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptRequest(AcceptRequestRequest request, std::function<void(AsyncAcceptRequestResult)> callback)
    {
        AcceptRequestTask& task = *new AcceptRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドリクエストを承諾<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptRequestByUserId(AcceptRequestByUserIdRequest request, std::function<void(AsyncAcceptRequestByUserIdResult)> callback)
    {
        AcceptRequestByUserIdTask& task = *new AcceptRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フレンドリクエストを拒否<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void rejectRequest(RejectRequestRequest request, std::function<void(AsyncRejectRequestResult)> callback)
    {
        RejectRequestTask& task = *new RejectRequestTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してフレンドリクエストを拒否<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void rejectRequestByUserId(RejectRequestByUserIdRequest request, std::function<void(AsyncRejectRequestByUserIdResult)> callback)
    {
        RejectRequestByUserIdTask& task = *new RejectRequestByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_