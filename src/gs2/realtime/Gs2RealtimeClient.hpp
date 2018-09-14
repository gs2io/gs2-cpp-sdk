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

#ifndef GS2_REALTIME_GS2REALTIMECLIENT_HPP_
#define GS2_REALTIME_GS2REALTIMECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace realtime {

typedef AsyncResult<CreateGatheringPoolResult> AsyncCreateGatheringPoolResult;
typedef AsyncResult<void> AsyncDeleteGatheringPoolResult;
typedef AsyncResult<DescribeGatheringPoolResult> AsyncDescribeGatheringPoolResult;
typedef AsyncResult<GetGatheringPoolResult> AsyncGetGatheringPoolResult;
typedef AsyncResult<UpdateGatheringPoolResult> AsyncUpdateGatheringPoolResult;
typedef AsyncResult<CreateGatheringResult> AsyncCreateGatheringResult;
typedef AsyncResult<void> AsyncDeleteGatheringResult;
typedef AsyncResult<DescribeGatheringResult> AsyncDescribeGatheringResult;
typedef AsyncResult<GetGatheringResult> AsyncGetGatheringResult;

class Gs2RealtimeClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "realtime";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const GatheringPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringPoolId())
        {
            writer.writePropertyName("gatheringPoolId");
            writer.write(*obj.getGatheringPoolId());
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

    void write(detail::json::JsonWriter& writer, const Gathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.write(*obj.getGatheringId());
        }
        if (obj.getGatheringPoolId())
        {
            writer.writePropertyName("gatheringPoolId");
            writer.write(*obj.getGatheringPoolId());
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
        if (obj.getIpAddress())
        {
            writer.writePropertyName("ipAddress");
            writer.write(*obj.getIpAddress());
        }
        if (obj.getPort())
        {
            writer.writePropertyName("port");
            writer.write(*obj.getPort());
        }
        if (obj.getSecret())
        {
            writer.writePropertyName("secret");
            writer.write(*obj.getSecret());
        }
        if (obj.getUserIds())
        {
            writer.writePropertyName("userIds");
            writer.writeArrayStart();
            auto& list = *obj.getUserIds();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
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
    Gs2RealtimeClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RealtimeClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RealtimeClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ギャザリングプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGatheringPool(std::function<void(AsyncCreateGatheringPoolResult&)> callback, CreateGatheringPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGatheringPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool");
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
     * ギャザリングプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGatheringPool(std::function<void(AsyncDeleteGatheringPoolResult&)> callback, DeleteGatheringPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGatheringPool(std::function<void(AsyncDescribeGatheringPoolResult&)> callback, DescribeGatheringPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGatheringPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool");
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
     * ギャザリングプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGatheringPool(std::function<void(AsyncGetGatheringPoolResult&)> callback, GetGatheringPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGatheringPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGatheringPool(std::function<void(AsyncUpdateGatheringPoolResult&)> callback, UpdateGatheringPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGatheringPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("");
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
     * ギャザリングを作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGathering(std::function<void(AsyncCreateGatheringResult&)> callback, CreateGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("/gathering");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getUserIds())
        {
            writer.writePropertyName("userIds");
            writer.write(*request.getUserIds());
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
     * ギャザリングを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGathering(std::function<void(AsyncDeleteGatheringResult&)> callback, DeleteGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("/gathering/").append(detail::StringUtil::toStr(buffer, request.getGatheringName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGathering(std::function<void(AsyncDescribeGatheringResult&)> callback, DescribeGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("/gathering");
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
     * ギャザリングを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGathering(std::function<void(AsyncGetGatheringResult&)> callback, GetGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gatheringPool/").append(detail::StringUtil::toStr(buffer, request.getGatheringPoolName())).append("/gathering/").append(detail::StringUtil::toStr(buffer, request.getGatheringName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_REALTIME_GS2REALTIMECLIENT_HPP_