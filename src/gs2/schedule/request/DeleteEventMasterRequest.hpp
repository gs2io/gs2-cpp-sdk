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

#ifndef GS2_SCHEDULE_CONTROL_DELETEEVENTMASTERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_DELETEEVENTMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/schedule/Gs2ScheduleConst.hpp>
#include <gs2/schedule/model/model.hpp>
#include <memory>

namespace gs2 { namespace schedule
{

/**
 * イベントマスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** イベントの種類名 */
        optional<StringHolder> eventName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
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
    DeleteEventMasterRequest() = default;
    DeleteEventMasterRequest(const DeleteEventMasterRequest& deleteEventMasterRequest) = default;
    DeleteEventMasterRequest(DeleteEventMasterRequest&& deleteEventMasterRequest) = default;
    ~DeleteEventMasterRequest() GS2_OVERRIDE = default;

    DeleteEventMasterRequest& operator=(const DeleteEventMasterRequest& deleteEventMasterRequest) = default;
    DeleteEventMasterRequest& operator=(DeleteEventMasterRequest&& deleteEventMasterRequest) = default;

    DeleteEventMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteEventMasterRequest);
    }

    const DeleteEventMasterRequest* operator->() const
    {
        return this;
    }

    DeleteEventMasterRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DeleteEventMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * イベントの種類名を取得
     *
     * @return イベントの種類名
     */
    const optional<StringHolder>& getEventName() const
    {
        return ensureData().eventName;
    }

    /**
     * イベントの種類名を設定
     *
     * @param eventName イベントの種類名
     */
    void setEventName(StringHolder eventName)
    {
        ensureData().eventName.emplace(std::move(eventName));
    }

    /**
     * イベントの種類名を設定
     *
     * @param eventName イベントの種類名
     */
    DeleteEventMasterRequest& withEventName(StringHolder eventName)
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
    DeleteEventMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteEventMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_DELETEEVENTMASTERREQUEST_HPP_