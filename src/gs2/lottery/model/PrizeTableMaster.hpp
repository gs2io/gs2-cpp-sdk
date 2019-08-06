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

#ifndef GS2_LOTTERY_MODEL_PRIZETABLEMASTER_HPP_
#define GS2_LOTTERY_MODEL_PRIZETABLEMASTER_HPP_

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
 * 排出確率テーブルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class PrizeTableMaster : public Gs2Object
{
    friend bool operator!=(const PrizeTableMaster& lhs, const PrizeTableMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 排出確率テーブルマスター */
        optional<StringHolder> prizeTableId;
        /** 排出確率テーブル名 */
        optional<StringHolder> name;
        /** 排出確率テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 排出確率テーブルマスターの説明 */
        optional<StringHolder> description;
        /** 景品リスト */
        optional<List<Prize>> prizes;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            prizeTableId(data.prizeTableId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            prizes(data.prizes),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            prizeTableId(std::move(data.prizeTableId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            prizes(std::move(data.prizes)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "prizeTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "prizes") == 0) {
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
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    PrizeTableMaster() :
        m_pData(nullptr)
    {}

    PrizeTableMaster(const PrizeTableMaster& prizeTableMaster) :
        Gs2Object(prizeTableMaster),
        m_pData(prizeTableMaster.m_pData != nullptr ? new Data(*prizeTableMaster.m_pData) : nullptr)
    {}

    PrizeTableMaster(PrizeTableMaster&& prizeTableMaster) :
        Gs2Object(std::move(prizeTableMaster)),
        m_pData(prizeTableMaster.m_pData)
    {
        prizeTableMaster.m_pData = nullptr;
    }

    ~PrizeTableMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PrizeTableMaster& operator=(const PrizeTableMaster& prizeTableMaster)
    {
        Gs2Object::operator=(prizeTableMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*prizeTableMaster.m_pData);

        return *this;
    }

    PrizeTableMaster& operator=(PrizeTableMaster&& prizeTableMaster)
    {
        Gs2Object::operator=(std::move(prizeTableMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = prizeTableMaster.m_pData;
        prizeTableMaster.m_pData = nullptr;

        return *this;
    }

    const PrizeTableMaster* operator->() const
    {
        return this;
    }

    PrizeTableMaster* operator->()
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
    PrizeTableMaster& withPrizeTableId(const Char* prizeTableId)
    {
        setPrizeTableId(prizeTableId);
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    PrizeTableMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 排出確率テーブルのメタデータを取得
     *
     * @return 排出確率テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 排出確率テーブルのメタデータを設定
     *
     * @param metadata 排出確率テーブルのメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 排出確率テーブルのメタデータを設定
     *
     * @param metadata 排出確率テーブルのメタデータ
     */
    PrizeTableMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 排出確率テーブルマスターの説明を取得
     *
     * @return 排出確率テーブルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 排出確率テーブルマスターの説明を設定
     *
     * @param description 排出確率テーブルマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 排出確率テーブルマスターの説明を設定
     *
     * @param description 排出確率テーブルマスターの説明
     */
    PrizeTableMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    PrizeTableMaster& withPrizes(const List<Prize>& prizes)
    {
        setPrizes(prizes);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    PrizeTableMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    PrizeTableMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const PrizeTableMaster& lhs, const PrizeTableMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->prizes != lhr.m_pData->prizes)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const PrizeTableMaster& lhs, const PrizeTableMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PRIZETABLEMASTER_HPP_