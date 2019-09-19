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

#ifndef GS2_STAMINA_CONTROL_SETMAXVALUEBYSTATUSREQUEST_HPP_
#define GS2_STAMINA_CONTROL_SETMAXVALUEBYSTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタミナの最大値をGS2-Experienceのステータスを使用して更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SetMaxValueByStatusRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaName;
        /** 署名をつけるのに使用した暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 署名対象のステータスボディ */
        optional<StringHolder> signedStatusBody;
        /** ステータスの署名 */
        optional<StringHolder> signedStatusSignature;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            keyId(data.keyId),
            signedStatusBody(data.signedStatusBody),
            signedStatusSignature(data.signedStatusSignature),
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
    SetMaxValueByStatusRequest() = default;
    SetMaxValueByStatusRequest(const SetMaxValueByStatusRequest& setMaxValueByStatusRequest) = default;
    SetMaxValueByStatusRequest(SetMaxValueByStatusRequest&& setMaxValueByStatusRequest) = default;
    ~SetMaxValueByStatusRequest() GS2_OVERRIDE = default;

    SetMaxValueByStatusRequest& operator=(const SetMaxValueByStatusRequest& setMaxValueByStatusRequest) = default;
    SetMaxValueByStatusRequest& operator=(SetMaxValueByStatusRequest&& setMaxValueByStatusRequest) = default;

    SetMaxValueByStatusRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetMaxValueByStatusRequest);
    }

    const SetMaxValueByStatusRequest* operator->() const
    {
        return this;
    }

    SetMaxValueByStatusRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    SetMaxValueByStatusRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    SetMaxValueByStatusRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getStaminaName() const
    {
        return ensureData().staminaName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    void setStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    SetMaxValueByStatusRequest& withStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
        return *this;
    }

    /**
     * 署名をつけるのに使用した暗号鍵 のGRNを取得
     *
     * @return 署名をつけるのに使用した暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 署名をつけるのに使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名をつけるのに使用した暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 署名をつけるのに使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名をつけるのに使用した暗号鍵 のGRN
     */
    SetMaxValueByStatusRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }

    /**
     * 署名対象のステータスボディを取得
     *
     * @return 署名対象のステータスボディ
     */
    const optional<StringHolder>& getSignedStatusBody() const
    {
        return ensureData().signedStatusBody;
    }

    /**
     * 署名対象のステータスボディを設定
     *
     * @param signedStatusBody 署名対象のステータスボディ
     */
    void setSignedStatusBody(StringHolder signedStatusBody)
    {
        ensureData().signedStatusBody.emplace(std::move(signedStatusBody));
    }

    /**
     * 署名対象のステータスボディを設定
     *
     * @param signedStatusBody 署名対象のステータスボディ
     */
    SetMaxValueByStatusRequest& withSignedStatusBody(StringHolder signedStatusBody)
    {
        ensureData().signedStatusBody.emplace(std::move(signedStatusBody));
        return *this;
    }

    /**
     * ステータスの署名を取得
     *
     * @return ステータスの署名
     */
    const optional<StringHolder>& getSignedStatusSignature() const
    {
        return ensureData().signedStatusSignature;
    }

    /**
     * ステータスの署名を設定
     *
     * @param signedStatusSignature ステータスの署名
     */
    void setSignedStatusSignature(StringHolder signedStatusSignature)
    {
        ensureData().signedStatusSignature.emplace(std::move(signedStatusSignature));
    }

    /**
     * ステータスの署名を設定
     *
     * @param signedStatusSignature ステータスの署名
     */
    SetMaxValueByStatusRequest& withSignedStatusSignature(StringHolder signedStatusSignature)
    {
        ensureData().signedStatusSignature.emplace(std::move(signedStatusSignature));
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
    SetMaxValueByStatusRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SetMaxValueByStatusRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetMaxValueByStatusRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_SETMAXVALUEBYSTATUSREQUEST_HPP_