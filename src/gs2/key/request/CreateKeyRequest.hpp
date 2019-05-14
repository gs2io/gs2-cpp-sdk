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

#ifndef GS2_KEY_CONTROL_CREATEKEYREQUEST_HPP_
#define GS2_KEY_CONTROL_CREATEKEYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2KeyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * 暗号鍵を新規作成します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateKeyRequest : public Gs2BasicRequest, public Gs2Key
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 暗号鍵名 */
        optional<StringHolder> name;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    CreateKeyRequest() :
        m_pData(nullptr)
    {}

    CreateKeyRequest(const CreateKeyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Key(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateKeyRequest(CreateKeyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Key(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateKeyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateKeyRequest& operator=(const CreateKeyRequest& createKeyRequest)
    {
        Gs2BasicRequest::operator=(createKeyRequest);
        Gs2Key::operator=(createKeyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createKeyRequest.m_pData);

        return *this;
    }

    CreateKeyRequest& operator=(CreateKeyRequest&& createKeyRequest)
    {
        Gs2BasicRequest::operator=(std::move(createKeyRequest));
        Gs2Key::operator=(std::move(createKeyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createKeyRequest.m_pData;
        createKeyRequest.m_pData = nullptr;

        return *this;
    }

    const CreateKeyRequest* operator->() const
    {
        return this;
    }

    CreateKeyRequest* operator->()
    {
        return this;
    }
    /**
     * 暗号鍵名を取得
     *
     * @return 暗号鍵名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 暗号鍵名を設定
     *
     * @param name 暗号鍵名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 暗号鍵名を設定
     *
     * @param name 暗号鍵名
     */
    CreateKeyRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateKeyRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateKeyRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateKeyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateKeyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_KEY_CONTROL_CREATEKEYREQUEST_HPP_