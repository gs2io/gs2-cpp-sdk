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

#ifndef GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_
#define GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeCategoryModelsRequest.hpp"
#include "request/GetCategoryModelRequest.hpp"
#include "request/DescribeCategoryModelMastersRequest.hpp"
#include "request/CreateCategoryModelMasterRequest.hpp"
#include "request/GetCategoryModelMasterRequest.hpp"
#include "request/UpdateCategoryModelMasterRequest.hpp"
#include "request/DeleteCategoryModelMasterRequest.hpp"
#include "request/DescribeSubscribesByCategoryNameRequest.hpp"
#include "request/DescribeSubscribesByCategoryNameAndUserIdRequest.hpp"
#include "request/SubscribeRequest.hpp"
#include "request/SubscribeByUserIdRequest.hpp"
#include "request/GetSubscribeRequest.hpp"
#include "request/GetSubscribeByUserIdRequest.hpp"
#include "request/UnsubscribeRequest.hpp"
#include "request/UnsubscribeByUserIdRequest.hpp"
#include "request/DescribeRankingsRequest.hpp"
#include "request/DescribeRankingssByUserIdRequest.hpp"
#include "request/DescribeNearRankingsRequest.hpp"
#include "request/PutScoreRequest.hpp"
#include "request/PutScoreByUserIdRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRankingMasterRequest.hpp"
#include "request/UpdateCurrentRankingMasterRequest.hpp"
#include "request/UpdateCurrentRankingMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCategoryModelsResult.hpp"
#include "result/GetCategoryModelResult.hpp"
#include "result/DescribeCategoryModelMastersResult.hpp"
#include "result/CreateCategoryModelMasterResult.hpp"
#include "result/GetCategoryModelMasterResult.hpp"
#include "result/UpdateCategoryModelMasterResult.hpp"
#include "result/DeleteCategoryModelMasterResult.hpp"
#include "result/DescribeSubscribesByCategoryNameResult.hpp"
#include "result/DescribeSubscribesByCategoryNameAndUserIdResult.hpp"
#include "result/SubscribeResult.hpp"
#include "result/SubscribeByUserIdResult.hpp"
#include "result/GetSubscribeResult.hpp"
#include "result/GetSubscribeByUserIdResult.hpp"
#include "result/UnsubscribeResult.hpp"
#include "result/UnsubscribeByUserIdResult.hpp"
#include "result/DescribeRankingsResult.hpp"
#include "result/DescribeRankingssByUserIdResult.hpp"
#include "result/DescribeNearRankingsResult.hpp"
#include "result/PutScoreResult.hpp"
#include "result/PutScoreByUserIdResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentRankingMasterResult.hpp"
#include "result/UpdateCurrentRankingMasterResult.hpp"
#include "result/UpdateCurrentRankingMasterFromGitHubResult.hpp"

namespace gs2 { namespace ranking {

/**
 * GS2 Ranking API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2RankingRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2RankingRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
	 * カテゴリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategoryModels(DescribeCategoryModelsRequest request, std::function<void(AsyncDescribeCategoryModelsResult)> callback);

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryModel(GetCategoryModelRequest request, std::function<void(AsyncGetCategoryModelResult)> callback);

	/**
	 * カテゴリマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategoryModelMasters(DescribeCategoryModelMastersRequest request, std::function<void(AsyncDescribeCategoryModelMastersResult)> callback);

	/**
	 * カテゴリマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCategoryModelMaster(CreateCategoryModelMasterRequest request, std::function<void(AsyncCreateCategoryModelMasterResult)> callback);

	/**
	 * カテゴリマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryModelMaster(GetCategoryModelMasterRequest request, std::function<void(AsyncGetCategoryModelMasterResult)> callback);

	/**
	 * カテゴリマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCategoryModelMaster(UpdateCategoryModelMasterRequest request, std::function<void(AsyncUpdateCategoryModelMasterResult)> callback);

	/**
	 * カテゴリマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCategoryModelMaster(DeleteCategoryModelMasterRequest request, std::function<void(AsyncDeleteCategoryModelMasterResult)> callback);

	/**
	 * 購読しているユーザIDの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByCategoryName(DescribeSubscribesByCategoryNameRequest request, std::function<void(AsyncDescribeSubscribesByCategoryNameResult)> callback);

	/**
	 * ユーザIDを指定して購読しているユーザIDの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByCategoryNameAndUserId(DescribeSubscribesByCategoryNameAndUserIdRequest request, std::function<void(AsyncDescribeSubscribesByCategoryNameAndUserIdResult)> callback);

	/**
	 * ユーザIDを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribe(SubscribeRequest request, std::function<void(AsyncSubscribeResult)> callback);

	/**
	 * ユーザIDを指定してユーザIDを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribeByUserId(SubscribeByUserIdRequest request, std::function<void(AsyncSubscribeByUserIdResult)> callback);

	/**
	 * 購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(GetSubscribeRequest request, std::function<void(AsyncGetSubscribeResult)> callback);

	/**
	 * ユーザIDを指定して購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribeByUserId(GetSubscribeByUserIdRequest request, std::function<void(AsyncGetSubscribeByUserIdResult)> callback);

	/**
	 * 購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribe(UnsubscribeRequest request, std::function<void(AsyncUnsubscribeResult)> callback);

	/**
	 * ユーザIDを指定して購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribeByUserId(UnsubscribeByUserIdRequest request, std::function<void(AsyncUnsubscribeByUserIdResult)> callback);

	/**
	 * ランキングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRankings(DescribeRankingsRequest request, std::function<void(AsyncDescribeRankingsResult)> callback);

	/**
	 * ユーザIDを指定してランキングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRankingssByUserId(DescribeRankingssByUserIdRequest request, std::function<void(AsyncDescribeRankingssByUserIdResult)> callback);

	/**
	 * 指定したスコア付近のランキングを取得<br>
	 *   <br>
	 *   このAPIはグローバルランキングのときのみ使用できます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNearRankings(DescribeNearRankingsRequest request, std::function<void(AsyncDescribeNearRankingsResult)> callback);

	/**
	 * スコアを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putScore(PutScoreRequest request, std::function<void(AsyncPutScoreResult)> callback);

	/**
	 * ユーザーIDを指定してスコアを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putScoreByUserId(PutScoreByUserIdRequest request, std::function<void(AsyncPutScoreByUserIdResult)> callback);

	/**
	 * 現在有効なランキング設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback);

	/**
	 * 現在有効なランキング設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentRankingMaster(GetCurrentRankingMasterRequest request, std::function<void(AsyncGetCurrentRankingMasterResult)> callback);

	/**
	 * 現在有効なランキング設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRankingMaster(UpdateCurrentRankingMasterRequest request, std::function<void(AsyncUpdateCurrentRankingMasterResult)> callback);

	/**
	 * 現在有効なランキング設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRankingMasterFromGitHub(UpdateCurrentRankingMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRankingMasterFromGitHubResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_