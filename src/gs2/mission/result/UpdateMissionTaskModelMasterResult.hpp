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

#ifndef GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERRESULT_HPP_
#define GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERRESULT_HPP_

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
 * ミッションタスクマスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMissionTaskModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したミッションタスクマスター */
        optional<MissionTaskModelMaster> item;

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
    UpdateMissionTaskModelMasterResult() :
        m_pData(nullptr)
    {}

    UpdateMissionTaskModelMasterResult(const UpdateMissionTaskModelMasterResult& updateMissionTaskModelMasterResult) :
        Gs2Object(updateMissionTaskModelMasterResult),
        m_pData(updateMissionTaskModelMasterResult.m_pData != nullptr ? new Data(*updateMissionTaskModelMasterResult.m_pData) : nullptr)
    {}

    UpdateMissionTaskModelMasterResult(UpdateMissionTaskModelMasterResult&& updateMissionTaskModelMasterResult) :
        Gs2Object(std::move(updateMissionTaskModelMasterResult)),
        m_pData(updateMissionTaskModelMasterResult.m_pData)
    {
        updateMissionTaskModelMasterResult.m_pData = nullptr;
    }

    ~UpdateMissionTaskModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMissionTaskModelMasterResult& operator=(const UpdateMissionTaskModelMasterResult& updateMissionTaskModelMasterResult)
    {
        Gs2Object::operator=(updateMissionTaskModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMissionTaskModelMasterResult.m_pData);

        return *this;
    }

    UpdateMissionTaskModelMasterResult& operator=(UpdateMissionTaskModelMasterResult&& updateMissionTaskModelMasterResult)
    {
        Gs2Object::operator=(std::move(updateMissionTaskModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMissionTaskModelMasterResult.m_pData;
        updateMissionTaskModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateMissionTaskModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateMissionTaskModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新したミッションタスクマスターを取得
     *
     * @return 更新したミッションタスクマスター
     */
    const optional<MissionTaskModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したミッションタスクマスターを設定
     *
     * @param item 更新したミッションタスクマスター
     */
    void setItem(const MissionTaskModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERRESULT_HPP_