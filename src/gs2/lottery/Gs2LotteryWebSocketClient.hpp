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

#ifndef GS2_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_
#define GS2_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeLotteryModelMastersRequest.hpp"
#include "request/CreateLotteryModelMasterRequest.hpp"
#include "request/GetLotteryModelMasterRequest.hpp"
#include "request/UpdateLotteryModelMasterRequest.hpp"
#include "request/DeleteLotteryModelMasterRequest.hpp"
#include "request/DescribePrizeTableMastersRequest.hpp"
#include "request/CreatePrizeTableMasterRequest.hpp"
#include "request/GetPrizeTableMasterRequest.hpp"
#include "request/UpdatePrizeTableMasterRequest.hpp"
#include "request/DeletePrizeTableMasterRequest.hpp"
#include "request/DescribeBoxesRequest.hpp"
#include "request/DescribeBoxesByUserIdRequest.hpp"
#include "request/GetBoxRequest.hpp"
#include "request/GetBoxByUserIdRequest.hpp"
#include "request/ResetBoxRequest.hpp"
#include "request/ResetBoxByUserIdRequest.hpp"
#include "request/DescribeLotteryModelsRequest.hpp"
#include "request/GetLotteryModelRequest.hpp"
#include "request/DescribePrizeTablesRequest.hpp"
#include "request/GetPrizeTableRequest.hpp"
#include "request/DrawByUserIdRequest.hpp"
#include "request/DescribeProbabilitiesRequest.hpp"
#include "request/DescribeProbabilitiesByUserIdRequest.hpp"
#include "request/DrawByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeLotteryModelMastersResult.hpp"
#include "result/CreateLotteryModelMasterResult.hpp"
#include "result/GetLotteryModelMasterResult.hpp"
#include "result/UpdateLotteryModelMasterResult.hpp"
#include "result/DeleteLotteryModelMasterResult.hpp"
#include "result/DescribePrizeTableMastersResult.hpp"
#include "result/CreatePrizeTableMasterResult.hpp"
#include "result/GetPrizeTableMasterResult.hpp"
#include "result/UpdatePrizeTableMasterResult.hpp"
#include "result/DeletePrizeTableMasterResult.hpp"
#include "result/DescribeBoxesResult.hpp"
#include "result/DescribeBoxesByUserIdResult.hpp"
#include "result/GetBoxResult.hpp"
#include "result/GetBoxByUserIdResult.hpp"
#include "result/ResetBoxResult.hpp"
#include "result/ResetBoxByUserIdResult.hpp"
#include "result/DescribeLotteryModelsResult.hpp"
#include "result/GetLotteryModelResult.hpp"
#include "result/DescribePrizeTablesResult.hpp"
#include "result/GetPrizeTableResult.hpp"
#include "result/DrawByUserIdResult.hpp"
#include "result/DescribeProbabilitiesResult.hpp"
#include "result/DescribeProbabilitiesByUserIdResult.hpp"
#include "result/DrawByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterFromGitHubResult.hpp"

namespace gs2 { namespace lottery {

/**
 * GS2 Lottery API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LotteryWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2LotteryWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 抽選の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModelMasters(DescribeLotteryModelMastersRequest request, std::function<void(AsyncDescribeLotteryModelMastersResult)> callback);

	/**
	 * 抽選の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLotteryModelMaster(CreateLotteryModelMasterRequest request, std::function<void(AsyncCreateLotteryModelMasterResult)> callback);

	/**
	 * 抽選の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModelMaster(GetLotteryModelMasterRequest request, std::function<void(AsyncGetLotteryModelMasterResult)> callback);

	/**
	 * 抽選の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLotteryModelMaster(UpdateLotteryModelMasterRequest request, std::function<void(AsyncUpdateLotteryModelMasterResult)> callback);

	/**
	 * 抽選の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLotteryModelMaster(DeleteLotteryModelMasterRequest request, std::function<void(AsyncDeleteLotteryModelMasterResult)> callback);

	/**
	 * 排出確率テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMasters(DescribePrizeTableMastersRequest request, std::function<void(AsyncDescribePrizeTableMastersResult)> callback);

	/**
	 * 排出確率テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(CreatePrizeTableMasterRequest request, std::function<void(AsyncCreatePrizeTableMasterResult)> callback);

	/**
	 * 排出確率テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(GetPrizeTableMasterRequest request, std::function<void(AsyncGetPrizeTableMasterResult)> callback);

	/**
	 * 排出確率テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeTableMaster(UpdatePrizeTableMasterRequest request, std::function<void(AsyncUpdatePrizeTableMasterResult)> callback);

	/**
	 * 排出確率テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(DeletePrizeTableMasterRequest request, std::function<void(AsyncDeletePrizeTableMasterResult)> callback);

	/**
	 * ボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxes(DescribeBoxesRequest request, std::function<void(AsyncDescribeBoxesResult)> callback);

	/**
	 * ユーザIDを指定してボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxesByUserId(DescribeBoxesByUserIdRequest request, std::function<void(AsyncDescribeBoxesByUserIdResult)> callback);

	/**
	 * ボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBox(GetBoxRequest request, std::function<void(AsyncGetBoxResult)> callback);

	/**
	 * ユーザIDを指定してボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBoxByUserId(GetBoxByUserIdRequest request, std::function<void(AsyncGetBoxByUserIdResult)> callback);

	/**
	 * ボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBox(ResetBoxRequest request, std::function<void(AsyncResetBoxResult)> callback);

	/**
	 * ユーザIDを指定してボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBoxByUserId(ResetBoxByUserIdRequest request, std::function<void(AsyncResetBoxByUserIdResult)> callback);

	/**
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModels(DescribeLotteryModelsRequest request, std::function<void(AsyncDescribeLotteryModelsResult)> callback);

	/**
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModel(GetLotteryModelRequest request, std::function<void(AsyncGetLotteryModelResult)> callback);

	/**
	 * 排出確率テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTables(DescribePrizeTablesRequest request, std::function<void(AsyncDescribePrizeTablesResult)> callback);

	/**
	 * 排出確率テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTable(GetPrizeTableRequest request, std::function<void(AsyncGetPrizeTableResult)> callback);

	/**
	 * ユーザIDを指定して抽選を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void drawByUserId(DrawByUserIdRequest request, std::function<void(AsyncDrawByUserIdResult)> callback);

	/**
	 * 排出確率を取得<br>
	 *   <br>
	 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
	 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilities(DescribeProbabilitiesRequest request, std::function<void(AsyncDescribeProbabilitiesResult)> callback);

	/**
	 * 排出確率を取得<br>
	 *   <br>
	 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
	 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilitiesByUserId(DescribeProbabilitiesByUserIdRequest request, std::function<void(AsyncDescribeProbabilitiesByUserIdResult)> callback);

	/**
	 * スタンプシートを使用して抽選処理を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void drawByStampSheet(DrawByStampSheetRequest request, std::function<void(AsyncDrawByStampSheetResult)> callback);

	/**
	 * 現在有効な抽選設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効な抽選設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLotteryMaster(GetCurrentLotteryMasterRequest request, std::function<void(AsyncGetCurrentLotteryMasterResult)> callback);

	/**
	 * 現在有効な抽選設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMaster(UpdateCurrentLotteryMasterRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterResult)> callback);

	/**
	 * 現在有効な抽選設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMasterFromGitHub(UpdateCurrentLotteryMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterFromGitHubResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_