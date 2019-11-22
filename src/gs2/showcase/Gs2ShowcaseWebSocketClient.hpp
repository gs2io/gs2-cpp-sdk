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

#ifndef GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_
#define GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeSalesItemMastersRequest.hpp"
#include "request/CreateSalesItemMasterRequest.hpp"
#include "request/GetSalesItemMasterRequest.hpp"
#include "request/UpdateSalesItemMasterRequest.hpp"
#include "request/DeleteSalesItemMasterRequest.hpp"
#include "request/DescribeSalesItemGroupMastersRequest.hpp"
#include "request/CreateSalesItemGroupMasterRequest.hpp"
#include "request/GetSalesItemGroupMasterRequest.hpp"
#include "request/UpdateSalesItemGroupMasterRequest.hpp"
#include "request/DeleteSalesItemGroupMasterRequest.hpp"
#include "request/DescribeShowcaseMastersRequest.hpp"
#include "request/CreateShowcaseMasterRequest.hpp"
#include "request/GetShowcaseMasterRequest.hpp"
#include "request/UpdateShowcaseMasterRequest.hpp"
#include "request/DeleteShowcaseMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterFromGitHubRequest.hpp"
#include "request/DescribeShowcasesRequest.hpp"
#include "request/DescribeShowcasesByUserIdRequest.hpp"
#include "request/GetShowcaseRequest.hpp"
#include "request/GetShowcaseByUserIdRequest.hpp"
#include "request/BuyRequest.hpp"
#include "request/BuyByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeSalesItemMastersResult.hpp"
#include "result/CreateSalesItemMasterResult.hpp"
#include "result/GetSalesItemMasterResult.hpp"
#include "result/UpdateSalesItemMasterResult.hpp"
#include "result/DeleteSalesItemMasterResult.hpp"
#include "result/DescribeSalesItemGroupMastersResult.hpp"
#include "result/CreateSalesItemGroupMasterResult.hpp"
#include "result/GetSalesItemGroupMasterResult.hpp"
#include "result/UpdateSalesItemGroupMasterResult.hpp"
#include "result/DeleteSalesItemGroupMasterResult.hpp"
#include "result/DescribeShowcaseMastersResult.hpp"
#include "result/CreateShowcaseMasterResult.hpp"
#include "result/GetShowcaseMasterResult.hpp"
#include "result/UpdateShowcaseMasterResult.hpp"
#include "result/DeleteShowcaseMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterFromGitHubResult.hpp"
#include "result/DescribeShowcasesResult.hpp"
#include "result/DescribeShowcasesByUserIdResult.hpp"
#include "result/GetShowcaseResult.hpp"
#include "result/GetShowcaseByUserIdResult.hpp"
#include "result/BuyResult.hpp"
#include "result/BuyByUserIdResult.hpp"

namespace gs2 { namespace showcase {

/**
 * GS2 Showcase API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ShowcaseWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ShowcaseWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 商品マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSalesItemMasters(DescribeSalesItemMastersRequest request, std::function<void(AsyncDescribeSalesItemMastersResult)> callback);

	/**
	 * 商品マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemMaster(CreateSalesItemMasterRequest request, std::function<void(AsyncCreateSalesItemMasterResult)> callback);

	/**
	 * 商品マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemMaster(GetSalesItemMasterRequest request, std::function<void(AsyncGetSalesItemMasterResult)> callback);

	/**
	 * 商品マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemMaster(UpdateSalesItemMasterRequest request, std::function<void(AsyncUpdateSalesItemMasterResult)> callback);

	/**
	 * 商品マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemMaster(DeleteSalesItemMasterRequest request, std::function<void(AsyncDeleteSalesItemMasterResult)> callback);

	/**
	 * 商品グループマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSalesItemGroupMasters(DescribeSalesItemGroupMastersRequest request, std::function<void(AsyncDescribeSalesItemGroupMastersResult)> callback);

	/**
	 * 商品グループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemGroupMaster(CreateSalesItemGroupMasterRequest request, std::function<void(AsyncCreateSalesItemGroupMasterResult)> callback);

	/**
	 * 商品グループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemGroupMaster(GetSalesItemGroupMasterRequest request, std::function<void(AsyncGetSalesItemGroupMasterResult)> callback);

	/**
	 * 商品グループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemGroupMaster(UpdateSalesItemGroupMasterRequest request, std::function<void(AsyncUpdateSalesItemGroupMasterResult)> callback);

	/**
	 * 商品グループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemGroupMaster(DeleteSalesItemGroupMasterRequest request, std::function<void(AsyncDeleteSalesItemGroupMasterResult)> callback);

	/**
	 * 陳列棚マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcaseMasters(DescribeShowcaseMastersRequest request, std::function<void(AsyncDescribeShowcaseMastersResult)> callback);

	/**
	 * 陳列棚マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createShowcaseMaster(CreateShowcaseMasterRequest request, std::function<void(AsyncCreateShowcaseMasterResult)> callback);

	/**
	 * 陳列棚マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseMaster(GetShowcaseMasterRequest request, std::function<void(AsyncGetShowcaseMasterResult)> callback);

	/**
	 * 陳列棚マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateShowcaseMaster(UpdateShowcaseMasterRequest request, std::function<void(AsyncUpdateShowcaseMasterResult)> callback);

	/**
	 * 陳列棚マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteShowcaseMaster(DeleteShowcaseMasterRequest request, std::function<void(AsyncDeleteShowcaseMasterResult)> callback);

	/**
	 * 現在有効な陳列棚マスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効な陳列棚マスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentShowcaseMaster(GetCurrentShowcaseMasterRequest request, std::function<void(AsyncGetCurrentShowcaseMasterResult)> callback);

	/**
	 * 現在有効な陳列棚マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentShowcaseMaster(UpdateCurrentShowcaseMasterRequest request, std::function<void(AsyncUpdateCurrentShowcaseMasterResult)> callback);

	/**
	 * 現在有効な陳列棚マスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentShowcaseMasterFromGitHub(UpdateCurrentShowcaseMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentShowcaseMasterFromGitHubResult)> callback);

	/**
	 * 陳列棚の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcases(DescribeShowcasesRequest request, std::function<void(AsyncDescribeShowcasesResult)> callback);

	/**
	 * ユーザIDを指定して陳列棚の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeShowcasesByUserId(DescribeShowcasesByUserIdRequest request, std::function<void(AsyncDescribeShowcasesByUserIdResult)> callback);

	/**
	 * 陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcase(GetShowcaseRequest request, std::function<void(AsyncGetShowcaseResult)> callback);

	/**
	 * ユーザIDを指定して陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseByUserId(GetShowcaseByUserIdRequest request, std::function<void(AsyncGetShowcaseByUserIdResult)> callback);

	/**
	 * 陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void buy(BuyRequest request, std::function<void(AsyncBuyResult)> callback);

	/**
	 * ユーザIDを指定して陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void buyByUserId(BuyByUserIdRequest request, std::function<void(AsyncBuyByUserIdResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_