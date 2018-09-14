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

#ifndef GS2_SCHEDULE_CONTROL_UPDATEEVENTMASTERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_UPDATEEVENTMASTERREQUEST_HPP_

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
class UpdateEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "UpdateEventMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュールの名前を指定します。 */
        optional<StringHolder> scheduleName;
        /** イベント名を指定します。 */
        optional<StringHolder> eventName;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 期間 */
        optional<StringHolder> type;
        /** 絶対時間を選択した場合の開始日時 */
        optional<Int32> absoluteBegin;
        /** 絶対時間を選択した場合の終了日時 */
        optional<Int32> absoluteEnd;
        /** 相対時間を選択した場合の開始トリガー名 */
        optional<StringHolder> relativeTriggerName;
        /** 相対時間を選択した場合のトリガーを引いてからのイベント期間(分) */
        optional<Int32> relativeSpan;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scheduleName(data.scheduleName),
            eventName(data.eventName),
            meta(data.meta),
            type(data.type),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            relativeTriggerName(data.relativeTriggerName),
            relativeSpan(data.relativeSpan)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            eventName(std::move(data.eventName)),
            meta(std::move(data.meta)),
            type(std::move(data.type)),
            absoluteBegin(std::move(data.absoluteBegin)),
            absoluteEnd(std::move(data.absoluteEnd)),
            relativeTriggerName(std::move(data.relativeTriggerName)),
            relativeSpan(std::move(data.relativeSpan))
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
    UpdateEventMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateEventMasterRequest(const UpdateEventMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateEventMasterRequest(UpdateEventMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateEventMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateEventMasterRequest& operator=(const UpdateEventMasterRequest& updateEventMasterRequest)
    {
        Gs2BasicRequest::operator=(updateEventMasterRequest);
        Gs2Schedule::operator=(updateEventMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateEventMasterRequest.m_pData);

        return *this;
    }

    UpdateEventMasterRequest& operator=(UpdateEventMasterRequest&& updateEventMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateEventMasterRequest));
        Gs2Schedule::operator=(std::move(updateEventMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateEventMasterRequest.m_pData;
        updateEventMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateEventMasterRequest* operator->() const
    {
        return this;
    }

    UpdateEventMasterRequest* operator->()
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
    UpdateEventMasterRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
        return *this;
    }

    /**
     * イベント名を指定します。を取得
     *
     * @return イベント名を指定します。
     */
    const optional<StringHolder>& getEventName() const
    {
        return ensureData().eventName;
    }

    /**
     * イベント名を指定します。を設定
     *
     * @param eventName イベント名を指定します。
     */
    void setEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
    }

    /**
     * イベント名を指定します。を設定
     *
     * @param eventName イベント名を指定します。
     */
    UpdateEventMasterRequest& withEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    UpdateEventMasterRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }

    /**
     * 期間を取得
     *
     * @return 期間
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 期間を設定
     *
     * @param type 期間
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 期間を設定
     *
     * @param type 期間
     */
    UpdateEventMasterRequest& withType(const Char* type)
    {
        ensureData().type.emplace(type);
        return *this;
    }

    /**
     * 絶対時間を選択した場合の開始日時を取得
     *
     * @return 絶対時間を選択した場合の開始日時
     */
    const optional<Int32>& getAbsoluteBegin() const
    {
        return ensureData().absoluteBegin;
    }

    /**
     * 絶対時間を選択した場合の開始日時を設定
     *
     * @param absoluteBegin 絶対時間を選択した場合の開始日時
     */
    void setAbsoluteBegin(Int32 absoluteBegin)
    {
        ensureData().absoluteBegin.emplace(absoluteBegin);
    }

    /**
     * 絶対時間を選択した場合の開始日時を設定
     *
     * @param absoluteBegin 絶対時間を選択した場合の開始日時
     */
    UpdateEventMasterRequest& withAbsoluteBegin(Int32 absoluteBegin)
    {
        ensureData().absoluteBegin.emplace(absoluteBegin);
        return *this;
    }

    /**
     * 絶対時間を選択した場合の終了日時を取得
     *
     * @return 絶対時間を選択した場合の終了日時
     */
    const optional<Int32>& getAbsoluteEnd() const
    {
        return ensureData().absoluteEnd;
    }

    /**
     * 絶対時間を選択した場合の終了日時を設定
     *
     * @param absoluteEnd 絶対時間を選択した場合の終了日時
     */
    void setAbsoluteEnd(Int32 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
    }

    /**
     * 絶対時間を選択した場合の終了日時を設定
     *
     * @param absoluteEnd 絶対時間を選択した場合の終了日時
     */
    UpdateEventMasterRequest& withAbsoluteEnd(Int32 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
        return *this;
    }

    /**
     * 相対時間を選択した場合の開始トリガー名を取得
     *
     * @return 相対時間を選択した場合の開始トリガー名
     */
    const optional<StringHolder>& getRelativeTriggerName() const
    {
        return ensureData().relativeTriggerName;
    }

    /**
     * 相対時間を選択した場合の開始トリガー名を設定
     *
     * @param relativeTriggerName 相対時間を選択した場合の開始トリガー名
     */
    void setRelativeTriggerName(const Char* relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(relativeTriggerName);
    }

    /**
     * 相対時間を選択した場合の開始トリガー名を設定
     *
     * @param relativeTriggerName 相対時間を選択した場合の開始トリガー名
     */
    UpdateEventMasterRequest& withRelativeTriggerName(const Char* relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(relativeTriggerName);
        return *this;
    }

    /**
     * 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)を取得
     *
     * @return 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)
     */
    const optional<Int32>& getRelativeSpan() const
    {
        return ensureData().relativeSpan;
    }

    /**
     * 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)を設定
     *
     * @param relativeSpan 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)
     */
    void setRelativeSpan(Int32 relativeSpan)
    {
        ensureData().relativeSpan.emplace(relativeSpan);
    }

    /**
     * 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)を設定
     *
     * @param relativeSpan 相対時間を選択した場合のトリガーを引いてからのイベント期間(分)
     */
    UpdateEventMasterRequest& withRelativeSpan(Int32 relativeSpan)
    {
        ensureData().relativeSpan.emplace(relativeSpan);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateEventMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateEventMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateEventMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateEventMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCHEDULE_CONTROL_UPDATEEVENTMASTERREQUEST_HPP_