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
#include <vector>

GS2_START_OF_NAMESPACE

template<typename T> class List : public Gs2Object {

private:

    std::vector<T, detail::StandardAllocator<T>>m_List;

public:

    List()
    {}

    List(const List& obj) :
        Gs2Object(obj),
        m_List(obj.m_List)
    {
    }

    List(List&& obj) :
        Gs2Object(std::move(obj)),
        m_List(std::move(obj.m_List))
    {
    }

    ~List() {
    }

    List& operator=(const List& list)
    {
        Gs2Object::operator=(list);

        if (&list != this)
        {
            m_List.clear();
            for (const auto& element : list.m_List)
            {
                m_List.emplace_back(element);
            }
        }

        return *this;
    }

    List& operator=(List&& list)
    {
        Gs2Object::operator=(std::move(list));

        if (&list != this)
        {
            m_List = std::move(list.m_List);
        }

        return *this;
    }

    const List* operator->() const
    {
        return this;
    }

    List* operator->()
    {
        return this;
    }

    const Int32 getCount() const
    {
        return m_List.size();
    }

    const T& operator[](Int32 i) const
    {
        return m_List[i];
    }

    void clear()
    {
        m_List.clear();
    }

    List& operator+=(const T& element)
    {
        m_List.emplace_back(element);
        return *this;
    }

    List& operator+=(T&& element)
    {
        m_List.emplace_back(std::move(element));
        return *this;
    }

    List& operator+=(const List& list)
    {
        m_List.insert(m_List.end(), list.m_List.begin(), list.m_List.end());
        return *this;
    }

    List& operator+=(List&& list)
    {
        for (auto itr = list.m_List.begin(); itr != list.m_List.end(); ++itr)
        {
            m_List.insert(m_List.end(), std::move(*itr));
        }
        return *this;
    }
};

template<typename T>
bool operator!=(const List<T>& lhs, const List<T>& lhr)
{
    Int32 count = lhs.getCount();
    if (count != lhr.getCount())
    {
        return true;
    }

    for (Int32 i = 0; i < count; ++i)
    {
        if (lhs[i] != lhr[i])
        {
            return true;
        }
    }

    return false;
}

template<typename T>
bool operator==(const List<T>& lhs, const List<T>& lhr)
{
    return !(lhs != lhr);
}

template<> class List<StringHolder> : public Gs2Object {

private:

    std::vector<StringHolder, detail::StandardAllocator<StringHolder>>m_List;

public:

    List()
    {}

    List(const List& obj) :
        Gs2Object(obj),
        m_List(obj.m_List)
    {
    }

    List(List&& obj) :
        Gs2Object(std::move(obj)),
        m_List(std::move(obj.m_List))
    {
    }

    ~List() {
    }

    List& operator=(const List& list)
    {
        Gs2Object::operator=(list);

        if (&list != this)
        {
            m_List.clear();
            for (const auto& element : list.m_List)
            {
                m_List.emplace_back(element);
            }
        }

        return *this;
    }

    List& operator=(List&& list)
    {
        Gs2Object::operator=(std::move(list));

        if (&list != this)
        {
            m_List = std::move(list.m_List);
        }

        return *this;
    }

    const List* operator->() const
    {
        return this;
    }

    List* operator->()
    {
        return this;
    }

    const Int32 getCount() const
    {
        return m_List.size();
    }

    const StringHolder& operator[](Int32 i) const
    {
        return m_List[i];
    }

    void clear()
    {
        m_List.clear();
    }

    List& operator+=(const StringHolder& element)
    {
        m_List.emplace_back(element);
        return *this;
    }

    List& operator+=(StringHolder&& element)
    {
        m_List.emplace_back(std::move(element));
        return *this;
    }

    List& operator+=(const Char element[])
    {
        m_List.emplace_back(element);
        return *this;
    }

    List& operator+=(const List& list)
    {
        m_List.insert(m_List.end(), list.m_List.begin(), list.m_List.end());
        return *this;
    }

    List& operator+=(List&& list)
    {
        for (auto itr = list.m_List.begin(); itr != list.m_List.end(); ++itr)
        {
            m_List.insert(m_List.end(), std::move(*itr));
        }
        return *this;
    }

    // TODO: move
};


namespace detail {

template<typename T>
inline Int32 getCountOfListElements(const List<T>& list)
{
	return list.getCount();
}

template<typename T>
inline void addToList(List<T>& list, T&& value)
{
	list += std::move(value);
}

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_LIST_HPP_
