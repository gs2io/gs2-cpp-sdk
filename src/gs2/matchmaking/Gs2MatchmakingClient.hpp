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

#ifndef GS2_MATCHMAKING_GS2MATCHMAKINGCLIENT_HPP_
#define GS2_MATCHMAKING_GS2MATCHMAKINGCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace matchmaking {

typedef AsyncResult<AnybodyDescribeJoinedUserResult> AsyncAnybodyDescribeJoinedUserResult;
typedef AsyncResult<AnybodyDoMatchmakingResult> AsyncAnybodyDoMatchmakingResult;
typedef AsyncResult<void> AsyncAnybodyLeaveGatheringResult;
typedef AsyncResult<CustomAutoDescribeJoinedUserResult> AsyncCustomAutoDescribeJoinedUserResult;
typedef AsyncResult<CustomAutoDoMatchmakingResult> AsyncCustomAutoDoMatchmakingResult;
typedef AsyncResult<void> AsyncCustomAutoLeaveGatheringResult;
typedef AsyncResult<CreateMatchmakingResult> AsyncCreateMatchmakingResult;
typedef AsyncResult<void> AsyncDeleteMatchmakingResult;
typedef AsyncResult<DescribeMatchmakingResult> AsyncDescribeMatchmakingResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetMatchmakingResult> AsyncGetMatchmakingResult;
typedef AsyncResult<GetMatchmakingStatusResult> AsyncGetMatchmakingStatusResult;
typedef AsyncResult<UpdateMatchmakingResult> AsyncUpdateMatchmakingResult;
typedef AsyncResult<void> AsyncPasscodeBreakupGatheringResult;
typedef AsyncResult<PasscodeCreateGatheringResult> AsyncPasscodeCreateGatheringResult;
typedef AsyncResult<PasscodeDescribeJoinedUserResult> AsyncPasscodeDescribeJoinedUserResult;
typedef AsyncResult<void> AsyncPasscodeEarlyCompleteGatheringResult;
typedef AsyncResult<PasscodeJoinGatheringResult> AsyncPasscodeJoinGatheringResult;
typedef AsyncResult<void> AsyncPasscodeLeaveGatheringResult;
typedef AsyncResult<void> AsyncRoomBreakupGatheringResult;
typedef AsyncResult<RoomCreateGatheringResult> AsyncRoomCreateGatheringResult;
typedef AsyncResult<RoomDescribeGatheringResult> AsyncRoomDescribeGatheringResult;
typedef AsyncResult<RoomDescribeJoinedUserResult> AsyncRoomDescribeJoinedUserResult;
typedef AsyncResult<void> AsyncRoomEarlyCompleteGatheringResult;
typedef AsyncResult<RoomJoinGatheringResult> AsyncRoomJoinGatheringResult;
typedef AsyncResult<void> AsyncRoomLeaveGatheringResult;

class Gs2MatchmakingClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "matchmaking";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Matchmaking& obj)
    {
        writer.writeObjectStart();
        if (obj.getMatchmakingId())
        {
            writer.writePropertyName("matchmakingId");
            writer.write(*obj.getMatchmakingId());
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
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
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
        if (obj.getMaxPlayer())
        {
            writer.writePropertyName("maxPlayer");
            writer.write(*obj.getMaxPlayer());
        }
        if (obj.getCallback())
        {
            writer.writePropertyName("callback");
            writer.write(*obj.getCallback());
        }
        if (obj.getGatheringPoolName())
        {
            writer.writePropertyName("gatheringPoolName");
            writer.write(*obj.getGatheringPoolName());
        }
        if (obj.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*obj.getNotificationGameName());
        }
        if (obj.getCreateGatheringTriggerScript())
        {
            writer.writePropertyName("createGatheringTriggerScript");
            writer.write(*obj.getCreateGatheringTriggerScript());
        }
        if (obj.getCreateGatheringDoneTriggerScript())
        {
            writer.writePropertyName("createGatheringDoneTriggerScript");
            writer.write(*obj.getCreateGatheringDoneTriggerScript());
        }
        if (obj.getJoinGatheringTriggerScript())
        {
            writer.writePropertyName("joinGatheringTriggerScript");
            writer.write(*obj.getJoinGatheringTriggerScript());
        }
        if (obj.getJoinGatheringDoneTriggerScript())
        {
            writer.writePropertyName("joinGatheringDoneTriggerScript");
            writer.write(*obj.getJoinGatheringDoneTriggerScript());
        }
        if (obj.getLeaveGatheringTriggerScript())
        {
            writer.writePropertyName("leaveGatheringTriggerScript");
            writer.write(*obj.getLeaveGatheringTriggerScript());
        }
        if (obj.getLeaveGatheringDoneTriggerScript())
        {
            writer.writePropertyName("leaveGatheringDoneTriggerScript");
            writer.write(*obj.getLeaveGatheringDoneTriggerScript());
        }
        if (obj.getBreakupGatheringTriggerScript())
        {
            writer.writePropertyName("breakupGatheringTriggerScript");
            writer.write(*obj.getBreakupGatheringTriggerScript());
        }
        if (obj.getMatchmakingCompleteTriggerScript())
        {
            writer.writePropertyName("matchmakingCompleteTriggerScript");
            writer.write(*obj.getMatchmakingCompleteTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const AnybodyGathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.write(*obj.getGatheringId());
        }
        if (obj.getJoinPlayer())
        {
            writer.writePropertyName("joinPlayer");
            writer.write(*obj.getJoinPlayer());
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

    void write(detail::json::JsonWriter& writer, const CustomAutoGathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.write(*obj.getGatheringId());
        }
        if (obj.getAttribute1())
        {
            writer.writePropertyName("attribute1");
            writer.write(*obj.getAttribute1());
        }
        if (obj.getAttribute2())
        {
            writer.writePropertyName("attribute2");
            writer.write(*obj.getAttribute2());
        }
        if (obj.getAttribute3())
        {
            writer.writePropertyName("attribute3");
            writer.write(*obj.getAttribute3());
        }
        if (obj.getAttribute4())
        {
            writer.writePropertyName("attribute4");
            writer.write(*obj.getAttribute4());
        }
        if (obj.getAttribute5())
        {
            writer.writePropertyName("attribute5");
            writer.write(*obj.getAttribute5());
        }
        if (obj.getJoinPlayer())
        {
            writer.writePropertyName("joinPlayer");
            writer.write(*obj.getJoinPlayer());
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

    void write(detail::json::JsonWriter& writer, const PasscodeGathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.write(*obj.getGatheringId());
        }
        if (obj.getOwnerUserId())
        {
            writer.writePropertyName("ownerUserId");
            writer.write(*obj.getOwnerUserId());
        }
        if (obj.getPasscode())
        {
            writer.writePropertyName("passcode");
            writer.write(*obj.getPasscode());
        }
        if (obj.getJoinPlayer())
        {
            writer.writePropertyName("joinPlayer");
            writer.write(*obj.getJoinPlayer());
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

    void write(detail::json::JsonWriter& writer, const RoomGathering& obj)
    {
        writer.writeObjectStart();
        if (obj.getGatheringId())
        {
            writer.writePropertyName("gatheringId");
            writer.write(*obj.getGatheringId());
        }
        if (obj.getOwnerUserId())
        {
            writer.writePropertyName("ownerUserId");
            writer.write(*obj.getOwnerUserId());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getJoinPlayer())
        {
            writer.writePropertyName("joinPlayer");
            writer.write(*obj.getJoinPlayer());
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
    Gs2MatchmakingClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2MatchmakingClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2MatchmakingClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ギャザリングの参加者一覧を取得します<br>
     * <br>
     * マッチメイキングが成立すると 404 Not Found 応答が返るようになります。<br>
     * 404応答を返すようになる直前にコールバックエンドポイントに確定した参加者一覧情報が渡されるため、<br>
     * コールバックを受け取ってからは本APIを呼び出さないように実装するべきです。<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void anybodyDescribeJoinedUser(std::function<void(AsyncAnybodyDescribeJoinedUserResult&)> callback, AnybodyDescribeJoinedUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AnybodyDescribeJoinedUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/anybody/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * Anybodyマッチメイキングを開始します<br>
     * <br>
     * すでに存在するギャザリングに参加するか、新しいギャザリングを新規作成します。<br>
     * 戻り値で参加したギャザリングIDが返りますので、そのIDを利用して後続のAPIを利用できます。<br>
     * <br>
     * ギャザリングが成立した場合、マッチメイキングに設定したコールバックエンドポイントにギャザリング<br>
     * とそのギャザリングの参加者一覧が返されます。<br>
     * コールバック後にギャザリング情報はマッチメイキングサーバから削除され、後続のAPIも利用できなくなります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void anybodyDoMatchmaking(std::function<void(AsyncAnybodyDoMatchmakingResult&)> callback, AnybodyDoMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AnybodyDoMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/anybody");
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
     * ギャザリングから離脱します<br>
     * <br>
     * 本APIは確実に成功することを保証していません。<br>
     * 例えば、離脱する直前にギャザリングが成立した場合は 404 Not Found を応答します。<br>
     * <br>
     * 404応答を受け取った場合はすでにギャザリングが成立していないかを確認する必要があります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void anybodyLeaveGathering(std::function<void(AsyncAnybodyLeaveGatheringResult&)> callback, AnybodyLeaveGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/anybody/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングの参加者一覧を取得します<br>
     * <br>
     * マッチメイキングが成立すると 404 Not Found 応答が返るようになります。<br>
     * 404応答を返すようになる直前にコールバックエンドポイントに確定した参加者一覧情報が渡されるため、<br>
     * コールバックを受け取ってからは本APIを呼び出さないように実装するべきです。<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void customAutoDescribeJoinedUser(std::function<void(AsyncCustomAutoDescribeJoinedUserResult&)> callback, CustomAutoDescribeJoinedUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CustomAutoDescribeJoinedUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/customauto/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カスタムオートマッチメイキングを開始します<br>
     * <br>
     * カスタムオートマッチメイキングは最大5つの属性値を指定してギャザリングを作成するか、<br>
     * すでに存在するギャザリングの最大5つの属性値で、すべての属性値が指定した範囲内に収まっているギャザリングに参加します。<br>
     * <br>
     * ギャザリングへの参加が成功した場合は done に true が返ります。<br>
     * done に true が返った場合は、同時に item に参加したギャザリングの情報が格納されています。<br>
     * <br>
     * done に false が返った場合は、一定時間内に存在するギャザリングの検索が完了しなかった場合に返ります。<br>
     * この場合、searchContext に検索を継続するための情報が返ります。<br>
     * 引き続き検索を続けるために、再度APIを呼び出す際に引数に指定することで検索を再開することができます。<br>
     * <br>
     * すべてのギャザリングを検索したが、条件にマッチするものがなかった場合、新しいギャザリングを作成し done に true が返ります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void customAutoDoMatchmaking(std::function<void(AsyncCustomAutoDoMatchmakingResult&)> callback, CustomAutoDoMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CustomAutoDoMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/customauto");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAttribute1())
        {
            writer.writePropertyName("attribute1");
            writer.write(*request.getAttribute1());
        }
        if (request.getAttribute2())
        {
            writer.writePropertyName("attribute2");
            writer.write(*request.getAttribute2());
        }
        if (request.getAttribute3())
        {
            writer.writePropertyName("attribute3");
            writer.write(*request.getAttribute3());
        }
        if (request.getAttribute4())
        {
            writer.writePropertyName("attribute4");
            writer.write(*request.getAttribute4());
        }
        if (request.getAttribute5())
        {
            writer.writePropertyName("attribute5");
            writer.write(*request.getAttribute5());
        }
        if (request.getSearchAttribute1Min())
        {
            writer.writePropertyName("searchAttribute1Min");
            writer.write(*request.getSearchAttribute1Min());
        }
        if (request.getSearchAttribute2Min())
        {
            writer.writePropertyName("searchAttribute2Min");
            writer.write(*request.getSearchAttribute2Min());
        }
        if (request.getSearchAttribute3Min())
        {
            writer.writePropertyName("searchAttribute3Min");
            writer.write(*request.getSearchAttribute3Min());
        }
        if (request.getSearchAttribute4Min())
        {
            writer.writePropertyName("searchAttribute4Min");
            writer.write(*request.getSearchAttribute4Min());
        }
        if (request.getSearchAttribute5Min())
        {
            writer.writePropertyName("searchAttribute5Min");
            writer.write(*request.getSearchAttribute5Min());
        }
        if (request.getSearchAttribute1Max())
        {
            writer.writePropertyName("searchAttribute1Max");
            writer.write(*request.getSearchAttribute1Max());
        }
        if (request.getSearchAttribute2Max())
        {
            writer.writePropertyName("searchAttribute2Max");
            writer.write(*request.getSearchAttribute2Max());
        }
        if (request.getSearchAttribute3Max())
        {
            writer.writePropertyName("searchAttribute3Max");
            writer.write(*request.getSearchAttribute3Max());
        }
        if (request.getSearchAttribute4Max())
        {
            writer.writePropertyName("searchAttribute4Max");
            writer.write(*request.getSearchAttribute4Max());
        }
        if (request.getSearchAttribute5Max())
        {
            writer.writePropertyName("searchAttribute5Max");
            writer.write(*request.getSearchAttribute5Max());
        }
        if (request.getSearchContext())
        {
            writer.writePropertyName("searchContext");
            writer.write(*request.getSearchContext());
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
     * ギャザリングから離脱します<br>
     * <br>
     * 本APIは確実に成功することを保証していません。<br>
     * 例えば、離脱する直前にギャザリングが成立した場合は 404 Not Found を応答します。<br>
     * <br>
     * 404応答を受け取った場合はすでにギャザリングが成立していないかを確認する必要があります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void customAutoLeaveGathering(std::function<void(AsyncCustomAutoLeaveGatheringResult&)> callback, CustomAutoLeaveGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/customauto/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMatchmaking(std::function<void(AsyncCreateMatchmakingResult&)> callback, CreateMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking");
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
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.write(*request.getType());
        }
        if (request.getMaxPlayer())
        {
            writer.writePropertyName("maxPlayer");
            writer.write(*request.getMaxPlayer());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getGatheringPoolName())
        {
            writer.writePropertyName("gatheringPoolName");
            writer.write(*request.getGatheringPoolName());
        }
        if (request.getCallback())
        {
            writer.writePropertyName("callback");
            writer.write(*request.getCallback());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
        }
        if (request.getCreateGatheringTriggerScript())
        {
            writer.writePropertyName("createGatheringTriggerScript");
            writer.write(*request.getCreateGatheringTriggerScript());
        }
        if (request.getCreateGatheringDoneTriggerScript())
        {
            writer.writePropertyName("createGatheringDoneTriggerScript");
            writer.write(*request.getCreateGatheringDoneTriggerScript());
        }
        if (request.getJoinGatheringTriggerScript())
        {
            writer.writePropertyName("joinGatheringTriggerScript");
            writer.write(*request.getJoinGatheringTriggerScript());
        }
        if (request.getJoinGatheringDoneTriggerScript())
        {
            writer.writePropertyName("joinGatheringDoneTriggerScript");
            writer.write(*request.getJoinGatheringDoneTriggerScript());
        }
        if (request.getLeaveGatheringTriggerScript())
        {
            writer.writePropertyName("leaveGatheringTriggerScript");
            writer.write(*request.getLeaveGatheringTriggerScript());
        }
        if (request.getLeaveGatheringDoneTriggerScript())
        {
            writer.writePropertyName("leaveGatheringDoneTriggerScript");
            writer.write(*request.getLeaveGatheringDoneTriggerScript());
        }
        if (request.getBreakupGatheringTriggerScript())
        {
            writer.writePropertyName("breakupGatheringTriggerScript");
            writer.write(*request.getBreakupGatheringTriggerScript());
        }
        if (request.getMatchmakingCompleteTriggerScript())
        {
            writer.writePropertyName("matchmakingCompleteTriggerScript");
            writer.write(*request.getMatchmakingCompleteTriggerScript());
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
     * マッチメイキングを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMatchmaking(std::function<void(AsyncDeleteMatchmakingResult&)> callback, DeleteMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMatchmaking(std::function<void(AsyncDescribeMatchmakingResult&)> callback, DescribeMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking");
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
            url.append("/matchmaking/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMatchmaking(std::function<void(AsyncGetMatchmakingResult&)> callback, GetMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングのステータスを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMatchmakingStatus(std::function<void(AsyncGetMatchmakingStatusResult&)> callback, GetMatchmakingStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMatchmakingStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMatchmaking(std::function<void(AsyncUpdateMatchmakingResult&)> callback, UpdateMatchmakingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateMatchmakingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("");
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
        if (request.getGatheringPoolName())
        {
            writer.writePropertyName("gatheringPoolName");
            writer.write(*request.getGatheringPoolName());
        }
        if (request.getCallback())
        {
            writer.writePropertyName("callback");
            writer.write(*request.getCallback());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
        }
        if (request.getCreateGatheringTriggerScript())
        {
            writer.writePropertyName("createGatheringTriggerScript");
            writer.write(*request.getCreateGatheringTriggerScript());
        }
        if (request.getCreateGatheringDoneTriggerScript())
        {
            writer.writePropertyName("createGatheringDoneTriggerScript");
            writer.write(*request.getCreateGatheringDoneTriggerScript());
        }
        if (request.getJoinGatheringTriggerScript())
        {
            writer.writePropertyName("joinGatheringTriggerScript");
            writer.write(*request.getJoinGatheringTriggerScript());
        }
        if (request.getJoinGatheringDoneTriggerScript())
        {
            writer.writePropertyName("joinGatheringDoneTriggerScript");
            writer.write(*request.getJoinGatheringDoneTriggerScript());
        }
        if (request.getLeaveGatheringTriggerScript())
        {
            writer.writePropertyName("leaveGatheringTriggerScript");
            writer.write(*request.getLeaveGatheringTriggerScript());
        }
        if (request.getLeaveGatheringDoneTriggerScript())
        {
            writer.writePropertyName("leaveGatheringDoneTriggerScript");
            writer.write(*request.getLeaveGatheringDoneTriggerScript());
        }
        if (request.getBreakupGatheringTriggerScript())
        {
            writer.writePropertyName("breakupGatheringTriggerScript");
            writer.write(*request.getBreakupGatheringTriggerScript());
        }
        if (request.getMatchmakingCompleteTriggerScript())
        {
            writer.writePropertyName("matchmakingCompleteTriggerScript");
            writer.write(*request.getMatchmakingCompleteTriggerScript());
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
     * ギャザリングを解散します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeBreakupGathering(std::function<void(AsyncPasscodeBreakupGatheringResult&)> callback, PasscodeBreakupGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * パスコード付きギャザリングを新規作成します<br>
     * <br>
     * パスコードは8桁の数字で構成されたものが自動的に発行されます。<br>
     * パスコードの解像度的に秒間100を超える勢いでギャザリングを作成する必要がある場合は<br>
     * オートマッチメイキングと組み合わせる必要があります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeCreateGathering(std::function<void(AsyncPasscodeCreateGatheringResult&)> callback, PasscodeCreateGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PasscodeCreateGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode");
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
     * ギャザリングの参加者一覧を取得します<br>
     * <br>
     * マッチメイキングが成立すると 404 Not Found 応答が返るようになります。<br>
     * 404応答を返すようになる直前にコールバックエンドポイントに確定した参加者一覧情報が渡されるため、<br>
     * コールバックを受け取ってからは本APIを呼び出さないように実装するべきです。<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeDescribeJoinedUser(std::function<void(AsyncPasscodeDescribeJoinedUserResult&)> callback, PasscodeDescribeJoinedUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PasscodeDescribeJoinedUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングを早期終了します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeEarlyCompleteGathering(std::function<void(AsyncPasscodeEarlyCompleteGatheringResult&)> callback, PasscodeEarlyCompleteGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/complete");
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
     * パスコード付きギャザリングに参加します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeJoinGathering(std::function<void(AsyncPasscodeJoinGatheringResult&)> callback, PasscodeJoinGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PasscodeJoinGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode/join/").append(detail::StringUtil::toStr(buffer, request.getPasscode())).append("");
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
     * ギャザリングから離脱します<br>
     * <br>
     * 本APIは確実に成功することを保証していません。<br>
     * 例えば、離脱する直前にギャザリングが成立した場合は 404 Not Found を応答します。<br>
     * <br>
     * 404応答を受け取った場合はすでにギャザリングが成立していないかを確認する必要があります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void passcodeLeaveGathering(std::function<void(AsyncPasscodeLeaveGatheringResult&)> callback, PasscodeLeaveGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/passcode/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングを解散します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomBreakupGathering(std::function<void(AsyncRoomBreakupGatheringResult&)> callback, RoomBreakupGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ギャザリングを新規作成します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomCreateGathering(std::function<void(AsyncRoomCreateGatheringResult&)> callback, RoomCreateGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RoomCreateGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
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
     * ギャザリング一覧を取得します<br>
     * <br>
     * - 消費クオータ: 20件あたり3クオータ<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomDescribeGathering(std::function<void(AsyncRoomDescribeGatheringResult&)> callback, RoomDescribeGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RoomDescribeGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room");
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
     * ギャザリングの参加者一覧を取得します<br>
     * <br>
     * マッチメイキングが成立すると 404 Not Found 応答が返るようになります。<br>
     * 404応答を返すようになる直前にコールバックエンドポイントに確定した参加者一覧情報が渡されるため、<br>
     * コールバックを受け取ってからは本APIを呼び出さないように実装するべきです。<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomDescribeJoinedUser(std::function<void(AsyncRoomDescribeJoinedUserResult&)> callback, RoomDescribeJoinedUserRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RoomDescribeJoinedUserResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * マッチメイキングを早期終了します<br>
     * <br>
     *     - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomEarlyCompleteGathering(std::function<void(AsyncRoomEarlyCompleteGatheringResult&)> callback, RoomEarlyCompleteGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/complete");
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
     * ギャザリングに参加します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomJoinGathering(std::function<void(AsyncRoomJoinGatheringResult&)> callback, RoomJoinGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RoomJoinGatheringResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("");
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
     * ギャザリングから離脱します<br>
     * <br>
     * 本APIは確実に成功することを保証していません。<br>
     * 例えば、離脱する直前にギャザリングが成立した場合は 404 Not Found を応答します。<br>
     * <br>
     * 404応答を受け取った場合はすでにギャザリングが成立していないかを確認する必要があります。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void roomLeaveGathering(std::function<void(AsyncRoomLeaveGatheringResult&)> callback, RoomLeaveGatheringRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/matchmaking/").append(detail::StringUtil::toStr(buffer, request.getMatchmakingName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getGatheringId())).append("/player");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGCLIENT_HPP_