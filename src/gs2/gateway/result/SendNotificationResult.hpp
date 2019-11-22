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

#ifndef GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_
#define GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/gateway/model/model.hpp>
#include <memory>

namespace gs2 { namespace gateway
{

/**
 * 通知を送信 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SendNotificationResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 通知に使用したプロトコル */
        optional<StringHolder> protocol;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SendNotificationResult() = default;
    SendNotificationResult(const SendNotificationResult& sendNotificationResult) = default;
    SendNotificationResult(SendNotificationResult&& sendNotificationResult) = default;
    ~SendNotificationResult() = default;

    SendNotificationResult& operator=(const SendNotificationResult& sendNotificationResult) = default;
    SendNotificationResult& operator=(SendNotificationResult&& sendNotificationResult) = default;

    SendNotificationResult deepCopy() const;

    const SendNotificationResult* operator->() const
    {
        return this;
    }

    SendNotificationResult* operator->()
    {
        return this;
    }
    /**
     * 通知に使用したプロトコルを取得
     *
     * @return 通知に使用したプロトコル
     */
    const optional<StringHolder>& getProtocol() const
    {
        return ensureData().protocol;
    }

    /**
     * 通知に使用したプロトコルを設定
     *
     * @param protocol 通知に使用したプロトコル
     */
    void setProtocol(StringHolder protocol)
    {
        ensureData().protocol.emplace(std::move(protocol));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<SendNotificationResult> AsyncSendNotificationResult;

} }

#endif //GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_