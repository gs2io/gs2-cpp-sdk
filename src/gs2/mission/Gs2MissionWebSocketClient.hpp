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

#ifndef GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_
#define GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include "request/DescribeMissionGroupModelMastersRequest.hpp"
#include "request/CreateMissionGroupModelMasterRequest.hpp"
#include "request/GetMissionGroupModelMasterRequest.hpp"
#include "request/UpdateMissionGroupModelMasterRequest.hpp"
#include "request/DeleteMissionGroupModelMasterRequest.hpp"
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/IncreaseCounterByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/IncreaseByStampSheetRequest.hpp"
#include "request/DescribeMissionTaskModelMastersRequest.hpp"
#include "request/CreateMissionTaskModelMasterRequest.hpp"
#include "request/GetMissionTaskModelMasterRequest.hpp"
#include "request/UpdateMissionTaskModelMasterRequest.hpp"
#include "request/DeleteMissionTaskModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterRequest.hpp"
#include "request/UpdateCurrentMissionMasterFromGitHubRequest.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeCompletesRequest.hpp"
#include "request/DescribeCompletesByUserIdRequest.hpp"
#include "request/CompleteRequest.hpp"
#include "request/CompleteByUserIdRequest.hpp"
#include "request/ReceiveByUserIdRequest.hpp"
#include "request/GetCompleteRequest.hpp"
#include "request/GetCompleteByUserIdRequest.hpp"
#include "request/DeleteCompleteByUserIdRequest.hpp"
#include "request/ReceiveByStampTaskRequest.hpp"
#include "request/DescribeCounterModelMastersRequest.hpp"
#include "request/CreateCounterModelMasterRequest.hpp"
#include "request/GetCounterModelMasterRequest.hpp"
#include "request/UpdateCounterModelMasterRequest.hpp"
#include "request/DeleteCounterModelMasterRequest.hpp"
#include "request/DescribeCounterModelsRequest.hpp"
#include "request/GetCounterModelRequest.hpp"
#include "request/DescribeMissionGroupModelsRequest.hpp"
#include "request/GetMissionGroupModelRequest.hpp"
#include "request/DescribeMissionTaskModelsRequest.hpp"
#include "request/GetMissionTaskModelRequest.hpp"
#include "result/DescribeMissionGroupModelMastersResult.hpp"
#include "result/CreateMissionGroupModelMasterResult.hpp"
#include "result/GetMissionGroupModelMasterResult.hpp"
#include "result/UpdateMissionGroupModelMasterResult.hpp"
#include "result/DeleteMissionGroupModelMasterResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/IncreaseCounterByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/IncreaseByStampSheetResult.hpp"
#include "result/DescribeMissionTaskModelMastersResult.hpp"
#include "result/CreateMissionTaskModelMasterResult.hpp"
#include "result/GetMissionTaskModelMasterResult.hpp"
#include "result/UpdateMissionTaskModelMasterResult.hpp"
#include "result/DeleteMissionTaskModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterResult.hpp"
#include "result/UpdateCurrentMissionMasterFromGitHubResult.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCompletesResult.hpp"
#include "result/DescribeCompletesByUserIdResult.hpp"
#include "result/CompleteResult.hpp"
#include "result/CompleteByUserIdResult.hpp"
#include "result/ReceiveByUserIdResult.hpp"
#include "result/GetCompleteResult.hpp"
#include "result/GetCompleteByUserIdResult.hpp"
#include "result/DeleteCompleteByUserIdResult.hpp"
#include "result/ReceiveByStampTaskResult.hpp"
#include "result/DescribeCounterModelMastersResult.hpp"
#include "result/CreateCounterModelMasterResult.hpp"
#include "result/GetCounterModelMasterResult.hpp"
#include "result/UpdateCounterModelMasterResult.hpp"
#include "result/DeleteCounterModelMasterResult.hpp"
#include "result/DescribeCounterModelsResult.hpp"
#include "result/GetCounterModelResult.hpp"
#include "result/DescribeMissionGroupModelsResult.hpp"
#include "result/GetMissionGroupModelResult.hpp"
#include "result/DescribeMissionTaskModelsResult.hpp"
#include "result/GetMissionTaskModelResult.hpp"

namespace gs2 { namespace mission {

/**
 * GS2 Mission API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MissionWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2MissionWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ミッショングループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModelMasters(DescribeMissionGroupModelMastersRequest request, std::function<void(AsyncDescribeMissionGroupModelMastersResult)> callback);

	/**
	 * ミッショングループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionGroupModelMaster(CreateMissionGroupModelMasterRequest request, std::function<void(AsyncCreateMissionGroupModelMasterResult)> callback);

	/**
	 * ミッショングループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModelMaster(GetMissionGroupModelMasterRequest request, std::function<void(AsyncGetMissionGroupModelMasterResult)> callback);

	/**
	 * ミッショングループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionGroupModelMaster(UpdateMissionGroupModelMasterRequest request, std::function<void(AsyncUpdateMissionGroupModelMasterResult)> callback);

	/**
	 * ミッショングループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionGroupModelMaster(DeleteMissionGroupModelMasterRequest request, std::function<void(AsyncDeleteMissionGroupModelMasterResult)> callback);

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(DescribeCountersRequest request, std::function<void(AsyncDescribeCountersResult)> callback);

	/**
	 * ユーザIDを指定してカウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(DescribeCountersByUserIdRequest request, std::function<void(AsyncDescribeCountersByUserIdResult)> callback);

	/**
	 * カウンターに加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseCounterByUserId(IncreaseCounterByUserIdRequest request, std::function<void(AsyncIncreaseCounterByUserIdResult)> callback);

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
	 * カウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(DeleteCounterByUserIdRequest request, std::function<void(AsyncDeleteCounterByUserIdResult)> callback);

	/**
	 * カウンター加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseByStampSheet(IncreaseByStampSheetRequest request, std::function<void(AsyncIncreaseByStampSheetResult)> callback);

	/**
	 * ミッションタスクマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModelMasters(DescribeMissionTaskModelMastersRequest request, std::function<void(AsyncDescribeMissionTaskModelMastersResult)> callback);

	/**
	 * ミッションタスクマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMissionTaskModelMaster(CreateMissionTaskModelMasterRequest request, std::function<void(AsyncCreateMissionTaskModelMasterResult)> callback);

	/**
	 * ミッションタスクマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModelMaster(GetMissionTaskModelMasterRequest request, std::function<void(AsyncGetMissionTaskModelMasterResult)> callback);

	/**
	 * ミッションタスクマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMissionTaskModelMaster(UpdateMissionTaskModelMasterRequest request, std::function<void(AsyncUpdateMissionTaskModelMasterResult)> callback);

	/**
	 * ミッションタスクマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMissionTaskModelMaster(DeleteMissionTaskModelMasterRequest request, std::function<void(AsyncDeleteMissionTaskModelMasterResult)> callback);

	/**
	 * 現在有効なミッションのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効なミッションを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentMissionMaster(GetCurrentMissionMasterRequest request, std::function<void(AsyncGetCurrentMissionMasterResult)> callback);

	/**
	 * 現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMaster(UpdateCurrentMissionMasterRequest request, std::function<void(AsyncUpdateCurrentMissionMasterResult)> callback);

	/**
	 * 現在有効なミッションを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMissionMasterFromGitHub(UpdateCurrentMissionMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentMissionMasterFromGitHubResult)> callback);

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
	 * 達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletes(DescribeCompletesRequest request, std::function<void(AsyncDescribeCompletesResult)> callback);

	/**
	 * ユーザIDを指定して達成状況の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletesByUserId(DescribeCompletesByUserIdRequest request, std::function<void(AsyncDescribeCompletesByUserIdResult)> callback);

	/**
	 * ミッション達成報酬を受領するためのスタンプシートを発行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void complete(CompleteRequest request, std::function<void(AsyncCompleteResult)> callback);

	/**
	 * 達成状況を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void completeByUserId(CompleteByUserIdRequest request, std::function<void(AsyncCompleteByUserIdResult)> callback);

	/**
	 * ミッション達成報酬を受領する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByUserId(ReceiveByUserIdRequest request, std::function<void(AsyncReceiveByUserIdResult)> callback);

	/**
	 * 達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getComplete(GetCompleteRequest request, std::function<void(AsyncGetCompleteResult)> callback);

	/**
	 * ユーザIDを指定して達成状況を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompleteByUserId(GetCompleteByUserIdRequest request, std::function<void(AsyncGetCompleteByUserIdResult)> callback);

	/**
	 * 達成状況を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompleteByUserId(DeleteCompleteByUserIdRequest request, std::function<void(AsyncDeleteCompleteByUserIdResult)> callback);

	/**
	 * 達成状況を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveByStampTask(ReceiveByStampTaskRequest request, std::function<void(AsyncReceiveByStampTaskResult)> callback);

	/**
	 * カウンターの種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModelMasters(DescribeCounterModelMastersRequest request, std::function<void(AsyncDescribeCounterModelMastersResult)> callback);

	/**
	 * カウンターの種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCounterModelMaster(CreateCounterModelMasterRequest request, std::function<void(AsyncCreateCounterModelMasterResult)> callback);

	/**
	 * カウンターの種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModelMaster(GetCounterModelMasterRequest request, std::function<void(AsyncGetCounterModelMasterResult)> callback);

	/**
	 * カウンターの種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCounterModelMaster(UpdateCounterModelMasterRequest request, std::function<void(AsyncUpdateCounterModelMasterResult)> callback);

	/**
	 * カウンターの種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterModelMaster(DeleteCounterModelMasterRequest request, std::function<void(AsyncDeleteCounterModelMasterResult)> callback);

	/**
	 * カウンターの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterModels(DescribeCounterModelsRequest request, std::function<void(AsyncDescribeCounterModelsResult)> callback);

	/**
	 * カウンターの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterModel(GetCounterModelRequest request, std::function<void(AsyncGetCounterModelResult)> callback);

	/**
	 * ミッショングループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionGroupModels(DescribeMissionGroupModelsRequest request, std::function<void(AsyncDescribeMissionGroupModelsResult)> callback);

	/**
	 * ミッショングループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionGroupModel(GetMissionGroupModelRequest request, std::function<void(AsyncGetMissionGroupModelResult)> callback);

	/**
	 * ミッションタスクの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMissionTaskModels(DescribeMissionTaskModelsRequest request, std::function<void(AsyncDescribeMissionTaskModelsResult)> callback);

	/**
	 * ミッションタスクを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMissionTaskModel(GetMissionTaskModelRequest request, std::function<void(AsyncGetMissionTaskModelResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MISSION_GS2MISSIONWEBSOCKETCLIENT_HPP_