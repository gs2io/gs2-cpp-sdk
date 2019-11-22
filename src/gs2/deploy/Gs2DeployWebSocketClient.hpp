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

#ifndef GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_
#define GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include "request/DescribeStacksRequest.hpp"
#include "request/CreateStackRequest.hpp"
#include "request/CreateStackFromGitHubRequest.hpp"
#include "request/GetStackStatusRequest.hpp"
#include "request/GetStackRequest.hpp"
#include "request/UpdateStackRequest.hpp"
#include "request/UpdateStackFromGitHubRequest.hpp"
#include "request/DeleteStackRequest.hpp"
#include "request/ForceDeleteStackRequest.hpp"
#include "request/DescribeResourcesRequest.hpp"
#include "request/GetResourceRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/DescribeOutputsRequest.hpp"
#include "request/GetOutputRequest.hpp"
#include "result/DescribeStacksResult.hpp"
#include "result/CreateStackResult.hpp"
#include "result/CreateStackFromGitHubResult.hpp"
#include "result/GetStackStatusResult.hpp"
#include "result/GetStackResult.hpp"
#include "result/UpdateStackResult.hpp"
#include "result/UpdateStackFromGitHubResult.hpp"
#include "result/DeleteStackResult.hpp"
#include "result/ForceDeleteStackResult.hpp"
#include "result/DescribeResourcesResult.hpp"
#include "result/GetResourceResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/DescribeOutputsResult.hpp"
#include "result/GetOutputResult.hpp"

namespace gs2 { namespace deploy {

/**
 * GS2 Deploy API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DeployWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2DeployWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * スタックの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStacks(DescribeStacksRequest request, std::function<void(AsyncDescribeStacksResult)> callback);

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStack(CreateStackRequest request, std::function<void(AsyncCreateStackResult)> callback);

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStackFromGitHub(CreateStackFromGitHubRequest request, std::function<void(AsyncCreateStackFromGitHubResult)> callback);

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStackStatus(GetStackStatusRequest request, std::function<void(AsyncGetStackStatusResult)> callback);

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStack(GetStackRequest request, std::function<void(AsyncGetStackResult)> callback);

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStack(UpdateStackRequest request, std::function<void(AsyncUpdateStackResult)> callback);

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStackFromGitHub(UpdateStackFromGitHubRequest request, std::function<void(AsyncUpdateStackFromGitHubResult)> callback);

	/**
	 * スタックを削除<br>
	 *   <br>
	 *   スタックの削除は2段階で行われます。<br>
	 *   DELETE_COMPLETED ステータスではないスタックを削除すると、まずはスタックによって作成されたリソースの削除を行います。<br>
	 *   DELETE_COMPLETED ステータスのスタックを削除すると、完全にエンティティを削除します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStack(DeleteStackRequest request, std::function<void(AsyncDeleteStackResult)> callback);

	/**
	 * スタックを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forceDeleteStack(ForceDeleteStackRequest request, std::function<void(AsyncForceDeleteStackResult)> callback);

	/**
	 * 作成されたのリソースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResources(DescribeResourcesRequest request, std::function<void(AsyncDescribeResourcesResult)> callback);

	/**
	 * 作成されたのリソースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResource(GetResourceRequest request, std::function<void(AsyncGetResourceResult)> callback);

	/**
	 * 発生したイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(DescribeEventsRequest request, std::function<void(AsyncDescribeEventsResult)> callback);

	/**
	 * 発生したイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(GetEventRequest request, std::function<void(AsyncGetEventResult)> callback);

	/**
	 * アウトプットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeOutputs(DescribeOutputsRequest request, std::function<void(AsyncDescribeOutputsResult)> callback);

	/**
	 * アウトプットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getOutput(GetOutputRequest request, std::function<void(AsyncGetOutputResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DEPLOY_GS2DEPLOYWEBSOCKETCLIENT_HPP_