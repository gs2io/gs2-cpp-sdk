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

#include "EzVersion.hpp"
#include <gs2/version/model/Version.hpp>


namespace gs2 { namespace ez { namespace version {

EzVersion::Data::Data(const Data& data) :
    Gs2Object(data),
    major_(data.major_),
    minor_(data.minor_),
    micro(data.micro)
{
}

EzVersion::Data::Data(const gs2::version::Version& version) :
    major_(version.getMajor() ? *version.getMajor() : 0),
    minor_(version.getMinor() ? *version.getMinor() : 0),
    micro(version.getMicro() ? *version.getMicro() : 0)
{
}

EzVersion::EzVersion(gs2::version::Version version) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(version)
{
}

EzVersion EzVersion::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzVersion);
}

gs2::version::Version EzVersion::ToModel() const
{
    gs2::version::Version version;
    version.setMajor(getMajor());
    version.setMinor(getMinor());
    version.setMicro(getMicro());
    return version;
}

}}}