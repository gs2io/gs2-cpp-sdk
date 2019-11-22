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

#ifndef GS2_CHAT_GS2CHATRESTCLIENT_HPP_
#define GS2_CHAT_GS2CHATRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeRoomsRequest.hpp"
#include "request/CreateRoomRequest.hpp"
#include "request/CreateRoomFromBackendRequest.hpp"
#include "request/GetRoomRequest.hpp"
#include "request/UpdateRoomRequest.hpp"
#include "request/DeleteRoomRequest.hpp"
#include "request/DeleteRoomFromBackendRequest.hpp"
#include "request/DescribeMessagesRequest.hpp"
#include "request/PostRequest.hpp"
#include "request/PostByUserIdRequest.hpp"
#include "request/GetMessageRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DescribeSubscribesRequest.hpp"
#include "request/DescribeSubscribesByUserIdRequest.hpp"
#include "request/DescribeSubscribesByRoomNameRequest.hpp"
#include "request/SubscribeRequest.hpp"
#include "request/SubscribeByUserIdRequest.hpp"
#include "request/GetSubscribeRequest.hpp"
#include "request/GetSubscribeByUserIdRequest.hpp"
#include "request/UpdateNotificationTypeRequest.hpp"
#include "request/UpdateNotificationTypeByUserIdRequest.hpp"
#include "request/UnsubscribeRequest.hpp"
#include "request/UnsubscribeByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeRoomsResult.hpp"
#include "result/CreateRoomResult.hpp"
#include "result/CreateRoomFromBackendResult.hpp"
#include "result/GetRoomResult.hpp"
#include "result/UpdateRoomResult.hpp"
#include "result/DeleteRoomResult.hpp"
#include "result/DeleteRoomFromBackendResult.hpp"
#include "result/DescribeMessagesResult.hpp"
#include "result/PostResult.hpp"
#include "result/PostByUserIdResult.hpp"
#include "result/GetMessageResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DescribeSubscribesResult.hpp"
#include "result/DescribeSubscribesByUserIdResult.hpp"
#include "result/DescribeSubscribesByRoomNameResult.hpp"
#include "result/SubscribeResult.hpp"
#include "result/SubscribeByUserIdResult.hpp"
#include "result/GetSubscribeResult.hpp"
#include "result/GetSubscribeByUserIdResult.hpp"
#include "result/UpdateNotificationTypeResult.hpp"
#include "result/UpdateNotificationTypeByUserIdResult.hpp"
#include "result/UnsubscribeResult.hpp"
#include "result/UnsubscribeByUserIdResult.hpp"

namespace gs2 { namespace chat {

/**
 * GS2 Chat API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ChatRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ChatRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback);

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback);

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback);

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback);

	/**
	 * ルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRooms(DescribeRoomsRequest request, std::function<void(AsyncDescribeRoomsResult)> callback);

	/**
	 * ルームを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRoom(CreateRoomRequest request, std::function<void(AsyncCreateRoomResult)> callback);

	/**
	 * ルームを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRoomFromBackend(CreateRoomFromBackendRequest request, std::function<void(AsyncCreateRoomFromBackendResult)> callback);

	/**
	 * ルームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRoom(GetRoomRequest request, std::function<void(AsyncGetRoomResult)> callback);

	/**
	 * ルームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRoom(UpdateRoomRequest request, std::function<void(AsyncUpdateRoomResult)> callback);

	/**
	 * ルームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRoom(DeleteRoomRequest request, std::function<void(AsyncDeleteRoomResult)> callback);

	/**
	 * ルームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRoomFromBackend(DeleteRoomFromBackendRequest request, std::function<void(AsyncDeleteRoomFromBackendResult)> callback);

	/**
	 * メッセージの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(DescribeMessagesRequest request, std::function<void(AsyncDescribeMessagesResult)> callback);

	/**
	 * メッセージを投稿<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void post(PostRequest request, std::function<void(AsyncPostResult)> callback);

	/**
	 * ユーザIDを指定してメッセージを投稿<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void postByUserId(PostByUserIdRequest request, std::function<void(AsyncPostByUserIdResult)> callback);

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(GetMessageRequest request, std::function<void(AsyncGetMessageResult)> callback);

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(DeleteMessageRequest request, std::function<void(AsyncDeleteMessageResult)> callback);

	/**
	 * 購読しているルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribes(DescribeSubscribesRequest request, std::function<void(AsyncDescribeSubscribesResult)> callback);

	/**
	 * ユーザIDを指定して購読しているルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByUserId(DescribeSubscribesByUserIdRequest request, std::function<void(AsyncDescribeSubscribesByUserIdResult)> callback);

	/**
	 * ルーム名を指定して購読しているユーザの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByRoomName(DescribeSubscribesByRoomNameRequest request, std::function<void(AsyncDescribeSubscribesByRoomNameResult)> callback);

	/**
	 * ルームを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribe(SubscribeRequest request, std::function<void(AsyncSubscribeResult)> callback);

	/**
	 * ユーザIDを指定してルームを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribeByUserId(SubscribeByUserIdRequest request, std::function<void(AsyncSubscribeByUserIdResult)> callback);

	/**
	 * 購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(GetSubscribeRequest request, std::function<void(AsyncGetSubscribeResult)> callback);

	/**
	 * ユーザIDを指定して購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribeByUserId(GetSubscribeByUserIdRequest request, std::function<void(AsyncGetSubscribeByUserIdResult)> callback);

	/**
	 * 通知方法を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNotificationType(UpdateNotificationTypeRequest request, std::function<void(AsyncUpdateNotificationTypeResult)> callback);

	/**
	 * ユーザIDを指定して通知方法を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNotificationTypeByUserId(UpdateNotificationTypeByUserIdRequest request, std::function<void(AsyncUpdateNotificationTypeByUserIdResult)> callback);

	/**
	 * 購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribe(UnsubscribeRequest request, std::function<void(AsyncUnsubscribeResult)> callback);

	/**
	 * ユーザIDを指定して購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribeByUserId(UnsubscribeByUserIdRequest request, std::function<void(AsyncUnsubscribeByUserIdResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_CHAT_GS2CHATRESTCLIENT_HPP_