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
        model/EzGathering.hpp
        model/EzRatingModel.hpp
        model/EzAttributeRange.hpp
        model/EzCapacityOfRole.hpp
        model/EzAttribute.hpp
        model/EzPlayer.hpp
        model/EzRating.hpp
        model/EzGameResult.hpp
        model/EzBallot.hpp
        model/EzSignedBallot.hpp
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
        Gs2_Ez_Matchmaking_Client.cpp
        model/Gs2_Ez_Matchmaking_EzGathering.cpp
        model/Gs2_Ez_Matchmaking_EzRatingModel.cpp
        model/Gs2_Ez_Matchmaking_EzAttributeRange.cpp
        model/Gs2_Ez_Matchmaking_EzCapacityOfRole.cpp
        model/Gs2_Ez_Matchmaking_EzAttribute.cpp
        model/Gs2_Ez_Matchmaking_EzPlayer.cpp
        model/Gs2_Ez_Matchmaking_EzRating.cpp
        model/Gs2_Ez_Matchmaking_EzGameResult.cpp
        model/Gs2_Ez_Matchmaking_EzBallot.cpp
        model/Gs2_Ez_Matchmaking_EzSignedBallot.cpp
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