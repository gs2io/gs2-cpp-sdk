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

#ifndef GS2_MONEY_CONTROL_UPDATEMONEYRESULT_HPP_
#define GS2_MONEY_CONTROL_UPDATEMONEYRESULT_HPP_

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
 * 課金通貨を新規作成します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMoneyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した課金通貨 */
        optional<Money> item;

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
    UpdateMoneyResult() :
        m_pData(nullptr)
    {}

    UpdateMoneyResult(const UpdateMoneyResult& updateMoneyResult) :
        Gs2Object(updateMoneyResult),
        m_pData(updateMoneyResult.m_pData != nullptr ? new Data(*updateMoneyResult.m_pData) : nullptr)
    {}

    UpdateMoneyResult(UpdateMoneyResult&& updateMoneyResult) :
        Gs2Object(std::move(updateMoneyResult)),
        m_pData(updateMoneyResult.m_pData)
    {
        updateMoneyResult.m_pData = nullptr;
    }

    ~UpdateMoneyResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMoneyResult& operator=(const UpdateMoneyResult& updateMoneyResult)
    {
        Gs2Object::operator=(updateMoneyResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMoneyResult.m_pData);

        return *this;
    }

    UpdateMoneyResult& operator=(UpdateMoneyResult&& updateMoneyResult)
    {
        Gs2Object::operator=(std::move(updateMoneyResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMoneyResult.m_pData;
        updateMoneyResult.m_pData = nullptr;

        return *this;
    }

    const UpdateMoneyResult* operator->() const
    {
        return this;
    }

    UpdateMoneyResult* operator->()
    {
        return this;
    }
    /**
     * 更新した課金通貨を取得
     *
     * @return 更新した課金通貨
     */
    const optional<Money>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した課金通貨を設定
     *
     * @param item 更新した課金通貨
     */
    void setItem(const Money& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_CONTROL_UPDATEMONEYRESULT_HPP_