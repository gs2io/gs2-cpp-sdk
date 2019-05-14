/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LOTTERY_MODEL_PRIZEMASTER_HPP_
#define GS2_LOTTERY_MODEL_PRIZEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

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
        /** 景品の種類 */
        optional<StringHolder> type;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 排出重み/BOXに入れる数量 */
        
        optional<Int32> weight;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            type(data.type),
            propertyId(data.propertyId),
            prizeTableName(data.prizeTableName),
            weight(data.weight)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            type(std::move(data.type)),
            propertyId(std::move(data.propertyId)),
            prizeTableName(std::move(data.prizeTableName)),
            weight(std::move(data.weight))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "propertyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizeTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "weight") == 0) {
                if (jsonValue.IsInt())
                {
                    this->weight = jsonValue.GetInt();
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
     * 景品の種類を取得
     *
     * @return 景品の種類
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 景品の種類を設定
     *
     * @param type 景品の種類
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }

    /**
     * 景品テーブルの名前を取得
     *
     * @return 景品テーブルの名前
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 排出重み/BOXに入れる数量を取得
     *
     * @return 排出重み/BOXに入れる数量
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 排出重み/BOXに入れる数量を設定
     *
     * @param weight 排出重み/BOXに入れる数量
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_MODEL_PRIZEMASTER_HPP_