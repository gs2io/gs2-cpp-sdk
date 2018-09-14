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

#ifndef GS2_STAMINA_MODEL_STAMINA_HPP_
#define GS2_STAMINA_MODEL_STAMINA_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナ
 *
 * @author Game Server Services, Inc.
 *
 */
class Stamina : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** スタミナ値 */
        optional<Int32> value;
        /** 最大値を超えて保持しているスタミナ値 */
        optional<Int32> overflow;
        /** 最終更新日時(エポック秒) */
        optional<Int32> lastUpdateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            value(data.value),
            overflow(data.overflow),
            lastUpdateAt(data.lastUpdateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            value(std::move(data.value)),
            overflow(std::move(data.overflow)),
            lastUpdateAt(std::move(data.lastUpdateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "overflow") == 0) {
                if (jsonValue.IsInt())
                {
                    this->overflow = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "lastUpdateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->lastUpdateAt = jsonValue.GetInt();
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
    Stamina() :
        m_pData(nullptr)
    {}

    Stamina(const Stamina& stamina) :
        Gs2Object(stamina),
        m_pData(stamina.m_pData != nullptr ? new Data(*stamina.m_pData) : nullptr)
    {}

    Stamina(Stamina&& stamina) :
        Gs2Object(std::move(stamina)),
        m_pData(stamina.m_pData)
    {
        stamina.m_pData = nullptr;
    }

    ~Stamina()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Stamina& operator=(const Stamina& stamina)
    {
        Gs2Object::operator=(stamina);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*stamina.m_pData);

        return *this;
    }

    Stamina& operator=(Stamina&& stamina)
    {
        Gs2Object::operator=(std::move(stamina));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = stamina.m_pData;
        stamina.m_pData = nullptr;

        return *this;
    }

    const Stamina* operator->() const
    {
        return this;
    }

    Stamina* operator->()
    {
        return this;
    }


    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * スタミナ値を取得
     *
     * @return スタミナ値
     */
    const optional<Int32>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * スタミナ値を設定
     *
     * @param value スタミナ値
     */
    void setValue(Int32 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 最大値を超えて保持しているスタミナ値を取得
     *
     * @return 最大値を超えて保持しているスタミナ値
     */
    const optional<Int32>& getOverflow() const
    {
        return ensureData().overflow;
    }

    /**
     * 最大値を超えて保持しているスタミナ値を設定
     *
     * @param overflow 最大値を超えて保持しているスタミナ値
     */
    void setOverflow(Int32 overflow)
    {
        ensureData().overflow.emplace(overflow);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getLastUpdateAt() const
    {
        return ensureData().lastUpdateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param lastUpdateAt 最終更新日時(エポック秒)
     */
    void setLastUpdateAt(Int32 lastUpdateAt)
    {
        ensureData().lastUpdateAt.emplace(lastUpdateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_MODEL_STAMINA_HPP_