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

#ifndef GS2_QUEST_CONTROL_GETCOMPLETEDQUESTLISTBYUSERIDRESULT_HPP_
#define GS2_QUEST_CONTROL_GETCOMPLETEDQUESTLISTBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエスト進行を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCompletedQuestListByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト進行 */
        optional<CompletedQuestList> item;

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
    GetCompletedQuestListByUserIdResult() :
        m_pData(nullptr)
    {}

    GetCompletedQuestListByUserIdResult(const GetCompletedQuestListByUserIdResult& getCompletedQuestListByUserIdResult) :
        Gs2Object(getCompletedQuestListByUserIdResult),
        m_pData(getCompletedQuestListByUserIdResult.m_pData != nullptr ? new Data(*getCompletedQuestListByUserIdResult.m_pData) : nullptr)
    {}

    GetCompletedQuestListByUserIdResult(GetCompletedQuestListByUserIdResult&& getCompletedQuestListByUserIdResult) :
        Gs2Object(std::move(getCompletedQuestListByUserIdResult)),
        m_pData(getCompletedQuestListByUserIdResult.m_pData)
    {
        getCompletedQuestListByUserIdResult.m_pData = nullptr;
    }

    ~GetCompletedQuestListByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCompletedQuestListByUserIdResult& operator=(const GetCompletedQuestListByUserIdResult& getCompletedQuestListByUserIdResult)
    {
        Gs2Object::operator=(getCompletedQuestListByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCompletedQuestListByUserIdResult.m_pData);

        return *this;
    }

    GetCompletedQuestListByUserIdResult& operator=(GetCompletedQuestListByUserIdResult&& getCompletedQuestListByUserIdResult)
    {
        Gs2Object::operator=(std::move(getCompletedQuestListByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCompletedQuestListByUserIdResult.m_pData;
        getCompletedQuestListByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetCompletedQuestListByUserIdResult* operator->() const
    {
        return this;
    }

    GetCompletedQuestListByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * クエスト進行を取得
     *
     * @return クエスト進行
     */
    const optional<CompletedQuestList>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クエスト進行を設定
     *
     * @param item クエスト進行
     */
    void setItem(const CompletedQuestList& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetCompletedQuestListByUserIdResult> AsyncGetCompletedQuestListByUserIdResult;

} }

#endif //GS2_QUEST_CONTROL_GETCOMPLETEDQUESTLISTBYUSERIDRESULT_HPP_