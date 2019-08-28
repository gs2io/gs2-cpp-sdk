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

#ifndef GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERRESULT_HPP_
#define GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * 回数制限の種類マスターを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteLimitModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除した回数制限の種類マスター */
        optional<LimitModelMaster> item;

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
    DeleteLimitModelMasterResult() :
        m_pData(nullptr)
    {}

    DeleteLimitModelMasterResult(const DeleteLimitModelMasterResult& deleteLimitModelMasterResult) :
        Gs2Object(deleteLimitModelMasterResult),
        m_pData(deleteLimitModelMasterResult.m_pData != nullptr ? new Data(*deleteLimitModelMasterResult.m_pData) : nullptr)
    {}

    DeleteLimitModelMasterResult(DeleteLimitModelMasterResult&& deleteLimitModelMasterResult) :
        Gs2Object(std::move(deleteLimitModelMasterResult)),
        m_pData(deleteLimitModelMasterResult.m_pData)
    {
        deleteLimitModelMasterResult.m_pData = nullptr;
    }

    ~DeleteLimitModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteLimitModelMasterResult& operator=(const DeleteLimitModelMasterResult& deleteLimitModelMasterResult)
    {
        Gs2Object::operator=(deleteLimitModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteLimitModelMasterResult.m_pData);

        return *this;
    }

    DeleteLimitModelMasterResult& operator=(DeleteLimitModelMasterResult&& deleteLimitModelMasterResult)
    {
        Gs2Object::operator=(std::move(deleteLimitModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteLimitModelMasterResult.m_pData;
        deleteLimitModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const DeleteLimitModelMasterResult* operator->() const
    {
        return this;
    }

    DeleteLimitModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 削除した回数制限の種類マスターを取得
     *
     * @return 削除した回数制限の種類マスター
     */
    const optional<LimitModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除した回数制限の種類マスターを設定
     *
     * @param item 削除した回数制限の種類マスター
     */
    void setItem(const LimitModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DeleteLimitModelMasterResult> AsyncDeleteLimitModelMasterResult;

} }

#endif //GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERRESULT_HPP_