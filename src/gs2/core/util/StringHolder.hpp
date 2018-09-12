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

#ifndef GS2_CORE_UTIL_STRINGHOLDER_HPP_
#define GS2_CORE_UTIL_STRINGHOLDER_HPP_

#include "../Gs2Object.hpp"
#include "../external/optional/optional.hpp"

GS2_START_OF_NAMESPACE

class StringHolder : public Gs2Object {

    friend bool operator==(const StringHolder& lhs, const StringHolder& lhr);
    friend bool operator==(const StringHolder& lhs, const Char lhr[]);

private:
    Int32 m_Size;    // TODO: unsigned
    Char* m_Buffer;

public:
    explicit StringHolder(const Char string[]);

    StringHolder(const StringHolder& stringHolder);

    StringHolder(StringHolder&& stringHolder) noexcept;

    ~StringHolder();

    StringHolder& operator=(const StringHolder& stringHolder);

    StringHolder& operator=(StringHolder&& stringHolder) noexcept;

    StringHolder& operator=(const Char string[]);

    operator const Char*() const;

    Int32 getSize() const;

    const Char* getCString() const;
};

bool operator==(const StringHolder& lhs, const StringHolder& lhr);
bool operator==(const StringHolder& lhs, const Char lhr[]);
bool operator==(const Char lhs[], const StringHolder& lhr);
bool operator==(const optional<StringHolder>& lhs, const Char lhr[]);
bool operator==(const Char lhs[], const optional<StringHolder>& lhr);
bool operator!=(const StringHolder& lhs, const StringHolder& lhr);
bool operator!=(const StringHolder& lhs, const Char lhr[]);
bool operator!=(const Char lhs[], const StringHolder& lhr);
bool operator!=(const optional<StringHolder>& lhs, const Char lhr[]);
bool operator!=(const Char lhs[], const optional<StringHolder>& lhr);


GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_STRINGHOLDER_HPP_
