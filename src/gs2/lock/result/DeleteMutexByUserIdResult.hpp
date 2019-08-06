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

#ifndef GS2_LOCK_CONTROL_DELETEMUTEXBYUSERIDRESULT_HPP_
#define GS2_LOCK_CONTROL_DELETEMUTEXBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace lock
{

/**
 * ミューテックスを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteMutexByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミューテックス */
        optional<Mutex> item;

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
    DeleteMutexByUserIdResult() :
        m_pData(nullptr)
    {}

    DeleteMutexByUserIdResult(const DeleteMutexByUserIdResult& deleteMutexByUserIdResult) :
        Gs2Object(deleteMutexByUserIdResult),
        m_pData(deleteMutexByUserIdResult.m_pData != nullptr ? new Data(*deleteMutexByUserIdResult.m_pData) : nullptr)
    {}

    DeleteMutexByUserIdResult(DeleteMutexByUserIdResult&& deleteMutexByUserIdResult) :
        Gs2Object(std::move(deleteMutexByUserIdResult)),
        m_pData(deleteMutexByUserIdResult.m_pData)
    {
        deleteMutexByUserIdResult.m_pData = nullptr;
    }

    ~DeleteMutexByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMutexByUserIdResult& operator=(const DeleteMutexByUserIdResult& deleteMutexByUserIdResult)
    {
        Gs2Object::operator=(deleteMutexByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMutexByUserIdResult.m_pData);

        return *this;
    }

    DeleteMutexByUserIdResult& operator=(DeleteMutexByUserIdResult&& deleteMutexByUserIdResult)
    {
        Gs2Object::operator=(std::move(deleteMutexByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMutexByUserIdResult.m_pData;
        deleteMutexByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DeleteMutexByUserIdResult* operator->() const
    {
        return this;
    }

    DeleteMutexByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * ミューテックスを取得
     *
     * @return ミューテックス
     */
    const optional<Mutex>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ミューテックスを設定
     *
     * @param item ミューテックス
     */
    void setItem(const Mutex& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOCK_CONTROL_DELETEMUTEXBYUSERIDRESULT_HPP_