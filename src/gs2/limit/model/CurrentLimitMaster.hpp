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

#ifndef GS2_LIMIT_MODEL_CURRENTLIMITMASTER_HPP_
#define GS2_LIMIT_MODEL_CURRENTLIMITMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace limit {

/**
 * 現在有効な回数制限設定
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentLimitMaster : public Gs2Object
{
    friend bool operator!=(const CurrentLimitMaster& lhs, const CurrentLimitMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "namespaceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
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
    CurrentLimitMaster() :
        m_pData(nullptr)
    {}

    CurrentLimitMaster(const CurrentLimitMaster& currentLimitMaster) :
        Gs2Object(currentLimitMaster),
        m_pData(currentLimitMaster.m_pData != nullptr ? new Data(*currentLimitMaster.m_pData) : nullptr)
    {}

    CurrentLimitMaster(CurrentLimitMaster&& currentLimitMaster) :
        Gs2Object(std::move(currentLimitMaster)),
        m_pData(currentLimitMaster.m_pData)
    {
        currentLimitMaster.m_pData = nullptr;
    }

    ~CurrentLimitMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentLimitMaster& operator=(const CurrentLimitMaster& currentLimitMaster)
    {
        Gs2Object::operator=(currentLimitMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentLimitMaster.m_pData);

        return *this;
    }

    CurrentLimitMaster& operator=(CurrentLimitMaster&& currentLimitMaster)
    {
        Gs2Object::operator=(std::move(currentLimitMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentLimitMaster.m_pData;
        currentLimitMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentLimitMaster* operator->() const
    {
        return this;
    }

    CurrentLimitMaster* operator->()
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
    CurrentLimitMaster& withNamespaceName(const Char* namespaceName)
    {
        setNamespaceName(namespaceName);
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
    CurrentLimitMaster& withSettings(const Char* settings)
    {
        setSettings(settings);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CurrentLimitMaster& lhs, const CurrentLimitMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
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

inline bool operator==(const CurrentLimitMaster& lhs, const CurrentLimitMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LIMIT_MODEL_CURRENTLIMITMASTER_HPP_