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

#ifndef GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORRESULT_HPP_

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
 * ディストリビュータを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteDistributorResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したディストリビュータ */
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
    DeleteDistributorResult() :
        m_pData(nullptr)
    {}

    DeleteDistributorResult(const DeleteDistributorResult& deleteDistributorResult) :
        Gs2Object(deleteDistributorResult),
        m_pData(deleteDistributorResult.m_pData != nullptr ? new Data(*deleteDistributorResult.m_pData) : nullptr)
    {}

    DeleteDistributorResult(DeleteDistributorResult&& deleteDistributorResult) :
        Gs2Object(std::move(deleteDistributorResult)),
        m_pData(deleteDistributorResult.m_pData)
    {
        deleteDistributorResult.m_pData = nullptr;
    }

    ~DeleteDistributorResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteDistributorResult& operator=(const DeleteDistributorResult& deleteDistributorResult)
    {
        Gs2Object::operator=(deleteDistributorResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteDistributorResult.m_pData);

        return *this;
    }

    DeleteDistributorResult& operator=(DeleteDistributorResult&& deleteDistributorResult)
    {
        Gs2Object::operator=(std::move(deleteDistributorResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteDistributorResult.m_pData;
        deleteDistributorResult.m_pData = nullptr;

        return *this;
    }

    const DeleteDistributorResult* operator->() const
    {
        return this;
    }

    DeleteDistributorResult* operator->()
    {
        return this;
    }
    /**
     * 削除したディストリビュータを取得
     *
     * @return 削除したディストリビュータ
     */
    const optional<Distributor>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したディストリビュータを設定
     *
     * @param item 削除したディストリビュータ
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

#endif //GS2_DISTRIBUTOR_CONTROL_DELETEDISTRIBUTORRESULT_HPP_