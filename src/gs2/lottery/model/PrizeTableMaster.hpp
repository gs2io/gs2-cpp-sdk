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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Prize.hpp"
#include <memory>

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

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PrizeTableMaster() = default;
    PrizeTableMaster(const PrizeTableMaster& prizeTableMaster) = default;
    PrizeTableMaster(PrizeTableMaster&& prizeTableMaster) = default;
    ~PrizeTableMaster() = default;

    PrizeTableMaster& operator=(const PrizeTableMaster& prizeTableMaster) = default;
    PrizeTableMaster& operator=(PrizeTableMaster&& prizeTableMaster) = default;

    PrizeTableMaster deepCopy() const;

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
    void setPrizeTableId(StringHolder prizeTableId)
    {
        ensureData().prizeTableId.emplace(std::move(prizeTableId));
    }

    /**
     * 排出確率テーブルマスターを設定
     *
     * @param prizeTableId 排出確率テーブルマスター
     */
    PrizeTableMaster& withPrizeTableId(StringHolder prizeTableId)
    {
        setPrizeTableId(std::move(prizeTableId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param name 排出確率テーブル名
     */
    PrizeTableMaster& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 排出確率テーブルのメタデータを設定
     *
     * @param metadata 排出確率テーブルのメタデータ
     */
    PrizeTableMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 排出確率テーブルマスターの説明を設定
     *
     * @param description 排出確率テーブルマスターの説明
     */
    PrizeTableMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    void setPrizes(List<Prize> prizes)
    {
        ensureData().prizes.emplace(std::move(prizes));
    }

    /**
     * 景品リストを設定
     *
     * @param prizes 景品リスト
     */
    PrizeTableMaster& withPrizes(List<Prize> prizes)
    {
        setPrizes(std::move(prizes));
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

bool operator!=(const PrizeTableMaster& lhs, const PrizeTableMaster& lhr);

inline bool operator==(const PrizeTableMaster& lhs, const PrizeTableMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PRIZETABLEMASTER_HPP_