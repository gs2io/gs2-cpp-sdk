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

#ifndef GS2_LEVEL_MODEL_LEVELTABLEMASTER_HPP_
#define GS2_LEVEL_MODEL_LEVELTABLEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace level {

/**
 * レベルテーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class LevelTableMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レベルテーブルGRN */
        optional<StringHolder> levelTableId;
        /** レベルテーブル名 */
        optional<StringHolder> name;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            levelTableId(data.levelTableId),
            name(data.name),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            levelTableId(std::move(data.levelTableId)),
            name(std::move(data.name)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "levelTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->levelTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
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
    LevelTableMaster() :
        m_pData(nullptr)
    {}

    LevelTableMaster(const LevelTableMaster& levelTableMaster) :
        Gs2Object(levelTableMaster),
        m_pData(levelTableMaster.m_pData != nullptr ? new Data(*levelTableMaster.m_pData) : nullptr)
    {}

    LevelTableMaster(LevelTableMaster&& levelTableMaster) :
        Gs2Object(std::move(levelTableMaster)),
        m_pData(levelTableMaster.m_pData)
    {
        levelTableMaster.m_pData = nullptr;
    }

    ~LevelTableMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LevelTableMaster& operator=(const LevelTableMaster& levelTableMaster)
    {
        Gs2Object::operator=(levelTableMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*levelTableMaster.m_pData);

        return *this;
    }

    LevelTableMaster& operator=(LevelTableMaster&& levelTableMaster)
    {
        Gs2Object::operator=(std::move(levelTableMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = levelTableMaster.m_pData;
        levelTableMaster.m_pData = nullptr;

        return *this;
    }

    const LevelTableMaster* operator->() const
    {
        return this;
    }

    LevelTableMaster* operator->()
    {
        return this;
    }


    /**
     * レベルテーブルGRNを取得
     *
     * @return レベルテーブルGRN
     */
    const optional<StringHolder>& getLevelTableId() const
    {
        return ensureData().levelTableId;
    }

    /**
     * レベルテーブルGRNを設定
     *
     * @param levelTableId レベルテーブルGRN
     */
    void setLevelTableId(const Char* levelTableId)
    {
        ensureData().levelTableId.emplace(levelTableId);
    }

    /**
     * レベルテーブル名を取得
     *
     * @return レベルテーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * レベルテーブル名を設定
     *
     * @param name レベルテーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
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

#endif //GS2_LEVEL_MODEL_LEVELTABLEMASTER_HPP_