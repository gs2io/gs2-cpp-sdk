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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * 現在有効な現在有効な配信設定を更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentDistributorMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な現在有効な配信設定 */
        optional<CurrentDistributorMaster> item;

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
    UpdateCurrentDistributorMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentDistributorMasterResult(const UpdateCurrentDistributorMasterResult& updateCurrentDistributorMasterResult) :
        Gs2Object(updateCurrentDistributorMasterResult),
        m_pData(updateCurrentDistributorMasterResult.m_pData != nullptr ? new Data(*updateCurrentDistributorMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentDistributorMasterResult(UpdateCurrentDistributorMasterResult&& updateCurrentDistributorMasterResult) :
        Gs2Object(std::move(updateCurrentDistributorMasterResult)),
        m_pData(updateCurrentDistributorMasterResult.m_pData)
    {
        updateCurrentDistributorMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentDistributorMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentDistributorMasterResult& operator=(const UpdateCurrentDistributorMasterResult& updateCurrentDistributorMasterResult)
    {
        Gs2Object::operator=(updateCurrentDistributorMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentDistributorMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentDistributorMasterResult& operator=(UpdateCurrentDistributorMasterResult&& updateCurrentDistributorMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentDistributorMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentDistributorMasterResult.m_pData;
        updateCurrentDistributorMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentDistributorMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentDistributorMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な現在有効な配信設定を取得
     *
     * @return 更新した現在有効な現在有効な配信設定
     */
    const optional<CurrentDistributorMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な現在有効な配信設定を設定
     *
     * @param item 更新した現在有効な現在有効な配信設定
     */
    void setItem(const CurrentDistributorMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateCurrentDistributorMasterResult> AsyncUpdateCurrentDistributorMasterResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATECURRENTDISTRIBUTORMASTERRESULT_HPP_