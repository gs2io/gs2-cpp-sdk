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

#ifndef GS2_CORE_UTIL_INTRUSIVELIST_HPP_
#define GS2_CORE_UTIL_INTRUSIVELIST_HPP_

#include "../Gs2Object.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class IntrusiveListItemBase : public Gs2Object
{
    friend class IntrusiveListBase;

private:
    IntrusiveListItemBase* m_pNext;

protected:
    IntrusiveListItemBase* getNext()
    {
        return m_pNext;
    }

public:
    IntrusiveListItemBase():
        m_pNext(nullptr)
    {}

    ~IntrusiveListItemBase() = default;
};

template<typename T>
class IntrusiveListItem : public IntrusiveListItemBase
{
public:
    IntrusiveListItem() = default;
    ~IntrusiveListItem() = default;

    T* getNext()
    {
        return static_cast<T*>(getNext());
    }
};

class IntrusiveListBase : public Gs2Object
{
private:
    IntrusiveListItemBase* m_pHead;

protected:
    void push(IntrusiveListItemBase& item)
    {
        assert(item.m_pNext == nullptr);

        item.m_pNext = m_pHead;
        m_pHead = &item;
    }

    IntrusiveListItemBase* pop()
    {
        auto pHead = m_pHead;

        if (pHead != nullptr)
        {
            m_pHead = pHead->m_pNext;
            pHead->m_pNext = nullptr;
        }

        return pHead;
    }

    IntrusiveListItemBase* remove(IntrusiveListItemBase& item)
    {
        auto** ppItem = &m_pHead;
        while (*ppItem != nullptr)
        {
            if (*ppItem == &item)
            {
                *ppItem = item.m_pNext;
                return &item;
            }

            ppItem = &item.m_pNext;
        }

        return nullptr;
    }

public:
    IntrusiveListBase():
        m_pHead(nullptr)
    {}

    ~IntrusiveListBase() = default;

    bool isEmpty() const
    {
        return m_pHead == nullptr;
    }
};

template<typename T>
class IntrusiveList : public IntrusiveListBase
{
public:
    IntrusiveList() = default;
    ~IntrusiveList() = default;

    void push(T& item)
    {
        IntrusiveListBase::push(item);
    }

    T* pop()
    {
        return static_cast<T*>(IntrusiveListBase::pop());
    }

    T* remove(T& item)
    {
        return static_cast<T*>(IntrusiveListBase::remove(item));
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_INTRUSIVELIST_HPP_
