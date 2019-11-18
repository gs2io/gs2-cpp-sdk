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

#ifndef GS2_CORE_UTIL_STANDARDALLOCATOR_HPP_
#define GS2_CORE_UTIL_STANDARDALLOCATOR_HPP_

#include "../common.hpp"
#include <memory>
#include <limits>

GS2_START_OF_NAMESPACE

namespace detail {

template<class T> class StandardAllocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    // typedef std::true_type propagate_on_container_move_assignment;
    template<class U> struct rebind { typedef StandardAllocator<U> other; };
    // typedef std::true_type is_always_equal;

    StandardAllocator() = default;

    template<class U>
    StandardAllocator(const StandardAllocator<U>&)
    {}

    pointer address(reference x) const
    {
        return std::addressof(x);
    }

    const_pointer address(const_reference x) const
    {
        return std::addressof(x);
    }

    pointer allocate(size_type n, std::allocator<void>::const_pointer hint = 0)
    {
        GS2_NOT_USED(hint);
        return reinterpret_cast<pointer>(Gs2Object::getAllocator().malloc(sizeof(T) * n));
    }

    void deallocate(pointer p, size_type n)
    {
        GS2_NOT_USED(n);
        Gs2Object::getAllocator().free(p);
    }

    size_type max_size() const
    {
        return std::numeric_limits<size_type>::max() / sizeof(value_type);
    }

    void construct(pointer p, const_reference val)
    {
#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma warning(push)
#pragma warning(disable:4291)
#endif
        new(p) T(val);
#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma warning(pop)
#endif
    }

    /*
    template< class U, class... Args >
    void construct( U* p, Args&&... args );
    */

    void destroy( pointer p )
    {
        p->~T();
    }

    /*
    template< class U >
    void destroy( U* p );
    */
};

template<class T>
bool operator==(const StandardAllocator<T>& lhs, const StandardAllocator<T>& lhr)
{
    return true;
}

template<class T>
bool operator!=(const StandardAllocator<T>& lhs, const StandardAllocator<T>& lhr)
{
    return !(lhs == lhr);
}

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_STANDARDALLOCATOR_HPP_
