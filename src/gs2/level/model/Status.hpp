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

#ifndef GS2_LEVEL_MODEL_STATUS_HPP_
#define GS2_LEVEL_MODEL_STATUS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace level {

/**
 * ステータス
 *
 * @author Game Server Services, Inc.
 *
 */
class Status : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータスGRN */
        optional<StringHolder> statusId;
        /** リソースタイプ名 */
        optional<StringHolder> resourceTypeName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** リソースID */
        optional<StringHolder> resourceId;
        /** レベル */
        optional<Int32> level;
        /** レベルキャップ */
        optional<Int32> levelCap;
        /** 累計獲得経験値 */
        optional<Int64> experience;
        /** 次のレベルに上がる累計獲得経験値 */
        optional<Int64> nextLevelExperience;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            statusId(data.statusId),
            resourceTypeName(data.resourceTypeName),
            userId(data.userId),
            resourceId(data.resourceId),
            level(data.level),
            levelCap(data.levelCap),
            experience(data.experience),
            nextLevelExperience(data.nextLevelExperience),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            statusId(std::move(data.statusId)),
            resourceTypeName(std::move(data.resourceTypeName)),
            userId(std::move(data.userId)),
            resourceId(std::move(data.resourceId)),
            level(std::move(data.level)),
            levelCap(std::move(data.levelCap)),
            experience(std::move(data.experience)),
            nextLevelExperience(std::move(data.nextLevelExperience)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "statusId") == 0) {
                if (jsonValue.IsString())
                {
                    this->statusId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceTypeName") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceTypeName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "level") == 0) {
                if (jsonValue.IsInt())
                {
                    this->level = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "levelCap") == 0) {
                if (jsonValue.IsInt())
                {
                    this->levelCap = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "experience") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->experience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "nextLevelExperience") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->nextLevelExperience = jsonValue.GetInt64();
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
    Status() :
        m_pData(nullptr)
    {}

    Status(const Status& status) :
        Gs2Object(status),
        m_pData(status.m_pData != nullptr ? new Data(*status.m_pData) : nullptr)
    {}

    Status(Status&& status) :
        Gs2Object(std::move(status)),
        m_pData(status.m_pData)
    {
        status.m_pData = nullptr;
    }

    ~Status()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Status& operator=(const Status& status)
    {
        Gs2Object::operator=(status);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*status.m_pData);

        return *this;
    }

    Status& operator=(Status&& status)
    {
        Gs2Object::operator=(std::move(status));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = status.m_pData;
        status.m_pData = nullptr;

        return *this;
    }

    const Status* operator->() const
    {
        return this;
    }

    Status* operator->()
    {
        return this;
    }


    /**
     * ステータスGRNを取得
     *
     * @return ステータスGRN
     */
    const optional<StringHolder>& getStatusId() const
    {
        return ensureData().statusId;
    }

    /**
     * ステータスGRNを設定
     *
     * @param statusId ステータスGRN
     */
    void setStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
    }

    /**
     * リソースタイプ名を取得
     *
     * @return リソースタイプ名
     */
    const optional<StringHolder>& getResourceTypeName() const
    {
        return ensureData().resourceTypeName;
    }

    /**
     * リソースタイプ名を設定
     *
     * @param resourceTypeName リソースタイプ名
     */
    void setResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * リソースIDを取得
     *
     * @return リソースID
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * レベルを取得
     *
     * @return レベル
     */
    const optional<Int32>& getLevel() const
    {
        return ensureData().level;
    }

    /**
     * レベルを設定
     *
     * @param level レベル
     */
    void setLevel(Int32 level)
    {
        ensureData().level.emplace(level);
    }

    /**
     * レベルキャップを取得
     *
     * @return レベルキャップ
     */
    const optional<Int32>& getLevelCap() const
    {
        return ensureData().levelCap;
    }

    /**
     * レベルキャップを設定
     *
     * @param levelCap レベルキャップ
     */
    void setLevelCap(Int32 levelCap)
    {
        ensureData().levelCap.emplace(levelCap);
    }

    /**
     * 累計獲得経験値を取得
     *
     * @return 累計獲得経験値
     */
    const optional<Int64>& getExperience() const
    {
        return ensureData().experience;
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param experience 累計獲得経験値
     */
    void setExperience(Int64 experience)
    {
        ensureData().experience.emplace(experience);
    }

    /**
     * 次のレベルに上がる累計獲得経験値を取得
     *
     * @return 次のレベルに上がる累計獲得経験値
     */
    const optional<Int64>& getNextLevelExperience() const
    {
        return ensureData().nextLevelExperience;
    }

    /**
     * 次のレベルに上がる累計獲得経験値を設定
     *
     * @param nextLevelExperience 次のレベルに上がる累計獲得経験値
     */
    void setNextLevelExperience(Int64 nextLevelExperience)
    {
        ensureData().nextLevelExperience.emplace(nextLevelExperience);
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

#endif //GS2_LEVEL_MODEL_STATUS_HPP_