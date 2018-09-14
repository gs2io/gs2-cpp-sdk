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

#ifndef GS2_STAMINA_MODEL_STAMINAPOOL_HPP_
#define GS2_STAMINA_MODEL_STAMINAPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナプール
 *
 * @author Game Server Services, Inc.
 *
 */
class StaminaPool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナプールGRN */
        optional<StringHolder> staminaPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** スタミナプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** スタミナの回復速度(秒) */
        optional<Int32> increaseInterval;
        /** スタミナ消費時 に実行されるGS2-Script */
        optional<StringHolder> consumeStaminaTriggerScript;
        /** スタミナ消費完了時 に実行されるGS2-Script */
        optional<StringHolder> consumeStaminaDoneTriggerScript;
        /** スタミナ回復時 に実行されるGS2-Script */
        optional<StringHolder> addStaminaTriggerScript;
        /** スタミナ回復完了時 に実行されるGS2-Script */
        optional<StringHolder> addStaminaDoneTriggerScript;
        /** スタミナの最大値取得 に実行されるGS2-Script */
        optional<StringHolder> getMaxStaminaTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            staminaPoolId(data.staminaPoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            increaseInterval(data.increaseInterval),
            consumeStaminaTriggerScript(data.consumeStaminaTriggerScript),
            consumeStaminaDoneTriggerScript(data.consumeStaminaDoneTriggerScript),
            addStaminaTriggerScript(data.addStaminaTriggerScript),
            addStaminaDoneTriggerScript(data.addStaminaDoneTriggerScript),
            getMaxStaminaTriggerScript(data.getMaxStaminaTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            staminaPoolId(std::move(data.staminaPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            increaseInterval(std::move(data.increaseInterval)),
            consumeStaminaTriggerScript(std::move(data.consumeStaminaTriggerScript)),
            consumeStaminaDoneTriggerScript(std::move(data.consumeStaminaDoneTriggerScript)),
            addStaminaTriggerScript(std::move(data.addStaminaTriggerScript)),
            addStaminaDoneTriggerScript(std::move(data.addStaminaDoneTriggerScript)),
            getMaxStaminaTriggerScript(std::move(data.getMaxStaminaTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "staminaPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->staminaPoolId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "increaseInterval") == 0) {
                if (jsonValue.IsInt())
                {
                    this->increaseInterval = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "consumeStaminaTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeStaminaTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeStaminaDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeStaminaDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "addStaminaTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->addStaminaTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "addStaminaDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->addStaminaDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "getMaxStaminaTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->getMaxStaminaTriggerScript.emplace(jsonValue.GetString());
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
    StaminaPool() :
        m_pData(nullptr)
    {}

    StaminaPool(const StaminaPool& staminaPool) :
        Gs2Object(staminaPool),
        m_pData(staminaPool.m_pData != nullptr ? new Data(*staminaPool.m_pData) : nullptr)
    {}

    StaminaPool(StaminaPool&& staminaPool) :
        Gs2Object(std::move(staminaPool)),
        m_pData(staminaPool.m_pData)
    {
        staminaPool.m_pData = nullptr;
    }

    ~StaminaPool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StaminaPool& operator=(const StaminaPool& staminaPool)
    {
        Gs2Object::operator=(staminaPool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*staminaPool.m_pData);

        return *this;
    }

    StaminaPool& operator=(StaminaPool&& staminaPool)
    {
        Gs2Object::operator=(std::move(staminaPool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = staminaPool.m_pData;
        staminaPool.m_pData = nullptr;

        return *this;
    }

    const StaminaPool* operator->() const
    {
        return this;
    }

    StaminaPool* operator->()
    {
        return this;
    }


    /**
     * スタミナプールGRNを取得
     *
     * @return スタミナプールGRN
     */
    const optional<StringHolder>& getStaminaPoolId() const
    {
        return ensureData().staminaPoolId;
    }

    /**
     * スタミナプールGRNを設定
     *
     * @param staminaPoolId スタミナプールGRN
     */
    void setStaminaPoolId(const Char* staminaPoolId)
    {
        ensureData().staminaPoolId.emplace(staminaPoolId);
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
     * スタミナプール名を取得
     *
     * @return スタミナプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナプール名を設定
     *
     * @param name スタミナプール名
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
     * スタミナの回復速度(秒)を取得
     *
     * @return スタミナの回復速度(秒)
     */
    const optional<Int32>& getIncreaseInterval() const
    {
        return ensureData().increaseInterval;
    }

    /**
     * スタミナの回復速度(秒)を設定
     *
     * @param increaseInterval スタミナの回復速度(秒)
     */
    void setIncreaseInterval(Int32 increaseInterval)
    {
        ensureData().increaseInterval.emplace(increaseInterval);
    }

    /**
     * スタミナ消費時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ消費時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeStaminaTriggerScript() const
    {
        return ensureData().consumeStaminaTriggerScript;
    }

    /**
     * スタミナ消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaTriggerScript スタミナ消費時 に実行されるGS2-Script
     */
    void setConsumeStaminaTriggerScript(const Char* consumeStaminaTriggerScript)
    {
        ensureData().consumeStaminaTriggerScript.emplace(consumeStaminaTriggerScript);
    }

    /**
     * スタミナ消費完了時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ消費完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeStaminaDoneTriggerScript() const
    {
        return ensureData().consumeStaminaDoneTriggerScript;
    }

    /**
     * スタミナ消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeStaminaDoneTriggerScript スタミナ消費完了時 に実行されるGS2-Script
     */
    void setConsumeStaminaDoneTriggerScript(const Char* consumeStaminaDoneTriggerScript)
    {
        ensureData().consumeStaminaDoneTriggerScript.emplace(consumeStaminaDoneTriggerScript);
    }

    /**
     * スタミナ回復時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ回復時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAddStaminaTriggerScript() const
    {
        return ensureData().addStaminaTriggerScript;
    }

    /**
     * スタミナ回復時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaTriggerScript スタミナ回復時 に実行されるGS2-Script
     */
    void setAddStaminaTriggerScript(const Char* addStaminaTriggerScript)
    {
        ensureData().addStaminaTriggerScript.emplace(addStaminaTriggerScript);
    }

    /**
     * スタミナ回復完了時 に実行されるGS2-Scriptを取得
     *
     * @return スタミナ回復完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAddStaminaDoneTriggerScript() const
    {
        return ensureData().addStaminaDoneTriggerScript;
    }

    /**
     * スタミナ回復完了時 に実行されるGS2-Scriptを設定
     *
     * @param addStaminaDoneTriggerScript スタミナ回復完了時 に実行されるGS2-Script
     */
    void setAddStaminaDoneTriggerScript(const Char* addStaminaDoneTriggerScript)
    {
        ensureData().addStaminaDoneTriggerScript.emplace(addStaminaDoneTriggerScript);
    }

    /**
     * スタミナの最大値取得 に実行されるGS2-Scriptを取得
     *
     * @return スタミナの最大値取得 に実行されるGS2-Script
     */
    const optional<StringHolder>& getGetMaxStaminaTriggerScript() const
    {
        return ensureData().getMaxStaminaTriggerScript;
    }

    /**
     * スタミナの最大値取得 に実行されるGS2-Scriptを設定
     *
     * @param getMaxStaminaTriggerScript スタミナの最大値取得 に実行されるGS2-Script
     */
    void setGetMaxStaminaTriggerScript(const Char* getMaxStaminaTriggerScript)
    {
        ensureData().getMaxStaminaTriggerScript.emplace(getMaxStaminaTriggerScript);
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

#endif //GS2_STAMINA_MODEL_STAMINAPOOL_HPP_