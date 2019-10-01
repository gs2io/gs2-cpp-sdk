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
project(gs2-cpp-sdk-ez-stamina)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzStaminaModelMaster.hpp
        model/EzMaxStaminaTableMaster.hpp
        model/EzRecoverIntervalTableMaster.hpp
        model/EzRecoverValueTableMaster.hpp
        model/EzCurrentStaminaMaster.hpp
        model/EzStaminaModel.hpp
        model/EzMaxStaminaTable.hpp
        model/EzRecoverIntervalTable.hpp
        model/EzRecoverValueTable.hpp
        model/EzStamina.hpp
        model/EzResponseCache.hpp
        model/EzGitHubCheckoutSetting.hpp
        result/EzListStaminaModelsResult.hpp
        result/EzGetStaminaModelResult.hpp
        result/EzGetStaminaResult.hpp
        result/EzConsumeResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-ez)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )