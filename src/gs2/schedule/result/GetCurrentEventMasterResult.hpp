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

#ifndef GS2_SCHEDULE_CONTROL_GETCURRENTEVENTMASTERRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_GETCURRENTEVENTMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * 現在有効なイベントマスターJSONを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCurrentEventMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在有効なイベントマスターJSON */
        optional<CurrentEventMaster> item;

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

        ~Data() = default;

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
    GetCurrentEventMasterResult() :
        m_pData(nullptr)
    {}

    GetCurrentEventMasterResult(const GetCurrentEventMasterResult& getCurrentEventMasterResult) :
        Gs2Object(getCurrentEventMasterResult),
        m_pData(getCurrentEventMasterResult.m_pData != nullptr ? new Data(*getCurrentEventMasterResult.m_pData) : nullptr)
    {}

    GetCurrentEventMasterResult(GetCurrentEventMasterResult&& getCurrentEventMasterResult) :
        Gs2Object(std::move(getCurrentEventMasterResult)),
        m_pData(getCurrentEventMasterResult.m_pData)
    {
        getCurrentEventMasterResult.m_pData = nullptr;
    }

    ~GetCurrentEventMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCurrentEventMasterResult& operator=(const GetCurrentEventMasterResult& getCurrentEventMasterResult)
    {
        Gs2Object::operator=(getCurrentEventMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCurrentEventMasterResult.m_pData);

        return *this;
    }

    GetCurrentEventMasterResult& operator=(GetCurrentEventMasterResult&& getCurrentEventMasterResult)
    {
        Gs2Object::operator=(std::move(getCurrentEventMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCurrentEventMasterResult.m_pData;
        getCurrentEventMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCurrentEventMasterResult* operator->() const
    {
        return this;
    }

    GetCurrentEventMasterResult* operator->()
    {
        return this;
    }
    /**
     * 現在有効なイベントマスターJSONを取得
     *
     * @return 現在有効なイベントマスターJSON
     */
    const optional<CurrentEventMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在有効なイベントマスターJSONを設定
     *
     * @param item 現在有効なイベントマスターJSON
     */
    void setItem(const CurrentEventMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_GETCURRENTEVENTMASTERRESULT_HPP_