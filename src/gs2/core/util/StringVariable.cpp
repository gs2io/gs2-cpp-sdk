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

#include "StringVariable.hpp"
#include "List.hpp"
#include "StringHolder.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

namespace detail {

namespace {

inline char toHex(char ch)
{
    return ch < 10 ? '0' + ch : 'A' + (ch - 10);
}

void encodeUrl(StringVariable& dst, const char src[], std::size_t srcSize)
{
    dst.reserve(srcSize * 12 / 10);     // Base64 変換済の文字列を変換するのが主要ユースケースなので、ざっくり1.2倍程度確保

    char encoded[4];
    encoded[0] = '%';
    encoded[3] = '\0';

    for (int i = 0; i < srcSize; i++)
    {
        char ch = src[i];

        if (ch == ' ')
        {
            dst.append("+");
        }
        else if (std::isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~')
        {
            dst.append(1, ch);
        }
        else
        {
            encoded[1] = toHex((ch >> 4) & 0xF);
            encoded[2] = toHex((ch & 0xF));
            dst.append(encoded);
        }
    }
}

void encodeUrl(StringVariable& dst, const char src[])
{
    encodeUrl(dst, src, std::strlen(src));
}

}

StringVariable::StringVariable(const List<StringHolder>& list)
{
    auto count = getCountOfListElements(list);
    if (count > 0)
    {
        append(list[0].getCString());

        for (int i = 1; i < count; ++i)
        {
            append(",").append(list[i].getCString());
        }
    }
}

StringVariable::StringVariable(const Char string[], UrlSafeEncode urlSafeEncode)
{
    GS2_NOT_USED(urlSafeEncode);

    encodeUrl(*this, string);
}

StringVariable& StringVariable::replace(const Char pattern[], const Char replacement[])
{
    std::size_t patternLength = std::strlen(pattern);
    std::size_t replacementLength = std::strlen(replacement);

    size_type index = 0;
    while ((index = find(pattern, index)) != StringVariable::npos)
    {
        BasicString::replace(index, patternLength, replacement);
        index += replacementLength;
    }

    return *this;
}

StringVariable& StringVariable::replace(const StringVariable& pattern, const Char replacement[])
{
    return replace(pattern.c_str(), replacement);
}

StringVariable& StringVariable::replace(const Char pattern[], const StringVariable& replacement)
{
    return replace(pattern, replacement.c_str());
}

StringVariable& StringVariable::replace(const StringVariable& pattern, const StringVariable& replacement)
{
    return replace(pattern.c_str(), replacement.c_str());
}

bool StringVariable::endsWith(const StringVariable& suffix)
{
    return endsWith(suffix.c_str());
}

bool StringVariable::endsWith(const Char suffix[])
{
    auto suffixLength = strlen(suffix);
    if (this->size() < suffixLength) return false;
    return this->compare(this->size() - suffixLength, suffixLength, suffix) == 0;
}

}

GS2_END_OF_NAMESPACE
