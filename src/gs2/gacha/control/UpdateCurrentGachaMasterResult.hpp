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

#ifndef GS2_GACHA_CONTROL_UPDATECURRENTGACHAMASTERRESULT_HPP_
#define GS2_GACHA_CONTROL_UPDATECURRENTGACHAMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateCurrentGachaMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 現在適用されているガチャマスターデータ */
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
    UpdateCurrentGachaMasterResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentGachaMasterResult(const UpdateCurrentGachaMasterResult& updateCurrentGachaMasterResult) :
        Gs2Object(updateCurrentGachaMasterResult),
        m_pData(updateCurrentGachaMasterResult.m_pData != nullptr ? new Data(*updateCurrentGachaMasterResult.m_pData) : nullptr)
    {}

    UpdateCurrentGachaMasterResult(UpdateCurrentGachaMasterResult&& updateCurrentGachaMasterResult) :
        Gs2Object(std::move(updateCurrentGachaMasterResult)),
        m_pData(updateCurrentGachaMasterResult.m_pData)
    {
        updateCurrentGachaMasterResult.m_pData = nullptr;
    }

    ~UpdateCurrentGachaMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentGachaMasterResult& operator=(const UpdateCurrentGachaMasterResult& updateCurrentGachaMasterResult)
    {
        Gs2Object::operator=(updateCurrentGachaMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentGachaMasterResult.m_pData);

        return *this;
    }

    UpdateCurrentGachaMasterResult& operator=(UpdateCurrentGachaMasterResult&& updateCurrentGachaMasterResult)
    {
        Gs2Object::operator=(std::move(updateCurrentGachaMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentGachaMasterResult.m_pData;
        updateCurrentGachaMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentGachaMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentGachaMasterResult* operator->()
    {
        return this;
    }


    /**
     * 現在適用されているガチャマスターデータを取得
     *
     * @return 現在適用されているガチャマスターデータ
     */
    const optional<StringHolder>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 現在適用されているガチャマスターデータを設定
     *
     * @param item 現在適用されているガチャマスターデータ
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

#endif //GS2_GACHA_CONTROL_UPDATECURRENTGACHAMASTERRESULT_HPP_