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

#ifndef GS2_EXCHANGE_CONTROL_CREATEAWAITBYUSERIDRESULT_HPP_
#define GS2_EXCHANGE_CONTROL_CREATEAWAITBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * 交換待機を作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateAwaitByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換待機 */
        optional<Await> item;
        /** 取得できるようになる日時 */
        optional<Int64> unlockAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            unlockAt(data.unlockAt)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "unlockAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->unlockAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CreateAwaitByUserIdResult() = default;
    CreateAwaitByUserIdResult(const CreateAwaitByUserIdResult& createAwaitByUserIdResult) = default;
    CreateAwaitByUserIdResult(CreateAwaitByUserIdResult&& createAwaitByUserIdResult) = default;
    ~CreateAwaitByUserIdResult() = default;

    CreateAwaitByUserIdResult& operator=(const CreateAwaitByUserIdResult& createAwaitByUserIdResult) = default;
    CreateAwaitByUserIdResult& operator=(CreateAwaitByUserIdResult&& createAwaitByUserIdResult) = default;

    CreateAwaitByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateAwaitByUserIdResult);
    }

    const CreateAwaitByUserIdResult* operator->() const
    {
        return this;
    }

    CreateAwaitByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 交換待機を取得
     *
     * @return 交換待機
     */
    const optional<Await>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 交換待機を設定
     *
     * @param item 交換待機
     */
    void setItem(Await item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 取得できるようになる日時を取得
     *
     * @return 取得できるようになる日時
     */
    const optional<Int64>& getUnlockAt() const
    {
        return ensureData().unlockAt;
    }

    /**
     * 取得できるようになる日時を設定
     *
     * @param unlockAt 取得できるようになる日時
     */
    void setUnlockAt(Int64 unlockAt)
    {
        ensureData().unlockAt.emplace(unlockAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateAwaitByUserIdResult> AsyncCreateAwaitByUserIdResult;

} }

#endif //GS2_EXCHANGE_CONTROL_CREATEAWAITBYUSERIDRESULT_HPP_