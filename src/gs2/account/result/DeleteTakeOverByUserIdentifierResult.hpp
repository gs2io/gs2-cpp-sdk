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

#ifndef GS2_ACCOUNT_CONTROL_DELETETAKEOVERBYUSERIDENTIFIERRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_DELETETAKEOVERBYUSERIDENTIFIERRESULT_HPP_

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
class DeleteTakeOverByUserIdentifierResult : public Gs2Object
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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
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
    DeleteTakeOverByUserIdentifierResult() :
        m_pData(nullptr)
    {}

    DeleteTakeOverByUserIdentifierResult(const DeleteTakeOverByUserIdentifierResult& deleteTakeOverByUserIdentifierResult) :
        Gs2Object(deleteTakeOverByUserIdentifierResult),
        m_pData(deleteTakeOverByUserIdentifierResult.m_pData != nullptr ? new Data(*deleteTakeOverByUserIdentifierResult.m_pData) : nullptr)
    {}

    DeleteTakeOverByUserIdentifierResult(DeleteTakeOverByUserIdentifierResult&& deleteTakeOverByUserIdentifierResult) :
        Gs2Object(std::move(deleteTakeOverByUserIdentifierResult)),
        m_pData(deleteTakeOverByUserIdentifierResult.m_pData)
    {
        deleteTakeOverByUserIdentifierResult.m_pData = nullptr;
    }

    ~DeleteTakeOverByUserIdentifierResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTakeOverByUserIdentifierResult& operator=(const DeleteTakeOverByUserIdentifierResult& deleteTakeOverByUserIdentifierResult)
    {
        Gs2Object::operator=(deleteTakeOverByUserIdentifierResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTakeOverByUserIdentifierResult.m_pData);

        return *this;
    }

    DeleteTakeOverByUserIdentifierResult& operator=(DeleteTakeOverByUserIdentifierResult&& deleteTakeOverByUserIdentifierResult)
    {
        Gs2Object::operator=(std::move(deleteTakeOverByUserIdentifierResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTakeOverByUserIdentifierResult.m_pData;
        deleteTakeOverByUserIdentifierResult.m_pData = nullptr;

        return *this;
    }

    const DeleteTakeOverByUserIdentifierResult* operator->() const
    {
        return this;
    }

    DeleteTakeOverByUserIdentifierResult* operator->()
    {
        return this;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_DELETETAKEOVERBYUSERIDENTIFIERRESULT_HPP_