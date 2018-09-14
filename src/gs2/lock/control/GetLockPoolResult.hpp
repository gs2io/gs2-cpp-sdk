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

#ifndef GS2_LOCK_CONTROL_GETLOCKPOOLRESULT_HPP_
#define GS2_LOCK_CONTROL_GETLOCKPOOLRESULT_HPP_

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
 * @author Game Server Services, Inc.
 */
class GetLockPoolResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ロックプール */
        optional<LockPool> item;

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
    GetLockPoolResult() :
        m_pData(nullptr)
    {}

    GetLockPoolResult(const GetLockPoolResult& getLockPoolResult) :
        Gs2Object(getLockPoolResult),
        m_pData(getLockPoolResult.m_pData != nullptr ? new Data(*getLockPoolResult.m_pData) : nullptr)
    {}

    GetLockPoolResult(GetLockPoolResult&& getLockPoolResult) :
        Gs2Object(std::move(getLockPoolResult)),
        m_pData(getLockPoolResult.m_pData)
    {
        getLockPoolResult.m_pData = nullptr;
    }

    ~GetLockPoolResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetLockPoolResult& operator=(const GetLockPoolResult& getLockPoolResult)
    {
        Gs2Object::operator=(getLockPoolResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getLockPoolResult.m_pData);

        return *this;
    }

    GetLockPoolResult& operator=(GetLockPoolResult&& getLockPoolResult)
    {
        Gs2Object::operator=(std::move(getLockPoolResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getLockPoolResult.m_pData;
        getLockPoolResult.m_pData = nullptr;

        return *this;
    }

    const GetLockPoolResult* operator->() const
    {
        return this;
    }

    GetLockPoolResult* operator->()
    {
        return this;
    }


    /**
     * ロックプールを取得
     *
     * @return ロックプール
     */
    const optional<LockPool>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ロックプールを設定
     *
     * @param item ロックプール
     */
    void setItem(const LockPool& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOCK_CONTROL_GETLOCKPOOLRESULT_HPP_