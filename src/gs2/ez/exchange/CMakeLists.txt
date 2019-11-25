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
project(gs2-cpp-sdk-ez-exchange)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzRateModel.hpp
        model/EzRateModelMaster.hpp
        model/EzCurrentRateMaster.hpp
        model/EzResponseCache.hpp
        model/EzConfig.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzLogSetting.hpp
        model/EzAcquireAction.hpp
        model/EzConsumeAction.hpp
        result/EzListRateModelsResult.hpp
        result/EzGetRateModelResult.hpp
        result/EzExchangeResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzRateModel.cpp
        model/EzRateModelMaster.cpp
        model/EzCurrentRateMaster.cpp
        model/EzResponseCache.cpp
        model/EzConfig.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzLogSetting.cpp
        model/EzAcquireAction.cpp
        model/EzConsumeAction.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-ez)

add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )