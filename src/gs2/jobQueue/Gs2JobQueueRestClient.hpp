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

#ifndef GS2_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_
#define GS2_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeJobsByUserIdRequest.hpp"
#include "request/GetJobByUserIdRequest.hpp"
#include "request/PushByUserIdRequest.hpp"
#include "request/RunRequest.hpp"
#include "request/RunByUserIdRequest.hpp"
#include "request/DeleteJobByUserIdRequest.hpp"
#include "request/PushByStampSheetRequest.hpp"
#include "request/DescribeDeadLetterJobsByUserIdRequest.hpp"
#include "request/GetDeadLetterJobByUserIdRequest.hpp"
#include "request/DeleteDeadLetterJobByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeJobsByUserIdResult.hpp"
#include "result/GetJobByUserIdResult.hpp"
#include "result/PushByUserIdResult.hpp"
#include "result/RunResult.hpp"
#include "result/RunByUserIdResult.hpp"
#include "result/DeleteJobByUserIdResult.hpp"
#include "result/PushByStampSheetResult.hpp"
#include "result/DescribeDeadLetterJobsByUserIdResult.hpp"
#include "result/GetDeadLetterJobByUserIdResult.hpp"
#include "result/DeleteDeadLetterJobByUserIdResult.hpp"

namespace gs2 { namespace jobQueue {

/**
 * GS2 JobQueue API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2JobQueueRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2JobQueueRestClient(Gs2RestSession& gs2RestSession) :
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
	 * ジョブの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeJobsByUserId(DescribeJobsByUserIdRequest request, std::function<void(AsyncDescribeJobsByUserIdResult)> callback);

	/**
	 * ジョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getJobByUserId(GetJobByUserIdRequest request, std::function<void(AsyncGetJobByUserIdResult)> callback);

	/**
	 * ユーザIDを指定してジョブを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void pushByUserId(PushByUserIdRequest request, std::function<void(AsyncPushByUserIdResult)> callback);

	/**
	 * ジョブを実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void run(RunRequest request, std::function<void(AsyncRunResult)> callback);

	/**
	 * ユーザIDを指定してジョブを実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runByUserId(RunByUserIdRequest request, std::function<void(AsyncRunByUserIdResult)> callback);

	/**
	 * ジョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteJobByUserId(DeleteJobByUserIdRequest request, std::function<void(AsyncDeleteJobByUserIdResult)> callback);

	/**
	 * スタンプシートでジョブを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void pushByStampSheet(PushByStampSheetRequest request, std::function<void(AsyncPushByStampSheetResult)> callback);

	/**
	 * デッドレタージョブの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDeadLetterJobsByUserId(DescribeDeadLetterJobsByUserIdRequest request, std::function<void(AsyncDescribeDeadLetterJobsByUserIdResult)> callback);

	/**
	 * デッドレタージョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDeadLetterJobByUserId(GetDeadLetterJobByUserIdRequest request, std::function<void(AsyncGetDeadLetterJobByUserIdResult)> callback);

	/**
	 * デッドレタージョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDeadLetterJobByUserId(DeleteDeadLetterJobByUserIdRequest request, std::function<void(AsyncDeleteDeadLetterJobByUserIdResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_