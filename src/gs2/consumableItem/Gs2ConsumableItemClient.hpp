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

#ifndef GS2_CONSUMABLEITEM_GS2CONSUMABLEITEMCLIENT_HPP_
#define GS2_CONSUMABLEITEM_GS2CONSUMABLEITEMCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace consumableItem {

typedef AsyncResult<GetCurrentItemMasterResult> AsyncGetCurrentItemMasterResult;
typedef AsyncResult<UpdateCurrentItemMasterResult> AsyncUpdateCurrentItemMasterResult;
typedef AsyncResult<AcquisitionItemResult> AsyncAcquisitionItemResult;
typedef AsyncResult<AcquisitionItemByStampSheetResult> AsyncAcquisitionItemByStampSheetResult;
typedef AsyncResult<AcquisitionItemByUserIdResult> AsyncAcquisitionItemByUserIdResult;
typedef AsyncResult<ConsumeItemResult> AsyncConsumeItemResult;
typedef AsyncResult<ConsumeItemByStampTaskResult> AsyncConsumeItemByStampTaskResult;
typedef AsyncResult<ConsumeItemByUserIdResult> AsyncConsumeItemByUserIdResult;
typedef AsyncResult<void> AsyncDeleteInventoryByUserIdResult;
typedef AsyncResult<DescribeInventoryResult> AsyncDescribeInventoryResult;
typedef AsyncResult<DescribeInventoryByUserIdResult> AsyncDescribeInventoryByUserIdResult;
typedef AsyncResult<GetInventoryResult> AsyncGetInventoryResult;
typedef AsyncResult<GetInventoryByUserIdResult> AsyncGetInventoryByUserIdResult;
typedef AsyncResult<CreateItemMasterResult> AsyncCreateItemMasterResult;
typedef AsyncResult<void> AsyncDeleteItemMasterResult;
typedef AsyncResult<DescribeItemMasterResult> AsyncDescribeItemMasterResult;
typedef AsyncResult<GetItemMasterResult> AsyncGetItemMasterResult;
typedef AsyncResult<UpdateItemMasterResult> AsyncUpdateItemMasterResult;
typedef AsyncResult<CreateItemPoolResult> AsyncCreateItemPoolResult;
typedef AsyncResult<void> AsyncDeleteItemPoolResult;
typedef AsyncResult<DescribeItemPoolResult> AsyncDescribeItemPoolResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetItemPoolResult> AsyncGetItemPoolResult;
typedef AsyncResult<GetItemPoolStatusResult> AsyncGetItemPoolStatusResult;
typedef AsyncResult<UpdateItemPoolResult> AsyncUpdateItemPoolResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;

class Gs2ConsumableItemClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "consumable-item";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const ItemPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getItemPoolId())
        {
            writer.writePropertyName("itemPoolId");
            writer.write(*obj.getItemPoolId());
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
        if (obj.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*obj.getAcquisitionItemTriggerScript());
        }
        if (obj.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*obj.getAcquisitionItemDoneTriggerScript());
        }
        if (obj.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*obj.getConsumeItemTriggerScript());
        }
        if (obj.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*obj.getConsumeItemDoneTriggerScript());
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
        if (obj.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*obj.getMax());
        }
        if (obj.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*obj.getAcquisitionItemTriggerScript());
        }
        if (obj.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*obj.getAcquisitionItemDoneTriggerScript());
        }
        if (obj.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*obj.getConsumeItemTriggerScript());
        }
        if (obj.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*obj.getConsumeItemDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Inventory& obj)
    {
        writer.writeObjectStart();
        if (obj.getInventoryId())
        {
            writer.writePropertyName("inventoryId");
            writer.write(*obj.getInventoryId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getItemName())
        {
            writer.writePropertyName("itemName");
            writer.write(*obj.getItemName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        if (obj.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*obj.getMax());
        }
        if (obj.getExpireAt())
        {
            writer.writePropertyName("expireAt");
            writer.write(*obj.getExpireAt());
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
    Gs2ConsumableItemClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ConsumableItemClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ConsumableItemClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 公開されているアイテムマスタを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentItemMaster(std::function<void(AsyncGetCurrentItemMasterResult&)> callback, GetCurrentItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/item/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 公開するアイテムマスタを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentItemMaster(std::function<void(AsyncUpdateCurrentItemMasterResult&)> callback, UpdateCurrentItemMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentItemMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/item/master");
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
     * インベントリにアイテムを加えます<br>
     * <br>
     * 有効期限に 0 を設定すると有効期限無しになります。<br>
     * <br>
     * アイテムに所持数の上限が設定されている状態で、複数個付与することによって<br>
     * 所持数の上限を超えてしまうケースでは一切付与せずエラー応答を返します。<br>
     * <br>
     * 例えば、所持数上限 10 のアイテムで、8個所持しているユーザに 3個 付与しようとすると1個も付与せずにエラーを返します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquisitionItem(std::function<void(AsyncAcquisitionItemResult&)> callback, AcquisitionItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AcquisitionItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/my/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getExpireAt())
        {
            writer.writePropertyName("expireAt");
            writer.write(*request.getExpireAt());
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
     * スタンプシートを使用してインベントリにアイテムを加えます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquisitionItemByStampSheet(std::function<void(AsyncAcquisitionItemByStampSheetResult&)> callback, AcquisitionItemByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AcquisitionItemByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inventory");
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
     * インベントリにアイテムを加えます<br>
     * <br>
     * 有効期限に 0 を設定すると有効期限無しになります。<br>
     * <br>
     * アイテムに所持数の上限が設定されている状態で、複数個付与することによって<br>
     * 所持数の上限を超えてしまうケースでは一切付与せずエラー応答を返します。<br>
     * <br>
     * 例えば、所持数上限 10 のアイテムで、8個所持しているユーザに 3個 付与しようとすると<br>
     * 1個も付与せずにエラーを返します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquisitionItemByUserId(std::function<void(AsyncAcquisitionItemByUserIdResult&)> callback, AcquisitionItemByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AcquisitionItemByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getExpireAt())
        {
            writer.writePropertyName("expireAt");
            writer.write(*request.getExpireAt());
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
     * インベントリのアイテムを消費します<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの中から有効期限の近いアイテムから消費します。<br>
     * ただし、この場合有効期限内の所有するアイテムの数量倍クォーターを消費します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItem(std::function<void(AsyncConsumeItemResult&)> callback, ConsumeItemRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/my/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getExpireAt())
        {
            writer.writePropertyName("expireAt");
            writer.write(*request.getExpireAt());
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
     * スタンプタスクを使用してインベントリのアイテムを消費します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemByStampTask(std::function<void(AsyncConsumeItemByStampTaskResult&)> callback, ConsumeItemByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/inventory");
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
     * インベントリのアイテムを消費します<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの中から有効期限の近いアイテムから消費します。<br>
     * ただし、この場合クォーターを有効期限内の所有するアイテムの数量倍消費します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeItemByUserId(std::function<void(AsyncConsumeItemByUserIdResult&)> callback, ConsumeItemByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeItemByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getExpireAt())
        {
            writer.writePropertyName("expireAt");
            writer.write(*request.getExpireAt());
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
     * インベントリからアイテムを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteInventoryByUserId(std::function<void(AsyncDeleteInventoryByUserIdResult&)> callback, DeleteInventoryByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("/").append(detail::StringUtil::toStr(buffer, request.getExpireAt())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザが所持しているインベントリの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventory(std::function<void(AsyncDescribeInventoryResult&)> callback, DescribeInventoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInventoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/my");
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
     * ユーザが所持しているインベントリの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeInventoryByUserId(std::function<void(AsyncDescribeInventoryByUserIdResult&)> callback, DescribeInventoryByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeInventoryByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
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
     * インベントリの内容を取得します<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの数量を丸めて応答します。<br>
     * 有効期限には0が設定されて応答されますので、有効期限が存在するかどうかを判別することもできなくなります。<br>
     * <br>
     * また、expireAt を指定しない場合は処理時間が expireAt を指定しない場合を指定する場合と比較して長くなります。<br>
     * 全ての消費型アイテムが有効期限を持たないアイテムで構成される場合は、有効期限に0を設定すると有効期限の無いアイテムとして管理されますので、そちらを利用してください。<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの数量倍クォーターを消費します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventory(std::function<void(AsyncGetInventoryResult&)> callback, GetInventoryRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/my/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getExpireAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExpireAt()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("expireAt={value}").replace("{value}", encodeBuffer) + "&";
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
     * インベントリの内容を取得します<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの数量を丸めて応答します。<br>
     * 有効期限には0が設定されて応答されますので、有効期限が存在するかどうかを判別することもできなくなります。<br>
     * <br>
     * また、expireAt を指定しない場合は処理時間が expireAt を指定しない場合を指定する場合と比較して長くなります。<br>
     * 全ての消費型アイテムが有効期限を持たないアイテムで構成される場合は、有効期限に0を設定すると有効期限の無いアイテムとして管理されますので、そちらを利用してください。<br>
     * <br>
     * expireAt を指定しない場合は有効期限内の所有するアイテムの数量倍クォーターを消費します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getInventoryByUserId(std::function<void(AsyncGetInventoryByUserIdResult&)> callback, GetInventoryByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetInventoryByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/inventory/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getExpireAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExpireAt()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("expireAt={value}").replace("{value}", encodeBuffer) + "&";
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
     * 消費型アイテムを新規作成します<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master/item");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*request.getMax());
        }
        if (request.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*request.getAcquisitionItemTriggerScript());
        }
        if (request.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*request.getAcquisitionItemDoneTriggerScript());
        }
        if (request.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*request.getConsumeItemTriggerScript());
        }
        if (request.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*request.getConsumeItemDoneTriggerScript());
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
     * 消費型アイテムを削除します<br>
     * <br>
     * 既にアイテムを所持しているユーザがいる場合、そのアイテムはインベントリから削除されることはありません。<br>
     * 消費型アイテムを削除することで新しくアイテムを付与することはできなくなりますが、消費することは出来ます。<br>
     * <br>
     * これを防ぎたい場合はすべてのユーザのインベントリを走査して該当アイテムを削除する必要があります。<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムの一覧を取得します<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master/item");
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
     * 消費型アイテムを取得します<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムを更新します<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master/item/").append(detail::StringUtil::toStr(buffer, request.getItemName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*request.getMax());
        }
        if (request.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*request.getAcquisitionItemTriggerScript());
        }
        if (request.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*request.getAcquisitionItemDoneTriggerScript());
        }
        if (request.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*request.getConsumeItemTriggerScript());
        }
        if (request.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*request.getConsumeItemDoneTriggerScript());
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
     * 消費型アイテムプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createItemPool(std::function<void(AsyncCreateItemPoolResult&)> callback, CreateItemPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateItemPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool");
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
        if (request.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*request.getAcquisitionItemTriggerScript());
        }
        if (request.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*request.getAcquisitionItemDoneTriggerScript());
        }
        if (request.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*request.getConsumeItemTriggerScript());
        }
        if (request.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*request.getConsumeItemDoneTriggerScript());
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
     * 消費型アイテムプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteItemPool(std::function<void(AsyncDeleteItemPoolResult&)> callback, DeleteItemPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeItemPool(std::function<void(AsyncDescribeItemPoolResult&)> callback, DescribeItemPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeItemPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool");
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
            url.append("/itemPool/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemPool(std::function<void(AsyncGetItemPoolResult&)> callback, GetItemPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getItemPoolStatus(std::function<void(AsyncGetItemPoolStatusResult&)> callback, GetItemPoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetItemPoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 消費型アイテムプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateItemPool(std::function<void(AsyncUpdateItemPoolResult&)> callback, UpdateItemPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateItemPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("");
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
        if (request.getAcquisitionItemTriggerScript())
        {
            writer.writePropertyName("acquisitionItemTriggerScript");
            writer.write(*request.getAcquisitionItemTriggerScript());
        }
        if (request.getAcquisitionItemDoneTriggerScript())
        {
            writer.writePropertyName("acquisitionItemDoneTriggerScript");
            writer.write(*request.getAcquisitionItemDoneTriggerScript());
        }
        if (request.getConsumeItemTriggerScript())
        {
            writer.writePropertyName("consumeItemTriggerScript");
            writer.write(*request.getConsumeItemTriggerScript());
        }
        if (request.getConsumeItemDoneTriggerScript())
        {
            writer.writePropertyName("consumeItemDoneTriggerScript");
            writer.write(*request.getConsumeItemDoneTriggerScript());
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
     * アイテムマスターデータをエクスポートする<br>
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
            url.append("/itemPool/").append(detail::StringUtil::toStr(buffer, request.getItemPoolName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_CONSUMABLEITEM_GS2CONSUMABLEITEMCLIENT_HPP_