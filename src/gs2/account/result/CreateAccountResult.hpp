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

#ifndef GS2_ACCOUNT_CONTROL_CREATEACCOUNTRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_CREATEACCOUNTRESULT_HPP_

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
 * ゲームプレイヤーアカウントを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateAccountResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したゲームプレイヤーアカウント */
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
    CreateAccountResult() :
        m_pData(nullptr)
    {}

    CreateAccountResult(const CreateAccountResult& createAccountResult) :
        Gs2Object(createAccountResult),
        m_pData(createAccountResult.m_pData != nullptr ? new Data(*createAccountResult.m_pData) : nullptr)
    {}

    CreateAccountResult(CreateAccountResult&& createAccountResult) :
        Gs2Object(std::move(createAccountResult)),
        m_pData(createAccountResult.m_pData)
    {
        createAccountResult.m_pData = nullptr;
    }

    ~CreateAccountResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateAccountResult& operator=(const CreateAccountResult& createAccountResult)
    {
        Gs2Object::operator=(createAccountResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createAccountResult.m_pData);

        return *this;
    }

    CreateAccountResult& operator=(CreateAccountResult&& createAccountResult)
    {
        Gs2Object::operator=(std::move(createAccountResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createAccountResult.m_pData;
        createAccountResult.m_pData = nullptr;

        return *this;
    }

    const CreateAccountResult* operator->() const
    {
        return this;
    }

    CreateAccountResult* operator->()
    {
        return this;
    }
    /**
     * 作成したゲームプレイヤーアカウントを取得
     *
     * @return 作成したゲームプレイヤーアカウント
     */
    const optional<Account>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したゲームプレイヤーアカウントを設定
     *
     * @param item 作成したゲームプレイヤーアカウント
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

#endif //GS2_ACCOUNT_CONTROL_CREATEACCOUNTRESULT_HPP_