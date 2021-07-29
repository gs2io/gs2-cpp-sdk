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

#include "EzTargetVersion.hpp"
#include <gs2/version/model/TargetVersion.hpp>


namespace gs2 { namespace ez { namespace version {

EzTargetVersion::Data::Data(const Data& data) :
    Gs2Object(data),
    versionName(data.versionName),
    body(data.body),
    signature(data.signature)
{
    version = data.version.deepCopy();
}

EzTargetVersion::Data::Data(const gs2::version::TargetVersion& targetVersion) :
    versionName(targetVersion.getVersionName() ? *targetVersion.getVersionName() : StringHolder()),
    version(targetVersion.getVersion()),
    body(targetVersion.getBody() ? *targetVersion.getBody() : StringHolder()),
    signature(targetVersion.getSignature() ? *targetVersion.getSignature() : StringHolder())
{
}

EzTargetVersion::Data::Data(const gs2::optional<gs2::version::TargetVersion>& targetVersion) :
    versionName(targetVersion && targetVersion->getVersionName() ? *targetVersion->getVersionName() : StringHolder()),
    version(targetVersion ? targetVersion->getVersion() : gs2::optional<gs2::version::Version>()),
    body(targetVersion && targetVersion->getBody() ? *targetVersion->getBody() : StringHolder()),
    signature(targetVersion && targetVersion->getSignature() ? *targetVersion->getSignature() : StringHolder())
{
}

EzTargetVersion::EzTargetVersion(gs2::version::TargetVersion targetVersion) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(targetVersion)
{
}

EzTargetVersion::EzTargetVersion(gs2::optional<gs2::version::TargetVersion> targetVersion) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(targetVersion)
{
}

EzTargetVersion EzTargetVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzTargetVersion);
}

gs2::version::TargetVersion EzTargetVersion::ToModel() const
{
    gs2::version::TargetVersion targetVersion;
    targetVersion.setVersionName(getVersionName());
    targetVersion.setVersion(getVersion().ToModel());
    targetVersion.setBody(getBody());
    targetVersion.setSignature(getSignature());
    return targetVersion;
}

}}}