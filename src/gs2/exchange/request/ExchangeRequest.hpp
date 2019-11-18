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

#ifndef GS2_EXCHANGE_CONTROL_EXCHANGEREQUEST_HPP_
#define GS2_EXCHANGE_CONTROL_EXCHANGEREQUEST_HPP_

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
 * 交換を実行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class ExchangeRequest : public Gs2BasicRequest, public Gs2Exchange
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
        /** 交換レートの種類名 */
        optional<StringHolder> rateName;
        /** 交換するロット数 */
        optional<Int32> count;
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
            count(data.count),
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
    ExchangeRequest() = default;
    ExchangeRequest(const ExchangeRequest& exchangeRequest) = default;
    ExchangeRequest(ExchangeRequest&& exchangeRequest) = default;
    ~ExchangeRequest() GS2_OVERRIDE = default;

    ExchangeRequest& operator=(const ExchangeRequest& exchangeRequest) = default;
    ExchangeRequest& operator=(ExchangeRequest&& exchangeRequest) = default;

    ExchangeRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExchangeRequest);
    }

    const ExchangeRequest* operator->() const
    {
        return this;
    }

    ExchangeRequest* operator->()
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
    ExchangeRequest& withAccessToken(StringHolder accessToken)
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
    ExchangeRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 交換レートの種類名を取得
     *
     * @return 交換レートの種類名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * 交換レートの種類名を設定
     *
     * @param rateName 交換レートの種類名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * 交換レートの種類名を設定
     *
     * @param rateName 交換レートの種類名
     */
    ExchangeRequest& withRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
        return *this;
    }

    /**
     * 交換するロット数を取得
     *
     * @return 交換するロット数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 交換するロット数を設定
     *
     * @param count 交換するロット数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 交換するロット数を設定
     *
     * @param count 交換するロット数
     */
    ExchangeRequest& withCount(Int32 count)
    {
        ensureData().count.emplace(count);
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
    ExchangeRequest& withConfig(List<Config> config)
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
    ExchangeRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    ExchangeRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ExchangeRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXCHANGE_CONTROL_EXCHANGEREQUEST_HPP_