/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_RANKING_MODEL_RANKINGTABLE_HPP_
#define GS2_RANKING_MODEL_RANKINGTABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * ランキングテーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class RankingTable : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ランキングテーブルGRN */
        optional<StringHolder> rankingTableId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ランキングテーブル名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** スコア登録時 に実行されるGS2-Script */
        optional<StringHolder> putScoreTriggerScript;
        /** スコア登録完了時 に実行されるGS2-Script */
        optional<StringHolder> putScoreDoneTriggerScript;
        /** 集計処理完了時 に実行されるGS2-Script */
        optional<StringHolder> calculateRankingDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            rankingTableId(data.rankingTableId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            putScoreTriggerScript(data.putScoreTriggerScript),
            putScoreDoneTriggerScript(data.putScoreDoneTriggerScript),
            calculateRankingDoneTriggerScript(data.calculateRankingDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            rankingTableId(std::move(data.rankingTableId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            putScoreTriggerScript(std::move(data.putScoreTriggerScript)),
            putScoreDoneTriggerScript(std::move(data.putScoreDoneTriggerScript)),
            calculateRankingDoneTriggerScript(std::move(data.calculateRankingDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "rankingTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rankingTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "putScoreTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->putScoreTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "putScoreDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->putScoreDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "calculateRankingDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->calculateRankingDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    RankingTable() :
        m_pData(nullptr)
    {}

    RankingTable(const RankingTable& rankingTable) :
        Gs2Object(rankingTable),
        m_pData(rankingTable.m_pData != nullptr ? new Data(*rankingTable.m_pData) : nullptr)
    {}

    RankingTable(RankingTable&& rankingTable) :
        Gs2Object(std::move(rankingTable)),
        m_pData(rankingTable.m_pData)
    {
        rankingTable.m_pData = nullptr;
    }

    ~RankingTable()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RankingTable& operator=(const RankingTable& rankingTable)
    {
        Gs2Object::operator=(rankingTable);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*rankingTable.m_pData);

        return *this;
    }

    RankingTable& operator=(RankingTable&& rankingTable)
    {
        Gs2Object::operator=(std::move(rankingTable));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = rankingTable.m_pData;
        rankingTable.m_pData = nullptr;

        return *this;
    }

    const RankingTable* operator->() const
    {
        return this;
    }

    RankingTable* operator->()
    {
        return this;
    }


    /**
     * ランキングテーブルGRNを取得
     *
     * @return ランキングテーブルGRN
     */
    const optional<StringHolder>& getRankingTableId() const
    {
        return ensureData().rankingTableId;
    }

    /**
     * ランキングテーブルGRNを設定
     *
     * @param rankingTableId ランキングテーブルGRN
     */
    void setRankingTableId(const Char* rankingTableId)
    {
        ensureData().rankingTableId.emplace(rankingTableId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * ランキングテーブル名を取得
     *
     * @return ランキングテーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ランキングテーブル名を設定
     *
     * @param name ランキングテーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スコア登録時 に実行されるGS2-Scriptを取得
     *
     * @return スコア登録時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPutScoreTriggerScript() const
    {
        return ensureData().putScoreTriggerScript;
    }

    /**
     * スコア登録時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreTriggerScript スコア登録時 に実行されるGS2-Script
     */
    void setPutScoreTriggerScript(const Char* putScoreTriggerScript)
    {
        ensureData().putScoreTriggerScript.emplace(putScoreTriggerScript);
    }

    /**
     * スコア登録完了時 に実行されるGS2-Scriptを取得
     *
     * @return スコア登録完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPutScoreDoneTriggerScript() const
    {
        return ensureData().putScoreDoneTriggerScript;
    }

    /**
     * スコア登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreDoneTriggerScript スコア登録完了時 に実行されるGS2-Script
     */
    void setPutScoreDoneTriggerScript(const Char* putScoreDoneTriggerScript)
    {
        ensureData().putScoreDoneTriggerScript.emplace(putScoreDoneTriggerScript);
    }

    /**
     * 集計処理完了時 に実行されるGS2-Scriptを取得
     *
     * @return 集計処理完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCalculateRankingDoneTriggerScript() const
    {
        return ensureData().calculateRankingDoneTriggerScript;
    }

    /**
     * 集計処理完了時 に実行されるGS2-Scriptを設定
     *
     * @param calculateRankingDoneTriggerScript 集計処理完了時 に実行されるGS2-Script
     */
    void setCalculateRankingDoneTriggerScript(const Char* calculateRankingDoneTriggerScript)
    {
        ensureData().calculateRankingDoneTriggerScript.emplace(calculateRankingDoneTriggerScript);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_MODEL_RANKINGTABLE_HPP_