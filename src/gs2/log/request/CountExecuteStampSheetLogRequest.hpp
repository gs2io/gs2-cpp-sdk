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

#ifndef GS2_LOG_CONTROL_COUNTEXECUTESTAMPSHEETLOGREQUEST_HPP_
#define GS2_LOG_CONTROL_COUNTEXECUTESTAMPSHEETLOGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/log/Gs2LogConst.hpp>
#include <gs2/log/model/model.hpp>
#include <memory>

namespace gs2 { namespace log
{

/**
 * スタンプシート実行ログの一覧を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CountExecuteStampSheetLogRequest : public Gs2BasicRequest, public Gs2Log
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** マイクロサービスの種類を集計軸に使用するか */
        optional<Bool> service;
        /** マイクロサービスのメソッドを集計軸に使用するか */
        optional<Bool> method;
        /** ユーザIDを集計軸に使用するか */
        optional<Bool> userId;
        /** 報酬アクションの種類を集計軸に使用するか */
        optional<Bool> action;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int64> limit;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            service(data.service),
            method(data.method),
            userId(data.userId),
            action(data.action),
            pageToken(data.pageToken),
            limit(data.limit),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    CountExecuteStampSheetLogRequest() = default;
    CountExecuteStampSheetLogRequest(const CountExecuteStampSheetLogRequest& countExecuteStampSheetLogRequest) = default;
    CountExecuteStampSheetLogRequest(CountExecuteStampSheetLogRequest&& countExecuteStampSheetLogRequest) = default;
    ~CountExecuteStampSheetLogRequest() GS2_OVERRIDE = default;

    CountExecuteStampSheetLogRequest& operator=(const CountExecuteStampSheetLogRequest& countExecuteStampSheetLogRequest) = default;
    CountExecuteStampSheetLogRequest& operator=(CountExecuteStampSheetLogRequest&& countExecuteStampSheetLogRequest) = default;

    CountExecuteStampSheetLogRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CountExecuteStampSheetLogRequest);
    }

    const CountExecuteStampSheetLogRequest* operator->() const
    {
        return this;
    }

    CountExecuteStampSheetLogRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    CountExecuteStampSheetLogRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * マイクロサービスの種類を集計軸に使用するかを取得
     *
     * @return マイクロサービスの種類を集計軸に使用するか
     */
    const optional<Bool>& getService() const
    {
        return ensureData().service;
    }

    /**
     * マイクロサービスの種類を集計軸に使用するかを設定
     *
     * @param service マイクロサービスの種類を集計軸に使用するか
     */
    void setService(Bool service)
    {
        ensureData().service.emplace(service);
    }

    /**
     * マイクロサービスの種類を集計軸に使用するかを設定
     *
     * @param service マイクロサービスの種類を集計軸に使用するか
     */
    CountExecuteStampSheetLogRequest& withService(Bool service)
    {
        ensureData().service.emplace(service);
        return *this;
    }

    /**
     * マイクロサービスのメソッドを集計軸に使用するかを取得
     *
     * @return マイクロサービスのメソッドを集計軸に使用するか
     */
    const optional<Bool>& getMethod() const
    {
        return ensureData().method;
    }

    /**
     * マイクロサービスのメソッドを集計軸に使用するかを設定
     *
     * @param method マイクロサービスのメソッドを集計軸に使用するか
     */
    void setMethod(Bool method)
    {
        ensureData().method.emplace(method);
    }

    /**
     * マイクロサービスのメソッドを集計軸に使用するかを設定
     *
     * @param method マイクロサービスのメソッドを集計軸に使用するか
     */
    CountExecuteStampSheetLogRequest& withMethod(Bool method)
    {
        ensureData().method.emplace(method);
        return *this;
    }

    /**
     * ユーザIDを集計軸に使用するかを取得
     *
     * @return ユーザIDを集計軸に使用するか
     */
    const optional<Bool>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを集計軸に使用するかを設定
     *
     * @param userId ユーザIDを集計軸に使用するか
     */
    void setUserId(Bool userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを集計軸に使用するかを設定
     *
     * @param userId ユーザIDを集計軸に使用するか
     */
    CountExecuteStampSheetLogRequest& withUserId(Bool userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 報酬アクションの種類を集計軸に使用するかを取得
     *
     * @return 報酬アクションの種類を集計軸に使用するか
     */
    const optional<Bool>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * 報酬アクションの種類を集計軸に使用するかを設定
     *
     * @param action 報酬アクションの種類を集計軸に使用するか
     */
    void setAction(Bool action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * 報酬アクションの種類を集計軸に使用するかを設定
     *
     * @param action 報酬アクションの種類を集計軸に使用するか
     */
    CountExecuteStampSheetLogRequest& withAction(Bool action)
    {
        ensureData().action.emplace(action);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(StringHolder pageToken)
    {
        ensureData().pageToken.emplace(std::move(pageToken));
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    CountExecuteStampSheetLogRequest& withPageToken(StringHolder pageToken)
    {
        ensureData().pageToken.emplace(std::move(pageToken));
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int64>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int64 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    CountExecuteStampSheetLogRequest& withLimit(Int64 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    CountExecuteStampSheetLogRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CountExecuteStampSheetLogRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CountExecuteStampSheetLogRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOG_CONTROL_COUNTEXECUTESTAMPSHEETLOGREQUEST_HPP_