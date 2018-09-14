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

#ifndef GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_
#define GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * イベントマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class EventMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベントマスターGRN */
        optional<StringHolder> eventMasterId;
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
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            eventMasterId(data.eventMasterId),
            name(data.name),
            meta(data.meta),
            type(data.type),
            absoluteBegin(data.absoluteBegin),
            absoluteEnd(data.absoluteEnd),
            relativeTriggerName(data.relativeTriggerName),
            relativeSpan(data.relativeSpan),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            eventMasterId(std::move(data.eventMasterId)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            type(std::move(data.type)),
            absoluteBegin(std::move(data.absoluteBegin)),
            absoluteEnd(std::move(data.absoluteEnd)),
            relativeTriggerName(std::move(data.relativeTriggerName)),
            relativeSpan(std::move(data.relativeSpan)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "eventMasterId") == 0) {
                if (jsonValue.IsString())
                {
                    this->eventMasterId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "absoluteBegin") == 0) {
                if (jsonValue.IsInt())
                {
                    this->absoluteBegin = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "absoluteEnd") == 0) {
                if (jsonValue.IsInt())
                {
                    this->absoluteEnd = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "relativeTriggerName") == 0) {
                if (jsonValue.IsString())
                {
                    this->relativeTriggerName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "relativeSpan") == 0) {
                if (jsonValue.IsInt())
                {
                    this->relativeSpan = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
                }
            }
        }
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
    EventMaster() :
        m_pData(nullptr)
    {}

    EventMaster(const EventMaster& eventMaster) :
        Gs2Object(eventMaster),
        m_pData(eventMaster.m_pData != nullptr ? new Data(*eventMaster.m_pData) : nullptr)
    {}

    EventMaster(EventMaster&& eventMaster) :
        Gs2Object(std::move(eventMaster)),
        m_pData(eventMaster.m_pData)
    {
        eventMaster.m_pData = nullptr;
    }

    ~EventMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    EventMaster& operator=(const EventMaster& eventMaster)
    {
        Gs2Object::operator=(eventMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*eventMaster.m_pData);

        return *this;
    }

    EventMaster& operator=(EventMaster&& eventMaster)
    {
        Gs2Object::operator=(std::move(eventMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = eventMaster.m_pData;
        eventMaster.m_pData = nullptr;

        return *this;
    }

    const EventMaster* operator->() const
    {
        return this;
    }

    EventMaster* operator->()
    {
        return this;
    }


    /**
     * イベントマスターGRNを取得
     *
     * @return イベントマスターGRN
     */
    const optional<StringHolder>& getEventMasterId() const
    {
        return ensureData().eventMasterId;
    }

    /**
     * イベントマスターGRNを設定
     *
     * @param eventMasterId イベントマスターGRN
     */
    void setEventMasterId(const Char* eventMasterId)
    {
        ensureData().eventMasterId.emplace(eventMasterId);
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
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_MODEL_EVENTMASTER_HPP_