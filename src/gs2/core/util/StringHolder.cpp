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

#include "StringHolder.hpp"
#include "StandardAllocator.hpp"
#include <cstring>

GS2_START_OF_NAMESPACE

namespace {

    inline void strcpy(char buffer[], const char string[])
    {
#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma warning(push)
#pragma warning(disable:4996)
#endif
        std::strcpy(buffer, string);
#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma warning(pop)
#endif
    }

    inline Char* alloc(Int32 size)
    {
        return reinterpret_cast<Char*>(Gs2Object::getAllocator().malloc(size));
    }

    void free(void* p)
    {
        Gs2Object::getAllocator().free(p);
    }
}

StringHolder::StringHolder() :
    m_Size(1)
{
}

StringHolder::StringHolder(const Char string[]) :
    m_Size(std::strlen(string) + 1)
{
    auto* buffer = alloc(m_Size);
    strcpy(buffer, string);
    m_Buffer.reset(buffer, free, detail::StandardAllocator<Char>());
}

StringHolder::StringHolder(const StringHolder& stringHolder) :
    m_Size(stringHolder.m_Size),
    m_Buffer(stringHolder.m_Buffer)
{
}

StringHolder::StringHolder(StringHolder&& stringHolder) noexcept :
    m_Size(stringHolder.m_Size),
    m_Buffer(std::move(stringHolder.m_Buffer))
{
    stringHolder.m_Size = 1;
}

StringHolder& StringHolder::operator=(const StringHolder& stringHolder)
{
    Gs2Object::operator=(stringHolder);

    if (&stringHolder != this)
    {
        m_Size = stringHolder.m_Size;
        m_Buffer = stringHolder.m_Buffer;
    }

    return *this;
}

StringHolder& StringHolder::operator=(StringHolder&& stringHolder) noexcept
{
    Gs2Object::operator=(std::move(stringHolder));

    if (&stringHolder != this)
    {
        m_Size = stringHolder.m_Size;
        m_Buffer = std::move(stringHolder.m_Buffer);

        stringHolder.m_Size = 1;
    }

    return *this;
}

StringHolder& StringHolder::operator=(const Char string[])
{
    if (string != m_Buffer.get())
    {
        m_Size = std::strlen(string) + 1;
        auto* buffer = alloc(m_Size);
        strcpy(buffer, string);
        m_Buffer.reset(buffer, free, detail::StandardAllocator<Char>());
    }

    return *this;
}

StringHolder::operator const Char*() const
{
    return getCString();
}

Int32 StringHolder::getSize() const
{
    return m_Size;
}

const Char* StringHolder::getCString() const
{
    return m_Buffer ? m_Buffer.get() : "";
}

bool operator==(const StringHolder& lhs, const StringHolder& lhr)
{
    return lhs.m_Buffer == lhr.m_Buffer || (lhs.m_Size == lhr.m_Size && std::strcmp(lhs.m_Buffer.get(), lhr.m_Buffer.get()) == 0);
}

bool operator==(const StringHolder& lhs, const Char lhr[])
{
    return std::strcmp(lhs.m_Buffer.get(), lhr) == 0;
}

bool operator==(const Char lhs[], const StringHolder& lhr)
{
    return lhr == lhs;
}

bool operator==(const optional<StringHolder>& lhs, const Char lhr[])
{
    return lhs ? *lhs == lhr : false;
}

bool operator==(const Char lhs[], const optional<StringHolder>& lhr)
{
    return lhr == lhs;
}

bool operator!=(const StringHolder& lhs, const StringHolder& lhr)
{
    return !(lhs == lhr);
}

bool operator!=(const StringHolder& lhs, const Char lhr[])
{
    return !(lhs == lhr);
}

bool operator!=(const Char lhs[], const StringHolder& lhr)
{
    return !(lhs == lhr);
}

bool operator!=(const optional<StringHolder>& lhs, const Char lhr[])
{
    return !(lhs == lhr);
}

bool operator!=(const Char lhs[], const optional<StringHolder>& lhr)
{
    return !(lhs == lhr);
}

GS2_END_OF_NAMESPACE