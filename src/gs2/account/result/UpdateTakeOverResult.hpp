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

#ifndef GS2_ACCOUNT_CONTROL_UPDATETAKEOVERRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATETAKEOVERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * 引き継ぎ設定を更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateTakeOverResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 引き継ぎ設定 */
        optional<TakeOver> item;

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
    UpdateTakeOverResult() :
        m_pData(nullptr)
    {}

    UpdateTakeOverResult(const UpdateTakeOverResult& updateTakeOverResult) :
        Gs2Object(updateTakeOverResult),
        m_pData(updateTakeOverResult.m_pData != nullptr ? new Data(*updateTakeOverResult.m_pData) : nullptr)
    {}

    UpdateTakeOverResult(UpdateTakeOverResult&& updateTakeOverResult) :
        Gs2Object(std::move(updateTakeOverResult)),
        m_pData(updateTakeOverResult.m_pData)
    {
        updateTakeOverResult.m_pData = nullptr;
    }

    ~UpdateTakeOverResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateTakeOverResult& operator=(const UpdateTakeOverResult& updateTakeOverResult)
    {
        Gs2Object::operator=(updateTakeOverResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateTakeOverResult.m_pData);

        return *this;
    }

    UpdateTakeOverResult& operator=(UpdateTakeOverResult&& updateTakeOverResult)
    {
        Gs2Object::operator=(std::move(updateTakeOverResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateTakeOverResult.m_pData;
        updateTakeOverResult.m_pData = nullptr;

        return *this;
    }

    const UpdateTakeOverResult* operator->() const
    {
        return this;
    }

    UpdateTakeOverResult* operator->()
    {
        return this;
    }
    /**
     * 引き継ぎ設定を取得
     *
     * @return 引き継ぎ設定
     */
    const optional<TakeOver>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 引き継ぎ設定を設定
     *
     * @param item 引き継ぎ設定
     */
    void setItem(const TakeOver& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATETAKEOVERRESULT_HPP_