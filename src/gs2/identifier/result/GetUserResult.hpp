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

#ifndef GS2_IDENTIFIER_CONTROL_GETUSERRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_GETUSERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * ユーザーを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetUserResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザー */
        optional<User> item;

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
    GetUserResult() :
        m_pData(nullptr)
    {}

    GetUserResult(const GetUserResult& getUserResult) :
        Gs2Object(getUserResult),
        m_pData(getUserResult.m_pData != nullptr ? new Data(*getUserResult.m_pData) : nullptr)
    {}

    GetUserResult(GetUserResult&& getUserResult) :
        Gs2Object(std::move(getUserResult)),
        m_pData(getUserResult.m_pData)
    {
        getUserResult.m_pData = nullptr;
    }

    ~GetUserResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetUserResult& operator=(const GetUserResult& getUserResult)
    {
        Gs2Object::operator=(getUserResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getUserResult.m_pData);

        return *this;
    }

    GetUserResult& operator=(GetUserResult&& getUserResult)
    {
        Gs2Object::operator=(std::move(getUserResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getUserResult.m_pData;
        getUserResult.m_pData = nullptr;

        return *this;
    }

    const GetUserResult* operator->() const
    {
        return this;
    }

    GetUserResult* operator->()
    {
        return this;
    }
    /**
     * ユーザーを取得
     *
     * @return ユーザー
     */
    const optional<User>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ユーザーを設定
     *
     * @param item ユーザー
     */
    void setItem(const User& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_GETUSERRESULT_HPP_