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

#ifndef GS2_MISSION_CONTROL_DELETECOMPLETEBYUSERIDRESULT_HPP_
#define GS2_MISSION_CONTROL_DELETECOMPLETEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace mission
{

/**
 * 達成状況を削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteCompleteByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除した達成状況 */
        optional<Complete> item;

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
    DeleteCompleteByUserIdResult() :
        m_pData(nullptr)
    {}

    DeleteCompleteByUserIdResult(const DeleteCompleteByUserIdResult& deleteCompleteByUserIdResult) :
        Gs2Object(deleteCompleteByUserIdResult),
        m_pData(deleteCompleteByUserIdResult.m_pData != nullptr ? new Data(*deleteCompleteByUserIdResult.m_pData) : nullptr)
    {}

    DeleteCompleteByUserIdResult(DeleteCompleteByUserIdResult&& deleteCompleteByUserIdResult) :
        Gs2Object(std::move(deleteCompleteByUserIdResult)),
        m_pData(deleteCompleteByUserIdResult.m_pData)
    {
        deleteCompleteByUserIdResult.m_pData = nullptr;
    }

    ~DeleteCompleteByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteCompleteByUserIdResult& operator=(const DeleteCompleteByUserIdResult& deleteCompleteByUserIdResult)
    {
        Gs2Object::operator=(deleteCompleteByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteCompleteByUserIdResult.m_pData);

        return *this;
    }

    DeleteCompleteByUserIdResult& operator=(DeleteCompleteByUserIdResult&& deleteCompleteByUserIdResult)
    {
        Gs2Object::operator=(std::move(deleteCompleteByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteCompleteByUserIdResult.m_pData;
        deleteCompleteByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DeleteCompleteByUserIdResult* operator->() const
    {
        return this;
    }

    DeleteCompleteByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 削除した達成状況を取得
     *
     * @return 削除した達成状況
     */
    const optional<Complete>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除した達成状況を設定
     *
     * @param item 削除した達成状況
     */
    void setItem(const Complete& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_DELETECOMPLETEBYUSERIDRESULT_HPP_