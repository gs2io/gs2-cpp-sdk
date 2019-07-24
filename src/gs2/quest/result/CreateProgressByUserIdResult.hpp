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

#ifndef GS2_QUEST_CONTROL_CREATEPROGRESSBYUSERIDRESULT_HPP_
#define GS2_QUEST_CONTROL_CREATEPROGRESSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエスト挑戦を作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateProgressByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト挑戦 */
        optional<Progress> item;

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
    CreateProgressByUserIdResult() :
        m_pData(nullptr)
    {}

    CreateProgressByUserIdResult(const CreateProgressByUserIdResult& createProgressByUserIdResult) :
        Gs2Object(createProgressByUserIdResult),
        m_pData(createProgressByUserIdResult.m_pData != nullptr ? new Data(*createProgressByUserIdResult.m_pData) : nullptr)
    {}

    CreateProgressByUserIdResult(CreateProgressByUserIdResult&& createProgressByUserIdResult) :
        Gs2Object(std::move(createProgressByUserIdResult)),
        m_pData(createProgressByUserIdResult.m_pData)
    {
        createProgressByUserIdResult.m_pData = nullptr;
    }

    ~CreateProgressByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateProgressByUserIdResult& operator=(const CreateProgressByUserIdResult& createProgressByUserIdResult)
    {
        Gs2Object::operator=(createProgressByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createProgressByUserIdResult.m_pData);

        return *this;
    }

    CreateProgressByUserIdResult& operator=(CreateProgressByUserIdResult&& createProgressByUserIdResult)
    {
        Gs2Object::operator=(std::move(createProgressByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createProgressByUserIdResult.m_pData;
        createProgressByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const CreateProgressByUserIdResult* operator->() const
    {
        return this;
    }

    CreateProgressByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * クエスト挑戦を取得
     *
     * @return クエスト挑戦
     */
    const optional<Progress>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クエスト挑戦を設定
     *
     * @param item クエスト挑戦
     */
    void setItem(const Progress& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_QUEST_CONTROL_CREATEPROGRESSBYUSERIDRESULT_HPP_