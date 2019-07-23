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

#ifndef GS2_PROJECT_CONTROL_CREATEPROJECTREQUEST_HPP_
#define GS2_PROJECT_CONTROL_CREATEPROJECTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * プロジェクトを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateProjectRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** GS2アカウントトークン */
        optional<StringHolder> accountToken;
        /** プロジェクト名 */
        optional<StringHolder> name;
        /** プロジェクトの説明 */
        optional<StringHolder> description;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accountToken(data.accountToken),
            name(data.name),
            description(data.description)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accountToken(std::move(data.accountToken)),
            name(std::move(data.name)),
            description(std::move(data.description))
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
    CreateProjectRequest() :
        m_pData(nullptr)
    {}

    CreateProjectRequest(const CreateProjectRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Project(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateProjectRequest(CreateProjectRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Project(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateProjectRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateProjectRequest& operator=(const CreateProjectRequest& createProjectRequest)
    {
        Gs2BasicRequest::operator=(createProjectRequest);
        Gs2Project::operator=(createProjectRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createProjectRequest.m_pData);

        return *this;
    }

    CreateProjectRequest& operator=(CreateProjectRequest&& createProjectRequest)
    {
        Gs2BasicRequest::operator=(std::move(createProjectRequest));
        Gs2Project::operator=(std::move(createProjectRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createProjectRequest.m_pData;
        createProjectRequest.m_pData = nullptr;

        return *this;
    }

    const CreateProjectRequest* operator->() const
    {
        return this;
    }

    CreateProjectRequest* operator->()
    {
        return this;
    }
    /**
     * GS2アカウントトークンを取得
     *
     * @return GS2アカウントトークン
     */
    const optional<StringHolder>& getAccountToken() const
    {
        return ensureData().accountToken;
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    void setAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    CreateProjectRequest& withAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
        return *this;
    }

    /**
     * プロジェクト名を取得
     *
     * @return プロジェクト名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * プロジェクト名を設定
     *
     * @param name プロジェクト名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * プロジェクト名を設定
     *
     * @param name プロジェクト名
     */
    CreateProjectRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * プロジェクトの説明を取得
     *
     * @return プロジェクトの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * プロジェクトの説明を設定
     *
     * @param description プロジェクトの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * プロジェクトの説明を設定
     *
     * @param description プロジェクトの説明
     */
    CreateProjectRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateProjectRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateProjectRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateProjectRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateProjectRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_PROJECT_CONTROL_CREATEPROJECTREQUEST_HPP_