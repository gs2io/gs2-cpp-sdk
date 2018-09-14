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

#ifndef GS2_LIMIT_MODEL_COUNTERMASTER_HPP_
#define GS2_LIMIT_MODEL_COUNTERMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace limit {

/**
 * カウンターマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class CounterMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウンターマスターGRN */
        optional<StringHolder> counterMasterId;
        /** カウンターマスター名 */
        optional<StringHolder> name;
        /** カウンターの最大値 */
        optional<Int32> max;
        /** リセット周期 */
        optional<StringHolder> resetType;
        /** 期間内の取得量をリセットする日にち */
        optional<Int32> resetDayOfMonth;
        /** 期間内の取得量をリセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** 期間内の取得量をリセットする時 */
        optional<Int32> resetHour;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            counterMasterId(data.counterMasterId),
            name(data.name),
            max(data.max),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            counterMasterId(std::move(data.counterMasterId)),
            name(std::move(data.name)),
            max(std::move(data.max)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "counterMasterId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterMasterId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "max") == 0) {
                if (jsonValue.IsInt())
                {
                    this->max = jsonValue.GetInt();
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
    CounterMaster() :
        m_pData(nullptr)
    {}

    CounterMaster(const CounterMaster& counterMaster) :
        Gs2Object(counterMaster),
        m_pData(counterMaster.m_pData != nullptr ? new Data(*counterMaster.m_pData) : nullptr)
    {}

    CounterMaster(CounterMaster&& counterMaster) :
        Gs2Object(std::move(counterMaster)),
        m_pData(counterMaster.m_pData)
    {
        counterMaster.m_pData = nullptr;
    }

    ~CounterMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CounterMaster& operator=(const CounterMaster& counterMaster)
    {
        Gs2Object::operator=(counterMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*counterMaster.m_pData);

        return *this;
    }

    CounterMaster& operator=(CounterMaster&& counterMaster)
    {
        Gs2Object::operator=(std::move(counterMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = counterMaster.m_pData;
        counterMaster.m_pData = nullptr;

        return *this;
    }

    const CounterMaster* operator->() const
    {
        return this;
    }

    CounterMaster* operator->()
    {
        return this;
    }


    /**
     * カウンターマスターGRNを取得
     *
     * @return カウンターマスターGRN
     */
    const optional<StringHolder>& getCounterMasterId() const
    {
        return ensureData().counterMasterId;
    }

    /**
     * カウンターマスターGRNを設定
     *
     * @param counterMasterId カウンターマスターGRN
     */
    void setCounterMasterId(const Char* counterMasterId)
    {
        ensureData().counterMasterId.emplace(counterMasterId);
    }

    /**
     * カウンターマスター名を取得
     *
     * @return カウンターマスター名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カウンターマスター名を設定
     *
     * @param name カウンターマスター名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カウンターの最大値を取得
     *
     * @return カウンターの最大値
     */
    const optional<Int32>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * カウンターの最大値を設定
     *
     * @param max カウンターの最大値
     */
    void setMax(Int32 max)
    {
        ensureData().max.emplace(max);
    }

    /**
     * リセット周期を取得
     *
     * @return リセット周期
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセット周期を設定
     *
     * @param resetType リセット周期
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

#endif //GS2_LIMIT_MODEL_COUNTERMASTER_HPP_