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

#ifndef GS2_SCHEDULE_MODEL_EVENT_HPP_
#define GS2_SCHEDULE_MODEL_EVENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * イベント
 *
 * @author Game Server Services, Inc.
 *
 */
class Event : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベント名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 開始日時 */
        optional<Int32> begin;
        /** 終了日時 */
        optional<Int32> end;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            meta(data.meta),
            begin(data.begin),
            end(data.end)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            begin(std::move(data.begin)),
            end(std::move(data.end))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
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
            else if (std::strcmp(name, "begin") == 0) {
                if (jsonValue.IsInt())
                {
                    this->begin = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "end") == 0) {
                if (jsonValue.IsInt())
                {
                    this->end = jsonValue.GetInt();
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
    Event() :
        m_pData(nullptr)
    {}

    Event(const Event& event) :
        Gs2Object(event),
        m_pData(event.m_pData != nullptr ? new Data(*event.m_pData) : nullptr)
    {}

    Event(Event&& event) :
        Gs2Object(std::move(event)),
        m_pData(event.m_pData)
    {
        event.m_pData = nullptr;
    }

    ~Event()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Event& operator=(const Event& event)
    {
        Gs2Object::operator=(event);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*event.m_pData);

        return *this;
    }

    Event& operator=(Event&& event)
    {
        Gs2Object::operator=(std::move(event));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = event.m_pData;
        event.m_pData = nullptr;

        return *this;
    }

    const Event* operator->() const
    {
        return this;
    }

    Event* operator->()
    {
        return this;
    }


    /**
     * イベント名を取得
     *
     * @return イベント名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * イベント名を設定
     *
     * @param name イベント名
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
     * 開始日時を取得
     *
     * @return 開始日時
     */
    const optional<Int32>& getBegin() const
    {
        return ensureData().begin;
    }

    /**
     * 開始日時を設定
     *
     * @param begin 開始日時
     */
    void setBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
    }

    /**
     * 終了日時を取得
     *
     * @return 終了日時
     */
    const optional<Int32>& getEnd() const
    {
        return ensureData().end;
    }

    /**
     * 終了日時を設定
     *
     * @param end 終了日時
     */
    void setEnd(Int32 end)
    {
        ensureData().end.emplace(end);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_MODEL_EVENT_HPP_