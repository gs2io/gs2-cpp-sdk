/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_CHAT_CONTROL_GETMYSUBSCRIBERESULT_HPP_
#define GS2_CHAT_CONTROL_GETMYSUBSCRIBERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class GetMySubscribeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 購読 */
        optional<Subscribe> item;

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
    GetMySubscribeResult() :
        m_pData(nullptr)
    {}

    GetMySubscribeResult(const GetMySubscribeResult& getMySubscribeResult) :
        Gs2Object(getMySubscribeResult),
        m_pData(getMySubscribeResult.m_pData != nullptr ? new Data(*getMySubscribeResult.m_pData) : nullptr)
    {}

    GetMySubscribeResult(GetMySubscribeResult&& getMySubscribeResult) :
        Gs2Object(std::move(getMySubscribeResult)),
        m_pData(getMySubscribeResult.m_pData)
    {
        getMySubscribeResult.m_pData = nullptr;
    }

    ~GetMySubscribeResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMySubscribeResult& operator=(const GetMySubscribeResult& getMySubscribeResult)
    {
        Gs2Object::operator=(getMySubscribeResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMySubscribeResult.m_pData);

        return *this;
    }

    GetMySubscribeResult& operator=(GetMySubscribeResult&& getMySubscribeResult)
    {
        Gs2Object::operator=(std::move(getMySubscribeResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMySubscribeResult.m_pData;
        getMySubscribeResult.m_pData = nullptr;

        return *this;
    }

    const GetMySubscribeResult* operator->() const
    {
        return this;
    }

    GetMySubscribeResult* operator->()
    {
        return this;
    }


    /**
     * 購読を取得
     *
     * @return 購読
     */
    const optional<Subscribe>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 購読を設定
     *
     * @param item 購読
     */
    void setItem(const Subscribe& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_CONTROL_GETMYSUBSCRIBERESULT_HPP_