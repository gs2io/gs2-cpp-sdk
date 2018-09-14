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

#ifndef GS2_LEVEL_MODEL_LEVELTHRESHOLDMASTER_HPP_
#define GS2_LEVEL_MODEL_LEVELTHRESHOLDMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace level {

/**
 * レベルアップ経験値閾値
 *
 * @author Game Server Services, Inc.
 *
 */
class LevelThresholdMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レベルアップ経験値閾値GRN */
        optional<StringHolder> thresholdId;
        /** レベルアップ経験値閾値 */
        optional<Int64> threshold;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            thresholdId(data.thresholdId),
            threshold(data.threshold),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            thresholdId(std::move(data.thresholdId)),
            threshold(std::move(data.threshold)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "thresholdId") == 0) {
                if (jsonValue.IsString())
                {
                    this->thresholdId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "threshold") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->threshold = jsonValue.GetInt64();
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
    LevelThresholdMaster() :
        m_pData(nullptr)
    {}

    LevelThresholdMaster(const LevelThresholdMaster& levelThresholdMaster) :
        Gs2Object(levelThresholdMaster),
        m_pData(levelThresholdMaster.m_pData != nullptr ? new Data(*levelThresholdMaster.m_pData) : nullptr)
    {}

    LevelThresholdMaster(LevelThresholdMaster&& levelThresholdMaster) :
        Gs2Object(std::move(levelThresholdMaster)),
        m_pData(levelThresholdMaster.m_pData)
    {
        levelThresholdMaster.m_pData = nullptr;
    }

    ~LevelThresholdMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LevelThresholdMaster& operator=(const LevelThresholdMaster& levelThresholdMaster)
    {
        Gs2Object::operator=(levelThresholdMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*levelThresholdMaster.m_pData);

        return *this;
    }

    LevelThresholdMaster& operator=(LevelThresholdMaster&& levelThresholdMaster)
    {
        Gs2Object::operator=(std::move(levelThresholdMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = levelThresholdMaster.m_pData;
        levelThresholdMaster.m_pData = nullptr;

        return *this;
    }

    const LevelThresholdMaster* operator->() const
    {
        return this;
    }

    LevelThresholdMaster* operator->()
    {
        return this;
    }


    /**
     * レベルアップ経験値閾値GRNを取得
     *
     * @return レベルアップ経験値閾値GRN
     */
    const optional<StringHolder>& getThresholdId() const
    {
        return ensureData().thresholdId;
    }

    /**
     * レベルアップ経験値閾値GRNを設定
     *
     * @param thresholdId レベルアップ経験値閾値GRN
     */
    void setThresholdId(const Char* thresholdId)
    {
        ensureData().thresholdId.emplace(thresholdId);
    }

    /**
     * レベルアップ経験値閾値を取得
     *
     * @return レベルアップ経験値閾値
     */
    const optional<Int64>& getThreshold() const
    {
        return ensureData().threshold;
    }

    /**
     * レベルアップ経験値閾値を設定
     *
     * @param threshold レベルアップ経験値閾値
     */
    void setThreshold(Int64 threshold)
    {
        ensureData().threshold.emplace(threshold);
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

#endif //GS2_LEVEL_MODEL_LEVELTHRESHOLDMASTER_HPP_