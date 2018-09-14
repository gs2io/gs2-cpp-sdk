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

#ifndef GS2_GACHA_MODEL_PRIZEMASTER_HPP_
#define GS2_GACHA_MODEL_PRIZEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * 景品
 *
 * @author Game Server Services, Inc.
 *
 */
class PrizeMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品GRN */
        optional<StringHolder> prizeId;
        /** リソースID */
        optional<StringHolder> resourceId;
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
            prizeId(data.prizeId),
            resourceId(data.resourceId),
            weight(data.weight),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            prizeId(std::move(data.prizeId)),
            resourceId(std::move(data.resourceId)),
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
            if (std::strcmp(name, "prizeId") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resourceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceId.emplace(jsonValue.GetString());
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
    PrizeMaster() :
        m_pData(nullptr)
    {}

    PrizeMaster(const PrizeMaster& prizeMaster) :
        Gs2Object(prizeMaster),
        m_pData(prizeMaster.m_pData != nullptr ? new Data(*prizeMaster.m_pData) : nullptr)
    {}

    PrizeMaster(PrizeMaster&& prizeMaster) :
        Gs2Object(std::move(prizeMaster)),
        m_pData(prizeMaster.m_pData)
    {
        prizeMaster.m_pData = nullptr;
    }

    ~PrizeMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PrizeMaster& operator=(const PrizeMaster& prizeMaster)
    {
        Gs2Object::operator=(prizeMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*prizeMaster.m_pData);

        return *this;
    }

    PrizeMaster& operator=(PrizeMaster&& prizeMaster)
    {
        Gs2Object::operator=(std::move(prizeMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = prizeMaster.m_pData;
        prizeMaster.m_pData = nullptr;

        return *this;
    }

    const PrizeMaster* operator->() const
    {
        return this;
    }

    PrizeMaster* operator->()
    {
        return this;
    }


    /**
     * 景品GRNを取得
     *
     * @return 景品GRN
     */
    const optional<StringHolder>& getPrizeId() const
    {
        return ensureData().prizeId;
    }

    /**
     * 景品GRNを設定
     *
     * @param prizeId 景品GRN
     */
    void setPrizeId(const Char* prizeId)
    {
        ensureData().prizeId.emplace(prizeId);
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

#endif //GS2_GACHA_MODEL_PRIZEMASTER_HPP_