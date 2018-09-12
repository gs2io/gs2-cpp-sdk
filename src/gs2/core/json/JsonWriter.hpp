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

#ifndef GS2_CORE_JSON_JSONWRITER_HPP_
#define GS2_CORE_JSON_JSONWRITER_HPP_

#include "../Gs2Object.hpp"
#include "../external/rapidjson/include/rapidjson/stringbuffer.h"
#include "../external/rapidjson/include/rapidjson/writer.h"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

class Allocator;

typedef GS2_RAPIDJSON_NAMESPACE::GenericStringBuffer<GS2_RAPIDJSON_NAMESPACE::UTF8<>, Allocator> RapidJsonStringBuffer;
typedef GS2_RAPIDJSON_NAMESPACE::Writer<RapidJsonStringBuffer, GS2_RAPIDJSON_NAMESPACE::UTF8<>, GS2_RAPIDJSON_NAMESPACE::UTF8<>, Allocator> RapidJsonWriter;

class JsonWriter : public Gs2Object
{
private:

    static JsonWriter instance;

    RapidJsonStringBuffer* stringBuffer = nullptr;
    RapidJsonWriter* writer = nullptr;

    JsonWriter();

public:

    JsonWriter(JsonWriter&) = delete;
    JsonWriter(JsonWriter&&) = delete;

    ~JsonWriter();

    static JsonWriter& getInstance();

    void reset();

    void writeObjectStart();
    void writeArrayStart();

    void writePropertyName(const Char* name);

    void write(const Char* value);
    void write(Bool value);
    void write(Int32 value);
    void write(Int64 value);
    void write(Float value);
    void write(Double value);

    void writeArrayEnd();
    void writeObjectEnd();

    const Char* toString();

};

} }
GS2_END_OF_NAMESPACE

#endif //GS2_CORE_JSON_JSONWRITER_HPP_
