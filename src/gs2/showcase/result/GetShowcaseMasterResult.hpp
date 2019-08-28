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

#ifndef GS2_SHOWCASE_CONTROL_GETSHOWCASEMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_GETSHOWCASEMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 陳列棚マスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetShowcaseMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚マスター */
        optional<ShowcaseMaster> item;

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
    GetShowcaseMasterResult() :
        m_pData(nullptr)
    {}

    GetShowcaseMasterResult(const GetShowcaseMasterResult& getShowcaseMasterResult) :
        Gs2Object(getShowcaseMasterResult),
        m_pData(getShowcaseMasterResult.m_pData != nullptr ? new Data(*getShowcaseMasterResult.m_pData) : nullptr)
    {}

    GetShowcaseMasterResult(GetShowcaseMasterResult&& getShowcaseMasterResult) :
        Gs2Object(std::move(getShowcaseMasterResult)),
        m_pData(getShowcaseMasterResult.m_pData)
    {
        getShowcaseMasterResult.m_pData = nullptr;
    }

    ~GetShowcaseMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetShowcaseMasterResult& operator=(const GetShowcaseMasterResult& getShowcaseMasterResult)
    {
        Gs2Object::operator=(getShowcaseMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getShowcaseMasterResult.m_pData);

        return *this;
    }

    GetShowcaseMasterResult& operator=(GetShowcaseMasterResult&& getShowcaseMasterResult)
    {
        Gs2Object::operator=(std::move(getShowcaseMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getShowcaseMasterResult.m_pData;
        getShowcaseMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetShowcaseMasterResult* operator->() const
    {
        return this;
    }

    GetShowcaseMasterResult* operator->()
    {
        return this;
    }
    /**
     * 陳列棚マスターを取得
     *
     * @return 陳列棚マスター
     */
    const optional<ShowcaseMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 陳列棚マスターを設定
     *
     * @param item 陳列棚マスター
     */
    void setItem(const ShowcaseMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetShowcaseMasterResult> AsyncGetShowcaseMasterResult;

} }

#endif //GS2_SHOWCASE_CONTROL_GETSHOWCASEMASTERRESULT_HPP_