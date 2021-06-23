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

#include "EzAcceptVersion.hpp"
#include <gs2/version/model/AcceptVersion.hpp>


namespace gs2 { namespace ez { namespace version {

EzAcceptVersion::Data::Data(const Data& data) :
    Gs2Object(data),
    versionName(data.versionName),
    userId(data.userId)
{
    if (data.version)
    {
        version = data.version->deepCopy();
    }
}

EzAcceptVersion::Data::Data(const gs2::version::AcceptVersion& acceptVersion) :
    versionName(acceptVersion.getVersionName()),
    userId(acceptVersion.getUserId()),
    version(*acceptVersion.getVersion())
{
}

EzAcceptVersion::EzAcceptVersion(gs2::version::AcceptVersion acceptVersion) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(acceptVersion)
{
}

EzAcceptVersion EzAcceptVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAcceptVersion);
}

gs2::version::AcceptVersion EzAcceptVersion::ToModel() const
{
    gs2::version::AcceptVersion acceptVersion;
    acceptVersion.setVersionName(getVersionName());
    acceptVersion.setUserId(getUserId());
    acceptVersion.setVersion(getVersion().ToModel());
    return acceptVersion;
}

}}}