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

#ifndef GS2_LEVEL_MODEL_RESOURCETYPEMASTER_HPP_
#define GS2_LEVEL_MODEL_RESOURCETYPEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace level {

/**
 * リソースタイプ
 *
 * @author Game Server Services, Inc.
 *
 */
class ResourceTypeMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** リソースタイプGRN */
        optional<StringHolder> resourceTypeId;
        /** リソースタイプ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** レベルテーブル名 */
        optional<StringHolder> levelTableName;
        /** デフォルト取得済み経験値 */
        optional<Int64> defaultExperience;
        /** デフォルトレベルキャップ */
        optional<Int32> defaultLevelCap;
        /** 最大レベルキャップ */
        optional<Int32> maxLevelCap;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            resourceTypeId(data.resourceTypeId),
            name(data.name),
            meta(data.meta),
            levelTableName(data.levelTableName),
            defaultExperience(data.defaultExperience),
            defaultLevelCap(data.defaultLevelCap),
            maxLevelCap(data.maxLevelCap),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            resourceTypeId(std::move(data.resourceTypeId)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            levelTableName(std::move(data.levelTableName)),
            defaultExperience(std::move(data.defaultExperience)),
            defaultLevelCap(std::move(data.defaultLevelCap)),
            maxLevelCap(std::move(data.maxLevelCap)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "resourceTypeId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceTypeId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "levelTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->levelTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "defaultExperience") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->defaultExperience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "defaultLevelCap") == 0) {
                if (jsonValue.IsInt())
                {
                    this->defaultLevelCap = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "maxLevelCap") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxLevelCap = jsonValue.GetInt();
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
    ResourceTypeMaster() :
        m_pData(nullptr)
    {}

    ResourceTypeMaster(const ResourceTypeMaster& resourceTypeMaster) :
        Gs2Object(resourceTypeMaster),
        m_pData(resourceTypeMaster.m_pData != nullptr ? new Data(*resourceTypeMaster.m_pData) : nullptr)
    {}

    ResourceTypeMaster(ResourceTypeMaster&& resourceTypeMaster) :
        Gs2Object(std::move(resourceTypeMaster)),
        m_pData(resourceTypeMaster.m_pData)
    {
        resourceTypeMaster.m_pData = nullptr;
    }

    ~ResourceTypeMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ResourceTypeMaster& operator=(const ResourceTypeMaster& resourceTypeMaster)
    {
        Gs2Object::operator=(resourceTypeMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*resourceTypeMaster.m_pData);

        return *this;
    }

    ResourceTypeMaster& operator=(ResourceTypeMaster&& resourceTypeMaster)
    {
        Gs2Object::operator=(std::move(resourceTypeMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = resourceTypeMaster.m_pData;
        resourceTypeMaster.m_pData = nullptr;

        return *this;
    }

    const ResourceTypeMaster* operator->() const
    {
        return this;
    }

    ResourceTypeMaster* operator->()
    {
        return this;
    }


    /**
     * リソースタイプGRNを取得
     *
     * @return リソースタイプGRN
     */
    const optional<StringHolder>& getResourceTypeId() const
    {
        return ensureData().resourceTypeId;
    }

    /**
     * リソースタイプGRNを設定
     *
     * @param resourceTypeId リソースタイプGRN
     */
    void setResourceTypeId(const Char* resourceTypeId)
    {
        ensureData().resourceTypeId.emplace(resourceTypeId);
    }

    /**
     * リソースタイプ名を取得
     *
     * @return リソースタイプ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * リソースタイプ名を設定
     *
     * @param name リソースタイプ名
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
     * レベルテーブル名を取得
     *
     * @return レベルテーブル名
     */
    const optional<StringHolder>& getLevelTableName() const
    {
        return ensureData().levelTableName;
    }

    /**
     * レベルテーブル名を設定
     *
     * @param levelTableName レベルテーブル名
     */
    void setLevelTableName(const Char* levelTableName)
    {
        ensureData().levelTableName.emplace(levelTableName);
    }

    /**
     * デフォルト取得済み経験値を取得
     *
     * @return デフォルト取得済み経験値
     */
    const optional<Int64>& getDefaultExperience() const
    {
        return ensureData().defaultExperience;
    }

    /**
     * デフォルト取得済み経験値を設定
     *
     * @param defaultExperience デフォルト取得済み経験値
     */
    void setDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
    }

    /**
     * デフォルトレベルキャップを取得
     *
     * @return デフォルトレベルキャップ
     */
    const optional<Int32>& getDefaultLevelCap() const
    {
        return ensureData().defaultLevelCap;
    }

    /**
     * デフォルトレベルキャップを設定
     *
     * @param defaultLevelCap デフォルトレベルキャップ
     */
    void setDefaultLevelCap(Int32 defaultLevelCap)
    {
        ensureData().defaultLevelCap.emplace(defaultLevelCap);
    }

    /**
     * 最大レベルキャップを取得
     *
     * @return 最大レベルキャップ
     */
    const optional<Int32>& getMaxLevelCap() const
    {
        return ensureData().maxLevelCap;
    }

    /**
     * 最大レベルキャップを設定
     *
     * @param maxLevelCap 最大レベルキャップ
     */
    void setMaxLevelCap(Int32 maxLevelCap)
    {
        ensureData().maxLevelCap.emplace(maxLevelCap);
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

#endif //GS2_LEVEL_MODEL_RESOURCETYPEMASTER_HPP_