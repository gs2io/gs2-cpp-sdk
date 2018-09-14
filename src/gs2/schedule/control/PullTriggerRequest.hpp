/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SCHEDULE_CONTROL_PULLTRIGGERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_PULLTRIGGERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * @author Game Server Services, Inc.
 */
class PullTriggerRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "PullTrigger";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュールの名前を指定します。 */
        optional<StringHolder> scheduleName;
        /** ユーザIDを指定します。 */
        optional<StringHolder> userId;
        /** トリガーの名前を指定します。 */
        optional<StringHolder> triggerName;
        /** 既にトリガーが引かれていた時の振る舞い */
        optional<StringHolder> action;
        /** action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分) */
        optional<Int32> ttl;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scheduleName(data.scheduleName),
            userId(data.userId),
            triggerName(data.triggerName),
            action(data.action),
            ttl(data.ttl)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            userId(std::move(data.userId)),
            triggerName(std::move(data.triggerName)),
            action(std::move(data.action)),
            ttl(std::move(data.ttl))
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
    PullTriggerRequest() :
        m_pData(nullptr)
    {}

    PullTriggerRequest(const PullTriggerRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    PullTriggerRequest(PullTriggerRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~PullTriggerRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PullTriggerRequest& operator=(const PullTriggerRequest& pullTriggerRequest)
    {
        Gs2BasicRequest::operator=(pullTriggerRequest);
        Gs2Schedule::operator=(pullTriggerRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*pullTriggerRequest.m_pData);

        return *this;
    }

    PullTriggerRequest& operator=(PullTriggerRequest&& pullTriggerRequest)
    {
        Gs2BasicRequest::operator=(std::move(pullTriggerRequest));
        Gs2Schedule::operator=(std::move(pullTriggerRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = pullTriggerRequest.m_pData;
        pullTriggerRequest.m_pData = nullptr;

        return *this;
    }

    const PullTriggerRequest* operator->() const
    {
        return this;
    }

    PullTriggerRequest* operator->()
    {
        return this;
    }

    /**
     * スケジュールの名前を指定します。を取得
     *
     * @return スケジュールの名前を指定します。
     */
    const optional<StringHolder>& getScheduleName() const
    {
        return ensureData().scheduleName;
    }

    /**
     * スケジュールの名前を指定します。を設定
     *
     * @param scheduleName スケジュールの名前を指定します。
     */
    void setScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
    }

    /**
     * スケジュールの名前を指定します。を設定
     *
     * @param scheduleName スケジュールの名前を指定します。
     */
    PullTriggerRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
        return *this;
    }

    /**
     * ユーザIDを指定します。を取得
     *
     * @return ユーザIDを指定します。
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを指定します。を設定
     *
     * @param userId ユーザIDを指定します。
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを指定します。を設定
     *
     * @param userId ユーザIDを指定します。
     */
    PullTriggerRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * トリガーの名前を指定します。を取得
     *
     * @return トリガーの名前を指定します。
     */
    const optional<StringHolder>& getTriggerName() const
    {
        return ensureData().triggerName;
    }

    /**
     * トリガーの名前を指定します。を設定
     *
     * @param triggerName トリガーの名前を指定します。
     */
    void setTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
    }

    /**
     * トリガーの名前を指定します。を設定
     *
     * @param triggerName トリガーの名前を指定します。
     */
    PullTriggerRequest& withTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
        return *this;
    }

    /**
     * 既にトリガーが引かれていた時の振る舞いを取得
     *
     * @return 既にトリガーが引かれていた時の振る舞い
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * 既にトリガーが引かれていた時の振る舞いを設定
     *
     * @param action 既にトリガーが引かれていた時の振る舞い
     */
    void setAction(const Char* action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * 既にトリガーが引かれていた時の振る舞いを設定
     *
     * @param action 既にトリガーが引かれていた時の振る舞い
     */
    PullTriggerRequest& withAction(const Char* action)
    {
        ensureData().action.emplace(action);
        return *this;
    }

    /**
     * action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)を取得
     *
     * @return action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)を設定
     *
     * @param ttl action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)を設定
     *
     * @param ttl action に if_expired_pull_again を指定したときに使用するトリガーの有効期間(分)
     */
    PullTriggerRequest& withTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    PullTriggerRequest& withGs2ClientId(const Char* gs2ClientId)
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
    PullTriggerRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    PullTriggerRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PullTriggerRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCHEDULE_CONTROL_PULLTRIGGERREQUEST_HPP_