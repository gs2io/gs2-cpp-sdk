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

#ifndef GS2_CORE_MODEL_NOTIFICATIONMESSAGE_HPP_
#define GS2_CORE_MODEL_NOTIFICATIONMESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

GS2_START_OF_NAMESPACE

/**
 * �ʒm���b�Z�[�W
 *
 * @author Game Server Services, Inc.
 *
 */
class NotificationMessage : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ���b�Z�[�W�̔��s�� */
        optional<StringHolder> issuer;
        /** ���b�Z�[�W�̑薼 */
        optional<StringHolder> subject;
        /** ���b�Z�[�W�̃y�C���[�h */
        optional<StringHolder> payload;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            issuer(data.issuer),
            subject(data.subject),
            payload(data.payload)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            issuer(std::move(data.issuer)),
            subject(std::move(data.subject)),
            payload(std::move(data.payload))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "issuer") == 0) {
                if (jsonValue.IsString())
                {
                    this->issuer.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "subject") == 0) {
                if (jsonValue.IsString())
                {
                    this->subject.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "payload") == 0) {
                if (jsonValue.IsString())
                {
                    this->payload.emplace(jsonValue.GetString());
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
    NotificationMessage() :
        m_pData(nullptr)
    {}

    NotificationMessage(const NotificationMessage& notificationMessage) :
        Gs2Object(notificationMessage),
        m_pData(notificationMessage.m_pData != nullptr ? new Data(*notificationMessage.m_pData) : nullptr)
    {}

    NotificationMessage(NotificationMessage&& notificationMessage) :
        Gs2Object(std::move(notificationMessage)),
        m_pData(notificationMessage.m_pData)
    {
        notificationMessage.m_pData = nullptr;
    }

    ~NotificationMessage()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    NotificationMessage& operator=(const NotificationMessage& notificationMessage)
    {
        Gs2Object::operator=(notificationMessage);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*notificationMessage.m_pData);

        return *this;
    }

    NotificationMessage& operator=(NotificationMessage&& notificationMessage)
    {
        Gs2Object::operator=(std::move(notificationMessage));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = notificationMessage.m_pData;
        notificationMessage.m_pData = nullptr;

        return *this;
    }

    const NotificationMessage* operator->() const
    {
        return this;
    }

    NotificationMessage* operator->()
    {
        return this;
    }


    /**
     * ���b�Z�[�W�̔��s�҂��擾
     *
     * @return ���b�Z�[�W�̔��s��
     */
    const optional<StringHolder>& getIssuer() const
    {
        return ensureData().issuer;
    }

    /**
     * ���b�Z�[�W�̔��s�҂�ݒ�
     *
     * @param issuer ���b�Z�[�W�̔��s��
     */
    void setIssuer(const Char* issuer)
    {
        ensureData().issuer.emplace(issuer);
    }

    /**
     * ���b�Z�[�W�̑薼���擾
     *
     * @return ���b�Z�[�W�̑薼
     */
    const optional<StringHolder>& getSubject() const
    {
        return ensureData().subject;
    }

    /**
     * ���b�Z�[�W�̑薼��ݒ�
     *
     * @param subject ���b�Z�[�W�̑薼
     */
    void setSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
    }

    /**
     * ���b�Z�[�W�̃y�C���[�h���擾
     *
     * @return ���b�Z�[�W�̃y�C���[�h
     */
    const optional<StringHolder>& getPayload() const
    {
        return ensureData().payload;
    }

    /**
     * ���b�Z�[�W�̃y�C���[�h��ݒ�
     *
     * @param payload ���b�Z�[�W�̃y�C���[�h
     */
    void setPayload(const Char* payload)
    {
        ensureData().payload.emplace(payload);
    }


    template<typename T>
    optional<T> getPayload() const
    {
        optional<T> out;
        if (getPayload())
        {
            out.emplace();
            detail::json::JsonParser::parse(&out->getModel(), *getPayload());
        }
        return out;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_NOTIFICATIONMESSAGE_HPP_
