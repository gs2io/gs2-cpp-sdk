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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            keyId(data.keyId),
            signedStatusBody(data.signedStatusBody),
            signedStatusSignature(data.signedStatusSignature),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accessToken(std::move(data.accessToken)),
            namespaceName(std::move(data.namespaceName)),
            staminaName(std::move(data.staminaName)),
            keyId(std::move(data.keyId)),
            signedStatusBody(std::move(data.signedStatusBody)),
            signedStatusSignature(std::move(data.signedStatusSignature)),
            duplicationAvoider(std::move(data.duplicationAvoider))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    SetMaxValueByStatusRequest() :
        m_pData(nullptr)
    {}

    SetMaxValueByStatusRequest(const SetMaxValueByStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SetMaxValueByStatusRequest(SetMaxValueByStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SetMaxValueByStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetMaxValueByStatusRequest& operator=(const SetMaxValueByStatusRequest& setMaxValueByStatusRequest)
    {
        Gs2BasicRequest::operator=(setMaxValueByStatusRequest);
        Gs2Stamina::operator=(setMaxValueByStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setMaxValueByStatusRequest.m_pData);

        return *this;
    }

    SetMaxValueByStatusRequest& operator=(SetMaxValueByStatusRequest&& setMaxValueByStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(setMaxValueByStatusRequest));
        Gs2Stamina::operator=(std::move(setMaxValueByStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setMaxValueByStatusRequest.m_pData;
        setMaxValueByStatusRequest.m_pData = nullptr;

        return *this;
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
    const gs2::optional<StringHolder>& getAccessToken() const {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(const Char* accessToken) {
        ensureData().accessToken.emplace(accessToken);
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    SetMaxValueByStatusRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    SetMaxValueByStatusRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setStaminaName(const Char* staminaName)
    {
        ensureData().staminaName.emplace(staminaName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    SetMaxValueByStatusRequest& withStaminaName(const Char* staminaName)
    {
        ensureData().staminaName.emplace(staminaName);
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
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 署名をつけるのに使用した暗号鍵 のGRNを設定
     *
     * @param keyId 署名をつけるのに使用した暗号鍵 のGRN
     */
    SetMaxValueByStatusRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
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
    void setSignedStatusBody(const Char* signedStatusBody)
    {
        ensureData().signedStatusBody.emplace(signedStatusBody);
    }

    /**
     * 署名対象のステータスボディを設定
     *
     * @param signedStatusBody 署名対象のステータスボディ
     */
    SetMaxValueByStatusRequest& withSignedStatusBody(const Char* signedStatusBody)
    {
        ensureData().signedStatusBody.emplace(signedStatusBody);
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
    void setSignedStatusSignature(const Char* signedStatusSignature)
    {
        ensureData().signedStatusSignature.emplace(signedStatusSignature);
    }

    /**
     * ステータスの署名を設定
     *
     * @param signedStatusSignature ステータスの署名
     */
    SetMaxValueByStatusRequest& withSignedStatusSignature(const Char* signedStatusSignature)
    {
        ensureData().signedStatusSignature.emplace(signedStatusSignature);
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    SetMaxValueByStatusRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SetMaxValueByStatusRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    SetMaxValueByStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    SetMaxValueByStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetMaxValueByStatusRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_SETMAXVALUEBYSTATUSREQUEST_HPP_