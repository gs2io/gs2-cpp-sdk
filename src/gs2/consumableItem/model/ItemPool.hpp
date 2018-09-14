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

#ifndef GS2_CONSUMABLEITEM_MODEL_ITEMPOOL_HPP_
#define GS2_CONSUMABLEITEM_MODEL_ITEMPOOL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace consumableItem {

/**
 * 消費型アイテムプール
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemPool : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費型アイテムプールID */
        optional<StringHolder> itemPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 消費型アイテムプール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** アイテム入手時 に実行されるGS2-Script */
        optional<StringHolder> acquisitionItemTriggerScript;
        /** アイテム入手完了時 に実行されるGS2-Script */
        optional<StringHolder> acquisitionItemDoneTriggerScript;
        /** アイテム消費時 に実行されるGS2-Script */
        optional<StringHolder> consumeItemTriggerScript;
        /** アイテム消費完了時 に実行されるGS2-Script */
        optional<StringHolder> consumeItemDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemPoolId(data.itemPoolId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            acquisitionItemTriggerScript(data.acquisitionItemTriggerScript),
            acquisitionItemDoneTriggerScript(data.acquisitionItemDoneTriggerScript),
            consumeItemTriggerScript(data.consumeItemTriggerScript),
            consumeItemDoneTriggerScript(data.consumeItemDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemPoolId(std::move(data.itemPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            acquisitionItemTriggerScript(std::move(data.acquisitionItemTriggerScript)),
            acquisitionItemDoneTriggerScript(std::move(data.acquisitionItemDoneTriggerScript)),
            consumeItemTriggerScript(std::move(data.consumeItemTriggerScript)),
            consumeItemDoneTriggerScript(std::move(data.consumeItemDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "itemPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemPoolId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "acquisitionItemTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->acquisitionItemTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "acquisitionItemDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->acquisitionItemDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeItemTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeItemTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeItemDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeItemDoneTriggerScript.emplace(jsonValue.GetString());
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
    ItemPool() :
        m_pData(nullptr)
    {}

    ItemPool(const ItemPool& itemPool) :
        Gs2Object(itemPool),
        m_pData(itemPool.m_pData != nullptr ? new Data(*itemPool.m_pData) : nullptr)
    {}

    ItemPool(ItemPool&& itemPool) :
        Gs2Object(std::move(itemPool)),
        m_pData(itemPool.m_pData)
    {
        itemPool.m_pData = nullptr;
    }

    ~ItemPool()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemPool& operator=(const ItemPool& itemPool)
    {
        Gs2Object::operator=(itemPool);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemPool.m_pData);

        return *this;
    }

    ItemPool& operator=(ItemPool&& itemPool)
    {
        Gs2Object::operator=(std::move(itemPool));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemPool.m_pData;
        itemPool.m_pData = nullptr;

        return *this;
    }

    const ItemPool* operator->() const
    {
        return this;
    }

    ItemPool* operator->()
    {
        return this;
    }


    /**
     * 消費型アイテムプールIDを取得
     *
     * @return 消費型アイテムプールID
     */
    const optional<StringHolder>& getItemPoolId() const
    {
        return ensureData().itemPoolId;
    }

    /**
     * 消費型アイテムプールIDを設定
     *
     * @param itemPoolId 消費型アイテムプールID
     */
    void setItemPoolId(const Char* itemPoolId)
    {
        ensureData().itemPoolId.emplace(itemPoolId);
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
     * 消費型アイテムプール名を取得
     *
     * @return 消費型アイテムプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 消費型アイテムプール名を設定
     *
     * @param name 消費型アイテムプール名
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
     * アイテム入手時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム入手時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAcquisitionItemTriggerScript() const
    {
        return ensureData().acquisitionItemTriggerScript;
    }

    /**
     * アイテム入手時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemTriggerScript アイテム入手時 に実行されるGS2-Script
     */
    void setAcquisitionItemTriggerScript(const Char* acquisitionItemTriggerScript)
    {
        ensureData().acquisitionItemTriggerScript.emplace(acquisitionItemTriggerScript);
    }

    /**
     * アイテム入手完了時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム入手完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getAcquisitionItemDoneTriggerScript() const
    {
        return ensureData().acquisitionItemDoneTriggerScript;
    }

    /**
     * アイテム入手完了時 に実行されるGS2-Scriptを設定
     *
     * @param acquisitionItemDoneTriggerScript アイテム入手完了時 に実行されるGS2-Script
     */
    void setAcquisitionItemDoneTriggerScript(const Char* acquisitionItemDoneTriggerScript)
    {
        ensureData().acquisitionItemDoneTriggerScript.emplace(acquisitionItemDoneTriggerScript);
    }

    /**
     * アイテム消費時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム消費時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeItemTriggerScript() const
    {
        return ensureData().consumeItemTriggerScript;
    }

    /**
     * アイテム消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemTriggerScript アイテム消費時 に実行されるGS2-Script
     */
    void setConsumeItemTriggerScript(const Char* consumeItemTriggerScript)
    {
        ensureData().consumeItemTriggerScript.emplace(consumeItemTriggerScript);
    }

    /**
     * アイテム消費完了時 に実行されるGS2-Scriptを取得
     *
     * @return アイテム消費完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeItemDoneTriggerScript() const
    {
        return ensureData().consumeItemDoneTriggerScript;
    }

    /**
     * アイテム消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeItemDoneTriggerScript アイテム消費完了時 に実行されるGS2-Script
     */
    void setConsumeItemDoneTriggerScript(const Char* consumeItemDoneTriggerScript)
    {
        ensureData().consumeItemDoneTriggerScript.emplace(consumeItemDoneTriggerScript);
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

#endif //GS2_CONSUMABLEITEM_MODEL_ITEMPOOL_HPP_