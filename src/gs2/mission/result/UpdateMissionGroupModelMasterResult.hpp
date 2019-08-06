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

#ifndef GS2_MISSION_CONTROL_UPDATEMISSIONGROUPMODELMASTERRESULT_HPP_
#define GS2_MISSION_CONTROL_UPDATEMISSIONGROUPMODELMASTERRESULT_HPP_

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
 * ミッショングループマスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMissionGroupModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したミッショングループマスター */
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
    UpdateMissionGroupModelMasterResult() :
        m_pData(nullptr)
    {}

    UpdateMissionGroupModelMasterResult(const UpdateMissionGroupModelMasterResult& updateMissionGroupModelMasterResult) :
        Gs2Object(updateMissionGroupModelMasterResult),
        m_pData(updateMissionGroupModelMasterResult.m_pData != nullptr ? new Data(*updateMissionGroupModelMasterResult.m_pData) : nullptr)
    {}

    UpdateMissionGroupModelMasterResult(UpdateMissionGroupModelMasterResult&& updateMissionGroupModelMasterResult) :
        Gs2Object(std::move(updateMissionGroupModelMasterResult)),
        m_pData(updateMissionGroupModelMasterResult.m_pData)
    {
        updateMissionGroupModelMasterResult.m_pData = nullptr;
    }

    ~UpdateMissionGroupModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMissionGroupModelMasterResult& operator=(const UpdateMissionGroupModelMasterResult& updateMissionGroupModelMasterResult)
    {
        Gs2Object::operator=(updateMissionGroupModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMissionGroupModelMasterResult.m_pData);

        return *this;
    }

    UpdateMissionGroupModelMasterResult& operator=(UpdateMissionGroupModelMasterResult&& updateMissionGroupModelMasterResult)
    {
        Gs2Object::operator=(std::move(updateMissionGroupModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMissionGroupModelMasterResult.m_pData;
        updateMissionGroupModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateMissionGroupModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateMissionGroupModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新したミッショングループマスターを取得
     *
     * @return 更新したミッショングループマスター
     */
    const optional<MissionGroupModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したミッショングループマスターを設定
     *
     * @param item 更新したミッショングループマスター
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

#endif //GS2_MISSION_CONTROL_UPDATEMISSIONGROUPMODELMASTERRESULT_HPP_