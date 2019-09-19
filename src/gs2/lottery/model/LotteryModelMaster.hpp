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

#ifndef GS2_LOTTERY_MODEL_LOTTERYMODELMASTER_HPP_
#define GS2_LOTTERY_MODEL_LOTTERYMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 抽選の種類マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class LotteryModelMaster : public Gs2Object
{
    friend bool operator!=(const LotteryModelMaster& lhs, const LotteryModelMaster& lhr);

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
        /** 抽選の種類マスターの説明 */
        optional<StringHolder> description;
        /** 抽選モード */
        optional<StringHolder> mode;
        /** 抽選方法 */
        optional<StringHolder> method;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 抽選テーブルを確定するスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            lotteryModelId(data.lotteryModelId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            mode(data.mode),
            method(data.method),
            prizeTableName(data.prizeTableName),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "lotteryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->lotteryModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "mode") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->mode.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "method") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->method.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "choicePrizeTableScriptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->choicePrizeTableScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    LotteryModelMaster() = default;
    LotteryModelMaster(const LotteryModelMaster& lotteryModelMaster) = default;
    LotteryModelMaster(LotteryModelMaster&& lotteryModelMaster) = default;
    ~LotteryModelMaster() = default;

    LotteryModelMaster& operator=(const LotteryModelMaster& lotteryModelMaster) = default;
    LotteryModelMaster& operator=(LotteryModelMaster&& lotteryModelMaster) = default;

    LotteryModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LotteryModelMaster);
    }

    const LotteryModelMaster* operator->() const
    {
        return this;
    }

    LotteryModelMaster* operator->()
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
    LotteryModelMaster& withLotteryModelId(StringHolder lotteryModelId)
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
    LotteryModelMaster& withName(StringHolder name)
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
    LotteryModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 抽選の種類マスターの説明を取得
     *
     * @return 抽選の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 抽選の種類マスターの説明を設定
     *
     * @param description 抽選の種類マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 抽選の種類マスターの説明を設定
     *
     * @param description 抽選の種類マスターの説明
     */
    LotteryModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    LotteryModelMaster& withMode(StringHolder mode)
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
    LotteryModelMaster& withMethod(StringHolder method)
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
    LotteryModelMaster& withPrizeTableName(StringHolder prizeTableName)
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
    LotteryModelMaster& withChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        setChoicePrizeTableScriptId(std::move(choicePrizeTableScriptId));
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
    LotteryModelMaster& withCreatedAt(Int64 createdAt)
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
    LotteryModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LotteryModelMaster& lhs, const LotteryModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->lotteryModelId != lhr.m_pData->lotteryModelId)
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
        if (lhs.m_pData->mode != lhr.m_pData->mode)
        {
            return true;
        }
        if (lhs.m_pData->method != lhr.m_pData->method)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->choicePrizeTableScriptId != lhr.m_pData->choicePrizeTableScriptId)
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

inline bool operator==(const LotteryModelMaster& lhs, const LotteryModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_LOTTERYMODELMASTER_HPP_