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

#include "EzStatus.hpp"
#include <gs2/version/model/Status.hpp>


namespace gs2 { namespace ez { namespace version {

EzStatus::Data::Data(const Data& data) :
    Gs2Object(data)
{
    versionModel = data.versionModel.deepCopy();
    currentVersion = data.currentVersion.deepCopy();
}

EzStatus::Data::Data(const gs2::version::Status& status) :
    versionModel(status.getVersionModel()),
    currentVersion(status.getCurrentVersion())
{
}

EzStatus::Data::Data(const gs2::optional<gs2::version::Status>& status) :
    versionModel(status ? status->getVersionModel() : gs2::optional<gs2::version::VersionModel>()),
    currentVersion(status ? status->getCurrentVersion() : gs2::optional<gs2::version::Version>())
{
}

EzStatus::EzStatus(gs2::version::Status status) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(status)
{
}

EzStatus::EzStatus(gs2::optional<gs2::version::Status> status) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(status)
{
}

EzStatus EzStatus::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStatus);
}

gs2::version::Status EzStatus::ToModel() const
{
    gs2::version::Status status;
    status.setVersionModel(getVersionModel().ToModel());
    status.setCurrentVersion(getCurrentVersion().ToModel());
    return status;
}

}}}