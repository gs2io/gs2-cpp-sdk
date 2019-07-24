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

#ifndef GS2_PROJECT_CONTROL_UPDATEACCOUNTRESULT_HPP_
#define GS2_PROJECT_CONTROL_UPDATEACCOUNTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * GS2アカウントを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateAccountResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したGS2アカウント */
        optional<Account> item;

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
    UpdateAccountResult() :
        m_pData(nullptr)
    {}

    UpdateAccountResult(const UpdateAccountResult& updateAccountResult) :
        Gs2Object(updateAccountResult),
        m_pData(updateAccountResult.m_pData != nullptr ? new Data(*updateAccountResult.m_pData) : nullptr)
    {}

    UpdateAccountResult(UpdateAccountResult&& updateAccountResult) :
        Gs2Object(std::move(updateAccountResult)),
        m_pData(updateAccountResult.m_pData)
    {
        updateAccountResult.m_pData = nullptr;
    }

    ~UpdateAccountResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateAccountResult& operator=(const UpdateAccountResult& updateAccountResult)
    {
        Gs2Object::operator=(updateAccountResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateAccountResult.m_pData);

        return *this;
    }

    UpdateAccountResult& operator=(UpdateAccountResult&& updateAccountResult)
    {
        Gs2Object::operator=(std::move(updateAccountResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateAccountResult.m_pData;
        updateAccountResult.m_pData = nullptr;

        return *this;
    }

    const UpdateAccountResult* operator->() const
    {
        return this;
    }

    UpdateAccountResult* operator->()
    {
        return this;
    }
    /**
     * 更新したGS2アカウントを取得
     *
     * @return 更新したGS2アカウント
     */
    const optional<Account>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したGS2アカウントを設定
     *
     * @param item 更新したGS2アカウント
     */
    void setItem(const Account& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_UPDATEACCOUNTRESULT_HPP_