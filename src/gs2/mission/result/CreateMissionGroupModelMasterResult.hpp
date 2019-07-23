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

#ifndef GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERRESULT_HPP_
#define GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERRESULT_HPP_

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
 * ミッショングループマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateMissionGroupModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したミッショングループマスター */
        optional<MissionGroupModelMaster> item;

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
    CreateMissionGroupModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateMissionGroupModelMasterResult(const CreateMissionGroupModelMasterResult& createMissionGroupModelMasterResult) :
        Gs2Object(createMissionGroupModelMasterResult),
        m_pData(createMissionGroupModelMasterResult.m_pData != nullptr ? new Data(*createMissionGroupModelMasterResult.m_pData) : nullptr)
    {}

    CreateMissionGroupModelMasterResult(CreateMissionGroupModelMasterResult&& createMissionGroupModelMasterResult) :
        Gs2Object(std::move(createMissionGroupModelMasterResult)),
        m_pData(createMissionGroupModelMasterResult.m_pData)
    {
        createMissionGroupModelMasterResult.m_pData = nullptr;
    }

    ~CreateMissionGroupModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateMissionGroupModelMasterResult& operator=(const CreateMissionGroupModelMasterResult& createMissionGroupModelMasterResult)
    {
        Gs2Object::operator=(createMissionGroupModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createMissionGroupModelMasterResult.m_pData);

        return *this;
    }

    CreateMissionGroupModelMasterResult& operator=(CreateMissionGroupModelMasterResult&& createMissionGroupModelMasterResult)
    {
        Gs2Object::operator=(std::move(createMissionGroupModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createMissionGroupModelMasterResult.m_pData;
        createMissionGroupModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateMissionGroupModelMasterResult* operator->() const
    {
        return this;
    }

    CreateMissionGroupModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したミッショングループマスターを取得
     *
     * @return 作成したミッショングループマスター
     */
    const optional<MissionGroupModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したミッショングループマスターを設定
     *
     * @param item 作成したミッショングループマスター
     */
    void setItem(const MissionGroupModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERRESULT_HPP_