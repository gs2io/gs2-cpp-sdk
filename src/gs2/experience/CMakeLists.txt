# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

cmake_minimum_required(VERSION 3.2)
project(gs2-cpp-sdk-experience)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Experience.hpp
        Gs2ExperienceConst.hpp
        Gs2ExperienceRestClient.hpp
        Gs2ExperienceWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/ExperienceModelMaster.hpp
        model/ExperienceModel.hpp
        model/ThresholdMaster.hpp
        model/Threshold.hpp
        model/CurrentExperienceMaster.hpp
        model/Status.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/ScriptSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeExperienceModelMastersRequest.hpp
        request/CreateExperienceModelMasterRequest.hpp
        request/GetExperienceModelMasterRequest.hpp
        request/UpdateExperienceModelMasterRequest.hpp
        request/DeleteExperienceModelMasterRequest.hpp
        request/DescribeExperienceModelsRequest.hpp
        request/GetExperienceModelRequest.hpp
        request/DescribeThresholdMastersRequest.hpp
        request/CreateThresholdMasterRequest.hpp
        request/GetThresholdMasterRequest.hpp
        request/UpdateThresholdMasterRequest.hpp
        request/DeleteThresholdMasterRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentExperienceMasterRequest.hpp
        request/UpdateCurrentExperienceMasterRequest.hpp
        request/UpdateCurrentExperienceMasterFromGitHubRequest.hpp
        request/DescribeStatusesRequest.hpp
        request/DescribeStatusesByUserIdRequest.hpp
        request/GetStatusRequest.hpp
        request/GetStatusByUserIdRequest.hpp
        request/GetStatusWithSignatureRequest.hpp
        request/AddExperienceByUserIdRequest.hpp
        request/SetExperienceByUserIdRequest.hpp
        request/AddRankCapByUserIdRequest.hpp
        request/SetRankCapByUserIdRequest.hpp
        request/DeleteStatusByUserIdRequest.hpp
        request/AddExperienceByStampSheetRequest.hpp
        request/AddRankCapByStampSheetRequest.hpp
        request/SetRankCapByStampSheetRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeExperienceModelMastersResult.hpp
        result/CreateExperienceModelMasterResult.hpp
        result/GetExperienceModelMasterResult.hpp
        result/UpdateExperienceModelMasterResult.hpp
        result/DeleteExperienceModelMasterResult.hpp
        result/DescribeExperienceModelsResult.hpp
        result/GetExperienceModelResult.hpp
        result/DescribeThresholdMastersResult.hpp
        result/CreateThresholdMasterResult.hpp
        result/GetThresholdMasterResult.hpp
        result/UpdateThresholdMasterResult.hpp
        result/DeleteThresholdMasterResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentExperienceMasterResult.hpp
        result/UpdateCurrentExperienceMasterResult.hpp
        result/UpdateCurrentExperienceMasterFromGitHubResult.hpp
        result/DescribeStatusesResult.hpp
        result/DescribeStatusesByUserIdResult.hpp
        result/GetStatusResult.hpp
        result/GetStatusByUserIdResult.hpp
        result/GetStatusWithSignatureResult.hpp
        result/AddExperienceByUserIdResult.hpp
        result/SetExperienceByUserIdResult.hpp
        result/AddRankCapByUserIdResult.hpp
        result/SetRankCapByUserIdResult.hpp
        result/DeleteStatusByUserIdResult.hpp
        result/AddExperienceByStampSheetResult.hpp
        result/AddRankCapByStampSheetResult.hpp
        result/SetRankCapByStampSheetResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ExperienceRestClient.cpp
        Gs2ExperienceWebSocketClient.cpp
        model/Namespace.cpp
        model/ExperienceModelMaster.cpp
        model/ExperienceModel.cpp
        model/ThresholdMaster.cpp
        model/Threshold.cpp
        model/CurrentExperienceMaster.cpp
        model/Status.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/ScriptSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeExperienceModelMastersResult.cpp
        result/CreateExperienceModelMasterResult.cpp
        result/GetExperienceModelMasterResult.cpp
        result/UpdateExperienceModelMasterResult.cpp
        result/DeleteExperienceModelMasterResult.cpp
        result/DescribeExperienceModelsResult.cpp
        result/GetExperienceModelResult.cpp
        result/DescribeThresholdMastersResult.cpp
        result/CreateThresholdMasterResult.cpp
        result/GetThresholdMasterResult.cpp
        result/UpdateThresholdMasterResult.cpp
        result/DeleteThresholdMasterResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentExperienceMasterResult.cpp
        result/UpdateCurrentExperienceMasterResult.cpp
        result/UpdateCurrentExperienceMasterFromGitHubResult.cpp
        result/DescribeStatusesResult.cpp
        result/DescribeStatusesByUserIdResult.cpp
        result/GetStatusResult.cpp
        result/GetStatusByUserIdResult.cpp
        result/GetStatusWithSignatureResult.cpp
        result/AddExperienceByUserIdResult.cpp
        result/SetExperienceByUserIdResult.cpp
        result/AddRankCapByUserIdResult.cpp
        result/SetRankCapByUserIdResult.cpp
        result/DeleteStatusByUserIdResult.cpp
        result/AddExperienceByStampSheetResult.cpp
        result/AddRankCapByStampSheetResult.cpp
        result/SetRankCapByStampSheetResult.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-core)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )