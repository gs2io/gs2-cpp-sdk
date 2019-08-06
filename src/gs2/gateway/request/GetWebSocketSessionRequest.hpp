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

#ifndef GS2_GATEWAY_CONTROL_GETWEBSOCKETSESSIONREQUEST_HPP_
#define GS2_GATEWAY_CONTROL_GETWEBSOCKETSESSIONREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GatewayConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gateway
{

/**
 * Websocketセッションを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetWebSocketSessionRequest : public Gs2BasicRequest, public Gs2Gateway
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            connectionId(data.connectionId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            connectionId(std::move(data.connectionId))
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
    GetWebSocketSessionRequest() :
        m_pData(nullptr)
    {}

    GetWebSocketSessionRequest(const GetWebSocketSessionRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gateway(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetWebSocketSessionRequest(GetWebSocketSessionRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gateway(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetWebSocketSessionRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWebSocketSessionRequest& operator=(const GetWebSocketSessionRequest& getWebSocketSessionRequest)
    {
        Gs2BasicRequest::operator=(getWebSocketSessionRequest);
        Gs2Gateway::operator=(getWebSocketSessionRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWebSocketSessionRequest.m_pData);

        return *this;
    }

    GetWebSocketSessionRequest& operator=(GetWebSocketSessionRequest&& getWebSocketSessionRequest)
    {
        Gs2BasicRequest::operator=(std::move(getWebSocketSessionRequest));
        Gs2Gateway::operator=(std::move(getWebSocketSessionRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWebSocketSessionRequest.m_pData;
        getWebSocketSessionRequest.m_pData = nullptr;

        return *this;
    }

    const GetWebSocketSessionRequest* operator->() const
    {
        return this;
    }

    GetWebSocketSessionRequest* operator->()
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
    GetWebSocketSessionRequest& withNamespaceName(const Char* namespaceName)
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
    GetWebSocketSessionRequest& withConnectionId(const Char* connectionId)
    {
        ensureData().connectionId.emplace(connectionId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetWebSocketSessionRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetWebSocketSessionRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetWebSocketSessionRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetWebSocketSessionRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_GETWEBSOCKETSESSIONREQUEST_HPP_