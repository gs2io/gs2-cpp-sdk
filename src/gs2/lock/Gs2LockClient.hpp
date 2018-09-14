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

#ifndef GS2_LOCK_GS2LOCKCLIENT_HPP_
#define GS2_LOCK_GS2LOCKCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace lock {

typedef AsyncResult<CreateLockPoolResult> AsyncCreateLockPoolResult;
typedef AsyncResult<void> AsyncDeleteLockPoolResult;
typedef AsyncResult<DescribeLockPoolResult> AsyncDescribeLockPoolResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetLockPoolResult> AsyncGetLockPoolResult;
typedef AsyncResult<GetLockPoolStatusResult> AsyncGetLockPoolStatusResult;
typedef AsyncResult<UpdateLockPoolResult> AsyncUpdateLockPoolResult;
typedef AsyncResult<LockResult> AsyncLockResult;
typedef AsyncResult<LockByUserResult> AsyncLockByUserResult;
typedef AsyncResult<void> AsyncUnlockResult;
typedef AsyncResult<void> AsyncUnlockByUserResult;
typedef AsyncResult<void> AsyncUnlockForceByUserResult;

class Gs2LockClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "lock";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const LockPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getLockPoolId())
        {
            writer.writePropertyName("lockPoolId");
            writer.write(*obj.getLockPoolId());
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

    void write(detail::json::JsonWriter& writer, const Lock& obj)
    {
        writer.writeObjectStart();
        if (obj.getLockPoolId())
        {
            writer.writePropertyName("lockPoolId");
            writer.write(*obj.getLockPoolId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*obj.getTransactionId());
        }
        if (obj.getResourceName())
        {
            writer.writePropertyName("resourceName");
            writer.write(*obj.getResourceName());
        }
        if (obj.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.write(*obj.getTtl());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2LockClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LockClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LockClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ロックプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLockPool(std::function<void(AsyncCreateLockPoolResult&)> callback, CreateLockPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLockPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool");
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
     * ロックプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLockPool(std::function<void(AsyncDeleteLockPoolResult&)> callback, DeleteLockPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロックプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLockPool(std::function<void(AsyncDescribeLockPoolResult&)> callback, DescribeLockPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLockPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool");
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
            url.append("/lockPool/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロックプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLockPool(std::function<void(AsyncGetLockPoolResult&)> callback, GetLockPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLockPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロックプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLockPoolStatus(std::function<void(AsyncGetLockPoolStatusResult&)> callback, GetLockPoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLockPoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロックプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLockPool(std::function<void(AsyncUpdateLockPoolResult&)> callback, UpdateLockPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateLockPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * ロックを取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lock(std::function<void(AsyncLockResult&)> callback, LockRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<LockResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/lock/transaction/").append(detail::StringUtil::toStr(buffer, request.getTransactionId())).append("/resource/").append(detail::StringUtil::toStr(buffer, request.getResourceName())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getTtl()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTtl()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("ttl={value}").replace("{value}", encodeBuffer) + "&";
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
     * ロックを取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lockByUser(std::function<void(AsyncLockByUserResult&)> callback, LockByUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<LockByUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/lock/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/transaction/").append(detail::StringUtil::toStr(buffer, request.getTransactionId())).append("/resource/").append(detail::StringUtil::toStr(buffer, request.getResourceName())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getTtl()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTtl()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("ttl={value}").replace("{value}", encodeBuffer) + "&";
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
     * アンロックします。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlock(std::function<void(AsyncUnlockResult&)> callback, UnlockRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/lock/transaction/").append(detail::StringUtil::toStr(buffer, request.getTransactionId())).append("/resource/").append(detail::StringUtil::toStr(buffer, request.getResourceName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * アンロックします。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlockByUser(std::function<void(AsyncUnlockByUserResult&)> callback, UnlockByUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/lock/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/transaction/").append(detail::StringUtil::toStr(buffer, request.getTransactionId())).append("/resource/").append(detail::StringUtil::toStr(buffer, request.getResourceName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 強制的にアンロックします。<br>
     * <br>
     * このAPIを利用すると、トランザクションやロックカウンターの状態を無視して強制的にアンロック出来ます。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlockForceByUser(std::function<void(AsyncUnlockForceByUserResult&)> callback, UnlockForceByUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lockPool/").append(detail::StringUtil::toStr(buffer, request.getLockPoolName())).append("/lock/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/resource/").append(detail::StringUtil::toStr(buffer, request.getResourceName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_LOCK_GS2LOCKCLIENT_HPP_