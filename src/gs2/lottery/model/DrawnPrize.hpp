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

#ifndef GS2_LOTTERY_MODEL_DRAWNPRIZE_HPP_
#define GS2_LOTTERY_MODEL_DRAWNPRIZE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * 排出された景品
 *
 * @author Game Server Services, Inc.
 *
 */
class DrawnPrize : public Gs2Object
{
    friend bool operator!=(const DrawnPrize& lhs, const DrawnPrize& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 入手アクションのリスト */
        optional<List<AcquireAction>> acquireActions;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "acquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->acquireActions += std::move(item);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DrawnPrize() = default;
    DrawnPrize(const DrawnPrize& drawnPrize) = default;
    DrawnPrize(DrawnPrize&& drawnPrize) = default;
    ~DrawnPrize() = default;

    DrawnPrize& operator=(const DrawnPrize& drawnPrize) = default;
    DrawnPrize& operator=(DrawnPrize&& drawnPrize) = default;

    DrawnPrize deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DrawnPrize);
    }

    const DrawnPrize* operator->() const
    {
        return this;
    }

    DrawnPrize* operator->()
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
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 入手アクションのリストを設定
     *
     * @param acquireActions 入手アクションのリスト
     */
    DrawnPrize& withAcquireActions(List<AcquireAction> acquireActions)
    {
        setAcquireActions(std::move(acquireActions));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DrawnPrize& lhs, const DrawnPrize& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->acquireActions != lhr.m_pData->acquireActions)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const DrawnPrize& lhs, const DrawnPrize& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_DRAWNPRIZE_HPP_