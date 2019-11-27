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
project(gs2-cpp-sdk-ez-showcase)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzSalesItemMaster.hpp
        model/EzSalesItemGroupMaster.hpp
        model/EzShowcaseMaster.hpp
        model/EzCurrentShowcaseMaster.hpp
        model/EzResponseCache.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzLogSetting.hpp
        model/EzSalesItem.hpp
        model/EzSalesItemGroup.hpp
        model/EzShowcase.hpp
        model/EzDisplayItem.hpp
        model/EzConfig.hpp
        model/EzConsumeAction.hpp
        model/EzAcquireAction.hpp
        model/EzDisplayItemMaster.hpp
        result/EzGetShowcaseResult.hpp
        result/EzBuyResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzSalesItemMaster.cpp
        model/EzSalesItemGroupMaster.cpp
        model/EzShowcaseMaster.cpp
        model/EzCurrentShowcaseMaster.cpp
        model/EzResponseCache.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzLogSetting.cpp
        model/EzSalesItem.cpp
        model/EzSalesItemGroup.cpp
        model/EzShowcase.cpp
        model/EzDisplayItem.cpp
        model/EzConfig.cpp
        model/EzConsumeAction.cpp
        model/EzAcquireAction.cpp
        model/EzDisplayItemMaster.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-ez)

set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${GS2_SDK_ARCHIVE_OUTPUT_DIRECTORY}"
        LIBRARY_OUTPUT_DIRECTORY "${GS2_SDK_LIBRARY_OUTPUT_DIRECTORY}"
        )

add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )