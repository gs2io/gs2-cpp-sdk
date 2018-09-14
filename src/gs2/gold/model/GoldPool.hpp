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

#ifndef GS2_GOLD_MODEL_GOLDPOOL_HPP_
#define GS2_GOLD_MODEL_GOLDPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gold {

/**
 * ゴールドプール
 *
 * @author Game Server Services, Inc.
 *
 */
class GoldPool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゴールドプールGRN */
        optional<StringHolder> goldPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゴールドプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** ウォレットの生成時 に実行されるGS2-Script */
        optional<StringHolder> createWalletTriggerScript;
        /** ウォレットの生成完了時 に実行されるGS2-Script */
        optional<StringHolder> createWalletDoneTriggerScript;
        /** ウォレットへの加算時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletTriggerScript;
        /** ウォレットへの加算完了時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletDoneTriggerScript;
        /** ウォレットからの減算時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletTriggerScript;
        /** ウォレットからの減算完了時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            goldPoolId(data.goldPoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            createWalletTriggerScript(data.createWalletTriggerScript),
            createWalletDoneTriggerScript(data.createWalletDoneTriggerScript),
            depositIntoWalletTriggerScript(data.depositIntoWalletTriggerScript),
            depositIntoWalletDoneTriggerScript(data.depositIntoWalletDoneTriggerScript),
            withdrawFromWalletTriggerScript(data.withdrawFromWalletTriggerScript),
            withdrawFromWalletDoneTriggerScript(data.withdrawFromWalletDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            goldPoolId(std::move(data.goldPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            createWalletTriggerScript(std::move(data.createWalletTriggerScript)),
            createWalletDoneTriggerScript(std::move(data.createWalletDoneTriggerScript)),
            depositIntoWalletTriggerScript(std::move(data.depositIntoWalletTriggerScript)),
            depositIntoWalletDoneTriggerScript(std::move(data.depositIntoWalletDoneTriggerScript)),
            withdrawFromWalletTriggerScript(std::move(data.withdrawFromWalletTriggerScript)),
            withdrawFromWalletDoneTriggerScript(std::move(data.withdrawFromWalletDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "goldPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->goldPoolId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositIntoWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositIntoWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositIntoWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositIntoWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawFromWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawFromWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawFromWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawFromWalletDoneTriggerScript.emplace(jsonValue.GetString());
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
    GoldPool() :
        m_pData(nullptr)
    {}

    GoldPool(const GoldPool& goldPool) :
        Gs2Object(goldPool),
        m_pData(goldPool.m_pData != nullptr ? new Data(*goldPool.m_pData) : nullptr)
    {}

    GoldPool(GoldPool&& goldPool) :
        Gs2Object(std::move(goldPool)),
        m_pData(goldPool.m_pData)
    {
        goldPool.m_pData = nullptr;
    }

    ~GoldPool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GoldPool& operator=(const GoldPool& goldPool)
    {
        Gs2Object::operator=(goldPool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*goldPool.m_pData);

        return *this;
    }

    GoldPool& operator=(GoldPool&& goldPool)
    {
        Gs2Object::operator=(std::move(goldPool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = goldPool.m_pData;
        goldPool.m_pData = nullptr;

        return *this;
    }

    const GoldPool* operator->() const
    {
        return this;
    }

    GoldPool* operator->()
    {
        return this;
    }


    /**
     * ゴールドプールGRNを取得
     *
     * @return ゴールドプールGRN
     */
    const optional<StringHolder>& getGoldPoolId() const
    {
        return ensureData().goldPoolId;
    }

    /**
     * ゴールドプールGRNを設定
     *
     * @param goldPoolId ゴールドプールGRN
     */
    void setGoldPoolId(const Char* goldPoolId)
    {
        ensureData().goldPoolId.emplace(goldPoolId);
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
     * ゴールドプール名を取得
     *
     * @return ゴールドプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ゴールドプール名を設定
     *
     * @param name ゴールドプール名
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
     * ウォレットの生成時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletTriggerScript() const
    {
        return ensureData().createWalletTriggerScript;
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレットの生成時 に実行されるGS2-Script
     */
    void setCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerScript() const
    {
        return ensureData().createWalletDoneTriggerScript;
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレットの生成完了時 に実行されるGS2-Script
     */
    void setCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletTriggerScript() const
    {
        return ensureData().depositIntoWalletTriggerScript;
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletTriggerScript ウォレットへの加算時 に実行されるGS2-Script
     */
    void setDepositIntoWalletTriggerScript(const Char* depositIntoWalletTriggerScript)
    {
        ensureData().depositIntoWalletTriggerScript.emplace(depositIntoWalletTriggerScript);
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletDoneTriggerScript() const
    {
        return ensureData().depositIntoWalletDoneTriggerScript;
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletDoneTriggerScript ウォレットへの加算完了時 に実行されるGS2-Script
     */
    void setDepositIntoWalletDoneTriggerScript(const Char* depositIntoWalletDoneTriggerScript)
    {
        ensureData().depositIntoWalletDoneTriggerScript.emplace(depositIntoWalletDoneTriggerScript);
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletTriggerScript() const
    {
        return ensureData().withdrawFromWalletTriggerScript;
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletTriggerScript ウォレットからの減算時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletTriggerScript(const Char* withdrawFromWalletTriggerScript)
    {
        ensureData().withdrawFromWalletTriggerScript.emplace(withdrawFromWalletTriggerScript);
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletDoneTriggerScript() const
    {
        return ensureData().withdrawFromWalletDoneTriggerScript;
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletDoneTriggerScript ウォレットからの減算完了時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletDoneTriggerScript(const Char* withdrawFromWalletDoneTriggerScript)
    {
        ensureData().withdrawFromWalletDoneTriggerScript.emplace(withdrawFromWalletDoneTriggerScript);
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

#endif //GS2_GOLD_MODEL_GOLDPOOL_HPP_