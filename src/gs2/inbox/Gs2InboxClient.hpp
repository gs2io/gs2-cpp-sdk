/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

typedef AsyncResult<CreateInboxResult> AsyncCreateInboxResult;
typedef AsyncResult<void> AsyncDeleteInboxResult;
typedef AsyncResult<DescribeInboxResult> AsyncDescribeInboxResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetInboxResult> AsyncGetInboxResult;
typedef AsyncResult<GetInboxStatusResult> AsyncGetInboxStatusResult;
typedef AsyncResult<UpdateInboxResult> AsyncUpdateInboxResult;
typedef AsyncResult<void> AsyncDeleteMessageResult;
typedef AsyncResult<void> AsyncDeleteMessagesResult;
typedef AsyncResult<DescribeMessageResult> AsyncDescribeMessageResult;
typedef AsyncResult<GetMessageResult> AsyncGetMessageResult;
typedef AsyncResult<ReadMessageResult> AsyncReadMessageResult;
typedef AsyncResult<ReadMessagesResult> AsyncReadMessagesResult;
typedef AsyncResult<SendMessageResult> AsyncSendMessageResult;

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
        if (obj.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*obj.getServiceClass());
        }
        if (obj.getAutoDelete())
        {
            writer.writePropertyName("autoDelete");
            writer.write(*obj.getAutoDelete());
        }
        if (obj.getCooperationUrl())
        {
            writer.writePropertyName("cooperationUrl");
            writer.write(*obj.getCooperationUrl());
        }
        if (obj.getReceiveMessageTriggerScript())
        {
            writer.writePropertyName("receiveMessageTriggerScript");
            writer.write(*obj.getReceiveMessageTriggerScript());
        }
        if (obj.getReceiveMessageDoneTriggerScript())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScript");
            writer.write(*obj.getReceiveMessageDoneTriggerScript());
        }
        if (obj.getReadMessageTriggerScript())
        {
            writer.writePropertyName("readMessageTriggerScript");
            writer.write(*obj.getReadMessageTriggerScript());
        }
        if (obj.getReadMessageDoneTriggerScript())
        {
            writer.writePropertyName("readMessageDoneTriggerScript");
            writer.write(*obj.getReadMessageDoneTriggerScript());
        }
        if (obj.getDeleteMessageTriggerScript())
        {
            writer.writePropertyName("deleteMessageTriggerScript");
            writer.write(*obj.getDeleteMessageTriggerScript());
        }
        if (obj.getDeleteMessageDoneTriggerScript())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScript");
            writer.write(*obj.getDeleteMessageDoneTriggerScript());
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
        if (obj.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.write(*obj.getInboxId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*obj.getMessage());
        }
        if (obj.getCooperation())
        {
            writer.writePropertyName("cooperation");
            writer.write(*obj.getCooperation());
        }
        if (obj.getRead())
        {
            writer.writePropertyName("read");
            writer.write(*obj.getRead());
        }
        if (obj.getDate())
        {
            writer.writePropertyName("date");
            writer.write(*obj.getDate());
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
     * 受信ボックスを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createInbox(std::function<void(AsyncCreateInboxResult&)> callback, CreateInboxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateInboxResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getAutoDelete())
        {
            writer.writePropertyName("autoDelete");
            writer.write(*request.getAutoDelete());
        }
        if (request.getCooperationUrl())
        {
            writer.writePropertyName("cooperationUrl");
            writer.write(*request.getCooperationUrl());
        }
        if (request.getReceiveMessageTriggerScript())
        {
            writer.writePropertyName("receiveMessageTriggerScript");
            writer.write(*request.getReceiveMessageTriggerScript());
        }
        if (request.getReceiveMessageDoneTriggerScript())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScript");
            writer.write(*request.getReceiveMessageDoneTriggerScript());
        }
        if (request.getReadMessageTriggerScript())
        {
            writer.writePropertyName("readMessageTriggerScript");
            writer.write(*request.getReadMessageTriggerScript());
        }
        if (request.getReadMessageDoneTriggerScript())
        {
            writer.writePropertyName("readMessageDoneTriggerScript");
            writer.write(*request.getReadMessageDoneTriggerScript());
        }
        if (request.getDeleteMessageTriggerScript())
        {
            writer.writePropertyName("deleteMessageTriggerScript");
            writer.write(*request.getDeleteMessageTriggerScript());
        }
        if (request.getDeleteMessageDoneTriggerScript())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScript");
            writer.write(*request.getDeleteMessageDoneTriggerScript());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信ボックスを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInbox(std::function<void(AsyncDeleteInboxResult&)> callback, DeleteInboxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信ボックスの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInbox(std::function<void(AsyncDescribeInboxResult&)> callback, DescribeInboxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInboxResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * サービスクラスの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeServiceClass(std::function<void(AsyncDescribeServiceClassResult&)> callback, DescribeServiceClassRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeServiceClassResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信ボックスを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInbox(std::function<void(AsyncGetInboxResult&)> callback, GetInboxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInboxResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信ボックスの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInboxStatus(std::function<void(AsyncGetInboxStatusResult&)> callback, GetInboxStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInboxStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信ボックスを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateInbox(std::function<void(AsyncUpdateInboxResult&)> callback, UpdateInboxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateInboxResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getCooperationUrl())
        {
            writer.writePropertyName("cooperationUrl");
            writer.write(*request.getCooperationUrl());
        }
        if (request.getReceiveMessageTriggerScript())
        {
            writer.writePropertyName("receiveMessageTriggerScript");
            writer.write(*request.getReceiveMessageTriggerScript());
        }
        if (request.getReceiveMessageDoneTriggerScript())
        {
            writer.writePropertyName("receiveMessageDoneTriggerScript");
            writer.write(*request.getReceiveMessageDoneTriggerScript());
        }
        if (request.getReadMessageTriggerScript())
        {
            writer.writePropertyName("readMessageTriggerScript");
            writer.write(*request.getReadMessageTriggerScript());
        }
        if (request.getReadMessageDoneTriggerScript())
        {
            writer.writePropertyName("readMessageDoneTriggerScript");
            writer.write(*request.getReadMessageDoneTriggerScript());
        }
        if (request.getDeleteMessageTriggerScript())
        {
            writer.writePropertyName("deleteMessageTriggerScript");
            writer.write(*request.getDeleteMessageTriggerScript());
        }
        if (request.getDeleteMessageDoneTriggerScript())
        {
            writer.writePropertyName("deleteMessageDoneTriggerScript");
            writer.write(*request.getDeleteMessageDoneTriggerScript());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * メッセージを削除します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(std::function<void(AsyncDeleteMessageResult&)> callback, DeleteMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message/").append(detail::StringUtil::toStr(buffer, request.getMessageId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 複数のメッセージをまとめて削除します<br>
     * <br>
     * - 消費クオータ: 削除するメッセージの数 * 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessages(std::function<void(AsyncDeleteMessagesResult&)> callback, DeleteMessagesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message/multiple");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getMessageIds()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessageIds()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("messageIds={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 受信メッセージの一覧を取得します<br>
     * <br>
     * - 消費クオータ: 50件あたり5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessage(std::function<void(AsyncDescribeMessageResult&)> callback, DescribeMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * メッセージを取得します<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(std::function<void(AsyncGetMessageResult&)> callback, GetMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message/").append(detail::StringUtil::toStr(buffer, request.getMessageId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * メッセージを開封します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessage(std::function<void(AsyncReadMessageResult&)> callback, ReadMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ReadMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message/").append(detail::StringUtil::toStr(buffer, request.getMessageId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 複数のメッセージをまとめて開封します<br>
     * <br>
     * 連携用URLと複数メッセージの開封処理を同時に利用する場合は、200レスポンスを応答すると、GS2側では指定されたすべてのメッセージを開封したことにします。<br>
     * <br>
     * 200 以外のステータスコードを応答する場合はレスポンスボディにJSON形式で、<br>
     * "success" というパラメータに開封に成功したメッセージIDのリストを返す必要があります。<br>
     * success に指定されたメッセージIDのみ開封成功処理を行い、BadGateway(502)応答を返します。<br>
     * <br>
     * BadGateway(502) のレスポンスボディには、コールバックで返された値がそのまま含まれます。<br>
     * 例えば、メッセージにアイテムを添付されていたが、一部アイテムが所有できる上限を超えていたため開封できなかった。という場合<br>
     * success にはアイテムを付与できたメッセージIDのみを応答し、reason など任意のパラメータでアイテムの所持上限を迎えたため<br>
     * メッセージID hoge のメッセージは開封に失敗した。というようなレスポンスを返すことでクライアントにも開封に失敗した理由を伝えることができます。<br>
     * <br>
     * - 消費クオータ: 開封するメッセージの数 * 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessages(std::function<void(AsyncReadMessagesResult&)> callback, ReadMessagesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ReadMessagesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message/multiple");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMessageIds())
        {
            writer.writePropertyName("messageIds");
            writer.writeArrayStart();
            auto& list = *request.getMessageIds();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * メッセージを送信します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessage(std::function<void(AsyncSendMessageResult&)> callback, SendMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SendMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inbox/").append(detail::StringUtil::toStr(buffer, request.getInboxName())).append("/message");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        if (request.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*request.getMessage());
        }
        if (request.getCooperation())
        {
            writer.writePropertyName("cooperation");
            writer.write(*request.getCooperation());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_INBOX_GS2INBOXCLIENT_HPP_