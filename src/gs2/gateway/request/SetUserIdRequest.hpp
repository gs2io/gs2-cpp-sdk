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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GatewayConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            connectionId(data.connectionId),
            allowConcurrentAccess(data.allowConcurrentAccess),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accessToken(std::move(data.accessToken)),
            namespaceName(std::move(data.namespaceName)),
            connectionId(std::move(data.connectionId)),
            allowConcurrentAccess(std::move(data.allowConcurrentAccess)),
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
    SetUserIdRequest() :
        m_pData(nullptr)
    {}

    SetUserIdRequest(const SetUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gateway(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SetUserIdRequest(SetUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gateway(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SetUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetUserIdRequest& operator=(const SetUserIdRequest& setUserIdRequest)
    {
        Gs2BasicRequest::operator=(setUserIdRequest);
        Gs2Gateway::operator=(setUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setUserIdRequest.m_pData);

        return *this;
    }

    SetUserIdRequest& operator=(SetUserIdRequest&& setUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(setUserIdRequest));
        Gs2Gateway::operator=(std::move(setUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setUserIdRequest.m_pData;
        setUserIdRequest.m_pData = nullptr;

        return *this;
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
    SetUserIdRequest& withAccessToken(const Char* accessToken) {
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
    SetUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setConnectionId(const Char* connectionId)
    {
        ensureData().connectionId.emplace(connectionId);
    }

    /**
     * コネクションIDを設定
     *
     * @param connectionId コネクションID
     */
    SetUserIdRequest& withConnectionId(const Char* connectionId)
    {
        ensureData().connectionId.emplace(connectionId);
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    SetUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    SetUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SetUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SetUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SETUSERIDREQUEST_HPP_