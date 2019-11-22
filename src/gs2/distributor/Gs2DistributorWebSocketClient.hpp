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

#ifndef GS2_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_
#define GS2_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeDistributorModelMastersRequest.hpp"
#include "request/CreateDistributorModelMasterRequest.hpp"
#include "request/GetDistributorModelMasterRequest.hpp"
#include "request/UpdateDistributorModelMasterRequest.hpp"
#include "request/DeleteDistributorModelMasterRequest.hpp"
#include "request/DescribeDistributorModelsRequest.hpp"
#include "request/GetDistributorModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentDistributorMasterRequest.hpp"
#include "request/UpdateCurrentDistributorMasterRequest.hpp"
#include "request/UpdateCurrentDistributorMasterFromGitHubRequest.hpp"
#include "request/DistributeRequest.hpp"
#include "request/RunStampTaskRequest.hpp"
#include "request/RunStampSheetRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeDistributorModelMastersResult.hpp"
#include "result/CreateDistributorModelMasterResult.hpp"
#include "result/GetDistributorModelMasterResult.hpp"
#include "result/UpdateDistributorModelMasterResult.hpp"
#include "result/DeleteDistributorModelMasterResult.hpp"
#include "result/DescribeDistributorModelsResult.hpp"
#include "result/GetDistributorModelResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentDistributorMasterResult.hpp"
#include "result/UpdateCurrentDistributorMasterResult.hpp"
#include "result/UpdateCurrentDistributorMasterFromGitHubResult.hpp"
#include "result/DistributeResult.hpp"
#include "result/RunStampTaskResult.hpp"
#include "result/RunStampSheetResult.hpp"

namespace gs2 { namespace distributor {

/**
 * GS2 Distributor API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DistributorWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2DistributorWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 配信設定マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModelMasters(DescribeDistributorModelMastersRequest request, std::function<void(AsyncDescribeDistributorModelMastersResult)> callback);

	/**
	 * 配信設定マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createDistributorModelMaster(CreateDistributorModelMasterRequest request, std::function<void(AsyncCreateDistributorModelMasterResult)> callback);

	/**
	 * 配信設定マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModelMaster(GetDistributorModelMasterRequest request, std::function<void(AsyncGetDistributorModelMasterResult)> callback);

	/**
	 * 配信設定マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDistributorModelMaster(UpdateDistributorModelMasterRequest request, std::function<void(AsyncUpdateDistributorModelMasterResult)> callback);

	/**
	 * 配信設定マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDistributorModelMaster(DeleteDistributorModelMasterRequest request, std::function<void(AsyncDeleteDistributorModelMasterResult)> callback);

	/**
	 * 配信設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModels(DescribeDistributorModelsRequest request, std::function<void(AsyncDescribeDistributorModelsResult)> callback);

	/**
	 * 配信設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModel(GetDistributorModelRequest request, std::function<void(AsyncGetDistributorModelResult)> callback);

	/**
	 * 現在有効な配信設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効な配信設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentDistributorMaster(GetCurrentDistributorMasterRequest request, std::function<void(AsyncGetCurrentDistributorMasterResult)> callback);

	/**
	 * 現在有効な配信設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentDistributorMaster(UpdateCurrentDistributorMasterRequest request, std::function<void(AsyncUpdateCurrentDistributorMasterResult)> callback);

	/**
	 * 現在有効な配信設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentDistributorMasterFromGitHub(UpdateCurrentDistributorMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentDistributorMasterFromGitHubResult)> callback);

	/**
	 * 所持品を配布する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void distribute(DistributeRequest request, std::function<void(AsyncDistributeResult)> callback);

	/**
	 * スタンプシートのタスクを実行する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runStampTask(RunStampTaskRequest request, std::function<void(AsyncRunStampTaskResult)> callback);

	/**
	 * スタンプシートの完了を報告する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runStampSheet(RunStampSheetRequest request, std::function<void(AsyncRunStampSheetResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_