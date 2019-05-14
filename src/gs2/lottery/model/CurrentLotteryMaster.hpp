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

#ifndef GS2_LOTTERY_MODEL_CURRENTLOTTERYMASTER_HPP_
#define GS2_LOTTERY_MODEL_CURRENTLOTTERYMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * 抽選マスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentLotteryMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** グループ名 */
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
    CurrentLotteryMaster() :
        m_pData(nullptr)
    {}

    CurrentLotteryMaster(const CurrentLotteryMaster& currentLotteryMaster) :
        Gs2Object(currentLotteryMaster),
        m_pData(currentLotteryMaster.m_pData != nullptr ? new Data(*currentLotteryMaster.m_pData) : nullptr)
    {}

    CurrentLotteryMaster(CurrentLotteryMaster&& currentLotteryMaster) :
        Gs2Object(std::move(currentLotteryMaster)),
        m_pData(currentLotteryMaster.m_pData)
    {
        currentLotteryMaster.m_pData = nullptr;
    }

    ~CurrentLotteryMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentLotteryMaster& operator=(const CurrentLotteryMaster& currentLotteryMaster)
    {
        Gs2Object::operator=(currentLotteryMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentLotteryMaster.m_pData);

        return *this;
    }

    CurrentLotteryMaster& operator=(CurrentLotteryMaster&& currentLotteryMaster)
    {
        Gs2Object::operator=(std::move(currentLotteryMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentLotteryMaster.m_pData;
        currentLotteryMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentLotteryMaster* operator->() const
    {
        return this;
    }

    CurrentLotteryMaster* operator->()
    {
        return this;
    }
    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * グループ名を設定
     *
     * @param groupName グループ名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_MODEL_CURRENTLOTTERYMASTER_HPP_