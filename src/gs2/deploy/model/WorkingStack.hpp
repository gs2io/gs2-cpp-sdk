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

#ifndef GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_
#define GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * 実行中のスタック
 *
 * @author Game Server Services, Inc.
 *
 */
class WorkingStack : public Gs2Object
{
    friend bool operator!=(const WorkingStack& lhs, const WorkingStack& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 実行中のスタック */
        optional<StringHolder> stackId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 実行中のスタック名 */
        optional<StringHolder> name;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            stackId(data.stackId),
            ownerId(data.ownerId),
            name(data.name),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            stackId(std::move(data.stackId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "stackId") == 0) {
                if (jsonValue.IsString())
                {
                    this->stackId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
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
    WorkingStack() :
        m_pData(nullptr)
    {}

    WorkingStack(const WorkingStack& workingStack) :
        Gs2Object(workingStack),
        m_pData(workingStack.m_pData != nullptr ? new Data(*workingStack.m_pData) : nullptr)
    {}

    WorkingStack(WorkingStack&& workingStack) :
        Gs2Object(std::move(workingStack)),
        m_pData(workingStack.m_pData)
    {
        workingStack.m_pData = nullptr;
    }

    ~WorkingStack()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WorkingStack& operator=(const WorkingStack& workingStack)
    {
        Gs2Object::operator=(workingStack);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*workingStack.m_pData);

        return *this;
    }

    WorkingStack& operator=(WorkingStack&& workingStack)
    {
        Gs2Object::operator=(std::move(workingStack));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = workingStack.m_pData;
        workingStack.m_pData = nullptr;

        return *this;
    }

    const WorkingStack* operator->() const
    {
        return this;
    }

    WorkingStack* operator->()
    {
        return this;
    }
    /**
     * 実行中のスタックを取得
     *
     * @return 実行中のスタック
     */
    const optional<StringHolder>& getStackId() const
    {
        return ensureData().stackId;
    }

    /**
     * 実行中のスタックを設定
     *
     * @param stackId 実行中のスタック
     */
    void setStackId(const Char* stackId)
    {
        ensureData().stackId.emplace(stackId);
    }

    /**
     * 実行中のスタックを設定
     *
     * @param stackId 実行中のスタック
     */
    WorkingStack& withStackId(const Char* stackId)
    {
        setStackId(stackId);
        return *this;
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
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    WorkingStack& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * 実行中のスタック名を取得
     *
     * @return 実行中のスタック名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 実行中のスタック名を設定
     *
     * @param name 実行中のスタック名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 実行中のスタック名を設定
     *
     * @param name 実行中のスタック名
     */
    WorkingStack& withName(const Char* name)
    {
        setName(name);
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
    WorkingStack& withCreatedAt(Int64 createdAt)
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
    WorkingStack& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WorkingStack& lhs, const WorkingStack& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->stackId != lhr.m_pData->stackId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
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

inline bool operator==(const WorkingStack& lhs, const WorkingStack& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_WORKINGSTACK_HPP_