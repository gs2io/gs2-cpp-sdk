/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_CORE_MACROS_HPP_
#define GS2_CORE_MACROS_HPP_

#define GS2_TARGET_UNKNOWN  0
#define GS2_TARGET_WINDOWS  1

#if _WIN32 == 1 || _WIN64 == 1
#define GS2_TARGET  GS2_TARGET_WINDOWS
#else
#define GS2_TARGET  GS2_TARGET_UNKNOWN
#endif

#define GS2_START_OF_NAMESPACE  namespace gs2 {
#define GS2_END_OF_NAMESPACE    }

#define GS2_NOT_USED(variable)  ((void)variable)

#define GS2_ALIGN_OF(variable)  alignof(variable)

#define GS2_OVERRIDE    override

#define GS2_COUNT_OF(array)     (sizeof(array) / sizeof(array[0]))

#endif //GS2_CORE_MACROS_HPP_

