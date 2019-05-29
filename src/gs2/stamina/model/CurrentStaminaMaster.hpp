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

#ifndef GS2_STAMINA_MODEL_CURRENTSTAMINAMASTER_HPP_
#define GS2_STAMINA_MODEL_CURRENTSTAMINAMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナマスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentStaminaMaster : public Gs2Object
{
    friend bool operator!=(const CurrentStaminaMaster& lhs, const CurrentStaminaMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> groupName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            groupName(data.groupName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            groupName(std::move(data.groupName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "groupName") == 0) {
                if (jsonValue.IsString())
                {
                    this->groupName.emplace(jsonValue.GetString());
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
    CurrentStaminaMaster() :
        m_pData(nullptr)
    {}

    CurrentStaminaMaster(const CurrentStaminaMaster& currentStaminaMaster) :
        Gs2Object(currentStaminaMaster),
        m_pData(currentStaminaMaster.m_pData != nullptr ? new Data(*currentStaminaMaster.m_pData) : nullptr)
    {}

    CurrentStaminaMaster(CurrentStaminaMaster&& currentStaminaMaster) :
        Gs2Object(std::move(currentStaminaMaster)),
        m_pData(currentStaminaMaster.m_pData)
    {
        currentStaminaMaster.m_pData = nullptr;
    }

    ~CurrentStaminaMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentStaminaMaster& operator=(const CurrentStaminaMaster& currentStaminaMaster)
    {
        Gs2Object::operator=(currentStaminaMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentStaminaMaster.m_pData);

        return *this;
    }

    CurrentStaminaMaster& operator=(CurrentStaminaMaster&& currentStaminaMaster)
    {
        Gs2Object::operator=(std::move(currentStaminaMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentStaminaMaster.m_pData;
        currentStaminaMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentStaminaMaster* operator->() const
    {
        return this;
    }

    CurrentStaminaMaster* operator->()
    {
        return this;
    }
    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    CurrentStaminaMaster& withGroupName(const Char* groupName)
    {
        setGroupName(groupName);
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
    CurrentStaminaMaster& withSettings(const Char* settings)
    {
        setSettings(settings);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentStaminaMaster& lhs, const CurrentStaminaMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->groupName != lhr.m_pData->groupName)
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

bool operator==(const CurrentStaminaMaster& lhs, const CurrentStaminaMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_CURRENTSTAMINAMASTER_HPP_