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

#ifndef GS2_EZ_GATEWAY_MODEL_EZWEBSOCKETSESSION_HPP_
#define GS2_EZ_GATEWAY_MODEL_EZWEBSOCKETSESSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace gateway {

class WebSocketSession;

}

namespace ez { namespace gateway {

class EzWebSocketSession : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** コネクションID */
        gs2::optional<StringHolder> connectionId;
        /** ネームスペース名 */
        gs2::optional<StringHolder> namespaceName;
        /** ユーザーID */
        gs2::optional<StringHolder> userId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::gateway::WebSocketSession& webSocketSession);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzWebSocketSession() = default;
    EzWebSocketSession(const EzWebSocketSession& ezWebSocketSession) = default;
    EzWebSocketSession(EzWebSocketSession&& ezWebSocketSession) = default;
    ~EzWebSocketSession() = default;

    EzWebSocketSession(gs2::gateway::WebSocketSession webSocketSession);

    EzWebSocketSession& operator=(const EzWebSocketSession& ezWebSocketSession) = default;
    EzWebSocketSession& operator=(EzWebSocketSession&& ezWebSocketSession) = default;

    EzWebSocketSession deepCopy() const;

    gs2::gateway::WebSocketSession ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getConnectionId() const
    {
        return *ensureData().connectionId;
    }

    const StringHolder& getNamespaceName() const
    {
        return *ensureData().namespaceName;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setConnectionId(StringHolder connectionId)
    {
        ensureData().connectionId = std::move(connectionId);
    }

    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName = std::move(namespaceName);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    EzWebSocketSession& withConnectionId(StringHolder connectionId)
    {
        setConnectionId(std::move(connectionId));
        return *this;
    }

    EzWebSocketSession& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(std::move(namespaceName));
        return *this;
    }

    EzWebSocketSession& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_GATEWAY_EZWEBSOCKETSESSION_HPP_