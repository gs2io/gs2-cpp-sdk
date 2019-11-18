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

#ifndef GS2_VERSION_MODEL_ACCEPTVERSION_HPP_
#define GS2_VERSION_MODEL_ACCEPTVERSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Version.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace version {

/**
 * 承認したバージョン
 *
 * @author Game Server Services, Inc.
 *
 */
class AcceptVersion : public Gs2Object
{
    friend bool operator!=(const AcceptVersion& lhs, const AcceptVersion& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 承認したバージョン */
        optional<StringHolder> acceptVersionId;
        /** 承認したバージョン名 */
        optional<StringHolder> versionName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 承認したバージョン */
        optional<Version> version;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            acceptVersionId(data.acceptVersionId),
            versionName(data.versionName),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.version)
            {
                version = data.version->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "acceptVersionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->acceptVersionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "versionName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->versionName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "version") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->version.emplace();
                    detail::json::JsonParser::parse(&this->version->getModel(), jsonObject);
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
    AcceptVersion() = default;
    AcceptVersion(const AcceptVersion& acceptVersion) = default;
    AcceptVersion(AcceptVersion&& acceptVersion) = default;
    ~AcceptVersion() = default;

    AcceptVersion& operator=(const AcceptVersion& acceptVersion) = default;
    AcceptVersion& operator=(AcceptVersion&& acceptVersion) = default;

    AcceptVersion deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcceptVersion);
    }

    const AcceptVersion* operator->() const
    {
        return this;
    }

    AcceptVersion* operator->()
    {
        return this;
    }
    /**
     * 承認したバージョンを取得
     *
     * @return 承認したバージョン
     */
    const optional<StringHolder>& getAcceptVersionId() const
    {
        return ensureData().acceptVersionId;
    }

    /**
     * 承認したバージョンを設定
     *
     * @param acceptVersionId 承認したバージョン
     */
    void setAcceptVersionId(StringHolder acceptVersionId)
    {
        ensureData().acceptVersionId.emplace(std::move(acceptVersionId));
    }

    /**
     * 承認したバージョンを設定
     *
     * @param acceptVersionId 承認したバージョン
     */
    AcceptVersion& withAcceptVersionId(StringHolder acceptVersionId)
    {
        setAcceptVersionId(std::move(acceptVersionId));
        return *this;
    }

    /**
     * 承認したバージョン名を取得
     *
     * @return 承認したバージョン名
     */
    const optional<StringHolder>& getVersionName() const
    {
        return ensureData().versionName;
    }

    /**
     * 承認したバージョン名を設定
     *
     * @param versionName 承認したバージョン名
     */
    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
    }

    /**
     * 承認したバージョン名を設定
     *
     * @param versionName 承認したバージョン名
     */
    AcceptVersion& withVersionName(StringHolder versionName)
    {
        setVersionName(std::move(versionName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    AcceptVersion& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 承認したバージョンを取得
     *
     * @return 承認したバージョン
     */
    const optional<Version>& getVersion() const
    {
        return ensureData().version;
    }

    /**
     * 承認したバージョンを設定
     *
     * @param version 承認したバージョン
     */
    void setVersion(Version version)
    {
        ensureData().version.emplace(std::move(version));
    }

    /**
     * 承認したバージョンを設定
     *
     * @param version 承認したバージョン
     */
    AcceptVersion& withVersion(Version version)
    {
        setVersion(std::move(version));
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
    AcceptVersion& withCreatedAt(Int64 createdAt)
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
    AcceptVersion& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const AcceptVersion& lhs, const AcceptVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->acceptVersionId != lhr.m_pData->acceptVersionId)
        {
            return true;
        }
        if (lhs.m_pData->versionName != lhr.m_pData->versionName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->version != lhr.m_pData->version)
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

inline bool operator==(const AcceptVersion& lhs, const AcceptVersion& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_ACCEPTVERSION_HPP_