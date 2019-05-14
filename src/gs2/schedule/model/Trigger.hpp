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

#ifndef GS2_SCHEDULE_MODEL_TRIGGER_HPP_
#define GS2_SCHEDULE_MODEL_TRIGGER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * トリガー
 *
 * @author Game Server Services, Inc.
 *
 */
class Trigger : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** トリガー のGRN */
        optional<StringHolder> triggerId;
        /** トリガーの名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** None */
        
        optional<Int64> expiresAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            triggerId(data.triggerId),
            name(data.name),
            userId(data.userId),
            createAt(data.createAt),
            expiresAt(data.expiresAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            triggerId(std::move(data.triggerId)),
            name(std::move(data.name)),
            userId(std::move(data.userId)),
            createAt(std::move(data.createAt)),
            expiresAt(std::move(data.expiresAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "triggerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->triggerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "expiresAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->expiresAt = jsonValue.GetInt64();
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
    Trigger() :
        m_pData(nullptr)
    {}

    Trigger(const Trigger& trigger) :
        Gs2Object(trigger),
        m_pData(trigger.m_pData != nullptr ? new Data(*trigger.m_pData) : nullptr)
    {}

    Trigger(Trigger&& trigger) :
        Gs2Object(std::move(trigger)),
        m_pData(trigger.m_pData)
    {
        trigger.m_pData = nullptr;
    }

    ~Trigger()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Trigger& operator=(const Trigger& trigger)
    {
        Gs2Object::operator=(trigger);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*trigger.m_pData);

        return *this;
    }

    Trigger& operator=(Trigger&& trigger)
    {
        Gs2Object::operator=(std::move(trigger));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = trigger.m_pData;
        trigger.m_pData = nullptr;

        return *this;
    }

    const Trigger* operator->() const
    {
        return this;
    }

    Trigger* operator->()
    {
        return this;
    }
    /**
     * トリガー のGRNを取得
     *
     * @return トリガー のGRN
     */
    const optional<StringHolder>& getTriggerId() const
    {
        return ensureData().triggerId;
    }

    /**
     * トリガー のGRNを設定
     *
     * @param triggerId トリガー のGRN
     */
    void setTriggerId(const Char* triggerId)
    {
        ensureData().triggerId.emplace(triggerId);
    }

    /**
     * トリガーの名前を取得
     *
     * @return トリガーの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * トリガーの名前を設定
     *
     * @param name トリガーの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
     * Noneを取得
     *
     * @return None
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * Noneを設定
     *
     * @param expiresAt None
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_MODEL_TRIGGER_HPP_