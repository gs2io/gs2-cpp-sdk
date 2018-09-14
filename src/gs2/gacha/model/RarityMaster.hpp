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

#ifndef GS2_GACHA_MODEL_RARITYMASTER_HPP_
#define GS2_GACHA_MODEL_RARITYMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * 景品レアリティ
 *
 * @author Game Server Services, Inc.
 *
 */
class RarityMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品レアリティGRN */
        optional<StringHolder> rarityId;
        /** 景品レアリティ名 */
        optional<StringHolder> name;
        /** 排出重み */
        optional<Int32> weight;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            rarityId(data.rarityId),
            name(data.name),
            weight(data.weight),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            rarityId(std::move(data.rarityId)),
            name(std::move(data.name)),
            weight(std::move(data.weight)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "rarityId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rarityId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "weight") == 0) {
                if (jsonValue.IsInt())
                {
                    this->weight = jsonValue.GetInt();
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
    RarityMaster() :
        m_pData(nullptr)
    {}

    RarityMaster(const RarityMaster& rarityMaster) :
        Gs2Object(rarityMaster),
        m_pData(rarityMaster.m_pData != nullptr ? new Data(*rarityMaster.m_pData) : nullptr)
    {}

    RarityMaster(RarityMaster&& rarityMaster) :
        Gs2Object(std::move(rarityMaster)),
        m_pData(rarityMaster.m_pData)
    {
        rarityMaster.m_pData = nullptr;
    }

    ~RarityMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RarityMaster& operator=(const RarityMaster& rarityMaster)
    {
        Gs2Object::operator=(rarityMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*rarityMaster.m_pData);

        return *this;
    }

    RarityMaster& operator=(RarityMaster&& rarityMaster)
    {
        Gs2Object::operator=(std::move(rarityMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = rarityMaster.m_pData;
        rarityMaster.m_pData = nullptr;

        return *this;
    }

    const RarityMaster* operator->() const
    {
        return this;
    }

    RarityMaster* operator->()
    {
        return this;
    }


    /**
     * 景品レアリティGRNを取得
     *
     * @return 景品レアリティGRN
     */
    const optional<StringHolder>& getRarityId() const
    {
        return ensureData().rarityId;
    }

    /**
     * 景品レアリティGRNを設定
     *
     * @param rarityId 景品レアリティGRN
     */
    void setRarityId(const Char* rarityId)
    {
        ensureData().rarityId.emplace(rarityId);
    }

    /**
     * 景品レアリティ名を取得
     *
     * @return 景品レアリティ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 景品レアリティ名を設定
     *
     * @param name 景品レアリティ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 排出重みを取得
     *
     * @return 排出重み
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 排出重みを設定
     *
     * @param weight 排出重み
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
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

#endif //GS2_GACHA_MODEL_RARITYMASTER_HPP_