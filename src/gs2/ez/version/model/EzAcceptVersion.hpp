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

#ifndef GS2_EZ_VERSION_MODEL_EZACCEPTVERSION_HPP_
#define GS2_EZ_VERSION_MODEL_EZACCEPTVERSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzVersion.hpp"
#include <memory>


namespace gs2 {

namespace version {

class AcceptVersion;

}

namespace ez { namespace version {

class EzAcceptVersion : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 承認したバージョン名 */
        gs2::optional<StringHolder> versionName;
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 承認したバージョン */
        gs2::optional<EzVersion> version;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::version::AcceptVersion& acceptVersion);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAcceptVersion() = default;
    EzAcceptVersion(const EzAcceptVersion& ezAcceptVersion) = default;
    EzAcceptVersion(EzAcceptVersion&& ezAcceptVersion) = default;
    ~EzAcceptVersion() = default;

    EzAcceptVersion(gs2::version::AcceptVersion acceptVersion);

    EzAcceptVersion& operator=(const EzAcceptVersion& ezAcceptVersion) = default;
    EzAcceptVersion& operator=(EzAcceptVersion&& ezAcceptVersion) = default;

    EzAcceptVersion deepCopy() const;

    gs2::version::AcceptVersion ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getVersionName() const
    {
        return *ensureData().versionName;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const EzVersion& getVersion() const
    {
        return *ensureData().version;
    }

    // ========================================
    //   Setters
    // ========================================

    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName = std::move(versionName);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setVersion(EzVersion version)
    {
        ensureData().version = std::move(version);
    }

    EzAcceptVersion& withVersionName(StringHolder versionName)
    {
        setVersionName(std::move(versionName));
        return *this;
    }

    EzAcceptVersion& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzAcceptVersion& withVersion(EzVersion version)
    {
        setVersion(std::move(version));
        return *this;
    }
};

}}}

#endif //GS2_EZ_VERSION_EZACCEPTVERSION_HPP_