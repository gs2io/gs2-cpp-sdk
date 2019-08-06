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

#ifndef GS2_SHOWCASE_CONTROL_UPDATECURRENTSHOWCASEMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATECURRENTSHOWCASEMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 現在有効な現在有効な陳列棚マスターを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentShowcaseMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な現在有効な陳列棚マスター */
        optional<CurrentShowcaseMaster> item;

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
    UpdateCurrentShowcaseMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentShowcaseMasterResult(const UpdateCurrentShowcaseMasterResult& updateCurrentShowcaseMasterResult) :
        Gs2Object(updateCurrentShowcaseMasterResult),
        m_pData(updateCurrentShowcaseMasterResult.m_pData != nullptr ? new Data(*updateCurrentShowcaseMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentShowcaseMasterResult(UpdateCurrentShowcaseMasterResult&& updateCurrentShowcaseMasterResult) :
        Gs2Object(std::move(updateCurrentShowcaseMasterResult)),
        m_pData(updateCurrentShowcaseMasterResult.m_pData)
    {
        updateCurrentShowcaseMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentShowcaseMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentShowcaseMasterResult& operator=(const UpdateCurrentShowcaseMasterResult& updateCurrentShowcaseMasterResult)
    {
        Gs2Object::operator=(updateCurrentShowcaseMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentShowcaseMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentShowcaseMasterResult& operator=(UpdateCurrentShowcaseMasterResult&& updateCurrentShowcaseMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentShowcaseMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentShowcaseMasterResult.m_pData;
        updateCurrentShowcaseMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentShowcaseMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentShowcaseMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な現在有効な陳列棚マスターを取得
     *
     * @return 更新した現在有効な現在有効な陳列棚マスター
     */
    const optional<CurrentShowcaseMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な現在有効な陳列棚マスターを設定
     *
     * @param item 更新した現在有効な現在有効な陳列棚マスター
     */
    void setItem(const CurrentShowcaseMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATECURRENTSHOWCASEMASTERRESULT_HPP_