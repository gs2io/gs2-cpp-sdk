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
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
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
        /** 景品の種類 */
        optional<StringHolder> type;
        /** 景品の入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 排出確率テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 排出重み */
        optional<Int32> weight;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            type(data.type),
            acquireActions(data.acquireActions),
            prizeTableName(data.prizeTableName),
            weight(data.weight)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            type(std::move(data.type)),
            acquireActions(std::move(data.acquireActions)),
            prizeTableName(std::move(data.prizeTableName)),
            weight(std::move(data.weight))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->acquireActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "weight") == 0) {
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
    Prize() :
        m_pData(nullptr)
    {}

    Prize(const Prize& prize) :
        Gs2Object(prize),
        m_pData(prize.m_pData != nullptr ? new Data(*prize.m_pData) : nullptr)
    {}

    Prize(Prize&& prize) :
        Gs2Object(std::move(prize)),
        m_pData(prize.m_pData)
    {
        prize.m_pData = nullptr;
    }

    ~Prize()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Prize& operator=(const Prize& prize)
    {
        Gs2Object::operator=(prize);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*prize.m_pData);

        return *this;
    }

    Prize& operator=(Prize&& prize)
    {
        Gs2Object::operator=(std::move(prize));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = prize.m_pData;
        prize.m_pData = nullptr;

        return *this;
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
     * 景品の種類を設定
     *
     * @param type 景品の種類
     */
    Prize& withType(const Char* type)
    {
        setType(type);
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
    void setAcquireActions(const List<AcquireAction>& acquireActions)
    {
        ensureData().acquireActions.emplace(acquireActions);
    }

    /**
     * 景品の入手アクションリストを設定
     *
     * @param acquireActions 景品の入手アクションリスト
     */
    Prize& withAcquireActions(const List<AcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
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
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 排出確率テーブルの名前を設定
     *
     * @param prizeTableName 排出確率テーブルの名前
     */
    Prize& withPrizeTableName(const Char* prizeTableName)
    {
        setPrizeTableName(prizeTableName);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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