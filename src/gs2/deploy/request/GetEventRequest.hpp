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

#ifndef GS2_DEPLOY_CONTROL_GETEVENTREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_GETEVENTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace deploy
{

/**
 * 発生したイベントを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetEventRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** イベント名 */
        optional<StringHolder> eventName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            stackName(data.stackName),
            eventName(data.eventName)
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
    GetEventRequest() = default;
    GetEventRequest(const GetEventRequest& getEventRequest) = default;
    GetEventRequest(GetEventRequest&& getEventRequest) = default;
    ~GetEventRequest() GS2_OVERRIDE = default;

    GetEventRequest& operator=(const GetEventRequest& getEventRequest) = default;
    GetEventRequest& operator=(GetEventRequest&& getEventRequest) = default;

    GetEventRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetEventRequest);
    }

    const GetEventRequest* operator->() const
    {
        return this;
    }

    GetEventRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getStackName() const
    {
        return ensureData().stackName;
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    void setStackName(StringHolder stackName)
    {
        ensureData().stackName.emplace(std::move(stackName));
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    GetEventRequest& withStackName(StringHolder stackName)
    {
        ensureData().stackName.emplace(std::move(stackName));
        return *this;
    }

    /**
     * イベント名を取得
     *
     * @return イベント名
     */
    const optional<StringHolder>& getEventName() const
    {
        return ensureData().eventName;
    }

    /**
     * イベント名を設定
     *
     * @param eventName イベント名
     */
    void setEventName(StringHolder eventName)
    {
        ensureData().eventName.emplace(std::move(eventName));
    }

    /**
     * イベント名を設定
     *
     * @param eventName イベント名
     */
    GetEventRequest& withEventName(StringHolder eventName)
    {
        ensureData().eventName.emplace(std::move(eventName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetEventRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetEventRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETEVENTREQUEST_HPP_