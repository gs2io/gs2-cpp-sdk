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

#ifndef GS2_MONEY_GS2MONEYCLIENT_HPP_
#define GS2_MONEY_GS2MONEYCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace money {

typedef AsyncResult<CreateItemResult> AsyncCreateItemResult;
typedef AsyncResult<void> AsyncDeleteItemResult;
typedef AsyncResult<DescribeItemResult> AsyncDescribeItemResult;
typedef AsyncResult<GetItemResult> AsyncGetItemResult;
typedef AsyncResult<UpdateItemResult> AsyncUpdateItemResult;
typedef AsyncResult<CreateMoneyResult> AsyncCreateMoneyResult;
typedef AsyncResult<void> AsyncDeleteMoneyResult;
typedef AsyncResult<DescribeMoneyResult> AsyncDescribeMoneyResult;
typedef AsyncResult<GetMoneyResult> AsyncGetMoneyResult;
typedef AsyncResult<GetMoneyStatusResult> AsyncGetMoneyStatusResult;
typedef AsyncResult<UpdateMoneyResult> AsyncUpdateMoneyResult;
typedef AsyncResult<CreatePlatformedItemResult> AsyncCreatePlatformedItemResult;
typedef AsyncResult<void> AsyncDeletePlatformedItemResult;
typedef AsyncResult<DescribePlatformedItemResult> AsyncDescribePlatformedItemResult;
typedef AsyncResult<GetPlatformedItemResult> AsyncGetPlatformedItemResult;
typedef AsyncResult<UpdatePlatformedItemResult> AsyncUpdatePlatformedItemResult;
typedef AsyncResult<DescribeReceiptResult> AsyncDescribeReceiptResult;
typedef AsyncResult<DescribeReceiptByUserIdAndSlotResult> AsyncDescribeReceiptByUserIdAndSlotResult;
typedef AsyncResult<VerifyResult> AsyncVerifyResult;
typedef AsyncResult<void> AsyncVerifyByStampTaskResult;
typedef AsyncResult<ChargeWalletResult> AsyncChargeWalletResult;
typedef AsyncResult<ChargeWalletByStampSheetResult> AsyncChargeWalletByStampSheetResult;
typedef AsyncResult<ChargeWalletByUserIdResult> AsyncChargeWalletByUserIdResult;
typedef AsyncResult<ConsumeWalletResult> AsyncConsumeWalletResult;
typedef AsyncResult<ConsumeWalletByStampTaskResult> AsyncConsumeWalletByStampTaskResult;
typedef AsyncResult<ConsumeWalletByUserIdResult> AsyncConsumeWalletByUserIdResult;
typedef AsyncResult<DescribeWalletResult> AsyncDescribeWalletResult;
typedef AsyncResult<GetWalletResult> AsyncGetWalletResult;
typedef AsyncResult<GetWalletByUserIdResult> AsyncGetWalletByUserIdResult;
typedef AsyncResult<GetWalletDetailResult> AsyncGetWalletDetailResult;

class Gs2MoneyClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "money";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Money& obj)
    {
        writer.writeObjectStart();
        if (obj.getMoneyId())
        {
            writer.writePropertyName("moneyId");
            writer.write(*obj.getMoneyId());
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
        if (obj.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*obj.getPriority());
        }
        if (obj.getShareFree())
        {
            writer.writePropertyName("shareFree");
            writer.write(*obj.getShareFree());
        }
        if (obj.getCurrency())
        {
            writer.writePropertyName("currency");
            writer.write(*obj.getCurrency());
        }
        if (obj.getUseVerifyReceipt())
        {
            writer.writePropertyName("useVerifyReceipt");
            writer.write(*obj.getUseVerifyReceipt());
        }
        if (obj.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.write(*obj.getAppleKey());
        }
        if (obj.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.write(*obj.getGoogleKey());
        }
        if (obj.getBalance())
        {
            writer.writePropertyName("balance");
            writer.write(*obj.getBalance());
        }
        if (obj.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*obj.getCreateWalletTriggerScript());
        }
        if (obj.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*obj.getCreateWalletDoneTriggerScript());
        }
        if (obj.getChargeWalletTriggerScript())
        {
            writer.writePropertyName("chargeWalletTriggerScript");
            writer.write(*obj.getChargeWalletTriggerScript());
        }
        if (obj.getChargeWalletDoneTriggerScript())
        {
            writer.writePropertyName("chargeWalletDoneTriggerScript");
            writer.write(*obj.getChargeWalletDoneTriggerScript());
        }
        if (obj.getConsumeWalletTriggerScript())
        {
            writer.writePropertyName("consumeWalletTriggerScript");
            writer.write(*obj.getConsumeWalletTriggerScript());
        }
        if (obj.getConsumeWalletDoneTriggerScript())
        {
            writer.writePropertyName("consumeWalletDoneTriggerScript");
            writer.write(*obj.getConsumeWalletDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Item& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemId())
        {
            writer.writePropertyName("itemId");
            writer.write(*obj.getItemId());
        }
        if (obj.getMoneyId())
        {
            writer.writePropertyName("moneyId");
            writer.write(*obj.getMoneyId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
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

    void write(detail::json::JsonWriter& writer, const PlatformedItem& obj)
    {
        writer.writeObjectStart();
        if (obj.getPlatformedItemId())
        {
            writer.writePropertyName("platformedItemId");
            writer.write(*obj.getPlatformedItemId());
        }
        if (obj.getMoneyId())
        {
            writer.writePropertyName("moneyId");
            writer.write(*obj.getMoneyId());
        }
        if (obj.getItemId())
        {
            writer.writePropertyName("itemId");
            writer.write(*obj.getItemId());
        }
        if (obj.getPlatform())
        {
            writer.writePropertyName("platform");
            writer.write(*obj.getPlatform());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*obj.getPrice());
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

    void write(detail::json::JsonWriter& writer, const Summary& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            writer.writePropertyName("slot");
            writer.write(*obj.getSlot());
        }
        if (obj.getPaid())
        {
            writer.writePropertyName("paid");
            writer.write(*obj.getPaid());
        }
        if (obj.getFree())
        {
            writer.writePropertyName("free");
            writer.write(*obj.getFree());
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

    void write(detail::json::JsonWriter& writer, const Wallet& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*obj.getPrice());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Receipt& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            writer.writePropertyName("slot");
            writer.write(*obj.getSlot());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*obj.getPrice());
        }
        if (obj.getPaid())
        {
            writer.writePropertyName("paid");
            writer.write(*obj.getPaid());
        }
        if (obj.getFree())
        {
            writer.writePropertyName("free");
            writer.write(*obj.getFree());
        }
        if (obj.getTotal())
        {
            writer.writePropertyName("total");
            writer.write(*obj.getTotal());
        }
        if (obj.getUse())
        {
            writer.writePropertyName("use");
            writer.write(*obj.getUse());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2MoneyClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2MoneyClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2MoneyClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 商品を新規作成します<br>
     * <br>
     * このデータは GS2-Money のレシート検証機能を利用するときにのみ登録する必要があります。<br>
     * これはレシート検証の結果妥当だった場合対価として課金通貨を付与するために、<br>
     * どのような価値の課金通貨をいくらで販売しているのかという情報を GS2-Money が持っていなければサービスを実現できないためです。<br>
     * <br>
     * - 商品(課金通貨 60個)<br>
     * -- プラットフォーム個別商品(AppleAppStore 120円)<br>
     * -- プラットフォーム個別商品(GooglePlay 120円)<br>
     * <br>
     * という構造で商品を登録する必要があります。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItem(std::function<void(AsyncCreateItemResult&)> callback, CreateItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
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
     * 商品を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItem(std::function<void(AsyncDeleteItemResult&)> callback, DeleteItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 商品の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItem(std::function<void(AsyncDescribeItemResult&)> callback, DescribeItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item");
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
     * 商品を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItem(std::function<void(AsyncGetItemResult&)> callback, GetItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 商品を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItem(std::function<void(AsyncUpdateItemResult&)> callback, UpdateItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
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
     * 課金通貨を新規作成します<br>
     * <br>
     * priority には課金通貨の消費優先度を指定することが出来ます。<br>
     * 無償課金通貨を優先して消費する場合は free を、有償課金通貨を優先して消費する場合は paid を指定します。<br>
     * 資金決済法への対応としては有償課金通貨を優先して消費するほうが未使用残高が溜まりにくく効率的ですが、<br>
     * 有償課金通貨でしか購入できないアイテムを提供している場合はユーザの心象は悪いかもしれません。<br>
     * <br>
     * ユーザごとにウォレットという財布のようなものを用意し、課金通貨はそこにチャージされます。<br>
     * ウォレットにはスロットという概念があり、各ユーザ複数の財布を持つことが出来ます。<br>
     * これはガイドラインによってプラットフォームごとに課金通貨を分けて管理する必要があるためです。<br>
     * このガイドラインは有償課金通貨にのみ適用される者で、無償課金通貨はその義務は生じません。<br>
     * そのため shareFree という設定値があり、ここを true に設定することですべてのスロットで無償課金通貨を共有することができるようになります。<br>
     * この際、あらゆるスロットにアクセスしても無償課金通貨に関してはスロット0の課金通貨が利用される。という挙動を取ります。<br>
     * <br>
     * useVerifyReceipt で課金時に各プラットフォームから取得できるレシートを検証する機能を利用できるようになります。<br>
     * レシートの検証機能を利用する場合は各プラットフォームごとに検証に必要な要素を登録しておく必要があります。<br>
     * <br>
     * AppleAppStore におけるレシートの検証を実現するには appleKey を指定します。<br>
     * appleKey にはアプリケーションの bundle_id を指定してください。<br>
     * 異なるアプリケーションで決済されたトランザクションで課金通貨をチャージすることを防ぐ意味があります。<br>
     * <br>
     * GooglePlay におけるレシートの検証を実現するには googleKey を指定します。<br>
     * googleKey には Google Play Developer Console で取得できる公開鍵を指定してください。<br>
     * レシートが改ざんされていないか検証するために利用します。<br>
     * <br>
     * GS2-Money は資金決済法における前払式支払手段(自家型)に対応します。<br>
     * マネージメントコンソールやAPIで取得できる未使用残高が1,000万円を超えると法的な責任が発生します。<br>
     * 詳しくはドキュメントを参照してください。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMoney(std::function<void(AsyncCreateMoneyResult&)> callback, CreateMoneyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateMoneyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*request.getPriority());
        }
        if (request.getShareFree())
        {
            writer.writePropertyName("shareFree");
            writer.write(*request.getShareFree());
        }
        if (request.getCurrency())
        {
            writer.writePropertyName("currency");
            writer.write(*request.getCurrency());
        }
        if (request.getUseVerifyReceipt())
        {
            writer.writePropertyName("useVerifyReceipt");
            writer.write(*request.getUseVerifyReceipt());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.write(*request.getAppleKey());
        }
        if (request.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.write(*request.getGoogleKey());
        }
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getChargeWalletTriggerScript())
        {
            writer.writePropertyName("chargeWalletTriggerScript");
            writer.write(*request.getChargeWalletTriggerScript());
        }
        if (request.getChargeWalletDoneTriggerScript())
        {
            writer.writePropertyName("chargeWalletDoneTriggerScript");
            writer.write(*request.getChargeWalletDoneTriggerScript());
        }
        if (request.getConsumeWalletTriggerScript())
        {
            writer.writePropertyName("consumeWalletTriggerScript");
            writer.write(*request.getConsumeWalletTriggerScript());
        }
        if (request.getConsumeWalletDoneTriggerScript())
        {
            writer.writePropertyName("consumeWalletDoneTriggerScript");
            writer.write(*request.getConsumeWalletDoneTriggerScript());
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
     * 課金通貨を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMoney(std::function<void(AsyncDeleteMoneyResult&)> callback, DeleteMoneyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 課金通貨の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMoney(std::function<void(AsyncDescribeMoneyResult&)> callback, DescribeMoneyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMoneyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money");
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
     * 課金通貨を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoney(std::function<void(AsyncGetMoneyResult&)> callback, GetMoneyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMoneyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 課金通貨の状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoneyStatus(std::function<void(AsyncGetMoneyStatusResult&)> callback, GetMoneyStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMoneyStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 課金通貨を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMoney(std::function<void(AsyncUpdateMoneyResult&)> callback, UpdateMoneyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateMoneyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*request.getPriority());
        }
        if (request.getUseVerifyReceipt())
        {
            writer.writePropertyName("useVerifyReceipt");
            writer.write(*request.getUseVerifyReceipt());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.write(*request.getAppleKey());
        }
        if (request.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.write(*request.getGoogleKey());
        }
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getChargeWalletTriggerScript())
        {
            writer.writePropertyName("chargeWalletTriggerScript");
            writer.write(*request.getChargeWalletTriggerScript());
        }
        if (request.getChargeWalletDoneTriggerScript())
        {
            writer.writePropertyName("chargeWalletDoneTriggerScript");
            writer.write(*request.getChargeWalletDoneTriggerScript());
        }
        if (request.getConsumeWalletTriggerScript())
        {
            writer.writePropertyName("consumeWalletTriggerScript");
            writer.write(*request.getConsumeWalletTriggerScript());
        }
        if (request.getConsumeWalletDoneTriggerScript())
        {
            writer.writePropertyName("consumeWalletDoneTriggerScript");
            writer.write(*request.getConsumeWalletDoneTriggerScript());
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
     * プラットフォーム個別商品を新規作成します<br>
     * <br>
     * name には各プラットフォームの管理コンソールで作成した消費型アイテムの名前を指定してください。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPlatformedItem(std::function<void(AsyncCreatePlatformedItemResult&)> callback, CreatePlatformedItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreatePlatformedItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/platformedItem");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPlatform())
        {
            writer.writePropertyName("platform");
            writer.write(*request.getPlatform());
        }
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
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
     * プラットフォーム個別商品を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePlatformedItem(std::function<void(AsyncDeletePlatformedItemResult&)> callback, DeletePlatformedItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/platformedItem/").append(detail::StringUtil::toStr(buffer, request.getPlatform())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * プラットフォーム個別商品の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePlatformedItem(std::function<void(AsyncDescribePlatformedItemResult&)> callback, DescribePlatformedItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribePlatformedItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/platformedItem");
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
     * プラットフォーム個別商品を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPlatformedItem(std::function<void(AsyncGetPlatformedItemResult&)> callback, GetPlatformedItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetPlatformedItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/platformedItem/").append(detail::StringUtil::toStr(buffer, request.getPlatform())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * プラットフォーム個別商品を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePlatformedItem(std::function<void(AsyncUpdatePlatformedItemResult&)> callback, UpdatePlatformedItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdatePlatformedItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/platformedItem/").append(detail::StringUtil::toStr(buffer, request.getPlatform())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
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
     * レシートを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipt(std::function<void(AsyncDescribeReceiptResult&)> callback, DescribeReceiptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeReceiptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/receipt");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
        }
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
     * 指定したユーザ・スロット番号のレシートを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiptByUserIdAndSlot(std::function<void(AsyncDescribeReceiptByUserIdAndSlotResult&)> callback, DescribeReceiptByUserIdAndSlotRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeReceiptByUserIdAndSlotResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/receipt/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
        }
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
     * レシートを検証する<br>
     * <br>
     * 下記フォーマットのレシートをPOSTすることでレシートを検証し、課金通貨のチャージまでアトミックに実行できます。<br>
     * {<br>
     *   "Store": ストア名,<br>
     *   "TransactionID": トランザクションID,<br>
     *   "Payload": レシート本体<br>
     * }<br>
     * <br>
     * 現在ストア名には<br>
     * - AppleAppStore<br>
     * - GooglePlay<br>
     * が指定できます。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verify(std::function<void(AsyncVerifyResult&)> callback, VerifyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<VerifyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/verify");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSlot())
        {
            writer.writePropertyName("slot");
            writer.write(*request.getSlot());
        }
        if (request.getReceipt())
        {
            writer.writePropertyName("receipt");
            writer.write(*request.getReceipt());
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
     * スタンプタスクを使用してレシートを検証する<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void verifyByStampTask(std::function<void(AsyncVerifyByStampTaskResult&)> callback, VerifyByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/verify/stampTask");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTask())
        {
            writer.writePropertyName("task");
            writer.write(*request.getTask());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
        }
        if (request.getReceipt())
        {
            writer.writePropertyName("receipt");
            writer.write(*request.getReceipt());
        }
        if (request.getSlot())
        {
            writer.writePropertyName("slot");
            writer.write(*request.getSlot());
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
     * ウォレットに課金通貨をチャージします<br>
     * <br>
     * trasactionId にトランザクションIDを指定することで、<br>
     * 1回の課金処理で複数回課金通貨をチャージすることを防ぐことが出来ます。<br>
     * 重複したリクエストが発生した場合は 409エラー(ConflictException) が発生しますが、正常処理とするべきです。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void chargeWallet(std::function<void(AsyncChargeWalletResult&)> callback, ChargeWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChargeWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/charge");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
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
     * スタンプシートを使用してウォレットに課金通貨をチャージします<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void chargeWalletByStampSheet(std::function<void(AsyncChargeWalletByStampSheetResult&)> callback, ChargeWalletByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChargeWalletByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/stampSheet/charge");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSheet())
        {
            writer.writePropertyName("sheet");
            writer.write(*request.getSheet());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
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
     * ウォレットに課金通貨をチャージします<br>
     * <br>
     * trasactionId にトランザクションIDを指定することで、<br>
     * 1回の課金処理で複数回課金通貨をチャージすることを防ぐことが出来ます。<br>
     * 重複したリクエストが発生した場合は 409エラー(ConflictException) が発生しますが、正常処理とするべきです。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void chargeWalletByUserId(std::function<void(AsyncChargeWalletByUserIdResult&)> callback, ChargeWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChargeWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/charge");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
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
     * ウォレットから課金通貨を消費します<br>
     * <br>
     * paidOnly に true を指定することで、有償課金通貨のみ消費対象とすることが出来ます。<br>
     * プレミアムなサービスの提供時などに活用してください。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeWallet(std::function<void(AsyncConsumeWalletResult&)> callback, ConsumeWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/consume");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getUse())
        {
            writer.writePropertyName("use");
            writer.write(*request.getUse());
        }
        if (request.getPaidOnly())
        {
            writer.writePropertyName("paidOnly");
            writer.write(*request.getPaidOnly());
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
     * スタンプタスクを使用してウォレットから課金通貨を消費します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeWalletByStampTask(std::function<void(AsyncConsumeWalletByStampTaskResult&)> callback, ConsumeWalletByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeWalletByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/stampTask/consume");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTask())
        {
            writer.writePropertyName("task");
            writer.write(*request.getTask());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
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
     * ウォレットの課金通貨を消費します<br>
     * <br>
     * trasactionId にトランザクションIDを指定することで、<br>
     * 1回の課金処理で複数回課金通貨を消費することを防ぐことが出来ます。<br>
     * 重複したリクエストが発生した場合は 409エラー(ConflictException) が発生しますが、正常処理とするべきです。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeWalletByUserId(std::function<void(AsyncConsumeWalletByUserIdResult&)> callback, ConsumeWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/consume");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getUse())
        {
            writer.writePropertyName("use");
            writer.write(*request.getUse());
        }
        if (request.getPaidOnly())
        {
            writer.writePropertyName("paidOnly");
            writer.write(*request.getPaidOnly());
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
     * ウォレット一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallet(std::function<void(AsyncDescribeWalletResult&)> callback, DescribeWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("userId={value}").replace("{value}", encodeBuffer) + "&";
        }
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
     * ウォレットを取得します<br>
     * <br>
     * ここでは有償課金通貨と無償課金通貨の数が取得できます。<br>
     * 有償課金通貨は単価ごとに所持数量が別途管理されています。<br>
     * 詳細な構成を取得したい場合は Gs2Money:GetWalletDetail を使ってください。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(std::function<void(AsyncGetWalletResult&)> callback, GetWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザIDを指定してウォレットを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(std::function<void(AsyncGetWalletByUserIdResult&)> callback, GetWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットの詳細を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletDetail(std::function<void(AsyncGetWalletDetailResult&)> callback, GetWalletDetailRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletDetailResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/money/").append(detail::StringUtil::toStr(buffer, request.getMoneyName())).append("/wallet/").append(detail::StringUtil::toStr(buffer, request.getSlot())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/detail");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_MONEY_GS2MONEYCLIENT_HPP_