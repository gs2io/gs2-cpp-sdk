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

#ifndef GS2_DEPLOY_MODEL_STACK_HPP_
#define GS2_DEPLOY_MODEL_STACK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * スタック
 *
 * @author Game Server Services, Inc.
 *
 */
class Stack : public Gs2Object
{
    friend bool operator!=(const Stack& lhs, const Stack& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタック */
        optional<StringHolder> stackId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** スタック名 */
        optional<StringHolder> name;
        /** スタックの説明 */
        optional<StringHolder> description;
        /** テンプレートデータ */
        optional<StringHolder> template_;
        /** 実行状態 */
        optional<StringHolder> status;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stackId(data.stackId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            template_(data.template_),
            status(data.status),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "stackId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stackId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "template") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->template_.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "status") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Stack() = default;
    Stack(const Stack& stack) = default;
    Stack(Stack&& stack) = default;
    ~Stack() = default;

    Stack& operator=(const Stack& stack) = default;
    Stack& operator=(Stack&& stack) = default;

    Stack deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Stack);
    }

    const Stack* operator->() const
    {
        return this;
    }

    Stack* operator->()
    {
        return this;
    }
    /**
     * スタックを取得
     *
     * @return スタック
     */
    const optional<StringHolder>& getStackId() const
    {
        return ensureData().stackId;
    }

    /**
     * スタックを設定
     *
     * @param stackId スタック
     */
    void setStackId(StringHolder stackId)
    {
        ensureData().stackId.emplace(std::move(stackId));
    }

    /**
     * スタックを設定
     *
     * @param stackId スタック
     */
    Stack& withStackId(StringHolder stackId)
    {
        setStackId(std::move(stackId));
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Stack& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    Stack& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * スタックの説明を取得
     *
     * @return スタックの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    Stack& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * テンプレートデータを取得
     *
     * @return テンプレートデータ
     */
    const optional<StringHolder>& getTemplate() const
    {
        return ensureData().template_;
    }

    /**
     * テンプレートデータを設定
     *
     * @param template_ テンプレートデータ
     */
    void setTemplate(StringHolder template_)
    {
        ensureData().template_.emplace(std::move(template_));
    }

    /**
     * テンプレートデータを設定
     *
     * @param template_ テンプレートデータ
     */
    Stack& withTemplate(StringHolder template_)
    {
        setTemplate(std::move(template_));
        return *this;
    }

    /**
     * 実行状態を取得
     *
     * @return 実行状態
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * 実行状態を設定
     *
     * @param status 実行状態
     */
    void setStatus(StringHolder status)
    {
        ensureData().status.emplace(std::move(status));
    }

    /**
     * 実行状態を設定
     *
     * @param status 実行状態
     */
    Stack& withStatus(StringHolder status)
    {
        setStatus(std::move(status));
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
    Stack& withCreatedAt(Int64 createdAt)
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
    Stack& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Stack& lhs, const Stack& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->template_ != lhr.m_pData->template_)
        {
            return true;
        }
        if (lhs.m_pData->status != lhr.m_pData->status)
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

inline bool operator==(const Stack& lhs, const Stack& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_STACK_HPP_