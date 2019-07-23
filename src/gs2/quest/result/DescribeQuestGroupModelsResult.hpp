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

#ifndef GS2_QUEST_CONTROL_DESCRIBEQUESTGROUPMODELSRESULT_HPP_
#define GS2_QUEST_CONTROL_DESCRIBEQUESTGROUPMODELSRESULT_HPP_

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
 * クエストグループの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeQuestGroupModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストグループのリスト */
        optional<List<QuestGroupModel>> items;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        QuestGroupModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->items, std::move(item));
                    }
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
    DescribeQuestGroupModelsResult() :
        m_pData(nullptr)
    {}

    DescribeQuestGroupModelsResult(const DescribeQuestGroupModelsResult& describeQuestGroupModelsResult) :
        Gs2Object(describeQuestGroupModelsResult),
        m_pData(describeQuestGroupModelsResult.m_pData != nullptr ? new Data(*describeQuestGroupModelsResult.m_pData) : nullptr)
    {}

    DescribeQuestGroupModelsResult(DescribeQuestGroupModelsResult&& describeQuestGroupModelsResult) :
        Gs2Object(std::move(describeQuestGroupModelsResult)),
        m_pData(describeQuestGroupModelsResult.m_pData)
    {
        describeQuestGroupModelsResult.m_pData = nullptr;
    }

    ~DescribeQuestGroupModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeQuestGroupModelsResult& operator=(const DescribeQuestGroupModelsResult& describeQuestGroupModelsResult)
    {
        Gs2Object::operator=(describeQuestGroupModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeQuestGroupModelsResult.m_pData);

        return *this;
    }

    DescribeQuestGroupModelsResult& operator=(DescribeQuestGroupModelsResult&& describeQuestGroupModelsResult)
    {
        Gs2Object::operator=(std::move(describeQuestGroupModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeQuestGroupModelsResult.m_pData;
        describeQuestGroupModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeQuestGroupModelsResult* operator->() const
    {
        return this;
    }

    DescribeQuestGroupModelsResult* operator->()
    {
        return this;
    }
    /**
     * クエストグループのリストを取得
     *
     * @return クエストグループのリスト
     */
    const optional<List<QuestGroupModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * クエストグループのリストを設定
     *
     * @param items クエストグループのリスト
     */
    void setItems(const List<QuestGroupModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_QUEST_CONTROL_DESCRIBEQUESTGROUPMODELSRESULT_HPP_