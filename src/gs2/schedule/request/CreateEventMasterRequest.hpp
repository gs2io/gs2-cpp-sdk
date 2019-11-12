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

#ifndef GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_

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
 * イベントマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
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
        optional<StringHolder> name;
        /** イベントマスターの説明 */
        optional<StringHolder> description;
        /** イベントの種類のメタデータ */
        optional<StringHolder> metadata;
        /** イベント期間の種類 */
        optional<StringHolder> scheduleType;
        /** イベントの開始日時 */
        optional<Int64> absoluteBegin;
        /** イベントの終了日時 */
        optional<Int64> absoluteEnd;
        /** 繰り返しの種類 */
        optional<StringHolder> repeatType;
        /** イベントの繰り返し開始日 */
        optional<Int32> repeatBeginDayOfMonth;
        /** イベントの繰り返し終了日 */
        optional<Int32> repeatEndDayOfMonth;
        /** イベントの繰り返し開始曜日 */
        optional<StringHolder> repeatBeginDayOfWeek;
        /** イベントの繰り返し終了曜日 */
        optional<StringHolder> repeatEndDayOfWeek;
        /** イベントの繰り返し開始時間 */
        optional<Int32> repeatBeginHour;
        /** イベントの繰り返し終了時間 */
        optional<Int32> repeatEndHour;
        /** イベントの開始トリガー名 */
        optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        optional<Int32> relativeDuration;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            scheduleType(data.scheduleType),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            repeatType(data.repeatType),
            repeatBeginDayOfMonth(data.repeatBeginDayOfMonth),
            repeatEndDayOfMonth(data.repeatEndDayOfMonth),
            repeatBeginDayOfWeek(data.repeatBeginDayOfWeek),
            repeatEndDayOfWeek(data.repeatEndDayOfWeek),
            repeatBeginHour(data.repeatBeginHour),
            repeatEndHour(data.repeatEndHour),
            relativeTriggerName(data.relativeTriggerName),
            relativeDuration(data.relativeDuration)
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
    CreateEventMasterRequest() = default;
    CreateEventMasterRequest(const CreateEventMasterRequest& createEventMasterRequest) = default;
    CreateEventMasterRequest(CreateEventMasterRequest&& createEventMasterRequest) = default;
    ~CreateEventMasterRequest() GS2_OVERRIDE = default;

    CreateEventMasterRequest& operator=(const CreateEventMasterRequest& createEventMasterRequest) = default;
    CreateEventMasterRequest& operator=(CreateEventMasterRequest&& createEventMasterRequest) = default;

    CreateEventMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateEventMasterRequest);
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
    CreateEventMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * イベントの種類名を取得
     *
     * @return イベントの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * イベントの種類名を設定
     *
     * @param name イベントの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * イベントの種類名を設定
     *
     * @param name イベントの種類名
     */
    CreateEventMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * イベントマスターの説明を取得
     *
     * @return イベントマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * イベントマスターの説明を設定
     *
     * @param description イベントマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * イベントマスターの説明を設定
     *
     * @param description イベントマスターの説明
     */
    CreateEventMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * イベントの種類のメタデータを取得
     *
     * @return イベントの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * イベントの種類のメタデータを設定
     *
     * @param metadata イベントの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * イベントの種類のメタデータを設定
     *
     * @param metadata イベントの種類のメタデータ
     */
    CreateEventMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * イベント期間の種類を取得
     *
     * @return イベント期間の種類
     */
    const optional<StringHolder>& getScheduleType() const
    {
        return ensureData().scheduleType;
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    void setScheduleType(StringHolder scheduleType)
    {
        ensureData().scheduleType.emplace(std::move(scheduleType));
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    CreateEventMasterRequest& withScheduleType(StringHolder scheduleType)
    {
        ensureData().scheduleType.emplace(std::move(scheduleType));
        return *this;
    }

    /**
     * イベントの開始日時を取得
     *
     * @return イベントの開始日時
     */
    const optional<Int64>& getAbsoluteBegin() const
    {
        return ensureData().absoluteBegin;
    }

    /**
     * イベントの開始日時を設定
     *
     * @param absoluteBegin イベントの開始日時
     */
    void setAbsoluteBegin(Int64 absoluteBegin)
    {
        ensureData().absoluteBegin.emplace(absoluteBegin);
    }

    /**
     * イベントの開始日時を設定
     *
     * @param absoluteBegin イベントの開始日時
     */
    CreateEventMasterRequest& withAbsoluteBegin(Int64 absoluteBegin)
    {
        ensureData().absoluteBegin.emplace(absoluteBegin);
        return *this;
    }

    /**
     * イベントの終了日時を取得
     *
     * @return イベントの終了日時
     */
    const optional<Int64>& getAbsoluteEnd() const
    {
        return ensureData().absoluteEnd;
    }

    /**
     * イベントの終了日時を設定
     *
     * @param absoluteEnd イベントの終了日時
     */
    void setAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
    }

    /**
     * イベントの終了日時を設定
     *
     * @param absoluteEnd イベントの終了日時
     */
    CreateEventMasterRequest& withAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
        return *this;
    }

    /**
     * 繰り返しの種類を取得
     *
     * @return 繰り返しの種類
     */
    const optional<StringHolder>& getRepeatType() const
    {
        return ensureData().repeatType;
    }

    /**
     * 繰り返しの種類を設定
     *
     * @param repeatType 繰り返しの種類
     */
    void setRepeatType(StringHolder repeatType)
    {
        ensureData().repeatType.emplace(std::move(repeatType));
    }

    /**
     * 繰り返しの種類を設定
     *
     * @param repeatType 繰り返しの種類
     */
    CreateEventMasterRequest& withRepeatType(StringHolder repeatType)
    {
        ensureData().repeatType.emplace(std::move(repeatType));
        return *this;
    }

    /**
     * イベントの繰り返し開始日を取得
     *
     * @return イベントの繰り返し開始日
     */
    const optional<Int32>& getRepeatBeginDayOfMonth() const
    {
        return ensureData().repeatBeginDayOfMonth;
    }

    /**
     * イベントの繰り返し開始日を設定
     *
     * @param repeatBeginDayOfMonth イベントの繰り返し開始日
     */
    void setRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        ensureData().repeatBeginDayOfMonth.emplace(repeatBeginDayOfMonth);
    }

    /**
     * イベントの繰り返し開始日を設定
     *
     * @param repeatBeginDayOfMonth イベントの繰り返し開始日
     */
    CreateEventMasterRequest& withRepeatBeginDayOfMonth(Int32 repeatBeginDayOfMonth)
    {
        ensureData().repeatBeginDayOfMonth.emplace(repeatBeginDayOfMonth);
        return *this;
    }

    /**
     * イベントの繰り返し終了日を取得
     *
     * @return イベントの繰り返し終了日
     */
    const optional<Int32>& getRepeatEndDayOfMonth() const
    {
        return ensureData().repeatEndDayOfMonth;
    }

    /**
     * イベントの繰り返し終了日を設定
     *
     * @param repeatEndDayOfMonth イベントの繰り返し終了日
     */
    void setRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        ensureData().repeatEndDayOfMonth.emplace(repeatEndDayOfMonth);
    }

    /**
     * イベントの繰り返し終了日を設定
     *
     * @param repeatEndDayOfMonth イベントの繰り返し終了日
     */
    CreateEventMasterRequest& withRepeatEndDayOfMonth(Int32 repeatEndDayOfMonth)
    {
        ensureData().repeatEndDayOfMonth.emplace(repeatEndDayOfMonth);
        return *this;
    }

    /**
     * イベントの繰り返し開始曜日を取得
     *
     * @return イベントの繰り返し開始曜日
     */
    const optional<StringHolder>& getRepeatBeginDayOfWeek() const
    {
        return ensureData().repeatBeginDayOfWeek;
    }

    /**
     * イベントの繰り返し開始曜日を設定
     *
     * @param repeatBeginDayOfWeek イベントの繰り返し開始曜日
     */
    void setRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        ensureData().repeatBeginDayOfWeek.emplace(std::move(repeatBeginDayOfWeek));
    }

    /**
     * イベントの繰り返し開始曜日を設定
     *
     * @param repeatBeginDayOfWeek イベントの繰り返し開始曜日
     */
    CreateEventMasterRequest& withRepeatBeginDayOfWeek(StringHolder repeatBeginDayOfWeek)
    {
        ensureData().repeatBeginDayOfWeek.emplace(std::move(repeatBeginDayOfWeek));
        return *this;
    }

    /**
     * イベントの繰り返し終了曜日を取得
     *
     * @return イベントの繰り返し終了曜日
     */
    const optional<StringHolder>& getRepeatEndDayOfWeek() const
    {
        return ensureData().repeatEndDayOfWeek;
    }

    /**
     * イベントの繰り返し終了曜日を設定
     *
     * @param repeatEndDayOfWeek イベントの繰り返し終了曜日
     */
    void setRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        ensureData().repeatEndDayOfWeek.emplace(std::move(repeatEndDayOfWeek));
    }

    /**
     * イベントの繰り返し終了曜日を設定
     *
     * @param repeatEndDayOfWeek イベントの繰り返し終了曜日
     */
    CreateEventMasterRequest& withRepeatEndDayOfWeek(StringHolder repeatEndDayOfWeek)
    {
        ensureData().repeatEndDayOfWeek.emplace(std::move(repeatEndDayOfWeek));
        return *this;
    }

    /**
     * イベントの繰り返し開始時間を取得
     *
     * @return イベントの繰り返し開始時間
     */
    const optional<Int32>& getRepeatBeginHour() const
    {
        return ensureData().repeatBeginHour;
    }

    /**
     * イベントの繰り返し開始時間を設定
     *
     * @param repeatBeginHour イベントの繰り返し開始時間
     */
    void setRepeatBeginHour(Int32 repeatBeginHour)
    {
        ensureData().repeatBeginHour.emplace(repeatBeginHour);
    }

    /**
     * イベントの繰り返し開始時間を設定
     *
     * @param repeatBeginHour イベントの繰り返し開始時間
     */
    CreateEventMasterRequest& withRepeatBeginHour(Int32 repeatBeginHour)
    {
        ensureData().repeatBeginHour.emplace(repeatBeginHour);
        return *this;
    }

    /**
     * イベントの繰り返し終了時間を取得
     *
     * @return イベントの繰り返し終了時間
     */
    const optional<Int32>& getRepeatEndHour() const
    {
        return ensureData().repeatEndHour;
    }

    /**
     * イベントの繰り返し終了時間を設定
     *
     * @param repeatEndHour イベントの繰り返し終了時間
     */
    void setRepeatEndHour(Int32 repeatEndHour)
    {
        ensureData().repeatEndHour.emplace(repeatEndHour);
    }

    /**
     * イベントの繰り返し終了時間を設定
     *
     * @param repeatEndHour イベントの繰り返し終了時間
     */
    CreateEventMasterRequest& withRepeatEndHour(Int32 repeatEndHour)
    {
        ensureData().repeatEndHour.emplace(repeatEndHour);
        return *this;
    }

    /**
     * イベントの開始トリガー名を取得
     *
     * @return イベントの開始トリガー名
     */
    const optional<StringHolder>& getRelativeTriggerName() const
    {
        return ensureData().relativeTriggerName;
    }

    /**
     * イベントの開始トリガー名を設定
     *
     * @param relativeTriggerName イベントの開始トリガー名
     */
    void setRelativeTriggerName(StringHolder relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(std::move(relativeTriggerName));
    }

    /**
     * イベントの開始トリガー名を設定
     *
     * @param relativeTriggerName イベントの開始トリガー名
     */
    CreateEventMasterRequest& withRelativeTriggerName(StringHolder relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(std::move(relativeTriggerName));
        return *this;
    }

    /**
     * イベントの開催期間(秒)を取得
     *
     * @return イベントの開催期間(秒)
     */
    const optional<Int32>& getRelativeDuration() const
    {
        return ensureData().relativeDuration;
    }

    /**
     * イベントの開催期間(秒)を設定
     *
     * @param relativeDuration イベントの開催期間(秒)
     */
    void setRelativeDuration(Int32 relativeDuration)
    {
        ensureData().relativeDuration.emplace(relativeDuration);
    }

    /**
     * イベントの開催期間(秒)を設定
     *
     * @param relativeDuration イベントの開催期間(秒)
     */
    CreateEventMasterRequest& withRelativeDuration(Int32 relativeDuration)
    {
        ensureData().relativeDuration.emplace(relativeDuration);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateEventMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateEventMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_CREATEEVENTMASTERREQUEST_HPP_