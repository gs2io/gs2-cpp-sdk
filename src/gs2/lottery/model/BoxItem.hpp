/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LOTTERY_MODEL_BOXITEM_HPP_
#define GS2_LOTTERY_MODEL_BOXITEM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * ボックスから取り出したアイテム
 *
 * @author Game Server Services, Inc.
 *
 */
class BoxItem : public Gs2Object
{
    friend bool operator!=(const BoxItem& lhs, const BoxItem& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 入手アクションのリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 残り数量 */
        optional<Int32> remaining;
        /** 初期数量 */
        optional<Int32> initial;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            acquireActions(data.acquireActions),
            remaining(data.remaining),
            initial(data.initial)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            acquireActions(std::move(data.acquireActions)),
            remaining(std::move(data.remaining)),
            initial(std::move(data.initial))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "acquireActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->acquireActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "remaining") == 0) {
                if (jsonValue.IsInt())
                {
                    this->remaining = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "initial") == 0) {
                if (jsonValue.IsInt())
                {
                    this->initial = jsonValue.GetInt();
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    BoxItem() :
        m_pData(nullptr)
    {}

    BoxItem(const BoxItem& boxItem) :
        Gs2Object(boxItem),
        m_pData(boxItem.m_pData != nullptr ? new Data(*boxItem.m_pData) : nullptr)
    {}

    BoxItem(BoxItem&& boxItem) :
        Gs2Object(std::move(boxItem)),
        m_pData(boxItem.m_pData)
    {
        boxItem.m_pData = nullptr;
    }

    ~BoxItem()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    BoxItem& operator=(const BoxItem& boxItem)
    {
        Gs2Object::operator=(boxItem);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*boxItem.m_pData);

        return *this;
    }

    BoxItem& operator=(BoxItem&& boxItem)
    {
        Gs2Object::operator=(std::move(boxItem));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = boxItem.m_pData;
        boxItem.m_pData = nullptr;

        return *this;
    }

    const BoxItem* operator->() const
    {
        return this;
    }

    BoxItem* operator->()
    {
        return this;
    }
    /**
     * 入手アクションのリストを取得
     *
     * @return 入手アクションのリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 入手アクションのリストを設定
     *
     * @param acquireActions 入手アクションのリスト
     */
    void setAcquireActions(const List<AcquireAction>& acquireActions)
    {
        ensureData().acquireActions.emplace(acquireActions);
    }

    /**
     * 入手アクションのリストを設定
     *
     * @param acquireActions 入手アクションのリスト
     */
    BoxItem& withAcquireActions(const List<AcquireAction>& acquireActions)
    {
        setAcquireActions(acquireActions);
        return *this;
    }

    /**
     * 残り数量を取得
     *
     * @return 残り数量
     */
    const optional<Int32>& getRemaining() const
    {
        return ensureData().remaining;
    }

    /**
     * 残り数量を設定
     *
     * @param remaining 残り数量
     */
    void setRemaining(Int32 remaining)
    {
        ensureData().remaining.emplace(remaining);
    }

    /**
     * 残り数量を設定
     *
     * @param remaining 残り数量
     */
    BoxItem& withRemaining(Int32 remaining)
    {
        setRemaining(remaining);
        return *this;
    }

    /**
     * 初期数量を取得
     *
     * @return 初期数量
     */
    const optional<Int32>& getInitial() const
    {
        return ensureData().initial;
    }

    /**
     * 初期数量を設定
     *
     * @param initial 初期数量
     */
    void setInitial(Int32 initial)
    {
        ensureData().initial.emplace(initial);
    }

    /**
     * 初期数量を設定
     *
     * @param initial 初期数量
     */
    BoxItem& withInitial(Int32 initial)
    {
        setInitial(initial);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const BoxItem& lhs, const BoxItem& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
        if (lhs.m_pData->remaining != lhr.m_pData->remaining)
        {
            return true;
        }
        if (lhs.m_pData->initial != lhr.m_pData->initial)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const BoxItem& lhs, const BoxItem& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_BOXITEM_HPP_