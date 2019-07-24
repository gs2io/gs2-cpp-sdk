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

#ifndef GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_

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
 * クエストモデルマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateQuestModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したクエストモデルマスター */
        optional<QuestModelMaster> item;

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
    CreateQuestModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateQuestModelMasterResult(const CreateQuestModelMasterResult& createQuestModelMasterResult) :
        Gs2Object(createQuestModelMasterResult),
        m_pData(createQuestModelMasterResult.m_pData != nullptr ? new Data(*createQuestModelMasterResult.m_pData) : nullptr)
    {}

    CreateQuestModelMasterResult(CreateQuestModelMasterResult&& createQuestModelMasterResult) :
        Gs2Object(std::move(createQuestModelMasterResult)),
        m_pData(createQuestModelMasterResult.m_pData)
    {
        createQuestModelMasterResult.m_pData = nullptr;
    }

    ~CreateQuestModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateQuestModelMasterResult& operator=(const CreateQuestModelMasterResult& createQuestModelMasterResult)
    {
        Gs2Object::operator=(createQuestModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createQuestModelMasterResult.m_pData);

        return *this;
    }

    CreateQuestModelMasterResult& operator=(CreateQuestModelMasterResult&& createQuestModelMasterResult)
    {
        Gs2Object::operator=(std::move(createQuestModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createQuestModelMasterResult.m_pData;
        createQuestModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateQuestModelMasterResult* operator->() const
    {
        return this;
    }

    CreateQuestModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したクエストモデルマスターを取得
     *
     * @return 作成したクエストモデルマスター
     */
    const optional<QuestModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したクエストモデルマスターを設定
     *
     * @param item 作成したクエストモデルマスター
     */
    void setItem(const QuestModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_