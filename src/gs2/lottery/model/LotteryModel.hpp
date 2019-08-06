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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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
        /** 抽選回数 */
        optional<Int32> count;
        /** 抽選方法 */
        optional<StringHolder> method;
        /** 景品テーブルの名前 */
        optional<StringHolder> prizeTableName;
        /** 抽選テーブルを確定するスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            lotteryModelId(data.lotteryModelId),
            name(data.name),
            metadata(data.metadata),
            mode(data.mode),
            count(data.count),
            method(data.method),
            prizeTableName(data.prizeTableName),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            lotteryModelId(std::move(data.lotteryModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            mode(std::move(data.mode)),
            count(std::move(data.count)),
            method(std::move(data.method)),
            prizeTableName(std::move(data.prizeTableName)),
            choicePrizeTableScriptId(std::move(data.choicePrizeTableScriptId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "lotteryModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->lotteryModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "mode") == 0) {
                if (jsonValue.IsString())
                {
                    this->mode.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "method") == 0) {
                if (jsonValue.IsString())
                {
                    this->method.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "choicePrizeTableScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->choicePrizeTableScriptId.emplace(jsonValue.GetString());
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
    LotteryModel() :
        m_pData(nullptr)
    {}

    LotteryModel(const LotteryModel& lotteryModel) :
        Gs2Object(lotteryModel),
        m_pData(lotteryModel.m_pData != nullptr ? new Data(*lotteryModel.m_pData) : nullptr)
    {}

    LotteryModel(LotteryModel&& lotteryModel) :
        Gs2Object(std::move(lotteryModel)),
        m_pData(lotteryModel.m_pData)
    {
        lotteryModel.m_pData = nullptr;
    }

    ~LotteryModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LotteryModel& operator=(const LotteryModel& lotteryModel)
    {
        Gs2Object::operator=(lotteryModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lotteryModel.m_pData);

        return *this;
    }

    LotteryModel& operator=(LotteryModel&& lotteryModel)
    {
        Gs2Object::operator=(std::move(lotteryModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lotteryModel.m_pData;
        lotteryModel.m_pData = nullptr;

        return *this;
    }

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
    void setLotteryModelId(const Char* lotteryModelId)
    {
        ensureData().lotteryModelId.emplace(lotteryModelId);
    }

    /**
     * 抽選の種類マスターを設定
     *
     * @param lotteryModelId 抽選の種類マスター
     */
    LotteryModel& withLotteryModelId(const Char* lotteryModelId)
    {
        setLotteryModelId(lotteryModelId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 抽選モデルの種類名を設定
     *
     * @param name 抽選モデルの種類名
     */
    LotteryModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 抽選モデルの種類のメタデータを設定
     *
     * @param metadata 抽選モデルの種類のメタデータ
     */
    LotteryModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setMode(const Char* mode)
    {
        ensureData().mode.emplace(mode);
    }

    /**
     * 抽選モードを設定
     *
     * @param mode 抽選モード
     */
    LotteryModel& withMode(const Char* mode)
    {
        setMode(mode);
        return *this;
    }

    /**
     * 抽選回数を取得
     *
     * @return 抽選回数
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 抽選回数を設定
     *
     * @param count 抽選回数
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 抽選回数を設定
     *
     * @param count 抽選回数
     */
    LotteryModel& withCount(Int32 count)
    {
        setCount(count);
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
    void setMethod(const Char* method)
    {
        ensureData().method.emplace(method);
    }

    /**
     * 抽選方法を設定
     *
     * @param method 抽選方法
     */
    LotteryModel& withMethod(const Char* method)
    {
        setMethod(method);
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
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 景品テーブルの名前を設定
     *
     * @param prizeTableName 景品テーブルの名前
     */
    LotteryModel& withPrizeTableName(const Char* prizeTableName)
    {
        setPrizeTableName(prizeTableName);
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
    void setChoicePrizeTableScriptId(const Char* choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(choicePrizeTableScriptId);
    }

    /**
     * 抽選テーブルを確定するスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 抽選テーブルを確定するスクリプト のGRN
     */
    LotteryModel& withChoicePrizeTableScriptId(const Char* choicePrizeTableScriptId)
    {
        setChoicePrizeTableScriptId(choicePrizeTableScriptId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const LotteryModel& lhs, const LotteryModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->mode != lhr.m_pData->mode)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
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
    }
    return false;
}

inline bool operator==(const LotteryModel& lhs, const LotteryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_LOTTERYMODEL_HPP_