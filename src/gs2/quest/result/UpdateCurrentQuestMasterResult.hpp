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

#ifndef GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERRESULT_HPP_

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
 * 現在有効な現在有効なクエストマスターを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentQuestMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な現在有効なクエストマスター */
        optional<CurrentQuestMaster> item;

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
    UpdateCurrentQuestMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentQuestMasterResult(const UpdateCurrentQuestMasterResult& updateCurrentQuestMasterResult) :
        Gs2Object(updateCurrentQuestMasterResult),
        m_pData(updateCurrentQuestMasterResult.m_pData != nullptr ? new Data(*updateCurrentQuestMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentQuestMasterResult(UpdateCurrentQuestMasterResult&& updateCurrentQuestMasterResult) :
        Gs2Object(std::move(updateCurrentQuestMasterResult)),
        m_pData(updateCurrentQuestMasterResult.m_pData)
    {
        updateCurrentQuestMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentQuestMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentQuestMasterResult& operator=(const UpdateCurrentQuestMasterResult& updateCurrentQuestMasterResult)
    {
        Gs2Object::operator=(updateCurrentQuestMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentQuestMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentQuestMasterResult& operator=(UpdateCurrentQuestMasterResult&& updateCurrentQuestMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentQuestMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentQuestMasterResult.m_pData;
        updateCurrentQuestMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentQuestMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentQuestMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な現在有効なクエストマスターを取得
     *
     * @return 更新した現在有効な現在有効なクエストマスター
     */
    const optional<CurrentQuestMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な現在有効なクエストマスターを設定
     *
     * @param item 更新した現在有効な現在有効なクエストマスター
     */
    void setItem(const CurrentQuestMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERRESULT_HPP_