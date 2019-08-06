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

#ifndef GS2_MISSION_CONTROL_GETMISSIONTASKMODELRESULT_HPP_
#define GS2_MISSION_CONTROL_GETMISSIONTASKMODELRESULT_HPP_

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
 * ミッションタスクを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMissionTaskModelResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションタスク */
        optional<MissionTaskModel> item;

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
    GetMissionTaskModelResult() :
        m_pData(nullptr)
    {}

    GetMissionTaskModelResult(const GetMissionTaskModelResult& getMissionTaskModelResult) :
        Gs2Object(getMissionTaskModelResult),
        m_pData(getMissionTaskModelResult.m_pData != nullptr ? new Data(*getMissionTaskModelResult.m_pData) : nullptr)
    {}

    GetMissionTaskModelResult(GetMissionTaskModelResult&& getMissionTaskModelResult) :
        Gs2Object(std::move(getMissionTaskModelResult)),
        m_pData(getMissionTaskModelResult.m_pData)
    {
        getMissionTaskModelResult.m_pData = nullptr;
    }

    ~GetMissionTaskModelResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMissionTaskModelResult& operator=(const GetMissionTaskModelResult& getMissionTaskModelResult)
    {
        Gs2Object::operator=(getMissionTaskModelResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMissionTaskModelResult.m_pData);

        return *this;
    }

    GetMissionTaskModelResult& operator=(GetMissionTaskModelResult&& getMissionTaskModelResult)
    {
        Gs2Object::operator=(std::move(getMissionTaskModelResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMissionTaskModelResult.m_pData;
        getMissionTaskModelResult.m_pData = nullptr;

        return *this;
    }

    const GetMissionTaskModelResult* operator->() const
    {
        return this;
    }

    GetMissionTaskModelResult* operator->()
    {
        return this;
    }
    /**
     * ミッションタスクを取得
     *
     * @return ミッションタスク
     */
    const optional<MissionTaskModel>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ミッションタスクを設定
     *
     * @param item ミッションタスク
     */
    void setItem(const MissionTaskModel& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_GETMISSIONTASKMODELRESULT_HPP_