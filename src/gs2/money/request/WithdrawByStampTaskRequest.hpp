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

#ifndef GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKREQUEST_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace money
{

/**
 * ウォレットから残高を消費します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawByStampTaskRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタンプタスク */
        optional<StringHolder> stampTask;
        /** スタンプタスクの署名検証に使用する 暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            stampTask(data.stampTask),
            keyId(data.keyId),
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
    WithdrawByStampTaskRequest() = default;
    WithdrawByStampTaskRequest(const WithdrawByStampTaskRequest& withdrawByStampTaskRequest) = default;
    WithdrawByStampTaskRequest(WithdrawByStampTaskRequest&& withdrawByStampTaskRequest) = default;
    ~WithdrawByStampTaskRequest() GS2_OVERRIDE = default;

    WithdrawByStampTaskRequest& operator=(const WithdrawByStampTaskRequest& withdrawByStampTaskRequest) = default;
    WithdrawByStampTaskRequest& operator=(WithdrawByStampTaskRequest&& withdrawByStampTaskRequest) = default;

    WithdrawByStampTaskRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WithdrawByStampTaskRequest);
    }

    const WithdrawByStampTaskRequest* operator->() const
    {
        return this;
    }

    WithdrawByStampTaskRequest* operator->()
    {
        return this;
    }

    /**
     * スタンプタスクを取得
     *
     * @return スタンプタスク
     */
    const optional<StringHolder>& getStampTask() const
    {
        return ensureData().stampTask;
    }

    /**
     * スタンプタスクを設定
     *
     * @param stampTask スタンプタスク
     */
    void setStampTask(StringHolder stampTask)
    {
        ensureData().stampTask.emplace(std::move(stampTask));
    }

    /**
     * スタンプタスクを設定
     *
     * @param stampTask スタンプタスク
     */
    WithdrawByStampTaskRequest& withStampTask(StringHolder stampTask)
    {
        ensureData().stampTask.emplace(std::move(stampTask));
        return *this;
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを取得
     *
     * @return スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    WithdrawByStampTaskRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
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
    WithdrawByStampTaskRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    WithdrawByStampTaskRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WithdrawByStampTaskRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKREQUEST_HPP_