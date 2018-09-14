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

#ifndef GS2_RANKING_CONTROL_UPDATEGAMEMODERESULT_HPP_
#define GS2_RANKING_CONTROL_UPDATEGAMEMODERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace ranking
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateGameModeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームモード */
        optional<GameMode> item;

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
    UpdateGameModeResult() :
        m_pData(nullptr)
    {}

    UpdateGameModeResult(const UpdateGameModeResult& updateGameModeResult) :
        Gs2Object(updateGameModeResult),
        m_pData(updateGameModeResult.m_pData != nullptr ? new Data(*updateGameModeResult.m_pData) : nullptr)
    {}

    UpdateGameModeResult(UpdateGameModeResult&& updateGameModeResult) :
        Gs2Object(std::move(updateGameModeResult)),
        m_pData(updateGameModeResult.m_pData)
    {
        updateGameModeResult.m_pData = nullptr;
    }

    ~UpdateGameModeResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGameModeResult& operator=(const UpdateGameModeResult& updateGameModeResult)
    {
        Gs2Object::operator=(updateGameModeResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGameModeResult.m_pData);

        return *this;
    }

    UpdateGameModeResult& operator=(UpdateGameModeResult&& updateGameModeResult)
    {
        Gs2Object::operator=(std::move(updateGameModeResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGameModeResult.m_pData;
        updateGameModeResult.m_pData = nullptr;

        return *this;
    }

    const UpdateGameModeResult* operator->() const
    {
        return this;
    }

    UpdateGameModeResult* operator->()
    {
        return this;
    }


    /**
     * ゲームモードを取得
     *
     * @return ゲームモード
     */
    const optional<GameMode>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ゲームモードを設定
     *
     * @param item ゲームモード
     */
    void setItem(const GameMode& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_CONTROL_UPDATEGAMEMODERESULT_HPP_