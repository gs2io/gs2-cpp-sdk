/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_MESSAGEBUFFER_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_MESSAGEBUFFER_HPP_

#include "../common.hpp"
#include <gs2/core/Gs2Object.hpp>
#include <cstring>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

class MessageBufferProxy : public Gs2Object {
private:
    UInt8 *m_Buffer;
    UInt32 m_Size;
    UInt8 *m_pCurrent;

public:
    MessageBufferProxy(void *message, UInt32 size)
            : m_Buffer(reinterpret_cast<UInt8*>(message)),
              m_Size(size),
              m_pCurrent(m_Buffer) {
    }

    inline void writeU8(UInt8 value) {
        // TODO: assert(m_pCurrent + 1 < &m_Buffer[m_Size]);
        *m_pCurrent++ = value;
    }

    inline void writeU16(UInt16 value) {
        // TODO: assert(m_pCurrent + 2 < &m_Buffer[m_Size]);
        *m_pCurrent++ = static_cast<UInt8>(value >> 8);
        *m_pCurrent++ = static_cast<UInt8>(value);
    }

    inline void writeU32(UInt16 value) {
        // TODO: assert(m_pCurrent + 4 < &m_Buffer[m_Size]);
        *m_pCurrent++ = static_cast<UInt8>(value >> 24);
        *m_pCurrent++ = static_cast<UInt8>(value >> 16);
        *m_pCurrent++ = static_cast<UInt8>(value >> 8);
        *m_pCurrent++ = static_cast<UInt8>(value);
    }

    inline void writeBinary(const void *binary, UInt32 size) {
        // TODO: assert(m_pCurrent + size < &m_Buffer[m_Size]);
        std::memcpy(m_pCurrent, binary, size);
        m_pCurrent += size;
    }

    void writeMbi(UInt32 value) {
        // TODO: assert(size < 0x0fffffff);
        do {
            UInt8 digit = value & 0x7f;
            value >>= 7;
            if (value > 0) {
                digit |= 0x80;
            }
            writeU8(digit);
        } while (value > 0);
    }

    inline UInt8 readU8() {
        // TODO: assert(m_pCurrent + 1 < &m_Buffer[m_Size]);
        return *m_pCurrent++;
    }

    inline UInt16 readU16() {
        // TODO: assert(m_pCurrent + 2 < &m_Buffer[m_Size]);
        UInt16 value = 0;
        value = *m_pCurrent++ << 8;
        value = *m_pCurrent++;
        return value;
    }

    inline UInt32 readU32() {
        // TODO: assert(m_pCurrent + 4 < &m_Buffer[m_Size]);
        UInt32 value = 0;
        value = *m_pCurrent++ << 24;
        value = *m_pCurrent++ << 16;
        value = *m_pCurrent++ << 8;
        value = *m_pCurrent++;
        return value;
    }

    // TODO: readBinary

    UInt32 readMbi() {
        UInt8 digit;
        UInt32 value = 0;
        int shift = 0;
        do {
            digit = readU8();
            value |= static_cast<UInt32>(digit & 0x7f) << shift;
            shift += 7;
        } while ((digit & 0x80) != 0);

        return value;
    }

    inline void skip(UInt32 size) {
        m_pCurrent += size;
    }

    inline void *getCurrent() const {
        return m_pCurrent;
    }

    inline bool isEof() const {
        return m_pCurrent >= &m_Buffer[m_Size];
    }

    UInt32 getRemainingSize() const {
        return isEof() ? 0 : m_Size - (m_pCurrent - &m_Buffer[0]);
    }

    static inline UInt32 getMbiSizeOf(UInt32 value) {
        if (value <= 0x7f) return 1;
        if (value <= 0x3fff) return 2;
        if (value <= 0x1fffff) return 3;
        if (value <= 0x0fffffff) return 4;
        // TODO: assert();
        return 0;
    }
};

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_MESSAGEBUFFER_HPP_
