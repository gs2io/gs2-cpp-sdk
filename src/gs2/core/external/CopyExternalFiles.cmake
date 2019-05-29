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

macro(define_external_file_rule SRC_DIR DST_DIR OUTPUT_FILES_VARIABLE OUTPUT_SOURCE_FILES_VARIABLE)
    foreach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})
        set(TEMP_SRC ${SRC_DIR}/${EXTERNAL_FILE_ENTRY})
        set(TEMP_DST ${DST_DIR}/${EXTERNAL_FILE_ENTRY})
        add_custom_command(OUTPUT ${TEMP_DST}
                DEPENDS ${TEMP_SRC}
                COMMAND ${CMAKE_COMMAND} -E copy ${TEMP_SRC} ${TEMP_DST}
                )
        set(${OUTPUT_FILES_VARIABLE}
                ${${OUTPUT_FILES_VARIABLE}}
                ${TEMP_DST}
                )
    endforeach(EXTERNAL_FILE_ENTRY ${EXTERNAL_FILE_ENTRIES})

    foreach(EXTERNAL_SOURCE_FILE_ENTRY ${EXTERNAL_SOURCE_FILE_ENTRIES})
        set(TEMP_DST ${DST_DIR}/${EXTERNAL_SOURCE_FILE_ENTRY})
        set(${OUTPUT_SOURCE_FILES_VARIABLE}
                ${${OUTPUT_SOURCE_FILES_VARIABLE}}
                ${TEMP_DST}
                )
    endforeach(EXTERNAL_SOURCE_FILE_ENTRY ${EXTERNAL_SOURCE_FILE_ENTRIES})
endmacro(define_external_file_rule SRC_DIR DST_DIR OUTPUT_FILES_VARIABLE OUTPUT_SOURCE_FILES_VARIABLE)
