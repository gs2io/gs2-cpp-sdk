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

#ifndef GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONRESULT_HPP_
#define GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace notification
{

/**
 * @author Game Server Services, Inc.
 */
class CreateNotificationResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 通知 */
        optional<Notification> item;

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
    CreateNotificationResult() :
        m_pData(nullptr)
    {}

    CreateNotificationResult(const CreateNotificationResult& createNotificationResult) :
        Gs2Object(createNotificationResult),
        m_pData(createNotificationResult.m_pData != nullptr ? new Data(*createNotificationResult.m_pData) : nullptr)
    {}

    CreateNotificationResult(CreateNotificationResult&& createNotificationResult) :
        Gs2Object(std::move(createNotificationResult)),
        m_pData(createNotificationResult.m_pData)
    {
        createNotificationResult.m_pData = nullptr;
    }

    ~CreateNotificationResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNotificationResult& operator=(const CreateNotificationResult& createNotificationResult)
    {
        Gs2Object::operator=(createNotificationResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNotificationResult.m_pData);

        return *this;
    }

    CreateNotificationResult& operator=(CreateNotificationResult&& createNotificationResult)
    {
        Gs2Object::operator=(std::move(createNotificationResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNotificationResult.m_pData;
        createNotificationResult.m_pData = nullptr;

        return *this;
    }

    const CreateNotificationResult* operator->() const
    {
        return this;
    }

    CreateNotificationResult* operator->()
    {
        return this;
    }


    /**
     * 通知を取得
     *
     * @return 通知
     */
    const optional<Notification>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 通知を設定
     *
     * @param item 通知
     */
    void setItem(const Notification& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONRESULT_HPP_