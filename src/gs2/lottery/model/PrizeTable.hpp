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

#ifndef GS2_LOTTERY_MODEL_PRIZETABLE_HPP_
#define GS2_LOTTERY_MODEL_PRIZETABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Prize.hpp"
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 排出確率テーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class PrizeTable : public Gs2Object
{
    friend bool operator!=(const PrizeTable& lhs, const PrizeTable& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 排出確率テーブルマスター */
        optional<StringHolder> prizeTableId;
        /** 景品テーブル名 */
        optional<StringHolder> name;
        /** 景品テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 景品リスト */
        optional<List<Prize>> prizes;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            prizeTableId(data.prizeTableId),
            name(data.name),
            metadata(data.metadata),
            prizes(data.prizes)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            prizeTableId(std::move(data.prizeTableId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            prizes(std::move(data.prizes))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "prizeTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizes") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->prizes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Prize item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->prizes, std::move(item));
                    }
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
    PrizeTable() :
        m_pData(nullptr)
    {}

    PrizeTable(const PrizeTable& prizeTable) :
        Gs2Object(prizeTable),
        m_pData(prizeTable.m_pData != nullptr ? new Data(*prizeTable.m_pData) : nullptr)
    {}

    PrizeTable(PrizeTable&& prizeTable) :
        Gs2Object(std::move(prizeTable)),
        m_pData(prizeTable.m_pData)
    {
        prizeTable.m_pData = nullptr;
    }

    ~PrizeTable()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PrizeTable& operator=(const PrizeTable& prizeTable)
    {
        Gs2Object::operator=(prizeTable);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*prizeTable.m_pData);

        return *this;
    }

    PrizeTable& operator=(PrizeTable&& prizeTable)
    {
        Gs2Object::operator=(std::move(prizeTable));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = prizeTable.m_pData;
        prizeTable.m_pData = nullptr;

        return *this;
    }

    const PrizeTable* operator->() const
    {
        return this;
    }

    PrizeTable* operator->()
    {
        return this;
    }
    /**
     * 排出確率テーブルマスターを取得
     *
     * @return 排出確率テーブルマスター
     */
    const optional<StringHolder>& getPrizeTableId() const
    {
        return ensureData().prizeTableId;
    }

    /**
     * 排出確率テーブルマスターを設定
     *
     * @param prizeTableId 排出確率テーブルマスター
     */
    void setPrizeTableId(const Char* prizeTableId)
    {
        ensureData().prizeTableId.emplace(prizeTableId);
    }

    /**
     * 排出確率テーブルマスターを設定
     *
     * @param prizeTableId 排出確率テーブルマスター
     */
    PrizeTable& withPrizeTableId(const Char* prizeTableId)
    {
        setPrizeTableId(prizeTableId);
        return *this;
    }

    /**
     * 景品テーブル名を取得
     *
     * @return 景品テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 景品テーブル名を設定
     *
     * @param name 景品テーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 景品テーブル名を設定
     *
     * @param name 景品テーブル名
     */
    PrizeTable& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 景品テーブルのメタデータを取得
     *
     * @return 景品テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 景品テーブルのメタデータを設定
     *
     * @param metadata 景品テーブルのメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 景品テーブルのメタデータを設定
     *
     * @param metadata 景品テーブルのメタデータ
     */
    PrizeTable& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 景品リストを取得
     *
     * @return 景品リスト
     */
    const optional<List<Prize>>& getPrizes() const
    {
        return ensureData().prizes;
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    void setPrizes(const List<Prize>& prizes)
    {
        ensureData().prizes.emplace(prizes);
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    PrizeTable& withPrizes(const List<Prize>& prizes)
    {
        setPrizes(prizes);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const PrizeTable& lhs, const PrizeTable& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableId != lhr.m_pData->prizeTableId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->prizes != lhr.m_pData->prizes)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const PrizeTable& lhs, const PrizeTable& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PRIZETABLE_HPP_