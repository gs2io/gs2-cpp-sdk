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

#ifndef GS2_GATEWAY_CONTROL_SETUSERIDREQUEST_HPP_
#define GS2_GATEWAY_CONTROL_SETUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GatewayConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace gateway
{

/**
 * WebsocketセッションにユーザIDを設定 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SetUserIdRequest : public Gs2BasicRequest, public Gs2Gateway
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
        /** コネクションID */
        optional<StringHolder> connectionId;
        /** 同時に異なるクライアントからの接続を許容するか */
        optional<Bool> allowConcurrentAccess;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            connectionId(data.connectionId),
            allowConcurrentAccess(data.allowConcurrentAccess),
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
    SetUserIdRequest() = default;
    SetUserIdRequest(const SetUserIdRequest& setUserIdRequest) = default;
    SetUserIdRequest(SetUserIdRequest&& setUserIdRequest) = default;
    ~SetUserIdRequest() GS2_OVERRIDE = default;

    SetUserIdRequest& operator=(const SetUserIdRequest& setUserIdRequest) = default;
    SetUserIdRequest& operator=(SetUserIdRequest&& setUserIdRequest) = default;

    SetUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetUserIdRequest);
    }

    const SetUserIdRequest* operator->() const
    {
        return this;
    }

    SetUserIdRequest* operator->()
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
    SetUserIdRequest& withAccessToken(StringHolder accessToken)
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
    SetUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * コネクションIDを取得
     *
     * @return コネクションID
     */
    const optional<StringHolder>& getConnectionId() const
    {
        return ensureData().connectionId;
    }

    /**
     * コネクションIDを設定
     *
     * @param connectionId コネクションID
     */
    void setConnectionId(StringHolder connectionId)
    {
        ensureData().connectionId.emplace(std::move(connectionId));
    }

    /**
     * コネクションIDを設定
     *
     * @param connectionId コネクションID
     */
    SetUserIdRequest& withConnectionId(StringHolder connectionId)
    {
        ensureData().connectionId.emplace(std::move(connectionId));
        return *this;
    }

    /**
     * 同時に異なるクライアントからの接続を許容するかを取得
     *
     * @return 同時に異なるクライアントからの接続を許容するか
     */
    const optional<Bool>& getAllowConcurrentAccess() const
    {
        return ensureData().allowConcurrentAccess;
    }

    /**
     * 同時に異なるクライアントからの接続を許容するかを設定
     *
     * @param allowConcurrentAccess 同時に異なるクライアントからの接続を許容するか
     */
    void setAllowConcurrentAccess(Bool allowConcurrentAccess)
    {
        ensureData().allowConcurrentAccess.emplace(allowConcurrentAccess);
    }

    /**
     * 同時に異なるクライアントからの接続を許容するかを設定
     *
     * @param allowConcurrentAccess 同時に異なるクライアントからの接続を許容するか
     */
    SetUserIdRequest& withAllowConcurrentAccess(Bool allowConcurrentAccess)
    {
        ensureData().allowConcurrentAccess.emplace(allowConcurrentAccess);
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
    SetUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SetUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SETUSERIDREQUEST_HPP_