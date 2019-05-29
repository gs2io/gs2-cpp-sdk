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

#ifndef GS2_SCHEDULE_MODEL_CURRENTEVENTMASTER_HPP_
#define GS2_SCHEDULE_MODEL_CURRENTEVENTMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * イベントマスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentEventMaster : public Gs2Object
{
    friend bool operator!=(const CurrentEventMaster& lhs, const CurrentEventMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スケジュール名 */
        optional<StringHolder> scheduleName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            scheduleName(data.scheduleName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            scheduleName(std::move(data.scheduleName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "scheduleName") == 0) {
                if (jsonValue.IsString())
                {
                    this->scheduleName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "settings") == 0) {
                if (jsonValue.IsString())
                {
                    this->settings.emplace(jsonValue.GetString());
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
    CurrentEventMaster() :
        m_pData(nullptr)
    {}

    CurrentEventMaster(const CurrentEventMaster& currentEventMaster) :
        Gs2Object(currentEventMaster),
        m_pData(currentEventMaster.m_pData != nullptr ? new Data(*currentEventMaster.m_pData) : nullptr)
    {}

    CurrentEventMaster(CurrentEventMaster&& currentEventMaster) :
        Gs2Object(std::move(currentEventMaster)),
        m_pData(currentEventMaster.m_pData)
    {
        currentEventMaster.m_pData = nullptr;
    }

    ~CurrentEventMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentEventMaster& operator=(const CurrentEventMaster& currentEventMaster)
    {
        Gs2Object::operator=(currentEventMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentEventMaster.m_pData);

        return *this;
    }

    CurrentEventMaster& operator=(CurrentEventMaster&& currentEventMaster)
    {
        Gs2Object::operator=(std::move(currentEventMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentEventMaster.m_pData;
        currentEventMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentEventMaster* operator->() const
    {
        return this;
    }

    CurrentEventMaster* operator->()
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
    CurrentEventMaster& withScheduleName(const Char* scheduleName)
    {
        setScheduleName(scheduleName);
        return *this;
    }

    /**
     * マスターデータを取得
     *
     * @return マスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    void setSettings(const Char* settings)
    {
        ensureData().settings.emplace(settings);
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    CurrentEventMaster& withSettings(const Char* settings)
    {
        setSettings(settings);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentEventMaster& lhs, const CurrentEventMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->scheduleName != lhr.m_pData->scheduleName)
        {
            return true;
        }
        if (lhs.m_pData->settings != lhr.m_pData->settings)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const CurrentEventMaster& lhs, const CurrentEventMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SCHEDULE_MODEL_CURRENTEVENTMASTER_HPP_