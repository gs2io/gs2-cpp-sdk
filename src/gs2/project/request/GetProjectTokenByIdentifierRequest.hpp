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

#ifndef GS2_PROJECT_CONTROL_GETPROJECTTOKENBYIDENTIFIERREQUEST_HPP_
#define GS2_PROJECT_CONTROL_GETPROJECTTOKENBYIDENTIFIERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/Gs2ProjectConst.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * プロジェクトトークンを発行します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetProjectTokenByIdentifierRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;
        /** プロジェクト名 */
        optional<StringHolder> projectName;
        /** ユーザ名 */
        optional<StringHolder> userName;
        /** パスワード */
        optional<StringHolder> password;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountName(data.accountName),
            projectName(data.projectName),
            userName(data.userName),
            password(data.password)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    GetProjectTokenByIdentifierRequest() = default;
    GetProjectTokenByIdentifierRequest(const GetProjectTokenByIdentifierRequest& getProjectTokenByIdentifierRequest) = default;
    GetProjectTokenByIdentifierRequest(GetProjectTokenByIdentifierRequest&& getProjectTokenByIdentifierRequest) = default;
    ~GetProjectTokenByIdentifierRequest() GS2_OVERRIDE = default;

    GetProjectTokenByIdentifierRequest& operator=(const GetProjectTokenByIdentifierRequest& getProjectTokenByIdentifierRequest) = default;
    GetProjectTokenByIdentifierRequest& operator=(GetProjectTokenByIdentifierRequest&& getProjectTokenByIdentifierRequest) = default;

    GetProjectTokenByIdentifierRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetProjectTokenByIdentifierRequest);
    }

    const GetProjectTokenByIdentifierRequest* operator->() const
    {
        return this;
    }

    GetProjectTokenByIdentifierRequest* operator->()
    {
        return this;
    }

    /**
     * GS2アカウントの名前を取得
     *
     * @return GS2アカウントの名前
     */
    const optional<StringHolder>& getAccountName() const
    {
        return ensureData().accountName;
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    void setAccountName(StringHolder accountName)
    {
        ensureData().accountName.emplace(std::move(accountName));
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    GetProjectTokenByIdentifierRequest& withAccountName(StringHolder accountName)
    {
        ensureData().accountName.emplace(std::move(accountName));
        return *this;
    }

    /**
     * プロジェクト名を取得
     *
     * @return プロジェクト名
     */
    const optional<StringHolder>& getProjectName() const
    {
        return ensureData().projectName;
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    void setProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    GetProjectTokenByIdentifierRequest& withProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
        return *this;
    }

    /**
     * ユーザ名を取得
     *
     * @return ユーザ名
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザ名を設定
     *
     * @param userName ユーザ名
     */
    void setUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
    }

    /**
     * ユーザ名を設定
     *
     * @param userName ユーザ名
     */
    GetProjectTokenByIdentifierRequest& withUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
        return *this;
    }

    /**
     * パスワードを取得
     *
     * @return パスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    GetProjectTokenByIdentifierRequest& withPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetProjectTokenByIdentifierRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetProjectTokenByIdentifierRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_GETPROJECTTOKENBYIDENTIFIERREQUEST_HPP_