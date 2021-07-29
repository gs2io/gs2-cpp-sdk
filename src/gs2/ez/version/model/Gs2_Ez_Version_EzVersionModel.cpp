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

#include "EzVersionModel.hpp"
#include <gs2/version/model/VersionModel.hpp>


namespace gs2 { namespace ez { namespace version {

EzVersionModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    scope(data.scope),
    needSignature(data.needSignature)
{
    warningVersion = data.warningVersion.deepCopy();
    errorVersion = data.errorVersion.deepCopy();
    currentVersion = data.currentVersion.deepCopy();
}

EzVersionModel::Data::Data(const gs2::version::VersionModel& versionModel) :
    name(versionModel.getName() ? *versionModel.getName() : StringHolder()),
    metadata(versionModel.getMetadata() ? *versionModel.getMetadata() : StringHolder()),
    warningVersion(versionModel.getWarningVersion()),
    errorVersion(versionModel.getErrorVersion()),
    scope(versionModel.getScope() ? *versionModel.getScope() : StringHolder()),
    currentVersion(versionModel.getCurrentVersion()),
    needSignature(versionModel.getNeedSignature() ? *versionModel.getNeedSignature() : false)
{
}

EzVersionModel::Data::Data(const gs2::optional<gs2::version::VersionModel>& versionModel) :
    name(versionModel && versionModel->getName() ? *versionModel->getName() : StringHolder()),
    metadata(versionModel && versionModel->getMetadata() ? *versionModel->getMetadata() : StringHolder()),
    warningVersion(versionModel ? versionModel->getWarningVersion() : gs2::optional<gs2::version::Version>()),
    errorVersion(versionModel ? versionModel->getErrorVersion() : gs2::optional<gs2::version::Version>()),
    scope(versionModel && versionModel->getScope() ? *versionModel->getScope() : StringHolder()),
    currentVersion(versionModel ? versionModel->getCurrentVersion() : gs2::optional<gs2::version::Version>()),
    needSignature(versionModel && versionModel->getNeedSignature() ? *versionModel->getNeedSignature() : false)
{
}

EzVersionModel::EzVersionModel(gs2::version::VersionModel versionModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(versionModel)
{
}

EzVersionModel::EzVersionModel(gs2::optional<gs2::version::VersionModel> versionModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(versionModel)
{
}

EzVersionModel EzVersionModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzVersionModel);
}

gs2::version::VersionModel EzVersionModel::ToModel() const
{
    gs2::version::VersionModel versionModel;
    versionModel.setName(getName());
    versionModel.setMetadata(getMetadata());
    versionModel.setWarningVersion(getWarningVersion().ToModel());
    versionModel.setErrorVersion(getErrorVersion().ToModel());
    versionModel.setScope(getScope());
    versionModel.setCurrentVersion(getCurrentVersion().ToModel());
    versionModel.setNeedSignature(getNeedSignature());
    return versionModel;
}

}}}