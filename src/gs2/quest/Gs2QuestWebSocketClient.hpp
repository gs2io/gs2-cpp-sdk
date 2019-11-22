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

#ifndef GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_
#define GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeQuestGroupModelMastersRequest.hpp"
#include "request/CreateQuestGroupModelMasterRequest.hpp"
#include "request/GetQuestGroupModelMasterRequest.hpp"
#include "request/UpdateQuestGroupModelMasterRequest.hpp"
#include "request/DeleteQuestGroupModelMasterRequest.hpp"
#include "request/DescribeQuestModelMastersRequest.hpp"
#include "request/CreateQuestModelMasterRequest.hpp"
#include "request/GetQuestModelMasterRequest.hpp"
#include "request/UpdateQuestModelMasterRequest.hpp"
#include "request/DeleteQuestModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterRequest.hpp"
#include "request/UpdateCurrentQuestMasterFromGitHubRequest.hpp"
#include "request/DescribeProgressesByUserIdRequest.hpp"
#include "request/CreateProgressByUserIdRequest.hpp"
#include "request/GetProgressRequest.hpp"
#include "request/GetProgressByUserIdRequest.hpp"
#include "request/StartRequest.hpp"
#include "request/StartByUserIdRequest.hpp"
#include "request/EndRequest.hpp"
#include "request/EndByUserIdRequest.hpp"
#include "request/DeleteProgressRequest.hpp"
#include "request/DeleteProgressByUserIdRequest.hpp"
#include "request/CreateProgressByStampSheetRequest.hpp"
#include "request/DeleteProgressByStampTaskRequest.hpp"
#include "request/DescribeCompletedQuestListsRequest.hpp"
#include "request/DescribeCompletedQuestListsByUserIdRequest.hpp"
#include "request/GetCompletedQuestListRequest.hpp"
#include "request/GetCompletedQuestListByUserIdRequest.hpp"
#include "request/DeleteCompletedQuestListByUserIdRequest.hpp"
#include "request/DescribeQuestGroupModelsRequest.hpp"
#include "request/GetQuestGroupModelRequest.hpp"
#include "request/DescribeQuestModelsRequest.hpp"
#include "request/GetQuestModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeQuestGroupModelMastersResult.hpp"
#include "result/CreateQuestGroupModelMasterResult.hpp"
#include "result/GetQuestGroupModelMasterResult.hpp"
#include "result/UpdateQuestGroupModelMasterResult.hpp"
#include "result/DeleteQuestGroupModelMasterResult.hpp"
#include "result/DescribeQuestModelMastersResult.hpp"
#include "result/CreateQuestModelMasterResult.hpp"
#include "result/GetQuestModelMasterResult.hpp"
#include "result/UpdateQuestModelMasterResult.hpp"
#include "result/DeleteQuestModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterResult.hpp"
#include "result/UpdateCurrentQuestMasterFromGitHubResult.hpp"
#include "result/DescribeProgressesByUserIdResult.hpp"
#include "result/CreateProgressByUserIdResult.hpp"
#include "result/GetProgressResult.hpp"
#include "result/GetProgressByUserIdResult.hpp"
#include "result/StartResult.hpp"
#include "result/StartByUserIdResult.hpp"
#include "result/EndResult.hpp"
#include "result/EndByUserIdResult.hpp"
#include "result/DeleteProgressResult.hpp"
#include "result/DeleteProgressByUserIdResult.hpp"
#include "result/CreateProgressByStampSheetResult.hpp"
#include "result/DeleteProgressByStampTaskResult.hpp"
#include "result/DescribeCompletedQuestListsResult.hpp"
#include "result/DescribeCompletedQuestListsByUserIdResult.hpp"
#include "result/GetCompletedQuestListResult.hpp"
#include "result/GetCompletedQuestListByUserIdResult.hpp"
#include "result/DeleteCompletedQuestListByUserIdResult.hpp"
#include "result/DescribeQuestGroupModelsResult.hpp"
#include "result/GetQuestGroupModelResult.hpp"
#include "result/DescribeQuestModelsResult.hpp"
#include "result/GetQuestModelResult.hpp"

namespace gs2 { namespace quest {

/**
 * GS2 Quest API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2QuestWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2QuestWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * クエストを分類するカテゴリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback);

	/**
	 * クエストを分類するカテゴリーを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback);

	/**
	 * クエストを分類するカテゴリーの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback);

	/**
	 * クエストを分類するカテゴリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback);

	/**
	 * クエストを分類するカテゴリーを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback);

	/**
	 * クエストを分類するカテゴリーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback);

	/**
	 * クエストグループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModelMasters(DescribeQuestGroupModelMastersRequest request, std::function<void(AsyncDescribeQuestGroupModelMastersResult)> callback);

	/**
	 * クエストグループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestGroupModelMaster(CreateQuestGroupModelMasterRequest request, std::function<void(AsyncCreateQuestGroupModelMasterResult)> callback);

	/**
	 * クエストグループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModelMaster(GetQuestGroupModelMasterRequest request, std::function<void(AsyncGetQuestGroupModelMasterResult)> callback);

	/**
	 * クエストグループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestGroupModelMaster(UpdateQuestGroupModelMasterRequest request, std::function<void(AsyncUpdateQuestGroupModelMasterResult)> callback);

	/**
	 * クエストグループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestGroupModelMaster(DeleteQuestGroupModelMasterRequest request, std::function<void(AsyncDeleteQuestGroupModelMasterResult)> callback);

	/**
	 * クエストモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModelMasters(DescribeQuestModelMastersRequest request, std::function<void(AsyncDescribeQuestModelMastersResult)> callback);

	/**
	 * クエストモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQuestModelMaster(CreateQuestModelMasterRequest request, std::function<void(AsyncCreateQuestModelMasterResult)> callback);

	/**
	 * クエストモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModelMaster(GetQuestModelMasterRequest request, std::function<void(AsyncGetQuestModelMasterResult)> callback);

	/**
	 * クエストモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQuestModelMaster(UpdateQuestModelMasterRequest request, std::function<void(AsyncUpdateQuestModelMasterResult)> callback);

	/**
	 * クエストモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQuestModelMaster(DeleteQuestModelMasterRequest request, std::function<void(AsyncDeleteQuestModelMasterResult)> callback);

	/**
	 * 現在有効なクエストマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効なクエストマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentQuestMaster(GetCurrentQuestMasterRequest request, std::function<void(AsyncGetCurrentQuestMasterResult)> callback);

	/**
	 * 現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMaster(UpdateCurrentQuestMasterRequest request, std::function<void(AsyncUpdateCurrentQuestMasterResult)> callback);

	/**
	 * 現在有効なクエストマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentQuestMasterFromGitHub(UpdateCurrentQuestMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentQuestMasterFromGitHubResult)> callback);

	/**
	 * クエスト挑戦の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProgressesByUserId(DescribeProgressesByUserIdRequest request, std::function<void(AsyncDescribeProgressesByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してクエスト挑戦を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByUserId(CreateProgressByUserIdRequest request, std::function<void(AsyncCreateProgressByUserIdResult)> callback);

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgress(GetProgressRequest request, std::function<void(AsyncGetProgressResult)> callback);

	/**
	 * ユーザIDを指定してクエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgressByUserId(GetProgressByUserIdRequest request, std::function<void(AsyncGetProgressByUserIdResult)> callback);

	/**
	 * クエストを開始<br>
	 *   <br>
	 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
	 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
	 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
	 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
	 *   <br>
	 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
	 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
	 *   <br>
	 *   transactionId は実行中のクエスト固有のIDです。<br>
	 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
	 *   <br>
	 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
	 *   クエストを開始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
	 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
	 *   <br>
	 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
	 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
	 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void start(StartRequest request, std::function<void(AsyncStartResult)> callback);

	/**
	 * ユーザIDを指定してクエストを開始<br>
	 *   <br>
	 *   同一カテゴリ内でゲームプレイヤーは同時に1つのクエストを実行できます。<br>
	 *   すでに同一カテゴリ内で実行中のクエストがある場合、このAPIはエラーを返します。<br>
	 *   進行中のクエストを取得するAPIを呼び出すことで、クエストを再開するために必要な情報を得ることができます。<br>
	 *   強制的にクエストを開始するには force パラメータに true を指定することで強制的にクエストを開始できます。<br>
	 *   <br>
	 *   クエストが正常に開始できた場合、Progress オブジェクトを応答します。<br>
	 *   Progress オブジェクトはクエストを実行するために必要ないくつかの情報を応答します。<br>
	 *   <br>
	 *   transactionId は実行中のクエスト固有のIDです。<br>
	 *   クエストの完了報告にはこのIDを指定する必要があります。<br>
	 *   <br>
	 *   randomSeed はクエストの内容を決定するために使用できる乱数シードです。<br>
	 *   クエストを開®®始するたびに異なる乱数が払い出されますので、この値をシード値としてゲームを進行させることで<br>
	 *   クエスト中にアプリケーションを強制終了したとしても同一条件で再開することができます。<br>
	 *   <br>
	 *   rewards にはこのクエストにおいて入手可能な報酬とその数量の"最大値"が得られます。<br>
	 *   クエストの完了報告にも rewards を渡すことができ、そこでクエスト中に実際に入手したアイテムの数量を指定します。<br>
	 *   詳細はクエストの完了報告APIのドキュメントを参照してください。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void startByUserId(StartByUserIdRequest request, std::function<void(AsyncStartByUserIdResult)> callback);

	/**
	 * クエストを完了<br>
	 *   <br>
	 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
	 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void end(EndRequest request, std::function<void(AsyncEndResult)> callback);

	/**
	 * ユーザIDを指定してクエストを完了<br>
	 *   <br>
	 *   開始時に受け取ったクエストにおいて入手可能な報酬とその数量の"最大値"のうち、クエスト内で実際に入手した報酬を rewards で報告します。<br>
	 *   isComplete にはクエストをクリアできたかを報告します。クエストに失敗した場合、rewards の値は無視してクエストに設定された失敗した場合の報酬が付与されます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void endByUserId(EndByUserIdRequest request, std::function<void(AsyncEndByUserIdResult)> callback);

	/**
	 * クエスト挑戦を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgress(DeleteProgressRequest request, std::function<void(AsyncDeleteProgressResult)> callback);

	/**
	 * ユーザIDを指定してクエスト挑戦を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByUserId(DeleteProgressByUserIdRequest request, std::function<void(AsyncDeleteProgressByUserIdResult)> callback);

	/**
	 * スタンプシートでクエストを開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByStampSheet(CreateProgressByStampSheetRequest request, std::function<void(AsyncCreateProgressByStampSheetResult)> callback);

	/**
	 * スタンプタスクで クエスト挑戦 を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByStampTask(DeleteProgressByStampTaskRequest request, std::function<void(AsyncDeleteProgressByStampTaskResult)> callback);

	/**
	 * クエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestLists(DescribeCompletedQuestListsRequest request, std::function<void(AsyncDescribeCompletedQuestListsResult)> callback);

	/**
	 * ユーザIDを指定してクエスト進行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCompletedQuestListsByUserId(DescribeCompletedQuestListsByUserIdRequest request, std::function<void(AsyncDescribeCompletedQuestListsByUserIdResult)> callback);

	/**
	 * クエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestList(GetCompletedQuestListRequest request, std::function<void(AsyncGetCompletedQuestListResult)> callback);

	/**
	 * ユーザIDを指定してクエスト進行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCompletedQuestListByUserId(GetCompletedQuestListByUserIdRequest request, std::function<void(AsyncGetCompletedQuestListByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してクエスト進行を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCompletedQuestListByUserId(DeleteCompletedQuestListByUserIdRequest request, std::function<void(AsyncDeleteCompletedQuestListByUserIdResult)> callback);

	/**
	 * クエストグループの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestGroupModels(DescribeQuestGroupModelsRequest request, std::function<void(AsyncDescribeQuestGroupModelsResult)> callback);

	/**
	 * クエストグループを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestGroupModel(GetQuestGroupModelRequest request, std::function<void(AsyncGetQuestGroupModelResult)> callback);

	/**
	 * クエストモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQuestModels(DescribeQuestModelsRequest request, std::function<void(AsyncDescribeQuestModelsResult)> callback);

	/**
	 * クエストモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQuestModel(GetQuestModelRequest request, std::function<void(AsyncGetQuestModelResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_