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

#ifndef GS2_LOCK_GS2LOCKRESTCLIENT_HPP_
#define GS2_LOCK_GS2LOCKRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeMutexesRequest.hpp"
#include "request/DescribeMutexesByUserIdRequest.hpp"
#include "request/LockRequest.hpp"
#include "request/LockByUserIdRequest.hpp"
#include "request/UnlockRequest.hpp"
#include "request/UnlockByUserIdRequest.hpp"
#include "request/GetMutexRequest.hpp"
#include "request/GetMutexByUserIdRequest.hpp"
#include "request/DeleteMutexByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeMutexesResult.hpp"
#include "result/DescribeMutexesByUserIdResult.hpp"
#include "result/LockResult.hpp"
#include "result/LockByUserIdResult.hpp"
#include "result/UnlockResult.hpp"
#include "result/UnlockByUserIdResult.hpp"
#include "result/GetMutexResult.hpp"
#include "result/GetMutexByUserIdResult.hpp"
#include "result/DeleteMutexByUserIdResult.hpp"

namespace gs2 { namespace lock {

/**
 * GS2 Lock API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LockRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2LockRestClient(Gs2RestSession& gs2RestSession) :
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
	 * ミューテックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMutexes(DescribeMutexesRequest request, std::function<void(AsyncDescribeMutexesResult)> callback);

	/**
	 * ミューテックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMutexesByUserId(DescribeMutexesByUserIdRequest request, std::function<void(AsyncDescribeMutexesByUserIdResult)> callback);

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lock(LockRequest request, std::function<void(AsyncLockResult)> callback);

	/**
	 * ユーザIDを指定してミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void lockByUserId(LockByUserIdRequest request, std::function<void(AsyncLockByUserIdResult)> callback);

	/**
	 * ミューテックスを解放<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlock(UnlockRequest request, std::function<void(AsyncUnlockResult)> callback);

	/**
	 * ユーザIDを指定してミューテックスを解放<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unlockByUserId(UnlockByUserIdRequest request, std::function<void(AsyncUnlockByUserIdResult)> callback);

	/**
	 * ミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMutex(GetMutexRequest request, std::function<void(AsyncGetMutexResult)> callback);

	/**
	 * ユーザIDを指定してミューテックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMutexByUserId(GetMutexByUserIdRequest request, std::function<void(AsyncGetMutexByUserIdResult)> callback);

	/**
	 * ミューテックスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMutexByUserId(DeleteMutexByUserIdRequest request, std::function<void(AsyncDeleteMutexByUserIdResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOCK_GS2LOCKRESTCLIENT_HPP_