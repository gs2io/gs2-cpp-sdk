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
#include "PrizeMaster.hpp"
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 景品の排出確率テーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class PrizeTableMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 景品の排出確率テーブル のGRN */
        optional<StringHolder> prizeTableId;
        /** 景品テーブル名 */
        optional<StringHolder> name;
        /** 景品テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 景品の排出確率テーブルの説明 */
        optional<StringHolder> description;
        /** 景品リスト */
        optional<List<PrizeMaster>> prizes;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            prizeTableId(data.prizeTableId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            prizes(data.prizes),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            prizeTableId(std::move(data.prizeTableId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            prizes(std::move(data.prizes)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizes") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->prizes.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        PrizeMaster item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->prizes += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * 景品の排出確率テーブル のGRNを取得
     *
     * @return 景品の排出確率テーブル のGRN
     */
    const optional<StringHolder>& getPrizeTableId() const
    {
        return ensureData().prizeTableId;
    }

    /**
     * 景品の排出確率テーブル のGRNを設定
     *
     * @param prizeTableId 景品の排出確率テーブル のGRN
     */
    void setPrizeTableId(const Char* prizeTableId)
    {
        ensureData().prizeTableId.emplace(prizeTableId);
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
     * 景品の排出確率テーブルの説明を取得
     *
     * @return 景品の排出確率テーブルの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 景品の排出確率テーブルの説明を設定
     *
     * @param description 景品の排出確率テーブルの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 景品リストを取得
     *
     * @return 景品リスト
     */
    const optional<List<PrizeMaster>>& getPrizes() const
    {
        return ensureData().prizes;
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    void setPrizes(const List<PrizeMaster>& prizes)
    {
        ensureData().prizes.emplace(prizes);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_MODEL_PRIZETABLEMASTER_HPP_