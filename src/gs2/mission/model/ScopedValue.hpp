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

#ifndef GS2_MISSION_MODEL_SCOPEDVALUE_HPP_
#define GS2_MISSION_MODEL_SCOPEDVALUE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace mission {

/**
 * リセットタイミングまでの期間のカウンター値
 *
 * @author Game Server Services, Inc.
 *
 */
class ScopedValue : public Gs2Object
{
    friend bool operator!=(const ScopedValue& lhs, const ScopedValue& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** カウント */
        optional<Int64> value;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            resetType(data.resetType),
            value(data.value),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            resetType(std::move(data.resetType)),
            value(std::move(data.value)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "resetType") == 0) {
                if (jsonValue.IsString())
                {
                    this->resetType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->value = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    ScopedValue() :
        m_pData(nullptr)
    {}

    ScopedValue(const ScopedValue& scopedValue) :
        Gs2Object(scopedValue),
        m_pData(scopedValue.m_pData != nullptr ? new Data(*scopedValue.m_pData) : nullptr)
    {}

    ScopedValue(ScopedValue&& scopedValue) :
        Gs2Object(std::move(scopedValue)),
        m_pData(scopedValue.m_pData)
    {
        scopedValue.m_pData = nullptr;
    }

    ~ScopedValue()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ScopedValue& operator=(const ScopedValue& scopedValue)
    {
        Gs2Object::operator=(scopedValue);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*scopedValue.m_pData);

        return *this;
    }

    ScopedValue& operator=(ScopedValue&& scopedValue)
    {
        Gs2Object::operator=(std::move(scopedValue));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = scopedValue.m_pData;
        scopedValue.m_pData = nullptr;

        return *this;
    }

    const ScopedValue* operator->() const
    {
        return this;
    }

    ScopedValue* operator->()
    {
        return this;
    }
    /**
     * リセットタイミングを取得
     *
     * @return リセットタイミング
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    ScopedValue& withResetType(const Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    /**
     * カウントを取得
     *
     * @return カウント
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * カウントを設定
     *
     * @param value カウント
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * カウントを設定
     *
     * @param value カウント
     */
    ScopedValue& withValue(Int64 value)
    {
        setValue(value);
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
    ScopedValue& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ScopedValue& lhs, const ScopedValue& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->resetType != lhr.m_pData->resetType)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
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

bool operator==(const ScopedValue& lhs, const ScopedValue& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_SCOPEDVALUE_HPP_