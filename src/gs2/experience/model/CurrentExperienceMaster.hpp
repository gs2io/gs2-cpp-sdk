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

#ifndef GS2_EXPERIENCE_MODEL_CURRENTEXPERIENCEMASTER_HPP_
#define GS2_EXPERIENCE_MODEL_CURRENTEXPERIENCEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * 経験値マスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentExperienceMaster : public Gs2Object
{
    friend bool operator!=(const CurrentExperienceMaster& lhs, const CurrentExperienceMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            experienceName(data.experienceName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            experienceName(std::move(data.experienceName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "experienceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceName.emplace(jsonValue.GetString());
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
    CurrentExperienceMaster() :
        m_pData(nullptr)
    {}

    CurrentExperienceMaster(const CurrentExperienceMaster& currentExperienceMaster) :
        Gs2Object(currentExperienceMaster),
        m_pData(currentExperienceMaster.m_pData != nullptr ? new Data(*currentExperienceMaster.m_pData) : nullptr)
    {}

    CurrentExperienceMaster(CurrentExperienceMaster&& currentExperienceMaster) :
        Gs2Object(std::move(currentExperienceMaster)),
        m_pData(currentExperienceMaster.m_pData)
    {
        currentExperienceMaster.m_pData = nullptr;
    }

    ~CurrentExperienceMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentExperienceMaster& operator=(const CurrentExperienceMaster& currentExperienceMaster)
    {
        Gs2Object::operator=(currentExperienceMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentExperienceMaster.m_pData);

        return *this;
    }

    CurrentExperienceMaster& operator=(CurrentExperienceMaster&& currentExperienceMaster)
    {
        Gs2Object::operator=(std::move(currentExperienceMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentExperienceMaster.m_pData;
        currentExperienceMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentExperienceMaster* operator->() const
    {
        return this;
    }

    CurrentExperienceMaster* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    void setExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    CurrentExperienceMaster& withExperienceName(const Char* experienceName)
    {
        setExperienceName(experienceName);
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
    CurrentExperienceMaster& withSettings(const Char* settings)
    {
        setSettings(settings);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentExperienceMaster& lhs, const CurrentExperienceMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->experienceName != lhr.m_pData->experienceName)
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

bool operator==(const CurrentExperienceMaster& lhs, const CurrentExperienceMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_CURRENTEXPERIENCEMASTER_HPP_