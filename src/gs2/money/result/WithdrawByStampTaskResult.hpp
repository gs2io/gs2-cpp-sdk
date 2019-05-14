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

#ifndef GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * ウォレットの概要から残高を消費します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後のウォレットの概要 */
        optional<Summary> item;
        /** スタンプシートの進捗を記録したコンテキスト */
        optional<StringHolder> contextStack;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            contextStack(data.contextStack)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            contextStack(std::move(data.contextStack))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "contextStack") == 0) {
                if (jsonValue.IsString())
                {
                    this->contextStack.emplace(jsonValue.GetString());
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
    WithdrawByStampTaskResult() :
        m_pData(nullptr)
    {}

    WithdrawByStampTaskResult(const WithdrawByStampTaskResult& withdrawByStampTaskResult) :
        Gs2Object(withdrawByStampTaskResult),
        m_pData(withdrawByStampTaskResult.m_pData != nullptr ? new Data(*withdrawByStampTaskResult.m_pData) : nullptr)
    {}

    WithdrawByStampTaskResult(WithdrawByStampTaskResult&& withdrawByStampTaskResult) :
        Gs2Object(std::move(withdrawByStampTaskResult)),
        m_pData(withdrawByStampTaskResult.m_pData)
    {
        withdrawByStampTaskResult.m_pData = nullptr;
    }

    ~WithdrawByStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawByStampTaskResult& operator=(const WithdrawByStampTaskResult& withdrawByStampTaskResult)
    {
        Gs2Object::operator=(withdrawByStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawByStampTaskResult.m_pData);

        return *this;
    }

    WithdrawByStampTaskResult& operator=(WithdrawByStampTaskResult&& withdrawByStampTaskResult)
    {
        Gs2Object::operator=(std::move(withdrawByStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawByStampTaskResult.m_pData;
        withdrawByStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const WithdrawByStampTaskResult* operator->() const
    {
        return this;
    }

    WithdrawByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * 消費後のウォレットの概要を取得
     *
     * @return 消費後のウォレットの概要
     */
    const optional<Summary>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 消費後のウォレットの概要を設定
     *
     * @param item 消費後のウォレットの概要
     */
    void setItem(const Summary& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * スタンプシートの進捗を記録したコンテキストを取得
     *
     * @return スタンプシートの進捗を記録したコンテキスト
     */
    const optional<StringHolder>& getContextStack() const
    {
        return ensureData().contextStack;
    }

    /**
     * スタンプシートの進捗を記録したコンテキストを設定
     *
     * @param contextStack スタンプシートの進捗を記録したコンテキスト
     */
    void setContextStack(const Char* contextStack)
    {
        ensureData().contextStack.emplace(contextStack);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_