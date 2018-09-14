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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_PUBLISHRESPONSE_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_PUBLISHRESPONSE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * 通知結果
 *
 * @author Game Server Services, Inc.
 *
 */
class PublishResponse : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 通知に使用した方式 */
        optional<StringHolder> type;
        /** 件名 */
        optional<StringHolder> subject;
        /** 本文 */
        optional<StringHolder> body;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            type(data.type),
            subject(data.subject),
            body(data.body)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            type(std::move(data.type)),
            subject(std::move(data.subject)),
            body(std::move(data.body))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "subject") == 0) {
                if (jsonValue.IsString())
                {
                    this->subject.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "body") == 0) {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
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
    PublishResponse() :
        m_pData(nullptr)
    {}

    PublishResponse(const PublishResponse& publishResponse) :
        Gs2Object(publishResponse),
        m_pData(publishResponse.m_pData != nullptr ? new Data(*publishResponse.m_pData) : nullptr)
    {}

    PublishResponse(PublishResponse&& publishResponse) :
        Gs2Object(std::move(publishResponse)),
        m_pData(publishResponse.m_pData)
    {
        publishResponse.m_pData = nullptr;
    }

    ~PublishResponse()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PublishResponse& operator=(const PublishResponse& publishResponse)
    {
        Gs2Object::operator=(publishResponse);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*publishResponse.m_pData);

        return *this;
    }

    PublishResponse& operator=(PublishResponse&& publishResponse)
    {
        Gs2Object::operator=(std::move(publishResponse));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = publishResponse.m_pData;
        publishResponse.m_pData = nullptr;

        return *this;
    }

    const PublishResponse* operator->() const
    {
        return this;
    }

    PublishResponse* operator->()
    {
        return this;
    }


    /**
     * 通知に使用した方式を取得
     *
     * @return 通知に使用した方式
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 通知に使用した方式を設定
     *
     * @param type 通知に使用した方式
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 件名を取得
     *
     * @return 件名
     */
    const optional<StringHolder>& getSubject() const
    {
        return ensureData().subject;
    }

    /**
     * 件名を設定
     *
     * @param subject 件名
     */
    void setSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
    }

    /**
     * 本文を取得
     *
     * @return 本文
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 本文を設定
     *
     * @param body 本文
     */
    void setBody(const Char* body)
    {
        ensureData().body.emplace(body);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_PUBLISHRESPONSE_HPP_