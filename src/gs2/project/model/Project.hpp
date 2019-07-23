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
#include <gs2/core/external/optional/optional.hpp>
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            projectId(data.projectId),
            accountName(data.accountName),
            name(data.name),
            description(data.description),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            projectId(std::move(data.projectId)),
            accountName(std::move(data.accountName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "projectId") == 0) {
                if (jsonValue.IsString())
                {
                    this->projectId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "accountName") == 0) {
                if (jsonValue.IsString())
                {
                    this->accountName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Project() :
        m_pData(nullptr)
    {}

    Project(const Project& project) :
        Gs2Object(project),
        m_pData(project.m_pData != nullptr ? new Data(*project.m_pData) : nullptr)
    {}

    Project(Project&& project) :
        Gs2Object(std::move(project)),
        m_pData(project.m_pData)
    {
        project.m_pData = nullptr;
    }

    ~Project()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Project& operator=(const Project& project)
    {
        Gs2Object::operator=(project);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*project.m_pData);

        return *this;
    }

    Project& operator=(Project&& project)
    {
        Gs2Object::operator=(std::move(project));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = project.m_pData;
        project.m_pData = nullptr;

        return *this;
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
    void setProjectId(const Char* projectId)
    {
        ensureData().projectId.emplace(projectId);
    }

    /**
     * プロジェクトを設定
     *
     * @param projectId プロジェクト
     */
    Project& withProjectId(const Char* projectId)
    {
        setProjectId(projectId);
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
    void setAccountName(const Char* accountName)
    {
        ensureData().accountName.emplace(accountName);
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    Project& withAccountName(const Char* accountName)
    {
        setAccountName(accountName);
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
    Project& withName(const Char* name)
    {
        setName(name);
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
    Project& withDescription(const Char* description)
    {
        setDescription(description);
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

bool operator!=(const Project& lhs, const Project& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const Project& lhs, const Project& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_PROJECT_HPP_