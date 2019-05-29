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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORRESULT_HPP_

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
 * ディストリビュータを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateDistributorResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したディストリビュータ */
        optional<Distributor> item;

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
    UpdateDistributorResult() :
        m_pData(nullptr)
    {}

    UpdateDistributorResult(const UpdateDistributorResult& updateDistributorResult) :
        Gs2Object(updateDistributorResult),
        m_pData(updateDistributorResult.m_pData != nullptr ? new Data(*updateDistributorResult.m_pData) : nullptr)
    {}

    UpdateDistributorResult(UpdateDistributorResult&& updateDistributorResult) :
        Gs2Object(std::move(updateDistributorResult)),
        m_pData(updateDistributorResult.m_pData)
    {
        updateDistributorResult.m_pData = nullptr;
    }

    ~UpdateDistributorResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateDistributorResult& operator=(const UpdateDistributorResult& updateDistributorResult)
    {
        Gs2Object::operator=(updateDistributorResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateDistributorResult.m_pData);

        return *this;
    }

    UpdateDistributorResult& operator=(UpdateDistributorResult&& updateDistributorResult)
    {
        Gs2Object::operator=(std::move(updateDistributorResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateDistributorResult.m_pData;
        updateDistributorResult.m_pData = nullptr;

        return *this;
    }

    const UpdateDistributorResult* operator->() const
    {
        return this;
    }

    UpdateDistributorResult* operator->()
    {
        return this;
    }
    /**
     * 更新したディストリビュータを取得
     *
     * @return 更新したディストリビュータ
     */
    const optional<Distributor>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したディストリビュータを設定
     *
     * @param item 更新したディストリビュータ
     */
    void setItem(const Distributor& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORRESULT_HPP_