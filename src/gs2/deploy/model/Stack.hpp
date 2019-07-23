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
#include <gs2/core/external/optional/optional.hpp>
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
        optional<StringHolder> template;
        /** 実行状態 */
        optional<StringHolder> status;
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
            description(data.description),
            template(data.template),
            status(data.status),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            stackId(std::move(data.stackId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            template(std::move(data.template)),
            status(std::move(data.status)),
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "template") == 0) {
                if (jsonValue.IsString())
                {
                    this->template.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "status") == 0) {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
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
    Stack() :
        m_pData(nullptr)
    {}

    Stack(const Stack& stack) :
        Gs2Object(stack),
        m_pData(stack.m_pData != nullptr ? new Data(*stack.m_pData) : nullptr)
    {}

    Stack(Stack&& stack) :
        Gs2Object(std::move(stack)),
        m_pData(stack.m_pData)
    {
        stack.m_pData = nullptr;
    }

    ~Stack()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Stack& operator=(const Stack& stack)
    {
        Gs2Object::operator=(stack);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*stack.m_pData);

        return *this;
    }

    Stack& operator=(Stack&& stack)
    {
        Gs2Object::operator=(std::move(stack));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = stack.m_pData;
        stack.m_pData = nullptr;

        return *this;
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
    void setStackId(const Char* stackId)
    {
        ensureData().stackId.emplace(stackId);
    }

    /**
     * スタックを設定
     *
     * @param stackId スタック
     */
    Stack& withStackId(const Char* stackId)
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
    Stack& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    Stack& withName(const Char* name)
    {
        setName(name);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    Stack& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * テンプレートデータを取得
     *
     * @return テンプレートデータ
     */
    const optional<StringHolder>& getTemplate() const
    {
        return ensureData().template;
    }

    /**
     * テンプレートデータを設定
     *
     * @param template テンプレートデータ
     */
    void setTemplate(const Char* template)
    {
        ensureData().template.emplace(template);
    }

    /**
     * テンプレートデータを設定
     *
     * @param template テンプレートデータ
     */
    Stack& withTemplate(const Char* template)
    {
        setTemplate(template);
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
    void setStatus(const Char* status)
    {
        ensureData().status.emplace(status);
    }

    /**
     * 実行状態を設定
     *
     * @param status 実行状態
     */
    Stack& withStatus(const Char* status)
    {
        setStatus(status);
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

bool operator!=(const Stack& lhs, const Stack& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->template != lhr.m_pData->template)
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

bool operator==(const Stack& lhs, const Stack& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_STACK_HPP_