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

#ifndef GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * 抽選の種類の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeLotteryModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選の種類のリスト */
        optional<List<LotteryModel>> items;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        LotteryModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
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
    DescribeLotteryModelsResult() :
        m_pData(nullptr)
    {}

    DescribeLotteryModelsResult(const DescribeLotteryModelsResult& describeLotteryModelsResult) :
        Gs2Object(describeLotteryModelsResult),
        m_pData(describeLotteryModelsResult.m_pData != nullptr ? new Data(*describeLotteryModelsResult.m_pData) : nullptr)
    {}

    DescribeLotteryModelsResult(DescribeLotteryModelsResult&& describeLotteryModelsResult) :
        Gs2Object(std::move(describeLotteryModelsResult)),
        m_pData(describeLotteryModelsResult.m_pData)
    {
        describeLotteryModelsResult.m_pData = nullptr;
    }

    ~DescribeLotteryModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeLotteryModelsResult& operator=(const DescribeLotteryModelsResult& describeLotteryModelsResult)
    {
        Gs2Object::operator=(describeLotteryModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeLotteryModelsResult.m_pData);

        return *this;
    }

    DescribeLotteryModelsResult& operator=(DescribeLotteryModelsResult&& describeLotteryModelsResult)
    {
        Gs2Object::operator=(std::move(describeLotteryModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeLotteryModelsResult.m_pData;
        describeLotteryModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeLotteryModelsResult* operator->() const
    {
        return this;
    }

    DescribeLotteryModelsResult* operator->()
    {
        return this;
    }
    /**
     * 抽選の種類のリストを取得
     *
     * @return 抽選の種類のリスト
     */
    const optional<List<LotteryModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 抽選の種類のリストを設定
     *
     * @param items 抽選の種類のリスト
     */
    void setItems(const List<LotteryModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_DESCRIBELOTTERYMODELSRESULT_HPP_