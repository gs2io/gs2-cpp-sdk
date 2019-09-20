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

#ifndef GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_

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
 * ユーザIDを指定してトリガーを登録 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class TriggerByUserIdRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** トリガーの名前 */
        optional<StringHolder> triggerName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** トリガーの引き方の方針 */
        optional<StringHolder> triggerStrategy;
        /** トリガーの有効期限(秒) */
        optional<Int32> ttl;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            triggerName(data.triggerName),
            userId(data.userId),
            triggerStrategy(data.triggerStrategy),
            ttl(data.ttl),
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
    TriggerByUserIdRequest() = default;
    TriggerByUserIdRequest(const TriggerByUserIdRequest& triggerByUserIdRequest) = default;
    TriggerByUserIdRequest(TriggerByUserIdRequest&& triggerByUserIdRequest) = default;
    ~TriggerByUserIdRequest() GS2_OVERRIDE = default;

    TriggerByUserIdRequest& operator=(const TriggerByUserIdRequest& triggerByUserIdRequest) = default;
    TriggerByUserIdRequest& operator=(TriggerByUserIdRequest&& triggerByUserIdRequest) = default;

    TriggerByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TriggerByUserIdRequest);
    }

    const TriggerByUserIdRequest* operator->() const
    {
        return this;
    }

    TriggerByUserIdRequest* operator->()
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
    TriggerByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * トリガーの名前を取得
     *
     * @return トリガーの名前
     */
    const optional<StringHolder>& getTriggerName() const
    {
        return ensureData().triggerName;
    }

    /**
     * トリガーの名前を設定
     *
     * @param triggerName トリガーの名前
     */
    void setTriggerName(StringHolder triggerName)
    {
        ensureData().triggerName.emplace(std::move(triggerName));
    }

    /**
     * トリガーの名前を設定
     *
     * @param triggerName トリガーの名前
     */
    TriggerByUserIdRequest& withTriggerName(StringHolder triggerName)
    {
        ensureData().triggerName.emplace(std::move(triggerName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    TriggerByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * トリガーの引き方の方針を取得
     *
     * @return トリガーの引き方の方針
     */
    const optional<StringHolder>& getTriggerStrategy() const
    {
        return ensureData().triggerStrategy;
    }

    /**
     * トリガーの引き方の方針を設定
     *
     * @param triggerStrategy トリガーの引き方の方針
     */
    void setTriggerStrategy(StringHolder triggerStrategy)
    {
        ensureData().triggerStrategy.emplace(std::move(triggerStrategy));
    }

    /**
     * トリガーの引き方の方針を設定
     *
     * @param triggerStrategy トリガーの引き方の方針
     */
    TriggerByUserIdRequest& withTriggerStrategy(StringHolder triggerStrategy)
    {
        ensureData().triggerStrategy.emplace(std::move(triggerStrategy));
        return *this;
    }

    /**
     * トリガーの有効期限(秒)を取得
     *
     * @return トリガーの有効期限(秒)
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * トリガーの有効期限(秒)を設定
     *
     * @param ttl トリガーの有効期限(秒)
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * トリガーの有効期限(秒)を設定
     *
     * @param ttl トリガーの有効期限(秒)
     */
    TriggerByUserIdRequest& withTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
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
    TriggerByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    TriggerByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    TriggerByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_