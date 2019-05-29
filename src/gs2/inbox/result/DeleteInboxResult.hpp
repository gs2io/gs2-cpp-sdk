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

#ifndef GS2_INBOX_CONTROL_DELETEINBOXRESULT_HPP_
#define GS2_INBOX_CONTROL_DELETEINBOXRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * プレゼントボックスを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteInboxResult : public Gs2Object
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
    DeleteInboxResult() :
        m_pData(nullptr)
    {}

    DeleteInboxResult(const DeleteInboxResult& deleteInboxResult) :
        Gs2Object(deleteInboxResult),
        m_pData(deleteInboxResult.m_pData != nullptr ? new Data(*deleteInboxResult.m_pData) : nullptr)
    {}

    DeleteInboxResult(DeleteInboxResult&& deleteInboxResult) :
        Gs2Object(std::move(deleteInboxResult)),
        m_pData(deleteInboxResult.m_pData)
    {
        deleteInboxResult.m_pData = nullptr;
    }

    ~DeleteInboxResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteInboxResult& operator=(const DeleteInboxResult& deleteInboxResult)
    {
        Gs2Object::operator=(deleteInboxResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteInboxResult.m_pData);

        return *this;
    }

    DeleteInboxResult& operator=(DeleteInboxResult&& deleteInboxResult)
    {
        Gs2Object::operator=(std::move(deleteInboxResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteInboxResult.m_pData;
        deleteInboxResult.m_pData = nullptr;

        return *this;
    }

    const DeleteInboxResult* operator->() const
    {
        return this;
    }

    DeleteInboxResult* operator->()
    {
        return this;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_DELETEINBOXRESULT_HPP_