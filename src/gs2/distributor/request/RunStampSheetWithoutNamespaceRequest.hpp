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

#ifndef GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETWITHOUTNAMESPACEREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETWITHOUTNAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/distributor/Gs2DistributorConst.hpp>
#include <gs2/distributor/model/model.hpp>
#include <memory>

namespace gs2 { namespace distributor
{

/**
 * スタンプシートの完了を報告する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class RunStampSheetWithoutNamespaceRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** 実行するスタンプタスク */
        optional<StringHolder> stampSheet;
        /** スタンプシートの暗号化に使用した暗号鍵GRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            stampSheet(data.stampSheet),
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
    RunStampSheetWithoutNamespaceRequest() = default;
    RunStampSheetWithoutNamespaceRequest(const RunStampSheetWithoutNamespaceRequest& runStampSheetWithoutNamespaceRequest) = default;
    RunStampSheetWithoutNamespaceRequest(RunStampSheetWithoutNamespaceRequest&& runStampSheetWithoutNamespaceRequest) = default;
    ~RunStampSheetWithoutNamespaceRequest() GS2_OVERRIDE = default;

    RunStampSheetWithoutNamespaceRequest& operator=(const RunStampSheetWithoutNamespaceRequest& runStampSheetWithoutNamespaceRequest) = default;
    RunStampSheetWithoutNamespaceRequest& operator=(RunStampSheetWithoutNamespaceRequest&& runStampSheetWithoutNamespaceRequest) = default;

    RunStampSheetWithoutNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RunStampSheetWithoutNamespaceRequest);
    }

    const RunStampSheetWithoutNamespaceRequest* operator->() const
    {
        return this;
    }

    RunStampSheetWithoutNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * 実行するスタンプタスクを取得
     *
     * @return 実行するスタンプタスク
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 実行するスタンプタスクを設定
     *
     * @param stampSheet 実行するスタンプタスク
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }

    /**
     * 実行するスタンプタスクを設定
     *
     * @param stampSheet 実行するスタンプタスク
     */
    RunStampSheetWithoutNamespaceRequest& withStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
        return *this;
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを取得
     *
     * @return スタンプシートの暗号化に使用した暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを設定
     *
     * @param keyId スタンプシートの暗号化に使用した暗号鍵GRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * スタンプシートの暗号化に使用した暗号鍵GRNを設定
     *
     * @param keyId スタンプシートの暗号化に使用した暗号鍵GRN
     */
    RunStampSheetWithoutNamespaceRequest& withKeyId(StringHolder keyId)
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
    RunStampSheetWithoutNamespaceRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    RunStampSheetWithoutNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RunStampSheetWithoutNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETWITHOUTNAMESPACEREQUEST_HPP_