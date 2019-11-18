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

#ifndef GS2_VERSION_MODEL_SIGNTARGETVERSION_HPP_
#define GS2_VERSION_MODEL_SIGNTARGETVERSION_HPP_

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
 * 署名検証に使用するバージョン
 *
 * @author Game Server Services, Inc.
 *
 */
class SignTargetVersion : public Gs2Object
{
    friend bool operator!=(const SignTargetVersion& lhs, const SignTargetVersion& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** None */
        optional<StringHolder> region;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** バージョンの種類名 */
        optional<StringHolder> versionName;
        /** バージョン */
        optional<Version> version;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            region(data.region),
            ownerId(data.ownerId),
            namespaceName(data.namespaceName),
            versionName(data.versionName)
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
            if (std::strcmp(name_, "region") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->region.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "namespaceName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "versionName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->versionName.emplace(jsonValue.GetString());
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
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SignTargetVersion() = default;
    SignTargetVersion(const SignTargetVersion& signTargetVersion) = default;
    SignTargetVersion(SignTargetVersion&& signTargetVersion) = default;
    ~SignTargetVersion() = default;

    SignTargetVersion& operator=(const SignTargetVersion& signTargetVersion) = default;
    SignTargetVersion& operator=(SignTargetVersion&& signTargetVersion) = default;

    SignTargetVersion deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SignTargetVersion);
    }

    const SignTargetVersion* operator->() const
    {
        return this;
    }

    SignTargetVersion* operator->()
    {
        return this;
    }
    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getRegion() const
    {
        return ensureData().region;
    }

    /**
     * Noneを設定
     *
     * @param region None
     */
    void setRegion(StringHolder region)
    {
        ensureData().region.emplace(std::move(region));
    }

    /**
     * Noneを設定
     *
     * @param region None
     */
    SignTargetVersion& withRegion(StringHolder region)
    {
        setRegion(std::move(region));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    SignTargetVersion& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    SignTargetVersion& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(std::move(namespaceName));
        return *this;
    }

    /**
     * バージョンの種類名を取得
     *
     * @return バージョンの種類名
     */
    const optional<StringHolder>& getVersionName() const
    {
        return ensureData().versionName;
    }

    /**
     * バージョンの種類名を設定
     *
     * @param versionName バージョンの種類名
     */
    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
    }

    /**
     * バージョンの種類名を設定
     *
     * @param versionName バージョンの種類名
     */
    SignTargetVersion& withVersionName(StringHolder versionName)
    {
        setVersionName(std::move(versionName));
        return *this;
    }

    /**
     * バージョンを取得
     *
     * @return バージョン
     */
    const optional<Version>& getVersion() const
    {
        return ensureData().version;
    }

    /**
     * バージョンを設定
     *
     * @param version バージョン
     */
    void setVersion(Version version)
    {
        ensureData().version.emplace(std::move(version));
    }

    /**
     * バージョンを設定
     *
     * @param version バージョン
     */
    SignTargetVersion& withVersion(Version version)
    {
        setVersion(std::move(version));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SignTargetVersion& lhs, const SignTargetVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->region != lhr.m_pData->region)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->versionName != lhr.m_pData->versionName)
        {
            return true;
        }
        if (lhs.m_pData->version != lhr.m_pData->version)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SignTargetVersion& lhs, const SignTargetVersion& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_SIGNTARGETVERSION_HPP_