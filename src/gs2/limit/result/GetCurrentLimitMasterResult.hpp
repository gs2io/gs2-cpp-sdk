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

#ifndef GS2_LIMIT_CONTROL_GETCURRENTLIMITMASTERRESULT_HPP_
#define GS2_LIMIT_CONTROL_GETCURRENTLIMITMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * 現在有効な現在有効な回数制限設定を取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCurrentLimitMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在有効な現在有効な回数制限設定 */
        optional<CurrentLimitMaster> item;

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
    GetCurrentLimitMasterResult() :
        m_pData(nullptr)
    {}

    GetCurrentLimitMasterResult(const GetCurrentLimitMasterResult& getCurrentLimitMasterResult) :
        Gs2Object(getCurrentLimitMasterResult),
        m_pData(getCurrentLimitMasterResult.m_pData != nullptr ? new Data(*getCurrentLimitMasterResult.m_pData) : nullptr)
    {}

    GetCurrentLimitMasterResult(GetCurrentLimitMasterResult&& getCurrentLimitMasterResult) :
        Gs2Object(std::move(getCurrentLimitMasterResult)),
        m_pData(getCurrentLimitMasterResult.m_pData)
    {
        getCurrentLimitMasterResult.m_pData = nullptr;
    }

    ~GetCurrentLimitMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCurrentLimitMasterResult& operator=(const GetCurrentLimitMasterResult& getCurrentLimitMasterResult)
    {
        Gs2Object::operator=(getCurrentLimitMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCurrentLimitMasterResult.m_pData);

        return *this;
    }

    GetCurrentLimitMasterResult& operator=(GetCurrentLimitMasterResult&& getCurrentLimitMasterResult)
    {
        Gs2Object::operator=(std::move(getCurrentLimitMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCurrentLimitMasterResult.m_pData;
        getCurrentLimitMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCurrentLimitMasterResult* operator->() const
    {
        return this;
    }

    GetCurrentLimitMasterResult* operator->()
    {
        return this;
    }
    /**
     * 現在有効な現在有効な回数制限設定を取得
     *
     * @return 現在有効な現在有効な回数制限設定
     */
    const optional<CurrentLimitMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在有効な現在有効な回数制限設定を設定
     *
     * @param item 現在有効な現在有効な回数制限設定
     */
    void setItem(const CurrentLimitMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LIMIT_CONTROL_GETCURRENTLIMITMASTERRESULT_HPP_