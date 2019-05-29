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

#ifndef GS2_DISTRIBUTOR_MODEL_CURRENTDISTRIBUTORMASTER_HPP_
#define GS2_DISTRIBUTOR_MODEL_CURRENTDISTRIBUTORMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace distributor {

/**
 * ディストリビューターマスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentDistributorMaster : public Gs2Object
{
    friend bool operator!=(const CurrentDistributorMaster& lhs, const CurrentDistributorMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorName(data.distributorName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributorName(std::move(data.distributorName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "distributorName") == 0) {
                if (jsonValue.IsString())
                {
                    this->distributorName.emplace(jsonValue.GetString());
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
    CurrentDistributorMaster() :
        m_pData(nullptr)
    {}

    CurrentDistributorMaster(const CurrentDistributorMaster& currentDistributorMaster) :
        Gs2Object(currentDistributorMaster),
        m_pData(currentDistributorMaster.m_pData != nullptr ? new Data(*currentDistributorMaster.m_pData) : nullptr)
    {}

    CurrentDistributorMaster(CurrentDistributorMaster&& currentDistributorMaster) :
        Gs2Object(std::move(currentDistributorMaster)),
        m_pData(currentDistributorMaster.m_pData)
    {
        currentDistributorMaster.m_pData = nullptr;
    }

    ~CurrentDistributorMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentDistributorMaster& operator=(const CurrentDistributorMaster& currentDistributorMaster)
    {
        Gs2Object::operator=(currentDistributorMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentDistributorMaster.m_pData);

        return *this;
    }

    CurrentDistributorMaster& operator=(CurrentDistributorMaster&& currentDistributorMaster)
    {
        Gs2Object::operator=(std::move(currentDistributorMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentDistributorMaster.m_pData;
        currentDistributorMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentDistributorMaster* operator->() const
    {
        return this;
    }

    CurrentDistributorMaster* operator->()
    {
        return this;
    }
    /**
     * ディストリビュータ名を取得
     *
     * @return ディストリビュータ名
     */
    const optional<StringHolder>& getDistributorName() const
    {
        return ensureData().distributorName;
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    void setDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    CurrentDistributorMaster& withDistributorName(const Char* distributorName)
    {
        setDistributorName(distributorName);
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
    CurrentDistributorMaster& withSettings(const Char* settings)
    {
        setSettings(settings);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentDistributorMaster& lhs, const CurrentDistributorMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->distributorName != lhr.m_pData->distributorName)
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

bool operator==(const CurrentDistributorMaster& lhs, const CurrentDistributorMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_CURRENTDISTRIBUTORMASTER_HPP_