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
            writer.write(*obj.getInboxId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.write(*obj.getIsAutomaticDeletingEnabled());
        }
        if (obj.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.write(*obj.getReceiveMessageTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.write(*obj.getReceiveMessageDoneTriggerScriptId());
        }
        if (obj.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.write(*obj.getReceiveMessageDoneTriggerQueueId());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.write(*obj.getReadMessageDoneTriggerScriptId());
        }
        if (obj.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.write(*obj.getReadMessageDoneTriggerQueueId());
        }
        if (obj.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.write(*obj.getDeleteMessageTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.write(*obj.getDeleteMessageDoneTriggerScriptId());
        }
        if (obj.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.write(*obj.getDeleteMessageDoneTriggerQueueId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Message& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageId())
        {
            writer.writePropertyName("messageId");
            writer.write(*obj.getMessageId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getIsRead())
        {
            writer.writePropertyName("isRead");
            writer.write(*obj.getIsRead());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.write(*obj.getReadMessageTriggerScriptArgs());
        }
        if (obj.getReceivedAt())
        {
            writer.writePropertyName("receivedAt");
            writer.write(*obj.getReceivedAt());
        }
        if (obj.getReadAt())
        {
            writer.writePropertyName("readAt");
            writer.write(*obj.getReadAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.write(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.write(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.write(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.write(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Body& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*obj.getReadMessageTriggerScriptId());
        }
        if (obj.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.write(*obj.getReadMessageTriggerScriptArgs());
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
            writer.write(*obj.getReason());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const NotGetMessage& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageName())
        {
            writer.writePropertyName("messageName");
            writer.write(*obj.getMessageName());
        }
        if (obj.getReason())
        {
            writer.writePropertyName("reason");
            writer.write(*obj.getReason());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2InboxClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InboxClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InboxClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
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
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.write(*request.getIsAutomaticDeletingEnabled());
        }
        if (request.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.write(*request.getReceiveMessageTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.write(*request.getReceiveMessageDoneTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.write(*request.getReceiveMessageDoneTriggerQueueId());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.write(*request.getReadMessageDoneTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.write(*request.getReadMessageDoneTriggerQueueId());
        }
        if (request.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.write(*request.getDeleteMessageTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.write(*request.getDeleteMessageDoneTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.write(*request.getDeleteMessageDoneTriggerQueueId());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getIsAutomaticDeletingEnabled())
        {
            writer.writePropertyName("isAutomaticDeletingEnabled");
            writer.write(*request.getIsAutomaticDeletingEnabled());
        }
        if (request.getReceiveMessageTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageTriggerScriptId");
            writer.write(*request.getReceiveMessageTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScriptId");
            writer.write(*request.getReceiveMessageDoneTriggerScriptId());
        }
        if (request.getReceiveMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("receiveMessageDoneTriggerQueueId");
            writer.write(*request.getReceiveMessageDoneTriggerQueueId());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("readMessageDoneTriggerScriptId");
            writer.write(*request.getReadMessageDoneTriggerScriptId());
        }
        if (request.getReadMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("readMessageDoneTriggerQueueId");
            writer.write(*request.getReadMessageDoneTriggerQueueId());
        }
        if (request.getDeleteMessageTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageTriggerScriptId");
            writer.write(*request.getDeleteMessageTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerScriptId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScriptId");
            writer.write(*request.getDeleteMessageDoneTriggerScriptId());
        }
        if (request.getDeleteMessageDoneTriggerQueueId())
        {
            writer.writePropertyName("deleteMessageDoneTriggerQueueId");
            writer.write(*request.getDeleteMessageDoneTriggerQueueId());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getReadMessageTriggerScriptId())
        {
            writer.writePropertyName("readMessageTriggerScriptId");
            writer.write(*request.getReadMessageTriggerScriptId());
        }
        if (request.getReadMessageTriggerScriptArgs())
        {
            writer.writePropertyName("readMessageTriggerScriptArgs");
            writer.write(*request.getReadMessageTriggerScriptArgs());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getBodies())
        {
            writer.writePropertyName("bodies");
            writer.writeArrayStart();
            auto& list = *request.getBodies();
            for (Int32 i = 0; i < list.getCount(); ++i)
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageNames()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageNames()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageNames={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageNames()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageNames()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageNames={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
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
        Char encodeBuffer[2048];
        if (request.getInboxName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getInboxName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("inboxName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMessageName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("messageName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_INBOX_GS2INBOXCLIENT_HPP_