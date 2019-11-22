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

#ifndef GS2_LOTTERY_MODEL_LOTTERYMODEL_HPP_
#define GS2_LOTTERY_MODEL_LOTTERYMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace lottery {

/**
 * 抽選の種類
 *
 * @author Game Server Services, Inc.
 *
 */
class LotteryModel : public Gs2Object
{
    friend bool operator!=(const LotteryModel& lhs, const LotteryModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選の種類マスター */
        optional<StringHolder> lotteryModelId;
        /** 抽選モデルの種類名 */
        optional<StringHolder> name;
        /** 抽選モデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 抽選モード */
        optional<StringHolder> mode;
        /** 抽選方法 */
        optional<StringHolder> method;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 抽選テーブルを確定するスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;

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
    LotteryModel() = default;
    LotteryModel(const LotteryModel& lotteryModel) = default;
    LotteryModel(LotteryModel&& lotteryModel) = default;
    ~LotteryModel() = default;

    LotteryModel& operator=(const LotteryModel& lotteryModel) = default;
    LotteryModel& operator=(LotteryModel&& lotteryModel) = default;

    LotteryModel deepCopy() const;

    const LotteryModel* operator->() const
    {
        return this;
    }

    LotteryModel* operator->()
    {
        return this;
    }
    /**
     * 抽選の種類マスターを取得
     *
     * @return 抽選の種類マスター
     */
    const optional<StringHolder>& getLotteryModelId() const
    {
        return ensureData().lotteryModelId;
    }

    /**
     * 抽選の種類マスターを設定
     *
     * @param lotteryModelId 抽選の種類マスター
     */
    void setLotteryModelId(StringHolder lotteryModelId)
    {
        ensureData().lotteryModelId.emplace(std::move(lotteryModelId));
    }

    /**
     * 抽選の種類マスターを設定
     *
     * @param lotteryModelId 抽選の種類マスター
     */
    LotteryModel& withLotteryModelId(StringHolder lotteryModelId)
    {
        setLotteryModelId(std::move(lotteryModelId));
        return *this;
    }

    /**
     * 抽選モデルの種類名を取得
     *
     * @return 抽選モデルの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    LotteryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 抽選モデルの種類のメタデータを取得
     *
     * @return 抽選モデルの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    LotteryModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 抽選モードを取得
     *
     * @return 抽選モード
     */
    const optional<StringHolder>& getMode() const
    {
        return ensureData().mode;
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    void setMode(StringHolder mode)
    {
        ensureData().mode.emplace(std::move(mode));
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    LotteryModel& withMode(StringHolder mode)
    {
        setMode(std::move(mode));
        return *this;
    }

    /**
     * 抽選方法を取得
     *
     * @return 抽選方法
     */
    const optional<StringHolder>& getMethod() const
    {
        return ensureData().method;
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    void setMethod(StringHolder method)
    {
        ensureData().method.emplace(std::move(method));
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    LotteryModel& withMethod(StringHolder method)
    {
        setMethod(std::move(method));
        return *this;
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
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    LotteryModel& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
        return *this;
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを取得
     *
     * @return 抽選テーブルを確定するスクリプト のGRN
     */
    const optional<StringHolder>& getChoicePrizeTableScriptId() const
    {
        return ensureData().choicePrizeTableScriptId;
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    void setChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(std::move(choicePrizeTableScriptId));
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    LotteryModel& withChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        setChoicePrizeTableScriptId(std::move(choicePrizeTableScriptId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const LotteryModel& lhs, const LotteryModel& lhr);

inline bool operator==(const LotteryModel& lhs, const LotteryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_LOTTERYMODEL_HPP_