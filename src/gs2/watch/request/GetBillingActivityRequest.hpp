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

#ifndef GS2_WATCH_CONTROL_GETBILLINGACTIVITYREQUEST_HPP_
#define GS2_WATCH_CONTROL_GETBILLINGACTIVITYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/watch/Gs2WatchConst.hpp>
#include <gs2/watch/model/model.hpp>
#include <memory>

namespace gs2 { namespace watch
{

/**
 * 請求にまつわるアクティビティを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetBillingActivityRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** イベントの発生年 */
        optional<Int32> year;
        /** イベントの発生月 */
        optional<Int32> month;
        /** サービスの種類 */
        optional<StringHolder> service;
        /** イベントの種類 */
        optional<StringHolder> activityType;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            year(data.year),
            month(data.month),
            service(data.service),
            activityType(data.activityType)
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
    GetBillingActivityRequest() = default;
    GetBillingActivityRequest(const GetBillingActivityRequest& getBillingActivityRequest) = default;
    GetBillingActivityRequest(GetBillingActivityRequest&& getBillingActivityRequest) = default;
    ~GetBillingActivityRequest() GS2_OVERRIDE = default;

    GetBillingActivityRequest& operator=(const GetBillingActivityRequest& getBillingActivityRequest) = default;
    GetBillingActivityRequest& operator=(GetBillingActivityRequest&& getBillingActivityRequest) = default;

    GetBillingActivityRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetBillingActivityRequest);
    }

    const GetBillingActivityRequest* operator->() const
    {
        return this;
    }

    GetBillingActivityRequest* operator->()
    {
        return this;
    }

    /**
     * イベントの発生年を取得
     *
     * @return イベントの発生年
     */
    const optional<Int32>& getYear() const
    {
        return ensureData().year;
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    void setYear(Int32 year)
    {
        ensureData().year.emplace(year);
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    GetBillingActivityRequest& withYear(Int32 year)
    {
        ensureData().year.emplace(year);
        return *this;
    }

    /**
     * イベントの発生月を取得
     *
     * @return イベントの発生月
     */
    const optional<Int32>& getMonth() const
    {
        return ensureData().month;
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    void setMonth(Int32 month)
    {
        ensureData().month.emplace(month);
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    GetBillingActivityRequest& withMonth(Int32 month)
    {
        ensureData().month.emplace(month);
        return *this;
    }

    /**
     * サービスの種類を取得
     *
     * @return サービスの種類
     */
    const optional<StringHolder>& getService() const
    {
        return ensureData().service;
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    void setService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    GetBillingActivityRequest& withService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
        return *this;
    }

    /**
     * イベントの種類を取得
     *
     * @return イベントの種類
     */
    const optional<StringHolder>& getActivityType() const
    {
        return ensureData().activityType;
    }

    /**
     * イベントの種類を設定
     *
     * @param activityType イベントの種類
     */
    void setActivityType(StringHolder activityType)
    {
        ensureData().activityType.emplace(std::move(activityType));
    }

    /**
     * イベントの種類を設定
     *
     * @param activityType イベントの種類
     */
    GetBillingActivityRequest& withActivityType(StringHolder activityType)
    {
        ensureData().activityType.emplace(std::move(activityType));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetBillingActivityRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetBillingActivityRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_WATCH_CONTROL_GETBILLINGACTIVITYREQUEST_HPP_