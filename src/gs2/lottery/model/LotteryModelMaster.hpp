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
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * 抽選の種類
 *
 * @author Game Server Services, Inc.
 *
 */
class LotteryModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選の種類 のGRN */
        optional<StringHolder> lotteryModelId;
        /** 抽選モデルの種類名 */
        optional<StringHolder> name;
        /** 抽選モデルの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 抽選の種類の説明 */
        optional<StringHolder> description;
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
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            lotteryModelId(data.lotteryModelId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            mode(data.mode),
            count(data.count),
            method(data.method),
            prizeTableName(data.prizeTableName),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            lotteryModelId(std::move(data.lotteryModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            mode(std::move(data.mode)),
            count(std::move(data.count)),
            method(std::move(data.method)),
            prizeTableName(std::move(data.prizeTableName)),
            choicePrizeTableScriptId(std::move(data.choicePrizeTableScriptId)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "lotteryModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->lotteryModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "mode") == 0) {
                if (jsonValue.IsString())
                {
                    this->mode.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "method") == 0) {
                if (jsonValue.IsString())
                {
                    this->method.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizeTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "choicePrizeTableScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->choicePrizeTableScriptId.emplace(jsonValue.GetString());
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
    LotteryModelMaster() :
        m_pData(nullptr)
    {}

    LotteryModelMaster(const LotteryModelMaster& lotteryModelMaster) :
        Gs2Object(lotteryModelMaster),
        m_pData(lotteryModelMaster.m_pData != nullptr ? new Data(*lotteryModelMaster.m_pData) : nullptr)
    {}

    LotteryModelMaster(LotteryModelMaster&& lotteryModelMaster) :
        Gs2Object(std::move(lotteryModelMaster)),
        m_pData(lotteryModelMaster.m_pData)
    {
        lotteryModelMaster.m_pData = nullptr;
    }

    ~LotteryModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LotteryModelMaster& operator=(const LotteryModelMaster& lotteryModelMaster)
    {
        Gs2Object::operator=(lotteryModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lotteryModelMaster.m_pData);

        return *this;
    }

    LotteryModelMaster& operator=(LotteryModelMaster&& lotteryModelMaster)
    {
        Gs2Object::operator=(std::move(lotteryModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lotteryModelMaster.m_pData;
        lotteryModelMaster.m_pData = nullptr;

        return *this;
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
     * 抽選の種類 のGRNを取得
     *
     * @return 抽選の種類 のGRN
     */
    const optional<StringHolder>& getLotteryModelId() const
    {
        return ensureData().lotteryModelId;
    }

    /**
     * 抽選の種類 のGRNを設定
     *
     * @param lotteryModelId 抽選の種類 のGRN
     */
    void setLotteryModelId(const Char* lotteryModelId)
    {
        ensureData().lotteryModelId.emplace(lotteryModelId);
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
     * 抽選の種類の説明を取得
     *
     * @return 抽選の種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 抽選の種類の説明を設定
     *
     * @param description 抽選の種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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

#endif //GS2_LOTTERY_MODEL_LOTTERYMODELMASTER_HPP_