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

# Gs2CoreExternal.cmake からインクルードして利用

foreach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})
    set(TEMP_SRC ${CMAKE_CURRENT_LIST_DIR}/../src/external/${EXTERNAL_FILE_ENTRY})
    set(TEMP_DST ${CMAKE_CURRENT_LIST_DIR}/../src/gs2/core/external/${EXTERNAL_FILE_ENTRY})
    add_custom_command(OUTPUT ${TEMP_DST}
            DEPENDS ${TEMP_SRC}
            COMMAND ${CMAKE_COMMAND} -E copy ${TEMP_SRC} ${TEMP_DST}
            )
endforeach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})
