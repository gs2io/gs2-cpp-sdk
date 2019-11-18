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

JsonWriter::JsonWriter() :
    m_StringBuffer(&Allocator::getInstance()),
    m_Writer(m_StringBuffer, &Allocator::getInstance())
{
}

void JsonWriter::reset()
{
    m_StringBuffer.Clear();
    m_Writer.Reset(m_StringBuffer);
}

void JsonWriter::writeObjectStart()
{
    m_Writer.StartObject();
}

void JsonWriter::writeArrayStart()
{
    m_Writer.StartArray();
}

void JsonWriter::writePropertyName(const Char name[])
{
    m_Writer.Key(name);
}

void JsonWriter::writeCharArray(const Char value[])
{
    m_Writer.String(value);
}

void JsonWriter::writeBool(Bool value)
{
    m_Writer.Bool(value);
}

void JsonWriter::writeInt32(Int32 value)
{
    m_Writer.Int(value);
}

void JsonWriter::writeInt64(Int64 value)
{
    m_Writer.Int64(value);
}

void JsonWriter::writeFloat(Float value)
{
    m_Writer.Double(value);
}

void JsonWriter::writeDouble(Double value)
{
    m_Writer.Double(value);
}

void JsonWriter::writeArrayEnd()
{
    m_Writer.EndArray();
}

void JsonWriter::writeObjectEnd()
{
    m_Writer.EndObject();
}

const Char* JsonWriter::toString()
{
    return m_StringBuffer.GetString();
}

} }
GS2_END_OF_NAMESPACE
