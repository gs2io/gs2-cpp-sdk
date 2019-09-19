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

#ifndef GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_

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
 * スタミナを消費 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeStaminaRequest : public Gs2BasicRequest, public Gs2Stamina
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
        /** 消費するスタミナ量 */
        optional<Int32> consumeValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            consumeValue(data.consumeValue),
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
    ConsumeStaminaRequest() = default;
    ConsumeStaminaRequest(const ConsumeStaminaRequest& consumeStaminaRequest) = default;
    ConsumeStaminaRequest(ConsumeStaminaRequest&& consumeStaminaRequest) = default;
    ~ConsumeStaminaRequest() GS2_OVERRIDE = default;

    ConsumeStaminaRequest& operator=(const ConsumeStaminaRequest& consumeStaminaRequest) = default;
    ConsumeStaminaRequest& operator=(ConsumeStaminaRequest&& consumeStaminaRequest) = default;

    ConsumeStaminaRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ConsumeStaminaRequest);
    }

    const ConsumeStaminaRequest* operator->() const
    {
        return this;
    }

    ConsumeStaminaRequest* operator->()
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
    ConsumeStaminaRequest& withAccessToken(StringHolder accessToken)
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
    ConsumeStaminaRequest& withNamespaceName(StringHolder namespaceName)
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
    ConsumeStaminaRequest& withStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
        return *this;
    }

    /**
     * 消費するスタミナ量を取得
     *
     * @return 消費するスタミナ量
     */
    const optional<Int32>& getConsumeValue() const
    {
        return ensureData().consumeValue;
    }

    /**
     * 消費するスタミナ量を設定
     *
     * @param consumeValue 消費するスタミナ量
     */
    void setConsumeValue(Int32 consumeValue)
    {
        ensureData().consumeValue.emplace(consumeValue);
    }

    /**
     * 消費するスタミナ量を設定
     *
     * @param consumeValue 消費するスタミナ量
     */
    ConsumeStaminaRequest& withConsumeValue(Int32 consumeValue)
    {
        ensureData().consumeValue.emplace(consumeValue);
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
    ConsumeStaminaRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    ConsumeStaminaRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ConsumeStaminaRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CONSUMESTAMINAREQUEST_HPP_