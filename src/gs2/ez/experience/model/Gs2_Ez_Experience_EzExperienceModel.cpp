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

#include "EzExperienceModel.hpp"
#include <gs2/experience/model/ExperienceModel.hpp>


namespace gs2 { namespace ez { namespace experience {

EzExperienceModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    defaultExperience(data.defaultExperience),
    defaultRankCap(data.defaultRankCap),
    maxRankCap(data.maxRankCap)
{
    rankThreshold = data.rankThreshold.deepCopy();
}

EzExperienceModel::Data::Data(const gs2::experience::ExperienceModel& experienceModel) :
    name(experienceModel.getName() ? *experienceModel.getName() : StringHolder()),
    metadata(experienceModel.getMetadata() ? *experienceModel.getMetadata() : StringHolder()),
    defaultExperience(experienceModel.getDefaultExperience() ? *experienceModel.getDefaultExperience() : 0),
    defaultRankCap(experienceModel.getDefaultRankCap() ? *experienceModel.getDefaultRankCap() : 0),
    maxRankCap(experienceModel.getMaxRankCap() ? *experienceModel.getMaxRankCap() : 0),
    rankThreshold(experienceModel.getRankThreshold())
{
}

EzExperienceModel::Data::Data(const gs2::optional<gs2::experience::ExperienceModel>& experienceModel) :
    name(experienceModel && experienceModel->getName() ? *experienceModel->getName() : StringHolder()),
    metadata(experienceModel && experienceModel->getMetadata() ? *experienceModel->getMetadata() : StringHolder()),
    defaultExperience(experienceModel && experienceModel->getDefaultExperience() ? *experienceModel->getDefaultExperience() : 0),
    defaultRankCap(experienceModel && experienceModel->getDefaultRankCap() ? *experienceModel->getDefaultRankCap() : 0),
    maxRankCap(experienceModel && experienceModel->getMaxRankCap() ? *experienceModel->getMaxRankCap() : 0),
    rankThreshold(experienceModel ? experienceModel->getRankThreshold() : gs2::optional<gs2::experience::Threshold>())
{
}

EzExperienceModel::EzExperienceModel(gs2::experience::ExperienceModel experienceModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(experienceModel)
{
}

EzExperienceModel::EzExperienceModel(gs2::optional<gs2::experience::ExperienceModel> experienceModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(experienceModel)
{
}

EzExperienceModel EzExperienceModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzExperienceModel);
}

gs2::experience::ExperienceModel EzExperienceModel::ToModel() const
{
    gs2::experience::ExperienceModel experienceModel;
    experienceModel.setName(getName());
    experienceModel.setMetadata(getMetadata());
    experienceModel.setDefaultExperience(getDefaultExperience());
    experienceModel.setDefaultRankCap(getDefaultRankCap());
    experienceModel.setMaxRankCap(getMaxRankCap());
    experienceModel.setRankThreshold(getRankThreshold().ToModel());
    return experienceModel;
}

}}}