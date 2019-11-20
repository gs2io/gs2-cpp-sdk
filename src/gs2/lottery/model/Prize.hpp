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

#ifndef GS2_LOTTERY_MODEL_PRIZE_HPP_
#define GS2_LOTTERY_MODEL_PRIZE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 景品
 *
 * @author Game Server Services, Inc.
 *
 */
class Prize : public Gs2Object
{
    friend bool operator!=(const Prize& lhs, const Prize& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品ID */
        optional<StringHolder> prizeId;
        /** 景品の種類 */
        optional<StringHolder> type;
        /** 景品の入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 排出確率テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 排出重み */
        optional<Int32> weight;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            prizeId(data.prizeId),
            type(data.type),
            prizeTableName(data.prizeTableName),
            weight(data.weight)
        {
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "prizeId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->prizeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->acquireActions += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "weight") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->weight = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Prize() = default;
    Prize(const Prize& prize) = default;
    Prize(Prize&& prize) = default;
    ~Prize() = default;

    Prize& operator=(const Prize& prize) = default;
    Prize& operator=(Prize&& prize) = default;

    Prize deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Prize);
    }

    const Prize* operator->() const
    {
        return this;
    }

    Prize* operator->()
    {
        return this;
    }
    /**
     * 景品IDを取得
     *
     * @return 景品ID
     */
    const optional<StringHolder>& getPrizeId() const
    {
        return ensureData().prizeId;
    }

    /**
     * 景品IDを設定
     *
     * @param prizeId 景品ID
     */
    void setPrizeId(StringHolder prizeId)
    {
        ensureData().prizeId.emplace(std::move(prizeId));
    }

    /**
     * 景品IDを設定
     *
     * @param prizeId 景品ID
     */
    Prize& withPrizeId(StringHolder prizeId)
    {
        setPrizeId(std::move(prizeId));
        return *this;
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
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * 景品の種類を設定
     *
     * @param type 景品の種類
     */
    Prize& withType(StringHolder type)
    {
        setType(std::move(type));
        return *this;
    }

    /**
     * 景品の入手アクションリストを取得
     *
     * @return 景品の入手アクションリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 景品の入手アクションリストを設定
     *
     * @param acquireActions 景品の入手アクションリスト
     */
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 景品の入手アクションリストを設定
     *
     * @param acquireActions 景品の入手アクションリスト
     */
    Prize& withAcquireActions(List<AcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }

    /**
     * 排出確率テーブルの名前を取得
     *
     * @return 排出確率テーブルの名前
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 排出確率テーブルの名前を設定
     *
     * @param prizeTableName 排出確率テーブルの名前
     */
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 排出確率テーブルの名前を設定
     *
     * @param prizeTableName 排出確率テーブルの名前
     */
    Prize& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
        return *this;
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
     * 排出重みを設定
     *
     * @param weight 排出重み
     */
    Prize& withWeight(Int32 weight)
    {
        setWeight(weight);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Prize& lhs, const Prize& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->prizeId != lhr.m_pData->prizeId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->weight != lhr.m_pData->weight)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Prize& lhs, const Prize& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PRIZE_HPP_