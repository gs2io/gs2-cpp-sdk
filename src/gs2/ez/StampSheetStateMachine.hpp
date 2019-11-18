/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_
#define GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_

#include "../core/common.hpp"
#include "../core/AsyncResult.hpp"
#include "EzStampSheet.hpp"
#include <functional>
#include <mutex>

namespace gs2 { namespace ez {

class Client;

/**
 * スタンプシート処理用ステートマシン
 *
 * @author Game Server Services, Inc.
 *
 */
class StampSheetStateMachine
{
public:
    typedef std::function<void(EzStampSheet, distributor::AsyncEzRunStampSheetResult)> EzStampSheetCallback;
    typedef std::function<void(EzStampTask, distributor::AsyncEzRunStampTaskResult)> EzStampTaskCallback;

private:
    EzStampSheet m_EzStampSheet;
    Client& m_Client;
    StringHolder m_DistributorNamespaceName;
    StringHolder m_StampSheetEncryptKeyId;

    EzStampSheetCallback m_EzStampSheetCallback;
    EzStampTaskCallback m_EzStampTaskCallback;

    enum class State {
        Idle,
        Running,
    } m_State;
    Int32 m_Step;
    StringHolder m_StackContext;
    distributor::AsyncEzRunStampSheetResult m_AsyncEzRunStampSheetResult;

    std::mutex m_Mutex;

private:
    void executeStep(Int32 step);

public:
    /**
     * コンストラクタ
     *
     * @param signedStampSheetString 署名付きスタンプシート文字列
     * @param client クライアントインスタンスへの参照
     * @param distributorNamespaceName 実行する GS2-Distributor のネームスペース名
     * @param stampSheetEncryptKeyId スタンプシートを暗号化したキーの ID
     * @param ezStampSheetCallback スタンプシートの処理完了時に呼ばれるコールバック
     * @param ezStampTaskCallback 各スタンプタスクの処理完了ごとに呼ばれるコールバック
     */
    StampSheetStateMachine(
        StringHolder signedStampSheetString,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId,
        EzStampSheetCallback ezStampSheetCallback,
        EzStampTaskCallback ezStampTaskCallback = nullptr
    );

    /**
     * コンストラクタ
     *
     * @param ezStampSheet EzStampSheet オブジェクト
     * @param client クライアントインスタンスへの参照
     * @param distributorNamespaceName 実行する GS2-Distributor のネームスペース名
     * @param stampSheetEncryptKeyId スタンプシートを暗号化したキーの ID
     * @param ezStampSheetCallback スタンプシートの処理完了時に呼ばれるコールバック
     * @param ezStampTaskCallback 各スタンプタスクの処理完了ごとに呼ばれるコールバック
     */
    StampSheetStateMachine(
        EzStampSheet ezStampSheet,
        Client& client,
        StringHolder distributorNamespaceName,
        StringHolder stampSheetEncryptKeyId,
        EzStampSheetCallback ezStampSheetCallback,
        EzStampTaskCallback ezStampTaskCallback = nullptr
    );

    /**
     * スタンプシートの処理を実行します
     *
     * この関数はスタンプシートの処理を開始し、即座に返ります。
     * 処理完了後、その結果が成功か失敗かにかかわらず、スタンプシートの処理完了コールバックが呼び出されます。
     * スタンプタスクの処理完了コールバックが設定されている場合、各タスクの処理完了ごとにそれが呼び出されます。
     * 途中のスタンプタスクが失敗したあと、再度この関数を呼び出すと、失敗したタスクから処理を再試行します。
     * この関数を呼び出した後、スタンプシートの処理完了コールバックが呼び出されるより前に再度この関数を呼び出した場合、
     * コールバックは合計1回しか呼び出されないことに注意してください。
     */
    void execute();
};

}}

#endif //GS2_EZ_STAMPSHEETSTATEMACHINE_HPP_
