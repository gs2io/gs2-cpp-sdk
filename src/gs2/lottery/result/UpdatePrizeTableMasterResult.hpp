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

#ifndef GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERRESULT_HPP_
#define GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERRESULT_HPP_

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
 * 景品の排出確率テーブルを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdatePrizeTableMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した景品の排出確率テーブル */
        optional<PrizeTableMaster> item;

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
    UpdatePrizeTableMasterResult() :
        m_pData(nullptr)
    {}

    UpdatePrizeTableMasterResult(const UpdatePrizeTableMasterResult& updatePrizeTableMasterResult) :
        Gs2Object(updatePrizeTableMasterResult),
        m_pData(updatePrizeTableMasterResult.m_pData != nullptr ? new Data(*updatePrizeTableMasterResult.m_pData) : nullptr)
    {}

    UpdatePrizeTableMasterResult(UpdatePrizeTableMasterResult&& updatePrizeTableMasterResult) :
        Gs2Object(std::move(updatePrizeTableMasterResult)),
        m_pData(updatePrizeTableMasterResult.m_pData)
    {
        updatePrizeTableMasterResult.m_pData = nullptr;
    }

    ~UpdatePrizeTableMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdatePrizeTableMasterResult& operator=(const UpdatePrizeTableMasterResult& updatePrizeTableMasterResult)
    {
        Gs2Object::operator=(updatePrizeTableMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updatePrizeTableMasterResult.m_pData);

        return *this;
    }

    UpdatePrizeTableMasterResult& operator=(UpdatePrizeTableMasterResult&& updatePrizeTableMasterResult)
    {
        Gs2Object::operator=(std::move(updatePrizeTableMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updatePrizeTableMasterResult.m_pData;
        updatePrizeTableMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdatePrizeTableMasterResult* operator->() const
    {
        return this;
    }

    UpdatePrizeTableMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した景品の排出確率テーブルを取得
     *
     * @return 更新した景品の排出確率テーブル
     */
    const optional<PrizeTableMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した景品の排出確率テーブルを設定
     *
     * @param item 更新した景品の排出確率テーブル
     */
    void setItem(const PrizeTableMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_UPDATEPRIZETABLEMASTERRESULT_HPP_