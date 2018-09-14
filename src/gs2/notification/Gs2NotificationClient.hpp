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

#ifndef GS2_NOTIFICATION_GS2NOTIFICATIONCLIENT_HPP_
#define GS2_NOTIFICATION_GS2NOTIFICATIONCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace notification {

typedef AsyncResult<CreateNotificationResult> AsyncCreateNotificationResult;
typedef AsyncResult<void> AsyncDeleteNotificationResult;
typedef AsyncResult<DescribeNotificationResult> AsyncDescribeNotificationResult;
typedef AsyncResult<GetNotificationResult> AsyncGetNotificationResult;
typedef AsyncResult<UpdateNotificationResult> AsyncUpdateNotificationResult;
typedef AsyncResult<CreateSubscribeResult> AsyncCreateSubscribeResult;
typedef AsyncResult<void> AsyncDeleteSubscribeResult;
typedef AsyncResult<DescribeSubscribeResult> AsyncDescribeSubscribeResult;
typedef AsyncResult<GetSubscribeResult> AsyncGetSubscribeResult;

class Gs2NotificationClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "notification";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Notification& obj)
    {
        writer.writeObjectStart();
        if (obj.getNotificationId())
        {
            writer.writePropertyName("notificationId");
            writer.write(*obj.getNotificationId());
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

    void write(detail::json::JsonWriter& writer, const Subscribe& obj)
    {
        writer.writeObjectStart();
        if (obj.getSubscribeId())
        {
            writer.writePropertyName("subscribeId");
            writer.write(*obj.getSubscribeId());
        }
        if (obj.getNotificationId())
        {
            writer.writePropertyName("notificationId");
            writer.write(*obj.getNotificationId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getEndpoint())
        {
            writer.writePropertyName("endpoint");
            writer.write(*obj.getEndpoint());
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



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2NotificationClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2NotificationClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2NotificationClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 通知を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNotification(std::function<void(AsyncCreateNotificationResult&)> callback, CreateNotificationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateNotificationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification");
        }
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
     * 通知を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNotification(std::function<void(AsyncDeleteNotificationResult&)> callback, DeleteNotificationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 通知の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNotification(std::function<void(AsyncDescribeNotificationResult&)> callback, DescribeNotificationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeNotificationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * 通知を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNotification(std::function<void(AsyncGetNotificationResult&)> callback, GetNotificationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetNotificationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 通知を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNotification(std::function<void(AsyncUpdateNotificationResult&)> callback, UpdateNotificationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateNotificationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
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
     * 購読を作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSubscribe(std::function<void(AsyncCreateSubscribeResult&)> callback, CreateSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateSubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("/subscribe");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.write(*request.getType());
        }
        if (request.getEndpoint())
        {
            writer.writePropertyName("endpoint");
            writer.write(*request.getEndpoint());
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
     * 購読を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSubscribe(std::function<void(AsyncDeleteSubscribeResult&)> callback, DeleteSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("/subscribe/").append(detail::StringUtil::toStr(buffer, request.getSubscribeId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 購読の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribe(std::function<void(AsyncDescribeSubscribeResult&)> callback, DescribeSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeSubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("/subscribe");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * 購読を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(std::function<void(AsyncGetSubscribeResult&)> callback, GetSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetSubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/notification/").append(detail::StringUtil::toStr(buffer, request.getNotificationName())).append("/subscribe/").append(detail::StringUtil::toStr(buffer, request.getSubscribeId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_NOTIFICATION_GS2NOTIFICATIONCLIENT_HPP_