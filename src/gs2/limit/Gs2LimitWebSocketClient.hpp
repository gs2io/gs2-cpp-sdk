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

#ifndef GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_
#define GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/CountUpByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/CountUpByStampTaskRequest.hpp"
#include "request/DeleteByStampSheetRequest.hpp"
#include "request/DescribeLimitModelMastersRequest.hpp"
#include "request/CreateLimitModelMasterRequest.hpp"
#include "request/GetLimitModelMasterRequest.hpp"
#include "request/UpdateLimitModelMasterRequest.hpp"
#include "request/DeleteLimitModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterFromGitHubRequest.hpp"
#include "request/DescribeLimitModelsRequest.hpp"
#include "request/GetLimitModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/CountUpByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/CountUpByStampTaskResult.hpp"
#include "result/DeleteByStampSheetResult.hpp"
#include "result/DescribeLimitModelMastersResult.hpp"
#include "result/CreateLimitModelMasterResult.hpp"
#include "result/GetLimitModelMasterResult.hpp"
#include "result/UpdateLimitModelMasterResult.hpp"
#include "result/DeleteLimitModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterFromGitHubResult.hpp"
#include "result/DescribeLimitModelsResult.hpp"
#include "result/GetLimitModelResult.hpp"

namespace gs2 { namespace limit {

/**
 * GS2 Limit API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LimitWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2LimitWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback);

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback);

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback);

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback);

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback);

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(DescribeCountersRequest request, std::function<void(AsyncDescribeCountersResult)> callback);

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(DescribeCountersByUserIdRequest request, std::function<void(AsyncDescribeCountersByUserIdResult)> callback);

	/**
	 * カウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(GetCounterRequest request, std::function<void(AsyncGetCounterResult)> callback);

	/**
	 * ユーザIDを指定してカウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterByUserId(GetCounterByUserIdRequest request, std::function<void(AsyncGetCounterByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByUserId(CountUpByUserIdRequest request, std::function<void(AsyncCountUpByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(DeleteCounterByUserIdRequest request, std::function<void(AsyncDeleteCounterByUserIdResult)> callback);

	/**
	 * スタンプシートでカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByStampTask(CountUpByStampTaskRequest request, std::function<void(AsyncCountUpByStampTaskResult)> callback);

	/**
	 * スタンプシートでカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteByStampSheet(DeleteByStampSheetRequest request, std::function<void(AsyncDeleteByStampSheetResult)> callback);

	/**
	 * 回数制限の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModelMasters(DescribeLimitModelMastersRequest request, std::function<void(AsyncDescribeLimitModelMastersResult)> callback);

	/**
	 * 回数制限の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLimitModelMaster(CreateLimitModelMasterRequest request, std::function<void(AsyncCreateLimitModelMasterResult)> callback);

	/**
	 * 回数制限の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModelMaster(GetLimitModelMasterRequest request, std::function<void(AsyncGetLimitModelMasterResult)> callback);

	/**
	 * 回数制限の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLimitModelMaster(UpdateLimitModelMasterRequest request, std::function<void(AsyncUpdateLimitModelMasterResult)> callback);

	/**
	 * 回数制限の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLimitModelMaster(DeleteLimitModelMasterRequest request, std::function<void(AsyncDeleteLimitModelMasterResult)> callback);

	/**
	 * 現在有効な回数制限設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効な回数制限設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLimitMaster(GetCurrentLimitMasterRequest request, std::function<void(AsyncGetCurrentLimitMasterResult)> callback);

	/**
	 * 現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMaster(UpdateCurrentLimitMasterRequest request, std::function<void(AsyncUpdateCurrentLimitMasterResult)> callback);

	/**
	 * 現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMasterFromGitHub(UpdateCurrentLimitMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLimitMasterFromGitHubResult)> callback);

	/**
	 * 回数制限の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModels(DescribeLimitModelsRequest request, std::function<void(AsyncDescribeLimitModelsResult)> callback);

	/**
	 * 回数制限の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModel(GetLimitModelRequest request, std::function<void(AsyncGetLimitModelResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_