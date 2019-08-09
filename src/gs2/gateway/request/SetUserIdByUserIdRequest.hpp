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

#ifndef GS2_GATEWAY_CONTROL_SETUSERIDBYUSERIDREQUEST_HPP_
#define GS2_GATEWAY_CONTROL_SETUSERIDBYUSERIDREQUEST_HPP_

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
class SetUserIdByUserIdRequest : public Gs2BasicRequest, public Gs2Gateway
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** コネクションID */
        optional<StringHolder> connectionId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 同時に異なるクライアントからの接続を許容するか */
        optional<Bool> allowConcurrentAccess;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            connectionId(data.connectionId),
            userId(data.userId),
            allowConcurrentAccess(data.allowConcurrentAccess),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            connectionId(std::move(data.connectionId)),
            userId(std::move(data.userId)),
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
    SetUserIdByUserIdRequest() :
        m_pData(nullptr)
    {}

    SetUserIdByUserIdRequest(const SetUserIdByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gateway(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SetUserIdByUserIdRequest(SetUserIdByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gateway(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SetUserIdByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetUserIdByUserIdRequest& operator=(const SetUserIdByUserIdRequest& setUserIdByUserIdRequest)
    {
        Gs2BasicRequest::operator=(setUserIdByUserIdRequest);
        Gs2Gateway::operator=(setUserIdByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setUserIdByUserIdRequest.m_pData);

        return *this;
    }

    SetUserIdByUserIdRequest& operator=(SetUserIdByUserIdRequest&& setUserIdByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(setUserIdByUserIdRequest));
        Gs2Gateway::operator=(std::move(setUserIdByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setUserIdByUserIdRequest.m_pData;
        setUserIdByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const SetUserIdByUserIdRequest* operator->() const
    {
        return this;
    }

    SetUserIdByUserIdRequest* operator->()
    {
        return this;
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
    SetUserIdByUserIdRequest& withNamespaceName(const Char* namespaceName)
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
    SetUserIdByUserIdRequest& withConnectionId(const Char* connectionId)
    {
        ensureData().connectionId.emplace(connectionId);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    SetUserIdByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    SetUserIdByUserIdRequest& withAllowConcurrentAccess(Bool allowConcurrentAccess)
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
    SetUserIdByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    SetUserIdByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SetUserIdByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SetUserIdByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetUserIdByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SETUSERIDBYUSERIDREQUEST_HPP_