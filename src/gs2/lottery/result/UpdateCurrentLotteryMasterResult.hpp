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

#ifndef GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERRESULT_HPP_
#define GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERRESULT_HPP_

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
 * 現在有効な現在有効な抽選設定を更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentLotteryMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な現在有効な抽選設定 */
        optional<CurrentLotteryMaster> item;

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
    UpdateCurrentLotteryMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentLotteryMasterResult(const UpdateCurrentLotteryMasterResult& updateCurrentLotteryMasterResult) :
        Gs2Object(updateCurrentLotteryMasterResult),
        m_pData(updateCurrentLotteryMasterResult.m_pData != nullptr ? new Data(*updateCurrentLotteryMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentLotteryMasterResult(UpdateCurrentLotteryMasterResult&& updateCurrentLotteryMasterResult) :
        Gs2Object(std::move(updateCurrentLotteryMasterResult)),
        m_pData(updateCurrentLotteryMasterResult.m_pData)
    {
        updateCurrentLotteryMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentLotteryMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentLotteryMasterResult& operator=(const UpdateCurrentLotteryMasterResult& updateCurrentLotteryMasterResult)
    {
        Gs2Object::operator=(updateCurrentLotteryMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentLotteryMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentLotteryMasterResult& operator=(UpdateCurrentLotteryMasterResult&& updateCurrentLotteryMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentLotteryMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentLotteryMasterResult.m_pData;
        updateCurrentLotteryMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentLotteryMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentLotteryMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な現在有効な抽選設定を取得
     *
     * @return 更新した現在有効な現在有効な抽選設定
     */
    const optional<CurrentLotteryMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な現在有効な抽選設定を設定
     *
     * @param item 更新した現在有効な現在有効な抽選設定
     */
    void setItem(const CurrentLotteryMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_UPDATECURRENTLOTTERYMASTERRESULT_HPP_