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

#ifndef GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_
#define GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeStaminaModelMastersRequest.hpp"
#include "request/CreateStaminaModelMasterRequest.hpp"
#include "request/GetStaminaModelMasterRequest.hpp"
#include "request/UpdateStaminaModelMasterRequest.hpp"
#include "request/DeleteStaminaModelMasterRequest.hpp"
#include "request/DescribeMaxStaminaTableMastersRequest.hpp"
#include "request/CreateMaxStaminaTableMasterRequest.hpp"
#include "request/GetMaxStaminaTableMasterRequest.hpp"
#include "request/UpdateMaxStaminaTableMasterRequest.hpp"
#include "request/DeleteMaxStaminaTableMasterRequest.hpp"
#include "request/DescribeRecoverIntervalTableMastersRequest.hpp"
#include "request/CreateRecoverIntervalTableMasterRequest.hpp"
#include "request/GetRecoverIntervalTableMasterRequest.hpp"
#include "request/UpdateRecoverIntervalTableMasterRequest.hpp"
#include "request/DeleteRecoverIntervalTableMasterRequest.hpp"
#include "request/DescribeRecoverValueTableMastersRequest.hpp"
#include "request/CreateRecoverValueTableMasterRequest.hpp"
#include "request/GetRecoverValueTableMasterRequest.hpp"
#include "request/UpdateRecoverValueTableMasterRequest.hpp"
#include "request/DeleteRecoverValueTableMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterFromGitHubRequest.hpp"
#include "request/DescribeStaminaModelsRequest.hpp"
#include "request/GetStaminaModelRequest.hpp"
#include "request/DescribeStaminasRequest.hpp"
#include "request/DescribeStaminasByUserIdRequest.hpp"
#include "request/GetStaminaRequest.hpp"
#include "request/GetStaminaByUserIdRequest.hpp"
#include "request/UpdateStaminaByUserIdRequest.hpp"
#include "request/ConsumeStaminaRequest.hpp"
#include "request/ConsumeStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByUserIdRequest.hpp"
#include "request/RaiseMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByUserIdRequest.hpp"
#include "request/SetRecoverIntervalByUserIdRequest.hpp"
#include "request/SetRecoverValueByUserIdRequest.hpp"
#include "request/SetMaxValueByStatusRequest.hpp"
#include "request/SetRecoverIntervalByStatusRequest.hpp"
#include "request/SetRecoverValueByStatusRequest.hpp"
#include "request/DeleteStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByStampSheetRequest.hpp"
#include "request/RaiseMaxValueByStampSheetRequest.hpp"
#include "request/SetMaxValueByStampSheetRequest.hpp"
#include "request/SetRecoverIntervalByStampSheetRequest.hpp"
#include "request/SetRecoverValueByStampSheetRequest.hpp"
#include "request/ConsumeStaminaByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeStaminaModelMastersResult.hpp"
#include "result/CreateStaminaModelMasterResult.hpp"
#include "result/GetStaminaModelMasterResult.hpp"
#include "result/UpdateStaminaModelMasterResult.hpp"
#include "result/DeleteStaminaModelMasterResult.hpp"
#include "result/DescribeMaxStaminaTableMastersResult.hpp"
#include "result/CreateMaxStaminaTableMasterResult.hpp"
#include "result/GetMaxStaminaTableMasterResult.hpp"
#include "result/UpdateMaxStaminaTableMasterResult.hpp"
#include "result/DeleteMaxStaminaTableMasterResult.hpp"
#include "result/DescribeRecoverIntervalTableMastersResult.hpp"
#include "result/CreateRecoverIntervalTableMasterResult.hpp"
#include "result/GetRecoverIntervalTableMasterResult.hpp"
#include "result/UpdateRecoverIntervalTableMasterResult.hpp"
#include "result/DeleteRecoverIntervalTableMasterResult.hpp"
#include "result/DescribeRecoverValueTableMastersResult.hpp"
#include "result/CreateRecoverValueTableMasterResult.hpp"
#include "result/GetRecoverValueTableMasterResult.hpp"
#include "result/UpdateRecoverValueTableMasterResult.hpp"
#include "result/DeleteRecoverValueTableMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterFromGitHubResult.hpp"
#include "result/DescribeStaminaModelsResult.hpp"
#include "result/GetStaminaModelResult.hpp"
#include "result/DescribeStaminasResult.hpp"
#include "result/DescribeStaminasByUserIdResult.hpp"
#include "result/GetStaminaResult.hpp"
#include "result/GetStaminaByUserIdResult.hpp"
#include "result/UpdateStaminaByUserIdResult.hpp"
#include "result/ConsumeStaminaResult.hpp"
#include "result/ConsumeStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByUserIdResult.hpp"
#include "result/RaiseMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByUserIdResult.hpp"
#include "result/SetRecoverIntervalByUserIdResult.hpp"
#include "result/SetRecoverValueByUserIdResult.hpp"
#include "result/SetMaxValueByStatusResult.hpp"
#include "result/SetRecoverIntervalByStatusResult.hpp"
#include "result/SetRecoverValueByStatusResult.hpp"
#include "result/DeleteStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByStampSheetResult.hpp"
#include "result/RaiseMaxValueByStampSheetResult.hpp"
#include "result/SetMaxValueByStampSheetResult.hpp"
#include "result/SetRecoverIntervalByStampSheetResult.hpp"
#include "result/SetRecoverValueByStampSheetResult.hpp"
#include "result/ConsumeStaminaByStampTaskResult.hpp"

namespace gs2 { namespace stamina {

/**
 * GS2 Stamina API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2StaminaWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2StaminaWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModelMasters(DescribeStaminaModelMastersRequest request, std::function<void(AsyncDescribeStaminaModelMastersResult)> callback);

	/**
	 * スタミナモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaModelMaster(CreateStaminaModelMasterRequest request, std::function<void(AsyncCreateStaminaModelMasterResult)> callback);

	/**
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModelMaster(GetStaminaModelMasterRequest request, std::function<void(AsyncGetStaminaModelMasterResult)> callback);

	/**
	 * スタミナモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaModelMaster(UpdateStaminaModelMasterRequest request, std::function<void(AsyncUpdateStaminaModelMasterResult)> callback);

	/**
	 * スタミナモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaModelMaster(DeleteStaminaModelMasterRequest request, std::function<void(AsyncDeleteStaminaModelMasterResult)> callback);

	/**
	 * スタミナの最大値テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMaxStaminaTableMasters(DescribeMaxStaminaTableMastersRequest request, std::function<void(AsyncDescribeMaxStaminaTableMastersResult)> callback);

	/**
	 * スタミナの最大値テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMaxStaminaTableMaster(CreateMaxStaminaTableMasterRequest request, std::function<void(AsyncCreateMaxStaminaTableMasterResult)> callback);

	/**
	 * スタミナの最大値テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMaxStaminaTableMaster(GetMaxStaminaTableMasterRequest request, std::function<void(AsyncGetMaxStaminaTableMasterResult)> callback);

	/**
	 * スタミナの最大値テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMaxStaminaTableMaster(UpdateMaxStaminaTableMasterRequest request, std::function<void(AsyncUpdateMaxStaminaTableMasterResult)> callback);

	/**
	 * スタミナの最大値テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMaxStaminaTableMaster(DeleteMaxStaminaTableMasterRequest request, std::function<void(AsyncDeleteMaxStaminaTableMasterResult)> callback);

	/**
	 * スタミナ回復間隔テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRecoverIntervalTableMasters(DescribeRecoverIntervalTableMastersRequest request, std::function<void(AsyncDescribeRecoverIntervalTableMastersResult)> callback);

	/**
	 * スタミナ回復間隔テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRecoverIntervalTableMaster(CreateRecoverIntervalTableMasterRequest request, std::function<void(AsyncCreateRecoverIntervalTableMasterResult)> callback);

	/**
	 * スタミナ回復間隔テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRecoverIntervalTableMaster(GetRecoverIntervalTableMasterRequest request, std::function<void(AsyncGetRecoverIntervalTableMasterResult)> callback);

	/**
	 * スタミナ回復間隔テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRecoverIntervalTableMaster(UpdateRecoverIntervalTableMasterRequest request, std::function<void(AsyncUpdateRecoverIntervalTableMasterResult)> callback);

	/**
	 * スタミナ回復間隔テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRecoverIntervalTableMaster(DeleteRecoverIntervalTableMasterRequest request, std::function<void(AsyncDeleteRecoverIntervalTableMasterResult)> callback);

	/**
	 * スタミナ回復量テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRecoverValueTableMasters(DescribeRecoverValueTableMastersRequest request, std::function<void(AsyncDescribeRecoverValueTableMastersResult)> callback);

	/**
	 * スタミナ回復量テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRecoverValueTableMaster(CreateRecoverValueTableMasterRequest request, std::function<void(AsyncCreateRecoverValueTableMasterResult)> callback);

	/**
	 * スタミナ回復量テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRecoverValueTableMaster(GetRecoverValueTableMasterRequest request, std::function<void(AsyncGetRecoverValueTableMasterResult)> callback);

	/**
	 * スタミナ回復量テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRecoverValueTableMaster(UpdateRecoverValueTableMasterRequest request, std::function<void(AsyncUpdateRecoverValueTableMasterResult)> callback);

	/**
	 * スタミナ回復量テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRecoverValueTableMaster(DeleteRecoverValueTableMasterRequest request, std::function<void(AsyncDeleteRecoverValueTableMasterResult)> callback);

	/**
	 * 現在有効なスタミナマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効なスタミナマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentStaminaMaster(GetCurrentStaminaMasterRequest request, std::function<void(AsyncGetCurrentStaminaMasterResult)> callback);

	/**
	 * 現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMaster(UpdateCurrentStaminaMasterRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterResult)> callback);

	/**
	 * 現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMasterFromGitHub(UpdateCurrentStaminaMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterFromGitHubResult)> callback);

	/**
	 * スタミナモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModels(DescribeStaminaModelsRequest request, std::function<void(AsyncDescribeStaminaModelsResult)> callback);

	/**
	 * スタミナモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModel(GetStaminaModelRequest request, std::function<void(AsyncGetStaminaModelResult)> callback);

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminas(DescribeStaminasRequest request, std::function<void(AsyncDescribeStaminasResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminasByUserId(DescribeStaminasByUserIdRequest request, std::function<void(AsyncDescribeStaminasByUserIdResult)> callback);

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(GetStaminaRequest request, std::function<void(AsyncGetStaminaResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaByUserId(GetStaminaByUserIdRequest request, std::function<void(AsyncGetStaminaByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを作成・更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaByUserId(UpdateStaminaByUserIdRequest request, std::function<void(AsyncUpdateStaminaByUserIdResult)> callback);

	/**
	 * スタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(ConsumeStaminaRequest request, std::function<void(AsyncConsumeStaminaResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByUserId(ConsumeStaminaByUserIdRequest request, std::function<void(AsyncConsumeStaminaByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByUserId(RecoverStaminaByUserIdRequest request, std::function<void(AsyncRecoverStaminaByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByUserId(RaiseMaxValueByUserIdRequest request, std::function<void(AsyncRaiseMaxValueByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByUserId(SetMaxValueByUserIdRequest request, std::function<void(AsyncSetMaxValueByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByUserId(SetRecoverIntervalByUserIdRequest request, std::function<void(AsyncSetRecoverIntervalByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByUserId(SetRecoverValueByUserIdRequest request, std::function<void(AsyncSetRecoverValueByUserIdResult)> callback);

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStatus(SetMaxValueByStatusRequest request, std::function<void(AsyncSetMaxValueByStatusResult)> callback);

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByStatus(SetRecoverIntervalByStatusRequest request, std::function<void(AsyncSetRecoverIntervalByStatusResult)> callback);

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByStatus(SetRecoverValueByStatusRequest request, std::function<void(AsyncSetRecoverValueByStatusResult)> callback);

	/**
	 * ユーザIDを指定してスタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaByUserId(DeleteStaminaByUserIdRequest request, std::function<void(AsyncDeleteStaminaByUserIdResult)> callback);

	/**
	 * スタンプシートを使用してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByStampSheet(RecoverStaminaByStampSheetRequest request, std::function<void(AsyncRecoverStaminaByStampSheetResult)> callback);

	/**
	 * スタンプシートでスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByStampSheet(RaiseMaxValueByStampSheetRequest request, std::function<void(AsyncRaiseMaxValueByStampSheetResult)> callback);

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStampSheet(SetMaxValueByStampSheetRequest request, std::function<void(AsyncSetMaxValueByStampSheetResult)> callback);

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByStampSheet(SetRecoverIntervalByStampSheetRequest request, std::function<void(AsyncSetRecoverIntervalByStampSheetResult)> callback);

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByStampSheet(SetRecoverValueByStampSheetRequest request, std::function<void(AsyncSetRecoverValueByStampSheetResult)> callback);

	/**
	 * スタンプタスクを使用してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(ConsumeStaminaByStampTaskRequest request, std::function<void(AsyncConsumeStaminaByStampTaskResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_