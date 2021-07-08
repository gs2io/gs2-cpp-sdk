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

#ifndef GS2_CORE_UTIL_LIST_HPP_
#define GS2_CORE_UTIL_LIST_HPP_

#include "../Gs2Object.hpp"
#include "StandardAllocator.hpp"
#include "StringHolder.hpp"
#include <memory>
#include <vector>
#include <utility>

GS2_START_OF_NAMESPACE

namespace detail {

template <class T>
inline void deepCopy(std::vector<T, detail::StandardAllocator<T>>& to, const std::vector<T, detail::StandardAllocator<T>>& from)
{
    for (const auto& e : from)
    {
        to.emplace_back(e.deepCopy());
    }
}

// 実際にはディープコピーの必要がない型たち
template<> inline void deepCopy<Int8>(std::vector<Int8, detail::StandardAllocator<Int8>>& to, const std::vector<Int8, detail::StandardAllocator<Int8>>& from) { to = from; }
template<> inline void deepCopy<Int16>(std::vector<Int16, detail::StandardAllocator<Int16>>& to, const std::vector<Int16, detail::StandardAllocator<Int16>>& from) { to = from; }
template<> inline void deepCopy<Int32>(std::vector<Int32, detail::StandardAllocator<Int32>>& to, const std::vector<Int32, detail::StandardAllocator<Int32>>& from) { to = from; }
template<> inline void deepCopy<Int64>(std::vector<Int64, detail::StandardAllocator<Int64>>& to, const std::vector<Int64, detail::StandardAllocator<Int64>>& from) { to = from; }
template<> inline void deepCopy<UInt8>(std::vector<UInt8, detail::StandardAllocator<UInt8>>& to, const std::vector<UInt8, detail::StandardAllocator<UInt8>>& from) { to = from; }
template<> inline void deepCopy<UInt16>(std::vector<UInt16, detail::StandardAllocator<UInt16>>& to, const std::vector<UInt16, detail::StandardAllocator<UInt16>>& from) { to = from; }
template<> inline void deepCopy<UInt32>(std::vector<UInt32, detail::StandardAllocator<UInt32>>& to, const std::vector<UInt32, detail::StandardAllocator<UInt32>>& from) { to = from; }
template<> inline void deepCopy<UInt64>(std::vector<UInt64, detail::StandardAllocator<UInt64>>& to, const std::vector<UInt64, detail::StandardAllocator<UInt64>>& from) { to = from; }
template<> inline void deepCopy<Float>(std::vector<Float, detail::StandardAllocator<Float>>& to, const std::vector<Float, detail::StandardAllocator<Float>>& from) { to = from; }
template<> inline void deepCopy<Double>(std::vector<Double, detail::StandardAllocator<Double>>& to, const std::vector<Double, detail::StandardAllocator<Double>>& from) { to = from; }
template<> inline void deepCopy<StringHolder>(std::vector<StringHolder, detail::StandardAllocator<StringHolder>>& to, const std::vector<StringHolder, detail::StandardAllocator<StringHolder>>& from) { to = from; }

}

template<typename T>
class List : public Gs2Object
{
private:
    using Vector = std::vector<T, detail::StandardAllocator<T>>;

    std::shared_ptr<Vector> m_pList;

public:
    class Iterator
    {
        friend List;

    private:
        typename Vector::iterator m_Iterator;

        explicit Iterator(typename Vector::iterator iterator) :
            m_Iterator(iterator)
        {
        }

    public:
        T& operator *()
        {
            return *m_Iterator;
        }

        Iterator& operator++()
        {
            ++m_Iterator;
            return *this;
        }

        bool operator==(Iterator iterator) const
        {
            return m_Iterator == iterator.m_Iterator;
        }

        bool operator!=(Iterator iterator) const
        {
            return !(*this == iterator);
        }
    };

    class ConstIterator
    {
        friend List;

    private:
        typename Vector::const_iterator m_ConstIterator;

        ConstIterator(typename Vector::const_iterator constIterator) :
            m_ConstIterator(constIterator)
        {
        }

    public:
        const T& operator *() const
        {
            return *m_ConstIterator;
        }

        ConstIterator& operator++()
        {
            ++m_ConstIterator;
            return *this;
        }

        bool operator==(ConstIterator constIterator) const
        {
            return m_ConstIterator == constIterator.m_ConstIterator;
        }

        bool operator!=(ConstIterator constIterator) const
        {
            return !(*this == constIterator);
        }
    };

public:
    List() :
        m_pList(std::allocate_shared<Vector>(detail::StandardAllocator<char>()))
    {}

    List(const List& obj) :
        Gs2Object(obj),
        m_pList(obj.m_pList)
    {}

    List(List&& obj) :
        Gs2Object(std::move(obj)),
        m_pList(std::move(obj.m_pList))
    {}

    ~List() = default;

    List& operator=(const List& list) = default;
    List& operator=(List&& list) = default;

    List deepCopy() const
    {
        List list;
        detail::deepCopy(*list.m_pList, *m_pList);
        return list;
    }

    const List* operator->() const
    {
        return this;
    }

    List* operator->()
    {
        return this;
    }

    bool isValid() const
    {
        return m_pList != nullptr;
    }

    Int32 getCount() const
    {
        return m_pList->size();
    }

    const T& operator[](Int32 i) const
    {
        return (*m_pList)[i];
    }

    void clear()
    {
        m_pList->clear();
    }

    List& operator+=(T element)
    {
        m_pList->emplace_back(std::move(element));
        return *this;
    }

    List& operator+=(const List& list)
    {
        std::copy(list.m_pList->begin(), list.m_pList->end(), std::back_inserter(*m_pList));
        return *this;
    }

    List& operator+=(List&& list)
    {
        std::move(list.m_pList->begin(), list.m_pList->end(), std::back_inserter(*m_pList));
        list.clear();
        return *this;
    }

    Iterator begin()
    {
        return Iterator(m_pList->begin());
    }

    Iterator end()
    {
        return Iterator(m_pList->end());
    }

    ConstIterator begin() const
    {
        return ConstIterator(m_pList->begin());
    }

    ConstIterator end() const
    {
        return ConstIterator(m_pList->end());
    }

    bool operator!=(const List& list) const
    {
        if (m_pList != list.m_pList)
        {
            if (m_pList == nullptr || list.m_pList == nullptr)
            {
                return true;
            }

            auto count = getCount();

            if (count != list.getCount())
            {
                return true;
            }

            for (Int32 i = 0; i < count; ++i)
            {
                if ((*m_pList)[i] != (*list.m_pList)[i])
                {
                    return true;
                }
            }
        }

        return false;
    }
};

template<typename T>
inline bool operator==(const List<T>& lhs, const List<T>& lhr)
{
    return !(lhs != lhr);
}


namespace detail {

template<typename T>
inline Int32 getCountOfListElements(const List<T>& list)
{
    return list.getCount();
}

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_LIST_HPP_
