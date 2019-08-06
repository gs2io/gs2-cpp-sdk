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

#ifndef GS2_JOBQUEUE_CONTROL_GETDEADLETTERJOBBYUSERIDRESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_GETDEADLETTERJOBBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * デッドレタージョブを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetDeadLetterJobByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** デッドレタージョブ */
        optional<DeadLetterJob> item;

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
    GetDeadLetterJobByUserIdResult() :
        m_pData(nullptr)
    {}

    GetDeadLetterJobByUserIdResult(const GetDeadLetterJobByUserIdResult& getDeadLetterJobByUserIdResult) :
        Gs2Object(getDeadLetterJobByUserIdResult),
        m_pData(getDeadLetterJobByUserIdResult.m_pData != nullptr ? new Data(*getDeadLetterJobByUserIdResult.m_pData) : nullptr)
    {}

    GetDeadLetterJobByUserIdResult(GetDeadLetterJobByUserIdResult&& getDeadLetterJobByUserIdResult) :
        Gs2Object(std::move(getDeadLetterJobByUserIdResult)),
        m_pData(getDeadLetterJobByUserIdResult.m_pData)
    {
        getDeadLetterJobByUserIdResult.m_pData = nullptr;
    }

    ~GetDeadLetterJobByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetDeadLetterJobByUserIdResult& operator=(const GetDeadLetterJobByUserIdResult& getDeadLetterJobByUserIdResult)
    {
        Gs2Object::operator=(getDeadLetterJobByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getDeadLetterJobByUserIdResult.m_pData);

        return *this;
    }

    GetDeadLetterJobByUserIdResult& operator=(GetDeadLetterJobByUserIdResult&& getDeadLetterJobByUserIdResult)
    {
        Gs2Object::operator=(std::move(getDeadLetterJobByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getDeadLetterJobByUserIdResult.m_pData;
        getDeadLetterJobByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetDeadLetterJobByUserIdResult* operator->() const
    {
        return this;
    }

    GetDeadLetterJobByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * デッドレタージョブを取得
     *
     * @return デッドレタージョブ
     */
    const optional<DeadLetterJob>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * デッドレタージョブを設定
     *
     * @param item デッドレタージョブ
     */
    void setItem(const DeadLetterJob& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_JOBQUEUE_CONTROL_GETDEADLETTERJOBBYUSERIDRESULT_HPP_