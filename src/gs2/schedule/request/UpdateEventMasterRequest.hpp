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
 * イベントマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateEventMasterRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** イベントの種類名 */
        optional<StringHolder> eventName;
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
        /** イベントの開始トリガー名 */
        optional<StringHolder> relativeTriggerName;
        /** イベントの開催期間(秒) */
        optional<Int32> relativeDuration;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            eventName(data.eventName),
            description(data.description),
            metadata(data.metadata),
            scheduleType(data.scheduleType),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            relativeTriggerName(data.relativeTriggerName),
            relativeDuration(data.relativeDuration)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            eventName(std::move(data.eventName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            scheduleType(std::move(data.scheduleType)),
            absoluteBegin(std::move(data.absoluteBegin)),
            absoluteEnd(std::move(data.absoluteEnd)),
            relativeTriggerName(std::move(data.relativeTriggerName)),
            relativeDuration(std::move(data.relativeDuration))
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateEventMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
    }

    /**
     * イベントの種類名を設定
     *
     * @param eventName イベントの種類名
     */
    UpdateEventMasterRequest& withEventName(const Char* eventName)
    {
        ensureData().eventName.emplace(eventName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * イベントマスターの説明を設定
     *
     * @param description イベントマスターの説明
     */
    UpdateEventMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * イベントの種類のメタデータを設定
     *
     * @param metadata イベントの種類のメタデータ
     */
    UpdateEventMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setScheduleType(const Char* scheduleType)
    {
        ensureData().scheduleType.emplace(scheduleType);
    }

    /**
     * イベント期間の種類を設定
     *
     * @param scheduleType イベント期間の種類
     */
    UpdateEventMasterRequest& withScheduleType(const Char* scheduleType)
    {
        ensureData().scheduleType.emplace(scheduleType);
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
    UpdateEventMasterRequest& withAbsoluteBegin(Int64 absoluteBegin)
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
    UpdateEventMasterRequest& withAbsoluteEnd(Int64 absoluteEnd)
    {
        ensureData().absoluteEnd.emplace(absoluteEnd);
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
    void setRelativeTriggerName(const Char* relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(relativeTriggerName);
    }

    /**
     * イベントの開始トリガー名を設定
     *
     * @param relativeTriggerName イベントの開始トリガー名
     */
    UpdateEventMasterRequest& withRelativeTriggerName(const Char* relativeTriggerName)
    {
        ensureData().relativeTriggerName.emplace(relativeTriggerName);
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
    UpdateEventMasterRequest& withRelativeDuration(Int32 relativeDuration)
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