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

#ifndef GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ディストリビュータの種類を新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateDistributorModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したディストリビュータの種類 */
        optional<DistributorModelMaster> item;

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
    CreateDistributorModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateDistributorModelMasterResult(const CreateDistributorModelMasterResult& createDistributorModelMasterResult) :
        Gs2Object(createDistributorModelMasterResult),
        m_pData(createDistributorModelMasterResult.m_pData != nullptr ? new Data(*createDistributorModelMasterResult.m_pData) : nullptr)
    {}

    CreateDistributorModelMasterResult(CreateDistributorModelMasterResult&& createDistributorModelMasterResult) :
        Gs2Object(std::move(createDistributorModelMasterResult)),
        m_pData(createDistributorModelMasterResult.m_pData)
    {
        createDistributorModelMasterResult.m_pData = nullptr;
    }

    ~CreateDistributorModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateDistributorModelMasterResult& operator=(const CreateDistributorModelMasterResult& createDistributorModelMasterResult)
    {
        Gs2Object::operator=(createDistributorModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createDistributorModelMasterResult.m_pData);

        return *this;
    }

    CreateDistributorModelMasterResult& operator=(CreateDistributorModelMasterResult&& createDistributorModelMasterResult)
    {
        Gs2Object::operator=(std::move(createDistributorModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createDistributorModelMasterResult.m_pData;
        createDistributorModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateDistributorModelMasterResult* operator->() const
    {
        return this;
    }

    CreateDistributorModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したディストリビュータの種類を取得
     *
     * @return 作成したディストリビュータの種類
     */
    const optional<DistributorModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したディストリビュータの種類を設定
     *
     * @param item 作成したディストリビュータの種類
     */
    void setItem(const DistributorModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERRESULT_HPP_