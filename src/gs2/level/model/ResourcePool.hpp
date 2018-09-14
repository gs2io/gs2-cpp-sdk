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

#ifndef GS2_LEVEL_MODEL_RESOURCEPOOL_HPP_
#define GS2_LEVEL_MODEL_RESOURCEPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace level {

/**
 * リソースプール
 *
 * @author Game Server Services, Inc.
 *
 */
class ResourcePool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** リソースプールGRN */
        optional<StringHolder> resourcePoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** リソースプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** レベルキャップ取得時 に実行されるGS2-Script */
        optional<StringHolder> levelCapScript;
        /** 経験値変化時 に実行されるGS2-Script */
        optional<StringHolder> changeExperienceTriggerScript;
        /** 経験値変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeExperienceDoneTriggerScript;
        /** レベル変化時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelTriggerScript;
        /** レベル変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelDoneTriggerScript;
        /** レベルキャップ変化時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelCapTriggerScript;
        /** レベルキャップ変化完了時 に実行されるGS2-Script */
        optional<StringHolder> changeLevelCapDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            resourcePoolId(data.resourcePoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            levelCapScript(data.levelCapScript),
            changeExperienceTriggerScript(data.changeExperienceTriggerScript),
            changeExperienceDoneTriggerScript(data.changeExperienceDoneTriggerScript),
            changeLevelTriggerScript(data.changeLevelTriggerScript),
            changeLevelDoneTriggerScript(data.changeLevelDoneTriggerScript),
            changeLevelCapTriggerScript(data.changeLevelCapTriggerScript),
            changeLevelCapDoneTriggerScript(data.changeLevelCapDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            resourcePoolId(std::move(data.resourcePoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            levelCapScript(std::move(data.levelCapScript)),
            changeExperienceTriggerScript(std::move(data.changeExperienceTriggerScript)),
            changeExperienceDoneTriggerScript(std::move(data.changeExperienceDoneTriggerScript)),
            changeLevelTriggerScript(std::move(data.changeLevelTriggerScript)),
            changeLevelDoneTriggerScript(std::move(data.changeLevelDoneTriggerScript)),
            changeLevelCapTriggerScript(std::move(data.changeLevelCapTriggerScript)),
            changeLevelCapDoneTriggerScript(std::move(data.changeLevelCapDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "resourcePoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourcePoolId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "serviceClass") == 0) {
                if (jsonValue.IsString())
                {
                    this->serviceClass.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "levelCapScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->levelCapScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeExperienceTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeExperienceDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeLevelTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeLevelTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeLevelDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeLevelDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeLevelCapTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeLevelCapTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeLevelCapDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeLevelCapDoneTriggerScript.emplace(jsonValue.GetString());
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
    ResourcePool() :
        m_pData(nullptr)
    {}

    ResourcePool(const ResourcePool& resourcePool) :
        Gs2Object(resourcePool),
        m_pData(resourcePool.m_pData != nullptr ? new Data(*resourcePool.m_pData) : nullptr)
    {}

    ResourcePool(ResourcePool&& resourcePool) :
        Gs2Object(std::move(resourcePool)),
        m_pData(resourcePool.m_pData)
    {
        resourcePool.m_pData = nullptr;
    }

    ~ResourcePool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ResourcePool& operator=(const ResourcePool& resourcePool)
    {
        Gs2Object::operator=(resourcePool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*resourcePool.m_pData);

        return *this;
    }

    ResourcePool& operator=(ResourcePool&& resourcePool)
    {
        Gs2Object::operator=(std::move(resourcePool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = resourcePool.m_pData;
        resourcePool.m_pData = nullptr;

        return *this;
    }

    const ResourcePool* operator->() const
    {
        return this;
    }

    ResourcePool* operator->()
    {
        return this;
    }


    /**
     * リソースプールGRNを取得
     *
     * @return リソースプールGRN
     */
    const optional<StringHolder>& getResourcePoolId() const
    {
        return ensureData().resourcePoolId;
    }

    /**
     * リソースプールGRNを設定
     *
     * @param resourcePoolId リソースプールGRN
     */
    void setResourcePoolId(const Char* resourcePoolId)
    {
        ensureData().resourcePoolId.emplace(resourcePoolId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * リソースプール名を取得
     *
     * @return リソースプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * リソースプール名を設定
     *
     * @param name リソースプール名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * レベルキャップ取得時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ取得時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getLevelCapScript() const
    {
        return ensureData().levelCapScript;
    }

    /**
     * レベルキャップ取得時 に実行されるGS2-Scriptを設定
     *
     * @param levelCapScript レベルキャップ取得時 に実行されるGS2-Script
     */
    void setLevelCapScript(const Char* levelCapScript)
    {
        ensureData().levelCapScript.emplace(levelCapScript);
    }

    /**
     * 経験値変化時 に実行されるGS2-Scriptを取得
     *
     * @return 経験値変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeExperienceTriggerScript() const
    {
        return ensureData().changeExperienceTriggerScript;
    }

    /**
     * 経験値変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceTriggerScript 経験値変化時 に実行されるGS2-Script
     */
    void setChangeExperienceTriggerScript(const Char* changeExperienceTriggerScript)
    {
        ensureData().changeExperienceTriggerScript.emplace(changeExperienceTriggerScript);
    }

    /**
     * 経験値変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return 経験値変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeExperienceDoneTriggerScript() const
    {
        return ensureData().changeExperienceDoneTriggerScript;
    }

    /**
     * 経験値変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeExperienceDoneTriggerScript 経験値変化完了時 に実行されるGS2-Script
     */
    void setChangeExperienceDoneTriggerScript(const Char* changeExperienceDoneTriggerScript)
    {
        ensureData().changeExperienceDoneTriggerScript.emplace(changeExperienceDoneTriggerScript);
    }

    /**
     * レベル変化時 に実行されるGS2-Scriptを取得
     *
     * @return レベル変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelTriggerScript() const
    {
        return ensureData().changeLevelTriggerScript;
    }

    /**
     * レベル変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelTriggerScript レベル変化時 に実行されるGS2-Script
     */
    void setChangeLevelTriggerScript(const Char* changeLevelTriggerScript)
    {
        ensureData().changeLevelTriggerScript.emplace(changeLevelTriggerScript);
    }

    /**
     * レベル変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return レベル変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelDoneTriggerScript() const
    {
        return ensureData().changeLevelDoneTriggerScript;
    }

    /**
     * レベル変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelDoneTriggerScript レベル変化完了時 に実行されるGS2-Script
     */
    void setChangeLevelDoneTriggerScript(const Char* changeLevelDoneTriggerScript)
    {
        ensureData().changeLevelDoneTriggerScript.emplace(changeLevelDoneTriggerScript);
    }

    /**
     * レベルキャップ変化時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ変化時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelCapTriggerScript() const
    {
        return ensureData().changeLevelCapTriggerScript;
    }

    /**
     * レベルキャップ変化時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapTriggerScript レベルキャップ変化時 に実行されるGS2-Script
     */
    void setChangeLevelCapTriggerScript(const Char* changeLevelCapTriggerScript)
    {
        ensureData().changeLevelCapTriggerScript.emplace(changeLevelCapTriggerScript);
    }

    /**
     * レベルキャップ変化完了時 に実行されるGS2-Scriptを取得
     *
     * @return レベルキャップ変化完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChangeLevelCapDoneTriggerScript() const
    {
        return ensureData().changeLevelCapDoneTriggerScript;
    }

    /**
     * レベルキャップ変化完了時 に実行されるGS2-Scriptを設定
     *
     * @param changeLevelCapDoneTriggerScript レベルキャップ変化完了時 に実行されるGS2-Script
     */
    void setChangeLevelCapDoneTriggerScript(const Char* changeLevelCapDoneTriggerScript)
    {
        ensureData().changeLevelCapDoneTriggerScript.emplace(changeLevelCapDoneTriggerScript);
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

#endif //GS2_LEVEL_MODEL_RESOURCEPOOL_HPP_