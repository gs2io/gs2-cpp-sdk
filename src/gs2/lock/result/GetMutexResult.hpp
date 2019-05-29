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

#ifndef GS2_LOCK_CONTROL_GETMUTEXRESULT_HPP_
#define GS2_LOCK_CONTROL_GETMUTEXRESULT_HPP_

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
 * ミューテックスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMutexResult : public Gs2Object
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
    GetMutexResult() :
        m_pData(nullptr)
    {}

    GetMutexResult(const GetMutexResult& getMutexResult) :
        Gs2Object(getMutexResult),
        m_pData(getMutexResult.m_pData != nullptr ? new Data(*getMutexResult.m_pData) : nullptr)
    {}

    GetMutexResult(GetMutexResult&& getMutexResult) :
        Gs2Object(std::move(getMutexResult)),
        m_pData(getMutexResult.m_pData)
    {
        getMutexResult.m_pData = nullptr;
    }

    ~GetMutexResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMutexResult& operator=(const GetMutexResult& getMutexResult)
    {
        Gs2Object::operator=(getMutexResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMutexResult.m_pData);

        return *this;
    }

    GetMutexResult& operator=(GetMutexResult&& getMutexResult)
    {
        Gs2Object::operator=(std::move(getMutexResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMutexResult.m_pData;
        getMutexResult.m_pData = nullptr;

        return *this;
    }

    const GetMutexResult* operator->() const
    {
        return this;
    }

    GetMutexResult* operator->()
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

#endif //GS2_LOCK_CONTROL_GETMUTEXRESULT_HPP_