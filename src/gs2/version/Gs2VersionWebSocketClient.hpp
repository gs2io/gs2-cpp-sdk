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

#ifndef GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_
#define GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeVersionModelMastersRequest.hpp"
#include "request/CreateVersionModelMasterRequest.hpp"
#include "request/GetVersionModelMasterRequest.hpp"
#include "request/UpdateVersionModelMasterRequest.hpp"
#include "request/DeleteVersionModelMasterRequest.hpp"
#include "request/DescribeVersionModelsRequest.hpp"
#include "request/GetVersionModelRequest.hpp"
#include "request/DescribeAcceptVersionsRequest.hpp"
#include "request/DescribeAcceptVersionsByUserIdRequest.hpp"
#include "request/AcceptRequest.hpp"
#include "request/AcceptByUserIdRequest.hpp"
#include "request/GetAcceptVersionRequest.hpp"
#include "request/GetAcceptVersionByUserIdRequest.hpp"
#include "request/DeleteAcceptVersionRequest.hpp"
#include "request/DeleteAcceptVersionByUserIdRequest.hpp"
#include "request/CheckVersionRequest.hpp"
#include "request/CheckVersionByUserIdRequest.hpp"
#include "request/CalculateSignatureRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentVersionMasterRequest.hpp"
#include "request/UpdateCurrentVersionMasterRequest.hpp"
#include "request/UpdateCurrentVersionMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeVersionModelMastersResult.hpp"
#include "result/CreateVersionModelMasterResult.hpp"
#include "result/GetVersionModelMasterResult.hpp"
#include "result/UpdateVersionModelMasterResult.hpp"
#include "result/DeleteVersionModelMasterResult.hpp"
#include "result/DescribeVersionModelsResult.hpp"
#include "result/GetVersionModelResult.hpp"
#include "result/DescribeAcceptVersionsResult.hpp"
#include "result/DescribeAcceptVersionsByUserIdResult.hpp"
#include "result/AcceptResult.hpp"
#include "result/AcceptByUserIdResult.hpp"
#include "result/GetAcceptVersionResult.hpp"
#include "result/GetAcceptVersionByUserIdResult.hpp"
#include "result/DeleteAcceptVersionResult.hpp"
#include "result/DeleteAcceptVersionByUserIdResult.hpp"
#include "result/CheckVersionResult.hpp"
#include "result/CheckVersionByUserIdResult.hpp"
#include "result/CalculateSignatureResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentVersionMasterResult.hpp"
#include "result/UpdateCurrentVersionMasterResult.hpp"
#include "result/UpdateCurrentVersionMasterFromGitHubResult.hpp"

namespace gs2 { namespace version {

/**
 * GS2 Version API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2VersionWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2VersionWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * バージョンマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeVersionModelMasters(DescribeVersionModelMastersRequest request, std::function<void(AsyncDescribeVersionModelMastersResult)> callback);

	/**
	 * バージョンマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createVersionModelMaster(CreateVersionModelMasterRequest request, std::function<void(AsyncCreateVersionModelMasterResult)> callback);

	/**
	 * バージョンマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getVersionModelMaster(GetVersionModelMasterRequest request, std::function<void(AsyncGetVersionModelMasterResult)> callback);

	/**
	 * バージョンマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateVersionModelMaster(UpdateVersionModelMasterRequest request, std::function<void(AsyncUpdateVersionModelMasterResult)> callback);

	/**
	 * バージョンマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteVersionModelMaster(DeleteVersionModelMasterRequest request, std::function<void(AsyncDeleteVersionModelMasterResult)> callback);

	/**
	 * バージョン設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeVersionModels(DescribeVersionModelsRequest request, std::function<void(AsyncDescribeVersionModelsResult)> callback);

	/**
	 * バージョン設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getVersionModel(GetVersionModelRequest request, std::function<void(AsyncGetVersionModelResult)> callback);

	/**
	 * 承認したバージョンの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAcceptVersions(DescribeAcceptVersionsRequest request, std::function<void(AsyncDescribeAcceptVersionsResult)> callback);

	/**
	 * 承認したバージョンの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAcceptVersionsByUserId(DescribeAcceptVersionsByUserIdRequest request, std::function<void(AsyncDescribeAcceptVersionsByUserIdResult)> callback);

	/**
	 * 現在のバージョンを承認<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void accept(AcceptRequest request, std::function<void(AsyncAcceptResult)> callback);

	/**
	 * ユーザIDを指定して現在のバージョンを承認<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptByUserId(AcceptByUserIdRequest request, std::function<void(AsyncAcceptByUserIdResult)> callback);

	/**
	 * 承認したバージョンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAcceptVersion(GetAcceptVersionRequest request, std::function<void(AsyncGetAcceptVersionResult)> callback);

	/**
	 * ユーザーIDを指定して承認したバージョンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAcceptVersionByUserId(GetAcceptVersionByUserIdRequest request, std::function<void(AsyncGetAcceptVersionByUserIdResult)> callback);

	/**
	 * 承認したバージョンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAcceptVersion(DeleteAcceptVersionRequest request, std::function<void(AsyncDeleteAcceptVersionResult)> callback);

	/**
	 * ユーザーIDを指定して承認したバージョンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAcceptVersionByUserId(DeleteAcceptVersionByUserIdRequest request, std::function<void(AsyncDeleteAcceptVersionByUserIdResult)> callback);

	/**
	 * バージョンチェック<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkVersion(CheckVersionRequest request, std::function<void(AsyncCheckVersionResult)> callback);

	/**
	 * バージョンチェック<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkVersionByUserId(CheckVersionByUserIdRequest request, std::function<void(AsyncCheckVersionByUserIdResult)> callback);

	/**
	 * スタンプシートのタスクを実行する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void calculateSignature(CalculateSignatureRequest request, std::function<void(AsyncCalculateSignatureResult)> callback);

	/**
	 * 現在有効なバージョンのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効なバージョンを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentVersionMaster(GetCurrentVersionMasterRequest request, std::function<void(AsyncGetCurrentVersionMasterResult)> callback);

	/**
	 * 現在有効なバージョンを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentVersionMaster(UpdateCurrentVersionMasterRequest request, std::function<void(AsyncUpdateCurrentVersionMasterResult)> callback);

	/**
	 * 現在有効なバージョンを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentVersionMasterFromGitHub(UpdateCurrentVersionMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentVersionMasterFromGitHubResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_VERSION_GS2VERSIONWEBSOCKETCLIENT_HPP_