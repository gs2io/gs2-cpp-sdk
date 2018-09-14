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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_CREATECERTIFICATERESULT_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_CREATECERTIFICATERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inGamePushNotification
{

/**
 * @author Game Server Services, Inc.
 */
class CreateCertificateResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クライアント証明書 */
        optional<Certificate> item;

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
    CreateCertificateResult() :
        m_pData(nullptr)
    {}

    CreateCertificateResult(const CreateCertificateResult& createCertificateResult) :
        Gs2Object(createCertificateResult),
        m_pData(createCertificateResult.m_pData != nullptr ? new Data(*createCertificateResult.m_pData) : nullptr)
    {}

    CreateCertificateResult(CreateCertificateResult&& createCertificateResult) :
        Gs2Object(std::move(createCertificateResult)),
        m_pData(createCertificateResult.m_pData)
    {
        createCertificateResult.m_pData = nullptr;
    }

    ~CreateCertificateResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateCertificateResult& operator=(const CreateCertificateResult& createCertificateResult)
    {
        Gs2Object::operator=(createCertificateResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createCertificateResult.m_pData);

        return *this;
    }

    CreateCertificateResult& operator=(CreateCertificateResult&& createCertificateResult)
    {
        Gs2Object::operator=(std::move(createCertificateResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createCertificateResult.m_pData;
        createCertificateResult.m_pData = nullptr;

        return *this;
    }

    const CreateCertificateResult* operator->() const
    {
        return this;
    }

    CreateCertificateResult* operator->()
    {
        return this;
    }


    /**
     * クライアント証明書を取得
     *
     * @return クライアント証明書
     */
    const optional<Certificate>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クライアント証明書を設定
     *
     * @param item クライアント証明書
     */
    void setItem(const Certificate& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_CREATECERTIFICATERESULT_HPP_