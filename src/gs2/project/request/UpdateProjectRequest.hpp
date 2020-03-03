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

#ifndef GS2_PROJECT_CONTROL_UPDATEPROJECTREQUEST_HPP_
#define GS2_PROJECT_CONTROL_UPDATEPROJECTREQUEST_HPP_

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
 * プロジェクトを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateProjectRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** GS2アカウントトークン */
        optional<StringHolder> accountToken;
        /** プロジェクト名 */
        optional<StringHolder> projectName;
        /** プロジェクトの説明 */
        optional<StringHolder> description;
        /** 契約プラン */
        optional<StringHolder> plan;
        /** 支払い方法名 */
        optional<StringHolder> billingMethodName;
        /** AWS EventBridge の設定 */
        optional<StringHolder> enableEventBridge;
        /** 通知に使用するAWSアカウントのID */
        optional<StringHolder> eventBridgeAwsAccountId;
        /** 通知に使用するAWSリージョン */
        optional<StringHolder> eventBridgeAwsRegion;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountToken(data.accountToken),
            projectName(data.projectName),
            description(data.description),
            plan(data.plan),
            billingMethodName(data.billingMethodName),
            enableEventBridge(data.enableEventBridge),
            eventBridgeAwsAccountId(data.eventBridgeAwsAccountId),
            eventBridgeAwsRegion(data.eventBridgeAwsRegion)
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
    UpdateProjectRequest() = default;
    UpdateProjectRequest(const UpdateProjectRequest& updateProjectRequest) = default;
    UpdateProjectRequest(UpdateProjectRequest&& updateProjectRequest) = default;
    ~UpdateProjectRequest() GS2_OVERRIDE = default;

    UpdateProjectRequest& operator=(const UpdateProjectRequest& updateProjectRequest) = default;
    UpdateProjectRequest& operator=(UpdateProjectRequest&& updateProjectRequest) = default;

    UpdateProjectRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateProjectRequest);
    }

    const UpdateProjectRequest* operator->() const
    {
        return this;
    }

    UpdateProjectRequest* operator->()
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
    void setAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    UpdateProjectRequest& withAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
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
    UpdateProjectRequest& withProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * プロジェクトの説明を設定
     *
     * @param description プロジェクトの説明
     */
    UpdateProjectRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 契約プランを取得
     *
     * @return 契約プラン
     */
    const optional<StringHolder>& getPlan() const
    {
        return ensureData().plan;
    }

    /**
     * 契約プランを設定
     *
     * @param plan 契約プラン
     */
    void setPlan(StringHolder plan)
    {
        ensureData().plan.emplace(std::move(plan));
    }

    /**
     * 契約プランを設定
     *
     * @param plan 契約プラン
     */
    UpdateProjectRequest& withPlan(StringHolder plan)
    {
        ensureData().plan.emplace(std::move(plan));
        return *this;
    }

    /**
     * 支払い方法名を取得
     *
     * @return 支払い方法名
     */
    const optional<StringHolder>& getBillingMethodName() const
    {
        return ensureData().billingMethodName;
    }

    /**
     * 支払い方法名を設定
     *
     * @param billingMethodName 支払い方法名
     */
    void setBillingMethodName(StringHolder billingMethodName)
    {
        ensureData().billingMethodName.emplace(std::move(billingMethodName));
    }

    /**
     * 支払い方法名を設定
     *
     * @param billingMethodName 支払い方法名
     */
    UpdateProjectRequest& withBillingMethodName(StringHolder billingMethodName)
    {
        ensureData().billingMethodName.emplace(std::move(billingMethodName));
        return *this;
    }

    /**
     * AWS EventBridge の設定を取得
     *
     * @return AWS EventBridge の設定
     */
    const optional<StringHolder>& getEnableEventBridge() const
    {
        return ensureData().enableEventBridge;
    }

    /**
     * AWS EventBridge の設定を設定
     *
     * @param enableEventBridge AWS EventBridge の設定
     */
    void setEnableEventBridge(StringHolder enableEventBridge)
    {
        ensureData().enableEventBridge.emplace(std::move(enableEventBridge));
    }

    /**
     * AWS EventBridge の設定を設定
     *
     * @param enableEventBridge AWS EventBridge の設定
     */
    UpdateProjectRequest& withEnableEventBridge(StringHolder enableEventBridge)
    {
        ensureData().enableEventBridge.emplace(std::move(enableEventBridge));
        return *this;
    }

    /**
     * 通知に使用するAWSアカウントのIDを取得
     *
     * @return 通知に使用するAWSアカウントのID
     */
    const optional<StringHolder>& getEventBridgeAwsAccountId() const
    {
        return ensureData().eventBridgeAwsAccountId;
    }

    /**
     * 通知に使用するAWSアカウントのIDを設定
     *
     * @param eventBridgeAwsAccountId 通知に使用するAWSアカウントのID
     */
    void setEventBridgeAwsAccountId(StringHolder eventBridgeAwsAccountId)
    {
        ensureData().eventBridgeAwsAccountId.emplace(std::move(eventBridgeAwsAccountId));
    }

    /**
     * 通知に使用するAWSアカウントのIDを設定
     *
     * @param eventBridgeAwsAccountId 通知に使用するAWSアカウントのID
     */
    UpdateProjectRequest& withEventBridgeAwsAccountId(StringHolder eventBridgeAwsAccountId)
    {
        ensureData().eventBridgeAwsAccountId.emplace(std::move(eventBridgeAwsAccountId));
        return *this;
    }

    /**
     * 通知に使用するAWSリージョンを取得
     *
     * @return 通知に使用するAWSリージョン
     */
    const optional<StringHolder>& getEventBridgeAwsRegion() const
    {
        return ensureData().eventBridgeAwsRegion;
    }

    /**
     * 通知に使用するAWSリージョンを設定
     *
     * @param eventBridgeAwsRegion 通知に使用するAWSリージョン
     */
    void setEventBridgeAwsRegion(StringHolder eventBridgeAwsRegion)
    {
        ensureData().eventBridgeAwsRegion.emplace(std::move(eventBridgeAwsRegion));
    }

    /**
     * 通知に使用するAWSリージョンを設定
     *
     * @param eventBridgeAwsRegion 通知に使用するAWSリージョン
     */
    UpdateProjectRequest& withEventBridgeAwsRegion(StringHolder eventBridgeAwsRegion)
    {
        ensureData().eventBridgeAwsRegion.emplace(std::move(eventBridgeAwsRegion));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateProjectRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateProjectRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_UPDATEPROJECTREQUEST_HPP_