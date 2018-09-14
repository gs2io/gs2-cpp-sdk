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

#ifndef GS2_GOLD_MODEL_WALLETSETTINGS_HPP_
#define GS2_GOLD_MODEL_WALLETSETTINGS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gold {

/**
 * ウォレット設定
 *
 * @author Game Server Services, Inc.
 *
 */
class WalletSettings : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゴールド名 */
        optional<StringHolder> goldName;
        /** 各ウォレットの残高の最大値 */
        optional<Int64> balanceMax;
        /** メタデータ */
        optional<StringHolder> meta;
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            goldName(data.goldName),
            balanceMax(data.balanceMax),
            meta(data.meta),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            latestGainMax(data.latestGainMax)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            goldName(std::move(data.goldName)),
            balanceMax(std::move(data.balanceMax)),
            meta(std::move(data.meta)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour)),
            latestGainMax(std::move(data.latestGainMax))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "goldName") == 0) {
                if (jsonValue.IsString())
                {
                    this->goldName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balanceMax") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->balanceMax = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
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
    WalletSettings() :
        m_pData(nullptr)
    {}

    WalletSettings(const WalletSettings& walletSettings) :
        Gs2Object(walletSettings),
        m_pData(walletSettings.m_pData != nullptr ? new Data(*walletSettings.m_pData) : nullptr)
    {}

    WalletSettings(WalletSettings&& walletSettings) :
        Gs2Object(std::move(walletSettings)),
        m_pData(walletSettings.m_pData)
    {
        walletSettings.m_pData = nullptr;
    }

    ~WalletSettings()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WalletSettings& operator=(const WalletSettings& walletSettings)
    {
        Gs2Object::operator=(walletSettings);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*walletSettings.m_pData);

        return *this;
    }

    WalletSettings& operator=(WalletSettings&& walletSettings)
    {
        Gs2Object::operator=(std::move(walletSettings));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = walletSettings.m_pData;
        walletSettings.m_pData = nullptr;

        return *this;
    }

    const WalletSettings* operator->() const
    {
        return this;
    }

    WalletSettings* operator->()
    {
        return this;
    }


    /**
     * ゴールド名を取得
     *
     * @return ゴールド名
     */
    const optional<StringHolder>& getGoldName() const
    {
        return ensureData().goldName;
    }

    /**
     * ゴールド名を設定
     *
     * @param goldName ゴールド名
     */
    void setGoldName(const Char* goldName)
    {
        ensureData().goldName.emplace(goldName);
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GOLD_MODEL_WALLETSETTINGS_HPP_