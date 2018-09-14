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

#ifndef GS2_GOLD_CONTROL_GETCURRENTGOLDMASTERRESULT_HPP_
#define GS2_GOLD_CONTROL_GETCURRENTGOLDMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gold
{

/**
 * @author Game Server Services, Inc.
 */
class GetCurrentGoldMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在適用されているゴールドマスターデータ */
        optional<StringHolder> item;

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
                if (jsonValue.IsString())
                {
                    this->item.emplace(jsonValue.GetString());
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
    GetCurrentGoldMasterResult() :
        m_pData(nullptr)
    {}

    GetCurrentGoldMasterResult(const GetCurrentGoldMasterResult& getCurrentGoldMasterResult) :
        Gs2Object(getCurrentGoldMasterResult),
        m_pData(getCurrentGoldMasterResult.m_pData != nullptr ? new Data(*getCurrentGoldMasterResult.m_pData) : nullptr)
    {}

    GetCurrentGoldMasterResult(GetCurrentGoldMasterResult&& getCurrentGoldMasterResult) :
        Gs2Object(std::move(getCurrentGoldMasterResult)),
        m_pData(getCurrentGoldMasterResult.m_pData)
    {
        getCurrentGoldMasterResult.m_pData = nullptr;
    }

    ~GetCurrentGoldMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetCurrentGoldMasterResult& operator=(const GetCurrentGoldMasterResult& getCurrentGoldMasterResult)
    {
        Gs2Object::operator=(getCurrentGoldMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getCurrentGoldMasterResult.m_pData);

        return *this;
    }

    GetCurrentGoldMasterResult& operator=(GetCurrentGoldMasterResult&& getCurrentGoldMasterResult)
    {
        Gs2Object::operator=(std::move(getCurrentGoldMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getCurrentGoldMasterResult.m_pData;
        getCurrentGoldMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetCurrentGoldMasterResult* operator->() const
    {
        return this;
    }

    GetCurrentGoldMasterResult* operator->()
    {
        return this;
    }


    /**
     * 現在適用されているゴールドマスターデータを取得
     *
     * @return 現在適用されているゴールドマスターデータ
     */
    const optional<StringHolder>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在適用されているゴールドマスターデータを設定
     *
     * @param item 現在適用されているゴールドマスターデータ
     */
    void setItem(const Char* item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GOLD_CONTROL_GETCURRENTGOLDMASTERRESULT_HPP_