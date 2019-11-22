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

#ifndef GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_
#define GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeGatheringsRequest.hpp"
#include "request/CreateGatheringRequest.hpp"
#include "request/CreateGatheringByUserIdRequest.hpp"
#include "request/UpdateGatheringRequest.hpp"
#include "request/UpdateGatheringByUserIdRequest.hpp"
#include "request/DoMatchmakingByPlayerRequest.hpp"
#include "request/DoMatchmakingRequest.hpp"
#include "request/GetGatheringRequest.hpp"
#include "request/CancelMatchmakingRequest.hpp"
#include "request/CancelMatchmakingByUserIdRequest.hpp"
#include "request/DeleteGatheringRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeGatheringsResult.hpp"
#include "result/CreateGatheringResult.hpp"
#include "result/CreateGatheringByUserIdResult.hpp"
#include "result/UpdateGatheringResult.hpp"
#include "result/UpdateGatheringByUserIdResult.hpp"
#include "result/DoMatchmakingByPlayerResult.hpp"
#include "result/DoMatchmakingResult.hpp"
#include "result/GetGatheringResult.hpp"
#include "result/CancelMatchmakingResult.hpp"
#include "result/CancelMatchmakingByUserIdResult.hpp"
#include "result/DeleteGatheringResult.hpp"

namespace gs2 { namespace matchmaking {

/**
 * GS2 Matchmaking API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MatchmakingRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2MatchmakingRestClient(Gs2RestSession& gs2RestSession) :
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
	 * ギャザリングの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGatherings(DescribeGatheringsRequest request, std::function<void(AsyncDescribeGatheringsResult)> callback);

	/**
	 * ギャザリングを作成して募集を開始<br>
	 *   <br>
	 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
	 *   <br>
	 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
	 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
	 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
	 *   <br>
	 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
	 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
	 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
	 *   <br>
	 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
	 *   ロールにはエイリアスを指定できます。<br>
	 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
	 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
	 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
	 *   <br>
	 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
	 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
	 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
	 *   <br>
	 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
	 *   <br>
	 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGathering(CreateGatheringRequest request, std::function<void(AsyncCreateGatheringResult)> callback);

	/**
	 * ギャザリングを作成して募集を開始<br>
	 *   <br>
	 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
	 *   <br>
	 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
	 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
	 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
	 *   <br>
	 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
	 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
	 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
	 *   <br>
	 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
	 *   ロールにはエイリアスを指定できます。<br>
	 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
	 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
	 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
	 *   <br>
	 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
	 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
	 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
	 *   <br>
	 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
	 *   <br>
	 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGatheringByUserId(CreateGatheringByUserIdRequest request, std::function<void(AsyncCreateGatheringByUserIdResult)> callback);

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGathering(UpdateGatheringRequest request, std::function<void(AsyncUpdateGatheringResult)> callback);

	/**
	 * ギャザリングを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGatheringByUserId(UpdateGatheringByUserIdRequest request, std::function<void(AsyncUpdateGatheringByUserIdResult)> callback);

	/**
	 * Player が参加できるギャザリングを探して参加する<br>
	 *   <br>
	 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
	 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
	 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doMatchmakingByPlayer(DoMatchmakingByPlayerRequest request, std::function<void(AsyncDoMatchmakingByPlayerResult)> callback);

	/**
	 * 自分が参加できるギャザリングを探して参加する<br>
	 *   <br>
	 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
	 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
	 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doMatchmaking(DoMatchmakingRequest request, std::function<void(AsyncDoMatchmakingResult)> callback);

	/**
	 * ギャザリングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGathering(GetGatheringRequest request, std::function<void(AsyncGetGatheringResult)> callback);

	/**
	 * マッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmaking(CancelMatchmakingRequest request, std::function<void(AsyncCancelMatchmakingResult)> callback);

	/**
	 * ユーザIDを指定してマッチメイキングをキャンセルする<br>
	 *   <br>
	 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void cancelMatchmakingByUserId(CancelMatchmakingByUserIdRequest request, std::function<void(AsyncCancelMatchmakingByUserIdResult)> callback);

	/**
	 * ギャザリングを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGathering(DeleteGatheringRequest request, std::function<void(AsyncDeleteGatheringResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MATCHMAKING_GS2MATCHMAKINGRESTCLIENT_HPP_