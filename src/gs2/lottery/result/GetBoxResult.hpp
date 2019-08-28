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

#ifndef GS2_LOTTERY_CONTROL_GETBOXRESULT_HPP_
#define GS2_LOTTERY_CONTROL_GETBOXRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace lottery
{

/**
 * ボックスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetBoxResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ボックスから取り出したアイテムのリスト */
        optional<BoxItems> item;

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
    GetBoxResult() :
        m_pData(nullptr)
    {}

    GetBoxResult(const GetBoxResult& getBoxResult) :
        Gs2Object(getBoxResult),
        m_pData(getBoxResult.m_pData != nullptr ? new Data(*getBoxResult.m_pData) : nullptr)
    {}

    GetBoxResult(GetBoxResult&& getBoxResult) :
        Gs2Object(std::move(getBoxResult)),
        m_pData(getBoxResult.m_pData)
    {
        getBoxResult.m_pData = nullptr;
    }

    ~GetBoxResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetBoxResult& operator=(const GetBoxResult& getBoxResult)
    {
        Gs2Object::operator=(getBoxResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getBoxResult.m_pData);

        return *this;
    }

    GetBoxResult& operator=(GetBoxResult&& getBoxResult)
    {
        Gs2Object::operator=(std::move(getBoxResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getBoxResult.m_pData;
        getBoxResult.m_pData = nullptr;

        return *this;
    }

    const GetBoxResult* operator->() const
    {
        return this;
    }

    GetBoxResult* operator->()
    {
        return this;
    }
    /**
     * ボックスから取り出したアイテムのリストを取得
     *
     * @return ボックスから取り出したアイテムのリスト
     */
    const optional<BoxItems>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ボックスから取り出したアイテムのリストを設定
     *
     * @param item ボックスから取り出したアイテムのリスト
     */
    void setItem(const BoxItems& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetBoxResult> AsyncGetBoxResult;

} }

#endif //GS2_LOTTERY_CONTROL_GETBOXRESULT_HPP_