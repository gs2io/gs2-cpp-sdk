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

#ifndef GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERRESULT_HPP_
#define GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERRESULT_HPP_

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
 * 排出確率テーブルマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreatePrizeTableMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成した排出確率テーブルマスター */
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
    CreatePrizeTableMasterResult() :
        m_pData(nullptr)
    {}

    CreatePrizeTableMasterResult(const CreatePrizeTableMasterResult& createPrizeTableMasterResult) :
        Gs2Object(createPrizeTableMasterResult),
        m_pData(createPrizeTableMasterResult.m_pData != nullptr ? new Data(*createPrizeTableMasterResult.m_pData) : nullptr)
    {}

    CreatePrizeTableMasterResult(CreatePrizeTableMasterResult&& createPrizeTableMasterResult) :
        Gs2Object(std::move(createPrizeTableMasterResult)),
        m_pData(createPrizeTableMasterResult.m_pData)
    {
        createPrizeTableMasterResult.m_pData = nullptr;
    }

    ~CreatePrizeTableMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreatePrizeTableMasterResult& operator=(const CreatePrizeTableMasterResult& createPrizeTableMasterResult)
    {
        Gs2Object::operator=(createPrizeTableMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createPrizeTableMasterResult.m_pData);

        return *this;
    }

    CreatePrizeTableMasterResult& operator=(CreatePrizeTableMasterResult&& createPrizeTableMasterResult)
    {
        Gs2Object::operator=(std::move(createPrizeTableMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createPrizeTableMasterResult.m_pData;
        createPrizeTableMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreatePrizeTableMasterResult* operator->() const
    {
        return this;
    }

    CreatePrizeTableMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成した排出確率テーブルマスターを取得
     *
     * @return 作成した排出確率テーブルマスター
     */
    const optional<PrizeTableMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成した排出確率テーブルマスターを設定
     *
     * @param item 作成した排出確率テーブルマスター
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

#endif //GS2_LOTTERY_CONTROL_CREATEPRIZETABLEMASTERRESULT_HPP_