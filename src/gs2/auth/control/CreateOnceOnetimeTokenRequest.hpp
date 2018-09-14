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

#ifndef GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENREQUEST_HPP_
#define GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AuthConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace auth
{

/**
 * @author Game Server Services, Inc.
 */
class CreateOnceOnetimeTokenRequest : public Gs2BasicRequest, public Gs2Auth
{
public:
    constexpr static const Char* const FUNCTION = "CreateOnceOnetimeToken";

private:
    class Data : public Gs2Object
    {
    public:
        /** 認可処理に実行するスクリプト */
        optional<StringHolder> scriptName;
        /** 認可するアクション */
        optional<StringHolder> grant;
        /** grant で指定したアクションに引数として渡すことを許可する内容 */
        optional<StringHolder> args;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scriptName(data.scriptName),
            grant(data.grant),
            args(data.args)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scriptName(std::move(data.scriptName)),
            grant(std::move(data.grant)),
            args(std::move(data.args))
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
    CreateOnceOnetimeTokenRequest() :
        m_pData(nullptr)
    {}

    CreateOnceOnetimeTokenRequest(const CreateOnceOnetimeTokenRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Auth(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateOnceOnetimeTokenRequest(CreateOnceOnetimeTokenRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Auth(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateOnceOnetimeTokenRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateOnceOnetimeTokenRequest& operator=(const CreateOnceOnetimeTokenRequest& createOnceOnetimeTokenRequest)
    {
        Gs2BasicRequest::operator=(createOnceOnetimeTokenRequest);
        Gs2Auth::operator=(createOnceOnetimeTokenRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createOnceOnetimeTokenRequest.m_pData);

        return *this;
    }

    CreateOnceOnetimeTokenRequest& operator=(CreateOnceOnetimeTokenRequest&& createOnceOnetimeTokenRequest)
    {
        Gs2BasicRequest::operator=(std::move(createOnceOnetimeTokenRequest));
        Gs2Auth::operator=(std::move(createOnceOnetimeTokenRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createOnceOnetimeTokenRequest.m_pData;
        createOnceOnetimeTokenRequest.m_pData = nullptr;

        return *this;
    }

    const CreateOnceOnetimeTokenRequest* operator->() const
    {
        return this;
    }

    CreateOnceOnetimeTokenRequest* operator->()
    {
        return this;
    }

    /**
     * 認可処理に実行するスクリプトを取得
     *
     * @return 認可処理に実行するスクリプト
     */
    const optional<StringHolder>& getScriptName() const
    {
        return ensureData().scriptName;
    }

    /**
     * 認可処理に実行するスクリプトを設定
     *
     * @param scriptName 認可処理に実行するスクリプト
     */
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * 認可処理に実行するスクリプトを設定
     *
     * @param scriptName 認可処理に実行するスクリプト
     */
    CreateOnceOnetimeTokenRequest& withScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
        return *this;
    }

    /**
     * 認可するアクションを取得
     *
     * @return 認可するアクション
     */
    const optional<StringHolder>& getGrant() const
    {
        return ensureData().grant;
    }

    /**
     * 認可するアクションを設定
     *
     * @param grant 認可するアクション
     */
    void setGrant(const Char* grant)
    {
        ensureData().grant.emplace(grant);
    }

    /**
     * 認可するアクションを設定
     *
     * @param grant 認可するアクション
     */
    CreateOnceOnetimeTokenRequest& withGrant(const Char* grant)
    {
        ensureData().grant.emplace(grant);
        return *this;
    }

    /**
     * grant で指定したアクションに引数として渡すことを許可する内容を取得
     *
     * @return grant で指定したアクションに引数として渡すことを許可する内容
     */
    const optional<StringHolder>& getArgs() const
    {
        return ensureData().args;
    }

    /**
     * grant で指定したアクションに引数として渡すことを許可する内容を設定
     *
     * @param args grant で指定したアクションに引数として渡すことを許可する内容
     */
    void setArgs(const Char* args)
    {
        ensureData().args.emplace(args);
    }

    /**
     * grant で指定したアクションに引数として渡すことを許可する内容を設定
     *
     * @param args grant で指定したアクションに引数として渡すことを許可する内容
     */
    CreateOnceOnetimeTokenRequest& withArgs(const Char* args)
    {
        ensureData().args.emplace(args);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateOnceOnetimeTokenRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateOnceOnetimeTokenRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateOnceOnetimeTokenRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateOnceOnetimeTokenRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENREQUEST_HPP_