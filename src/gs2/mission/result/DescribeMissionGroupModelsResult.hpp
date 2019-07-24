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

#ifndef GS2_MISSION_CONTROL_DESCRIBEMISSIONGROUPMODELSRESULT_HPP_
#define GS2_MISSION_CONTROL_DESCRIBEMISSIONGROUPMODELSRESULT_HPP_

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
 * ミッショングループの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeMissionGroupModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッショングループのリスト */
        optional<List<MissionGroupModel>> items;

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
                        MissionGroupModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
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
    DescribeMissionGroupModelsResult() :
        m_pData(nullptr)
    {}

    DescribeMissionGroupModelsResult(const DescribeMissionGroupModelsResult& describeMissionGroupModelsResult) :
        Gs2Object(describeMissionGroupModelsResult),
        m_pData(describeMissionGroupModelsResult.m_pData != nullptr ? new Data(*describeMissionGroupModelsResult.m_pData) : nullptr)
    {}

    DescribeMissionGroupModelsResult(DescribeMissionGroupModelsResult&& describeMissionGroupModelsResult) :
        Gs2Object(std::move(describeMissionGroupModelsResult)),
        m_pData(describeMissionGroupModelsResult.m_pData)
    {
        describeMissionGroupModelsResult.m_pData = nullptr;
    }

    ~DescribeMissionGroupModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeMissionGroupModelsResult& operator=(const DescribeMissionGroupModelsResult& describeMissionGroupModelsResult)
    {
        Gs2Object::operator=(describeMissionGroupModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeMissionGroupModelsResult.m_pData);

        return *this;
    }

    DescribeMissionGroupModelsResult& operator=(DescribeMissionGroupModelsResult&& describeMissionGroupModelsResult)
    {
        Gs2Object::operator=(std::move(describeMissionGroupModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeMissionGroupModelsResult.m_pData;
        describeMissionGroupModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeMissionGroupModelsResult* operator->() const
    {
        return this;
    }

    DescribeMissionGroupModelsResult* operator->()
    {
        return this;
    }
    /**
     * ミッショングループのリストを取得
     *
     * @return ミッショングループのリスト
     */
    const optional<List<MissionGroupModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ミッショングループのリストを設定
     *
     * @param items ミッショングループのリスト
     */
    void setItems(const List<MissionGroupModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MISSION_CONTROL_DESCRIBEMISSIONGROUPMODELSRESULT_HPP_