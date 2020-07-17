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

#ifndef GS2_EXCHANGE_CONTROL_ACQUIREREQUEST_HPP_
#define GS2_EXCHANGE_CONTROL_ACQUIREREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/Gs2ExchangeConst.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * 交換待機の報酬を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AcquireRequest : public Gs2BasicRequest, public Gs2Exchange
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
        /** 交換レート名 */
        optional<StringHolder> rateName;
        /** 交換待機の名前 */
        optional<StringHolder> awaitName;
        /** 設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            rateName(data.rateName),
            awaitName(data.awaitName),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.config)
            {
                config = data.config->deepCopy();
            }
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
    AcquireRequest() = default;
    AcquireRequest(const AcquireRequest& acquireRequest) = default;
    AcquireRequest(AcquireRequest&& acquireRequest) = default;
    ~AcquireRequest() GS2_OVERRIDE = default;

    AcquireRequest& operator=(const AcquireRequest& acquireRequest) = default;
    AcquireRequest& operator=(AcquireRequest&& acquireRequest) = default;

    AcquireRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcquireRequest);
    }

    const AcquireRequest* operator->() const
    {
        return this;
    }

    AcquireRequest* operator->()
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
    AcquireRequest& withAccessToken(StringHolder accessToken)
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
    AcquireRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 交換レート名を取得
     *
     * @return 交換レート名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * 交換レート名を設定
     *
     * @param rateName 交換レート名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * 交換レート名を設定
     *
     * @param rateName 交換レート名
     */
    AcquireRequest& withRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
        return *this;
    }

    /**
     * 交換待機の名前を取得
     *
     * @return 交換待機の名前
     */
    const optional<StringHolder>& getAwaitName() const
    {
        return ensureData().awaitName;
    }

    /**
     * 交換待機の名前を設定
     *
     * @param awaitName 交換待機の名前
     */
    void setAwaitName(StringHolder awaitName)
    {
        ensureData().awaitName.emplace(std::move(awaitName));
    }

    /**
     * 交換待機の名前を設定
     *
     * @param awaitName 交換待機の名前
     */
    AcquireRequest& withAwaitName(StringHolder awaitName)
    {
        ensureData().awaitName.emplace(std::move(awaitName));
        return *this;
    }

    /**
     * 設定値を取得
     *
     * @return 設定値
     */
    const optional<List<Config>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * 設定値を設定
     *
     * @param config 設定値
     */
    void setConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * 設定値を設定
     *
     * @param config 設定値
     */
    AcquireRequest& withConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
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
    AcquireRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    AcquireRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AcquireRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXCHANGE_CONTROL_ACQUIREREQUEST_HPP_