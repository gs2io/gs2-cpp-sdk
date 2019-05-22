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

#ifndef GS2_LOCK_GS2LOCKCLIENT_HPP_
#define GS2_LOCK_GS2LOCKCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeCategoriesRequest.hpp"
#include "request/CreateCategoryRequest.hpp"
#include "request/GetCategoryStatusRequest.hpp"
#include "request/GetCategoryRequest.hpp"
#include "request/UpdateCategoryRequest.hpp"
#include "request/DeleteCategoryRequest.hpp"
#include "request/DescribeMutexesRequest.hpp"
#include "request/LockRequest.hpp"
#include "request/LockByUserIdRequest.hpp"
#include "request/UnlockRequest.hpp"
#include "request/UnlockByUserIdRequest.hpp"
#include "request/GetMutexRequest.hpp"
#include "request/GetMutexByUserIdRequest.hpp"
#include "request/DeleteMutexByUserIdRequest.hpp"
#include "result/DescribeCategoriesResult.hpp"
#include "result/CreateCategoryResult.hpp"
#include "result/GetCategoryStatusResult.hpp"
#include "result/GetCategoryResult.hpp"
#include "result/UpdateCategoryResult.hpp"
#include "result/DeleteCategoryResult.hpp"
#include "result/DescribeMutexesResult.hpp"
#include "result/LockResult.hpp"
#include "result/LockByUserIdResult.hpp"
#include "result/UnlockResult.hpp"
#include "result/UnlockByUserIdResult.hpp"
#include "result/GetMutexResult.hpp"
#include "result/GetMutexByUserIdResult.hpp"
#include "result/DeleteMutexByUserIdResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace lock {

typedef AsyncResult<DescribeCategoriesResult> AsyncDescribeCategoriesResult;
typedef AsyncResult<CreateCategoryResult> AsyncCreateCategoryResult;
typedef AsyncResult<GetCategoryStatusResult> AsyncGetCategoryStatusResult;
typedef AsyncResult<GetCategoryResult> AsyncGetCategoryResult;
typedef AsyncResult<UpdateCategoryResult> AsyncUpdateCategoryResult;
typedef AsyncResult<DeleteCategoryResult> AsyncDeleteCategoryResult;
typedef AsyncResult<DescribeMutexesResult> AsyncDescribeMutexesResult;
typedef AsyncResult<LockResult> AsyncLockResult;
typedef AsyncResult<LockByUserIdResult> AsyncLockByUserIdResult;
typedef AsyncResult<UnlockResult> AsyncUnlockResult;
typedef AsyncResult<UnlockByUserIdResult> AsyncUnlockByUserIdResult;
typedef AsyncResult<GetMutexResult> AsyncGetMutexResult;
typedef AsyncResult<GetMutexByUserIdResult> AsyncGetMutexByUserIdResult;
typedef AsyncResult<DeleteMutexByUserIdResult> AsyncDeleteMutexByUserIdResult;

/**
 * GS2 Lock API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LockClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "lock";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Category& obj)
    {
        writer.writeObjectStart();
        if (obj.getCategoryId())
        {
            writer.writePropertyName("categoryId");
            writer.write(*obj.getCategoryId());
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

    void write(detail::json::JsonWriter& writer, const Mutex& obj)
    {
        writer.writeObjectStart();
        if (obj.getMutexId())
        {
            writer.writePropertyName("mutexId");
            writer.write(*obj.getMutexId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        if (obj.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*obj.getTransactionId());
        }
        if (obj.getReferenceCount())
        {
            writer.writePropertyName("referenceCount");
            writer.write(*obj.getReferenceCount());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getTtlAt())
        {
            writer.writePropertyName("ttlAt");
            writer.write(*obj.getTtlAt());
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
	 * カテゴリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategories(std::function<void(AsyncDescribeCategoriesResult&)> callback, DescribeCategoriesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeCategoriesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.describeCategories");
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
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * カテゴリを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCategory(std::function<void(AsyncCreateCategoryResult&)> callback, CreateCategoryRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateCategoryResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.createCategory");
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryStatus(std::function<void(AsyncGetCategoryStatusResult&)> callback, GetCategoryStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCategoryStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.getCategoryStatus");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategory(std::function<void(AsyncGetCategoryResult&)> callback, GetCategoryRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCategoryResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.getCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * カテゴリを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCategory(std::function<void(AsyncUpdateCategoryResult&)> callback, UpdateCategoryRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCategoryResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.updateCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * カテゴリを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCategory(std::function<void(AsyncDeleteCategoryResult&)> callback, DeleteCategoryRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteCategoryResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FCategoryFunctionHandler.deleteCategory");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMutexes(std::function<void(AsyncDescribeMutexesResult&)> callback, DescribeMutexesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeMutexesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.describeMutexes");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
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
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lock(std::function<void(AsyncLockResult&)> callback, LockRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<LockResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.lock");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.write(*request.getTtl());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lockByUserId(std::function<void(AsyncLockByUserIdResult&)> callback, LockByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<LockByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.lockByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.write(*request.getTtl());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlock(std::function<void(AsyncUnlockResult&)> callback, UnlockRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UnlockResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.unlock");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlockByUserId(std::function<void(AsyncUnlockByUserIdResult&)> callback, UnlockByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UnlockByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.unlockByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMutex(std::function<void(AsyncGetMutexResult&)> callback, GetMutexRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMutexResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.getMutex");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMutexByUserId(std::function<void(AsyncGetMutexByUserIdResult&)> callback, GetMutexByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMutexByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.getMutexByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ミューテックスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMutexByUserId(std::function<void(AsyncDeleteMutexByUserIdResult&)> callback, DeleteMutexByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteMutexByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lock-handler?handler=gs2_lock%2Fhandler%2FMutexFunctionHandler.deleteMutexByUserId");
        Char encodeBuffer[2048];
        if (request.getCategoryName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getCategoryName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("categoryName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_LOCK_GS2LOCKCLIENT_HPP_