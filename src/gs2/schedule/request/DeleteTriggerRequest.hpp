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

#ifndef GS2_SCHEDULE_CONTROL_DELETETRIGGERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_DELETETRIGGERREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"

namespace gs2 { namespace schedule
{

/**
 * トリガーを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteTriggerRequest : public Gs2UserRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュール名 */
        optional<StringHolder> scheduleName;
        /** トリガーの名前 */
        optional<StringHolder> triggerName;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scheduleName(data.scheduleName),
            triggerName(data.triggerName),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            triggerName(std::move(data.triggerName)),
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
    DeleteTriggerRequest() :
        m_pData(nullptr)
    {}

    DeleteTriggerRequest(const DeleteTriggerRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteTriggerRequest(DeleteTriggerRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteTriggerRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTriggerRequest& operator=(const DeleteTriggerRequest& deleteTriggerRequest)
    {
        Gs2UserRequest::operator=(deleteTriggerRequest);
        Gs2Schedule::operator=(deleteTriggerRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTriggerRequest.m_pData);

        return *this;
    }

    DeleteTriggerRequest& operator=(DeleteTriggerRequest&& deleteTriggerRequest)
    {
        Gs2UserRequest::operator=(std::move(deleteTriggerRequest));
        Gs2Schedule::operator=(std::move(deleteTriggerRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTriggerRequest.m_pData;
        deleteTriggerRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteTriggerRequest* operator->() const
    {
        return this;
    }

    DeleteTriggerRequest* operator->()
    {
        return this;
    }
    /**
     * スケジュール名を取得
     *
     * @return スケジュール名
     */
    const optional<StringHolder>& getScheduleName() const
    {
        return ensureData().scheduleName;
    }

    /**
     * スケジュール名を設定
     *
     * @param scheduleName スケジュール名
     */
    void setScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
    }

    /**
     * スケジュール名を設定
     *
     * @param scheduleName スケジュール名
     */
    DeleteTriggerRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
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
    void setTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
    }

    /**
     * トリガーの名前を設定
     *
     * @param triggerName トリガーの名前
     */
    DeleteTriggerRequest& withTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
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
    DeleteTriggerRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    DeleteTriggerRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteTriggerRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteTriggerRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteTriggerRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    DeleteTriggerRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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

#endif //GS2_SCHEDULE_CONTROL_DELETETRIGGERREQUEST_HPP_