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

#ifndef GS2_STAMINA_CONTROL_CONSUMESTAMINABYSTAMPTASKRESULT_HPP_
#define GS2_STAMINA_CONTROL_CONSUMESTAMINABYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタンプタスクを使用してスタミナを消費 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeStaminaByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            newContextStack(data.newContextStack)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            newContextStack(std::move(data.newContextStack))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "newContextStack") == 0) {
                if (jsonValue.IsString())
                {
                    this->newContextStack.emplace(jsonValue.GetString());
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
    ConsumeStaminaByStampTaskResult() :
        m_pData(nullptr)
    {}

    ConsumeStaminaByStampTaskResult(const ConsumeStaminaByStampTaskResult& consumeStaminaByStampTaskResult) :
        Gs2Object(consumeStaminaByStampTaskResult),
        m_pData(consumeStaminaByStampTaskResult.m_pData != nullptr ? new Data(*consumeStaminaByStampTaskResult.m_pData) : nullptr)
    {}

    ConsumeStaminaByStampTaskResult(ConsumeStaminaByStampTaskResult&& consumeStaminaByStampTaskResult) :
        Gs2Object(std::move(consumeStaminaByStampTaskResult)),
        m_pData(consumeStaminaByStampTaskResult.m_pData)
    {
        consumeStaminaByStampTaskResult.m_pData = nullptr;
    }

    ~ConsumeStaminaByStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeStaminaByStampTaskResult& operator=(const ConsumeStaminaByStampTaskResult& consumeStaminaByStampTaskResult)
    {
        Gs2Object::operator=(consumeStaminaByStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeStaminaByStampTaskResult.m_pData);

        return *this;
    }

    ConsumeStaminaByStampTaskResult& operator=(ConsumeStaminaByStampTaskResult&& consumeStaminaByStampTaskResult)
    {
        Gs2Object::operator=(std::move(consumeStaminaByStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeStaminaByStampTaskResult.m_pData;
        consumeStaminaByStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const ConsumeStaminaByStampTaskResult* operator->() const
    {
        return this;
    }

    ConsumeStaminaByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * スタミナを取得
     *
     * @return スタミナ
     */
    const optional<Stamina>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * スタミナを設定
     *
     * @param item スタミナ
     */
    void setItem(const Stamina& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを取得
     *
     * @return スタンプタスクの実行結果を記録したコンテキスト
     */
    const optional<StringHolder>& getNewContextStack() const
    {
        return ensureData().newContextStack;
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを設定
     *
     * @param newContextStack スタンプタスクの実行結果を記録したコンテキスト
     */
    void setNewContextStack(const Char* newContextStack)
    {
        ensureData().newContextStack.emplace(newContextStack);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CONSUMESTAMINABYSTAMPTASKRESULT_HPP_