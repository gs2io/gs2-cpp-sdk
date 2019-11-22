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

#ifndef GS2_EZ_VERSION_MODEL_EZTARGETVERSION_HPP_
#define GS2_EZ_VERSION_MODEL_EZTARGETVERSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzVersion.hpp"
#include <memory>


namespace gs2 {

namespace version {

class TargetVersion;

}

namespace ez { namespace version {

class EzTargetVersion : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** バージョンの名前 */
        gs2::optional<StringHolder> versionName;
        /** バージョン */
        gs2::optional<EzVersion> version;
        /** ボディ */
        gs2::optional<StringHolder> body;
        /** 署名 */
        gs2::optional<StringHolder> signature;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::version::TargetVersion& targetVersion);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzTargetVersion() = default;
    EzTargetVersion(const EzTargetVersion& ezTargetVersion) = default;
    EzTargetVersion(EzTargetVersion&& ezTargetVersion) = default;
    ~EzTargetVersion() = default;

    EzTargetVersion(gs2::version::TargetVersion targetVersion);

    EzTargetVersion& operator=(const EzTargetVersion& ezTargetVersion) = default;
    EzTargetVersion& operator=(EzTargetVersion&& ezTargetVersion) = default;

    EzTargetVersion deepCopy() const;

    gs2::version::TargetVersion ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getVersionName() const
    {
        return *ensureData().versionName;
    }

    const EzVersion& getVersion() const
    {
        return *ensureData().version;
    }

    const StringHolder& getBody() const
    {
        return *ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return *ensureData().signature;
    }

    // ========================================
    //   Setters
    // ========================================

    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName = std::move(versionName);
    }

    void setVersion(EzVersion version)
    {
        ensureData().version = std::move(version);
    }

    void setBody(StringHolder body)
    {
        ensureData().body = std::move(body);
    }

    void setSignature(StringHolder signature)
    {
        ensureData().signature = std::move(signature);
    }

    EzTargetVersion& withVersionName(StringHolder versionName)
    {
        setVersionName(std::move(versionName));
        return *this;
    }

    EzTargetVersion& withVersion(EzVersion version)
    {
        setVersion(std::move(version));
        return *this;
    }

    EzTargetVersion& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    EzTargetVersion& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }
};

}}}

#endif //GS2_EZ_VERSION_EZTARGETVERSION_HPP_