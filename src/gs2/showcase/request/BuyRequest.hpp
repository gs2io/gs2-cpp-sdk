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

#ifndef GS2_SHOWCASE_CONTROL_BUYREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_BUYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/showcase/Gs2ShowcaseConst.hpp>
#include <gs2/showcase/model/model.hpp>
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 陳列棚を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class BuyRequest : public Gs2BasicRequest, public Gs2Showcase
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
        /** 商品名 */
        optional<StringHolder> showcaseName;
        /** 陳列商品ID */
        optional<StringHolder> displayItemId;
        /** 設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            showcaseName(data.showcaseName),
            displayItemId(data.displayItemId),
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
    BuyRequest() = default;
    BuyRequest(const BuyRequest& buyRequest) = default;
    BuyRequest(BuyRequest&& buyRequest) = default;
    ~BuyRequest() GS2_OVERRIDE = default;

    BuyRequest& operator=(const BuyRequest& buyRequest) = default;
    BuyRequest& operator=(BuyRequest&& buyRequest) = default;

    BuyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(BuyRequest);
    }

    const BuyRequest* operator->() const
    {
        return this;
    }

    BuyRequest* operator->()
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
    BuyRequest& withAccessToken(StringHolder accessToken)
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
    BuyRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * 商品名を設定
     *
     * @param showcaseName 商品名
     */
    void setShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
    }

    /**
     * 商品名を設定
     *
     * @param showcaseName 商品名
     */
    BuyRequest& withShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
        return *this;
    }

    /**
     * 陳列商品IDを取得
     *
     * @return 陳列商品ID
     */
    const optional<StringHolder>& getDisplayItemId() const
    {
        return ensureData().displayItemId;
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    void setDisplayItemId(StringHolder displayItemId)
    {
        ensureData().displayItemId.emplace(std::move(displayItemId));
    }

    /**
     * 陳列商品IDを設定
     *
     * @param displayItemId 陳列商品ID
     */
    BuyRequest& withDisplayItemId(StringHolder displayItemId)
    {
        ensureData().displayItemId.emplace(std::move(displayItemId));
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
    BuyRequest& withConfig(List<Config> config)
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
    BuyRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    BuyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    BuyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_BUYREQUEST_HPP_