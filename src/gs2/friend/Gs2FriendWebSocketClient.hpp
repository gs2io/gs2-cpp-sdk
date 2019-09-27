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

#ifndef GS2_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_
#define GS2_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
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
class Gs2FriendWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNamespaces";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createNamespace";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespaceStatus";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeProfilesTask : public detail::Gs2WebSocketSessionTask<DescribeProfilesResult>
    {
    private:
        DescribeProfilesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeProfiles";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
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
        DescribeProfilesTask(
            DescribeProfilesRequest request,
            Gs2WebSocketSessionTask<DescribeProfilesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeProfilesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProfilesTask() GS2_OVERRIDE = default;
    };

    class GetProfileTask : public detail::Gs2WebSocketSessionTask<GetProfileResult>
    {
    private:
        GetProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProfile";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetProfileTask(
            GetProfileRequest request,
            Gs2WebSocketSessionTask<GetProfileResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProfileTask() GS2_OVERRIDE = default;
    };

    class GetProfileByUserIdTask : public detail::Gs2WebSocketSessionTask<GetProfileByUserIdResult>
    {
    private:
        GetProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProfileByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetProfileByUserIdTask(
            GetProfileByUserIdRequest request,
            Gs2WebSocketSessionTask<GetProfileByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProfileByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateProfileTask : public detail::Gs2WebSocketSessionTask<UpdateProfileResult>
    {
    private:
        UpdateProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateProfile";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateProfileTask(
            UpdateProfileRequest request,
            Gs2WebSocketSessionTask<UpdateProfileResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProfileTask() GS2_OVERRIDE = default;
    };

    class UpdateProfileByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateProfileByUserIdResult>
    {
    private:
        UpdateProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateProfileByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateProfileByUserIdTask(
            UpdateProfileByUserIdRequest request,
            Gs2WebSocketSessionTask<UpdateProfileByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateProfileByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteProfileByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteProfileByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteProfileByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteProfileByUserIdTask(
            DeleteProfileByUserIdRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProfileByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetPublicProfileTask : public detail::Gs2WebSocketSessionTask<GetPublicProfileResult>
    {
    private:
        GetPublicProfileRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "profile";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getPublicProfile";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetPublicProfileTask(
            GetPublicProfileRequest request,
            Gs2WebSocketSessionTask<GetPublicProfileResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetPublicProfileResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetPublicProfileTask() GS2_OVERRIDE = default;
    };

    class DescribeFollowsTask : public detail::Gs2WebSocketSessionTask<DescribeFollowsResult>
    {
    private:
        DescribeFollowsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeFollows";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
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
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeFollowsTask(
            DescribeFollowsRequest request,
            Gs2WebSocketSessionTask<DescribeFollowsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFollowsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFollowsTask() GS2_OVERRIDE = default;
    };

    class DescribeFollowsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeFollowsByUserIdResult>
    {
    private:
        DescribeFollowsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeFollowsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
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
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeFollowsByUserIdTask(
            DescribeFollowsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeFollowsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFollowsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFollowsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFollowTask : public detail::Gs2WebSocketSessionTask<GetFollowResult>
    {
    private:
        GetFollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getFollow";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetFollowTask(
            GetFollowRequest request,
            Gs2WebSocketSessionTask<GetFollowResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFollowTask() GS2_OVERRIDE = default;
    };

    class GetFollowByUserIdTask : public detail::Gs2WebSocketSessionTask<GetFollowByUserIdResult>
    {
    private:
        GetFollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getFollowByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetFollowByUserIdTask(
            GetFollowByUserIdRequest request,
            Gs2WebSocketSessionTask<GetFollowByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class FollowTask : public detail::Gs2WebSocketSessionTask<FollowResult>
    {
    private:
        FollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "follow";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        FollowTask(
            FollowRequest request,
            Gs2WebSocketSessionTask<FollowResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<FollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~FollowTask() GS2_OVERRIDE = default;
    };

    class FollowByUserIdTask : public detail::Gs2WebSocketSessionTask<FollowByUserIdResult>
    {
    private:
        FollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "followByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        FollowByUserIdTask(
            FollowByUserIdRequest request,
            Gs2WebSocketSessionTask<FollowByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<FollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~FollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class UnfollowTask : public detail::Gs2WebSocketSessionTask<UnfollowResult>
    {
    private:
        UnfollowRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "unfollow";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UnfollowTask(
            UnfollowRequest request,
            Gs2WebSocketSessionTask<UnfollowResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UnfollowResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnfollowTask() GS2_OVERRIDE = default;
    };

    class UnfollowByUserIdTask : public detail::Gs2WebSocketSessionTask<UnfollowByUserIdResult>
    {
    private:
        UnfollowByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "follow";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "unfollowByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UnfollowByUserIdTask(
            UnfollowByUserIdRequest request,
            Gs2WebSocketSessionTask<UnfollowByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UnfollowByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnfollowByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeFriendsTask : public detail::Gs2WebSocketSessionTask<DescribeFriendsResult>
    {
    private:
        DescribeFriendsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeFriends";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
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
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeFriendsTask(
            DescribeFriendsRequest request,
            Gs2WebSocketSessionTask<DescribeFriendsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFriendsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFriendsTask() GS2_OVERRIDE = default;
    };

    class DescribeFriendsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeFriendsByUserIdResult>
    {
    private:
        DescribeFriendsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeFriendsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
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
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeFriendsByUserIdTask(
            DescribeFriendsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeFriendsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeFriendsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFriendsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFriendTask : public detail::Gs2WebSocketSessionTask<GetFriendResult>
    {
    private:
        GetFriendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getFriend";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetFriendTask(
            GetFriendRequest request,
            Gs2WebSocketSessionTask<GetFriendResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFriendResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFriendTask() GS2_OVERRIDE = default;
    };

    class GetFriendByUserIdTask : public detail::Gs2WebSocketSessionTask<GetFriendByUserIdResult>
    {
    private:
        GetFriendByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getFriendByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getWithProfile())
            {
                jsonWriter.writePropertyName("withProfile");
                jsonWriter.writeBool(*m_Request.getWithProfile());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetFriendByUserIdTask(
            GetFriendByUserIdRequest request,
            Gs2WebSocketSessionTask<GetFriendByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetFriendByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFriendByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteFriendTask : public detail::Gs2WebSocketSessionTask<DeleteFriendResult>
    {
    private:
        DeleteFriendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteFriend";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteFriendTask(
            DeleteFriendRequest request,
            Gs2WebSocketSessionTask<DeleteFriendResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteFriendResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFriendTask() GS2_OVERRIDE = default;
    };

    class DeleteFriendByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteFriendByUserIdResult>
    {
    private:
        DeleteFriendByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteFriendByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteFriendByUserIdTask(
            DeleteFriendByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteFriendByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteFriendByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFriendByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeSendRequestsTask : public detail::Gs2WebSocketSessionTask<DescribeSendRequestsResult>
    {
    private:
        DescribeSendRequestsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSendRequests";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeSendRequestsTask(
            DescribeSendRequestsRequest request,
            Gs2WebSocketSessionTask<DescribeSendRequestsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSendRequestsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSendRequestsTask() GS2_OVERRIDE = default;
    };

    class DescribeSendRequestsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeSendRequestsByUserIdResult>
    {
    private:
        DescribeSendRequestsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSendRequestsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeSendRequestsByUserIdTask(
            DescribeSendRequestsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeSendRequestsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSendRequestsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSendRequestsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetSendRequestTask : public detail::Gs2WebSocketSessionTask<GetSendRequestResult>
    {
    private:
        GetSendRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSendRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetSendRequestTask(
            GetSendRequestRequest request,
            Gs2WebSocketSessionTask<GetSendRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSendRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSendRequestTask() GS2_OVERRIDE = default;
    };

    class GetSendRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<GetSendRequestByUserIdResult>
    {
    private:
        GetSendRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSendRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetSendRequestByUserIdTask(
            GetSendRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<GetSendRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSendRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSendRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendRequestTask : public detail::Gs2WebSocketSessionTask<SendRequestResult>
    {
    private:
        SendRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "sendRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        SendRequestTask(
            SendRequestRequest request,
            Gs2WebSocketSessionTask<SendRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendRequestTask() GS2_OVERRIDE = default;
    };

    class SendRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<SendRequestByUserIdResult>
    {
    private:
        SendRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "sendRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        SendRequestByUserIdTask(
            SendRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<SendRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SendRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteRequestTask : public detail::Gs2WebSocketSessionTask<DeleteRequestResult>
    {
    private:
        DeleteRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteRequestTask(
            DeleteRequestRequest request,
            Gs2WebSocketSessionTask<DeleteRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRequestTask() GS2_OVERRIDE = default;
    };

    class DeleteRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteRequestByUserIdResult>
    {
    private:
        DeleteRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "sendBox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTargetUserId())
            {
                jsonWriter.writePropertyName("targetUserId");
                jsonWriter.writeCharArray(*m_Request.getTargetUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteRequestByUserIdTask(
            DeleteRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiveRequestsTask : public detail::Gs2WebSocketSessionTask<DescribeReceiveRequestsResult>
    {
    private:
        DescribeReceiveRequestsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeReceiveRequests";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeReceiveRequestsTask(
            DescribeReceiveRequestsRequest request,
            Gs2WebSocketSessionTask<DescribeReceiveRequestsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReceiveRequestsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiveRequestsTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiveRequestsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeReceiveRequestsByUserIdResult>
    {
    private:
        DescribeReceiveRequestsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeReceiveRequestsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeReceiveRequestsByUserIdTask(
            DescribeReceiveRequestsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeReceiveRequestsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReceiveRequestsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiveRequestsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetReceiveRequestTask : public detail::Gs2WebSocketSessionTask<GetReceiveRequestResult>
    {
    private:
        GetReceiveRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getReceiveRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetReceiveRequestTask(
            GetReceiveRequestRequest request,
            Gs2WebSocketSessionTask<GetReceiveRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetReceiveRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceiveRequestTask() GS2_OVERRIDE = default;
    };

    class GetReceiveRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<GetReceiveRequestByUserIdResult>
    {
    private:
        GetReceiveRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getReceiveRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetReceiveRequestByUserIdTask(
            GetReceiveRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<GetReceiveRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetReceiveRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceiveRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcceptRequestTask : public detail::Gs2WebSocketSessionTask<AcceptRequestResult>
    {
    private:
        AcceptRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acceptRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        AcceptRequestTask(
            AcceptRequestRequest request,
            Gs2WebSocketSessionTask<AcceptRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcceptRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptRequestTask() GS2_OVERRIDE = default;
    };

    class AcceptRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<AcceptRequestByUserIdResult>
    {
    private:
        AcceptRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acceptRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        AcceptRequestByUserIdTask(
            AcceptRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<AcceptRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcceptRequestByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcceptRequestByUserIdTask() GS2_OVERRIDE = default;
    };

    class RejectRequestTask : public detail::Gs2WebSocketSessionTask<RejectRequestResult>
    {
    private:
        RejectRequestRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "rejectRequest";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        RejectRequestTask(
            RejectRequestRequest request,
            Gs2WebSocketSessionTask<RejectRequestResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RejectRequestResult>(callback),
            m_Request(std::move(request))
        {}

        ~RejectRequestTask() GS2_OVERRIDE = default;
    };

    class RejectRequestByUserIdTask : public detail::Gs2WebSocketSessionTask<RejectRequestByUserIdResult>
    {
    private:
        RejectRequestByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "friend";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "rejectRequestByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getFromUserId())
            {
                jsonWriter.writePropertyName("fromUserId");
                jsonWriter.writeCharArray(*m_Request.getFromUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        RejectRequestByUserIdTask(
            RejectRequestByUserIdRequest request,
            Gs2WebSocketSessionTask<RejectRequestByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RejectRequestByUserIdResult>(callback),
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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2FriendWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_