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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_CERTIFICATE_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_CERTIFICATE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * クライアント証明書
 *
 * @author Game Server Services, Inc.
 *
 */
class Certificate : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 証明書ID */
        optional<StringHolder> certificateId;
        /** クライアント証明書 */
        optional<StringHolder> certificate;
        /** 秘密鍵 */
        optional<StringHolder> privateKey;
        /** PFXフォーマットの秘密鍵 */
        optional<StringHolder> pfx;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            certificateId(data.certificateId),
            certificate(data.certificate),
            privateKey(data.privateKey),
            pfx(data.pfx)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            certificateId(std::move(data.certificateId)),
            certificate(std::move(data.certificate)),
            privateKey(std::move(data.privateKey)),
            pfx(std::move(data.pfx))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "certificateId") == 0) {
                if (jsonValue.IsString())
                {
                    this->certificateId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "certificate") == 0) {
                if (jsonValue.IsString())
                {
                    this->certificate.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "privateKey") == 0) {
                if (jsonValue.IsString())
                {
                    this->privateKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "pfx") == 0) {
                if (jsonValue.IsString())
                {
                    this->pfx.emplace(jsonValue.GetString());
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
    Certificate() :
        m_pData(nullptr)
    {}

    Certificate(const Certificate& certificate) :
        Gs2Object(certificate),
        m_pData(certificate.m_pData != nullptr ? new Data(*certificate.m_pData) : nullptr)
    {}

    Certificate(Certificate&& certificate) :
        Gs2Object(std::move(certificate)),
        m_pData(certificate.m_pData)
    {
        certificate.m_pData = nullptr;
    }

    ~Certificate()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Certificate& operator=(const Certificate& certificate)
    {
        Gs2Object::operator=(certificate);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*certificate.m_pData);

        return *this;
    }

    Certificate& operator=(Certificate&& certificate)
    {
        Gs2Object::operator=(std::move(certificate));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = certificate.m_pData;
        certificate.m_pData = nullptr;

        return *this;
    }

    const Certificate* operator->() const
    {
        return this;
    }

    Certificate* operator->()
    {
        return this;
    }


    /**
     * 証明書IDを取得
     *
     * @return 証明書ID
     */
    const optional<StringHolder>& getCertificateId() const
    {
        return ensureData().certificateId;
    }

    /**
     * 証明書IDを設定
     *
     * @param certificateId 証明書ID
     */
    void setCertificateId(const Char* certificateId)
    {
        ensureData().certificateId.emplace(certificateId);
    }

    /**
     * クライアント証明書を取得
     *
     * @return クライアント証明書
     */
    const optional<StringHolder>& getCertificate() const
    {
        return ensureData().certificate;
    }

    /**
     * クライアント証明書を設定
     *
     * @param certificate クライアント証明書
     */
    void setCertificate(const Char* certificate)
    {
        ensureData().certificate.emplace(certificate);
    }

    /**
     * 秘密鍵を取得
     *
     * @return 秘密鍵
     */
    const optional<StringHolder>& getPrivateKey() const
    {
        return ensureData().privateKey;
    }

    /**
     * 秘密鍵を設定
     *
     * @param privateKey 秘密鍵
     */
    void setPrivateKey(const Char* privateKey)
    {
        ensureData().privateKey.emplace(privateKey);
    }

    /**
     * PFXフォーマットの秘密鍵を取得
     *
     * @return PFXフォーマットの秘密鍵
     */
    const optional<StringHolder>& getPfx() const
    {
        return ensureData().pfx;
    }

    /**
     * PFXフォーマットの秘密鍵を設定
     *
     * @param pfx PFXフォーマットの秘密鍵
     */
    void setPfx(const Char* pfx)
    {
        ensureData().pfx.emplace(pfx);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_CERTIFICATE_HPP_