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

#ifndef GS2_LOTTERY_CONTROL_GETBOXBYUSERIDRESULT_HPP_
#define GS2_LOTTERY_CONTROL_GETBOXBYUSERIDRESULT_HPP_

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
 * ユーザIDを指定してボックスを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetBoxByUserIdResult : public Gs2Object
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
    GetBoxByUserIdResult() :
        m_pData(nullptr)
    {}

    GetBoxByUserIdResult(const GetBoxByUserIdResult& getBoxByUserIdResult) :
        Gs2Object(getBoxByUserIdResult),
        m_pData(getBoxByUserIdResult.m_pData != nullptr ? new Data(*getBoxByUserIdResult.m_pData) : nullptr)
    {}

    GetBoxByUserIdResult(GetBoxByUserIdResult&& getBoxByUserIdResult) :
        Gs2Object(std::move(getBoxByUserIdResult)),
        m_pData(getBoxByUserIdResult.m_pData)
    {
        getBoxByUserIdResult.m_pData = nullptr;
    }

    ~GetBoxByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetBoxByUserIdResult& operator=(const GetBoxByUserIdResult& getBoxByUserIdResult)
    {
        Gs2Object::operator=(getBoxByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getBoxByUserIdResult.m_pData);

        return *this;
    }

    GetBoxByUserIdResult& operator=(GetBoxByUserIdResult&& getBoxByUserIdResult)
    {
        Gs2Object::operator=(std::move(getBoxByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getBoxByUserIdResult.m_pData;
        getBoxByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetBoxByUserIdResult* operator->() const
    {
        return this;
    }

    GetBoxByUserIdResult* operator->()
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

typedef AsyncResult<GetBoxByUserIdResult> AsyncGetBoxByUserIdResult;

} }

#endif //GS2_LOTTERY_CONTROL_GETBOXBYUSERIDRESULT_HPP_