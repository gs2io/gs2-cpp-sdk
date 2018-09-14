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

#ifndef GS2_SHOWCASE_GS2SHOWCASECLIENT_HPP_
#define GS2_SHOWCASE_GS2SHOWCASECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

typedef AsyncResult<GetCurrentShowcaseMasterResult> AsyncGetCurrentShowcaseMasterResult;
typedef AsyncResult<UpdateCurrentShowcaseMasterResult> AsyncUpdateCurrentShowcaseMasterResult;
typedef AsyncResult<CreateItemGroupMasterResult> AsyncCreateItemGroupMasterResult;
typedef AsyncResult<void> AsyncDeleteItemGroupMasterResult;
typedef AsyncResult<DescribeItemGroupMasterResult> AsyncDescribeItemGroupMasterResult;
typedef AsyncResult<GetItemGroupMasterResult> AsyncGetItemGroupMasterResult;
typedef AsyncResult<UpdateItemGroupMasterResult> AsyncUpdateItemGroupMasterResult;
typedef AsyncResult<CreateItemMasterResult> AsyncCreateItemMasterResult;
typedef AsyncResult<void> AsyncDeleteItemMasterResult;
typedef AsyncResult<DescribeItemMasterResult> AsyncDescribeItemMasterResult;
typedef AsyncResult<GetItemMasterResult> AsyncGetItemMasterResult;
typedef AsyncResult<UpdateItemMasterResult> AsyncUpdateItemMasterResult;
typedef AsyncResult<BuyItemResult> AsyncBuyItemResult;
typedef AsyncResult<DescribeItemResult> AsyncDescribeItemResult;
typedef AsyncResult<GetItemResult> AsyncGetItemResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<CreateShowcaseItemMasterResult> AsyncCreateShowcaseItemMasterResult;
typedef AsyncResult<void> AsyncDeleteShowcaseItemMasterResult;
typedef AsyncResult<DescribeShowcaseItemMasterResult> AsyncDescribeShowcaseItemMasterResult;
typedef AsyncResult<GetShowcaseItemMasterResult> AsyncGetShowcaseItemMasterResult;
typedef AsyncResult<UpdateShowcaseItemMasterResult> AsyncUpdateShowcaseItemMasterResult;
typedef AsyncResult<CreateShowcaseResult> AsyncCreateShowcaseResult;
typedef AsyncResult<void> AsyncDeleteShowcaseResult;
typedef AsyncResult<DescribeShowcaseResult> AsyncDescribeShowcaseResult;
typedef AsyncResult<GetShowcaseResult> AsyncGetShowcaseResult;
typedef AsyncResult<GetShowcaseStatusResult> AsyncGetShowcaseStatusResult;
typedef AsyncResult<UpdateShowcaseResult> AsyncUpdateShowcaseResult;

class Gs2ShowcaseClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "showcase";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Showcase& obj)
    {
        writer.writeObjectStart();
        if (obj.getShowcaseId())
        {
            writer.writePropertyName("showcaseId");
            writer.write(*obj.getShowcaseId());
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
        if (obj.getReleaseConditionTriggerScript())
        {
            writer.writePropertyName("releaseConditionTriggerScript");
            writer.write(*obj.getReleaseConditionTriggerScript());
        }
        if (obj.getBuyTriggerScript())
        {
            writer.writePropertyName("buyTriggerScript");
            writer.write(*obj.getBuyTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const ShowcaseItemMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getShowcaseItemId())
        {
            writer.writePropertyName("showcaseItemId");
            writer.write(*obj.getShowcaseItemId());
        }
        if (obj.getCategory())
        {
            writer.writePropertyName("category");
            writer.write(*obj.getCategory());
        }
        if (obj.getItemName())
        {
            writer.writePropertyName("itemName");
            writer.write(*obj.getItemName());
        }
        if (obj.getItemGroupName())
        {
            writer.writePropertyName("itemGroupName");
            writer.write(*obj.getItemGroupName());
        }
        if (obj.getReleaseConditionType())
        {
            writer.writePropertyName("releaseConditionType");
            writer.write(*obj.getReleaseConditionType());
        }
        if (obj.getReleaseConditionScheduleName())
        {
            writer.writePropertyName("releaseConditionScheduleName");
            writer.write(*obj.getReleaseConditionScheduleName());
        }
        if (obj.getReleaseConditionScheduleEventName())
        {
            writer.writePropertyName("releaseConditionScheduleEventName");
            writer.write(*obj.getReleaseConditionScheduleEventName());
        }
        if (obj.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*obj.getPriority());
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

    void write(detail::json::JsonWriter& writer, const ItemGroupMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemGroupId())
        {
            writer.writePropertyName("itemGroupId");
            writer.write(*obj.getItemGroupId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getItemNames())
        {
            writer.writePropertyName("itemNames");
            writer.writeArrayStart();
            auto& list = *obj.getItemNames();
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

    void write(detail::json::JsonWriter& writer, const ItemMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemId())
        {
            writer.writePropertyName("itemId");
            writer.write(*obj.getItemId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getCurrencyType())
        {
            writer.writePropertyName("currencyType");
            writer.write(*obj.getCurrencyType());
        }
        if (obj.getCurrencyMoneyName())
        {
            writer.writePropertyName("currencyMoneyName");
            writer.write(*obj.getCurrencyMoneyName());
        }
        if (obj.getCurrencyGoldPoolName())
        {
            writer.writePropertyName("currencyGoldPoolName");
            writer.write(*obj.getCurrencyGoldPoolName());
        }
        if (obj.getCurrencyGoldName())
        {
            writer.writePropertyName("currencyGoldName");
            writer.write(*obj.getCurrencyGoldName());
        }
        if (obj.getCurrencyConsumableItemItemPoolName())
        {
            writer.writePropertyName("currencyConsumableItemItemPoolName");
            writer.write(*obj.getCurrencyConsumableItemItemPoolName());
        }
        if (obj.getCurrencyConsumableItemItemName())
        {
            writer.writePropertyName("currencyConsumableItemItemName");
            writer.write(*obj.getCurrencyConsumableItemItemName());
        }
        if (obj.getCurrencyOption())
        {
            writer.writePropertyName("currencyOption");
            writer.write(*obj.getCurrencyOption());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*obj.getPrice());
        }
        if (obj.getItemType())
        {
            writer.writePropertyName("itemType");
            writer.write(*obj.getItemType());
        }
        if (obj.getItemMoneyName())
        {
            writer.writePropertyName("itemMoneyName");
            writer.write(*obj.getItemMoneyName());
        }
        if (obj.getItemGoldPoolName())
        {
            writer.writePropertyName("itemGoldPoolName");
            writer.write(*obj.getItemGoldPoolName());
        }
        if (obj.getItemGoldName())
        {
            writer.writePropertyName("itemGoldName");
            writer.write(*obj.getItemGoldName());
        }
        if (obj.getItemStaminaStaminaPoolName())
        {
            writer.writePropertyName("itemStaminaStaminaPoolName");
            writer.write(*obj.getItemStaminaStaminaPoolName());
        }
        if (obj.getItemConsumableItemItemPoolName())
        {
            writer.writePropertyName("itemConsumableItemItemPoolName");
            writer.write(*obj.getItemConsumableItemItemPoolName());
        }
        if (obj.getItemConsumableItemItemName())
        {
            writer.writePropertyName("itemConsumableItemItemName");
            writer.write(*obj.getItemConsumableItemItemName());
        }
        if (obj.getItemGachaGachaPoolName())
        {
            writer.writePropertyName("itemGachaGachaPoolName");
            writer.write(*obj.getItemGachaGachaPoolName());
        }
        if (obj.getItemGachaGachaName())
        {
            writer.writePropertyName("itemGachaGachaName");
            writer.write(*obj.getItemGachaGachaName());
        }
        if (obj.getItemAmount())
        {
            writer.writePropertyName("itemAmount");
            writer.write(*obj.getItemAmount());
        }
        if (obj.getItemOption())
        {
            writer.writePropertyName("itemOption");
            writer.write(*obj.getItemOption());
        }
        if (obj.getOpenConditionType())
        {
            writer.writePropertyName("openConditionType");
            writer.write(*obj.getOpenConditionType());
        }
        if (obj.getOpenConditionLimitName())
        {
            writer.writePropertyName("openConditionLimitName");
            writer.write(*obj.getOpenConditionLimitName());
        }
        if (obj.getOpenConditionLimitCounterName())
        {
            writer.writePropertyName("openConditionLimitCounterName");
            writer.write(*obj.getOpenConditionLimitCounterName());
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
        if (obj.getShowcaseItemId())
        {
            writer.writePropertyName("showcaseItemId");
            writer.write(*obj.getShowcaseItemId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getCurrencyType())
        {
            writer.writePropertyName("currencyType");
            writer.write(*obj.getCurrencyType());
        }
        if (obj.getCurrencyMoneyName())
        {
            writer.writePropertyName("currencyMoneyName");
            writer.write(*obj.getCurrencyMoneyName());
        }
        if (obj.getCurrencyGoldPoolName())
        {
            writer.writePropertyName("currencyGoldPoolName");
            writer.write(*obj.getCurrencyGoldPoolName());
        }
        if (obj.getCurrencyGoldName())
        {
            writer.writePropertyName("currencyGoldName");
            writer.write(*obj.getCurrencyGoldName());
        }
        if (obj.getCurrencyConsumableItemItemPoolName())
        {
            writer.writePropertyName("currencyConsumableItemItemPoolName");
            writer.write(*obj.getCurrencyConsumableItemItemPoolName());
        }
        if (obj.getCurrencyConsumableItemName())
        {
            writer.writePropertyName("currencyConsumableItemName");
            writer.write(*obj.getCurrencyConsumableItemName());
        }
        if (obj.getCurrencyOption())
        {
            writer.writePropertyName("currencyOption");
            writer.write(*obj.getCurrencyOption());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*obj.getPrice());
        }
        if (obj.getItemType())
        {
            writer.writePropertyName("itemType");
            writer.write(*obj.getItemType());
        }
        if (obj.getItemMoneyName())
        {
            writer.writePropertyName("itemMoneyName");
            writer.write(*obj.getItemMoneyName());
        }
        if (obj.getItemGoldPoolName())
        {
            writer.writePropertyName("itemGoldPoolName");
            writer.write(*obj.getItemGoldPoolName());
        }
        if (obj.getItemGoldName())
        {
            writer.writePropertyName("itemGoldName");
            writer.write(*obj.getItemGoldName());
        }
        if (obj.getItemStaminaStaminaPoolName())
        {
            writer.writePropertyName("itemStaminaStaminaPoolName");
            writer.write(*obj.getItemStaminaStaminaPoolName());
        }
        if (obj.getItemConsumableItemItemPoolName())
        {
            writer.writePropertyName("itemConsumableItemItemPoolName");
            writer.write(*obj.getItemConsumableItemItemPoolName());
        }
        if (obj.getItemConsumableItemItemName())
        {
            writer.writePropertyName("itemConsumableItemItemName");
            writer.write(*obj.getItemConsumableItemItemName());
        }
        if (obj.getItemGachaGachaPoolName())
        {
            writer.writePropertyName("itemGachaGachaPoolName");
            writer.write(*obj.getItemGachaGachaPoolName());
        }
        if (obj.getItemGachaGachaName())
        {
            writer.writePropertyName("itemGachaGachaName");
            writer.write(*obj.getItemGachaGachaName());
        }
        if (obj.getItemAmount())
        {
            writer.writePropertyName("itemAmount");
            writer.write(*obj.getItemAmount());
        }
        if (obj.getItemOption())
        {
            writer.writePropertyName("itemOption");
            writer.write(*obj.getItemOption());
        }
        if (obj.getCanBuy())
        {
            writer.writePropertyName("canBuy");
            writer.write(*obj.getCanBuy());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2ShowcaseClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ShowcaseClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ShowcaseClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 公開されているショーケースマスタを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentShowcaseMaster(std::function<void(AsyncGetCurrentShowcaseMasterResult&)> callback, GetCurrentShowcaseMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentShowcaseMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/item/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 公開するショーケースマスタを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentShowcaseMaster(std::function<void(AsyncUpdateCurrentShowcaseMasterResult&)> callback, UpdateCurrentShowcaseMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentShowcaseMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/item/master");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*request.getSettings());
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
     * 商品グループを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemGroupMaster(std::function<void(AsyncCreateItemGroupMasterResult&)> callback, CreateItemGroupMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateItemGroupMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/itemGroup");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getItemNames())
        {
            writer.writePropertyName("itemNames");
            writer.writeArrayStart();
            auto& list = *request.getItemNames();
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
     * 商品グループを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemGroupMaster(std::function<void(AsyncDeleteItemGroupMasterResult&)> callback, DeleteItemGroupMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/itemGroup/").append(detail::StringUtil::toStr(buffer, request.getItemGroupName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 商品グループの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemGroupMaster(std::function<void(AsyncDescribeItemGroupMasterResult&)> callback, DescribeItemGroupMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemGroupMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/itemGroup");
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
     * 商品グループを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemGroupMaster(std::function<void(AsyncGetItemGroupMasterResult&)> callback, GetItemGroupMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemGroupMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/itemGroup/").append(detail::StringUtil::toStr(buffer, request.getItemGroupName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 商品グループを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemGroupMaster(std::function<void(AsyncUpdateItemGroupMasterResult&)> callback, UpdateItemGroupMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateItemGroupMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/itemGroup/").append(detail::StringUtil::toStr(buffer, request.getItemGroupName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getItemNames())
        {
            writer.writePropertyName("itemNames");
            writer.writeArrayStart();
            auto& list = *request.getItemNames();
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
     * 商品を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemMaster(std::function<void(AsyncCreateItemMasterResult&)> callback, CreateItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/item");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getCurrencyType())
        {
            writer.writePropertyName("currencyType");
            writer.write(*request.getCurrencyType());
        }
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
        }
        if (request.getItemType())
        {
            writer.writePropertyName("itemType");
            writer.write(*request.getItemType());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getCurrencyMoneyName())
        {
            writer.writePropertyName("currencyMoneyName");
            writer.write(*request.getCurrencyMoneyName());
        }
        if (request.getCurrencyGoldName())
        {
            writer.writePropertyName("currencyGoldName");
            writer.write(*request.getCurrencyGoldName());
        }
        if (request.getCurrencyGoldPoolName())
        {
            writer.writePropertyName("currencyGoldPoolName");
            writer.write(*request.getCurrencyGoldPoolName());
        }
        if (request.getCurrencyConsumableItemItemPoolName())
        {
            writer.writePropertyName("currencyConsumableItemItemPoolName");
            writer.write(*request.getCurrencyConsumableItemItemPoolName());
        }
        if (request.getCurrencyConsumableItemItemName())
        {
            writer.writePropertyName("currencyConsumableItemItemName");
            writer.write(*request.getCurrencyConsumableItemItemName());
        }
        if (request.getCurrencyOption())
        {
            writer.writePropertyName("currencyOption");
            writer.write(*request.getCurrencyOption());
        }
        if (request.getItemMoneyName())
        {
            writer.writePropertyName("itemMoneyName");
            writer.write(*request.getItemMoneyName());
        }
        if (request.getItemGoldPoolName())
        {
            writer.writePropertyName("itemGoldPoolName");
            writer.write(*request.getItemGoldPoolName());
        }
        if (request.getItemGoldName())
        {
            writer.writePropertyName("itemGoldName");
            writer.write(*request.getItemGoldName());
        }
        if (request.getItemStaminaStaminaPoolName())
        {
            writer.writePropertyName("itemStaminaStaminaPoolName");
            writer.write(*request.getItemStaminaStaminaPoolName());
        }
        if (request.getItemConsumableItemItemPoolName())
        {
            writer.writePropertyName("itemConsumableItemItemPoolName");
            writer.write(*request.getItemConsumableItemItemPoolName());
        }
        if (request.getItemConsumableItemItemName())
        {
            writer.writePropertyName("itemConsumableItemItemName");
            writer.write(*request.getItemConsumableItemItemName());
        }
        if (request.getItemGachaGachaPoolName())
        {
            writer.writePropertyName("itemGachaGachaPoolName");
            writer.write(*request.getItemGachaGachaPoolName());
        }
        if (request.getItemGachaGachaName())
        {
            writer.writePropertyName("itemGachaGachaName");
            writer.write(*request.getItemGachaGachaName());
        }
        if (request.getItemAmount())
        {
            writer.writePropertyName("itemAmount");
            writer.write(*request.getItemAmount());
        }
        if (request.getItemOption())
        {
            writer.writePropertyName("itemOption");
            writer.write(*request.getItemOption());
        }
        if (request.getOpenConditionType())
        {
            writer.writePropertyName("openConditionType");
            writer.write(*request.getOpenConditionType());
        }
        if (request.getOpenConditionLimitName())
        {
            writer.writePropertyName("openConditionLimitName");
            writer.write(*request.getOpenConditionLimitName());
        }
        if (request.getOpenConditionLimitCounterName())
        {
            writer.writePropertyName("openConditionLimitCounterName");
            writer.write(*request.getOpenConditionLimitCounterName());
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
    void deleteItemMaster(std::function<void(AsyncDeleteItemMasterResult&)> callback, DeleteItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
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
    void describeItemMaster(std::function<void(AsyncDescribeItemMasterResult&)> callback, DescribeItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/item");
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
    void getItemMaster(std::function<void(AsyncGetItemMasterResult&)> callback, GetItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
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
    void updateItemMaster(std::function<void(AsyncUpdateItemMasterResult&)> callback, UpdateItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCurrencyType())
        {
            writer.writePropertyName("currencyType");
            writer.write(*request.getCurrencyType());
        }
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.write(*request.getPrice());
        }
        if (request.getItemType())
        {
            writer.writePropertyName("itemType");
            writer.write(*request.getItemType());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getCurrencyMoneyName())
        {
            writer.writePropertyName("currencyMoneyName");
            writer.write(*request.getCurrencyMoneyName());
        }
        if (request.getCurrencyGoldName())
        {
            writer.writePropertyName("currencyGoldName");
            writer.write(*request.getCurrencyGoldName());
        }
        if (request.getCurrencyGoldPoolName())
        {
            writer.writePropertyName("currencyGoldPoolName");
            writer.write(*request.getCurrencyGoldPoolName());
        }
        if (request.getCurrencyConsumableItemItemPoolName())
        {
            writer.writePropertyName("currencyConsumableItemItemPoolName");
            writer.write(*request.getCurrencyConsumableItemItemPoolName());
        }
        if (request.getCurrencyConsumableItemItemName())
        {
            writer.writePropertyName("currencyConsumableItemItemName");
            writer.write(*request.getCurrencyConsumableItemItemName());
        }
        if (request.getCurrencyOption())
        {
            writer.writePropertyName("currencyOption");
            writer.write(*request.getCurrencyOption());
        }
        if (request.getItemMoneyName())
        {
            writer.writePropertyName("itemMoneyName");
            writer.write(*request.getItemMoneyName());
        }
        if (request.getItemGoldPoolName())
        {
            writer.writePropertyName("itemGoldPoolName");
            writer.write(*request.getItemGoldPoolName());
        }
        if (request.getItemGoldName())
        {
            writer.writePropertyName("itemGoldName");
            writer.write(*request.getItemGoldName());
        }
        if (request.getItemStaminaStaminaPoolName())
        {
            writer.writePropertyName("itemStaminaStaminaPoolName");
            writer.write(*request.getItemStaminaStaminaPoolName());
        }
        if (request.getItemConsumableItemItemPoolName())
        {
            writer.writePropertyName("itemConsumableItemItemPoolName");
            writer.write(*request.getItemConsumableItemItemPoolName());
        }
        if (request.getItemConsumableItemItemName())
        {
            writer.writePropertyName("itemConsumableItemItemName");
            writer.write(*request.getItemConsumableItemItemName());
        }
        if (request.getItemGachaGachaPoolName())
        {
            writer.writePropertyName("itemGachaGachaPoolName");
            writer.write(*request.getItemGachaGachaPoolName());
        }
        if (request.getItemGachaGachaName())
        {
            writer.writePropertyName("itemGachaGachaName");
            writer.write(*request.getItemGachaGachaName());
        }
        if (request.getItemAmount())
        {
            writer.writePropertyName("itemAmount");
            writer.write(*request.getItemAmount());
        }
        if (request.getItemOption())
        {
            writer.writePropertyName("itemOption");
            writer.write(*request.getItemOption());
        }
        if (request.getOpenConditionType())
        {
            writer.writePropertyName("openConditionType");
            writer.write(*request.getOpenConditionType());
        }
        if (request.getOpenConditionLimitName())
        {
            writer.writePropertyName("openConditionLimitName");
            writer.write(*request.getOpenConditionLimitName());
        }
        if (request.getOpenConditionLimitCounterName())
        {
            writer.writePropertyName("openConditionLimitCounterName");
            writer.write(*request.getOpenConditionLimitCounterName());
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
     * 購入処理を実行完了する為に必要となるスタンプシートを取得します。<br>
     * スタンプシートの詳細は GS2 ドキュメントを参照してください。<br>
     * <br>
     * このAPIによって払い出されるスタンプシートが要求するタスクは以下のアクションの可能性があります。<br>
     * <br>
     * Gs2Money:VerifyByStampTask<br>
     * Gs2Money:ConsumeWalletByStampTask<br>
     * Gs2Gold:WithdrawFromWalletByStampTask<br>
     * Gs2Stamina:ConsumeStaminaByStampTask<br>
     * Gs2ConsumableItem:ConsumeInventoryByStampTask<br>
     * Gs2Limit:UpCounterByStampTask<br>
     * <br>
     * このAPIによって払い出されるスタンプシートの完了は以下のアクションの可能性があります。<br>
     * <br>
     * Gs2Money:ChargeWalletByStampSheet<br>
     * Gs2Gold:DepositIntoWalletByStampSheet<br>
     * Gs2Stamina:ChangeStaminaByStampSheet<br>
     * Gs2ConsumableItem:AcquisitionInventoryByStampSheet<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void buyItem(std::function<void(AsyncBuyItemResult&)> callback, BuyItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<BuyItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getShowcaseItemId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * 陳列されている商品一覧を取得します<br>
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
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/item");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 陳列されている商品を取得します<br>
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
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getShowcaseItemId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ショーケースマスターデータをエクスポートする<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ExportMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 陳列商品を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createShowcaseItemMaster(std::function<void(AsyncCreateShowcaseItemMasterResult&)> callback, CreateShowcaseItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateShowcaseItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/showcaseItem");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCategory())
        {
            writer.writePropertyName("category");
            writer.write(*request.getCategory());
        }
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*request.getPriority());
        }
        if (request.getItemName())
        {
            writer.writePropertyName("itemName");
            writer.write(*request.getItemName());
        }
        if (request.getItemGroupName())
        {
            writer.writePropertyName("itemGroupName");
            writer.write(*request.getItemGroupName());
        }
        if (request.getReleaseConditionType())
        {
            writer.writePropertyName("releaseConditionType");
            writer.write(*request.getReleaseConditionType());
        }
        if (request.getReleaseConditionScheduleName())
        {
            writer.writePropertyName("releaseConditionScheduleName");
            writer.write(*request.getReleaseConditionScheduleName());
        }
        if (request.getReleaseConditionScheduleEventName())
        {
            writer.writePropertyName("releaseConditionScheduleEventName");
            writer.write(*request.getReleaseConditionScheduleEventName());
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
     * 陳列商品を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteShowcaseItemMaster(std::function<void(AsyncDeleteShowcaseItemMasterResult&)> callback, DeleteShowcaseItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/showcaseItem/").append(detail::StringUtil::toStr(buffer, request.getCategory())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 陳列商品の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcaseItemMaster(std::function<void(AsyncDescribeShowcaseItemMasterResult&)> callback, DescribeShowcaseItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeShowcaseItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/showcaseItem");
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
     * 陳列商品を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseItemMaster(std::function<void(AsyncGetShowcaseItemMasterResult&)> callback, GetShowcaseItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetShowcaseItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/showcaseItem/").append(detail::StringUtil::toStr(buffer, request.getCategory())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 陳列商品を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateShowcaseItemMaster(std::function<void(AsyncUpdateShowcaseItemMasterResult&)> callback, UpdateShowcaseItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateShowcaseItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/master/showcaseItem/").append(detail::StringUtil::toStr(buffer, request.getCategory())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getReleaseConditionType())
        {
            writer.writePropertyName("releaseConditionType");
            writer.write(*request.getReleaseConditionType());
        }
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.write(*request.getPriority());
        }
        if (request.getReleaseConditionScheduleName())
        {
            writer.writePropertyName("releaseConditionScheduleName");
            writer.write(*request.getReleaseConditionScheduleName());
        }
        if (request.getReleaseConditionScheduleEventName())
        {
            writer.writePropertyName("releaseConditionScheduleEventName");
            writer.write(*request.getReleaseConditionScheduleEventName());
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
     * ショーケースを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createShowcase(std::function<void(AsyncCreateShowcaseResult&)> callback, CreateShowcaseRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateShowcaseResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase");
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
        if (request.getReleaseConditionTriggerScript())
        {
            writer.writePropertyName("releaseConditionTriggerScript");
            writer.write(*request.getReleaseConditionTriggerScript());
        }
        if (request.getBuyTriggerScript())
        {
            writer.writePropertyName("buyTriggerScript");
            writer.write(*request.getBuyTriggerScript());
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
     * ショーケースを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteShowcase(std::function<void(AsyncDeleteShowcaseResult&)> callback, DeleteShowcaseRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ショーケースの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcase(std::function<void(AsyncDescribeShowcaseResult&)> callback, DescribeShowcaseRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeShowcaseResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase");
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
     * ショーケースを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcase(std::function<void(AsyncGetShowcaseResult&)> callback, GetShowcaseRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetShowcaseResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ショーケースの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseStatus(std::function<void(AsyncGetShowcaseStatusResult&)> callback, GetShowcaseStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetShowcaseStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ショーケースを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateShowcase(std::function<void(AsyncUpdateShowcaseResult&)> callback, UpdateShowcaseRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateShowcaseResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/showcase/").append(detail::StringUtil::toStr(buffer, request.getShowcaseName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getReleaseConditionTriggerScript())
        {
            writer.writePropertyName("releaseConditionTriggerScript");
            writer.write(*request.getReleaseConditionTriggerScript());
        }
        if (request.getBuyTriggerScript())
        {
            writer.writePropertyName("buyTriggerScript");
            writer.write(*request.getBuyTriggerScript());
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

#endif //GS2_SHOWCASE_GS2SHOWCASECLIENT_HPP_