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

#ifndef GS2_ACCOUNT_CONTROL_DELETETAKEOVERRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_DELETETAKEOVERRESULT_HPP_

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
 * 引き継ぎ設定を削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteTakeOverResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
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
    DeleteTakeOverResult() :
        m_pData(nullptr)
    {}

    DeleteTakeOverResult(const DeleteTakeOverResult& deleteTakeOverResult) :
        Gs2Object(deleteTakeOverResult),
        m_pData(deleteTakeOverResult.m_pData != nullptr ? new Data(*deleteTakeOverResult.m_pData) : nullptr)
    {}

    DeleteTakeOverResult(DeleteTakeOverResult&& deleteTakeOverResult) :
        Gs2Object(std::move(deleteTakeOverResult)),
        m_pData(deleteTakeOverResult.m_pData)
    {
        deleteTakeOverResult.m_pData = nullptr;
    }

    ~DeleteTakeOverResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTakeOverResult& operator=(const DeleteTakeOverResult& deleteTakeOverResult)
    {
        Gs2Object::operator=(deleteTakeOverResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTakeOverResult.m_pData);

        return *this;
    }

    DeleteTakeOverResult& operator=(DeleteTakeOverResult&& deleteTakeOverResult)
    {
        Gs2Object::operator=(std::move(deleteTakeOverResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTakeOverResult.m_pData;
        deleteTakeOverResult.m_pData = nullptr;

        return *this;
    }

    const DeleteTakeOverResult* operator->() const
    {
        return this;
    }

    DeleteTakeOverResult* operator->()
    {
        return this;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_DELETETAKEOVERRESULT_HPP_