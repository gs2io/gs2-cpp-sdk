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

#ifndef GS2_PROJECT_MODEL_PROJECT_HPP_
#define GS2_PROJECT_MODEL_PROJECT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace project {

/**
 * プロジェクト
 *
 * @author Game Server Services, Inc.
 *
 */
class Project : public Gs2Object
{
    friend bool operator!=(const Project& lhs, const Project& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** プロジェクト */
        optional<StringHolder> projectId;
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;
        /** プロジェクト名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            projectId(data.projectId),
            accountName(data.accountName),
            name(data.name),
            description(data.description),
            plan(data.plan),
            billingMethodName(data.billingMethodName),
            enableEventBridge(data.enableEventBridge),
            eventBridgeAwsAccountId(data.eventBridgeAwsAccountId),
            eventBridgeAwsRegion(data.eventBridgeAwsRegion),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "projectId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->projectId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "accountName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->accountName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "plan") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->plan.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "billingMethodName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->billingMethodName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "enableEventBridge") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->enableEventBridge.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "eventBridgeAwsAccountId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->eventBridgeAwsAccountId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "eventBridgeAwsRegion") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->eventBridgeAwsRegion.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Project() = default;
    Project(const Project& project) = default;
    Project(Project&& project) = default;
    ~Project() = default;

    Project& operator=(const Project& project) = default;
    Project& operator=(Project&& project) = default;

    Project deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Project);
    }

    const Project* operator->() const
    {
        return this;
    }

    Project* operator->()
    {
        return this;
    }
    /**
     * プロジェクトを取得
     *
     * @return プロジェクト
     */
    const optional<StringHolder>& getProjectId() const
    {
        return ensureData().projectId;
    }

    /**
     * プロジェクトを設定
     *
     * @param projectId プロジェクト
     */
    void setProjectId(StringHolder projectId)
    {
        ensureData().projectId.emplace(std::move(projectId));
    }

    /**
     * プロジェクトを設定
     *
     * @param projectId プロジェクト
     */
    Project& withProjectId(StringHolder projectId)
    {
        setProjectId(std::move(projectId));
        return *this;
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
    Project& withAccountName(StringHolder accountName)
    {
        setAccountName(std::move(accountName));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * プロジェクト名を設定
     *
     * @param name プロジェクト名
     */
    Project& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Project& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    Project& withPlan(StringHolder plan)
    {
        setPlan(std::move(plan));
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
    Project& withBillingMethodName(StringHolder billingMethodName)
    {
        setBillingMethodName(std::move(billingMethodName));
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
    Project& withEnableEventBridge(StringHolder enableEventBridge)
    {
        setEnableEventBridge(std::move(enableEventBridge));
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
    Project& withEventBridgeAwsAccountId(StringHolder eventBridgeAwsAccountId)
    {
        setEventBridgeAwsAccountId(std::move(eventBridgeAwsAccountId));
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
    Project& withEventBridgeAwsRegion(StringHolder eventBridgeAwsRegion)
    {
        setEventBridgeAwsRegion(std::move(eventBridgeAwsRegion));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Project& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Project& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Project& lhs, const Project& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->projectId != lhr.m_pData->projectId)
        {
            return true;
        }
        if (lhs.m_pData->accountName != lhr.m_pData->accountName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->plan != lhr.m_pData->plan)
        {
            return true;
        }
        if (lhs.m_pData->billingMethodName != lhr.m_pData->billingMethodName)
        {
            return true;
        }
        if (lhs.m_pData->enableEventBridge != lhr.m_pData->enableEventBridge)
        {
            return true;
        }
        if (lhs.m_pData->eventBridgeAwsAccountId != lhr.m_pData->eventBridgeAwsAccountId)
        {
            return true;
        }
        if (lhs.m_pData->eventBridgeAwsRegion != lhr.m_pData->eventBridgeAwsRegion)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Project& lhs, const Project& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_PROJECT_HPP_