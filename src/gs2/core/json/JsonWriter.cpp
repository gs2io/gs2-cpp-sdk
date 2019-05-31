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

#include "JsonWriter.hpp"
#include "Allocator.hpp"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

JsonWriter JsonWriter::instance;

JsonWriter::JsonWriter()
{
    this->stringBuffer = new RapidJsonStringBuffer(&Allocator::getInstance());
    this->writer = new RapidJsonWriter(*stringBuffer, &Allocator::getInstance());
}

JsonWriter& JsonWriter::getInstance() {
    return instance;
}

JsonWriter::~JsonWriter()
{
    if(writer != nullptr) {
        delete this->writer;
        this->writer = nullptr;
    }
}

void JsonWriter::reset()
{
    stringBuffer->Clear();
    writer->Reset(*stringBuffer);
}

void JsonWriter::writeObjectStart()
{
    writer->StartObject();
}

void JsonWriter::writeArrayStart()
{
    writer->StartArray();
}

void JsonWriter::writePropertyName(const Char* name)
{
    writer->Key(name);
}

void JsonWriter::writeCharArray(const Char* value)
{
    writer->String(value);
}

void JsonWriter::writeBool(bool value)
{
    writer->Bool(value);
}

void JsonWriter::writeInt32(Int32 value)
{
    writer->Int(value);
}

void JsonWriter::writeInt64(Int64 value)
{
    writer->Int64(value);
}

void JsonWriter::writeFloat(Float value)
{
    writer->Double(value);
}

void JsonWriter::writeDouble(Double value)
{
    writer->Double(value);
}

void JsonWriter::writeArrayEnd()
{
    writer->EndArray();
}

void JsonWriter::writeObjectEnd()
{
    writer->EndObject();
}

const Char* JsonWriter::toString()
{
    return stringBuffer->GetString();
}

} }
GS2_END_OF_NAMESPACE
