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

#ifndef GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETREQUEST_HPP_
#define GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/stamina/Gs2StaminaConst.hpp>
#include <gs2/stamina/model/model.hpp>
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタンプシートでスタミナの最大値を更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SetRecoverIntervalByStampSheetRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名検証に使用する 暗号鍵 のGRN */
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
    SetRecoverIntervalByStampSheetRequest() = default;
    SetRecoverIntervalByStampSheetRequest(const SetRecoverIntervalByStampSheetRequest& setRecoverIntervalByStampSheetRequest) = default;
    SetRecoverIntervalByStampSheetRequest(SetRecoverIntervalByStampSheetRequest&& setRecoverIntervalByStampSheetRequest) = default;
    ~SetRecoverIntervalByStampSheetRequest() GS2_OVERRIDE = default;

    SetRecoverIntervalByStampSheetRequest& operator=(const SetRecoverIntervalByStampSheetRequest& setRecoverIntervalByStampSheetRequest) = default;
    SetRecoverIntervalByStampSheetRequest& operator=(SetRecoverIntervalByStampSheetRequest&& setRecoverIntervalByStampSheetRequest) = default;

    SetRecoverIntervalByStampSheetRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetRecoverIntervalByStampSheetRequest);
    }

    const SetRecoverIntervalByStampSheetRequest* operator->() const
    {
        return this;
    }

    SetRecoverIntervalByStampSheetRequest* operator->()
    {
        return this;
    }

    /**
     * スタンプシートを取得
     *
     * @return スタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }

    /**
     * スタンプシートを設定
     *
     * @param stampSheet スタンプシート
     */
    SetRecoverIntervalByStampSheetRequest& withStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
        return *this;
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを取得
     *
     * @return スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * スタンプシートの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプシートの署名検証に使用する 暗号鍵 のGRN
     */
    SetRecoverIntervalByStampSheetRequest& withKeyId(StringHolder keyId)
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
    SetRecoverIntervalByStampSheetRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SetRecoverIntervalByStampSheetRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetRecoverIntervalByStampSheetRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETREQUEST_HPP_