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

#ifndef GS2_QUEST_CONTROL_DELETEQUESTMODELMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_DELETEQUESTMODELMASTERRESULT_HPP_

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
 * クエストモデルマスターを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteQuestModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したクエストモデルマスター */
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
    DeleteQuestModelMasterResult() :
        m_pData(nullptr)
    {}

    DeleteQuestModelMasterResult(const DeleteQuestModelMasterResult& deleteQuestModelMasterResult) :
        Gs2Object(deleteQuestModelMasterResult),
        m_pData(deleteQuestModelMasterResult.m_pData != nullptr ? new Data(*deleteQuestModelMasterResult.m_pData) : nullptr)
    {}

    DeleteQuestModelMasterResult(DeleteQuestModelMasterResult&& deleteQuestModelMasterResult) :
        Gs2Object(std::move(deleteQuestModelMasterResult)),
        m_pData(deleteQuestModelMasterResult.m_pData)
    {
        deleteQuestModelMasterResult.m_pData = nullptr;
    }

    ~DeleteQuestModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteQuestModelMasterResult& operator=(const DeleteQuestModelMasterResult& deleteQuestModelMasterResult)
    {
        Gs2Object::operator=(deleteQuestModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteQuestModelMasterResult.m_pData);

        return *this;
    }

    DeleteQuestModelMasterResult& operator=(DeleteQuestModelMasterResult&& deleteQuestModelMasterResult)
    {
        Gs2Object::operator=(std::move(deleteQuestModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteQuestModelMasterResult.m_pData;
        deleteQuestModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const DeleteQuestModelMasterResult* operator->() const
    {
        return this;
    }

    DeleteQuestModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 削除したクエストモデルマスターを取得
     *
     * @return 削除したクエストモデルマスター
     */
    const optional<QuestModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したクエストモデルマスターを設定
     *
     * @param item 削除したクエストモデルマスター
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

#endif //GS2_QUEST_CONTROL_DELETEQUESTMODELMASTERRESULT_HPP_