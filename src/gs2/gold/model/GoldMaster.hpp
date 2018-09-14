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

#ifndef GS2_GOLD_MODEL_GOLDMASTER_HPP_
#define GS2_GOLD_MODEL_GOLDMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gold {

/**
 * ゴールド
 *
 * @author Game Server Services, Inc.
 *
 */
class GoldMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゴールドGRN */
        optional<StringHolder> goldId;
        /** ゴールド名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 各ウォレットの残高の最大値 */
        optional<Int64> balanceMax;
        /** 取得量の期間制限のタイプ */
        optional<StringHolder> resetType;
        /** 期間内の取得量をリセットする日にち */
        optional<Int32> resetDayOfMonth;
        /** 期間内の取得量をリセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** 期間内の取得量をリセットする時 */
        optional<Int32> resetHour;
        /** 期間内の最大取得量 */
        optional<Int64> latestGainMax;
        /** ウォレットの生成時 に実行されるGS2-Script */
        optional<StringHolder> createWalletTriggerScript;
        /** ウォレットの生成完了時 に実行されるGS2-Script */
        optional<StringHolder> createWalletDoneTriggerScript;
        /** ウォレットへの加算時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletTriggerScript;
        /** ウォレットへの加算完了時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletDoneTriggerScript;
        /** ウォレットからの減算時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletTriggerScript;
        /** ウォレットからの減算完了時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            goldId(data.goldId),
            name(data.name),
            meta(data.meta),
            balanceMax(data.balanceMax),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            latestGainMax(data.latestGainMax),
            createWalletTriggerScript(data.createWalletTriggerScript),
            createWalletDoneTriggerScript(data.createWalletDoneTriggerScript),
            depositIntoWalletTriggerScript(data.depositIntoWalletTriggerScript),
            depositIntoWalletDoneTriggerScript(data.depositIntoWalletDoneTriggerScript),
            withdrawFromWalletTriggerScript(data.withdrawFromWalletTriggerScript),
            withdrawFromWalletDoneTriggerScript(data.withdrawFromWalletDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            goldId(std::move(data.goldId)),
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            balanceMax(std::move(data.balanceMax)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour)),
            latestGainMax(std::move(data.latestGainMax)),
            createWalletTriggerScript(std::move(data.createWalletTriggerScript)),
            createWalletDoneTriggerScript(std::move(data.createWalletDoneTriggerScript)),
            depositIntoWalletTriggerScript(std::move(data.depositIntoWalletTriggerScript)),
            depositIntoWalletDoneTriggerScript(std::move(data.depositIntoWalletDoneTriggerScript)),
            withdrawFromWalletTriggerScript(std::move(data.withdrawFromWalletTriggerScript)),
            withdrawFromWalletDoneTriggerScript(std::move(data.withdrawFromWalletDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "goldId") == 0) {
                if (jsonValue.IsString())
                {
                    this->goldId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balanceMax") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->balanceMax = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "resetType") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetDayOfMonth") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetDayOfMonth = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "resetDayOfWeek") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetDayOfWeek.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "resetHour") == 0) {
                if (jsonValue.IsInt())
                {
                    this->resetHour = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "latestGainMax") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->latestGainMax = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "createWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositIntoWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositIntoWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositIntoWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositIntoWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawFromWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawFromWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawFromWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawFromWalletDoneTriggerScript.emplace(jsonValue.GetString());
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
    GoldMaster() :
        m_pData(nullptr)
    {}

    GoldMaster(const GoldMaster& goldMaster) :
        Gs2Object(goldMaster),
        m_pData(goldMaster.m_pData != nullptr ? new Data(*goldMaster.m_pData) : nullptr)
    {}

    GoldMaster(GoldMaster&& goldMaster) :
        Gs2Object(std::move(goldMaster)),
        m_pData(goldMaster.m_pData)
    {
        goldMaster.m_pData = nullptr;
    }

    ~GoldMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GoldMaster& operator=(const GoldMaster& goldMaster)
    {
        Gs2Object::operator=(goldMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*goldMaster.m_pData);

        return *this;
    }

    GoldMaster& operator=(GoldMaster&& goldMaster)
    {
        Gs2Object::operator=(std::move(goldMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = goldMaster.m_pData;
        goldMaster.m_pData = nullptr;

        return *this;
    }

    const GoldMaster* operator->() const
    {
        return this;
    }

    GoldMaster* operator->()
    {
        return this;
    }


    /**
     * ゴールドGRNを取得
     *
     * @return ゴールドGRN
     */
    const optional<StringHolder>& getGoldId() const
    {
        return ensureData().goldId;
    }

    /**
     * ゴールドGRNを設定
     *
     * @param goldId ゴールドGRN
     */
    void setGoldId(const Char* goldId)
    {
        ensureData().goldId.emplace(goldId);
    }

    /**
     * ゴールド名を取得
     *
     * @return ゴールド名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ゴールド名を設定
     *
     * @param name ゴールド名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 各ウォレットの残高の最大値を取得
     *
     * @return 各ウォレットの残高の最大値
     */
    const optional<Int64>& getBalanceMax() const
    {
        return ensureData().balanceMax;
    }

    /**
     * 各ウォレットの残高の最大値を設定
     *
     * @param balanceMax 各ウォレットの残高の最大値
     */
    void setBalanceMax(Int64 balanceMax)
    {
        ensureData().balanceMax.emplace(balanceMax);
    }

    /**
     * 取得量の期間制限のタイプを取得
     *
     * @return 取得量の期間制限のタイプ
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * 取得量の期間制限のタイプを設定
     *
     * @param resetType 取得量の期間制限のタイプ
     */
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * 期間内の取得量をリセットする日にちを取得
     *
     * @return 期間内の取得量をリセットする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * 期間内の取得量をリセットする日にちを設定
     *
     * @param resetDayOfMonth 期間内の取得量をリセットする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * 期間内の取得量をリセットする曜日を取得
     *
     * @return 期間内の取得量をリセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * 期間内の取得量をリセットする曜日を設定
     *
     * @param resetDayOfWeek 期間内の取得量をリセットする曜日
     */
    void setResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
    }

    /**
     * 期間内の取得量をリセットする時を取得
     *
     * @return 期間内の取得量をリセットする時
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * 期間内の取得量をリセットする時を設定
     *
     * @param resetHour 期間内の取得量をリセットする時
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * 期間内の最大取得量を取得
     *
     * @return 期間内の最大取得量
     */
    const optional<Int64>& getLatestGainMax() const
    {
        return ensureData().latestGainMax;
    }

    /**
     * 期間内の最大取得量を設定
     *
     * @param latestGainMax 期間内の最大取得量
     */
    void setLatestGainMax(Int64 latestGainMax)
    {
        ensureData().latestGainMax.emplace(latestGainMax);
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletTriggerScript() const
    {
        return ensureData().createWalletTriggerScript;
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレットの生成時 に実行されるGS2-Script
     */
    void setCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerScript() const
    {
        return ensureData().createWalletDoneTriggerScript;
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレットの生成完了時 に実行されるGS2-Script
     */
    void setCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletTriggerScript() const
    {
        return ensureData().depositIntoWalletTriggerScript;
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletTriggerScript ウォレットへの加算時 に実行されるGS2-Script
     */
    void setDepositIntoWalletTriggerScript(const Char* depositIntoWalletTriggerScript)
    {
        ensureData().depositIntoWalletTriggerScript.emplace(depositIntoWalletTriggerScript);
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletDoneTriggerScript() const
    {
        return ensureData().depositIntoWalletDoneTriggerScript;
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletDoneTriggerScript ウォレットへの加算完了時 に実行されるGS2-Script
     */
    void setDepositIntoWalletDoneTriggerScript(const Char* depositIntoWalletDoneTriggerScript)
    {
        ensureData().depositIntoWalletDoneTriggerScript.emplace(depositIntoWalletDoneTriggerScript);
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletTriggerScript() const
    {
        return ensureData().withdrawFromWalletTriggerScript;
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletTriggerScript ウォレットからの減算時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletTriggerScript(const Char* withdrawFromWalletTriggerScript)
    {
        ensureData().withdrawFromWalletTriggerScript.emplace(withdrawFromWalletTriggerScript);
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletDoneTriggerScript() const
    {
        return ensureData().withdrawFromWalletDoneTriggerScript;
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletDoneTriggerScript ウォレットからの減算完了時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletDoneTriggerScript(const Char* withdrawFromWalletDoneTriggerScript)
    {
        ensureData().withdrawFromWalletDoneTriggerScript.emplace(withdrawFromWalletDoneTriggerScript);
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

#endif //GS2_GOLD_MODEL_GOLDMASTER_HPP_