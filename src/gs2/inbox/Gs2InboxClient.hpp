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

#ifndef GS2_INBOX_GS2INBOXCLIENT_HPP_
#define GS2_INBOX_GS2INBOXCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeInboxesRequest.hpp"
#include "request/CreateInboxRequest.hpp"
#include "request/GetInboxStatusRequest.hpp"
#include "request/GetInboxRequest.hpp"
#include "request/UpdateInboxRequest.hpp"
#include "request/DeleteInboxRequest.hpp"
#include "request/DescribeMessagesRequest.hpp"
#include "request/DescribeMessagesByUserIdRequest.hpp"
#include "request/SendMessageByUserIdRequest.hpp"
#include "request/SendMessagesByUserIdRequest.hpp"
#include "request/GetMessageRequest.hpp"
#include "request/GetMessageByUserIdRequest.hpp"
#include "request/GetMessagesRequest.hpp"
#include "request/GetMessagesByUserIdRequest.hpp"
#include "request/ReadMessageRequest.hpp"
#include "request/ReadMessageByUserIdRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DeleteMessageByUserIdRequest.hpp"
#include "result/DescribeInboxesResult.hpp"
#include "result/CreateInboxResult.hpp"
#include "result/GetInboxStatusResult.hpp"
#include "result/GetInboxResult.hpp"
#include "result/UpdateInboxResult.hpp"
#include "result/DeleteInboxResult.hpp"
#include "result/DescribeMessagesResult.hpp"
#include "result/DescribeMessagesByUserIdResult.hpp"
#include "result/SendMessageByUserIdResult.hpp"
#include "result/SendMessagesByUserIdResult.hpp"
#include "result/GetMessageResult.hpp"
#include "result/GetMessageByUserIdResult.hpp"
#include "result/GetMessagesResult.hpp"
#include "result/GetMessagesByUserIdResult.hpp"
#include "result/ReadMessageResult.hpp"
#include "result/ReadMessageByUserIdResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DeleteMessageByUserIdResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace inbox {

typedef AsyncResult<DescribeInboxesResult> AsyncDescribeInboxesResult;
typedef AsyncResult<CreateInboxResult> AsyncCreateInboxResult;
typedef AsyncResult<GetInboxStatusResult> AsyncGetInboxStatusResult;
typedef AsyncResult<GetInboxResult> AsyncGetInboxResult;
typedef AsyncResult<UpdateInboxResult> AsyncUpdateInboxResult;
typedef AsyncResult<void> AsyncDeleteInboxResult;
typedef AsyncResult<DescribeMessagesResult> AsyncDescribeMessagesResult;
typedef AsyncResult<DescribeMessagesByUserIdResult> AsyncDescribeMessagesByUserIdResult;
typedef AsyncResult<SendMessageByUserIdResult> AsyncSendMessageByUserIdResult;
typedef AsyncResult<SendMessagesByUserIdResult> AsyncSendMessagesByUserIdResult;
typedef AsyncResult<GetMessageResult> AsyncGetMessageResult;
typedef AsyncResult<GetMessageByUserIdResult> AsyncGetMessageByUserIdResult;
typedef AsyncResult<GetMessagesResult> AsyncGetMessagesResult;
typedef AsyncResult<GetMessagesByUserIdResult> AsyncGetMessagesByUserIdResult;
typedef AsyncResult<ReadMessageResult> AsyncReadMessageResult;
typedef AsyncResult<ReadMessageByUserIdResult> AsyncReadMessageByUserIdResult;
typedef AsyncResult<void> AsyncDeleteMessageResult;
typedef AsyncResult<void> AsyncDeleteMessageByUserIdResult;

/**
 * GS2 Inbox API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InboxClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "inbox";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Inbox& obj)
    {
        writer.writeObjectStart();
        if (obj.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.writeCharArray(*obj.getInboxId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.writeBool(*obj.getIsAutomaticDeletingEnabled());
        }
        if (obj.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveMessageTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getReceiveMessageDoneTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.writeCharArray(*obj.getReceiveMessageDoneTriggerQueueId());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageDoneTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.writeCharArray(*obj.getReadMessageDoneTriggerQueueId());
        }
        if (obj.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.writeCharArray(*obj.getDeleteMessageTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.writeCharArray(*obj.getDeleteMessageDoneTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.writeCharArray(*obj.getDeleteMessageDoneTriggerQueueId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Message& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageId())
        {
            writer.writePropertyName("messageId");
            writer.writeCharArray(*obj.getMessageId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getIsRead())
        {
            writer.writePropertyName("isRead");
            writer.writeBool(*obj.getIsRead());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptArgs());
        }
        if (obj.getReceivedAt())
        {
            writer.writePropertyName("receivedAt");
            writer.writeInt64(*obj.getReceivedAt());
        }
        if (obj.getReadAt())
        {
            writer.writePropertyName("readAt");
            writer.writeInt64(*obj.getReadAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Body& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.writeCharArray(*obj.getReadMessageTriggerScriptArgs());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const NotSendMessage& obj)
    {
        writer.writeObjectStart();
        if (obj.getBody())
        {
            writer.writePropertyName("body");
            write(writer, *obj.getBody());
        }
        if (obj.getReason())
        {
            writer.writePropertyName("reason");
            writer.writeCharArray(*obj.getReason());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const NotGetMessage& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageName())
        {
            writer.writePropertyName("messageName");
            writer.writeCharArray(*obj.getMessageName());
        }
        if (obj.getReason())
        {
            writer.writePropertyName("reason");
            writer.writeCharArray(*obj.getReason());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    Gs2InboxClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2InboxClient(Gs2RestSession& gs2RestSession, const Region& region) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2InboxClient(Gs2RestSession& gs2RestSession, const Char region[]) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

	/**
	 * プレゼントボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInboxes(std::function<void(AsyncDescribeInboxesResult&)> callback, DescribeInboxesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeInboxesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.describeInboxes");
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プレゼントボックスを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInbox(std::function<void(AsyncCreateInboxResult&)> callback, CreateInboxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateInboxResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.createInbox");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.writeBool(*request.getIsAutomaticDeletingEnabled());
        }
        if (request.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.writeCharArray(*request.getReceiveMessageTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getReceiveMessageDoneTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getReceiveMessageDoneTriggerQueueId());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getReadMessageDoneTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getReadMessageDoneTriggerQueueId());
        }
        if (request.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.writeCharArray(*request.getDeleteMessageTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getDeleteMessageDoneTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getDeleteMessageDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プレゼントボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInboxStatus(std::function<void(AsyncGetInboxStatusResult&)> callback, GetInboxStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetInboxStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.getInboxStatus");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プレゼントボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInbox(std::function<void(AsyncGetInboxResult&)> callback, GetInboxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetInboxResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.getInbox");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プレゼントボックスを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInbox(std::function<void(AsyncUpdateInboxResult&)> callback, UpdateInboxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateInboxResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.updateInbox");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.writeBool(*request.getIsAutomaticDeletingEnabled());
        }
        if (request.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.writeCharArray(*request.getReceiveMessageTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getReceiveMessageDoneTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getReceiveMessageDoneTriggerQueueId());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getReadMessageDoneTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getReadMessageDoneTriggerQueueId());
        }
        if (request.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.writeCharArray(*request.getDeleteMessageTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.writeCharArray(*request.getDeleteMessageDoneTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.writeCharArray(*request.getDeleteMessageDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * プレゼントボックスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInbox(std::function<void(AsyncDeleteInboxResult&)> callback, DeleteInboxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FInboxFunctionHandler.deleteInbox");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(std::function<void(AsyncDescribeMessagesResult&)> callback, DescribeMessagesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeMessagesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.describeMessages");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessagesByUserId(std::function<void(AsyncDescribeMessagesByUserIdResult&)> callback, DescribeMessagesByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeMessagesByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.describeMessagesByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessageByUserId(std::function<void(AsyncSendMessageByUserIdResult&)> callback, SendMessageByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SendMessageByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.sendMessageByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*request.getUserId());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.writeCharArray(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.writeCharArray(*request.getReadMessageTriggerScriptArgs());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを複数まとめて新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessagesByUserId(std::function<void(AsyncSendMessagesByUserIdResult&)> callback, SendMessagesByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SendMessagesByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.sendMessagesByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getBodies())
        {
            writer.writePropertyName("bodies");
            writer.writeArrayStart();
            auto& list = *request.getBodies();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(std::function<void(AsyncGetMessageResult&)> callback, GetMessageRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMessageResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.getMessage");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessageByUserId(std::function<void(AsyncGetMessageByUserIdResult&)> callback, GetMessageByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMessageByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.getMessageByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessages(std::function<void(AsyncGetMessagesResult&)> callback, GetMessagesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMessagesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.getMessages");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageNames()) {
            Char urlSafeValue[32];
            url += "&" + detail::StringVariable("messageNames={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessagesByUserId(std::function<void(AsyncGetMessagesByUserIdResult&)> callback, GetMessagesByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMessagesByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.getMessagesByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageNames()) {
            Char urlSafeValue[32];
            url += "&" + detail::StringVariable("messageNames={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessage(std::function<void(AsyncReadMessageResult&)> callback, ReadMessageRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ReadMessageResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.readMessage");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessageByUserId(std::function<void(AsyncReadMessageByUserIdResult&)> callback, ReadMessageByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ReadMessageByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.readMessageByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(std::function<void(AsyncDeleteMessageResult&)> callback, DeleteMessageRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.deleteMessage");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessageByUserId(std::function<void(AsyncDeleteMessageByUserIdResult&)> callback, DeleteMessageByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/inbox-handler?handler=gs2_inbox%2Fhandler%2FMessageFunctionHandler.deleteMessageByUserId");
        if (request.getInboxName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getInboxName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getMessageName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMessageName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_INBOX_GS2INBOXCLIENT_HPP_