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

#ifndef GS2_CONSUMABLEITEM_MODEL_ITEMMASTER_HPP_
#define GS2_CONSUMABLEITEM_MODEL_ITEMMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace consumableItem {

/**
 * 消費型アイテム
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費型アイテムID */
        optional<StringHolder> itemId;
        /** 消費型アイテム名 */
        optional<StringHolder> name;
        /** 所持数の上限 */
        optional<Int32> max;
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
            itemId(data.itemId),
            name(data.name),
            max(data.max),
            acquisitionItemTriggerScript(data.acquisitionItemTriggerScript),
            acquisitionItemDoneTriggerScript(data.acquisitionItemDoneTriggerScript),
            consumeItemTriggerScript(data.consumeItemTriggerScript),
            consumeItemDoneTriggerScript(data.consumeItemDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemId(std::move(data.itemId)),
            name(std::move(data.name)),
            max(std::move(data.max)),
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
            if (std::strcmp(name, "itemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "max") == 0) {
                if (jsonValue.IsInt())
                {
                    this->max = jsonValue.GetInt();
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
    ItemMaster() :
        m_pData(nullptr)
    {}

    ItemMaster(const ItemMaster& itemMaster) :
        Gs2Object(itemMaster),
        m_pData(itemMaster.m_pData != nullptr ? new Data(*itemMaster.m_pData) : nullptr)
    {}

    ItemMaster(ItemMaster&& itemMaster) :
        Gs2Object(std::move(itemMaster)),
        m_pData(itemMaster.m_pData)
    {
        itemMaster.m_pData = nullptr;
    }

    ~ItemMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemMaster& operator=(const ItemMaster& itemMaster)
    {
        Gs2Object::operator=(itemMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemMaster.m_pData);

        return *this;
    }

    ItemMaster& operator=(ItemMaster&& itemMaster)
    {
        Gs2Object::operator=(std::move(itemMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemMaster.m_pData;
        itemMaster.m_pData = nullptr;

        return *this;
    }

    const ItemMaster* operator->() const
    {
        return this;
    }

    ItemMaster* operator->()
    {
        return this;
    }


    /**
     * 消費型アイテムIDを取得
     *
     * @return 消費型アイテムID
     */
    const optional<StringHolder>& getItemId() const
    {
        return ensureData().itemId;
    }

    /**
     * 消費型アイテムIDを設定
     *
     * @param itemId 消費型アイテムID
     */
    void setItemId(const Char* itemId)
    {
        ensureData().itemId.emplace(itemId);
    }

    /**
     * 消費型アイテム名を取得
     *
     * @return 消費型アイテム名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 消費型アイテム名を設定
     *
     * @param name 消費型アイテム名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 所持数の上限を取得
     *
     * @return 所持数の上限
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * 所持数の上限を設定
     *
     * @param max 所持数の上限
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
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

#endif //GS2_CONSUMABLEITEM_MODEL_ITEMMASTER_HPP_