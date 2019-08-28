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

#ifndef GS2_LIMIT_CONTROL_COUNTUPBYUSERIDRESULT_HPP_
#define GS2_LIMIT_CONTROL_COUNTUPBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * ユーザIDを指定してカウントアップ のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CountUpByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウントを増やしたカウンター */
        optional<Counter> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    CountUpByUserIdResult() :
        m_pData(nullptr)
    {}

    CountUpByUserIdResult(const CountUpByUserIdResult& countUpByUserIdResult) :
        Gs2Object(countUpByUserIdResult),
        m_pData(countUpByUserIdResult.m_pData != nullptr ? new Data(*countUpByUserIdResult.m_pData) : nullptr)
    {}

    CountUpByUserIdResult(CountUpByUserIdResult&& countUpByUserIdResult) :
        Gs2Object(std::move(countUpByUserIdResult)),
        m_pData(countUpByUserIdResult.m_pData)
    {
        countUpByUserIdResult.m_pData = nullptr;
    }

    ~CountUpByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CountUpByUserIdResult& operator=(const CountUpByUserIdResult& countUpByUserIdResult)
    {
        Gs2Object::operator=(countUpByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*countUpByUserIdResult.m_pData);

        return *this;
    }

    CountUpByUserIdResult& operator=(CountUpByUserIdResult&& countUpByUserIdResult)
    {
        Gs2Object::operator=(std::move(countUpByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = countUpByUserIdResult.m_pData;
        countUpByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const CountUpByUserIdResult* operator->() const
    {
        return this;
    }

    CountUpByUserIdResult* operator->()
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CountUpByUserIdResult> AsyncCountUpByUserIdResult;

} }

#endif //GS2_LIMIT_CONTROL_COUNTUPBYUSERIDRESULT_HPP_