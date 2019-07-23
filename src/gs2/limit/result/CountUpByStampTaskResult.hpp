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

#ifndef GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_
#define GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * スタンプシートでカウントアップ のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CountUpByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウントを増やしたカウンター */
        optional<Counter> item;
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
                    const auto& jsonObject = jsonValue.GetObject();
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
    CountUpByStampTaskResult() :
        m_pData(nullptr)
    {}

    CountUpByStampTaskResult(const CountUpByStampTaskResult& countUpByStampTaskResult) :
        Gs2Object(countUpByStampTaskResult),
        m_pData(countUpByStampTaskResult.m_pData != nullptr ? new Data(*countUpByStampTaskResult.m_pData) : nullptr)
    {}

    CountUpByStampTaskResult(CountUpByStampTaskResult&& countUpByStampTaskResult) :
        Gs2Object(std::move(countUpByStampTaskResult)),
        m_pData(countUpByStampTaskResult.m_pData)
    {
        countUpByStampTaskResult.m_pData = nullptr;
    }

    ~CountUpByStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CountUpByStampTaskResult& operator=(const CountUpByStampTaskResult& countUpByStampTaskResult)
    {
        Gs2Object::operator=(countUpByStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*countUpByStampTaskResult.m_pData);

        return *this;
    }

    CountUpByStampTaskResult& operator=(CountUpByStampTaskResult&& countUpByStampTaskResult)
    {
        Gs2Object::operator=(std::move(countUpByStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = countUpByStampTaskResult.m_pData;
        countUpByStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const CountUpByStampTaskResult* operator->() const
    {
        return this;
    }

    CountUpByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * カウントを増やしたカウンターを取得
     *
     * @return カウントを増やしたカウンター
     */
    const optional<Counter>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * カウントを増やしたカウンターを設定
     *
     * @param item カウントを増やしたカウンター
     */
    void setItem(const Counter& item)
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

#endif //GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_