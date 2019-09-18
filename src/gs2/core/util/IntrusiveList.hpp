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
#include <cassert>
#include <utility>

GS2_START_OF_NAMESPACE

namespace detail {

class IntrusiveListItemBase
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
    IntrusiveListItemBase() :
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
        return static_cast<T*>(IntrusiveListItemBase::getNext());
    }
};

class IntrusiveListBase : public Gs2Object
{
private:
    IntrusiveListItemBase* m_pHead;
    IntrusiveListItemBase* m_pTail;     // unreliable when m_pHead == nullptr

protected:
    void enqueue(IntrusiveListItemBase& item)
    {
        assert(item.m_pNext == nullptr);

        if (m_pHead == nullptr)     // also m_pTail == nullptr
        {
            m_pHead = &item;
        }
        else
        {
            m_pTail->m_pNext = &item;
        }
        m_pTail = &item;
    }

    IntrusiveListItemBase* dequeue()
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
                item.m_pNext = nullptr;
                return &item;
            }

            ppItem = &(*ppItem)->m_pNext;
        }

        return nullptr;
    }

    IntrusiveListItemBase* getHead()
    {
        return m_pHead;
    }

public:
    IntrusiveListBase() :
        Gs2Object(),
        m_pHead(nullptr),
        m_pTail(nullptr)
    {}

    IntrusiveListBase(const IntrusiveListBase&) = delete;

    IntrusiveListBase(IntrusiveListBase&& intrusiveListBase) :
        Gs2Object(),
        m_pHead(intrusiveListBase.m_pHead),
        m_pTail(intrusiveListBase.m_pTail)
    {
        intrusiveListBase.m_pHead = nullptr;
    }

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

    IntrusiveList(IntrusiveList&& intrusiveList) :
        IntrusiveListBase(std::move(intrusiveList))
    {}

    ~IntrusiveList() = default;

    void enqueue(T& item)
    {
        IntrusiveListBase::enqueue(item);
    }

    T* dequeue()
    {
        return static_cast<T*>(IntrusiveListBase::dequeue());
    }

    T* remove(T& item)
    {
        return static_cast<T*>(IntrusiveListBase::remove(item));
    }

    T* getHead()
    {
        return static_cast<T*>(IntrusiveListBase::getHead());
    }
};

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_UTIL_INTRUSIVELIST_HPP_
