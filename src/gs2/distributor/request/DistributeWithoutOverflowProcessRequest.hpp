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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSREQUEST_HPP_

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
 * 所持品を配布する(溢れた際の救済処置無し) のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeWithoutOverflowProcessRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** 加算するリソース */
        optional<DistributeResource> distributeResource;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.distributeResource)
            {
                distributeResource = data.distributeResource->deepCopy();
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
    DistributeWithoutOverflowProcessRequest() = default;
    DistributeWithoutOverflowProcessRequest(const DistributeWithoutOverflowProcessRequest& distributeWithoutOverflowProcessRequest) = default;
    DistributeWithoutOverflowProcessRequest(DistributeWithoutOverflowProcessRequest&& distributeWithoutOverflowProcessRequest) = default;
    ~DistributeWithoutOverflowProcessRequest() GS2_OVERRIDE = default;

    DistributeWithoutOverflowProcessRequest& operator=(const DistributeWithoutOverflowProcessRequest& distributeWithoutOverflowProcessRequest) = default;
    DistributeWithoutOverflowProcessRequest& operator=(DistributeWithoutOverflowProcessRequest&& distributeWithoutOverflowProcessRequest) = default;

    DistributeWithoutOverflowProcessRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DistributeWithoutOverflowProcessRequest);
    }

    const DistributeWithoutOverflowProcessRequest* operator->() const
    {
        return this;
    }

    DistributeWithoutOverflowProcessRequest* operator->()
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
    DistributeWithoutOverflowProcessRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
    }

    /**
     * 加算するリソースを取得
     *
     * @return 加算するリソース
     */
    const optional<DistributeResource>& getDistributeResource() const
    {
        return ensureData().distributeResource;
    }

    /**
     * 加算するリソースを設定
     *
     * @param distributeResource 加算するリソース
     */
    void setDistributeResource(DistributeResource distributeResource)
    {
        ensureData().distributeResource.emplace(std::move(distributeResource));
    }

    /**
     * 加算するリソースを設定
     *
     * @param distributeResource 加算するリソース
     */
    DistributeWithoutOverflowProcessRequest& withDistributeResource(DistributeResource distributeResource)
    {
        ensureData().distributeResource.emplace(std::move(distributeResource));
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
    DistributeWithoutOverflowProcessRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    DistributeWithoutOverflowProcessRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DistributeWithoutOverflowProcessRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTEWITHOUTOVERFLOWPROCESSREQUEST_HPP_