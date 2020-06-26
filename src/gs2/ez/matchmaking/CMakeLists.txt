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
project(gs2-cpp-sdk-ez-matchmaking)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzGathering.hpp
        model/EzRatingModelMaster.hpp
        model/EzRatingModel.hpp
        model/EzCurrentRatingModelMaster.hpp
        model/EzResponseCache.hpp
        model/EzNotificationSetting.hpp
        model/EzLogSetting.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzAttributeRange.hpp
        model/EzCapacityOfRole.hpp
        model/EzAttribute.hpp
        model/EzPlayer.hpp
        model/EzRating.hpp
        model/EzGameResult.hpp
        model/EzBallot.hpp
        model/EzSignedBallot.hpp
        model/EzWrittenBallot.hpp
        model/EzVote.hpp
        result/EzCreateGatheringResult.hpp
        result/EzUpdateGatheringResult.hpp
        result/EzDoMatchmakingResult.hpp
        result/EzGetGatheringResult.hpp
        result/EzCancelMatchmakingResult.hpp
        result/EzListRatingModelsResult.hpp
        result/EzGetRatingModelResult.hpp
        result/EzListRatingsResult.hpp
        result/EzGetRatingResult.hpp
        result/EzCreateVoteResult.hpp
        result/EzVoteResult.hpp
        result/EzVoteMultipleResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzGathering.cpp
        model/EzRatingModelMaster.cpp
        model/EzRatingModel.cpp
        model/EzCurrentRatingModelMaster.cpp
        model/EzResponseCache.cpp
        model/EzNotificationSetting.cpp
        model/EzLogSetting.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzAttributeRange.cpp
        model/EzCapacityOfRole.cpp
        model/EzAttribute.cpp
        model/EzPlayer.cpp
        model/EzRating.cpp
        model/EzGameResult.cpp
        model/EzBallot.cpp
        model/EzSignedBallot.cpp
        model/EzWrittenBallot.cpp
        model/EzVote.cpp
        )

gs2_add_library(${PROJECT_NAME} STATIC
        "${${PROJECT_NAME}_SOURCE_FILES}"
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})

gs2_target_link_libraries(${PROJECT_NAME}
        PUBLIC gs2-cpp-sdk-ez
        )

gs2_add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )