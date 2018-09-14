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

#ifndef GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_

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
class CreateEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "CreateEventMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュールの名前を指定します。 */
        optional<StringHolder> scheduleName;
        /** イベントマスター名 */
        optional<StringHolder> name;
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
            name(data.name),
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
            name(std::move(data.name)),
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
    CreateEventMasterRequest() :
        m_pData(nullptr)
    {}

    CreateEventMasterRequest(const CreateEventMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateEventMasterRequest(CreateEventMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateEventMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateEventMasterRequest& operator=(const CreateEventMasterRequest& createEventMasterRequest)
    {
        Gs2BasicRequest::operator=(createEventMasterRequest);
        Gs2Schedule::operator=(createEventMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createEventMasterRequest.m_pData);

        return *this;
    }

    CreateEventMasterRequest& operator=(CreateEventMasterRequest&& createEventMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createEventMasterRequest));
        Gs2Schedule::operator=(std::move(createEventMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createEventMasterRequest.m_pData;
        createEventMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateEventMasterRequest* operator->() const
    {
        return this;
    }

    CreateEventMasterRequest* operator->()
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
    CreateEventMasterRequest& withScheduleName(const Char* scheduleName)
    {
        ensureData().scheduleName.emplace(scheduleName);
        return *this;
    }

    /**
     * イベントマスター名を取得
     *
     * @return イベントマスター名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * イベントマスター名を設定
     *
     * @param name イベントマスター名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * イベントマスター名を設定
     *
     * @param name イベントマスター名
     */
    CreateEventMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateEventMasterRequest& withMeta(const Char* meta)
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
    CreateEventMasterRequest& withType(const Char* type)
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
    CreateEventMasterRequest& withAbsoluteBegin(Int32 absoluteBegin)
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
    CreateEventMasterRequest& withAbsoluteEnd(Int32 absoluteEnd)
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
    CreateEventMasterRequest& withRelativeTriggerName(const Char* relativeTriggerName)
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
    CreateEventMasterRequest& withRelativeSpan(Int32 relativeSpan)
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
    CreateEventMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateEventMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateEventMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateEventMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_