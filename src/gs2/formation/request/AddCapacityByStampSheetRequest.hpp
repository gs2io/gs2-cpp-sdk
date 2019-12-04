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

#ifndef GS2_FORMATION_CONTROL_ADDCAPACITYBYSTAMPSHEETREQUEST_HPP_
#define GS2_FORMATION_CONTROL_ADDCAPACITYBYSTAMPSHEETREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/Gs2FormationConst.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * スタンプシートでキャパシティサイズを加算 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AddCapacityByStampSheetRequest : public Gs2BasicRequest, public Gs2Formation
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
    AddCapacityByStampSheetRequest() = default;
    AddCapacityByStampSheetRequest(const AddCapacityByStampSheetRequest& addCapacityByStampSheetRequest) = default;
    AddCapacityByStampSheetRequest(AddCapacityByStampSheetRequest&& addCapacityByStampSheetRequest) = default;
    ~AddCapacityByStampSheetRequest() GS2_OVERRIDE = default;

    AddCapacityByStampSheetRequest& operator=(const AddCapacityByStampSheetRequest& addCapacityByStampSheetRequest) = default;
    AddCapacityByStampSheetRequest& operator=(AddCapacityByStampSheetRequest&& addCapacityByStampSheetRequest) = default;

    AddCapacityByStampSheetRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AddCapacityByStampSheetRequest);
    }

    const AddCapacityByStampSheetRequest* operator->() const
    {
        return this;
    }

    AddCapacityByStampSheetRequest* operator->()
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
    AddCapacityByStampSheetRequest& withStampSheet(StringHolder stampSheet)
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
    AddCapacityByStampSheetRequest& withKeyId(StringHolder keyId)
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
    AddCapacityByStampSheetRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    AddCapacityByStampSheetRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AddCapacityByStampSheetRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_ADDCAPACITYBYSTAMPSHEETREQUEST_HPP_