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

#ifndef GS2_GATEWAY_CONTROL_SETFIREBASETOKENRESULT_HPP_
#define GS2_GATEWAY_CONTROL_SETFIREBASETOKENRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gateway
{

/**
 * デバイストークンを設定 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SetFirebaseTokenResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したFirebaseデバイストークン */
        optional<FirebaseToken> item;

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
    SetFirebaseTokenResult() :
        m_pData(nullptr)
    {}

    SetFirebaseTokenResult(const SetFirebaseTokenResult& setFirebaseTokenResult) :
        Gs2Object(setFirebaseTokenResult),
        m_pData(setFirebaseTokenResult.m_pData != nullptr ? new Data(*setFirebaseTokenResult.m_pData) : nullptr)
    {}

    SetFirebaseTokenResult(SetFirebaseTokenResult&& setFirebaseTokenResult) :
        Gs2Object(std::move(setFirebaseTokenResult)),
        m_pData(setFirebaseTokenResult.m_pData)
    {
        setFirebaseTokenResult.m_pData = nullptr;
    }

    ~SetFirebaseTokenResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetFirebaseTokenResult& operator=(const SetFirebaseTokenResult& setFirebaseTokenResult)
    {
        Gs2Object::operator=(setFirebaseTokenResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setFirebaseTokenResult.m_pData);

        return *this;
    }

    SetFirebaseTokenResult& operator=(SetFirebaseTokenResult&& setFirebaseTokenResult)
    {
        Gs2Object::operator=(std::move(setFirebaseTokenResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setFirebaseTokenResult.m_pData;
        setFirebaseTokenResult.m_pData = nullptr;

        return *this;
    }

    const SetFirebaseTokenResult* operator->() const
    {
        return this;
    }

    SetFirebaseTokenResult* operator->()
    {
        return this;
    }
    /**
     * 作成したFirebaseデバイストークンを取得
     *
     * @return 作成したFirebaseデバイストークン
     */
    const optional<FirebaseToken>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したFirebaseデバイストークンを設定
     *
     * @param item 作成したFirebaseデバイストークン
     */
    void setItem(const FirebaseToken& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SETFIREBASETOKENRESULT_HPP_