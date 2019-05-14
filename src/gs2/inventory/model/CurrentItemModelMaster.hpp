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

#ifndef GS2_INVENTORY_MODEL_CURRENTITEMMODELMASTER_HPP_
#define GS2_INVENTORY_MODEL_CURRENTITEMMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * カテゴリマスターJSON
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentItemModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** マスターデータ */
        optional<StringHolder> settings;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            categoryName(data.categoryName),
            settings(data.settings)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            categoryName(std::move(data.categoryName)),
            settings(std::move(data.settings))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "categoryName") == 0) {
                if (jsonValue.IsString())
                {
                    this->categoryName.emplace(jsonValue.GetString());
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
    CurrentItemModelMaster() :
        m_pData(nullptr)
    {}

    CurrentItemModelMaster(const CurrentItemModelMaster& currentItemModelMaster) :
        Gs2Object(currentItemModelMaster),
        m_pData(currentItemModelMaster.m_pData != nullptr ? new Data(*currentItemModelMaster.m_pData) : nullptr)
    {}

    CurrentItemModelMaster(CurrentItemModelMaster&& currentItemModelMaster) :
        Gs2Object(std::move(currentItemModelMaster)),
        m_pData(currentItemModelMaster.m_pData)
    {
        currentItemModelMaster.m_pData = nullptr;
    }

    ~CurrentItemModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CurrentItemModelMaster& operator=(const CurrentItemModelMaster& currentItemModelMaster)
    {
        Gs2Object::operator=(currentItemModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*currentItemModelMaster.m_pData);

        return *this;
    }

    CurrentItemModelMaster& operator=(CurrentItemModelMaster&& currentItemModelMaster)
    {
        Gs2Object::operator=(std::move(currentItemModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = currentItemModelMaster.m_pData;
        currentItemModelMaster.m_pData = nullptr;

        return *this;
    }

    const CurrentItemModelMaster* operator->() const
    {
        return this;
    }

    CurrentItemModelMaster* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(const Char* categoryName)
    {
        ensureData().categoryName.emplace(categoryName);
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

#endif //GS2_INVENTORY_MODEL_CURRENTITEMMODELMASTER_HPP_