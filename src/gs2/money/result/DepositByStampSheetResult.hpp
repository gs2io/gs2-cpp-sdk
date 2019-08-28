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

#ifndef GS2_MONEY_CONTROL_DEPOSITBYSTAMPSHEETRESULT_HPP_
#define GS2_MONEY_CONTROL_DEPOSITBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * スタンプシートを使用してウォレットに残高を加算します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DepositByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 加算後のウォレット */
        optional<Wallet> item;

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
    DepositByStampSheetResult() :
        m_pData(nullptr)
    {}

    DepositByStampSheetResult(const DepositByStampSheetResult& depositByStampSheetResult) :
        Gs2Object(depositByStampSheetResult),
        m_pData(depositByStampSheetResult.m_pData != nullptr ? new Data(*depositByStampSheetResult.m_pData) : nullptr)
    {}

    DepositByStampSheetResult(DepositByStampSheetResult&& depositByStampSheetResult) :
        Gs2Object(std::move(depositByStampSheetResult)),
        m_pData(depositByStampSheetResult.m_pData)
    {
        depositByStampSheetResult.m_pData = nullptr;
    }

    ~DepositByStampSheetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DepositByStampSheetResult& operator=(const DepositByStampSheetResult& depositByStampSheetResult)
    {
        Gs2Object::operator=(depositByStampSheetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*depositByStampSheetResult.m_pData);

        return *this;
    }

    DepositByStampSheetResult& operator=(DepositByStampSheetResult&& depositByStampSheetResult)
    {
        Gs2Object::operator=(std::move(depositByStampSheetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = depositByStampSheetResult.m_pData;
        depositByStampSheetResult.m_pData = nullptr;

        return *this;
    }

    const DepositByStampSheetResult* operator->() const
    {
        return this;
    }

    DepositByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 加算後のウォレットを取得
     *
     * @return 加算後のウォレット
     */
    const optional<Wallet>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 加算後のウォレットを設定
     *
     * @param item 加算後のウォレット
     */
    void setItem(const Wallet& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DepositByStampSheetResult> AsyncDepositByStampSheetResult;

} }

#endif //GS2_MONEY_CONTROL_DEPOSITBYSTAMPSHEETRESULT_HPP_