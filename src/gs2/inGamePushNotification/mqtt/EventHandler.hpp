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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_EVENTHANDLER_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_EVENTHANDLER_HPP_

#include "../common.hpp"
#include <gs2/core/Gs2Object.hpp>
#include <functional>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE

// TODO: core の util へ
class LinkedListEntry : public Gs2Object {
private:
    LinkedListEntry *m_pPrevious;
    LinkedListEntry *m_pNext;

public:
    LinkedListEntry()
            : m_pPrevious(nullptr),
              m_pNext(nullptr) {
    }

    virtual ~LinkedListEntry() {
        if (m_pPrevious != nullptr) {
            m_pPrevious->m_pNext = m_pNext;
            m_pPrevious = nullptr;
        }
        if (m_pNext != nullptr) {
            m_pNext->m_pPrevious = m_pPrevious;
            m_pNext = nullptr;
        }
    }

    bool add(LinkedListEntry &linkedListEntry) {
        if (&linkedListEntry == this) {
            return false;
        }

        if (linkedListEntry.m_pNext != nullptr) {
            return false;
        }

        if (m_pNext == nullptr) {
            m_pNext = &linkedListEntry;
            linkedListEntry.m_pPrevious = this;
            return true;
        }

        return m_pNext->add(linkedListEntry);
    }

    bool remove(LinkedListEntry &linkedListEntry) {
        if (linkedListEntry.m_pPrevious == nullptr) {
            return false;
        }

        if (m_pNext == nullptr) {
            return false;
        }

        if (m_pNext == &linkedListEntry) {
            // TODO: assert(m_pNext->m_pPrevious == this);
            m_pNext = linkedListEntry.m_pNext;
            if (m_pNext != nullptr) {
                m_pNext->m_pPrevious = this;
            }
            linkedListEntry.m_pPrevious = nullptr;
            linkedListEntry.m_pNext = nullptr;

            return true;
        }

        return m_pNext->remove(linkedListEntry);
    }

    LinkedListEntry* getPrevious() {
        return m_pPrevious;
    }

    const LinkedListEntry* getPrevious() const {
        return m_pPrevious;
    }

    LinkedListEntry* getNext() {
        return m_pNext;
    }

    const LinkedListEntry* getNext() const {
        return m_pNext;
    }

    // TODO: iterator
};

class EventHandlerBase : protected LinkedListEntry {
    friend class MqttClient;

private:
    virtual bool isDeleteRequired() {
        return false;
    }

public:
    ~EventHandlerBase() {
        // 自分に繋がった先をすべて切り離し、解放が必要なものは解放する
        // 自身の削除によるつなぎ直しは基底クラスのデストラクタに任せる
        auto pEventHandler = static_cast<EventHandlerBase*>(getNext());
        while (pEventHandler != nullptr)
        {
            remove(*pEventHandler);
            if (pEventHandler->isDeleteRequired())
            {
                delete pEventHandler;
            }
            pEventHandler = static_cast<EventHandlerBase*>(getNext());
        }
    }
};

template<class Traits, class... Args>
class EventHandler : public EventHandlerBase {
public:
    void invoke(Args... args) {
        execute(args...);

        if (getNext() != nullptr) {
            static_cast<EventHandler *>(getNext())->invoke(args...);
        }
    }

    virtual void execute(Args...) = 0;
};

class ConnectEventHandlerTraits;

class ReceiveEventHandlerTraits;

class CloseEventHandlerTraits;

class ErrorEventHandlerTraits;

typedef EventHandler<ConnectEventHandlerTraits> ConnectEventHandler;
typedef EventHandler<ReceiveEventHandlerTraits, const char[]> ReceiveEventHandler;
typedef EventHandler<CloseEventHandlerTraits> CloseEventHandler;
//typedef EventHandler<ErrorEventHandlerTraits, MqttClient::Error> ErrorEventHandler;

template<class T, class... Args>
class RootEventHandler : public T {
private:
    class FunctionHolder : public T {
    private:
        std::function<void(Args...)> m_Function;

        virtual void execute(Args... args) {
            m_Function(args...);
        }

    public:
        FunctionHolder(std::function<void(Args...)> function)
                : m_Function(function) {
        }

        virtual bool isDeleteRequired() {
            return true;
        }
    };

    virtual void execute(Args... args) {
    }

public:
    bool add(T &t) {
        return T::add(t);
    }

    bool add(std::function<void(Args...)> function) {
        return T::add(*new FunctionHolder(function));
    }

    bool remove(T &t) {
        return T::remove(t);
    }

    // TODO: bool remove(std::function<void(Args...)> function);

    RootEventHandler &operator+=(T &t) {
        add(t);
        return *this;
    }

    RootEventHandler &operator+=(std::function<void(Args...)> function) {
        add(function);
        return *this;
    }

    RootEventHandler &operator-=(T &t) {
        remove(t);
        return this;
    }
};

GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_EVENTHANDLER_HPP_
