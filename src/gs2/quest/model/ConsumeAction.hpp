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

#ifndef GS2_QUEST_MODEL_CONSUMEACTION_HPP_
#define GS2_QUEST_MODEL_CONSUMEACTION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * 消費アクション
 *
 * @author Game Server Services, Inc.
 *
 */
class ConsumeAction : public Gs2Object
{
    friend bool operator!=(const ConsumeAction& lhs, const ConsumeAction& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプタスクで実行するアクションの種類 */
        optional<StringHolder> action;
        /** 消費リクエストのJSON */
        optional<StringHolder> request;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            request(data.request)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            action(std::move(data.action)),
            request(std::move(data.request))
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
    ConsumeAction() :
        m_pData(nullptr)
    {}

    ConsumeAction(const ConsumeAction& consumeAction) :
        Gs2Object(consumeAction),
        m_pData(consumeAction.m_pData != nullptr ? new Data(*consumeAction.m_pData) : nullptr)
    {}

    ConsumeAction(ConsumeAction&& consumeAction) :
        Gs2Object(std::move(consumeAction)),
        m_pData(consumeAction.m_pData)
    {
        consumeAction.m_pData = nullptr;
    }

    ~ConsumeAction()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeAction& operator=(const ConsumeAction& consumeAction)
    {
        Gs2Object::operator=(consumeAction);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeAction.m_pData);

        return *this;
    }

    ConsumeAction& operator=(ConsumeAction&& consumeAction)
    {
        Gs2Object::operator=(std::move(consumeAction));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeAction.m_pData;
        consumeAction.m_pData = nullptr;

        return *this;
    }

    const ConsumeAction* operator->() const
    {
        return this;
    }

    ConsumeAction* operator->()
    {
        return this;
    }
    /**
     * スタンプタスクで実行するアクションの種類を取得
     *
     * @return スタンプタスクで実行するアクションの種類
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * スタンプタスクで実行するアクションの種類を設定
     *
     * @param action スタンプタスクで実行するアクションの種類
     */
    void setAction(const Char* action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * スタンプタスクで実行するアクションの種類を設定
     *
     * @param action スタンプタスクで実行するアクションの種類
     */
    ConsumeAction& withAction(const Char* action)
    {
        setAction(action);
        return *this;
    }

    /**
     * 消費リクエストのJSONを取得
     *
     * @return 消費リクエストのJSON
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * 消費リクエストのJSONを設定
     *
     * @param request 消費リクエストのJSON
     */
    void setRequest(const Char* request)
    {
        ensureData().request.emplace(request);
    }

    /**
     * 消費リクエストのJSONを設定
     *
     * @param request 消費リクエストのJSON
     */
    ConsumeAction& withRequest(const Char* request)
    {
        setRequest(request);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ConsumeAction& lhs, const ConsumeAction& lhr)
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
    }
    return false;
}

inline bool operator==(const ConsumeAction& lhs, const ConsumeAction& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_CONSUMEACTION_HPP_