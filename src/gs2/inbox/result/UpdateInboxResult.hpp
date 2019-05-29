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

#ifndef GS2_INBOX_CONTROL_UPDATEINBOXRESULT_HPP_
#define GS2_INBOX_CONTROL_UPDATEINBOXRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * プレゼントボックスを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateInboxResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したプレゼントボックス */
        optional<Inbox> item;

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
    UpdateInboxResult() :
        m_pData(nullptr)
    {}

    UpdateInboxResult(const UpdateInboxResult& updateInboxResult) :
        Gs2Object(updateInboxResult),
        m_pData(updateInboxResult.m_pData != nullptr ? new Data(*updateInboxResult.m_pData) : nullptr)
    {}

    UpdateInboxResult(UpdateInboxResult&& updateInboxResult) :
        Gs2Object(std::move(updateInboxResult)),
        m_pData(updateInboxResult.m_pData)
    {
        updateInboxResult.m_pData = nullptr;
    }

    ~UpdateInboxResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateInboxResult& operator=(const UpdateInboxResult& updateInboxResult)
    {
        Gs2Object::operator=(updateInboxResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateInboxResult.m_pData);

        return *this;
    }

    UpdateInboxResult& operator=(UpdateInboxResult&& updateInboxResult)
    {
        Gs2Object::operator=(std::move(updateInboxResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateInboxResult.m_pData;
        updateInboxResult.m_pData = nullptr;

        return *this;
    }

    const UpdateInboxResult* operator->() const
    {
        return this;
    }

    UpdateInboxResult* operator->()
    {
        return this;
    }
    /**
     * 更新したプレゼントボックスを取得
     *
     * @return 更新したプレゼントボックス
     */
    const optional<Inbox>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したプレゼントボックスを設定
     *
     * @param item 更新したプレゼントボックス
     */
    void setItem(const Inbox& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_UPDATEINBOXRESULT_HPP_