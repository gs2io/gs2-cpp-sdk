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

set(optional_HEADER_FILE_ENTRIES
        optional/optional.hpp
        )

set(optional_SOURCE_FILE_ENTRIES
        )

set(optional_ETC_FILE_ENTRIES
        optional/copyright.txt
        optional/LICENSE
        optional/LICENSE_1_0.txt
        optional/README.md
        )

set(rapidjson_HEADER_FILE_ENTRIES
        rapidjson/include/rapidjson/allocators.h
        rapidjson/include/rapidjson/document.h
        rapidjson/include/rapidjson/encodedstream.h
        rapidjson/include/rapidjson/encodings.h
        rapidjson/include/rapidjson/error/error.h
        rapidjson/include/rapidjson/internal/biginteger.h
        rapidjson/include/rapidjson/internal/diyfp.h
        rapidjson/include/rapidjson/internal/dtoa.h
        rapidjson/include/rapidjson/internal/ieee754.h
        rapidjson/include/rapidjson/internal/itoa.h
        rapidjson/include/rapidjson/internal/meta.h
        rapidjson/include/rapidjson/internal/pow10.h
        rapidjson/include/rapidjson/internal/stack.h
        rapidjson/include/rapidjson/internal/strfunc.h
        rapidjson/include/rapidjson/internal/strtod.h
        rapidjson/include/rapidjson/internal/swap.h
        rapidjson/include/rapidjson/memorystream.h
        rapidjson/include/rapidjson/msinttypes/inttypes.h
        rapidjson/include/rapidjson/msinttypes/stdint.h
        rapidjson/include/rapidjson/rapidjson.h
        rapidjson/include/rapidjson/reader.h
        rapidjson/include/rapidjson/stream.h
        rapidjson/include/rapidjson/stringbuffer.h
        rapidjson/include/rapidjson/writer.h
        )

set(rapidjson_SOURCE_FILE_ENTRIES
        )

set(rapidjson_ETC_FILE_ENTRIES
        rapidjson/license.txt
        rapidjson/readme.md
        )

set(EXTERNAL_SOURCE_FILE_ENTRIES
        ${optional_SOURCE_FILE_ENTRIES}
        ${rapidjson_SOURCE_FILE_ENTRIES}
        )

set(EXTERNAL_FILE_ENTRIES
        license.txt
        ${optional_HEADER_FILE_ENTRIES}
        ${optional_SOURCE_FILE_ENTRIES}
        ${optional_ETC_FILE_ENTRIES}
        ${rapidjson_HEADER_FILE_ENTRIES}
        ${rapidjson_SOURCE_FILE_ENTRIES}
        ${rapidjson_ETC_FILE_ENTRIES}
        )

# 相対パスだと Linux でファイルを発見できない
include(${CMAKE_CURRENT_LIST_DIR}/../../../../cmake/Gs2CopyExternalFiles.cmake OPTIONAL)

foreach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})
    set(EXTERNAL_FILE ${CMAKE_CURRENT_LIST_DIR}/${EXTERNAL_FILE_ENTRY})
    set(EXTERNAL_FILES
            ${EXTERNAL_FILES}
            ${EXTERNAL_FILE}
            )
endforeach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})

foreach(EXTERNAL_SOURCE_FILE_ENTRY ${EXTERNAL_SOURCE_FILE_ENTRIES})
    set(EXTERNAL_SOURCE_FILE ${CMAKE_CURRENT_LIST_DIR}/${EXTERNAL_SOURCE_FILE_ENTRY})
    set(EXTERNAL_SOURCE_FILES
            ${EXTERNAL_SOURCE_FILES}
            ${EXTERNAL_SOURCE_FILE}
            )
endforeach(EXTERNAL_SOURCE_FILE_ENTRY ${EXTERNAL_SOURCE_FILE_ENTRIES})

add_custom_target(gs2-cpp-sdk-core-external
        DEPENDS ${EXTERNAL_FILES}
        )

add_dependencies(gs2-cpp-sdk-core
        gs2-cpp-sdk-core-external
        )

if(EXTERNAL_SOURCE_FILES)
    target_sources(gs2-cpp-sdk-core
            ${EXTERNAL_SOURCE_FILES}
            )
endif(EXTERNAL_SOURCE_FILES)

set(gs2-cpp-sdk-core_FILES
        ${gs2-cpp-sdk-core_FILES}
        ${EXTERNAL_FILES}
        PARENT_SCOPE
        )
