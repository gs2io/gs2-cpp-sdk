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

#ifndef GS2_QUEST_MODEL_REWARD_HPP_
#define GS2_QUEST_MODEL_REWARD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クリア報酬
 *
 * @author Game Server Services, Inc.
 *
 */
class Reward : public Gs2Object
{
    friend bool operator!=(const Reward& lhs, const Reward& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプシートで実行するアクションの種類 */
        optional<StringHolder> action;
        /** リクエストモデル */
        optional<StringHolder> request;
        /** 入手するリソースGRN */
        optional<StringHolder> itemId;
        /** 入手する数量 */
        optional<Int32> value;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            request(data.request),
            itemId(data.itemId),
            value(data.value)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            action(std::move(data.action)),
            request(std::move(data.request)),
            itemId(std::move(data.itemId)),
            value(std::move(data.value))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "action") == 0) {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "request") == 0) {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
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
    Reward() :
        m_pData(nullptr)
    {}

    Reward(const Reward& reward) :
        Gs2Object(reward),
        m_pData(reward.m_pData != nullptr ? new Data(*reward.m_pData) : nullptr)
    {}

    Reward(Reward&& reward) :
        Gs2Object(std::move(reward)),
        m_pData(reward.m_pData)
    {
        reward.m_pData = nullptr;
    }

    ~Reward()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Reward& operator=(const Reward& reward)
    {
        Gs2Object::operator=(reward);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*reward.m_pData);

        return *this;
    }

    Reward& operator=(Reward&& reward)
    {
        Gs2Object::operator=(std::move(reward));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = reward.m_pData;
        reward.m_pData = nullptr;

        return *this;
    }

    const Reward* operator->() const
    {
        return this;
    }

    Reward* operator->()
    {
        return this;
    }
    /**
     * スタンプシートで実行するアクションの種類を取得
     *
     * @return スタンプシートで実行するアクションの種類
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    void setAction(const Char* action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    Reward& withAction(const Char* action)
    {
        setAction(action);
        return *this;
    }

    /**
     * リクエストモデルを取得
     *
     * @return リクエストモデル
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * リクエストモデルを設定
     *
     * @param request リクエストモデル
     */
    void setRequest(const Char* request)
    {
        ensureData().request.emplace(request);
    }

    /**
     * リクエストモデルを設定
     *
     * @param request リクエストモデル
     */
    Reward& withRequest(const Char* request)
    {
        setRequest(request);
        return *this;
    }

    /**
     * 入手するリソースGRNを取得
     *
     * @return 入手するリソースGRN
     */
    const optional<StringHolder>& getItemId() const
    {
        return ensureData().itemId;
    }

    /**
     * 入手するリソースGRNを設定
     *
     * @param itemId 入手するリソースGRN
     */
    void setItemId(const Char* itemId)
    {
        ensureData().itemId.emplace(itemId);
    }

    /**
     * 入手するリソースGRNを設定
     *
     * @param itemId 入手するリソースGRN
     */
    Reward& withItemId(const Char* itemId)
    {
        setItemId(itemId);
        return *this;
    }

    /**
     * 入手する数量を取得
     *
     * @return 入手する数量
     */
    const optional<Int32>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 入手する数量を設定
     *
     * @param value 入手する数量
     */
    void setValue(Int32 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 入手する数量を設定
     *
     * @param value 入手する数量
     */
    Reward& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Reward& lhs, const Reward& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->action != lhr.m_pData->action)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
        {
            return true;
        }
        if (lhs.m_pData->itemId != lhr.m_pData->itemId)
        {
            return true;
        }
        if (lhs.m_pData->value != lhr.m_pData->value)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Reward& lhs, const Reward& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_REWARD_HPP_