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

#ifndef GS2_EXPERIENCE_CONTROL_GETEXPERIENCEMODELMASTERRESULT_HPP_
#define GS2_EXPERIENCE_CONTROL_GETEXPERIENCEMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * 経験値の種類マスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetExperienceModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値の種類マスター */
        optional<ExperienceModelMaster> item;

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
    GetExperienceModelMasterResult() :
        m_pData(nullptr)
    {}

    GetExperienceModelMasterResult(const GetExperienceModelMasterResult& getExperienceModelMasterResult) :
        Gs2Object(getExperienceModelMasterResult),
        m_pData(getExperienceModelMasterResult.m_pData != nullptr ? new Data(*getExperienceModelMasterResult.m_pData) : nullptr)
    {}

    GetExperienceModelMasterResult(GetExperienceModelMasterResult&& getExperienceModelMasterResult) :
        Gs2Object(std::move(getExperienceModelMasterResult)),
        m_pData(getExperienceModelMasterResult.m_pData)
    {
        getExperienceModelMasterResult.m_pData = nullptr;
    }

    ~GetExperienceModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetExperienceModelMasterResult& operator=(const GetExperienceModelMasterResult& getExperienceModelMasterResult)
    {
        Gs2Object::operator=(getExperienceModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getExperienceModelMasterResult.m_pData);

        return *this;
    }

    GetExperienceModelMasterResult& operator=(GetExperienceModelMasterResult&& getExperienceModelMasterResult)
    {
        Gs2Object::operator=(std::move(getExperienceModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getExperienceModelMasterResult.m_pData;
        getExperienceModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetExperienceModelMasterResult* operator->() const
    {
        return this;
    }

    GetExperienceModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 経験値の種類マスターを取得
     *
     * @return 経験値の種類マスター
     */
    const optional<ExperienceModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 経験値の種類マスターを設定
     *
     * @param item 経験値の種類マスター
     */
    void setItem(const ExperienceModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetExperienceModelMasterResult> AsyncGetExperienceModelMasterResult;

} }

#endif //GS2_EXPERIENCE_CONTROL_GETEXPERIENCEMODELMASTERRESULT_HPP_