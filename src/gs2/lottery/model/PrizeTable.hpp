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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Prize.hpp"
#include <memory>

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
    PrizeTable() = default;
    PrizeTable(const PrizeTable& prizeTable) = default;
    PrizeTable(PrizeTable&& prizeTable) = default;
    ~PrizeTable() = default;

    PrizeTable& operator=(const PrizeTable& prizeTable) = default;
    PrizeTable& operator=(PrizeTable&& prizeTable) = default;

    PrizeTable deepCopy() const;

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
    void setPrizeTableId(StringHolder prizeTableId)
    {
        ensureData().prizeTableId.emplace(std::move(prizeTableId));
    }

    /**
     * 排出確率テーブルマスターを設定
     *
     * @param prizeTableId 排出確率テーブルマスター
     */
    PrizeTable& withPrizeTableId(StringHolder prizeTableId)
    {
        setPrizeTableId(std::move(prizeTableId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 景品テーブル名を設定
     *
     * @param name 景品テーブル名
     */
    PrizeTable& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 景品テーブルのメタデータを設定
     *
     * @param metadata 景品テーブルのメタデータ
     */
    PrizeTable& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    PrizeTable& withPrizes(List<Prize> prizes)
    {
        setPrizes(std::move(prizes));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const PrizeTable& lhs, const PrizeTable& lhr);

inline bool operator==(const PrizeTable& lhs, const PrizeTable& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_PRIZETABLE_HPP_