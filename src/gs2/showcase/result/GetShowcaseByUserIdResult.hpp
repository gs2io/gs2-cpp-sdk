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

#ifndef GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_

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
 * ユーザIDを指定して陳列棚を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetShowcaseByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚 */
        optional<Showcase> item;

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
    GetShowcaseByUserIdResult() :
        m_pData(nullptr)
    {}

    GetShowcaseByUserIdResult(const GetShowcaseByUserIdResult& getShowcaseByUserIdResult) :
        Gs2Object(getShowcaseByUserIdResult),
        m_pData(getShowcaseByUserIdResult.m_pData != nullptr ? new Data(*getShowcaseByUserIdResult.m_pData) : nullptr)
    {}

    GetShowcaseByUserIdResult(GetShowcaseByUserIdResult&& getShowcaseByUserIdResult) :
        Gs2Object(std::move(getShowcaseByUserIdResult)),
        m_pData(getShowcaseByUserIdResult.m_pData)
    {
        getShowcaseByUserIdResult.m_pData = nullptr;
    }

    ~GetShowcaseByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetShowcaseByUserIdResult& operator=(const GetShowcaseByUserIdResult& getShowcaseByUserIdResult)
    {
        Gs2Object::operator=(getShowcaseByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getShowcaseByUserIdResult.m_pData);

        return *this;
    }

    GetShowcaseByUserIdResult& operator=(GetShowcaseByUserIdResult&& getShowcaseByUserIdResult)
    {
        Gs2Object::operator=(std::move(getShowcaseByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getShowcaseByUserIdResult.m_pData;
        getShowcaseByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetShowcaseByUserIdResult* operator->() const
    {
        return this;
    }

    GetShowcaseByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 陳列棚を取得
     *
     * @return 陳列棚
     */
    const optional<Showcase>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 陳列棚を設定
     *
     * @param item 陳列棚
     */
    void setItem(const Showcase& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_GETSHOWCASEBYUSERIDRESULT_HPP_