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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            request(data.request),
            itemId(data.itemId),
            value(data.value)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "action") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "request") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "itemId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->itemId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "value") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->value = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Reward() = default;
    Reward(const Reward& reward) = default;
    Reward(Reward&& reward) = default;
    ~Reward() = default;

    Reward& operator=(const Reward& reward) = default;
    Reward& operator=(Reward&& reward) = default;

    Reward deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Reward);
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
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * スタンプシートで実行するアクションの種類を設定
     *
     * @param action スタンプシートで実行するアクションの種類
     */
    Reward& withAction(StringHolder action)
    {
        setAction(std::move(action));
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
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * リクエストモデルを設定
     *
     * @param request リクエストモデル
     */
    Reward& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
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
    void setItemId(StringHolder itemId)
    {
        ensureData().itemId.emplace(std::move(itemId));
    }

    /**
     * 入手するリソースGRNを設定
     *
     * @param itemId 入手するリソースGRN
     */
    Reward& withItemId(StringHolder itemId)
    {
        setItemId(std::move(itemId));
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

inline bool operator!=(const Reward& lhs, const Reward& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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

inline bool operator==(const Reward& lhs, const Reward& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_REWARD_HPP_